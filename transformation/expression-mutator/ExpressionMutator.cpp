#include "ExpressionMutator.h"
#include "../random-manager/ClangFuzzerCustomRandom.h"
#include <fstream>
#include <iostream>
#include <sstream>

/// <summary>
/// TODO: what this mutations does
///
/// TODO: Add details and mapping to the mutations in the paper.
///
/// Classes: ExpressionMutatorVisitor, ExpressionMutatorASTConsumer,
/// ExpressionMutatorFrontendAction
/// </summary>
// Write up in a mail
// Shorten expression mutator
// Ternary operators

static llvm::cl::OptionCategory MyToolCategory("Expression Mutator option");
std::string output_filename;

void ExpressionMutatorVisitor::collect_sub_expressions(BinaryOperator *stmt) {
  if (!stmt->isCommaOp() && !stmt->isPtrMemOp()) {
    Expr *sub_expr_r = stmt->getRHS();
    Expr *sub_expr_l = stmt->getLHS();
    bool is_rhs_arithmetic = sub_expr_r->getType()->isArithmeticType();
    bool is_lhs_arithmetic = sub_expr_l->getType()->isArithmeticType();
    Stmt *sub_stmt = cast<Stmt>(stmt);
    CharSourceRange sub_declRange_r = CharSourceRange::getTokenRange(
        sub_expr_r->getBeginLoc(), sub_expr_r->getEndLoc());
    std::string sub_decl_str_r = std::string(
        Lexer::getSourceText(sub_declRange_r, m_astContext->getSourceManager(),
                             m_astContext->getLangOpts()));
    CharSourceRange sub_declRange_l = CharSourceRange::getTokenRange(
        sub_expr_l->getBeginLoc(), sub_expr_l->getEndLoc());
    std::string sub_decl_str_l = std::string(
        Lexer::getSourceText(sub_declRange_l, m_astContext->getSourceManager(),
                             m_astContext->getLangOpts()));
    if (is_rhs_arithmetic)
      expr_to_add.push_back(sub_decl_str_r);
    if (is_lhs_arithmetic)
      expr_to_add.push_back(sub_decl_str_l);
    // For loop to iterate through the RHS expression sub-tree
    for (Stmt::child_iterator j_se = sub_stmt->child_begin(),
                              e = sub_stmt->child_end();
         j_se != e; ++j_se) {
      Stmt *currStmt = *j_se;
      // Deal with nested call expressions within binary operators on the RHS
      // expression.
      if (isa<BinaryOperator>(currStmt)) {
        BinaryOperator *sub_bop = cast<BinaryOperator>(currStmt);
        int node_id_args = (sub_bop)->getID(*m_astContext);
        visited_node_IDs.push_back(node_id_args);
        collect_sub_expressions(sub_bop);
      }
    }
  }
}

bool ExpressionMutatorVisitor::VisitBinaryOperator(BinaryOperator *stmt) {
  int binary_op_node_id = (stmt)->getID(*m_astContext);
  bool isVisited = (std::find(visited_node_IDs.begin(), visited_node_IDs.end(),
                              binary_op_node_id) != visited_node_IDs.end());
  CharSourceRange binop_range =
      CharSourceRange::getTokenRange(stmt->getBeginLoc(), stmt->getEndLoc());
  std::string bstmt_str = std::string(
      Lexer::getSourceText(binop_range, m_astContext->getSourceManager(),
                           m_astContext->getLangOpts()));
  if (stmt->isAssignmentOp() && !isVisited) {
    expr_to_add.clear();
    collect_sub_expressions(stmt);
    if (expr_to_add.size() == 0)
      return true;
    std::string expr_append = bstmt_str + " + 42 ";
    int expr_length = (ClangFuzzerCustomRandom::GetInstance()->rnd_dice() %
                       _MUTATOR_EXPR_SIZE) +
                      1;
    if (expr_length > _MUTATOR_MAX_EXPR_SIZE)
      return true; /* Limit the size of the expression we can create */
    for (int i = 0; i < expr_length; i++)
      expr_append += get_float_random_op() + "((" + get_random_dtype() + ")(" +
                     generate_random_expr() + "))";
    m_rewriter->ReplaceText(stmt->getBeginLoc(), bstmt_str.length(),
                            expr_append);
  }
  return true;
}

