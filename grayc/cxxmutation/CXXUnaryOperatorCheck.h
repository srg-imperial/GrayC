//===--- CXXUnaryOperatorCheck.h - GrayC -------------*- C++ -*-===//
//
// Taken from the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

#ifndef GRAYC_READABILITY_CXXUnaryOperatorCheck_H
#define GRAYC_READABILITY_CXXUnaryOperatorCheck_H

#include "../GrayCCheck.h"

namespace clang {
namespace grayc {
namespace cxxmutation {

/// Checks that bodies of `if` statements and loops (`for`, `range-for`,
/// `do-while`, and `while`) are inside braces
///
/// Before:
///
/// \code
///   if (condition)
///     statement;
/// \endcode
///
/// After:
///
/// \code
///   if (condition) {
///     statement;
///   }
/// \endcode
///
class CXXUnaryOperatorCheck : public GrayCCheck {
public:
  CXXUnaryOperatorCheck(StringRef Name, GrayCContext *Context);
  void registerMatchers(ast_matchers::MatchFinder *Finder) override;
  void check(const ast_matchers::MatchFinder::MatchResult &Result) override;

private:
  bool mutateUnaryOperator(const ast_matchers::MatchFinder::MatchResult &Result,
                 const UnaryOperator *S, SourceLocation StartLoc,
                 SourceLocation EndLocHint = SourceLocation());
};

} // namespace readability
} // namespace grayc
} // namespace clang

#endif // GRAYC_READABILITY_CXXUnaryOperatorCheck_H
