#ifndef __EXPRESSION_MUTATOR_H
#define __EXPRESSION_MUTATOR_H

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

// Control fuzzing aggressiveness
#define _MUTATOR_MAX_EXPR_SIZE 50
#define _MUTATOR_MAX_SUB_EXPR_SIZE 30
#define _MUTATOR_EXPR_SIZE 5
#define _MUTATOR_SUB_EXPR_SIZE 10
#define _MUTATOR_DATA_TYPE_SIZE 3
#define _MUTATOR_FLOAT_OP_SIZE 3
#define _MUTATOR_INT_OP_SIZE 6

class ExpressionMutatorVisitor
    : public RecursiveASTVisitor<ExpressionMutatorVisitor> {
private:
  ASTContext *m_astContext; // used for getting additional AST info
  Rewriter *m_rewriter;
  std::vector<std::string> expr_to_add;
  std::vector<int> visited_node_IDs;
  std::string float_operator_bank[_MUTATOR_FLOAT_OP_SIZE] = {"+", "-", "*"};
  std::string data_types[_MUTATOR_DATA_TYPE_SIZE] = {
      "int", "long", "short"}; // add short long and unsigned
  std::string int_operator_bank[_MUTATOR_INT_OP_SIZE] = {"<<", ">>", "&",
                                                         "^",  "%",  "|"};

public:
  explicit ExpressionMutatorVisitor(CompilerInstance *CI, Rewriter *rewriter)
      : m_astContext(&(CI->getASTContext())),
        m_rewriter(rewriter) // initialize private members
  {
    m_rewriter->setSourceMgr(m_astContext->getSourceManager(),
                             m_astContext->getLangOpts());
  }

  void collect_sub_expressions(BinaryOperator *stmt);
  bool VisitBinaryOperator(BinaryOperator *stmt);
  bool VisitIfStmt(IfStmt *istmt);
  std::string generate_random_expr();
  std::string get_float_random_op();
  std::string get_int_random_op();
  std::string get_random_dtype();
};

class ExpressionMutatorASTConsumer : public ASTConsumer {
private:
  ExpressionMutatorVisitor *m_visitor; // doesn't have to be private

public:
  // override the constructor in order to pass CI
  explicit ExpressionMutatorASTConsumer(CompilerInstance *CI,
                                        Rewriter *rewriter)
      : m_visitor(new ExpressionMutatorVisitor(
            CI, rewriter)) // initialize the visitor
  {}

  // override this to call our ExpressionMutatorVisitor on the entire source
  // file
  virtual void HandleTranslationUnit(ASTContext &Context) override {
    /* we can use ASTContext to get the TranslationUnitDecl, which is
         a single Decl that collectively represents the entire source file */
    m_visitor->TraverseDecl(Context.getTranslationUnitDecl());
  }

  virtual ~ExpressionMutatorASTConsumer() { delete m_visitor; }
};

class ExpressionMutatorFrontendAction : public ASTFrontendAction {
private:
  Rewriter *m_rewriter = new Rewriter();

public:
  virtual std::unique_ptr<clang::ASTConsumer>
  CreateASTConsumer(CompilerInstance &CI, StringRef file) final {
    // return std::unique_ptr<clang::ASTConsumer>(new
    // ExpressionMutatorASTConsumer(&CI, m_rewriter)); // pass CI pointer to
    // ASTConsumer
    return std::make_unique<ExpressionMutatorASTConsumer>(&CI, m_rewriter);
  }

  virtual ~ExpressionMutatorFrontendAction() { delete m_rewriter; }

  void EndSourceFileAction() override;
};
#endif // END OF  __EXPRESSION_MUTATOR_H
