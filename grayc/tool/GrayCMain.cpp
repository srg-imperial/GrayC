//===--- grayc/GrayCMain.cpp - GrayC tool -------===//
//
// Taken from the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
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

#include "GrayCMain.h"
#include "../GrayC.h"
#include "../GrayCForceLinker.h"
#include "../GlobList.h"
#include "clang/Tooling/CommonOptionsParser.h"
#include "llvm/Support/InitLLVM.h"
#include "llvm/Support/Process.h"
#include "llvm/Support/Signals.h"
#include "llvm/Support/TargetSelect.h"
#include "llvm/Support/WithColor.h"

using namespace clang::tooling;
using namespace llvm;

static cl::OptionCategory GrayCCategory("GrayC options");

static cl::extrahelp CommonHelp(CommonOptionsParser::HelpMessage);

const char DefaultChecks[] = // Enable these checks by default:
    "cmutation-*,cxxmutation-*";    //   * mutator transformations

static cl::opt<std::string> Checks("checks", cl::desc(R"(
Comma-separated list of globs with optional '-'
prefix. Globs are processed in order of
appearance in the list. Globs without '-'
prefix add checks with matching names to the
set, globs with the '-' prefix remove checks
with matching names from the set of enabled
checks. This option's value is appended to the
value of the 'Checks' option in .grayc
file, if any.
)"),
                                   cl::init(""), cl::cat(GrayCCategory));

static cl::opt<std::string> WarningsAsErrors("warnings-as-errors", cl::desc(R"(
Upgrades warnings to errors. Same format as
'-checks'.
This option's value is appended to the value of
the 'WarningsAsErrors' option in .grayc
file, if any.
)"),
                                             cl::init(""),
                                             cl::cat(GrayCCategory));

static cl::opt<std::string> HeaderFilter("header-filter", cl::desc(R"(
Regular expression matching the names of the
headers to output diagnostics from. Diagnostics
from the main file of each translation unit are
always displayed.
Can be used together with -line-filter.
)"),
                                         cl::init(""),
                                         cl::cat(GrayCCategory));

static cl::opt<bool>
    SystemHeaders("system-headers",
                  cl::desc("Display the errors from system headers."),
                  cl::init(false), cl::cat(GrayCCategory));
static cl::opt<std::string> LineFilter("line-filter", cl::desc(R"(
List of files with line ranges to filter the
warnings. Can be used together with
-header-filter. The format of the list is a
JSON array of objects:
  [
    {"name":"file1.cpp","lines":[[1,3],[5,7]]},
    {"name":"file2.h"}
  ]
)"),
                                       cl::init(""),
                                       cl::cat(GrayCCategory));

static cl::opt<bool> Fix("fix", cl::desc(R"(
Apply suggested fixes. Without -apply-mutation
GrayC will bail out if any compilation
errors were found.
)"),
                         cl::init(false), cl::cat(GrayCCategory));

static cl::opt<bool> ApplyMutations("apply-mutation", cl::desc(R"(
Apply suggested fixes even if compilation
errors were found. If compiler errors have
attached fix-its, GrayC will apply them as
well.
)"),
                               cl::init(false), cl::cat(GrayCCategory));

static cl::opt<std::string> FormatStyle("format-style", cl::desc(R"(
Style for formatting code around applied fixes:
  - 'none' (default) turns off formatting
  - 'file' (literally 'file', not a placeholder)
    uses .clang-format file in the closest parent
    directory
  - '{ <json> }' specifies options inline, e.g.
    -format-style='{BasedOnStyle: llvm, IndentWidth: 8}'
  - 'llvm', 'google', 'webkit', 'mozilla'
See clang-format documentation for the up-to-date
information about formatting styles and options.
)"),
                                   cl::init("none"),
                                   cl::cat(GrayCCategory));

