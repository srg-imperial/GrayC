#include "DeleteMutator.h"
#include "../utils-fuzzer/GrayCCustomRandom.h"
#include <fstream>
#include <iostream>

/// <summary>
/// This mutator remove text form a program: delete blocks of code
/// -  Replace if-then-else by either its if or else block
/// -  Same for while loops
///
/// Classes: DeleteMutatorVisitor, DeleteMutatorASTConsumer,
/// DeleteMutatorFrontendAction
/// </summary>

static llvm::cl::OptionCategory MyToolCategory("Delete Mutator option");

bool DeleteMutatorVisitor::VisitWhileStmt(WhileStmt *stmt) {
  if (!stmt || GrayCCustomRandom::GetInstance()->rnd_yes_no(0.7))
    return true;

  Expr *cond = stmt->getCond();
  if (!cond)
    return true;
  
  CharSourceRange condRange =
      CharSourceRange::getTokenRange(cond->getBeginLoc(), cond->getEndLoc());
  if (condRange.isInvalid())
    return true;

  // Edit only if not null and valid
  m_rewriter->InsertTextBefore(stmt->getBody()->getEndLoc(), "\nbreak;\n");
  int node_id = cast<Stmt>(stmt)->getID(*m_astContext);
  
  auto str_ref = Lexer::getSourceText(condRange, 
      m_astContext->getSourceManager(),
      m_astContext->getLangOpts());
  if (str_ref.empty())
    return true; // if no expr, exit
  
  std::string cond_call_expr_str = std::string(str_ref);
  if (cond_call_expr_str.empty())
    return true; // if no expr, exit
  
  // If all okay, then do the mutation
  m_rewriter->InsertTextBefore(stmt->getBeginLoc(),
                               "\nint while_condition_" + to_string(node_id) +
                                   " = " + cond_call_expr_str + ";\n");
  m_rewriter->ReplaceText(condRange, "while_condition_" + to_string(node_id));
  return true;
}

bool DeleteMutatorVisitor::VisitIfStmt(IfStmt *stmt) {
  if (!stmt)
    return true;
  // Else continue
  float randomValue = GrayCCustomRandom::GetInstance()->rnd_probability();
  if (!(randomValue < 0.5))
    return true;

  Expr *expr = stmt->getCond();
  if (!expr)
    return true;
  
  CharSourceRange conditionRange =
      CharSourceRange::getTokenRange(expr->getBeginLoc(), expr->getEndLoc());
  if (conditionRange.isInvalid())
    return true;

  // Edit only if not null and valid
  llvm::StringRef condition_str =
      Lexer::getSourceText(conditionRange, m_astContext->getSourceManager(),
                           m_astContext->getLangOpts());
  if (condition_str.empty())
    return true; // if no expr, exit
  
  std::string condition_type_str = expr->getType().getAsString();
  if (condition_str.empty() || condition_type_str.empty())
    return true;

  // Delete part of if-then-else block
  m_rewriter->ReplaceText(conditionRange, ((randomValue >= 0.75) ? "1" : "0"));
  return true;
}

void DeleteMutatorFrontendAction::EndSourceFileAction() {
  SourceManager &SM = m_rewriter->getSourceMgr();
  std::string base_filename =
      std::string(SM.getFileEntryForID(SM.getMainFileID())->getName());
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
  unsigned long Seed = std::stoi(argv[argc - 1]); // Seed is always in the end
  GrayCCustomRandom::CreateInstance(Seed, 6);     // Dice of 6
  // std::cout << "Seed in mutator: " << Seed << "\n";

  // create a new Clang Tool instance (a LibTooling environment)
  ClangTool Tool(op.getCompilations(), op.getSourcePathList());

  // run the Clang Tool, creating a new FrontendAction (explained below)
  int result =
      Tool.run(&(*newFrontendActionFactory<DeleteMutatorFrontendAction>()));

  // Free the random manager before exit
  GrayCCustomRandom::DeleteInstance(Seed);

  return result;
}