bool ExpressionMutatorVisitor::VisitIfStmt(IfStmt *istmt) {
  Expr *cond = istmt->getCond();
  CharSourceRange cond_range =
      CharSourceRange::getTokenRange(cond->getBeginLoc(), cond->getEndLoc());
  std::string cond_str = std::string(
      Lexer::getSourceText(cond_range, m_astContext->getSourceManager(),
                           m_astContext->getLangOpts()));
  Stmt *sub_stmt = cast<Stmt>(cond);
  expr_to_add.clear();
  if (isa<BinaryOperator>(cond)) {
    BinaryOperator *cond_bop = cast<BinaryOperator>(cond);
    collect_sub_expressions(cond_bop);
  } else {
    for (Stmt::child_iterator j_se = sub_stmt->child_begin(),
                              e = sub_stmt->child_end();
         j_se != e; ++j_se) {
      Stmt *currStmt = *j_se;
      // Deal with nested call expressions within binary operators on the RHS
      // expression.
      if (isa<BinaryOperator>(currStmt)) {
        BinaryOperator *sub_bop = cast<BinaryOperator>(currStmt);
        if (sub_bop->isAssignmentOp())
          return true;
        int node_id_args = (sub_bop)->getID(*m_astContext);
        visited_node_IDs.push_back(node_id_args);
        collect_sub_expressions(sub_bop);
      }
    }
  }
  if (expr_to_add.size()) {
    std::string expr_append = cond_str + " + 42 ";
    int expr_length = (ClangFuzzerCustomRandom::GetInstance()->rnd_dice() %
                       _MUTATOR_SUB_EXPR_SIZE) +
                      1;
    for (int i = 0; i < expr_length; i++)
      expr_append += get_float_random_op() + "((" + get_random_dtype() + ")(" +
                     generate_random_expr() + "))";
    expr_append = "((int)" + expr_append + ")";
    m_rewriter->ReplaceText(cond_range, expr_append);
  }
  return true;
}

std::string ExpressionMutatorVisitor::generate_random_expr() {
  std::string expr_lhs =
      expr_to_add[ClangFuzzerCustomRandom::GetInstance()->rnd_dice() %
                  expr_to_add.size()];
  std::string expr_rhs =
      expr_to_add[ClangFuzzerCustomRandom::GetInstance()->rnd_dice() %
                  expr_to_add.size()];

  bool lhs_pointer = (expr_lhs.find("*") != std::string::npos) ||
                     (expr_lhs.find("[") != std::string::npos);
  bool rhs_pointer = (expr_rhs.find("*") != std::string::npos) ||
                     (expr_rhs.find("[") != std::string::npos);
  std::string random_expr =
      (ClangFuzzerCustomRandom::GetInstance()->rnd_yes_no(0.5) &&
       !lhs_pointer && !rhs_pointer)
          ? "((double)(" + expr_lhs + ")) " + get_float_random_op() +
                "((double)(" + expr_rhs + "))"
          : "((int)(" + expr_lhs + ")) " + get_int_random_op() + "((int)(" +
                expr_rhs + "))";
  return ("(" + random_expr + ")");
}

std::string ExpressionMutatorVisitor::get_float_random_op() {
  return (
      float_operator_bank[ClangFuzzerCustomRandom::GetInstance()->rnd_dice() %
                          _MUTATOR_FLOAT_OP_SIZE]);
}

std::string ExpressionMutatorVisitor::get_int_random_op() {
  return (int_operator_bank[ClangFuzzerCustomRandom::GetInstance()->rnd_dice() %
                            _MUTATOR_INT_OP_SIZE]);
}

std::string ExpressionMutatorVisitor::get_random_dtype() {
  return (data_types[ClangFuzzerCustomRandom::GetInstance()->rnd_dice() %
                     _MUTATOR_DATA_TYPE_SIZE]);
}

void ExpressionMutatorFrontendAction::EndSourceFileAction() {
  SourceManager &SM = m_rewriter->getSourceMgr();
  std::error_code error_code;
  std::string base_filename =
      std::string(SM.getFileEntryForID(SM.getMainFileID())->getName());
  std::string::size_type const p(base_filename.find_last_of('.'));
  std::string file_without_extension = base_filename.substr(0, p);
  llvm::raw_fd_ostream outFile(file_without_extension + ".mutated.c",
                               error_code);
  m_rewriter->getEditBuffer(SM.getMainFileID()).write(outFile);
  outFile.close();
}

int main(int argc, const char **argv)
{
  static llvm::cl::OptionCategory ExpressionMutatorCategory("Transform tool option");
  static llvm::cl::opt<std::string> OutputFile("output",
                                              llvm::cl::desc("Name of the output file"),
                                              llvm::cl::cat(ExpressionMutatorCategory), cl::Required);
  static llvm::cl::opt<unsigned long> Seed("seed",
                                              llvm::cl::desc("String seed to feed into the mutator"),
                                              llvm::cl::cat(ExpressionMutatorCategory), cl::Required);

  llvm::cl::HideUnrelatedOptions(ExpressionMutatorCategory);
  CommonOptionsParser op(argc, argv, ExpressionMutatorCategory);

  // Create Random Generaton, uniform real dist

  ClangFuzzerCustomRandom::CreateInstance(Seed.getValue(), 6); // Dice of 6
  output_filename = OutputFile.getValue();
  // create a new Clang Tool instance (a LibTooling environment)
  ClangTool Tool(op.getCompilations(), op.getSourcePathList());

  // run the Clang Tool, creating a new FrontendAction (explained below)
  int result =
      Tool.run(&(*newFrontendActionFactory<ExpressionMutatorFrontendAction>()));

  // Free the random manager before exit
  ClangFuzzerCustomRandom::DeleteInstance(Seed);

  return result;
}