static cl::opt<bool> ListChecks("list-checks", cl::desc(R"(
List all enabled checks and exit. Use with
-checks=* to list all available checks.
)"),
                                cl::init(false), cl::cat(GrayCCategory));


static cl::opt<std::string> Config("config", cl::desc(R"(
Specifies a configuration in YAML/JSON format:
  -config="{Checks: '*',
            CheckOptions: [{key: x,
                            value: y}]}"
When the value is empty, GrayC will
attempt to find a file named .grayc for
each source file in its parent directories.
)"),
                                   cl::init(""), cl::cat(GrayCCategory));


static cl::opt<bool> EnableCheckProfile("enable-check-profile", cl::desc(R"(
Enable per-check timing profiles, and print a
report to stderr.
)"),
                                        cl::init(false),
                                        cl::cat(GrayCCategory));

static cl::opt<std::string> StoreCheckProfile("store-check-profile",
                                              cl::desc(R"(
By default reports are printed in tabulated
format to stderr. When this option is passed,
these per-TU profiles are instead stored as JSON.
)"),
                                              cl::value_desc("prefix"),
                                              cl::cat(GrayCCategory));


static cl::opt<std::string> ExportFixes("export-fixes", cl::desc(R"(
YAML file to store suggested fixes in. The
stored fixes can be applied to the input source
code with clang-apply-replacements.
)"),
                                        cl::value_desc("filename"),
                                        cl::cat(GrayCCategory));

static cl::opt<bool> Quiet("quiet", cl::desc(R"(
Run GrayC in quiet mode. This suppresses
printing statistics about ignored warnings and
warnings treated as errors if the respective
options are specified.
)"),
                           cl::init(false),
                           cl::cat(GrayCCategory));


static cl::opt<bool> UseColor("use-color", cl::desc(R"(
Use colors in diagnostics. If not set, colors
will be used if the terminal connected to
standard output supports colors.
This option overrides the 'UseColor' option in
.grayc file, if any.
)"),
                              cl::init(false), cl::cat(GrayCCategory));

