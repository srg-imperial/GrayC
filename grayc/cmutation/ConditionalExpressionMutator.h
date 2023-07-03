//===--- ConditionalExpressionMutator.h - grayc ------------*- C++ -*-===//
//
// Taken from the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

#ifndef LLVM_CLANG_TOOLS_EXTRA_GRAYC_CMUTATION_CONDITIONALEXPRESSIONMUTATOR_H
#define LLVM_CLANG_TOOLS_EXTRA_GRAYC_CMUTATION_CONDITIONALEXPRESSIONMUTATOR_H

#include "../GrayCCheck.h"

namespace clang
{
  namespace grayc
  {
    namespace cmutation
    {

      /// FIXME: Write a short description.
      ///
      class ConditionalExpressionMutator : public GrayCCheck
      {
      public:
        ConditionalExpressionMutator(StringRef Name, GrayCContext *Context)
            : GrayCCheck(Name, Context) { Seed = Context->getOptions().Seed;}
        void registerMatchers(ast_matchers::MatchFinder *Finder) override;
        void check(const ast_matchers::MatchFinder::MatchResult &Result) override;
        llvm::Optional<long> Seed;
        // Taken from LLVM source repo
        // [C++ 5.5] Pointer-to-member operators.
        // [C99 6.5.5] Multiplicative operators.
        // [C99 6.5.6] Additive operators.
        // [C99 6.5.7] Bitwise shift operators.
        //  C++20 [expr.spaceship] Three-way comparison operator.
        // [C99 6.5.8] Relational operators.
        // [C99 6.5.9] Equality operators.
        // [C99 6.5.10] Bitwise AND operator.
        // [C99 6.5.11] Bitwise XOR operator.
        // [C99 6.5.12] Bitwise OR operator.
        // [C99 6.5.13] Logical AND operator.
        // [C99 6.5.14] Logical OR operator.
        // [C99 6.5.17] Comma operator.

        enum ConditionOperatorKind
        {
          PtrMemD,
          PtrMemI,
          Mul,
          Div,
          Rem,
          Add,
          Sub,
          Shl,
          Shr,
          Cmp,
          LT,
          GT,
          LE,
          GE,
          EQ,
          NE,
          And,
          Xor,
          Or,
          LAnd,
          LOr,
          Comma,
          Last
        };
        llvm::StringRef ConditionOperatorStrings[19] = {".*", "->*", "*", "/", "%", "+", "-", "<<", ">>", "<=>", "<", ">", "<=", ">=", "&", "^", "|", "&&", "||"};

      private:
        bool mutateConditional(const ast_matchers::MatchFinder::MatchResult &Result,
                              const BinaryOperator *S, SourceLocation StartLoc,
                              SourceLocation EndLocHint = SourceLocation());
        void buildExpressionVector(const ast_matchers::MatchFinder::MatchResult &Result, llvm::SmallVector<llvm::StringRef, 20> &expressions, const Expr *E);
        llvm::SmallVector<llvm::StringRef, 20> expressions;
      };

    } // namespace cmutation
  }   // namespace grayc
} // namespace clang

#endif // LLVM_CLANG_TOOLS_EXTRA_GRAYC_CMUTATION_CONDITIONALEXPRESSIONMUTATOR_H
