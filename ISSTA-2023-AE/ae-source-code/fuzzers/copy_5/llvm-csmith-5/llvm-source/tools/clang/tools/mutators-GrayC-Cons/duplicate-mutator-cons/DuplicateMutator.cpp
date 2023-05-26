#include "DuplicateMutator.h"
#include "../utils-fuzzer-cons/GrayCCustomRandom.h"
#include "../utils-fuzzer-cons/GrayCUtils.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <time.h>
#include <vector>

/// <summary>
/// Duplicate statements or delete statements as long as these are not part of
/// loop or switch-case.
///
/// Classes: DuplicateMutatorVisitor, DuplicateMutatorASTConsumer,
/// DuplicateMutatorFrontendAction
/// </summary>

static llvm::cl::OptionCategory MyToolCategory("Duplicate Mutator option");

bool DuplicateMutatorVisitor::isInNestedAssignment(const clang::Expr& expr) {
  auto it = m_astContext->getParents(expr).begin();
  if (it == m_astContext->getParents(expr).end())
    return false;

  const clang::BinaryOperator* aDecl = it->get<clang::BinaryOperator>();
  if (aDecl && aDecl->isAssignmentOp())
    return false;

  const clang::Expr* aStmt = it->get<clang::Expr>();
  if (!aStmt)
    return false;

  aStmt = aStmt->IgnoreImpCasts();
  if (aStmt)
    return isInNestedAssignment(*aStmt);
  
  return false;
}

bool DuplicateMutatorVisitor::VisitBinaryOperator(BinaryOperator *stmt) {
  if (!stmt || stmt->getExprLoc().isInvalid() || !stmt->isAssignmentOp())
    return true; // Nothing to work on, return
  
  SourceLocation b_sloc = stmt->getBeginLoc();
  if (b_sloc.isInvalid())
    return true; // not a valid block, return

  // Else continue with the changes
  int line_no = (m_astContext->getSourceManager())
                    .getSpellingLineNumber(stmt->getBeginLoc());
  if (m_tmp_latest_loop_line == line_no)
    return true; // Do not edit the same location twice

  if (!m_rewriter->isRewritable(stmt->getBeginLoc()) || !m_rewriter->isRewritable(stmt->getEndLoc()))
    return true; // Do not attempt to edit if is not rewritable
      
  // Duplicate or delete part of statement
  if (pick_delete_or_duplicate() == "duplicate") {
    // Before duplicating things, check if it is a bad line!
    CharSourceRange binop_range =
        CharSourceRange::getTokenRange(stmt->getBeginLoc(), stmt->getEndLoc());
    if (binop_range.isInvalid())
      return true;
      
    auto str_ref = Lexer::getSourceText(binop_range, 
        m_astContext->getSourceManager(),
        m_astContext->getLangOpts());
    if (str_ref.empty())
      return true;
    
    std::string bstmt_str = std::string(str_ref);
    if (bstmt_str.empty())
      return true; // exit if nothing to add
    if (GrayCUtils::getAssignmentNos(bstmt_str) > 1) 
      return true; // if got multiple assignement, return 
    
    // extract the current line as a text
    int line_no_check = (m_astContext->getSourceManager())
                              .getSpellingLineNumber(stmt->getBeginLoc());
    if (line_no_check < 0)
      return true; // if invalid line, exit
     
    SourceLocation thisline =
        (m_astContext->getSourceManager())
            .translateLineCol((m_astContext->getSourceManager()).getMainFileID(),
                              line_no_check,
                              1); // get the beginning of line line_no
    if (thisline.isInvalid())
      return true; // not a valid location, return
      
    SourceLocation nextline =
        (m_astContext->getSourceManager())
            .translateLineCol((m_astContext->getSourceManager()).getMainFileID(),
                              line_no_check + 1,
                              1); // get the beginning of line line_no+1
    if (nextline.isInvalid())
      return true; // not a valid location, return
      
    SourceRange srange(thisline, nextline);
    if (srange.isInvalid())
      return true; // not valid, return
      
    // If bad line, do not edit
    std::string string_to_rewrite = string(Lexer::getSourceText(CharSourceRange::getTokenRange(srange), m_astContext->getSourceManager(), m_astContext->getLangOpts(), 0));
    if ((string_to_rewrite.empty()) || GrayCUtils::is_bad_line(string_to_rewrite)) {
      //debug print
      //llvm::outs() << ">>Stopped due to expression size\n";
      return true;
    }
      
    // Check before use the location
    if (m_last_sloc.isInvalid() || bstmt_str.empty())
      return true;
      
    // duplicate only if valid+not bad line+not empty
    m_rewriter->InsertTextBefore(m_last_sloc, "\n;" + bstmt_str + ";\n");
  } 
  else if (stmt->isAssignmentOp()) { // Delete but only assignements
    // Before duplicating things, check if it is a bad line!
    CharSourceRange binop_range_for_deletion =
        CharSourceRange::getTokenRange(stmt->getBeginLoc(), stmt->getEndLoc());
    if (binop_range_for_deletion.isInvalid())
      return true;

    // Delete line, here we can delete even if it is a bad line
    if (GrayCCustomRandom::GetInstance()->rnd_yes_no(__DUPLICATE_MUTATOR_REMOVE_RHS_OR_LHS)) {
      Expr* rhs_expr = stmt->getRHS();
      if (!rhs_expr)
        return true;
        
      CharSourceRange rhs_range =
          CharSourceRange::getTokenRange(rhs_expr->getBeginLoc(), rhs_expr->getEndLoc());
      if (rhs_range.isInvalid())
        return true;
        
      string rhs_str = string(Lexer::getSourceText(rhs_range, m_astContext->getSourceManager(), m_astContext->getLangOpts(), 0));
      m_rewriter->ReplaceText(binop_range_for_deletion, rhs_str);
    } else {
      Expr* lhs_expr = stmt->getLHS();
      if (!lhs_expr)
        return true;
        
      CharSourceRange lhs_range =
          CharSourceRange::getTokenRange(lhs_expr->getBeginLoc(), lhs_expr->getEndLoc());
      if (lhs_range.isInvalid())
        return true;
        
      string lhs_str = string(Lexer::getSourceText(lhs_range, m_astContext->getSourceManager(), m_astContext->getLangOpts(), 0));
      m_rewriter->ReplaceText(binop_range_for_deletion, lhs_str);
    }
  } // If not assignement, we do it somewhere else (in expression mutator)
    
  // Update the location and check
  if (stmt->getBeginLoc().isInvalid())
    return true;
  m_last_sloc = stmt->getBeginLoc();

  return true;
}

std::string DuplicateMutatorVisitor::pick_delete_or_duplicate() {
  return (GrayCCustomRandom::GetInstance()->rnd_yes_no(__DUPLICATE_MUTATOR_DUP_OR_DEL) 
            ? "duplicate"
            : "delete");
}

void DuplicateMutatorFrontendAction::EndSourceFileAction() {
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
  GrayCCustomRandom::CreateInstance(Seed, 2);
  // std::cout << "Seed in mutator: " << Seed << "\n";

  // create a new Clang Tool instance (a LibTooling environment)
  ClangTool Tool(op.getCompilations(), op.getSourcePathList());

  // run the Clang Tool, creating a new FrontendAction (explained below)
  int result =
      Tool.run(&(*newFrontendActionFactory<DuplicateMutatorFrontendAction>()));

  // Free the random manager before exit
  GrayCCustomRandom::DeleteInstance(Seed);

  return result;
}
