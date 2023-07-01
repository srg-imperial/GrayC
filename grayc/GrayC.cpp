//===--- GrayC/GrayC.cpp - GrayC tool -----------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//
///
///  \file This file implements a grayc tool.
///
///  This tool uses the Clang Tooling infrastructure, see
///    http://clang.llvm.org/docs/HowToSetupToolingForLLVM.html
///  for details on setting it up with LLVM source tree.
///
//===----------------------------------------------------------------------===//

#include "GrayC.h"
#include "GrayCCheck.h"
#include "GrayCDiagnosticConsumer.h"
#include "GrayCModuleRegistry.h"
#include "GrayCProfiling.h"
#include "clang/AST/ASTConsumer.h"
#include "clang/AST/ASTContext.h"
#include "clang/AST/Decl.h"
#include "clang/ASTMatchers/ASTMatchFinder.h"
#include "clang/Config/config.h"
#include "clang/Format/Format.h"
#include "clang/Frontend/ASTConsumers.h"
#include "clang/Frontend/CompilerInstance.h"
#include "clang/Frontend/FrontendActions.h"
#include "clang/Frontend/FrontendDiagnostic.h"
#include "clang/Frontend/MultiplexConsumer.h"
#include "clang/Frontend/TextDiagnosticPrinter.h"
#include "clang/Lex/PPCallbacks.h"
#include "clang/Lex/Preprocessor.h"
#include "clang/Lex/PreprocessorOptions.h"
#include "clang/Rewrite/Frontend/FixItRewriter.h"
#include "clang/Rewrite/Frontend/FrontendActions.h"
#include "clang/Tooling/Core/Diagnostic.h"
#include "clang/Tooling/DiagnosticsYaml.h"
#include "clang/Tooling/Refactoring.h"
#include "clang/Tooling/ReplacementsYaml.h"
#include "clang/Tooling/Tooling.h"
#include "llvm/Support/Process.h"
#include "llvm/Support/Signals.h"
#include <algorithm>
#include <utility>


using namespace clang::ast_matchers;
using namespace clang::driver;
using namespace clang::tooling;
using namespace llvm;

LLVM_INSTANTIATE_REGISTRY(clang::grayc::GrayCModuleRegistry)

namespace clang {
namespace grayc {

namespace {

class ErrorReporter {
public:
  ErrorReporter(GrayCContext &Context, bool ApplyFixes,
                llvm::IntrusiveRefCntPtr<llvm::vfs::FileSystem> BaseFS)
      : Files(FileSystemOptions(), BaseFS), DiagOpts(new DiagnosticOptions()),
        DiagPrinter(new TextDiagnosticPrinter(llvm::outs(), &*DiagOpts)),
        Diags(IntrusiveRefCntPtr<DiagnosticIDs>(new DiagnosticIDs), &*DiagOpts,
              DiagPrinter),
        SourceMgr(Diags, Files), Context(Context), ApplyFixes(ApplyFixes),
        TotalFixes(0), AppliedFixes(0), WarningsAsErrors(0) {
    DiagOpts->ShowColors = Context.getOptions().UseColor.getValueOr(
        llvm::sys::Process::StandardOutHasColors());
    DiagPrinter->BeginSourceFile(LangOpts);
  }

  SourceManager &getSourceManager() { return SourceMgr; }

