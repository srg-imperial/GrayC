//===--- ConditionalExpressionMutator.cpp - grayc --------------------===//
//
// Taken from the LLVM Project, under the Apache License v2.0 with LLVM
// Exceptions. See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

#include "ConditionalExpressionMutator.h"
#include "../utils/GrayCRandomManager.h"
#include "clang/AST/ASTContext.h"
#include "clang/ASTMatchers/ASTMatchFinder.h"
#include "clang/Lex/Lexer.h"

using namespace clang::ast_matchers;

namespace clang {
namespace grayc {
namespace cmutation {

void ConditionalExpressionMutator::registerMatchers(MatchFinder *Finder) {
  Finder->addMatcher(
      binaryOperator(unless(isAssignmentOperator())).bind("conditional"), this);
}

void ConditionalExpressionMutator::check(
    const MatchFinder::MatchResult &Result) {
  srand(Seed.getValue());
  const SourceManager &SM = *Result.SourceManager;
  const ASTContext *Context = Result.Context;
  llvm::WithColor::remark() << "Using SEED: " << Seed << "\n";
  if (auto C = Result.Nodes.getNodeAs<BinaryOperator>("conditional")) {
    mutateConditional(Result, C, C->getBeginLoc(), C->getEndLoc());
  } else {
    llvm_unreachable("Invalid match");
  }
}
bool ConditionalExpressionMutator::mutateConditional(
    const MatchFinder::MatchResult &Result, const BinaryOperator *C,
    SourceLocation InitialLoc, SourceLocation EndLocHint) {
  GrayCRandomManager::CreateInstance(Seed.getValue(), 65000);
  if (GrayCRandomManager::GetInstance()->rnd_yes_no(0.6)) {
    llvm::WithColor::note()
        << "Ignoring potential expression mutation due to the given seed\n";
    GrayCRandomManager::DeleteInstance(Seed.getValue());
    return true;
  }
  if (!InitialLoc.isValid()){
    GrayCRandomManager::DeleteInstance(Seed.getValue());
    return false;
  }
  const SourceManager &SM = *Result.SourceManager;
  const ASTContext *Context = Result.Context;

  // Treat macros.
  CharSourceRange FileRange = Lexer::makeFileCharRange(
      CharSourceRange::getTokenRange(C->getSourceRange()), SM,
      Context->getLangOpts());
  if (FileRange.isInvalid()){
    GrayCRandomManager::DeleteInstance(Seed.getValue());
    return false;
  }
  InitialLoc = Lexer::makeFileCharRange(
                   CharSourceRange::getCharRange(InitialLoc, C->getBeginLoc()),
                   SM, Context->getLangOpts())
                   .getBegin();

  if (InitialLoc.isInvalid()){
    GrayCRandomManager::DeleteInstance(Seed.getValue());
    return false;
  }
  assert(EndLocHint.isValid());
  auto Diag = diag(InitialLoc, "found conditional statement to mutate");
  buildExpressionVector(Result, expressions, C);
  if (expressions.size() == 0) {
    llvm::WithColor::remark() << "No subexpressions collected!!";
    GrayCRandomManager::DeleteInstance(Seed.getValue());
    return false;
  }
  ConditionOperatorKind CK = ConditionOperatorKind(GrayCRandomManager::GetInstance()->rnd_dice(Last));
  llvm::Twine SelectedConditionOperator(ConditionOperatorStrings[CK]);
  llvm::WithColor::remark()
      << "Selected operator: " << SelectedConditionOperator.str() << "\n";
  llvm::WithColor::remark()
      << "Number of subexpressions: " << expressions.size() << "\n";
  llvm::outs()<<GrayCRandomManager::GetInstance()->rnd_dice(expressions.size())<<"\n";
  llvm::Twine NewRHS(expressions[GrayCRandomManager::GetInstance()->rnd_dice(expressions.size())]);
  llvm::Twine NewLHS(expressions[(GrayCRandomManager::GetInstance()->rnd_dice(expressions.size())+1)%expressions.size()]);
  llvm::Twine MutatedConditional(NewLHS + SelectedConditionOperator + NewRHS);

  llvm::WithColor::remark()
      << "Expression built : " << MutatedConditional.str() << "\n";

  Diag << FixItHint::CreateReplacement(
      CharSourceRange::getTokenRange(InitialLoc, EndLocHint),
      MutatedConditional.str());
  GrayCRandomManager::DeleteInstance(Seed.getValue());
  return true;
}
void ConditionalExpressionMutator::buildExpressionVector(
    const MatchFinder::MatchResult &Result,
    llvm::SmallVector<llvm::StringRef, 20> &expressions, const Expr *E) {
  if (!isa<BinaryOperator>(E)) {
    return;
  } else {
    const SourceManager &SM = *Result.SourceManager;
    const ASTContext *Context = Result.Context;
    const BinaryOperator *BO = dyn_cast<BinaryOperator>(E);
    Expr *LHS = BO->getLHS()->IgnoreParens()->IgnoreImpCasts();
    Expr *RHS = BO->getRHS()->IgnoreParens()->IgnoreImpCasts();
    SourceRange LHSRange(LHS->getBeginLoc(), LHS->getEndLoc());
    SourceRange RHSRange(RHS->getBeginLoc(), RHS->getEndLoc());
    expressions.push_back(Lexer::getSourceText(
        CharSourceRange::getTokenRange(LHSRange), SM, Context->getLangOpts()));
    expressions.push_back(Lexer::getSourceText(
        CharSourceRange::getTokenRange(RHSRange), SM, Context->getLangOpts()));
    llvm::WithColor::remark()
        << "Number of expressions collected: " << expressions.size() << "\n";
    llvm::WithColor::remark()
        << "Collected subexpressions: "
        << Lexer::getSourceText(CharSourceRange::getTokenRange(LHSRange), SM,
                                Context->getLangOpts())
        << ","
        << Lexer::getSourceText(CharSourceRange::getTokenRange(RHSRange), SM,
                                Context->getLangOpts())
        << "\n";

    if (isa<BinaryOperator>(LHS)) {
      buildExpressionVector(Result, expressions, dyn_cast<BinaryOperator>(LHS));
    }
    if (isa<BinaryOperator>(RHS)) {
      buildExpressionVector(Result, expressions, dyn_cast<BinaryOperator>(RHS));
    }
  }
}
} // namespace cmutation
} // namespace grayc
} // namespace clang
