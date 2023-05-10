#include "JumpMutator.h"
#include "../utils-fuzzer/GrayCCustomRandom.h"
#include <fstream>
#include <iostream>
#include <sstream>

/// <summary>
/// TODO: what this mutations does
///
/// TODO: Add details and mapping to the mutations in the paper.
///
/// Classes: JumpMutatorVisitor, JumpMutatorASTConsumer,
/// JumpMutatorFrontendAction
/// </summary>

static llvm::cl::OptionCategory MyToolCategory("Jump Mutator option");

bool JumpMutatorVisitor::VisitWhileStmt(WhileStmt *stmt) {
  if (!stmt || m_astContext->getSourceManager().isInExternCSystemHeader(
                   stmt->getBeginLoc()))
    return true;

  int node_id_loop = (stmt)->getID(*m_astContext);
  int line_no = (m_astContext->getSourceManager())
                    .getSpellingLineNumber(stmt->getBeginLoc());
  if (line_no >= m_latest_loop_start && line_no <= m_latest_loop_end)
    return true;

  std::string loop_break_var = "loop_break_" + to_string(node_id_loop);
  std::string loop_break_decl = "\nint " + loop_break_var + " = 0;\n";
  std::string jump_construct = pick_break_or_continue();
  int loop_break_limit = GrayCCustomRandom::GetInstance()->rnd_dice() + 1;
  std::string loop_break_block =
      loop_break_var + "++;\n" + "if(" + loop_break_var +
      "<=" + to_string(loop_break_limit) + "){\n" + jump_construct + ";\n}\n";
  if (stmt->getBeginLoc().isInvalid())
    return true;

  m_rewriter->InsertTextBefore(stmt->getBeginLoc(), loop_break_decl);
  Stmt *body = stmt->getBody();
  for (Stmt::child_iterator j_se = body->child_begin(), e = body->child_end();
       j_se != e; ++j_se) {
    Stmt *currStmt = *j_se;
    if (currStmt && !isa<ForStmt>(currStmt) && !isa<WhileStmt>(currStmt) &&
        currStmt->getBeginLoc().isValid()) {
      m_rewriter->InsertTextAfter(currStmt->getBeginLoc(),
                                  "\n" + loop_break_block + "\n");
      break;
    }
  }
  m_latest_loop_start = ((m_astContext->getSourceManager())
                             .getSpellingLineNumber(stmt->getBeginLoc()));
  m_latest_loop_end = ((m_astContext->getSourceManager())
                           .getSpellingLineNumber(stmt->getEndLoc()));
  return true;
}

bool JumpMutatorVisitor::VisitForStmt(ForStmt *stmt) {
  if (!stmt || m_astContext->getSourceManager().isInExternCSystemHeader(
                   stmt->getBeginLoc()))
    return true;

  int line_no = (m_astContext->getSourceManager())
                    .getSpellingLineNumber(stmt->getBeginLoc());
  if (line_no >= m_latest_loop_start && line_no <= m_latest_loop_end) {
    return true;
  }
  int node_id_loop = (stmt)->getID(*m_astContext);
  std::string loop_break_var = "loop_break_" + to_string(node_id_loop);
  std::string loop_break_decl = "\nint " + loop_break_var + " = 0;\n";

  int loop_break_limit = GrayCCustomRandom::GetInstance()->rnd_dice() + 1;
  std::string jump_construct = pick_break_or_continue();
  std::string loop_break_block =
      loop_break_var + "++;\n" + "if(" + loop_break_var +
      "<=" + to_string(loop_break_limit) + "){\n" + jump_construct + ";\n}\n";
  if (stmt->getBeginLoc().isInvalid())
    return true;

  m_rewriter->InsertTextBefore(stmt->getBeginLoc(), loop_break_decl);
  Stmt *body = stmt->getBody();
  for (Stmt::child_iterator j_se = body->child_begin(), e = body->child_end();
       j_se != e; ++j_se) {
    Stmt *currStmt = *j_se;
    if (currStmt && !isa<ForStmt>(currStmt) && !isa<WhileStmt>(currStmt) &&
        currStmt->getBeginLoc().isValid()) {
      m_rewriter->InsertTextAfter(currStmt->getBeginLoc(),
                                  "\n" + loop_break_block + "\n");
      break;
    }
  }
  m_latest_loop_start = ((m_astContext->getSourceManager())
                             .getSpellingLineNumber(stmt->getBeginLoc()));
  m_latest_loop_end = ((m_astContext->getSourceManager())
                           .getSpellingLineNumber(stmt->getEndLoc()));
  return true;
}

string JumpMutatorVisitor::pick_break_or_continue() {
  return (GrayCCustomRandom::GetInstance()->rnd_yes_no(0.5) ? "break"
                                                            : "continue");
}

void JumpMutatorFrontendAction::EndSourceFileAction() {
  SourceManager &SM = m_rewriter->getSourceMgr();
  std::error_code error_code;
  string base_filename =
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
  GrayCCustomRandom::CreateInstance(Seed, 50);    // Dice of 50
  // std::cout << "Seed in mutator: " << Seed << "\n";

  // create a new Clang Tool instance (a LibTooling environment)
  ClangTool Tool(op.getCompilations(), op.getSourcePathList());

  // run the Clang Tool, creating a new FrontendAction (explained below)
  int result =
      Tool.run(&(*newFrontendActionFactory<JumpMutatorFrontendAction>()));

  // Free the random manager before exit
  GrayCCustomRandom::DeleteInstance(Seed);

  return result;
}
