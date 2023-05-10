#include "clang/Driver/Options.h"
#include "clang/AST/AST.h"
#include "clang/AST/ASTContext.h"
#include "clang/AST/ASTConsumer.h"
#include "clang/AST/RecursiveASTVisitor.h"
#include "clang/Frontend/ASTConsumers.h"
#include "clang/Frontend/FrontendActions.h"
#include "clang/Frontend/CompilerInstance.h"
#include "clang/Tooling/CommonOptionsParser.h"
#include "clang/Tooling/Tooling.h"
#include "clang/Rewrite/Core/Rewriter.h"
#include <iostream>
#include <algorithm>
#include <string>
#include <fstream>

using namespace std;
using namespace clang;
using namespace clang::driver;
using namespace clang::tooling;
using namespace llvm;

static llvm::cl::OptionCategory MyToolCategory("Hook Extractor option");

class GlobalExtractorVisitor : public RecursiveASTVisitor<GlobalExtractorVisitor> {
private:
    ASTContext *m_astContext; // used for getting additional AST info
    Rewriter *m_rewriter;

public:
    explicit GlobalExtractorVisitor(CompilerInstance *CI, Rewriter *rewriter)
      : m_astContext(&(CI->getASTContext())), m_rewriter(rewriter) // initialize private members
    {
        m_rewriter->setSourceMgr(m_astContext->getSourceManager(), m_astContext->getLangOpts());
    }

    static void appendLineToFile(string filepath, string line)
    {
        std::ofstream file;

        file.open(filepath, std::ios::out | std::ios::app);
        if (file.fail())
            errs() << "Problem opening given file\n";

        //make sure write fails with exception if something is wrong
        file.exceptions(file.exceptions() | std::ios::failbit | std::ifstream::badbit);

        file << line;
    }

    bool VisitFunctionDecl(FunctionDecl *func) {
        if (func->isMain()) {
            string func_text = string(Lexer::getSourceText(CharSourceRange::getCharRange(func->getSourceRange()), m_astContext->getSourceManager(), m_astContext->getLangOpts()));
            func_text = func_text.substr(0,func_text.find("{"));
            appendLineToFile("./Main-Sign.txt",func_text);
        }
        return true;

    }

    bool VisitVarDecl(clang::VarDecl *NamedDecl) {
        if (NamedDecl->hasGlobalStorage() && !(NamedDecl->isStaticLocal()))  {
            string decl_str = NamedDecl->getNameAsString() + "\t" + NamedDecl->getType().getAsString();
            llvm::outs()<<decl_str<<"\n";
            appendLineToFile("./Global-Info.txt",decl_str+"\n");
        }

        return true;
    }

    // bool VisitTypedefNameDecl(TypedefNameDecl *tdef){
    //   string tdef_text = Lexer::getSourceText(CharSourceRange::getCharRange(tdef->getSourceRange()), m_astContext->getSourceManager(), m_astContext->getLangOpts());
    //   appendLineToFile("./Record-Info.txt","New-Typedef\t" + tdef_text + "\n");
    //   return true;
    // }
    // bool VisitTypeDecl(TypeDecl *tdef){
    //   string tdef_text = Lexer::getSourceText(CharSourceRange::getCharRange(tdef->getSourceRange()), m_astContext->getSourceManager(), m_astContext->getLangOpts());
    //   appendLineToFile("./Record-Info.txt","New-Typedef\t" + tdef_text + "\n");
    //   return true;
    // }
    bool VisitRecordDecl(clang::RecordDecl *rd) {
        // RecordDecl *r_decl = rd->getDefinition();
        appendLineToFile("./Record-Info.txt","New-Record\t" + rd->getNameAsString() + "\n");
        for (RecordDecl::field_iterator j_se = rd->field_begin(), e = rd->field_end(); j_se != e; ++j_se) {
            FieldDecl *decl = cast<FieldDecl>(*j_se);
            string decl_str = decl->getNameAsString() + "\t" + decl->getType().getAsString();
            appendLineToFile("./Record-Info.txt",decl_str+"\n");
        }
        return true;
    }
};

class GlobalExtractorASTConsumer : public ASTConsumer {
private:
    GlobalExtractorVisitor *m_visitor;
public:
    // override the constructor in order to pass CI
    explicit GlobalExtractorASTConsumer(CompilerInstance *CI, Rewriter *rewriter)
        : m_visitor(new GlobalExtractorVisitor(CI, rewriter)) // initialize the visitor
    { }

    // override this to call our GlobalExtractorVisitor on the entire source file
    virtual void HandleTranslationUnit(ASTContext &Context) {
        /* we can use ASTContext to get the TranslationUnitDecl, which is
             a single Decl that collectively represents the entire source file */
        m_visitor->TraverseDecl(Context.getTranslationUnitDecl());
    }

    virtual ~GlobalExtractorASTConsumer() { delete m_visitor; }
};

class GlobalExtractorFrontendAction : public ASTFrontendAction {
private:
    Rewriter *m_rewriter=new Rewriter();
public:
    virtual std::unique_ptr<clang::ASTConsumer> CreateASTConsumer(CompilerInstance &CI, StringRef file) final {
        return std::unique_ptr<clang::ASTConsumer>(new GlobalExtractorASTConsumer(&CI,m_rewriter)); // pass CI pointer to ASTConsumer
    }
    virtual ~GlobalExtractorFrontendAction() { delete m_rewriter; }
};

int main(int argc, const char **argv) {
    // parse the command-line args passed to your code
    CommonOptionsParser op(argc, argv, MyToolCategory);
    // create a new Clang Tool instance (a LibTooling environment)
    ClangTool Tool(op.getCompilations(), op.getSourcePathList());

    // run the Clang Tool, creating a new FrontendAction (explained below)
    int result = Tool.run(&(*newFrontendActionFactory<GlobalExtractorFrontendAction>()));

    return result;
}