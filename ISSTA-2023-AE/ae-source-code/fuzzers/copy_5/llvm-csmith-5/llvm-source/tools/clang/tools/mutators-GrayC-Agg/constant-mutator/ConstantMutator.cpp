#include "ConstantMutator.h"
#include "../random-manager/ClangFuzzerCustomRandom.h"
#include <iostream>
#include <sstream>
#include <fstream>
#include <iomanip>
#include <bitset>
#include <limits>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

using namespace std;

/// <summary>
/// Mutate constants
/// 
/// TODO: Add details and mapping to the mutations in the paper. 
/// 
/// Classes: ConstantMutatorVisitor, ConstantMutatorASTConsumer, ConstantMutatorFrontendAction
/// </summary>

// Shorten expression mutator
// Ternary operators
// TODO: add random constant

static llvm::cl::OptionCategory MyToolCategory("Constant Mutator option");

bool ConstantMutatorVisitor::VisitVarDecl(VarDecl* D) {
    if (auto t = dyn_cast_or_null<ConstantArrayType>(D->getType().getTypePtr())) {
        latest_array_line_no = ((m_astContext->getSourceManager()).getSpellingLineNumber(D->getBeginLoc()));
    }
    return true;
}

bool ConstantMutatorVisitor::VisitFloatingLiteral(FloatingLiteral* flit) {
    CharSourceRange const_range = CharSourceRange::getTokenRange(flit->getBeginLoc(), flit->getEndLoc());
    string const_str = string(Lexer::getSourceText(const_range, m_astContext->getSourceManager(), m_astContext->getLangOpts()));
    size_t point_loc = const_str.find(".");
    if (point_loc != std::string::npos) {
        string before_point = const_str.substr(0, point_loc);
        string after_point = const_str.substr(point_loc + 1, const_str.length());
        string mutated_float = to_string(mutate_constant_float()) + "." + to_string(mutate_constant_float());
        m_rewriter->ReplaceText(const_range, "(" + mutated_float + ")");
    }
    return true;
}

bool ConstantMutatorVisitor::VisitIntegerLiteral(IntegerLiteral* ilit) {
    CharSourceRange const_range = CharSourceRange::getTokenRange(ilit->getBeginLoc(), ilit->getEndLoc());
    std::string const_str = std::string(Lexer::getSourceText(const_range, m_astContext->getSourceManager(), m_astContext->getLangOpts()));
    if (const_str != "" && is_number(const_str)) {
        m_rewriter->ReplaceText(const_range, "(" + mutate_constant_integers(const_str) + ")");
    }
    return true;
}

std::string ConstantMutatorVisitor::mutate_constant_integers(std::string constant) {
    // Sign flip, bit flip, char flip or replace with hexa
    if (ClangFuzzerCustomRandom::GetInstance()->rnd_yes_no(0.5)) 
         return ((ClangFuzzerCustomRandom::GetInstance()->rnd_yes_no(0.5)) 
            ? sign_flip(constant) : bit_flip(constant));
    else return ((ClangFuzzerCustomRandom::GetInstance()->rnd_yes_no(0.5))
            ? replace1char(constant) : replace2hex(constant.length()));
}

cType ConstantMutatorVisitor::guessType(std::string const_str, bool is_sign_flip)
{
    // If zero can be any of the data types
    bool is_zero = (const_str.compare("0") == 0);
    if (is_zero) {
        return ((cType) (ClangFuzzerCustomRandom::GetInstance()->rnd_dice() % MAX_CONST_TYPE));
    }

    // Negative number
    bool is_neg = (const_str.find("-") != std::string::npos);
    if (is_neg || is_sign_flip) {
        char* endptr; errno = 0; // init before using strtol
        const char* nptr = const_str.c_str();
        long long number = strtoll(nptr, &endptr, 10);
        if ((number == 0) || (nptr == endptr) || (errno == EINVAL) || (errno == ERANGE)) {
            return cChar;
        }
    
        // Check which data it can be
        if ((std::numeric_limits<char>::min() <= number) &&
            (std::numeric_limits<char>::max() >= number))
            return cChar;

        if ((std::numeric_limits<short>::min() <= number) &&
            (std::numeric_limits<short>::max() >= number))
            return cShort;

        if ((std::numeric_limits<int>::min() <= number) &&
            (std::numeric_limits<int>::max() >= number))
            return cInt;

        if ((std::numeric_limits<long>::min() <= number) &&
            (std::numeric_limits<long>::max() >= number))
            return cLong;

        return cLongLong;
    } else {
        char* endptr; errno = 0; // init before using strtol
        const char* nptr = const_str.c_str();
        unsigned long long number = strtoull(nptr, &endptr, 10);
        if ((number == 0) || (nptr == endptr) || (errno == EINVAL) || (errno == ERANGE))
        {
            return cUChar;
        }

        // Check which data it can be
                // Check which data it can be
        if ((std::numeric_limits<unsigned char>::min() <= number) &&
            (std::numeric_limits<unsigned char>::max() >= number))
            return cUChar;

        if ((std::numeric_limits<unsigned short>::min() <= number) &&
            (std::numeric_limits<unsigned short>::max() >= number))
            return cUShort;

        if ((std::numeric_limits<unsigned int>::min() <= number) &&
            (std::numeric_limits<unsigned int>::max() >= number))
            return cUInt;

        if ((std::numeric_limits<unsigned long>::min() <= number) &&
            (std::numeric_limits<unsigned long>::max() >= number))
            return cULong;

        return cULongLong;
    }
}

