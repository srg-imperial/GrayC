//===--- GrayCDiagnosticConsumer.h - grayc -------------*- C++ -*-===//
//
// Taken from the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

#ifndef GRAYC_GrayCDiagnosticConsumer_H
#define GRAYC_GrayCDiagnosticConsumer_H

#include "Compatability.h"
#include "GrayCOptions.h"
#include "GrayCProfiling.h"
#include "clang/Basic/Diagnostic.h"
#include "clang/Tooling/Core/Diagnostic.h"
#include "llvm/ADT/DenseMap.h"
#include "llvm/Support/Regex.h"

namespace clang {

class ASTContext;
class CompilerInstance;
class SourceManager;
namespace ast_matchers {
class MatchFinder;
}
namespace tooling {
class CompilationDatabase;
}

namespace grayc {

/// A detected error complete with information to display diagnostic and
/// automatic fix.
///
/// This is used as an intermediate format to transport Diagnostics without a
/// dependency on a SourceManager.
///
/// FIXME: Make Diagnostics flexible enough to support this directly.
struct GrayCError : tooling::Diagnostic {
  GrayCError(StringRef CheckName, Level DiagLevel, StringRef BuildDirectory,
                 bool IsWarningAsError);

  bool IsWarningAsError;
  std::vector<std::string> EnabledDiagnosticAliases;
};

/// Contains displayed and ignored diagnostic counters for a 
/// run.
struct GrayCStats {
  GrayCStats()
      : ErrorsDisplayed(0), ErrorsIgnoredCheckFilter(0), ErrorsIgnoredNOLINT(0),
        ErrorsIgnoredNonUserCode(0), ErrorsIgnoredLineFilter(0) {}

  unsigned ErrorsDisplayed;
  unsigned ErrorsIgnoredCheckFilter;
  unsigned ErrorsIgnoredNOLINT;
  unsigned ErrorsIgnoredNonUserCode;
  unsigned ErrorsIgnoredLineFilter;

  unsigned errorsIgnored() const {
    return ErrorsIgnoredNOLINT + ErrorsIgnoredCheckFilter +
           ErrorsIgnoredNonUserCode + ErrorsIgnoredLineFilter;
  }
};

/// Every \c GrayCCheck reports errors through a \c DiagnosticsEngine
/// provided by this context.
///
/// A \c GrayCCheck always has access to the active context to report
/// warnings like:
/// \code
/// Context->Diag(Loc, "Single-argument constructors must be explicit")
///     << FixItHint::CreateInsertion(Loc, "explicit ");
/// \endcode
class GrayCContext {
public:
  /// Initializes \c GrayCContext instance.
  GrayCContext(std::unique_ptr<GrayCOptionsProvider> OptionsProvider,
                   bool AllowEnablingAnalyzerAlphaCheckers = false);
  /// Sets the DiagnosticsEngine that diag() will emit diagnostics to.
  // FIXME: this is required initialization, and should be a constructor param.
  // Fix the context -> diag engine -> consumer -> context initialization cycle.
  void setDiagnosticsEngine(DiagnosticsEngine *DiagEngine) {
    this->DiagEngine = DiagEngine;
  }

  ~GrayCContext();

  /// Report any errors detected using this method.
  ///
  /// This is still under heavy development and will likely change towards using
  /// tablegen'd diagnostic IDs.
  /// FIXME: Figure out a way to manage ID spaces.
  DiagnosticBuilder diag(StringRef CheckName, SourceLocation Loc,
                         StringRef Message,
                         DiagnosticIDs::Level Level = DiagnosticIDs::Warning);

  /// Sets the \c SourceManager of the used \c DiagnosticsEngine.
  ///
  /// This is called from the \c GrayCCheck base class.
  void setSourceManager(SourceManager *SourceMgr);

  /// Should be called when starting to process new translation unit.
  void setCurrentFile(StringRef File);

  /// Returns the main file name of the current translation unit.
  StringRef getCurrentFile() const { return CurrentFile; }

  /// Sets ASTContext for the current translation unit.
  void setASTContext(ASTContext *Context);

  /// Gets the language options from the AST context.
  const LangOptions &getLangOpts() const { return LangOpts; }

  /// Returns the name of the grayc check which produced this
  /// diagnostic ID.
  std::string getCheckName(unsigned DiagnosticID) const;

  /// Returns \c true if the check is enabled for the \c CurrentFile.
  ///
  /// The \c CurrentFile can be changed using \c setCurrentFile.
  bool isCheckEnabled(StringRef CheckName) const;

  /// Returns \c true if the check should be upgraded to error for the
  /// \c CurrentFile.
  bool treatAsError(StringRef CheckName) const;

  /// Returns global options.
  const GrayCGlobalOptions &getGlobalOptions() const;

  /// Returns options for \c CurrentFile.
  ///
  /// The \c CurrentFile can be changed using \c setCurrentFile.
  const GrayCOptions &getOptions() const;

  /// Returns options for \c File. Does not change or depend on
  /// \c CurrentFile.
  GrayCOptions getOptionsForFile(StringRef File) const;

