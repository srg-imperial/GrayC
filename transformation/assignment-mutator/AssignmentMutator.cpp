#include "AssignmentMutator.h"
#include "../random-manager/ClangFuzzerCustomRandom.h"

#include <fstream>
#include <iostream>

/// <summary>
/// Delete part of RHS of assignment.
/// Classes: AssignmentMutatorVisitor, AssignmentMutatorASTConsumer,
/// AssignmentMutatorFrontendAction
/// </summary>

static llvm::cl::OptionCategory MyToolCategory("Assignment Mutator option");
std::string output_filename;

bool AssignmentMutatorVisitor::VisitUnaryOperator(UnaryOperator *stmt)
{
  if (ClangFuzzerCustomRandom::GetInstance()->rnd_yes_no(0.1))
  {
    CharSourceRange decl_range =
        CharSourceRange::getTokenRange(stmt->getBeginLoc(), stmt->getEndLoc());
    std::string decl_str = string(
        Lexer::getSourceText(decl_range, m_astContext->getSourceManager(),
                             m_astContext->getLangOpts()));
    if (stmt->isIncrementOp())
    {
      m_rewriter->ReplaceText(stmt->getExprLoc(), "--");
    }
    else if (stmt->isDecrementOp())
    {
      m_rewriter->ReplaceText(stmt->getExprLoc(), "++");
    }
  }
  return true;
}

bool AssignmentMutatorVisitor::VisitDeclStmt(clang::DeclStmt *stmt)
{
  if (ClangFuzzerCustomRandom::GetInstance()->rnd_yes_no(0.5))
  {
    if (stmt->isSingleDecl())
    {
      clang::VarDecl *vd = cast<clang::VarDecl>(stmt->getSingleDecl());
      std::string type = (vd->getType()).getAsString();
      if (type == "int" || type == "short")
      {
        CharSourceRange declRange = CharSourceRange::getTokenRange(
            stmt->getBeginLoc(), stmt->getEndLoc());
        std::string var_name = vd->getQualifiedNameAsString();
        m_rewriter->ReplaceText(declRange, type + " " + var_name + " = 8;");
      }
    }
  }
  return true;
}

void AssignmentMutatorFrontendAction::EndSourceFileAction()
{
  SourceManager &SM = m_rewriter->getSourceMgr();
  std::error_code error_code;

  llvm::raw_fd_ostream outFile(output_filename,
                               error_code);
  m_rewriter->getEditBuffer(SM.getMainFileID()).write(outFile);
  outFile.close();
}

int main(int argc, const char **argv)
{
  static llvm::cl::OptionCategory AssignmentMutatorCategory("Transform tool option");
  static llvm::cl::opt<std::string> OutputFile("output",
                                              llvm::cl::desc("Name of the output file"),
                                              llvm::cl::cat(AssignmentMutatorCategory), cl::Required);
  static llvm::cl::opt<unsigned long> Seed("seed",
                                              llvm::cl::desc("String seed to feed into the mutator"),
                                              llvm::cl::cat(AssignmentMutatorCategory), cl::Required);

  llvm::cl::HideUnrelatedOptions(AssignmentMutatorCategory);
  CommonOptionsParser op(argc, argv, AssignmentMutatorCategory);

  // Create Random Generaton, uniform real dist

  ClangFuzzerCustomRandom::CreateInstance(Seed.getValue(), 6); // Dice of 6
  output_filename = OutputFile.getValue();
  // create a new Clang Tool instance (a LibTooling environment)
  ClangTool Tool(op.getCompilations(), op.getSourcePathList());

  // run the Clang Tool, creating a new FrontendAction (explained below)
  int result =
      Tool.run(&(*newFrontendActionFactory<AssignmentMutatorFrontendAction>()));

  // Free the random manager before exit
  ClangFuzzerCustomRandom::DeleteInstance(Seed);

  return result;
}
