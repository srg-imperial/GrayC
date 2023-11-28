//===--- UnaryOperatorCheck.cpp - GrayC ---------------------===//
//
// Taken from the LLVM Project, under the Apache License v2.0 with LLVM
// Exceptions. See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

#include "UnaryOperatorCheck.h"
#include "../utils/GrayCRandomManager.h"
#include "clang/AST/ASTContext.h"
#include "clang/ASTMatchers/ASTMatchers.h"
#include "clang/Lex/Lexer.h"

using namespace clang::ast_matchers;

namespace clang {
namespace grayc {
namespace cmutation {
namespace {

tok::TokenKind getTokenKind(SourceLocation Loc, const SourceManager &SM,
                            const ASTContext *Context) {
  Token Tok;
  SourceLocation Beginning =
      Lexer::GetBeginningOfToken(Loc, SM, Context->getLangOpts());
  const bool Invalid =
      Lexer::getRawToken(Beginning, Tok, SM, Context->getLangOpts());
  assert(!Invalid && "Expected a valid token.");

  if (Invalid)
    return tok::NUM_TOKENS;

  return Tok.getKind();
}

SourceLocation forwardSkipWhitespaceAndComments(SourceLocation Loc,
                                                const SourceManager &SM,
                                                const ASTContext *Context) {
  assert(Loc.isValid());
  for (;;) {
    while (isWhitespace(*SM.getCharacterData(Loc)))
      Loc = Loc.getLocWithOffset(1);

    tok::TokenKind TokKind = getTokenKind(Loc, SM, Context);
    if (TokKind != tok::comment)
      return Loc;

    // Fast-forward current token.
    Loc = Lexer::getLocForEndOfToken(Loc, 0, SM, Context->getLangOpts());
  }
}

SourceLocation findEndLocation(SourceLocation LastTokenLoc,
                               const SourceManager &SM,
                               const ASTContext *Context) {
  SourceLocation Loc =
      Lexer::GetBeginningOfToken(LastTokenLoc, SM, Context->getLangOpts());
  // Loc points to the beginning of the last (non-comment non-ws) token
  // before end or ';'.
  assert(Loc.isValid());
  bool SkipEndWhitespaceAndComments = true;
  tok::TokenKind TokKind = getTokenKind(Loc, SM, Context);
  if (TokKind == tok::NUM_TOKENS || TokKind == tok::semi ||
      TokKind == tok::r_brace) {
    // If we are at ";" or "}", we found the last token. We could use as well
    // `if (isa<NullStmt>(S))`, but it wouldn't work for nested statements.
    SkipEndWhitespaceAndComments = false;
  }

  Loc = Lexer::getLocForEndOfToken(Loc, 0, SM, Context->getLangOpts());
  // Loc points past the last token before end or after ';'.
  if (SkipEndWhitespaceAndComments) {
    Loc = forwardSkipWhitespaceAndComments(Loc, SM, Context);
    tok::TokenKind TokKind = getTokenKind(Loc, SM, Context);
    if (TokKind == tok::semi)
      Loc = Lexer::getLocForEndOfToken(Loc, 0, SM, Context->getLangOpts());
  }

  for (;;) {
    assert(Loc.isValid());
    while (isHorizontalWhitespace(*SM.getCharacterData(Loc))) {
      Loc = Loc.getLocWithOffset(1);
    }

    if (isVerticalWhitespace(*SM.getCharacterData(Loc))) {
      // EOL, insert brace before.
      break;
    }
    tok::TokenKind TokKind = getTokenKind(Loc, SM, Context);
    if (TokKind != tok::comment) {
      // Non-comment token, insert brace before.
      break;
    }

    SourceLocation TokEndLoc =
        Lexer::getLocForEndOfToken(Loc, 0, SM, Context->getLangOpts());
    SourceRange TokRange(Loc, TokEndLoc);
    StringRef Comment = Lexer::getSourceText(
        CharSourceRange::getTokenRange(TokRange), SM, Context->getLangOpts());
    if (Comment.startswith("/*") && Comment.find('\n') != StringRef::npos) {
      // Multi-line block comment, insert brace before.
      break;
    }
    // else: Trailing comment, insert brace after the newline.

    // Fast-forward current token.
    Loc = TokEndLoc;
  }
  return Loc;
}

} // namespace

void UnaryOperatorCheck::registerMatchers(MatchFinder *Finder) {
  Finder->addMatcher(unaryOperator().bind("unary-operator"), this);
}

void UnaryOperatorCheck::check(const MatchFinder::MatchResult &Result) {
  const SourceManager &SM = *Result.SourceManager;
  const ASTContext *Context = Result.Context;
  llvm::WithColor::remark() << "Using SEED: " << Seed << "\n";
  if (auto S = Result.Nodes.getNodeAs<UnaryOperator>("unary-operator")) {
    mutateUnaryOperator(Result, S, S->getOperatorLoc(), S->getExprLoc());
  } else {
    llvm_unreachable("Invalid match");
  }
}

bool UnaryOperatorCheck::mutateUnaryOperator(
    const MatchFinder::MatchResult &Result, const UnaryOperator *S,
    SourceLocation InitialLoc, SourceLocation EndLocHint) {
  GrayCRandomManager::CreateInstance(Seed.getValue(), 65000);
  if (GrayCRandomManager::GetInstance()->rnd_yes_no(0.6)) {
    llvm::WithColor::note()
        << "Ignoring potential unary operator mutation due to the given seed\n";
    GrayCRandomManager::DeleteInstance(Seed.getValue());
    return true;
  }
  if (!S->isIncrementOp() && !S->isDecrementOp()) {
    return false;
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
  auto Diag = diag(InitialLoc, "found candidate unary operator to mutate");

  // Decide opcode and hence the mutated opcode
  std::string MutatedOperator;
  MutatedOperator = S->getOpcode() == UO_PreInc ? "--" : "++";

  Diag << FixItHint::CreateReplacement(
      CharSourceRange::getTokenRange(InitialLoc, EndLocHint), MutatedOperator);

  GrayCRandomManager::DeleteInstance(Seed.getValue());
  return true;
}

} // namespace cmutation
} // namespace grayc
} // namespace clang
