#include "AssignmentMutator.h"
#include "../random-manager/ClangFuzzerCustomRandom.h"

#include <fstream>
#include <iostream>

/// <summary>
/// Delete part of RHS of assignment.
///
/// TODO: Add details and mapping to the mutations in the paper.
///
/// Classes: AssignmentMutatorVisitor, AssignmentMutatorASTConsumer,
/// AssignmentMutatorFrontendAction
/// </summary>

static llvm::cl::OptionCategory MyToolCategory("Assignment Mutator option");

bool AssignmentMutatorVisitor::VisitUnaryOperator(UnaryOperator *stmt) {
  if (ClangFuzzerCustomRandom::GetInstance()->rnd_yes_no(0.1)) {
    CharSourceRange decl_range =
        CharSourceRange::getTokenRange(stmt->getBeginLoc(), stmt->getEndLoc());
    std::string decl_str = string(
        Lexer::getSourceText(decl_range, m_astContext->getSourceManager(),
                             m_astContext->getLangOpts()));
    if (stmt->isIncrementOp()) {
      m_rewriter->ReplaceText(stmt->getExprLoc(), "--");
    } else if (stmt->isDecrementOp()) {
      m_rewriter->ReplaceText(stmt->getExprLoc(), "++");
    }
  }
  return true;
}

bool AssignmentMutatorVisitor::VisitDeclStmt(clang::DeclStmt *stmt) {
  if (ClangFuzzerCustomRandom::GetInstance()->rnd_yes_no(0.5)) {
    if (stmt->isSingleDecl()) {
      clang::VarDecl *vd = cast<clang::VarDecl>(stmt->getSingleDecl());
      std::string type = (vd->getType()).getAsString();
      if (type == "int" || type == "short") {
        CharSourceRange declRange = CharSourceRange::getTokenRange(
            stmt->getBeginLoc(), stmt->getEndLoc());
        std::string var_name = vd->getQualifiedNameAsString();
        m_rewriter->ReplaceText(declRange, type + " " + var_name + " = 8;");
      }
    }
  }
  return true;
}

void AssignmentMutatorFrontendAction::EndSourceFileAction() {
  SourceManager &SM = m_rewriter->getSourceMgr();
  std::string base_filename =
      string(SM.getFileEntryForID(SM.getMainFileID())->getName());
  std::error_code error_code;

  // Write:
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
  unsigned long Seed = std::stoi(argv[argc - 1]);   // Seed is always in the end
  ClangFuzzerCustomRandom::CreateInstance(Seed, 6); // Dice of 6

  // create a new Clang Tool instance (a LibTooling environment)
  ClangTool Tool(op.getCompilations(), op.getSourcePathList());

  // run the Clang Tool, creating a new FrontendAction (explained below)
  int result =
      Tool.run(&(*newFrontendActionFactory<AssignmentMutatorFrontendAction>()));

  // Free the random manager before exit
  ClangFuzzerCustomRandom::DeleteInstance(Seed);

  return result;
}
