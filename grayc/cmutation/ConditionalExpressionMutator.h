//===--- ConditionalExpressionMutator.h - grayc ------------*- C++ -*-===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

#ifndef LLVM_CLANG_TOOLS_EXTRA_GRAYC_CMUTATION_CONDITIONALEXPRESSIONMUTATOR_H
#define LLVM_CLANG_TOOLS_EXTRA_GRAYC_CMUTATION_CONDITIONALEXPRESSIONMUTATOR_H

#include "../GrayCCheck.h"

namespace clang {
namespace grayc {
namespace cmutation {

/// FIXME: Write a short description.
///
class ConditionalExpressionMutator : public GrayCCheck {
public:
  ConditionalExpressionMutator(StringRef Name, GrayCContext *Context)
      : GrayCCheck(Name, Context) {}
  void registerMatchers(ast_matchers::MatchFinder *Finder) override;
  void check(const ast_matchers::MatchFinder::MatchResult &Result) override;
};

} // namespace cmutation
} // namespace grayc
} // namespace clang

#endif // LLVM_CLANG_TOOLS_EXTRA_GRAYC_CMUTATION_CONDITIONALEXPRESSIONMUTATOR_H
