#include "FunctionMerger.h"
#include "../random-manager/ClangFuzzerCustomRandom.h"
#include <fstream>
#include <iostream>
#include <sstream>

/// <summary>
/// TODO: what this mutations does
///
/// TODO: Add details and mapping to the mutations in the paper.
///
/// Classes: FunctionCombinerVisitor, FunctionCombinerASTConsumer,
/// FunctionCombinerFrontendAction
/// </summary>

static llvm::cl::OptionCategory MyToolCategory("Function Adder option");
std::string output_filename;
bool FunctionCombinerVisitor::VisitFunctionDecl(clang::FunctionDecl *func) {
  std::string append_string = getCandidateStatements();
  if ((func->isMain())) {
    std::string replace_func_text = getCandidateMutatingFunctionMap();
    replace_func_text = append_string + ";\n" + replace_func_text;
    if (!replace_func_text.empty())
      m_rewriter->InsertTextBefore(func->getBeginLoc(),
                                   replace_func_text + "\n");
  }
  return true;
}

std::string FunctionCombinerVisitor::getCandidateStatements() {
  std::ifstream inFile;
  inFile.open("./Global-Info.txt");
  std::stringstream strStream;
  strStream << inFile.rdbuf();
  std::string stmts = strStream.str();
  return (stmts);
}

std::string FunctionCombinerVisitor::getCandidateMutatingFunctionMap() {
  std::ifstream file("./Mutation-Hooks-Functions.txt");
  if (file.is_open()) {
    std::string funcName;
    std::string funcSign;
    std::string funcBody;
    while (true) {
      std::getline(file, funcName);
      std::getline(file, funcSign);
      std::getline(file, funcBody);
      if (file.eof())
        break;

      size_t pos = funcBody.find(funcName);
      if (pos !=
          std::string::npos) // Can find funcName in funcBody (first position)
        funcBody.replace(pos, funcName.length(), "mutator_function");
      return (funcBody);
    }
  }
  file.close();
  return "";
}

void FunctionCombinerFrontendAction::EndSourceFileAction() {
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
  static llvm::cl::OptionCategory FunctionMergerCategory("Transform tool option");
  static llvm::cl::opt<std::string> OutputFile("output",
                                              llvm::cl::desc("Name of the output file"),
                                              llvm::cl::cat(FunctionMergerCategory), cl::Required);
  static llvm::cl::opt<unsigned long> Seed("seed",
                                              llvm::cl::desc("String seed to feed into the mutator"),
                                              llvm::cl::cat(FunctionMergerCategory), cl::Required);

  llvm::cl::HideUnrelatedOptions(FunctionMergerCategory);
  CommonOptionsParser op(argc, argv, FunctionMergerCategory);

  // Create Random Generaton, uniform real dist

  ClangFuzzerCustomRandom::CreateInstance(Seed.getValue(), 6); // Dice of 6
  output_filename = OutputFile.getValue();
  // create a new Clang Tool instance (a LibTooling environment)
  ClangTool Tool(op.getCompilations(), op.getSourcePathList());

  // run the Clang Tool, creating a new FrontendAction (explained below)
  int result =
      Tool.run(&(*newFrontendActionFactory<FunctionCombinerFrontendAction>()));

  // Free the random manager before exit
  ClangFuzzerCustomRandom::DeleteInstance(Seed);

  return result;
}

