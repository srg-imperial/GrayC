#include "RenameTransform.h"
#include <string>
#include <iostream>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <map>

/// <summary>
/// TODO: what this mutations does
/// 
/// TODO: Add details and mapping to the mutations in the paper. 
/// 
/// Classes: HookExtractorVVisitor, HookExtractorVASTConsumer, HookExtractorVFrontendAction
/// </summary>

static llvm::cl::OptionCategory MyToolCategory("Rename Transform option");

// TODO: move to a proper struct
std::map<string,string> global_varnames;
std::string filename = "";
std::string file_without_extension = "";

bool HookExtractorVisitor::VisitVarDecl(clang::VarDecl *NamedDecl) {
    if (m_astContext->getSourceManager().isInExternCSystemHeader(NamedDecl->getBeginLoc()))
        return true;
      
    if (NamedDecl->hasGlobalStorage())  {
        string var_name = (NamedDecl->getNameAsString());
        global_varnames[var_name]= var_name + "_copy";
    }
    return true;
}

bool HookExtractorVisitor::VisitRecordDecl(clang::RecordDecl *RDecl) {
    clang::NamedDecl* nd = cast<clang::NamedDecl>(RDecl);
    string var_name = (nd->getNameAsString());
    global_varnames[var_name]= var_name + "_copy";
    return true;
}

void HookExtractorFrontendAction::EndSourceFileAction() {
    SourceManager &SM = m_rewriter->getSourceMgr();
    filename = string(SM.getFileEntryForID(SM.getMainFileID())->getName());
    std::string::size_type const p(filename.find_last_of('.'));
    file_without_extension = filename.substr(0, p);
}

int main(int argc, const char **argv) {
    // parse the command-line args passed to your code
    int argc_new = argc - 1;
    CommonOptionsParser op(argc_new, argv, MyToolCategory);

    // create a new Clang Tool instance (a LibTooling environment)
    ClangTool Tool(op.getCompilations(), op.getSourcePathList());

    // run the Clang Tool, creating a new FrontendAction (explained below)
    int result = Tool.run(&(*newFrontendActionFactory<HookExtractorFrontendAction>()));

    std::map<std::string, std::string>::iterator it;
    string rename_command = "bin/clang-rename";
    for(it=global_varnames.begin(); it!=global_varnames.end(); ++it) {
	    //llvm::outs()<<it->first<<"\n"; // Print variables of mutated program
	    if ((it->first).empty())
		    rename_command = rename_command + " -qualified-name=" + it->first + " -new-name=" + it->second;
    }
    rename_command = rename_command + " " + filename + " -- > " + file_without_extension + "_rename_output.c";
    //int output = system(rename_command.c_str());
    return result;
}
