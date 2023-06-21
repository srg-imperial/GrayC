#include "JumpMutator.h"
#include "../random-manager/ClangFuzzerCustomRandom.h"
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
// Write up in a mail
// Shorten expression mutator
// Ternary operators

static llvm::cl::OptionCategory MyToolCategory("Jump Mutator option");
std::string output_filename;
bool JumpMutatorVisitor::VisitWhileStmt(WhileStmt *stmt) {
  if (m_astContext->getSourceManager().isInExternCSystemHeader(
          stmt->getBeginLoc()))
    return true;

  int node_id_loop = (stmt)->getID(*m_astContext);
  std::string loop_break_var = "loop_break_" + to_string(node_id_loop);
  std::string loop_break_decl = "\nint " + loop_break_var + " = 0;\n";
  std::string jump_construct = pick_break_or_continue();
  int loop_break_limit = ClangFuzzerCustomRandom::GetInstance()->rnd_dice() + 1;
  std::string loop_break_block =
      loop_break_var + "++;\n" + "if(" + loop_break_var +
      "<=" + to_string(loop_break_limit) + "){\n" + jump_construct + ";\n}\n";
  if (!stmt->getBeginLoc().isValid())
    return true;

  m_rewriter->InsertTextBefore(stmt->getBeginLoc(), loop_break_decl);
  Stmt *body = stmt->getBody();
  for (Stmt::child_iterator j_se = body->child_begin(), e = body->child_end();
       j_se != e; ++j_se) {
    Stmt *currStmt = *j_se;
    if (currStmt && currStmt->getBeginLoc().isValid())
      m_rewriter->InsertTextAfter(currStmt->getBeginLoc(),
                                  "\n" + loop_break_block + "\n");
    break;
  }
  return true;
}

bool JumpMutatorVisitor::VisitForStmt(ForStmt *stmt) {
  if (m_astContext->getSourceManager().isInExternCSystemHeader(
          stmt->getBeginLoc()))
    return true;

  int node_id_loop = (stmt)->getID(*m_astContext);
  string loop_break_var = "loop_break_" + to_string(node_id_loop);
  string loop_break_decl = "\nint " + loop_break_var + " = 0;\n";
  int loop_break_limit = ClangFuzzerCustomRandom::GetInstance()->rnd_dice() + 1;
  string jump_construct = pick_break_or_continue();
  string loop_break_block = loop_break_var + "++;\n" + "if(" + loop_break_var +
                            "<=" + to_string(loop_break_limit) + "){\n" +
                            jump_construct + ";\n}\n";
  if (!stmt->getBeginLoc().isValid())
    return true;

  m_rewriter->InsertTextBefore(stmt->getBeginLoc(), loop_break_decl);
  Stmt *body = stmt->getBody();
  for (Stmt::child_iterator j_se = body->child_begin(), e = body->child_end();
       j_se != e; ++j_se) {
    Stmt *currStmt = *j_se;
    if (currStmt && currStmt->getBeginLoc().isValid())
      m_rewriter->InsertTextAfter(currStmt->getBeginLoc(),
                                  "\n" + loop_break_block + "\n");
    break;
  }
  return true;
}

string JumpMutatorVisitor::pick_break_or_continue() {
  return (ClangFuzzerCustomRandom::GetInstance()->rnd_yes_no(0.5) ? "break"
                                                                  : "continue");
}

void JumpMutatorFrontendAction::EndSourceFileAction() {
  SourceManager &SM = m_rewriter->getSourceMgr();
  std::error_code error_code;
  string base_filename =
      string(SM.getFileEntryForID(SM.getMainFileID())->getName());
  std::string::size_type const p(base_filename.find_last_of('.'));
  std::string file_without_extension = base_filename.substr(0, p);
  llvm::raw_fd_ostream outFile(file_without_extension + ".mutated.c",
                               error_code);
  m_rewriter->getEditBuffer(SM.getMainFileID()).write(outFile);
  outFile.close();
}

int main(int argc, const char **argv)
{
  static llvm::cl::OptionCategory JumpMutatorCategory("Transform tool option");
  static llvm::cl::opt<std::string> OutputFile("output",
                                              llvm::cl::desc("Name of the output file"),
                                              llvm::cl::cat(JumpMutatorCategory), cl::Required);
  static llvm::cl::opt<unsigned long> Seed("seed",
                                              llvm::cl::desc("String seed to feed into the mutator"),
                                              llvm::cl::cat(JumpMutatorCategory), cl::Required);

  llvm::cl::HideUnrelatedOptions(JumpMutatorCategory);
  CommonOptionsParser op(argc, argv, JumpMutatorCategory);

  // Create Random Generaton, uniform real dist

  ClangFuzzerCustomRandom::CreateInstance(Seed.getValue(), 6); // Dice of 6
  output_filename = OutputFile.getValue();
  // create a new Clang Tool instance (a LibTooling environment)
  ClangTool Tool(op.getCompilations(), op.getSourcePathList());

  // run the Clang Tool, creating a new FrontendAction (explained below)
  int result =
      Tool.run(&(*newFrontendActionFactory<JumpMutatorFrontendAction>()));

  // Free the random manager before exit
  ClangFuzzerCustomRandom::DeleteInstance(Seed);

  return result;
}