  /// Returns \c GrayCStats containing issued and ignored diagnostic
  /// counters.
  const GrayCStats &getStats() const { return Stats; }

  /// Control profile collection in grayc.
  void setEnableProfiling(bool Profile);
  bool getEnableProfiling() const { return Profile; }

  /// Control storage of profile date.
  void setProfileStoragePrefix(StringRef ProfilePrefix);
  OPTIONAL(GrayCProfiling::StorageParams)
  getProfileStorageParams() const;

  /// Should be called when starting to process new translation unit.
  void setCurrentBuildDirectory(StringRef BuildDirectory) {
    CurrentBuildDirectory = std::string(BuildDirectory);
  }

  /// Returns build directory of the current translation unit.
  const std::string &getCurrentBuildDirectory() {
    return CurrentBuildDirectory;
  }

  /// If the experimental alpha checkers from the static analyzer can be
  /// enabled.
  bool canEnableAnalyzerAlphaCheckers() const {
    return AllowEnablingAnalyzerAlphaCheckers;
  }

  using DiagLevelAndFormatString = std::pair<DiagnosticIDs::Level, std::string>;
  DiagLevelAndFormatString getDiagLevelAndFormatString(unsigned DiagnosticID,
                                                       SourceLocation Loc) {
    return DiagLevelAndFormatString(
        static_cast<DiagnosticIDs::Level>(
            DiagEngine->getDiagnosticLevel(DiagnosticID, Loc)),
        std::string(
            DiagEngine->getDiagnosticIDs()->getDescription(DiagnosticID)));
  }

private:
  // Writes to Stats.
  friend class GrayCDiagnosticConsumer;

  DiagnosticsEngine *DiagEngine;
  std::unique_ptr<GrayCOptionsProvider> OptionsProvider;

  std::string CurrentFile;
  GrayCOptions CurrentOptions;
  class CachedGlobList;
  std::unique_ptr<CachedGlobList> CheckFilter;
  std::unique_ptr<CachedGlobList> WarningAsErrorFilter;

  LangOptions LangOpts;

  GrayCStats Stats;

  std::string CurrentBuildDirectory;

  llvm::DenseMap<unsigned, std::string> CheckNamesByDiagnosticID;

  bool Profile;
  std::string ProfilePrefix;

  bool AllowEnablingAnalyzerAlphaCheckers;
};

/// Check whether a given diagnostic should be suppressed due to the presence
/// of a "NOLINT" suppression comment.
/// This is exposed so that other tools that present grayc diagnostics
/// (such as clangd) can respect the same suppression rules as grayc.
/// This does not handle suppression of notes following a suppressed diagnostic;
/// that is left to the caller is it requires maintaining state in between calls
/// to this function.
/// If `AllowIO` is false, the function does not attempt to read source files
/// from disk which are not already mapped into memory; such files are treated
/// as not containing a suppression comment.
bool shouldSuppressDiagnostic(DiagnosticsEngine::Level DiagLevel,
                              const Diagnostic &Info, GrayCContext &Context,
                              bool AllowIO = true);

/// A diagnostic consumer that turns each \c Diagnostic into a
/// \c SourceManager-independent \c GrayCError.
//
// FIXME: If we move away from unit-tests, this can be moved to a private
// implementation file.
class GrayCDiagnosticConsumer : public DiagnosticConsumer {
public:
  GrayCDiagnosticConsumer(GrayCContext &Ctx,
                              DiagnosticsEngine *ExternalDiagEngine = nullptr,
                              bool RemoveIncompatibleErrors = true);

  // FIXME: The concept of converting between FixItHints and Replacements is
  // more generic and should be pulled out into a more useful Diagnostics
  // library.
  void HandleDiagnostic(DiagnosticsEngine::Level DiagLevel,
                        const Diagnostic &Info) override;

  // Retrieve the diagnostics that were captured.
  std::vector<GrayCError> take();

private:
  void finalizeLastError();
  void removeIncompatibleErrors();
  void removeDuplicatedDiagnosticsOfAliasCheckers();

  /// Returns the \c HeaderFilter constructed for the options set in the
  /// context.
  llvm::Regex *getHeaderFilter();

  /// Updates \c LastErrorRelatesToUserCode and LastErrorPassesLineFilter
  /// according to the diagnostic \p Location.
  void checkFilters(SourceLocation Location, const SourceManager &Sources);
  bool passesLineFilter(StringRef FileName, unsigned LineNumber) const;

  void forwardDiagnostic(const Diagnostic &Info);

  GrayCContext &Context;
  DiagnosticsEngine *ExternalDiagEngine;
  bool RemoveIncompatibleErrors;
  std::vector<GrayCError> Errors;
  std::unique_ptr<llvm::Regex> HeaderFilter;
  bool LastErrorRelatesToUserCode;
  bool LastErrorPassesLineFilter;
  bool LastErrorWasIgnored;
};

} // end namespace grayc
} // end namespace clang

#endif // GRAYC_GrayCDiagnosticConsumer_H
