#ifndef __CONSTANT_MUTATOR_H
#define __CONSTANT_MUTATOR_H

#include "clang/AST/AST.h"
#include "clang/AST/ASTConsumer.h"
#include "clang/AST/ASTContext.h"
#include "clang/AST/RecursiveASTVisitor.h"
#include "clang/Driver/Options.h"
#include "clang/Frontend/ASTConsumers.h"
#include "clang/Frontend/CompilerInstance.h"
#include "clang/Frontend/FrontendActions.h"
#include "clang/Rewrite/Core/Rewriter.h"
#include "clang/Tooling/CommonOptionsParser.h"
#include "clang/Tooling/Tooling.h"
#include <string>

using namespace std;
using namespace clang;
using namespace clang::driver;
using namespace clang::tooling;
using namespace llvm;

enum cType {
  cChar,
  cShort,
  cInt,
  cLong,
  cLongLong,
  cUChar,
  cUShort,
  cUInt,
  cULong,
  cULongLong,
};
#define MAX_CONST_TYPE ((cType)(cULongLong + 1))

class ConstantMutatorVisitor
    : public RecursiveASTVisitor<ConstantMutatorVisitor> {
private:
  ASTContext *m_astContext; // used for getting additional AST info
  Rewriter *m_rewriter;
  int latest_array_line_no = -99;

  static bool is_number(const std::string &s);

  /////////////////////////////
  // Integer types mutations //
  /////////////////////////////

  // Guess the constant data type
  static cType guessType(std::string const_str, bool is_sign_flip = 0);

  // mutate constant
  static std::string mutate_constant_integers(std::string constant);

  // Sign flip
  static char sign_flip_char(char constant) { return (~constant); }
  static short sign_flip_short(short constant) { return (~constant); }
  static int sign_flip_int(int constant) { return (~constant); }
  static long sign_flip_long(long constant) { return (~constant); }
  static long long sign_flip_long_long(long long constant) {
    return (~constant);
  }

  // Classic bit flips
  static char bit_flip_char(char constant);
  static unsigned char bit_flip_uchar(unsigned char constant);
  static short bit_flip_short(short constant);
  static unsigned short bit_flip_ushort(unsigned short constant);
  static int bit_flip_int(int constant);
  static unsigned bit_flip_uint(unsigned constant);
  static long bit_flip_long(long constant);
  static unsigned long bit_flip_ulong(unsigned long constant);
  static long long bit_flip_long_long(long long constant);
  static unsigned long long bit_flip_ulong_long(unsigned long long constant);

  // Integers number mutators
  static std::string sign_flip(std::string constant);
  static std::string bit_flip(std::string constant);
  static std::string replace2hex(unsigned length);
  static std::string replace1char(std::string const_str);
  // TODO: can we think of other options to do so?

  ///////////////////////////
  // Float types mutations //
  ///////////////////////////

  static int mutate_constant_float();

public:
  explicit ConstantMutatorVisitor(CompilerInstance *CI, Rewriter *rewriter)
      : m_astContext(&(CI->getASTContext())),
        m_rewriter(rewriter) // initialize private members
  {
    m_rewriter->setSourceMgr(m_astContext->getSourceManager(),
                             m_astContext->getLangOpts());
  }

  bool VisitVarDecl(VarDecl *D);
  bool VisitFloatingLiteral(FloatingLiteral *flit);
  bool VisitIntegerLiteral(IntegerLiteral *ilit);
};

class ConstantMutatorASTConsumer : public ASTConsumer {
private:
  ConstantMutatorVisitor *m_visitor; // doesn't have to be private

public:
  // override the constructor in order to pass CI
  explicit ConstantMutatorASTConsumer(CompilerInstance *CI, Rewriter *rewriter)
      : m_visitor(
            new ConstantMutatorVisitor(CI, rewriter)) // initialize the visitor
  {}

  virtual ~ConstantMutatorASTConsumer() { delete m_visitor; }

  // override this to call our ConstantMutatorVisitor on the entire source file
  virtual void HandleTranslationUnit(ASTContext &Context) override {
    /* we can use ASTContext to get the TranslationUnitDecl, which is
         a single Decl that collectively represents the entire source file */
    m_visitor->TraverseDecl(Context.getTranslationUnitDecl());
  }
};

class ConstantMutatorFrontendAction : public ASTFrontendAction {
private:
  Rewriter *m_rewriter = new Rewriter();

public:
  virtual std::unique_ptr<clang::ASTConsumer>
  CreateASTConsumer(CompilerInstance &CI, StringRef file) final {
    // return std::unique_ptr<clang::ASTConsumer>(new
    // ConstantMutatorASTConsumer(&CI, m_rewriter)); // pass CI pointer to
    // ASTConsumer
    return std::make_unique<ConstantMutatorASTConsumer>(&CI, m_rewriter);
  }

  virtual ~ConstantMutatorFrontendAction() { delete m_rewriter; }

  void EndSourceFileAction() override;
};
#endif // END OF  __CONSTANT_MUTATOR_H
