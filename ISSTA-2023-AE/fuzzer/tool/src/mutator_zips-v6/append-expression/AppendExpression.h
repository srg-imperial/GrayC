//===--- append-expression/AppendExpression.h and
// append-expression/AppendExpression.cpp -----===//
//
// TODO: add License information
//
//===----------------------------------------------------------------------===//
//
//  This file implements append mutator of Csmith expressions
//
//  Inject Expression: (Recombiner, Insert) add expressions from randomly
//                     generated Csmith programs along with their variables
//                     and other definitions (uses function-extractor as
//                     as helper).
//
//===----------------------------------------------------------------------===//

#ifndef __APPEDND_EXPRESSION_H
#define __APPEDND_EXPRESSION_H

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
#include <vector>
using namespace std;
using namespace clang;
using namespace clang::driver;
using namespace clang::tooling;
using namespace llvm;

class AppendExpressionMutatorVisitor
    : public RecursiveASTVisitor<AppendExpressionMutatorVisitor> {
private:
  ASTContext *m_astContext; // used for getting additional AST info
  Rewriter *m_rewriter;

  std::vector<std::string> expr_to_add;
  std::vector<int> visited_node_IDs;
  int decl_start_line_number = -99;
  int decl_end_line_number = -99;
  // bool done_one = false;
  std::string float_operator_bank[3] = {"+", "-", "*"};
  std::string data_types[3] = {"int", "long",
                               "short"}; // add short long and unsigned
  std::string int_operator_bank[6] = {"<<", ">>", "&", "^", "%", "|"};

public:
  explicit AppendExpressionMutatorVisitor(CompilerInstance *CI,
                                          Rewriter *rewriter)
      : m_astContext(&(CI->getASTContext())),
        m_rewriter(rewriter) // initialize private members
  {
    m_rewriter->setSourceMgr(m_astContext->getSourceManager(),
                             m_astContext->getLangOpts());
  }

  // Methods
  bool VisitFunctionDecl(FunctionDecl *func);
  std::string readFileIntoString(const string &path);
};

class AppendExpressionMutatorASTConsumer : public ASTConsumer {
private:
  AppendExpressionMutatorVisitor *m_visitor; // doesn't have to be private
public:
  // override the constructor in order to pass CI
  explicit AppendExpressionMutatorASTConsumer(CompilerInstance *CI,
                                              Rewriter *rewriter)
      : m_visitor(new AppendExpressionMutatorVisitor(
            CI, rewriter)) // initialize the visitor
  {}

  virtual ~AppendExpressionMutatorASTConsumer() { delete m_visitor; }

  // override this to call our ExpressionMutatorVisitor on the entire source
  // file
  virtual void HandleTranslationUnit(ASTContext &Context) override {
    /* we can use ASTContext to get the TranslationUnitDecl, which is
         a single Decl that collectively represents the entire source file */
    m_visitor->TraverseDecl(Context.getTranslationUnitDecl());
  }
};

class AppendExpressionMutatorFrontendAction : public ASTFrontendAction {
private:
  Rewriter *m_rewriter = new Rewriter();

public:
  virtual std::unique_ptr<clang::ASTConsumer>
  CreateASTConsumer(CompilerInstance &CI, StringRef file) final {
    return std::make_unique<AppendExpressionMutatorASTConsumer>(&CI,
                                                                m_rewriter);
  }

  virtual ~AppendExpressionMutatorFrontendAction() { delete m_rewriter; }

  void EndSourceFileAction() override;
};
#endif // END OF __APPEDND_EXPRESSION_H
