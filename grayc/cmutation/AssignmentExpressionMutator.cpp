//===--- AssignmentExpressionMutator.cpp - grayc ---------------------===//
//
// Taken from the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

#include "AssignmentExpressionMutator.h"
#include "../utils/GrayCRandomManager.h"
#include "clang/AST/ASTContext.h"
#include "clang/ASTMatchers/ASTMatchFinder.h"
#include "clang/ASTMatchers/ASTMatchers.h"
#include "clang/Lex/Lexer.h"

using namespace clang::ast_matchers;

namespace clang
{
  namespace grayc
  {
    namespace cmutation
    {

      void AssignmentExpressionMutator::registerMatchers(MatchFinder *Finder)
      {
        Finder->addMatcher(binaryOperator(isAssignmentOperator()).bind("assignment"), this);
      }

      void AssignmentExpressionMutator::check(const MatchFinder::MatchResult &Result)
      {
        
        const SourceManager &SM = *Result.SourceManager;
        const ASTContext *Context = Result.Context;
        if (auto B = Result.Nodes.getNodeAs<BinaryOperator>("assignment"))
        {
          mutateAssignment(Result, B, B->getBeginLoc(), B->getEndLoc());
        }
        else
        {
          llvm_unreachable("Invalid match");
        }
      }

      bool AssignmentExpressionMutator::mutateAssignment(
          const MatchFinder::MatchResult &Result, const BinaryOperator *B,
          SourceLocation InitialLoc, SourceLocation EndLocHint)
      {
        GrayCRandomManager::CreateInstance(Seed.getValue(), 65000);
        if (!InitialLoc.isValid()){
          GrayCRandomManager::DeleteInstance(Seed.getValue());
          return false;
        }
        const SourceManager &SM = *Result.SourceManager;
        const ASTContext *Context = Result.Context;

        // Treat macros.
        CharSourceRange FileRange = Lexer::makeFileCharRange(
            CharSourceRange::getTokenRange(B->getSourceRange()), SM,
            Context->getLangOpts());
        if (FileRange.isInvalid()){
          GrayCRandomManager::DeleteInstance(Seed.getValue());
          return false;
        }
        InitialLoc = Lexer::makeFileCharRange(
                         CharSourceRange::getCharRange(InitialLoc, B->getBeginLoc()),
                         SM, Context->getLangOpts())
                         .getBegin();

        if (InitialLoc.isInvalid()){
          GrayCRandomManager::DeleteInstance(Seed.getValue());
          return false;
        }
        InitialLoc = B->getRHS()->getBeginLoc();
        assert(InitialLoc.isValid());
        assert(EndLocHint.isValid());
        auto Diag = diag(InitialLoc, "found binary assignment statement to mutate");
        if (isa<const BinaryOperator>(B->getRHS()))
        {
          llvm::WithColor::remark() << "Found RHS expression: " << B->getEndLoc().printToString(SM) << "\n";
          buildExpressionVector(Result, expressions, dyn_cast<const BinaryOperator>(B->getRHS()));
        }
        else
        {
          auto Diag = diag(InitialLoc, "RHS does not contain subexpressions");
        }
        // FIXIT: (Last-11) as, without extra checks, we can't use assignment operators without ensuring that the lvalue is modifiable.
        BinaryOperatorKind BK = BinaryOperatorKind(GrayCRandomManager::GetInstance()->rnd_dice(Last - 11));
        // FIXIT: Avoid using pointer-to-member operators
        llvm::Twine SelectedBinaryOperator(BinaryOperatorStrings[1 + BK]);
        llvm::WithColor::remark() << "Selected binary operator: " << SelectedBinaryOperator.str() << "\n";
        llvm::WithColor::remark() << "Number of subexpressions: " << expressions.size() << "\n";

        assert(expressions.size() > 0 && "No sub-expressions collected!!");
        llvm::Twine NewRHS(expressions[GrayCRandomManager::GetInstance()->rnd_dice(expressions.size()) % expressions.size()]);
        llvm::Twine NewLHS(expressions[(GrayCRandomManager::GetInstance()->rnd_dice(expressions.size())+1) % expressions.size()]);
        llvm::Twine MutatedAssignment(NewLHS + SelectedBinaryOperator + NewRHS);
        
        llvm::WithColor::remark() << "Expression built : " << MutatedAssignment.str() << "\n";

        Diag << FixItHint::CreateReplacement(CharSourceRange::getTokenRange(InitialLoc, EndLocHint), MutatedAssignment.str());
        GrayCRandomManager::DeleteInstance(Seed.getValue());
        return true;
      }
      void AssignmentExpressionMutator::buildExpressionVector(const MatchFinder::MatchResult &Result, llvm::SmallVector<llvm::StringRef, 20> &expressions, const Expr *E)
      {
        if (!isa<BinaryOperator>(E))
        {
          GrayCRandomManager::DeleteInstance(Seed.getValue());
          return;
        }
        else
        {
          const SourceManager &SM = *Result.SourceManager;
          const ASTContext *Context = Result.Context;
          const BinaryOperator *BO = dyn_cast<BinaryOperator>(E);
          Expr *LHS = BO->getLHS()->IgnoreParens()->IgnoreImpCasts();
          Expr *RHS = BO->getRHS()->IgnoreParens()->IgnoreImpCasts();
          SourceRange LHSRange(LHS->getBeginLoc(), LHS->getEndLoc());
          SourceRange RHSRange(RHS->getBeginLoc(), RHS->getEndLoc());
          expressions.push_back(Lexer::getSourceText(CharSourceRange::getTokenRange(LHSRange), SM, Context->getLangOpts()));
          expressions.push_back(Lexer::getSourceText(CharSourceRange::getTokenRange(RHSRange), SM, Context->getLangOpts()));
          llvm::WithColor::remark() << "Number of expressions collected: " << expressions.size() << "\n";
          llvm::WithColor::remark() << "Collected subexpressions: " << Lexer::getSourceText(CharSourceRange::getTokenRange(LHSRange), SM, Context->getLangOpts()) << "," << Lexer::getSourceText(CharSourceRange::getTokenRange(RHSRange), SM, Context->getLangOpts()) << "\n";

          if (isa<BinaryOperator>(LHS))
          {
            buildExpressionVector(Result, expressions, dyn_cast<BinaryOperator>(LHS));
          }
          if (isa<BinaryOperator>(RHS))
          {
            buildExpressionVector(Result, expressions, dyn_cast<BinaryOperator>(RHS));
          }
        }
      }

    } // namespace cmutation
  }   // namespace grayc
} // namespace clang
