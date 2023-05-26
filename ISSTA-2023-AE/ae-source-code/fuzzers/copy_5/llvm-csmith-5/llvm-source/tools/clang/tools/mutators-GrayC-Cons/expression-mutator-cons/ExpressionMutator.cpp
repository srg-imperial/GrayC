#include "ExpressionMutator.h"
#include "../utils-fuzzer-cons/GrayCCustomRandom.h"
#include "../utils-fuzzer-cons/GrayCUtils.h"
#include <fstream>
#include <iostream>
#include <sstream>

/// <summary>
/// Shrink or expand expression in a recursive way
///
/// Classes: ExpressionMutatorVisitor, ExpressionMutatorASTConsumer,
/// ExpressionMutatorFrontendAction
/// </summary>

static llvm::cl::OptionCategory MyToolCategory("Expression Mutator option");

void ExpressionMutatorVisitor::collect_sub_expressions(BinaryOperator *stmt) {
  if (!stmt)
    return;
  
  // Else continue with the edit
  CharSourceRange stmt_range =
      CharSourceRange::getTokenRange(stmt->getBeginLoc(), stmt->getEndLoc());
  if (stmt_range.isInvalid())
    return; // if no statments, exit
  if (m_rewriter->getRangeSize(stmt_range) > __EXPRESSION_MUTATOR_EXPR_MAX_LEN)
    return; // if too large, exit

  if (!stmt->isCommaOp() && !stmt->isPtrMemOp()) {
    Expr *sub_expr_l = stmt->getLHS();
    if (!sub_expr_l)
      return;
    
    Expr *sub_expr_r = stmt->getRHS();
    if (!sub_expr_r)
      return;
 
    Stmt *sub_stmt = cast<Stmt>(stmt);
    if (!sub_stmt)
      return;

    // Continue only if cast succeeded
    CharSourceRange sub_declRange_r = CharSourceRange::getTokenRange(
        sub_expr_r->getBeginLoc(), sub_expr_r->getEndLoc());
    if (sub_declRange_r.isInvalid())
      return; // if no decl, exit
    
    auto str_ref = Lexer::getSourceText(sub_declRange_r, 
        m_astContext->getSourceManager(),
        m_astContext->getLangOpts());
    if (str_ref.empty())
      return; // if no decl, exit
    
    std::string sub_decl_str_r = std::string(str_ref);
    if (sub_decl_str_r.empty())
      return; // if no decl, exit
    
    CharSourceRange sub_declRange_l = CharSourceRange::getTokenRange(
        sub_expr_l->getBeginLoc(), sub_expr_l->getEndLoc());
    if (sub_declRange_l.isInvalid())
      return; // if no decl, exit
    
    str_ref = Lexer::getSourceText(sub_declRange_l, 
        m_astContext->getSourceManager(),
        m_astContext->getLangOpts());
    if (str_ref.empty())
      return; // if no decl, exit
    
    std::string sub_decl_str_l = std::string(str_ref);
    if (sub_decl_str_r.empty())
      return;
    
    bool is_rhs_arithmetic = sub_expr_r->getType()->isArithmeticType();
    if (is_rhs_arithmetic) {
      if (sub_decl_str_r.empty())
        return;
      expr_to_add.push_back(sub_decl_str_r);
    }
    
    bool is_lhs_arithmetic = sub_expr_l->getType()->isArithmeticType();
    if (is_lhs_arithmetic) {
      if (sub_decl_str_l.empty())
        return;
      expr_to_add.push_back(sub_decl_str_l);
    }
    
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
  if (!stmt || !stmt->isAssignmentOp())
    return true;

  // Randomly skip to avoid replacing the expression - higher more aggressive
  if (GrayCCustomRandom::GetInstance()->rnd_yes_no(__EXPRESSION_MUTATOR_REPLACE_BIN_OP_SUB_EXPR))
    return true;
  
  // Check if visited
  int binary_op_node_id = (stmt)->getID(*m_astContext);
  if (std::find(visited_node_IDs.begin(), visited_node_IDs.end(),
                binary_op_node_id) != visited_node_IDs.end())
    return true;
  
  int line_no_check = (m_astContext->getSourceManager())
                          .getSpellingLineNumber(stmt->getBeginLoc());
  int line_no_next = line_no_check + 1;

  // Extract the current line as a text
  SourceLocation thisline =
      (m_astContext->getSourceManager())
          .translateLineCol((m_astContext->getSourceManager()).getMainFileID(),
                            line_no_check,
                            1); // get the beginning of line line_no
  SourceLocation nextline =
      (m_astContext->getSourceManager())
          .translateLineCol((m_astContext->getSourceManager()).getMainFileID(),
                            line_no_next,
                            1); // get the beginning of line line_no+1
  SourceRange srange(thisline, nextline);
  if (srange.isInvalid())
    return true;
  
  // Check if it is a bad line - do not edit
  string string_to_rewrite = string(Lexer::getSourceText(CharSourceRange::getTokenRange(srange), m_astContext->getSourceManager(), m_astContext->getLangOpts(), 0));
  if (string_to_rewrite.empty() || GrayCUtils::is_bad_line(string_to_rewrite)) {
    // Debug print
    //llvm::outs() << ">>Stopped due to expression size\n";
    return true;
  }
  // if (stmt->isAssignmentOp() && !isVisited) ==> then mutate
  CharSourceRange binop_range =
      CharSourceRange::getTokenRange(stmt->getBeginLoc(), stmt->getEndLoc());
  if (binop_range.isInvalid())
    return true; // if no decl, exit
  
  auto str_ref = Lexer::getSourceText(binop_range, 
      m_astContext->getSourceManager(),
      m_astContext->getLangOpts());
  if (str_ref.empty())
    return true; // if no decl, exit
      
  std::string bstmt_str = std::string(str_ref);
  if (bstmt_str.empty())
    return true; // if no decl, exit
  if (GrayCUtils::getAssignmentNos(bstmt_str) > 1) {
    return true; // if got multiple assignement, return 
  }
  
  expr_to_add.clear();
  collect_sub_expressions(stmt);
  if (expr_to_add.empty())
    return true;

  // Check if the expression is not too big
  unsigned expr_length =
      (GrayCCustomRandom::GetInstance()->rnd_dice() % _MUTATOR_EXPR_SIZE) + 1;
  if (expr_length < 1)
    return true;
  if ((expr_length + visited_node_IDs.size()) > _MUTATOR_MAX_EXPR_SIZE)
    return true; /* Limit the size of the expression we can create */

  // Mutate!
  std::string expr_append = bstmt_str + " + 42";
  for (unsigned i = 0; i < expr_length; i++)
    expr_append += " " + get_float_random_op() + " ((" + get_random_dtype() +
                   ")(" + generate_random_expr() + "))";
  m_rewriter->ReplaceText(stmt->getBeginLoc(), bstmt_str.length(), expr_append);
  return true;
}

bool ExpressionMutatorVisitor::VisitIfStmt(IfStmt *istmt) {
  if (!istmt)
    return true;
  Expr *cond = istmt->getCond();
  if (!cond)
    return true;

  CharSourceRange cond_range =
      CharSourceRange::getTokenRange(cond->getBeginLoc(), cond->getEndLoc());
  if (cond_range.isInvalid())
    return true; // if no cond, exit
  
  auto str_ref = Lexer::getSourceText(cond_range, 
      m_astContext->getSourceManager(),
      m_astContext->getLangOpts());
  if (str_ref.empty())
    return true; // if no cond, exit
  
  std::string cond_str = std::string(str_ref);
  if (cond_str.empty())
    return true; // if no cond, exit
  
  Stmt *sub_stmt = cast<Stmt>(cond);
  if (!sub_stmt)
    return true;

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
        if (!sub_bop)
          return true; // if cannot cast, return
        if (sub_bop->isAssignmentOp())
          return true;
  
        int node_id_args = (sub_bop)->getID(*m_astContext);
        visited_node_IDs.push_back(node_id_args);
        collect_sub_expressions(sub_bop);
      } // End of if stmt
    }   // End of For loop
  }     // End of ELSE

  if (expr_to_add.size()) {
    // Check if the expression is not too big
    unsigned expr_length = (GrayCCustomRandom::GetInstance()->rnd_dice() %
                            _MUTATOR_SUB_EXPR_SIZE) +
                           1;
    if ((expr_length + visited_node_IDs.size()) > _MUTATOR_MAX_SUB_EXPR_SIZE)
      return true; /* Limit the size of the expression we can create */

    // Mutate!
    std::string expr_append = cond_str + " + 41";
    for (unsigned i = 0; i < expr_length; i++)
      expr_append += " " + get_float_random_op() + " ((" + get_random_dtype() +
                     ")(" + generate_random_expr() + "))";
    expr_append = "((int)" + expr_append + ")";
    m_rewriter->ReplaceText(cond_range, expr_append);
  }
  return true;
}

