#include "AppendExpression.h"
#include "../utils-fuzzer-cons/GrayCCustomRandom.h"
#include <algorithm>
#include <fstream>
#include <iostream>
#include <map>
#include <sstream>

/// <summary>
/// Hybrid Append - Extract a Csmith expresssion to later use with code mutators
///
/// Classes: AppendExpressionMutatorVisitor, AppendExpressionMutatorASTConsumer
/// , AppendExpressionMutatorFrontendAction
/// </summary>

static llvm::cl::OptionCategory MyToolCategory("Append Expression Option");

bool AppendExpressionMutatorVisitor::VisitFunctionDecl(FunctionDecl *func) {
  if (!func)
    return true;
  
  static std::string _fuzzer_csmith_decl_file =
      "/home/user42/fuzzers/copy_5/llvm-csmith-5/llvm-fuzzer-build/fuzzer_csmith-tmp/"
      "csmith_decls.txt";
  static std::string _fuzzer_csmith_expr_file =
      "/home/user42/fuzzers/copy_5/llvm-csmith-5/llvm-fuzzer-build/fuzzer_csmith-tmp/"
      "csmith_expr.txt";

  std::string func_name = func->getNameInfo().getAsString();
  if (func_name == "main") {
    // get function name, body and return type information
    Stmt *body = func->getBody();
    if (!body)
      return true;

    Stmt *lastStmt = nullptr;
    for (Stmt::child_iterator j_se = body->child_begin(), e = body->child_end();
         j_se != e; ++j_se) {
      lastStmt = *j_se;
      break;
    }

    if (lastStmt != nullptr) {
      std::string csmith_decls = readFileIntoString(_fuzzer_csmith_decl_file);
      std::string csmith_expr = readFileIntoString(_fuzzer_csmith_expr_file);
      if (csmith_decls.empty() || csmith_expr.empty())
        return true; // missing declrations
      
      m_rewriter->InsertTextBefore(lastStmt->getBeginLoc(),
                                   "\n{\n" + csmith_decls + "\n" + csmith_expr +
                                       ";\n}\n");
      decl_start_line_number = (m_astContext->getSourceManager())
                                   .getSpellingLineNumber(body->getBeginLoc());
      decl_end_line_number = (m_astContext->getSourceManager())
                                 .getSpellingLineNumber(body->getEndLoc());
    } else {
      std::cerr << "ERROR AppendExpressionMutatorVisitor::VisitFunctionDecl >> "
                   "CANNOT FIND LAST STATEMENT"
                << std::endl;
    }
    
    lastStmt = nullptr;
    body = nullptr;
  }
  
  return true;
}

std::string
AppendExpressionMutatorVisitor::readFileIntoString(const string &path) {
  ifstream input_file(path);
  if (!input_file.is_open()) {
    cerr << "Could not open the file - '" << path << "'" << endl;
    exit(EXIT_FAILURE);
  }
  return string((std::istreambuf_iterator<char>(input_file)),
                std::istreambuf_iterator<char>());
}

void AppendExpressionMutatorFrontendAction::EndSourceFileAction() {
  SourceManager &SM = m_rewriter->getSourceMgr();
  std::error_code error_code;
  std::string base_filename =
      string(SM.getFileEntryForID(SM.getMainFileID())->getName());

  std::string::size_type const p(base_filename.find_last_of('.'));
  std::string file_without_extension = base_filename.substr(0, p);

  llvm::raw_fd_ostream outFile(file_without_extension + ".mutated.c",
                               error_code, llvm::sys::fs::F_None);
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
  int result = Tool.run(
      &(*newFrontendActionFactory<AppendExpressionMutatorFrontendAction>()));

  // Free the random manager before exit
  GrayCCustomRandom::DeleteInstance(Seed);

  return result;
}
