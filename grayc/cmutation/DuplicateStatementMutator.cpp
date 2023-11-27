//===--- DuplicateStatementMutator.cpp - grayc -----------------------===//
//
// Taken from the LLVM Project, under the Apache License v2.0 with LLVM
// Exceptions. See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

#include "DuplicateStatementMutator.h"
#include "clang/AST/ASTContext.h"
#include "clang/ASTMatchers/ASTMatchFinder.h"
#include "clang/Lex/Lexer.h"

using namespace clang::ast_matchers;

namespace clang
{
  namespace grayc
  {
    namespace cmutation
    {

      void DuplicateStatementMutator::registerMatchers(MatchFinder *Finder)
      {
        Finder->addMatcher(binaryOperator(
                               hasOperatorName("="),
                               hasLHS(declRefExpr().bind("lhs")),
                               hasRHS(expr().bind("rhs")))
                               .bind("binaryOp"),
                           this);
      }

      void DuplicateStatementMutator::check(const MatchFinder::MatchResult &Result)
      {
        srand(Seed.getValue());
        const SourceManager &SM = *Result.SourceManager;
        const ASTContext *Context = Result.Context;

        llvm::WithColor::remark() << "Using SEED: " << Seed << "\n";
        const auto *BinaryOp = Result.Nodes.getNodeAs<BinaryOperator>("binaryOp");
        // Treat macros.
        CharSourceRange FileRange = Lexer::makeFileCharRange(
            CharSourceRange::getTokenRange(BinaryOp->getSourceRange()), SM,
            Context->getLangOpts());
        if (FileRange.isInvalid())
        {
          return;
        }
        if (BinaryOp)
        {
          const auto *LHS = Result.Nodes.getNodeAs<DeclRefExpr>("lhs");
          const auto *RHS = Result.Nodes.getNodeAs<Expr>("rhs");

          if (LHS && RHS)
          {
            // Duplicate the binary assignment statement.
            SourceLocation StartLoc = BinaryOp->getBeginLoc();
            SourceLocation EndLoc = BinaryOp->getEndLoc();
            SourceRange AssignmentOperatorRange(StartLoc, EndLoc);
            std::string ExtractedString = std::string(Lexer::getSourceText(CharSourceRange::getTokenRange(AssignmentOperatorRange), SM, Context->getLangOpts()));
            std::string DuplicatedStringToInsert = ExtractedString + ";";
            auto Diag = diag(StartLoc, "found statement to duplicate");
            double to_mutate = rand()%2;
            llvm::WithColor::remark()<<"Selected seed-dictated value of "<< to_mutate << "\n";
            if (to_mutate<1){
            llvm::WithColor::remark() << "Adding duplicated statement after "
                                      << RHS->getEndLoc().getLocWithOffset(2).printToString(SM) << "\n";
            Diag << FixItHint::CreateInsertion(RHS->getEndLoc().getLocWithOffset(2), DuplicatedStringToInsert);
            }
            else {
                llvm::WithColor::remark()<<"Skipping mutation due to selected seed-dictated value of %l"<< to_mutate << " being less than 1\n";

            }
          }
        }
      }
    } // namespace cmutation
  }   // namespace grayc
} // namespace clang
