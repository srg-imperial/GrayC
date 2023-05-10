#include "FunctionExtractor.h"

#include <algorithm>
#include <fstream>
#include <iostream>
#include <sstream>

/// <summary>
/// TODO: what this mutations does
///
/// TODO: Add details and mapping to the mutations in the paper.
///
/// Classes: HookExtractorVisitor, HookExtractorASTConsumer,
/// HookExtractorFrontendAction
/// </summary>

static llvm::cl::OptionCategory MyToolCategory("Hook Extractor option");

void HookExtractorVisitor::appendLineToFile(string filepath, string line) {
  std::ofstream file;
  // can't enable exception now because of gcc bug that raises ios_base::failure
  // with useless message file.exceptions(file.exceptions() |
  // std::ios::failbit);
  
  file.open(filepath, std::ios::out | std::ios::app);
  if (file.fail())
    errs() << "Problem opening given file\n";
  // make sure write fails with exception if something is wrong
  file.exceptions(file.exceptions() | std::ios::failbit |
                  std::ifstream::badbit);
  file << line;
}

bool HookExtractorVisitor::VisitFunctionDecl(FunctionDecl *func) {
  if (m_astContext->getSourceManager().isInExternCSystemHeader(
          func->getBeginLoc()))
    return true;

  if (func->hasBody()) {
    Stmt *body = func->getBody();
    fn_start_line_no = (m_astContext->getSourceManager())
                           .getSpellingLineNumber(body->getBeginLoc());
    fn_end_line_no = (m_astContext->getSourceManager())
                         .getSpellingLineNumber(body->getEndLoc());
    if ((!(func->isMain()))) {
      std::string funcName = func->getNameInfo().getName().getAsString();
      std::string funcInfo = "";
      std::string paramInfo = "";
      std::string func_text = std::string(Lexer::getSourceText(
          CharSourceRange::getCharRange(func->getSourceRange()),
          m_astContext->getSourceManager(), m_astContext->getLangOpts()));
      
      for (unsigned i = 0; i < func->getNumParams(); i++)
        paramInfo = paramInfo +
                    func->parameters()[i]->getOriginalType().getAsString() +
                    ",";
      func_text.erase(std::remove(func_text.begin(), func_text.end(), '\n'),
                      func_text.end());
      funcInfo = funcName + "\n" + func->getReturnType().getAsString() + "\t" +
                 paramInfo + "\n" + func_text + "\n";
      appendLineToFile("./Mutation-Hooks-Functions.txt", funcInfo);
    }
  }
  return true;
}

bool HookExtractorVisitor::VisitVarDecl(clang::VarDecl *NamedDecl) {
  if (m_astContext->getSourceManager().isInExternCSystemHeader(
          NamedDecl->getBeginLoc()))
    return true;

  if (NamedDecl->hasGlobalStorage()) {
    CharSourceRange declRange = CharSourceRange::getTokenRange(
        NamedDecl->getBeginLoc(), NamedDecl->getEndLoc());
    std::string decl_str = std::string(
        Lexer::getSourceText(declRange, m_astContext->getSourceManager(),
                             m_astContext->getLangOpts()));
    decl_str.erase(std::remove(decl_str.begin(), decl_str.end(), '\n'),
                   decl_str.end());
    appendLineToFile("./Global-Info.txt", decl_str + ";" + "\n");
  }
  return true;
}

bool HookExtractorVisitor::VisitRecordDecl(clang::RecordDecl *RDecl) {
  if (m_astContext->getSourceManager().isInExternCSystemHeader(
          RDecl->getBeginLoc()))
    return true;

  CharSourceRange declRange =
      CharSourceRange::getTokenRange(RDecl->getBeginLoc(), RDecl->getEndLoc());
  std::string decl_str =
      string(Lexer::getSourceText(declRange, m_astContext->getSourceManager(),
                                  m_astContext->getLangOpts()));
  appendLineToFile("./Global-Info.txt", decl_str + ";" + "\n");
  return true;
}

int main(int argc, const char **argv) {
  // parse the command-line args passed to your code
  if (remove("./Mutation-Hooks-Functions.txt") != 0 ||
      remove("./Global-Info.txt"))
    errs() << "Problem deleting given file\n";
  int argc_new = argc - 1;
  CommonOptionsParser op(argc_new, argv, MyToolCategory);

  // create a new Clang Tool instance (a LibTooling environment)
  ClangTool Tool(op.getCompilations(), op.getSourcePathList());

  // run the Clang Tool, creating a new FrontendAction (explained below)
  int result =
      Tool.run(&(*newFrontendActionFactory<HookExtractorFrontendAction>()));

  return result;
}