  void reportDiagnostic(const GrayCError &Error) {
    const tooling::DiagnosticMessage &Message = Error.Message;
    SourceLocation Loc = getLocation(Message.FilePath, Message.FileOffset);
    // Contains a pair for each attempted fix: location and whether the fix was
    // applied successfully.
    SmallVector<std::pair<SourceLocation, bool>, 4> FixLocations;
    {
      auto Level = static_cast<DiagnosticsEngine::Level>(Error.DiagLevel);
      std::string Name = Error.DiagnosticName;
      if (!Error.EnabledDiagnosticAliases.empty())
        Name += "," + llvm::join(Error.EnabledDiagnosticAliases, ",");
      if (Error.IsWarningAsError) {
        Name += ",-warnings-as-errors";
        Level = DiagnosticsEngine::Error;
        WarningsAsErrors++;
      }
      auto Diag = Diags.Report(Loc, Diags.getCustomDiagID(Level, "%0 [%1]"))
                  << Message.Message << Name;
      // FIXME: explore options to support interactive fix selection.
      const llvm::StringMap<Replacements> *ChosenFix = selectFirstFix(Error);
      if (ApplyFixes && ChosenFix) {
        for (const auto &FileAndReplacements : *ChosenFix) {
          for (const auto &Repl : FileAndReplacements.second) {
            ++TotalFixes;
            bool CanBeApplied = false;
            if (!Repl.isApplicable())
              continue;
            SourceLocation FixLoc;
            SmallString<128> FixAbsoluteFilePath = Repl.getFilePath();
            Files.makeAbsolutePath(FixAbsoluteFilePath);
            tooling::Replacement R(FixAbsoluteFilePath, Repl.getOffset(),
                                   Repl.getLength(), Repl.getReplacementText());
            Replacements &Replacements = FileReplacements[R.getFilePath()];
            llvm::Error Err = Replacements.add(R);
            if (Err) {
              // FIXME: Implement better conflict handling.
              llvm::errs() << "Trying to resolve conflict: "
                           << llvm::toString(std::move(Err)) << "\n";
              unsigned NewOffset =
                  Replacements.getShiftedCodePosition(R.getOffset());
              unsigned NewLength = Replacements.getShiftedCodePosition(
                                       R.getOffset() + R.getLength()) -
                                   NewOffset;
              if (NewLength == R.getLength()) {
                R = Replacement(R.getFilePath(), NewOffset, NewLength,
                                R.getReplacementText());
                Replacements = Replacements.merge(tooling::Replacements(R));
                CanBeApplied = true;
                ++AppliedFixes;
              } else {
                llvm::errs()
                    << "Can't resolve conflict, skipping the replacement.\n";
              }
            } else {
              CanBeApplied = true;
              ++AppliedFixes;
            }
            FixLoc = getLocation(FixAbsoluteFilePath, Repl.getOffset());
            FixLocations.push_back(std::make_pair(FixLoc, CanBeApplied));
          }
        }
      }
      reportFix(Diag, Error.Message.Fix);
    }
    for (auto Fix : FixLocations) {
      Diags.Report(Fix.first, Fix.second ? diag::note_fixit_applied
                                         : diag::note_fixit_failed);
    }
    for (const auto &Note : Error.Notes)
      reportNote(Note);
  }

  void Finish() {
    if (ApplyFixes && TotalFixes > 0) {
      Rewriter Rewrite(SourceMgr, LangOpts);
      for (const auto &FileAndReplacements : FileReplacements) {
        StringRef File = FileAndReplacements.first();
        llvm::ErrorOr<std::unique_ptr<MemoryBuffer>> Buffer =
            SourceMgr.getFileManager().getBufferForFile(File);
        if (!Buffer) {
          llvm::errs() << "Can't get buffer for file " << File << ": "
                       << Buffer.getError().message() << "\n";
          // FIXME: Maybe don't apply fixes for other files as well.
          continue;
        }
        StringRef Code = Buffer.get()->getBuffer();
        auto Style = format::getStyle(
            *Context.getOptionsForFile(File).FormatStyle, File, "none");
        if (!Style) {
          llvm::errs() << llvm::toString(Style.takeError()) << "\n";
          continue;
        }
        llvm::Expected<tooling::Replacements> Replacements =
            format::cleanupAroundReplacements(Code, FileAndReplacements.second,
                                              *Style);
        if (!Replacements) {
          llvm::errs() << llvm::toString(Replacements.takeError()) << "\n";
          continue;
        }
        if (llvm::Expected<tooling::Replacements> FormattedReplacements =
                format::formatReplacements(Code, *Replacements, *Style)) {
          Replacements = std::move(FormattedReplacements);
          if (!Replacements)
            llvm_unreachable("!Replacements");
        } else {
          llvm::errs() << llvm::toString(FormattedReplacements.takeError())
                       << ". Skipping formatting.\n";
        }
        if (!tooling::applyAllReplacements(Replacements.get(), Rewrite)) {
          llvm::errs() << "Can't apply replacements for file " << File << "\n";
        }
      }
      if (Rewrite.overwriteChangedFiles()) {
        llvm::errs() << "GrayC failed to apply suggested transformations.\n";
      } else {
        llvm::errs() << "GrayC applied " << AppliedFixes << " of "
                     << TotalFixes << " suggested transformations.\n";
      }
    }
  }

