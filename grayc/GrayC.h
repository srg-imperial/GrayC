//===--- GrayC.h - GrayC -------------------------------*- C++ -*-===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

#ifndef GRAYC_GRAYC_H
#define GRAYC_GRAYC_H

#include "GrayCDiagnosticConsumer.h"
#include "GrayCOptions.h"
#include <memory>
#include <vector>

namespace llvm {
class raw_ostream;
} // namespace llvm

namespace clang {

class ASTConsumer;
class CompilerInstance;
namespace tooling {
class CompilationDatabase;
} // namespace tooling

namespace grayc {

class GrayCCheckFactories;

class GrayCASTConsumerFactory {
public:
  GrayCASTConsumerFactory(
      GrayCContext &Context,
      IntrusiveRefCntPtr<llvm::vfs::OverlayFileSystem> OverlayFS = nullptr);

  /// Returns an ASTConsumer that runs the specified GrayC checks.
  std::unique_ptr<clang::ASTConsumer>
  CreateASTConsumer(clang::CompilerInstance &Compiler, StringRef File);

  /// Get the list of enabled checks.
  std::vector<std::string> getCheckNames();

  /// Get the union of options from all checks.
  GrayCOptions::OptionMap getCheckOptions();

private:
  GrayCContext &Context;
  IntrusiveRefCntPtr<llvm::vfs::OverlayFileSystem> OverlayFS;
  std::unique_ptr<GrayCCheckFactories> CheckFactories;
};

/// Fills the list of check names that are enabled when the provided
/// filters are applied.
std::vector<std::string> getCheckNames(const GrayCOptions &Options,
                                       bool AllowEnablingAnalyzerAlphaCheckers);

/// Returns the effective check-specific options.
///
/// The method configures GrayC with the specified \p Options and collects
/// effective options from all created checks. The returned set of options
/// includes default check-specific options for all keys not overridden by \p
/// Options.
GrayCOptions::OptionMap
getCheckOptions(const GrayCOptions &Options,
                bool AllowEnablingAnalyzerAlphaCheckers);

/// Run a set of GrayC checks on a set of files.
///
/// \param EnableCheckProfile If provided, it enables check profile collection
/// in MatchFinder, and will contain the result of the profile.
/// \param StoreCheckProfile If provided, and EnableCheckProfile is true,
/// the profile will not be output to stderr, but will instead be stored
/// as a JSON file in the specified directory.
std::vector<GrayCError>
runGrayC(clang::grayc::GrayCContext &Context,
             const tooling::CompilationDatabase &Compilations,
             ArrayRef<std::string> InputFiles,
             llvm::IntrusiveRefCntPtr<llvm::vfs::OverlayFileSystem> BaseFS,
             bool EnableCheckProfile = false,
             llvm::StringRef StoreCheckProfile = StringRef());

// FIXME: This interface will need to be significantly extended to be useful.
// FIXME: Implement confidence levels for displaying/fixing errors.
//
/// Displays the found \p Errors to the users. If \p Fix is true, \p
/// Errors containing fixes are automatically applied and reformatted. If no
/// clang-format configuration file is found, the given \P FormatStyle is used.
void handleErrors(llvm::ArrayRef<GrayCError> Errors,
                  GrayCContext &Context, bool Fix,
                  unsigned &WarningsAsErrorsCount,
                  llvm::IntrusiveRefCntPtr<llvm::vfs::FileSystem> BaseFS);

/// Serializes replacements into YAML and writes them to the specified
/// output stream.
void exportReplacements(StringRef MainFilePath,
                        const std::vector<GrayCError> &Errors,
                        raw_ostream &OS);

} // end namespace grayc
} // end namespace clang

#endif // GRAYC_GRAYC_H
