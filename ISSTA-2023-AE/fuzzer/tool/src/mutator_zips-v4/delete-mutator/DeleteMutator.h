#ifndef __DELETE_MUTATOR_H
#define __DELETE_MUTATOR_H
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

class DeleteMutatorVisitor : public RecursiveASTVisitor<DeleteMutatorVisitor> {
private:
  ASTContext *m_astContext; // used for getting additional AST info
  Rewriter *m_rewriter;

public:
  explicit DeleteMutatorVisitor(ASTContext *astContext, Rewriter *rewriter)
      : m_astContext(astContext),
        m_rewriter(rewriter) // initialize private members
  {
    m_rewriter->setSourceMgr(m_astContext->getSourceManager(),
                             m_astContext->getLangOpts());
  }

  // Caused memory leak because of how RecursiveASTVisitor is defined
  // virtual ~DeleteMutatorVisitor() { m_rewriter=0; delete m_astContext; }

  // Methods
  bool VisitWhileStmt(WhileStmt *stmt);
  bool VisitIfStmt(IfStmt *stmt);
};

class DeleteMutatorASTConsumer : public ASTConsumer {
private:
  DeleteMutatorVisitor *m_visitor; // doesn't have to be private

public:
  // override the constructor in order to pass CI
  explicit DeleteMutatorASTConsumer(ASTContext *astContext, Rewriter *rewriter)
      : m_visitor(new DeleteMutatorVisitor(astContext,
                                           rewriter)) // initialize the visitor
  {}

  // override this to call our DeleteMutatorVisitor on the entire source file
  virtual void HandleTranslationUnit(ASTContext &Context) override {
    /* we can use ASTContext to get the TranslationUnitDecl, which is
         a single Decl that collectively represents the entire source file */
    m_visitor->TraverseDecl(Context.getTranslationUnitDecl());
  }

  virtual ~DeleteMutatorASTConsumer() { delete m_visitor; }
};

class DeleteMutatorFrontendAction : public ASTFrontendAction {
private:
  Rewriter *m_rewriter = new Rewriter();
  ASTContext *m_astContext = 0; // used for getting additional AST info

public:
  virtual std::unique_ptr<clang::ASTConsumer>
  CreateASTConsumer(CompilerInstance &CI, StringRef file) final {
    m_astContext = (&(CI.getASTContext()));
    // return std::unique_ptr<clang::ASTConsumer>(new
    // DeleteMutatorASTConsumer(m_astContext, m_rewriter));
    return std::make_unique<DeleteMutatorASTConsumer>(m_astContext, m_rewriter);
  }

  virtual ~DeleteMutatorFrontendAction() {
    delete m_rewriter;
    m_astContext = 0;
  }

  void EndSourceFileAction() override;
};

#endif // END OF  __DELETE_MUTATOR_H