  unsigned getWarningsAsErrorsCount() const { return WarningsAsErrors; }

private:
  SourceLocation getLocation(StringRef FilePath, unsigned Offset) {
    if (FilePath.empty())
      return SourceLocation();

    auto File = SourceMgr.getFileManager().getFile(FilePath);
    if (!File)
      return SourceLocation();

    FileID ID = SourceMgr.getOrCreateFileID(*File, SrcMgr::C_User);
    return SourceMgr.getLocForStartOfFile(ID).getLocWithOffset(Offset);
  }

  void reportFix(const DiagnosticBuilder &Diag,
                 const llvm::StringMap<Replacements> &Fix) {
    for (const auto &FileAndReplacements : Fix) {
      for (const auto &Repl : FileAndReplacements.second) {
        if (!Repl.isApplicable())
          continue;
        SmallString<128> FixAbsoluteFilePath = Repl.getFilePath();
        Files.makeAbsolutePath(FixAbsoluteFilePath);
        SourceLocation FixLoc =
            getLocation(FixAbsoluteFilePath, Repl.getOffset());
        SourceLocation FixEndLoc = FixLoc.getLocWithOffset(Repl.getLength());
        // Retrieve the source range for applicable fixes. Macro definitions
        // on the command line have locations in a virtual buffer and don't
        // have valid file paths and are therefore not applicable.
        CharSourceRange Range =
            CharSourceRange::getCharRange(SourceRange(FixLoc, FixEndLoc));
        Diag << FixItHint::CreateReplacement(Range, Repl.getReplacementText());
      }
    }
  }

  void reportNote(const tooling::DiagnosticMessage &Message) {
    SourceLocation Loc = getLocation(Message.FilePath, Message.FileOffset);
    auto Diag =
        Diags.Report(Loc, Diags.getCustomDiagID(DiagnosticsEngine::Note, "%0"))
        << Message.Message;
    reportFix(Diag, Message.Fix);
  }

