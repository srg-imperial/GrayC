#ifndef __JUMP_MUTATOR_H
#define __JUMP_MUTATOR_H

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

class JumpMutatorVisitor : public RecursiveASTVisitor<JumpMutatorVisitor> {
private:
  ASTContext *m_astContext; // used for getting additional AST info
  Rewriter *m_rewriter;

public:
  explicit JumpMutatorVisitor(CompilerInstance *CI, Rewriter *rewriter)
      : m_astContext(&(CI->getASTContext())),
        m_rewriter(rewriter) // initialize private members
  {
    m_rewriter->setSourceMgr(m_astContext->getSourceManager(),
                             m_astContext->getLangOpts());
  }

  bool VisitWhileStmt(WhileStmt *stmt);
  bool VisitForStmt(ForStmt *stmt);
  std::string pick_break_or_continue();
};

class JumpMutatorASTConsumer : public ASTConsumer {
private:
  JumpMutatorVisitor *m_visitor; // doesn't have to be private

public:
  // override the constructor in order to pass CI
  explicit JumpMutatorASTConsumer(CompilerInstance *CI, Rewriter *rewriter)
      : m_visitor(
            new JumpMutatorVisitor(CI, rewriter)) // initialize the visitor
  {}

  // override this to call our JumpMutatorVisitor on the entire source file
  virtual void HandleTranslationUnit(ASTContext &Context) override {
    /* we can use ASTContext to get the TranslationUnitDecl, which is
         a single Decl that collectively represents the entire source file */
    m_visitor->TraverseDecl(Context.getTranslationUnitDecl());
  }

  virtual ~JumpMutatorASTConsumer() { delete m_visitor; }
};

class JumpMutatorFrontendAction : public ASTFrontendAction {
private:
  Rewriter *m_rewriter = new Rewriter();

public:
  virtual std::unique_ptr<clang::ASTConsumer>
  CreateASTConsumer(CompilerInstance &CI, StringRef file) final {
    return std::make_unique<JumpMutatorASTConsumer>(&CI, m_rewriter);
  }

  virtual ~JumpMutatorFrontendAction() { delete m_rewriter; }

  void EndSourceFileAction() override;
};
#endif // END OF  __JUMP_MUTATOR_H
