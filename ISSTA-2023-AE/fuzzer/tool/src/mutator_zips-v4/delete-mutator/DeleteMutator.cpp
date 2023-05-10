#include "DeleteMutator.h"
#include "../random-manager/ClangFuzzerCustomRandom.h"
#include <iostream>
#include <fstream>

/// <summary>
/// TODO: what this mutations does
/// 
/// TODO: Add details and mapping to the mutations in the paper. 
/// 
/// Classes: DeleteMutatorVisitor, DeleteMutatorASTConsumer, DeleteMutatorFrontendAction
/// </summary>

static llvm::cl::OptionCategory MyToolCategory("Delete Mutator option");
    
bool DeleteMutatorVisitor::VisitWhileStmt(WhileStmt *stmt) {
    if (ClangFuzzerCustomRandom::GetInstance()->rnd_yes_no(0.7)) return true;
    
    Expr *cond = stmt->getCond();
    CharSourceRange condRange = CharSourceRange::getTokenRange(cond->getBeginLoc(), cond->getEndLoc());
    if (condRange.isInvalid())
        return true;
    
    m_rewriter->InsertTextBefore(stmt->getBody()->getEndLoc(),"\nbreak;\n");
    int node_id = cast<Stmt>(stmt)->getID(*m_astContext);
    std::string cond_call_expr_str = string(Lexer::getSourceText(condRange, m_astContext->getSourceManager(), m_astContext->getLangOpts()));
    m_rewriter->InsertTextBefore(stmt->getBeginLoc(),"\nint while_condition_"+to_string(node_id)+" = "+cond_call_expr_str+";\n");
    m_rewriter->ReplaceText(condRange, "while_condition_"+to_string(node_id));
    return true;
}

bool DeleteMutatorVisitor::VisitIfStmt(IfStmt *stmt) {
    float randomValue = ClangFuzzerCustomRandom::GetInstance()->rnd_probability();
    if (!(randomValue < 0.5)) return true;

    Expr *expr = stmt->getCond();
    CharSourceRange conditionRange = CharSourceRange::getTokenRange(expr->getBeginLoc(), expr->getEndLoc());
    if (conditionRange.isInvalid())
        return true;
	
    llvm::StringRef condition_str = Lexer::getSourceText(conditionRange, m_astContext->getSourceManager(), m_astContext->getLangOpts());
    string condition_type_str = expr->getType().getAsString();
    if (condition_str.empty() || condition_type_str.empty()) 
        return true;
	
    if (randomValue>=0.75)
        m_rewriter->ReplaceText(conditionRange, "1");
    else
        m_rewriter->ReplaceText(conditionRange, "0");
    
    return true;
}
        
void DeleteMutatorFrontendAction::EndSourceFileAction() {
    SourceManager &SM = m_rewriter->getSourceMgr();
    std::string base_filename = std::string(SM.getFileEntryForID(SM.getMainFileID())->getName());
    std::error_code error_code;
      
    // Write:
    std::string::size_type const p(base_filename.find_last_of('.'));
    std::string file_without_extension = base_filename.substr(0, p);
      	
    llvm::raw_fd_ostream outFile(file_without_extension+".mutated.c", error_code);
    m_rewriter->getEditBuffer(SM.getMainFileID()).write(outFile);
    outFile.close();
}
	
int main(int argc, const char **argv) {
    // parse the command-line args passed to your code
    int argc_new = argc - 1;
    CommonOptionsParser op(argc_new, argv, MyToolCategory);

    // Create Random Generaton, uniform real dist
    unsigned long Seed = std::stoi(argv[argc - 1]); // Seed is always in the end
    ClangFuzzerCustomRandom::CreateInstance(Seed, 6); // Dice of 6
    //std::cout << "Seed in mutator: " << Seed << "\n";

    // create a new Clang Tool instance (a LibTooling environment)
    ClangTool Tool(op.getCompilations(), op.getSourcePathList());

    // run the Clang Tool, creating a new FrontendAction (explained below)
    int result = Tool.run(&(*newFrontendActionFactory<DeleteMutatorFrontendAction>()));

    // Free the random manager before exit
    ClangFuzzerCustomRandom::DeleteInstance(Seed);

    return result;
}
