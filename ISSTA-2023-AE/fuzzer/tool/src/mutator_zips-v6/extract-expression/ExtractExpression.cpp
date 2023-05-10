#include "ExtractExpression.h"
#include "../utils-fuzzer/GrayCCustomRandom.h"
#include <algorithm>
#include <fstream>
#include <iostream>
#include <map>
#include <sstream>

/// <summary>
/// Hybrid mutator part 1: extract expressions and definitions
/// to be use later in AppendExpression
///
/// TODO: Add details and mapping to the mutations in the paper.
///
/// Classes: ExtractExpressionMutatorVisitor, 
/// ExtractExpressionMutatorASTConsumer,
/// ExtractExpressionMutatorFrontendAction
/// </summary>

static llvm::cl::OptionCategory MyToolCategory("Extract expression option");

bool ExtractExpressionMutatorVisitor::VisitFunctionDecl(FunctionDecl *func) {
  if (!func)
    return true;
  // Else, get function name, body and return type information
  if (func->getNameInfo().getAsString() == "func_1") {
    Stmt *body = func->getBody();
    decl_start_line_number = (m_astContext->getSourceManager())
                                 .getSpellingLineNumber(body->getBeginLoc());
    decl_end_line_number = (m_astContext->getSourceManager())
                               .getSpellingLineNumber(body->getEndLoc());
    body = nullptr;
  }

  return true;
}

bool ExtractExpressionMutatorVisitor::VisitDeclStmt(clang::DeclStmt *stmt) {
  if (!stmt)
    return true;
  // Else, continue
  static std::string _fuzzer_csmith_decl_file =
      "/home/user42/llvm-project/llvm-fuzzer-build/fuzzer_csmith-tmp/"
      "csmith_decls.txt";

  int line_no = (m_astContext->getSourceManager())
                    .getSpellingLineNumber(stmt->getBeginLoc());
  if (line_no >= decl_start_line_number && line_no <= decl_end_line_number) {
    CharSourceRange binop_range =
        CharSourceRange::getTokenRange(stmt->getBeginLoc(), stmt->getEndLoc());
    if (binop_range.isInvalid())
      return true; // if no expr, exit
    
    auto str_ref = Lexer::getSourceText(binop_range, 
        m_astContext->getSourceManager(),
        m_astContext->getLangOpts());
    if (str_ref.empty())
      return true;
    
    std::string stmt_str = std::string(str_ref);
    if (stmt_str.empty())
      return true;
    
    // Mutate if all okay
    appendLineToFile(_fuzzer_csmith_decl_file, stmt_str);
  }

  return true;
}

bool ExtractExpressionMutatorVisitor::VisitBinaryOperator(
    BinaryOperator *stmt) {
  if (!stmt)
    return true;
  // Else, continue
  static std::string _fuzzer_csmith_expr_file =
      "/home/user42/llvm-project/llvm-fuzzer-build/fuzzer_csmith-tmp/"
      "csmith_expr.txt";

  int line_no = (m_astContext->getSourceManager())
                    .getSpellingLineNumber(stmt->getBeginLoc());  

  if (stmt->isAssignmentOp() && !done_one &&
      (line_no >= decl_start_line_number && line_no <= decl_end_line_number)) {
    CharSourceRange binop_range =
      CharSourceRange::getTokenRange(stmt->getBeginLoc(), stmt->getEndLoc());
    if (binop_range.isInvalid())
      return true; // if no expr, exit
  
    auto str_ref = Lexer::getSourceText(binop_range, 
        m_astContext->getSourceManager(),
        m_astContext->getLangOpts());
    if (str_ref.empty())
      return true;
    
    std::string bstmt_str = std::string(str_ref);
    if (bstmt_str.empty())
      return true;
    
    done_one = true;
    appendLineToFile(_fuzzer_csmith_expr_file, bstmt_str + ";");
  }

  return true;
}

void ExtractExpressionMutatorVisitor::appendLineToFile(std::string filepath,
                                                       std::string line) {
  std::ofstream file;
  // can't enable exception now because of gcc bug that raises ios_base::failure
  // with useless message file.exceptions(file.exceptions() |
  // std::ios::failbit);
  file.open(filepath, std::ios::out | std::ios::app);

  // make sure write fails with exception if something is wrong
  file.exceptions(file.exceptions() | std::ios::failbit |
                  std::ifstream::badbit);

  file << line << std::endl;
}

void ExtractExpressionMutatorFrontendAction::EndSourceFileAction() {
  SourceManager &SM = m_rewriter->getSourceMgr();
  std::error_code error_code;
  std::string base_filename =
      std::string(SM.getFileEntryForID(SM.getMainFileID())->getName());
}

int main(int argc, const char **argv) {
  // parse the command-line args passed to your code
  int argc_new = argc - 1;
  CommonOptionsParser op(
      argc_new, argv,
      MyToolCategory); // requires: csmith_decls.txt and csmith_expr.txt

  // Create Random Generaton, uniform real dist
  unsigned long Seed = std::stoi(argv[argc - 1]); // Seed is always in the end
  GrayCCustomRandom::CreateInstance(Seed, 6);     // Dice of 6
  // std::cout << "Seed in mutator: " << Seed << "\n";

  // create a new Clang Tool instance (a LibTooling environment)
  ClangTool Tool(op.getCompilations(), op.getSourcePathList());

  // run the Clang Tool, creating a new FrontendAction (explained below)
  int result = Tool.run(
      &(*newFrontendActionFactory<ExtractExpressionMutatorFrontendAction>()));

  // Free the random manager before exit
  GrayCCustomRandom::DeleteInstance(Seed);

  return result;
}
