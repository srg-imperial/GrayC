//===--- ConditionalExpressionMutator.cpp - grayc --------------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

#include "ConditionalExpressionMutator.h"
#include "clang/AST/ASTContext.h"
#include "clang/ASTMatchers/ASTMatchFinder.h"

using namespace clang::ast_matchers;

namespace clang {
namespace grayc {
namespace cmutation {

void ConditionalExpressionMutator::registerMatchers(MatchFinder *Finder) {
  Finder->addMatcher(binaryOperator(isAssignmentOperator()).bind("conditional"), this);
}

void ConditionalExpressionMutator::check(const MatchFinder::MatchResult &Result) {
  const auto *MatchedConditional = Result.Nodes.getNodeAs<BinaryOperator>("conditional");
}

} // namespace cmutation
} // namespace grayc
} // namespace clang