bool ConstantMutatorVisitor::is_number(const std::string& s) {
    std::string::const_iterator it = s.begin();
    while (it != s.end() && (std::isdigit(*it) || (*it == '-') || (*it == '+'))) ++it;
    return (!s.empty() && it == s.end());
}

char ConstantMutatorVisitor::bit_flip_char(char constant) {
    std::bitset<std::numeric_limits<char>::digits> bits(constant);
    unsigned bit_flip_location = ClangFuzzerCustomRandom::GetInstance()->rnd_dice(bits.size());
    return static_cast<char>(bits.flip(bit_flip_location).to_ulong());
}

unsigned char ConstantMutatorVisitor::bit_flip_uchar(unsigned char constant) {
    std::bitset<std::numeric_limits<unsigned char>::digits> bits(constant);
    unsigned bit_flip_location = ClangFuzzerCustomRandom::GetInstance()->rnd_dice(bits.size());
    return static_cast<unsigned char>(bits.flip(bit_flip_location).to_ulong());
}

short ConstantMutatorVisitor::bit_flip_short(short constant) {
    std::bitset<std::numeric_limits<short>::digits> bits(constant);
    unsigned bit_flip_location = ClangFuzzerCustomRandom::GetInstance()->rnd_dice(bits.size());
    return static_cast<short>(bits.flip(bit_flip_location).to_ulong());
}

unsigned short ConstantMutatorVisitor::bit_flip_ushort(unsigned short constant) {
    std::bitset<std::numeric_limits<unsigned short>::digits> bits(constant);
    unsigned bit_flip_location = ClangFuzzerCustomRandom::GetInstance()->rnd_dice(bits.size());
    return static_cast<unsigned short>(bits.flip(bit_flip_location).to_ulong());
}

int ConstantMutatorVisitor::bit_flip_int(int constant) {
    std::bitset<std::numeric_limits<int>::digits> bits(constant);
    unsigned bit_flip_location = ClangFuzzerCustomRandom::GetInstance()->rnd_dice(bits.size());
    return static_cast<int>(bits.flip(bit_flip_location).to_ulong());
}

unsigned ConstantMutatorVisitor::bit_flip_uint(unsigned constant) {
    std::bitset<std::numeric_limits<unsigned>::digits> bits(constant);
    unsigned bit_flip_location = ClangFuzzerCustomRandom::GetInstance()->rnd_dice(bits.size());
    return static_cast<unsigned>(bits.flip(bit_flip_location).to_ulong());
}

long ConstantMutatorVisitor::bit_flip_long(long constant)
{
    std::bitset<std::numeric_limits<long>::digits> bits(constant);
    unsigned bit_flip_location = ClangFuzzerCustomRandom::GetInstance()->rnd_dice(bits.size());
    return static_cast<long>(bits.flip(bit_flip_location).to_ulong());
}

unsigned long ConstantMutatorVisitor::bit_flip_ulong(unsigned long constant) {
    std::bitset<std::numeric_limits<unsigned long>::digits> bits(constant);
    unsigned bit_flip_location = ClangFuzzerCustomRandom::GetInstance()->rnd_dice(bits.size());
    return (bits.flip(bit_flip_location).to_ulong());
}

long long ConstantMutatorVisitor::bit_flip_long_long(long long constant) {
    std::bitset<std::numeric_limits<long long>::digits> bits(constant);
    unsigned bit_flip_location = ClangFuzzerCustomRandom::GetInstance()->rnd_dice(bits.size());
    return static_cast<long long>(bits.flip(bit_flip_location).to_ulong());
}

unsigned long long ConstantMutatorVisitor::bit_flip_ulong_long(unsigned long long constant) {
    std::bitset<std::numeric_limits<unsigned long long>::digits> bits(constant);
    unsigned bit_flip_location = ClangFuzzerCustomRandom::GetInstance()->rnd_dice(bits.size());
    return static_cast<unsigned long long>(bits.flip(bit_flip_location).to_ulong());
}