std::string ExpressionMutatorVisitor::generate_random_expr() {
  std::string expr_lhs =
      expr_to_add[GrayCCustomRandom::GetInstance()->rnd_dice() %
                  expr_to_add.size()];
  std::string expr_rhs =
      expr_to_add[GrayCCustomRandom::GetInstance()->rnd_dice() %
                  expr_to_add.size()];

  bool lhs_pointer = (expr_lhs.find("*") != std::string::npos) ||
                     (expr_lhs.find("[") != std::string::npos);
  bool rhs_pointer = (expr_rhs.find("*") != std::string::npos) ||
                     (expr_rhs.find("[") != std::string::npos);
  std::string random_expr =
      (GrayCCustomRandom::GetInstance()->rnd_yes_no(0.5) && !lhs_pointer &&
       !rhs_pointer)
          ? "((double)(" + expr_lhs + ")) " + get_float_random_op() +
                " ((double)(" + expr_rhs + "))"
          : "((int)(" + expr_lhs + ")) " + get_int_random_op() + " ((int)(" +
                expr_rhs + "))";
  return ("(" + random_expr + ")");
}

std::string ExpressionMutatorVisitor::get_float_random_op() {
  return (float_operator_bank[GrayCCustomRandom::GetInstance()->rnd_dice() %
                              _MUTATOR_FLOAT_OP_SIZE]);
}

