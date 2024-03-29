//===--- LexerUtils.cpp - GrayC---------------------------------------===//
//
// Taken from the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

#include "LexerUtils.h"
#include "clang/Basic/SourceManager.h"

namespace clang {
namespace grayc {
namespace utils {
namespace lexer {

Token getPreviousToken(SourceLocation Location, const SourceManager &SM,
                       const LangOptions &LangOpts, bool SkipComments) {
  Token Token;
  Token.setKind(tok::unknown);

  Location = Location.getLocWithOffset(-1);
  if (Location.isInvalid())
      return Token;

  auto StartOfFile = SM.getLocForStartOfFile(SM.getFileID(Location));
  while (Location != StartOfFile) {
    Location = Lexer::GetBeginningOfToken(Location, SM, LangOpts);
    if (!Lexer::getRawToken(Location, Token, SM, LangOpts) &&
        (!SkipComments || !Token.is(tok::comment))) {
      break;
    }
    Location = Location.getLocWithOffset(-1);
  }
  return Token;
}

SourceLocation findPreviousTokenStart(SourceLocation Start,
                                      const SourceManager &SM,
                                      const LangOptions &LangOpts) {
  if (Start.isInvalid() || Start.isMacroID())
    return SourceLocation();

  SourceLocation BeforeStart = Start.getLocWithOffset(-1);
  if (BeforeStart.isInvalid() || BeforeStart.isMacroID())
    return SourceLocation();

  return Lexer::GetBeginningOfToken(BeforeStart, SM, LangOpts);
}

SourceLocation findPreviousTokenKind(SourceLocation Start,
                                     const SourceManager &SM,
                                     const LangOptions &LangOpts,
                                     tok::TokenKind TK) {
  if (Start.isInvalid() || Start.isMacroID())
    return SourceLocation();

  while (true) {
    SourceLocation L = findPreviousTokenStart(Start, SM, LangOpts);
    if (L.isInvalid() || L.isMacroID())
      return SourceLocation();

    Token T;
    if (Lexer::getRawToken(L, T, SM, LangOpts, /*IgnoreWhiteSpace=*/true))
      return SourceLocation();

    if (T.is(TK))
      return T.getLocation();

    Start = L;
  }
}

SourceLocation findNextTerminator(SourceLocation Start, const SourceManager &SM,
                                  const LangOptions &LangOpts) {
  return findNextAnyTokenKind(Start, SM, LangOpts, tok::comma, tok::semi);
}

Optional<Token> findNextTokenSkippingComments(SourceLocation Start,
                                              const SourceManager &SM,
                                              const LangOptions &LangOpts) {
  Optional<Token> CurrentToken;
  do {
    CurrentToken = Lexer::findNextToken(Start, SM, LangOpts);
  } while (CurrentToken && CurrentToken->is(tok::comment));
  return CurrentToken;
}

bool rangeContainsExpansionsOrDirectives(SourceRange Range,
                                         const SourceManager &SM,
                                         const LangOptions &LangOpts) {
  assert(Range.isValid() && "Invalid Range for relexing provided");
  SourceLocation Loc = Range.getBegin();

  while (Loc < Range.getEnd()) {
    if (Loc.isMacroID())
      return true;

    llvm::Optional<Token> Tok = Lexer::findNextToken(Loc, SM, LangOpts);

    if (!Tok)
      return true;

    if (Tok->is(tok::hash))
      return true;

    Loc = Lexer::getLocForEndOfToken(Loc, 0, SM, LangOpts).getLocWithOffset(1);
  }

  return false;
}

llvm::Optional<Token> getQualifyingToken(tok::TokenKind TK,
                                         CharSourceRange Range,
                                         const ASTContext &Context,
                                         const SourceManager &SM) {
  assert((TK == tok::kw_const || TK == tok::kw_volatile ||
          TK == tok::kw_restrict) &&
         "TK is not a qualifier keyword");
  std::pair<FileID, unsigned> LocInfo = SM.getDecomposedLoc(Range.getBegin());
  StringRef File = SM.getBufferData(LocInfo.first);
  Lexer RawLexer(SM.getLocForStartOfFile(LocInfo.first), Context.getLangOpts(),
                 File.begin(), File.data() + LocInfo.second, File.end());
  llvm::Optional<Token> LastMatchBeforeTemplate;
  llvm::Optional<Token> LastMatchAfterTemplate;
  bool SawTemplate = false;
  Token Tok;
  while (!RawLexer.LexFromRawLexer(Tok) &&
         Range.getEnd() != Tok.getLocation() &&
         !SM.isBeforeInTranslationUnit(Range.getEnd(), Tok.getLocation())) {
    if (Tok.is(tok::raw_identifier)) {
      IdentifierInfo &Info = Context.Idents.get(
          StringRef(SM.getCharacterData(Tok.getLocation()), Tok.getLength()));
      Tok.setIdentifierInfo(&Info);
      Tok.setKind(Info.getTokenID());
    }
    if (Tok.is(tok::less))
      SawTemplate = true;
    else if (Tok.isOneOf(tok::greater, tok::greatergreater))
      LastMatchAfterTemplate = None;
    else if (Tok.is(TK)) {
      if (SawTemplate)
        LastMatchAfterTemplate = Tok;
      else
        LastMatchBeforeTemplate = Tok;
    }
  }
  return LastMatchAfterTemplate != None ? LastMatchAfterTemplate
                                        : LastMatchBeforeTemplate;
}
} // namespace lexer
} // namespace utils
} // namespace grayc
} // namespace clang
