//===--- JumpMutator.cpp - grayc -------------------------------------===//
//
// Taken from the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

#include "JumpMutator.h"
#include "clang/AST/ASTContext.h"
#include "clang/ASTMatchers/ASTMatchFinder.h"
#include "clang/Lex/Lexer.h"
#include "../utils/GrayCRandomManager.h"


using namespace clang::ast_matchers;

namespace clang
{
  namespace grayc
  {
    namespace cmutation
    {

      void JumpMutator::registerMatchers(MatchFinder *Finder)
      {
        // FIXIT: Extend to nested loops, for now only match non-nested loops.
        Finder->addMatcher(forStmt(unless(hasDescendant(forStmt()))).bind("no-nest-for"), this);
        Finder->addMatcher(whileStmt(unless(hasDescendant(whileStmt()))).bind("no-nest-while"), this);
        Finder->addMatcher(doStmt(unless(hasDescendant(doStmt()))).bind("no-nest-do"), this);
      }

      void JumpMutator::check(const MatchFinder::MatchResult &Result)
      {
        
        if (auto F = Result.Nodes.getNodeAs<ForStmt>("no-nest-for"))
        {
          mutateLoop(Result, For, F, F->getBeginLoc(), F->getEndLoc());
        }
        else if (auto W = Result.Nodes.getNodeAs<WhileStmt>("no-nest-while"))
        {
          mutateLoop(Result, While, W, W->getBeginLoc(), W->getEndLoc());
        }
        else if (auto D = Result.Nodes.getNodeAs<DoStmt>("no-nest-while"))
        {
          mutateLoop(Result, DoWhile, D, D->getBeginLoc(), D->getEndLoc());
        }
        else
        {
          llvm_unreachable("Invalid match");
        }
      }
      bool JumpMutator::mutateLoop(
          const MatchFinder::MatchResult &Result, LoopKind L, const Stmt *S,
          SourceLocation InitialLoc, SourceLocation EndLocHint)
      {
        GrayCRandomManager::CreateInstance(Seed.getValue(), 65000);
        if (GrayCRandomManager::GetInstance()->rnd_yes_no(0.4)){
          llvm::WithColor::note()
            << "Ignoring potential jump statement mutation due to the given seed\n";
          GrayCRandomManager::DeleteInstance(Seed.getValue());
          return true;
        }
        if (!InitialLoc.isValid())
          return false;
        const SourceManager &SM = *Result.SourceManager;
        const ASTContext *Context = Result.Context;

        // Treat macros.
        CharSourceRange FileRange = Lexer::makeFileCharRange(
            CharSourceRange::getTokenRange(S->getSourceRange()), SM,
            Context->getLangOpts());
        if (FileRange.isInvalid())
          return false;
        InitialLoc = Lexer::makeFileCharRange(
                         CharSourceRange::getCharRange(InitialLoc, S->getBeginLoc()),
                         SM, Context->getLangOpts())
                         .getBegin();

        if (InitialLoc.isInvalid())
          return false;
        assert(EndLocHint.isValid());
        const Stmt *Body;
        std::string JumpConstruct((GrayCRandomManager::GetInstance()->rnd_yes_no(0.5)) == 1 ? "{break;}" : "{continue;}");

        switch (L)
        {
        case For:
          assert(isa<ForStmt>(S) && "Error matching nodes!!");
          if (dyn_cast<ForStmt>(S)->getBody())
          {
            Body = dyn_cast<ForStmt>(S)->getBody();
            auto Diag = diag(Body->getEndLoc(), "found for loop to mutate");
            llvm::WithColor::remark() << "Adding jump statement (`break` or `continue`) at " << Body->getEndLoc().printToString(SM) << "\n";
            Diag << FixItHint::CreateInsertion(Body->getEndLoc(), JumpConstruct);
          }
          else
          {
            return false;
          }
          break;
        case While:
          assert(isa<WhileStmt>(S) && "Error matching nodes!!");
          if (dyn_cast<WhileStmt>(S)->getBody())
          {
            Body = dyn_cast<WhileStmt>(S)->getBody();
            auto Diag = diag(InitialLoc, "found while loop to mutate");
            llvm::WithColor::remark() << "Adding jump statement (`break` or `continue`) at " << Body->getEndLoc().printToString(SM) << "\n";
            Diag << FixItHint::CreateInsertion(Body->getBeginLoc(), JumpConstruct);
          }
          else
          {
            return false;
          }
          break;
        case DoWhile:
          assert(isa<DoStmt>(S) && "Error matching nodes!!");
          if (dyn_cast<DoStmt>(S)->getBody())
          {
            Body = dyn_cast<DoStmt>(S)->getBody();
            auto Diag = diag(InitialLoc, "found do while loop to mutate");
            llvm::WithColor::remark() << "Adding jump statement (`break` or `continue`) at " << Body->getEndLoc().printToString(SM) << "\n";
            Diag << FixItHint::CreateInsertion(Body->getBeginLoc(), JumpConstruct);
          }
          else
          {
            return false;
          }
          break;
        default:
          return false;
        }

        return true;
      }
    } // namespace cmutation
  }   // namespace grayc
} // namespace clang