std::string ExpressionMutatorVisitor::get_int_random_op() {
  return (int_operator_bank[GrayCCustomRandom::GetInstance()->rnd_dice() %
                            _MUTATOR_INT_OP_SIZE]);
}

std::string ExpressionMutatorVisitor::get_random_dtype() {
  return (data_types[GrayCCustomRandom::GetInstance()->rnd_dice() %
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

int main(int argc, const char **argv) {
  // parse the command-line args passed to your code
  int argc_new = argc - 1;
  CommonOptionsParser op(argc_new, argv, MyToolCategory);

  // Create Random Generaton, uniform real dist
  unsigned long Seed = std::stoi(argv[argc - 1]); // Seed is always in the end
  GrayCCustomRandom::CreateInstance(Seed, 60);    // Dice of 60
  // std::cout << "Seed in mutator: " << Seed << "\n";

  // create a new Clang Tool instance (a LibTooling environment)
  ClangTool Tool(op.getCompilations(), op.getSourcePathList());

  // run the Clang Tool, creating a new FrontendAction (explained below)
  int result =
      Tool.run(&(*newFrontendActionFactory<ExpressionMutatorFrontendAction>()));

  // Free the random manager before exit
  GrayCCustomRandom::DeleteInstance(Seed);

  return result;
}
