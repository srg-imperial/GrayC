//===--- UnaryOperatorCheck.h - GrayC -------------*- C++ -*-===//
//
// Taken from the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

#ifndef GRAYC_READABILITY_UnaryOperatorCheck_H
#define GRAYC_READABILITY_UnaryOperatorCheck_H

#include "../GrayCCheck.h"
#include "../Compatability.h"

namespace clang {
namespace grayc {
namespace cmutation {

/// Transforms increment and decrement unary operators 
/// into their opposite types
///
/// Before:
///
/// \code
///   ++a;
/// \endcode
///
/// After:
///
/// \code
///   --a;
/// \endcode
///
class UnaryOperatorCheck : public GrayCCheck {
public:
  UnaryOperatorCheck(StringRef Name, GrayCContext *Context) : GrayCCheck(Name, Context) {Seed = Context->getOptions().Seed;}
  void registerMatchers(ast_matchers::MatchFinder *Finder) override;
  void check(const ast_matchers::MatchFinder::MatchResult &Result) override;
  OPTIONAL(long) Seed;
private:
  bool mutateUnaryOperator(const ast_matchers::MatchFinder::MatchResult &Result,
                 const UnaryOperator *S, SourceLocation StartLoc,
                 SourceLocation EndLocHint = SourceLocation());
};

} // namespace readability
} // namespace grayc
} // namespace clang

#endif // GRAYC_READABILITY_UnaryOperatorCheck_H
