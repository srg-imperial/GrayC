#include "DuplicateMutator.h"
#include "../random-manager/ClangFuzzerCustomRandom.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <time.h>
#include <vector>

/// <summary>
/// TODO: what this mutations does
///
/// TODO: Add details and mapping to the mutations in the paper.
///
/// Classes: DuplicateMutatorVisitor, DuplicateMutatorASTConsumer,
/// DuplicateMutatorFrontendAction
/// </summary>
// Write up in a mail
// Shorten expression mutator
// Ternary operators

static llvm::cl::OptionCategory MyToolCategory("Duplicate Mutator option");

bool DuplicateMutatorVisitor::VisitBinaryOperator(BinaryOperator *stmt) {
  int line_no = (m_astContext->getSourceManager())
                    .getSpellingLineNumber(stmt->getBeginLoc());
  
  if (stmt->isAssignmentOp() && latest_loop_line != line_no) {
    CharSourceRange binop_range =
        CharSourceRange::getTokenRange(stmt->getBeginLoc(), stmt->getEndLoc());
    std::string bstmt_str = string(
        Lexer::getSourceText(binop_range, m_astContext->getSourceManager(),
                             m_astContext->getLangOpts()));
    if (pick_delete_or_duplicate() == "duplicate")
      m_rewriter->ReplaceText(stmt->getBeginLoc(), bstmt_str.length(),
                              "\n" + bstmt_str + ";\n" + bstmt_str + ";\n");
    else
      m_rewriter->ReplaceText(stmt->getBeginLoc(), bstmt_str.length(), "");
  }
  
  return true;
}

std::string DuplicateMutatorVisitor::pick_delete_or_duplicate() {
  return (ClangFuzzerCustomRandom::GetInstance()->rnd_yes_no(0.5) ? "duplicate"
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
  ClangFuzzerCustomRandom::CreateInstance(Seed, 2);

  // create a new Clang Tool instance (a LibTooling environment)
  ClangTool Tool(op.getCompilations(), op.getSourcePathList());

  // run the Clang Tool, creating a new FrontendAction (explained below)
  int result =
      Tool.run(&(*newFrontendActionFactory<DuplicateMutatorFrontendAction>()));

  // Free the random manager before exit
  ClangFuzzerCustomRandom::DeleteInstance(Seed);

  return result;
}
