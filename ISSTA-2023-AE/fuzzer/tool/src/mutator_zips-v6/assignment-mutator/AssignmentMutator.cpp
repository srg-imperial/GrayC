#include "AssignmentMutator.h"
#include "../utils-fuzzer/GrayCCustomRandom.h"
#include "../utils-fuzzer/GrayCUtils.h"

#include <fstream>
#include <iostream>

/// <summary>
/// Delete part of RHS of assignment.
///
/// Classes: AssignmentMutatorVisitor, AssignmentMutatorASTConsumer,
/// AssignmentMutatorFrontendAction
/// </summary>

static llvm::cl::OptionCategory MyToolCategory("Assignment Mutator Option");

bool AssignmentMutatorVisitor::VisitUnaryOperator(UnaryOperator *stmt) {
  if (!stmt)
    return true;
  // else continue with the edit
  if (GrayCCustomRandom::GetInstance()->rnd_yes_no(0.1)) {
    CharSourceRange decl_range =
        CharSourceRange::getTokenRange(stmt->getBeginLoc(), stmt->getEndLoc());
    if (decl_range.isInvalid())
      return true; // if no decl, exit
    
    auto str_ref = Lexer::getSourceText(decl_range, 
        m_astContext->getSourceManager(),
        m_astContext->getLangOpts());
    if (str_ref.empty())
      return true; // if no decl, exit  
    
    std::string decl_str = std::string(str_ref);
    if (decl_str.empty())
      return true; // if no const, exit
  
    // Else continue with the mutation
    if (stmt->isIncrementOp()) {
      m_rewriter->ReplaceText(stmt->getExprLoc(), std::string("--"));
    } else if (stmt->isDecrementOp()) {
      m_rewriter->ReplaceText(stmt->getExprLoc(), std::string("++"));
    }
  }
  return true;
}

bool AssignmentMutatorVisitor::VisitDeclStmt(clang::DeclStmt *stmt) {
  if (!stmt || !stmt->isSingleDecl())
    return true; // not null and only if a single decl (int a, b; -> skip)
  
  if (GrayCCustomRandom::GetInstance()->rnd_yes_no(0.5))
    return true; // quite sometimes
  
  clang::VarDecl *vd = cast<clang::VarDecl>(stmt->getSingleDecl());
  if (!vd)  
    return true; // Can be null
    
  CharSourceRange decl_range =
        CharSourceRange::getTokenRange(stmt->getBeginLoc(), stmt->getEndLoc());
  if (decl_range.isInvalid())
    return true; // if no decl, exit

  auto str_ref = Lexer::getSourceText(decl_range,
      m_astContext->getSourceManager(),
      m_astContext->getLangOpts());
  if (str_ref.empty() || str_ref.find("__")!=std::string::npos)
        return true; // if no decl, exit
  
  QualType qt = vd->getType();
  if (qt.isNull() || qt->isArrayType() || !qt.isTrivialType(*m_astContext))
    return true;
  
  std::string type = qt.getAsString();
  if (!type.empty() && (type == "int" || type == "short")) {
    CharSourceRange declRange = CharSourceRange::getTokenRange(
        stmt->getBeginLoc(), stmt->getEndLoc());
    if (declRange.isInvalid())
      return true; // if no decl, exit
              
    std::string decl_str = std::string(str_ref);
    if (decl_str.empty())
      return true; // if no const, exit
    
    if (GrayCUtils::getAssignmentNos(decl_str) > 1)
      return true; // if got multiple assignement, return 
         
    std::string var_name = vd->getQualifiedNameAsString();
    if (var_name.empty())
      return true; // if not name, exit
          
    // mutate
    m_rewriter->ReplaceText(declRange, type + " " + var_name + " = 8;");
  }
  
  return true;
}

void AssignmentMutatorFrontendAction::EndSourceFileAction() {
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
      Tool.run(&(*newFrontendActionFactory<AssignmentMutatorFrontendAction>()));

  // Free the random manager before exit
  GrayCCustomRandom::DeleteInstance(Seed);

  return result;
}