std::string ConstantMutatorVisitor::sign_flip(std::string constant)
{
    // Sign flip
    char* endptr; errno = 0; // init before using strtol
    long long number = strtoll(constant.c_str(), &endptr, 10);
    switch (guessType(constant, 1)) {
    case cChar:
        return std::to_string(sign_flip_char(static_cast<char> (number)));
    case cShort:
        return std::to_string(sign_flip_short(static_cast<short> (number)));
    case cInt:
        return std::to_string(sign_flip_int(static_cast<int> (number)));
    case cLong:
        return std::to_string(sign_flip_long(static_cast<long> (number)));
    case cLongLong:
        return std::to_string(sign_flip_long_long(static_cast<long long> (number)));
    default:
        return constant;
    }
}

std::string ConstantMutatorVisitor::bit_flip(std::string constant)
{
    // Bit flip
    cType t = guessType(constant);
    long long number = 0; unsigned long long unumber = 0;
    switch (t) {
    case cChar:
    case cShort:
    case cInt:
    case cLong:
    case cLongLong:
        char* endptr_0; errno = 0; // init before using strtol
        number = strtoll(constant.c_str(), &endptr_0, 10);
        break;
    default:
        char* endptr_1; errno = 0; // init before using strtol
        unumber = strtoll(constant.c_str(), &endptr_1, 10);
    }
    switch (t) {
    case cChar:
        return std::to_string(bit_flip_char(static_cast<char> (number)));
    case cShort:
        return std::to_string(bit_flip_short(static_cast<short> (number)));
    case cInt:
        return std::to_string(bit_flip_int(static_cast<int> (number)));
    case cLong:
        return std::to_string(bit_flip_long(static_cast<long> (number)));
    case cLongLong:
        return std::to_string(bit_flip_long_long(static_cast<long long> (number)));
    case cUChar:
        return std::to_string(bit_flip_uchar(static_cast<unsigned char> (unumber)));
    case cUShort:
        return std::to_string(bit_flip_ushort(static_cast<unsigned short> (unumber)));
    case cUInt:
        return std::to_string(bit_flip_uint(static_cast<unsigned> (unumber)));
    case cULong:
        return std::to_string(bit_flip_ulong(static_cast<unsigned long> (unumber)));
    case cULongLong:
        return std::to_string(bit_flip_ulong_long(static_cast<unsigned long long> (unumber)));
    default:
        return constant;
    }
}

std::string ConstantMutatorVisitor::replace1char(std::string const_str)
{
    static std::string dec_characters = "0123456789";
    unsigned len = const_str.length();
    for (unsigned i = 0; i < len; i++) {
        if (std::isdigit(const_str[i]) && ClangFuzzerCustomRandom::GetInstance()->rnd_yes_no(0.1)) {
            const_str[i] = dec_characters[ClangFuzzerCustomRandom::GetInstance()->rnd_dice(10)];
            return const_str;
        }
    }
    return const_str;
}

std::string ConstantMutatorVisitor::replace2hex(unsigned length) {
    static std::string hex_characters = "0123456789ABCDEF";

    std::string rand_str = "0x";
    length += ClangFuzzerCustomRandom::GetInstance()->rnd_dice(5); /* Avoid creating always small numbers */
    for (unsigned i = 0; i < length; i++) 
        rand_str.append(hex_characters, ClangFuzzerCustomRandom::GetInstance()->rnd_dice(16), 1);
    return rand_str;
}

int ConstantMutatorVisitor::mutate_constant_float() {
    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<std::mt19937::result_type> dist6(1, 10);
    return ((dist6(rng)));
}

void ConstantMutatorFrontendAction::EndSourceFileAction() {
    SourceManager& src_mngr = m_rewriter->getSourceMgr();
    std::error_code error_code;
    std::string base_filename = string(src_mngr.getFileEntryForID(src_mngr.getMainFileID())->getName());
    std::string::size_type const p(base_filename.find_last_of('.'));
    std::string file_without_extension = base_filename.substr(0, p);
    llvm::raw_fd_ostream outFile(file_without_extension + ".mutated.c", error_code);
    m_rewriter->getEditBuffer(src_mngr.getMainFileID()).write(outFile);
    outFile.close();
}

int main(int argc, const char **argv) {
    // parse the command-line args passed to your code
    int argc_new = argc - 1;
    CommonOptionsParser op(argc_new, argv, MyToolCategory);

    // Create Random Generaton, uniform real dist
    unsigned long Seed = std::stoi(argv[argc - 1]); // Seed is always in the end
    ClangFuzzerCustomRandom::CreateInstance(Seed, 65000); // Dice of 65000
    //std::cout << "Seed in mutator: " << Seed << "\n";

    // create a new Clang Tool instance (a LibTooling environment)
    ClangTool Tool(op.getCompilations(), op.getSourcePathList());

    // run the Clang Tool, creating a new FrontendAction (explained below)
    int result = Tool.run(&(*newFrontendActionFactory<ConstantMutatorFrontendAction>()));

    // Free the random manager before exit
    ClangFuzzerCustomRandom::DeleteInstance(Seed);

	return result;
}
