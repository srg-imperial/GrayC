#ifndef __FUNCTION_EXTRACTOR_H
#define __FUNCTION_EXTRACTOR_H

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

class GlobalTraverser final : public RecursiveASTVisitor<GlobalTraverser> {
private:
  bool isGlobal = false;
  std::string decl_info = "";
  bool contains_call = false;

public:
  static bool find(FunctionDecl *func) {
    GlobalTraverser traverser;
    traverser.TraverseDecl(func);
    return traverser.isGlobal;
  }

  static bool extract(VarDecl *vd) {
    GlobalTraverser traverser;
    traverser.TraverseDecl(vd);
    return traverser.contains_call;
  }

  bool VisitCallExpr(CallExpr *cexpr) {
    contains_call = true;
    return contains_call;
  }

  // bool VisitDeclRefExpr(DeclRefExpr *dexpr);
};

class HookExtractorVisitor : public RecursiveASTVisitor<HookExtractorVisitor> {
private:
  ASTContext *m_astContext; // used for getting additional AST info
  Rewriter *m_rewriter;
  int fn_start_line_no = -99;
  int fn_end_line_no = -99;

public:
  explicit HookExtractorVisitor(CompilerInstance *CI, Rewriter *rewriter)
      : m_astContext(&(CI->getASTContext())),
        m_rewriter(rewriter) // initialize private members
  {
    m_rewriter->setSourceMgr(m_astContext->getSourceManager(),
                             m_astContext->getLangOpts());
  }

  static void appendLineToFile(string filepath, string line);
  bool VisitFunctionDecl(FunctionDecl *func);
  bool VisitVarDecl(clang::VarDecl *NamedDecl);
  bool VisitRecordDecl(clang::RecordDecl *RDecl);
};

class HookExtractorASTConsumer : public ASTConsumer {
private:
  HookExtractorVisitor *m_visitor;

public:
  // override the constructor in order to pass CI
  explicit HookExtractorASTConsumer(CompilerInstance *CI, Rewriter *rewriter)
      : m_visitor(
            new HookExtractorVisitor(CI, rewriter)) // initialize the visitor
  {}

  // override this to call our HookExtractorVisitor on the entire source file
  virtual void HandleTranslationUnit(ASTContext &Context) override {
    /* we can use ASTContext to get the TranslationUnitDecl, which is
         a single Decl that collectively represents the entire source file */
    m_visitor->TraverseDecl(Context.getTranslationUnitDecl());
  }

  virtual ~HookExtractorASTConsumer() { delete m_visitor; }
};

class HookExtractorFrontendAction : public ASTFrontendAction {
private:
  Rewriter *m_rewriter = new Rewriter();

public:
  virtual std::unique_ptr<clang::ASTConsumer>
  CreateASTConsumer(CompilerInstance &CI, StringRef file) final {
    // return std::unique_ptr<clang::ASTConsumer>(new
    // HookExtractorASTConsumer(&CI, m_rewriter)); // pass CI pointer to
    // ASTConsumer
    return std::make_unique<HookExtractorASTConsumer>(&CI, m_rewriter);
  }

  virtual ~HookExtractorFrontendAction() { delete m_rewriter; }
};
#endif // END OF  __FUNCTION_EXTRACTOR_H