namespace clang {
namespace grayc {

static void printStats(const GrayCStats &Stats) {
  if (Stats.errorsIgnored()) {
    llvm::errs() << "Suppressed " << Stats.errorsIgnored() << " warnings (";
    StringRef Separator = "";
    if (Stats.ErrorsIgnoredNonUserCode) {
      llvm::errs() << Stats.ErrorsIgnoredNonUserCode << " in non-user code";
      Separator = ", ";
    }
    if (Stats.ErrorsIgnoredLineFilter) {
      llvm::errs() << Separator << Stats.ErrorsIgnoredLineFilter
                   << " due to line filter";
      Separator = ", ";
    }
    if (Stats.ErrorsIgnoredNOLINT) {
      llvm::errs() << Separator << Stats.ErrorsIgnoredNOLINT << " NOLINT";
      Separator = ", ";
    }
    if (Stats.ErrorsIgnoredCheckFilter)
      llvm::errs() << Separator << Stats.ErrorsIgnoredCheckFilter
                   << " with check filters";
    llvm::errs() << ").\n";
    if (Stats.ErrorsIgnoredNonUserCode)
      llvm::errs() << "Use -header-filter=.* to display errors from all "
                      "non-system headers. Use -system-headers to display "
                      "errors from system headers as well.\n";
  }
}

static std::unique_ptr<GrayCOptionsProvider> createOptionsProvider(
   llvm::IntrusiveRefCntPtr<vfs::FileSystem> FS) {
  GrayCGlobalOptions GlobalOptions;
  if (std::error_code Err = parseLineFilter(LineFilter, GlobalOptions)) {
    llvm::errs() << "Invalid LineFilter: " << Err.message() << "\n\nUsage:\n";
    llvm::cl::PrintHelpMessage(/*Hidden=*/false, /*Categorized=*/true);
    return nullptr;
  }

  GrayCOptions DefaultOptions;
  DefaultOptions.Checks = DefaultChecks;
  DefaultOptions.WarningsAsErrors = "";
  DefaultOptions.HeaderFilterRegex = HeaderFilter;
  DefaultOptions.SystemHeaders = SystemHeaders;
  DefaultOptions.FormatStyle = FormatStyle;
  DefaultOptions.User = llvm::sys::Process::GetEnv("USER");
  // USERNAME is used on Windows.
  if (!DefaultOptions.User)
    DefaultOptions.User = llvm::sys::Process::GetEnv("USERNAME");

  GrayCOptions OverrideOptions;
  if (Checks.getNumOccurrences() > 0)
    OverrideOptions.Checks = Checks;
  if (WarningsAsErrors.getNumOccurrences() > 0)
    OverrideOptions.WarningsAsErrors = WarningsAsErrors;
  if (HeaderFilter.getNumOccurrences() > 0)
    OverrideOptions.HeaderFilterRegex = HeaderFilter;
  if (SystemHeaders.getNumOccurrences() > 0)
    OverrideOptions.SystemHeaders = SystemHeaders;
  if (FormatStyle.getNumOccurrences() > 0)
    OverrideOptions.FormatStyle = FormatStyle;
  if (UseColor.getNumOccurrences() > 0)
    OverrideOptions.UseColor = UseColor;

  if (!Config.empty()) {
    if (llvm::ErrorOr<GrayCOptions> ParsedConfig =
            parseConfiguration(Config)) {
      return std::make_unique<ConfigOptionsProvider>(
          GlobalOptions,
          GrayCOptions::getDefaults().mergeWith(DefaultOptions, 0),
          *ParsedConfig, OverrideOptions, std::move(FS));
    } else {
      llvm::errs() << "Error: invalid configuration specified.\n"
                   << ParsedConfig.getError().message() << "\n";
      return nullptr;
    }
  }
  return std::make_unique<FileOptionsProvider>(GlobalOptions, DefaultOptions,
                                                OverrideOptions, std::move(FS));
}

llvm::IntrusiveRefCntPtr<vfs::FileSystem>
getVfsFromFile(const std::string &OverlayFile,
               llvm::IntrusiveRefCntPtr<vfs::FileSystem> BaseFS) {
  llvm::ErrorOr<std::unique_ptr<llvm::MemoryBuffer>> Buffer =
      BaseFS->getBufferForFile(OverlayFile);
  if (!Buffer) {
    llvm::errs() << "Can't load virtual filesystem overlay file '"
                 << OverlayFile << "': " << Buffer.getError().message()
                 << ".\n";
    return nullptr;
  }

  IntrusiveRefCntPtr<vfs::FileSystem> FS = vfs::getVFSFromYAML(
      std::move(Buffer.get()), /*DiagHandler*/ nullptr, OverlayFile);
  if (!FS) {
    llvm::errs() << "Error: invalid virtual filesystem overlay file '"
                 << OverlayFile << "'.\n";
    return nullptr;
  }
  return FS;
}

int GrayCMain(int argc, const char **argv) {
  llvm::InitLLVM X(argc, argv);
  llvm::Expected<CommonOptionsParser> OptionsParser =
      CommonOptionsParser::create(argc, argv, GrayCCategory,
                                  cl::ZeroOrMore);
  if (!OptionsParser) {
    llvm::WithColor::error() << llvm::toString(OptionsParser.takeError());
    return 1;
  }

  llvm::IntrusiveRefCntPtr<vfs::OverlayFileSystem> BaseFS(
      new vfs::OverlayFileSystem(vfs::getRealFileSystem()));


  auto OwningOptionsProvider = createOptionsProvider(BaseFS);
  auto *OptionsProvider = OwningOptionsProvider.get();
  if (!OptionsProvider)
    return 1;

  auto MakeAbsolute = [](const std::string &Input) -> SmallString<256> {
    if (Input.empty())
      return {};
    SmallString<256> AbsolutePath(Input);
    if (std::error_code EC = llvm::sys::fs::make_absolute(AbsolutePath)) {
      llvm::errs() << "Can't make absolute path from " << Input << ": "
                   << EC.message() << "\n";
    }
    return AbsolutePath;
  };

  SmallString<256> ProfilePrefix = MakeAbsolute(StoreCheckProfile);

  StringRef FileName("dummy");
  auto PathList = OptionsParser->getSourcePathList();
  if (!PathList.empty()) {
    FileName = PathList.front();
  }

  SmallString<256> FilePath = MakeAbsolute(std::string(FileName));

  GrayCOptions EffectiveOptions = OptionsProvider->getOptions(FilePath);
  std::vector<std::string> EnabledChecks =
      getCheckNames(EffectiveOptions, false);


  if (ListChecks) {
    if (EnabledChecks.empty()) {
      llvm::errs() << "No checks enabled.\n";
      return 1;
    }
    llvm::outs() << "Enabled checks:";
    for (const auto &CheckName : EnabledChecks)
      llvm::outs() << "\n    " << CheckName;
    llvm::outs() << "\n\n";
    return 0;
  }

  if (EnabledChecks.empty()) {
    llvm::errs() << "Error: no checks enabled.\n";
    llvm::cl::PrintHelpMessage(/*Hidden=*/false, /*Categorized=*/true);
    return 1;
  }

  if (PathList.empty()) {
    llvm::errs() << "Error: no input files specified.\n";
    llvm::cl::PrintHelpMessage(/*Hidden=*/false, /*Categorized=*/true);
    return 1;
  }

  llvm::InitializeAllTargetInfos();
  llvm::InitializeAllTargetMCs();
  llvm::InitializeAllAsmParsers();

  GrayCContext Context(std::move(OwningOptionsProvider),
                           false);
  std::vector<GrayCError> Errors =
      runGrayC(Context, OptionsParser->getCompilations(), PathList, BaseFS,
                   EnableCheckProfile, ProfilePrefix);
  bool FoundErrors = llvm::find_if(Errors, [](const GrayCError &E) {
                       return E.DiagLevel == GrayCError::Error;
                     }) != Errors.end();

  const bool DisableFixes = Fix && FoundErrors && !ApplyMutations;

  unsigned WErrorCount = 0;

  // -apply-mutation implies -fix.
  handleErrors(Errors, Context, (ApplyMutations || Fix) && !DisableFixes, WErrorCount,
               BaseFS);

  if (!ExportFixes.empty() && !Errors.empty()) {
    std::error_code EC;
    llvm::raw_fd_ostream OS(ExportFixes, EC, llvm::sys::fs::OF_None);
    if (EC) {
      llvm::errs() << "Error opening output file: " << EC.message() << '\n';
      return 1;
    }
    exportReplacements(FilePath.str(), Errors, OS);
  }

  if (!Quiet) {
    printStats(Context.getStats());
    if (DisableFixes)
      llvm::errs()
          << "Found compiler errors, but -apply-mutation was not specified.\n"
             "Fixes have NOT been applied.\n\n";
  }

  if (WErrorCount) {
    if (!Quiet) {
      StringRef Plural = WErrorCount == 1 ? "" : "s";
      llvm::errs() << WErrorCount << " warning" << Plural << " treated as error"
                   << Plural << "\n";
    }
    return 1;
  }

  if (FoundErrors) {
    // TODO: Figure out when zero exit code should be used with -apply-mutation:
    //   a. when a fix has been applied for an error
    //   b. when a fix has been applied for all errors
    //   c. some other condition.
    // For now always returning zero when -apply-mutation is used.
    if (ApplyMutations)
      return 0;
    if (!Quiet)
      llvm::errs() << "Found compiler error(s).\n";
    return 1;
  }

  return 0;
}

} // namespace grayc
} // namespace clang