  FileManager Files;
  LangOptions LangOpts; // FIXME: use langopts from each original file
  IntrusiveRefCntPtr<DiagnosticOptions> DiagOpts;
  DiagnosticConsumer *DiagPrinter;
  DiagnosticsEngine Diags;
  SourceManager SourceMgr;
  llvm::StringMap<Replacements> FileReplacements;
  GrayCContext &Context;
  bool ApplyFixes;
  unsigned TotalFixes;
  unsigned AppliedFixes;
  unsigned WarningsAsErrors;
};

class GrayCASTConsumer : public MultiplexConsumer {
public:
  GrayCASTConsumer(std::vector<std::unique_ptr<ASTConsumer>> Consumers,
                       std::unique_ptr<GrayCProfiling> Profiling,
                       std::unique_ptr<ast_matchers::MatchFinder> Finder,
                       std::vector<std::unique_ptr<GrayCCheck>> Checks)
      : MultiplexConsumer(std::move(Consumers)),
        Profiling(std::move(Profiling)), Finder(std::move(Finder)),
        Checks(std::move(Checks)) {}

private:
  // Destructor order matters! Profiling must be destructed last.
  // Or at least after Finder.
  std::unique_ptr<GrayCProfiling> Profiling;
  std::unique_ptr<ast_matchers::MatchFinder> Finder;
  std::vector<std::unique_ptr<GrayCCheck>> Checks;
};

} // namespace

GrayCASTConsumerFactory::GrayCASTConsumerFactory(
    GrayCContext &Context,
    IntrusiveRefCntPtr<llvm::vfs::OverlayFileSystem> OverlayFS)
    : Context(Context), OverlayFS(OverlayFS),
      CheckFactories(new GrayCCheckFactories) {
  for (GrayCModuleRegistry::entry E : GrayCModuleRegistry::entries()) {
    std::unique_ptr<GrayCModule> Module = E.instantiate();
    Module->addCheckFactories(*CheckFactories);
  }
}


std::unique_ptr<clang::ASTConsumer>
GrayCASTConsumerFactory::CreateASTConsumer(
    clang::CompilerInstance &Compiler, StringRef File) {
  // FIXME: Move this to a separate method, so that CreateASTConsumer doesn't
  // modify Compiler.
  SourceManager *SM = &Compiler.getSourceManager();
  Context.setSourceManager(SM);
  Context.setCurrentFile(File);
  Context.setASTContext(&Compiler.getASTContext());

  auto WorkingDir = Compiler.getSourceManager()
                        .getFileManager()
                        .getVirtualFileSystem()
                        .getCurrentWorkingDirectory();
  if (WorkingDir)
    Context.setCurrentBuildDirectory(WorkingDir.get());

  std::vector<std::unique_ptr<GrayCCheck>> Checks =
      CheckFactories->createChecks(&Context);

  ast_matchers::MatchFinder::MatchFinderOptions FinderOptions;

  std::unique_ptr<GrayCProfiling> Profiling;
  if (Context.getEnableProfiling()) {
    Profiling = std::make_unique<GrayCProfiling>(
        Context.getProfileStorageParams());
    FinderOptions.CheckProfiling.emplace(Profiling->Records);
  }

  std::unique_ptr<ast_matchers::MatchFinder> Finder(
      new ast_matchers::MatchFinder(std::move(FinderOptions)));

  Preprocessor *PP = &Compiler.getPreprocessor();
  Preprocessor *ModuleExpanderPP = PP;

  // if (Context.getLangOpts().Modules && OverlayFS != nullptr) {
  //   auto ModuleExpander = std::make_unique<ExpandModularHeadersPPCallbacks>(
  //       &Compiler, OverlayFS);
  //   ModuleExpanderPP = ModuleExpander->getPreprocessor();
  //   PP->addPPCallbacks(std::move(ModuleExpander));
  // }

  for (auto &Check : Checks) {
    if (!Check->isLanguageVersionSupported(Context.getLangOpts()))
      continue;
    Check->registerMatchers(&*Finder);
    Check->registerPPCallbacks(*SM, PP, ModuleExpanderPP);
  }

  std::vector<std::unique_ptr<ASTConsumer>> Consumers;
  if (!Checks.empty())
    Consumers.push_back(Finder->newASTConsumer());

  return std::make_unique<GrayCASTConsumer>(
      std::move(Consumers), std::move(Profiling), std::move(Finder),
      std::move(Checks));
}

std::vector<std::string> GrayCASTConsumerFactory::getCheckNames() {
  std::vector<std::string> CheckNames;
  for (const auto &CheckFactory : *CheckFactories) {
    if (Context.isCheckEnabled(CheckFactory.first))
      CheckNames.push_back(CheckFactory.first);
  }


  llvm::sort(CheckNames);
  return CheckNames;
}

GrayCOptions::OptionMap GrayCASTConsumerFactory::getCheckOptions() {
  GrayCOptions::OptionMap Options;
  std::vector<std::unique_ptr<GrayCCheck>> Checks =
      CheckFactories->createChecks(&Context);
  for (const auto &Check : Checks)
    Check->storeOptions(Options);
  return Options;
}

std::vector<std::string>
getCheckNames(const GrayCOptions &Options,
              bool AllowEnablingAnalyzerAlphaCheckers) {
  clang::grayc::GrayCContext Context(
      std::make_unique<DefaultOptionsProvider>(GrayCGlobalOptions(),
                                                Options),
      AllowEnablingAnalyzerAlphaCheckers);
  GrayCASTConsumerFactory Factory(Context);
  return Factory.getCheckNames();
}

GrayCOptions::OptionMap
getCheckOptions(const GrayCOptions &Options,
                bool AllowEnablingAnalyzerAlphaCheckers) {
  clang::grayc::GrayCContext Context(
      std::make_unique<DefaultOptionsProvider>(GrayCGlobalOptions(),
                                                Options),
      AllowEnablingAnalyzerAlphaCheckers);
  GrayCASTConsumerFactory Factory(Context);
  return Factory.getCheckOptions();
}

std::vector<GrayCError>
runGrayC(clang::grayc::GrayCContext &Context,
             const CompilationDatabase &Compilations,
             ArrayRef<std::string> InputFiles,
             llvm::IntrusiveRefCntPtr<llvm::vfs::OverlayFileSystem> BaseFS,
             bool EnableCheckProfile, llvm::StringRef StoreCheckProfile) {
  ClangTool Tool(Compilations, InputFiles,
                 std::make_shared<PCHContainerOperations>(), BaseFS);

  // Add extra arguments passed by the GrayC command-line.
  ArgumentsAdjuster PerFileExtraArgumentsInserter =
      [&Context](const CommandLineArguments &Args, StringRef Filename) {
        GrayCOptions Opts = Context.getOptionsForFile(Filename);
        CommandLineArguments AdjustedArgs = Args;
        if (Opts.ExtraArgsBefore) {
          auto I = AdjustedArgs.begin();
          if (I != AdjustedArgs.end() && !StringRef(*I).startswith("-"))
            ++I; // Skip compiler binary name, if it is there.
          AdjustedArgs.insert(I, Opts.ExtraArgsBefore->begin(),
                              Opts.ExtraArgsBefore->end());
        }
        if (Opts.ExtraArgs)
          AdjustedArgs.insert(AdjustedArgs.end(), Opts.ExtraArgs->begin(),
                              Opts.ExtraArgs->end());
        return AdjustedArgs;
      };

  Tool.appendArgumentsAdjuster(PerFileExtraArgumentsInserter);
  Tool.appendArgumentsAdjuster(getStripPluginsAdjuster());
  Context.setEnableProfiling(EnableCheckProfile);
  Context.setProfileStoragePrefix(StoreCheckProfile);

  GrayCDiagnosticConsumer DiagConsumer(Context);
  DiagnosticsEngine DE(new DiagnosticIDs(), new DiagnosticOptions(),
                       &DiagConsumer, /*ShouldOwnClient=*/false);
  Context.setDiagnosticsEngine(&DE);
  Tool.setDiagnosticConsumer(&DiagConsumer);

  class ActionFactory : public FrontendActionFactory {
  public:
    ActionFactory(GrayCContext &Context,
                  IntrusiveRefCntPtr<llvm::vfs::OverlayFileSystem> BaseFS)
        : ConsumerFactory(Context, BaseFS) {}
    std::unique_ptr<FrontendAction> create() override {
      return std::make_unique<Action>(&ConsumerFactory);
    }

    bool runInvocation(std::shared_ptr<CompilerInvocation> Invocation,
                       FileManager *Files,
                       std::shared_ptr<PCHContainerOperations> PCHContainerOps,
                       DiagnosticConsumer *DiagConsumer) override {
      // Explicitly ask to define __clang_analyzer__ macro.
      Invocation->getPreprocessorOpts().SetUpStaticAnalyzer = true;
      return FrontendActionFactory::runInvocation(
          Invocation, Files, PCHContainerOps, DiagConsumer);
    }

  private:
    class Action : public ASTFrontendAction {
    public:
      Action(GrayCASTConsumerFactory *Factory) : Factory(Factory) {}
      std::unique_ptr<ASTConsumer> CreateASTConsumer(CompilerInstance &Compiler,
                                                     StringRef File) override {
        return Factory->CreateASTConsumer(Compiler, File);
      }

    private:
      GrayCASTConsumerFactory *Factory;
    };

    GrayCASTConsumerFactory ConsumerFactory;
  };

  ActionFactory Factory(Context, BaseFS);
  Tool.run(&Factory);
  return DiagConsumer.take();
}

void handleErrors(llvm::ArrayRef<GrayCError> Errors,
                  GrayCContext &Context, bool Fix,
                  unsigned &WarningsAsErrorsCount,
                  llvm::IntrusiveRefCntPtr<llvm::vfs::FileSystem> BaseFS) {
  ErrorReporter Reporter(Context, Fix, BaseFS);
  llvm::vfs::FileSystem &FileSystem =
      Reporter.getSourceManager().getFileManager().getVirtualFileSystem();
  auto InitialWorkingDir = FileSystem.getCurrentWorkingDirectory();
  if (!InitialWorkingDir)
    llvm::report_fatal_error("Cannot get current working path.");

  for (const GrayCError &Error : Errors) {
    if (!Error.BuildDirectory.empty()) {
      // By default, the working directory of file system is the current
      // grayc running directory.
      //
      // Change the directory to the one used during the analysis.
      FileSystem.setCurrentWorkingDirectory(Error.BuildDirectory);
    }
    Reporter.reportDiagnostic(Error);
    // Return to the initial directory to correctly resolve next Error.
    FileSystem.setCurrentWorkingDirectory(InitialWorkingDir.get());
  }
  Reporter.Finish();
  WarningsAsErrorsCount += Reporter.getWarningsAsErrorsCount();
}

void exportReplacements(const llvm::StringRef MainFilePath,
                        const std::vector<GrayCError> &Errors,
                        raw_ostream &OS) {
  TranslationUnitDiagnostics TUD;
  TUD.MainSourceFile = std::string(MainFilePath);
  for (const auto &Error : Errors) {
    tooling::Diagnostic Diag = Error;
    TUD.Diagnostics.insert(TUD.Diagnostics.end(), Diag);
  }

  yaml::Output YAML(OS);
  YAML << TUD;
}

} // namespace grayc
} // namespace clang
