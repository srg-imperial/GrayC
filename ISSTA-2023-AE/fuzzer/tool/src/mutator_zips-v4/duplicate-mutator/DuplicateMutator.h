#ifndef __DUPLICATE_MUTATOR_H
#define __DUPLICATE_MUTATOR_H

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

using namespace std;
using namespace clang;
using namespace clang::driver;
using namespace clang::tooling;
using namespace llvm;

class DuplicateMutatorVisitor
    : public RecursiveASTVisitor<DuplicateMutatorVisitor> {
private:
  ASTContext *m_astContext; // used for getting additional AST info
  Rewriter *m_rewriter;
  int latest_loop_line = -99;

public:
  explicit DuplicateMutatorVisitor(CompilerInstance *CI, Rewriter *rewriter)
      : m_astContext(&(CI->getASTContext())),
        m_rewriter(rewriter) // initialize private members
  {
    m_rewriter->setSourceMgr(m_astContext->getSourceManager(),
                             m_astContext->getLangOpts());
  }

  bool VisitWhileStmt(WhileStmt *stmt) {
    latest_loop_line = (m_astContext->getSourceManager())
                           .getSpellingLineNumber(stmt->getBeginLoc());
    return true;
  }

  bool VisitForStmt(ForStmt *stmt) {
    latest_loop_line = (m_astContext->getSourceManager())
                           .getSpellingLineNumber(stmt->getBeginLoc());
    return true;
  }

  std::string pick_delete_or_duplicate();
  bool VisitBinaryOperator(BinaryOperator *stmt);
};

class DuplicateMutatorASTConsumer : public ASTConsumer {
private:
  DuplicateMutatorVisitor *m_visitor; // doesn't have to be private

public:
  // override the constructor in order to pass CI
  explicit DuplicateMutatorASTConsumer(CompilerInstance *CI, Rewriter *rewriter)
      : m_visitor(
            new DuplicateMutatorVisitor(CI, rewriter)) // initialize the visitor
  {}

  // override this to call our DuplicateMutatorVisitor on the entire source file
  virtual void HandleTranslationUnit(ASTContext &Context) override {
    /* we can use ASTContext to get the TranslationUnitDecl, which is
         a single Decl that collectively represents the entire source file */
    m_visitor->TraverseDecl(Context.getTranslationUnitDecl());
  }

  virtual ~DuplicateMutatorASTConsumer() { delete m_visitor; }
};

class DuplicateMutatorFrontendAction : public ASTFrontendAction {
private:
  Rewriter *m_rewriter = new Rewriter();

public:
  virtual std::unique_ptr<clang::ASTConsumer>
  CreateASTConsumer(CompilerInstance &CI, StringRef file) final {
    return std::make_unique<DuplicateMutatorASTConsumer>(
        &CI, m_rewriter);
  }

  virtual ~DuplicateMutatorFrontendAction() { delete m_rewriter; }

  void EndSourceFileAction() override;
};
#endif // END OF  __DUPLICATE_MUTATOR_H
