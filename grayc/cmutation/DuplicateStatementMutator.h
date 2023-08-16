//===--- DuplicateStatementMutator.h - grayc ---------------*- C++ -*-===//
//
// Taken from the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

#ifndef LLVM_CLANG_TOOLS_EXTRA_GRAYC_CMUTATION_DUPLICATESTATEMENTMUTATOR_H
#define LLVM_CLANG_TOOLS_EXTRA_GRAYC_CMUTATION_DUPLICATESTATEMENTMUTATOR_H

#include "../GrayCCheck.h"

namespace clang {
namespace grayc {
namespace cmutation {

/// FIXME: Write a short description.
///
class DuplicateStatementMutator : public GrayCCheck {
public:
  DuplicateStatementMutator(StringRef Name, GrayCContext *Context)
      : GrayCCheck(Name, Context) {Seed = Context->getOptions().Seed;}
  void registerMatchers(ast_matchers::MatchFinder *Finder) override;
  void check(const ast_matchers::MatchFinder::MatchResult &Result) override;
  llvm::Optional<long> Seed;
};

} // namespace cmutation
} // namespace grayc
} // namespace clang

#endif // LLVM_CLANG_TOOLS_EXTRA_GRAYC_CMUTATION_DUPLICATESTATEMENTMUTATOR_H
