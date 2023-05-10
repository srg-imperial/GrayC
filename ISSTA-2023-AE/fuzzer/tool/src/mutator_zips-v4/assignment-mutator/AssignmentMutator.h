#ifndef __ASSIGNMENT_MUTATOR_H
#define __ASSIGNMENT_MUTATOR_H

#include "clang/Driver/Options.h"
#include "clang/AST/AST.h"
#include "clang/AST/ASTContext.h"
#include "clang/AST/ASTConsumer.h"
#include "clang/AST/RecursiveASTVisitor.h"
#include "clang/Frontend/ASTConsumers.h"
#include "clang/Frontend/FrontendActions.h"
#include "clang/Frontend/CompilerInstance.h"
#include "clang/Tooling/CommonOptionsParser.h"
#include "clang/Tooling/Tooling.h"
#include "clang/Rewrite/Core/Rewriter.h"

using namespace std;
using namespace clang;
using namespace clang::driver;
using namespace clang::tooling;
using namespace llvm;

class AssignmentMutatorVisitor : public RecursiveASTVisitor<AssignmentMutatorVisitor> {
private:
    ASTContext* m_astContext; // used for getting additional AST info
    Rewriter* m_rewriter;

public:
    explicit AssignmentMutatorVisitor(ASTContext* astContext, Rewriter* rewriter)
        : m_astContext(astContext), m_rewriter(rewriter) // initialize private members
    {
        m_rewriter->setSourceMgr(m_astContext->getSourceManager(), m_astContext->getLangOpts());
    }

    // Caused memory leak because of how RecursiveASTVisitor is defined
    //virtual ~AssignmentMutatorVisitor() { m_rewriter=0; Assignment m_astContext; } 

    // Methods
    bool VisitUnaryOperator(UnaryOperator* stmt);
    bool VisitDeclStmt(clang::DeclStmt* stmt);
};

class AssignmentMutatorASTConsumer : public ASTConsumer {
private:
    AssignmentMutatorVisitor* m_visitor; // doesn't have to be private

public:
    // override the constructor in order to pass CI
    explicit AssignmentMutatorASTConsumer(ASTContext* astContext, Rewriter* rewriter)
        : m_visitor(new AssignmentMutatorVisitor(astContext, rewriter)) // initialize the visitor
    { }

    virtual ~AssignmentMutatorASTConsumer() { delete m_visitor; }

    // override this to call our DeleteMutatorVisitor on the entire source file
    virtual void HandleTranslationUnit(ASTContext& Context) override {
        /* we can use ASTContext to get the TranslationUnitDecl, which is
             a single Decl that collectively represents the entire source file */
        m_visitor->TraverseDecl(Context.getTranslationUnitDecl());
    }
};

class AssignmentMutatorFrontendAction : public ASTFrontendAction {
private:
    Rewriter* m_rewriter = new Rewriter();
    ASTContext* m_astContext = 0; // used for getting additional AST info

public:
    virtual std::unique_ptr<clang::ASTConsumer> CreateASTConsumer(CompilerInstance& CI, StringRef file) final {
        m_astContext = (&(CI.getASTContext()));
        //return std::unique_ptr<clang::ASTConsumer>(new AssignmentMutatorASTConsumer(m_astContext, m_rewriter));
        return std::make_unique<AssignmentMutatorASTConsumer>(m_astContext, m_rewriter);
    }

    virtual ~AssignmentMutatorFrontendAction() { delete m_rewriter; m_astContext = 0; }

    void EndSourceFileAction() override;
};
#endif // END OF __ASSIGNMENT_MUTATOR_H