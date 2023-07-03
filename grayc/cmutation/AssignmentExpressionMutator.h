//===--- AssignmentExpressionMutator.h - grayc -------------*- C++ -*-===//
//
// Taken from the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

#ifndef LLVM_CLANG_TOOLS_EXTRA_GRAYC_CMUTATION_ASSIGNMENTEXPRESSIONMUTATOR_H
#define LLVM_CLANG_TOOLS_EXTRA_GRAYC_CMUTATION_ASSIGNMENTEXPRESSIONMUTATOR_H

#include "../GrayCCheck.h"

namespace clang
{
  namespace grayc
  {
    namespace cmutation
    {

      /// Expands binary assignments based on their
      /// subexpressions.
      ///
      /// Before:
      ///
      /// \code
      ///   a=a+b
      /// \endcode
      ///
      /// After:
      ///
      /// \code
      ///  a=a+(a/c)
      /// \endcode
      ///
      class AssignmentExpressionMutator : public GrayCCheck
      {
      public:
        AssignmentExpressionMutator(StringRef Name, GrayCContext *Context)
            : GrayCCheck(Name, Context) {}
        void registerMatchers(ast_matchers::MatchFinder *Finder) override;
        void check(const ast_matchers::MatchFinder::MatchResult &Result) override;

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
        // [C99 6.5.16] Assignment operators.
        // [C99 6.5.17] Comma operator.

        enum BinaryOperatorKind
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
          Assign,
          MulAssign,
          DivAssign,
          RemAssign,
          AddAssign,
          SubAssign,
          ShlAssign,
          ShrAssign,
          XorAssign,
          OrAssign,
          Comma,
          Last
        };
        llvm::StringRef BinaryOperatorStrings[32] = {".*", "->*", "*", "/", "%", "+", "-", "<<", ">>", "<=>", "<", ">", "<=", ">=", "&", "^", "|", "&&", "||", "=", "*=", "/=", "%=", "+=", "-=", "<<=", ">>=", "&=", "^=", "|="};

      private:
        bool mutateAssignment(const ast_matchers::MatchFinder::MatchResult &Result,
                              const BinaryOperator *S, SourceLocation StartLoc,
                              SourceLocation EndLocHint = SourceLocation());
        void buildExpressionVector(const ast_matchers::MatchFinder::MatchResult &Result, llvm::SmallVector<llvm::StringRef, 20> &expressions, const Expr *E);
        llvm::SmallVector<llvm::StringRef, 20> expressions;
      };

    } // namespace cmutation
  }   // namespace grayc
} // namespace clang

#endif // LLVM_CLANG_TOOLS_EXTRA_GRAYC_CMUTATION_ASSIGNMENTEXPRESSIONMUTATOR_H
