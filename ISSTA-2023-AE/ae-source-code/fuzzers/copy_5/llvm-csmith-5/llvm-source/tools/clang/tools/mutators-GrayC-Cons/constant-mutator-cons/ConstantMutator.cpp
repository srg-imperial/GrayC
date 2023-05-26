#include "ConstantMutator.h"
#include "../utils-fuzzer-cons/GrayCCustomRandom.h"
#include "../utils-fuzzer-cons/GrayCUtils.h"
#include <bitset>
#include <errno.h>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <limits>
#include <sstream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

/// <summary>
/// Mutate constants: integer, floats and array size and subscripts
///
/// Classes: ConstantMutatorVisitor, ConstantMutatorASTConsumer,
/// ConstantMutatorFrontendAction
/// </summary>

static llvm::cl::OptionCategory MyToolCategory("Constant Mutator Option");

bool ConstantMutatorVisitor::VisitVarDecl(VarDecl *D) {
  if (!D)
    return true;
  // Else continue
  if (auto t = dyn_cast_or_null<ConstantArrayType>(D->getType().getTypePtr())) {
    m_latest_array_line_no = ((m_astContext->getSourceManager())
                                  .getSpellingLineNumber(D->getBeginLoc()));
    m_array_size = (t->getSize()).roundToDouble();
  }
  return true;
}

bool ConstantMutatorVisitor::VisitFloatingLiteral(FloatingLiteral *flit) {
  if (!flit)
    return true; // no data to work on
  if (!m_rewriter->isRewritable(flit->getBeginLoc()) || !m_rewriter->isRewritable(flit->getEndLoc()))
      return true; // Do not attempt to edit if is not rewritable
  
  CharSourceRange const_range =
      CharSourceRange::getTokenRange(flit->getBeginLoc(), flit->getEndLoc());
  if (const_range.isInvalid())
    return true; // if no const, exit
  
  auto str_ref = Lexer::getSourceText(const_range, 
      m_astContext->getSourceManager(),
      m_astContext->getLangOpts());
  if (str_ref.empty())
    return true; // if no const, exit
  
  std::string const_str = std::string(str_ref);
  if (const_str.empty())
    return true; // if no const, exit
  
  // Else continue with the mutation
  size_t point_loc = const_str.find(".");
  if (point_loc != std::string::npos 
      && (point_loc + 1) <= const_str.length()) {
    std::string mutated_float = to_string(mutate_constant_float()) + "." +
                           to_string(mutate_constant_float());
    m_rewriter->ReplaceText(const_range, "(" + mutated_float + ")");
  }
  return true;
}

bool ConstantMutatorVisitor::VisitIntegerLiteral(IntegerLiteral *ilit) {
  if (!ilit)
    return true;
  // Else continue
  CharSourceRange const_range =
      CharSourceRange::getTokenRange(ilit->getBeginLoc(), ilit->getEndLoc());
  if (const_range.isInvalid())
    return true; // if no const, exit
  
  auto str_ref = Lexer::getSourceText(const_range, 
      m_astContext->getSourceManager(),
      m_astContext->getLangOpts());
  if (str_ref.empty())
    return true; // if no const, exit
  
  std::string const_str = std::string(str_ref);
  if (const_str.empty())
    return true; // if no const, exit
    
  // Number + not empty
  if (const_str != "" && is_number(const_str)) {
    int array_line_no = ((m_astContext->getSourceManager())
                             .getSpellingLineNumber(ilit->getBeginLoc()));
    const Expr *expr_un = cast<Expr>(ilit);
    if (!expr_un)
      return true;
    
    // Control the aggressiveness
    bool allow_bad_access = GrayCCustomRandom::GetInstance()->rnd_yes_no(__CONSTANT_MUTATOR_ALLOW_NEG_NUM_MEMORY_ACCESS_CONST);
    bool allow_bad_size = GrayCCustomRandom::GetInstance()->rnd_yes_no(__CONSTANT_MUTATOR_ALLOW_BIG_NUM_MEMORY_CONST);
    bool is_array_decl = (!isInArraySubsrcipt(*expr_un) && ((array_line_no != m_latest_array_line_no) || (array_line_no < 0)));
    
    // Check to reduce big array and access out of bounds
    if (!is_array_decl || (allow_bad_access && allow_bad_size)) { // or not an decl, or we allow both big and neg
      int line_no = (m_astContext->getSourceManager())
                  .getSpellingLineNumber(ilit->getBeginLoc());
      int line_no_next = line_no + 1;
      if (line_no < 0)
        return true; // if line number invalid, exit 
  
      // Extracting the line to be edited as a string
      SourceLocation thisline =
          (m_astContext->getSourceManager())
              .translateLineCol((m_astContext->getSourceManager()).getMainFileID(),
                                line_no, 1); // get the beginning of line line_no
      if (thisline.isInvalid())
        return true;
  
      SourceLocation nextline =
          (m_astContext->getSourceManager())
              .translateLineCol((m_astContext->getSourceManager()).getMainFileID(),
                                line_no_next,
                                1); // get the beginning of line line_no+1
      if (nextline.isInvalid())
        return true;
  
      SourceRange srange(thisline, nextline);
      if (srange.isInvalid())
        return true;
      
      string string_to_rewrite = string(Lexer::getSourceText(CharSourceRange::getTokenRange(srange), m_astContext->getSourceManager(), m_astContext->getLangOpts(), 0));
      // llvm::outs()<<string_to_rewrite<<"\n"; // log the extracted current line

      // If we are not in array, then check the line is ok to edit
      bool allow_bad = (is_array_decl && allow_bad_access && allow_bad_size) || (!is_array_decl && allow_bad_access);
      if (!string_to_rewrite.empty() && (allow_bad || !GrayCUtils::is_bad_line(string_to_rewrite))) {
        // Mutate the line
        m_rewriter->ReplaceText(
            const_range, "(" + mutate_constant_integers(const_str) + ")");
      }
    } else {
      // In an array!
      std::string to_append =
          "(" +
          mutate_constant_integers(
              const_str, ((array_line_no == m_latest_array_line_no) ? 1 : 0),
              allow_bad_size ? UINT_MAX	: SHRT_MAX) +
          ")";
      m_rewriter->ReplaceText(const_range, to_append);
    }
  }
  return true;
}

std::string
ConstantMutatorVisitor::mutate_constant_integers(std::string constant,
                                                 int b_lower, int b_upper) {
  if (constant.empty())
    return "-0";
  
  bool is_array_sub_script = (b_lower < b_upper);
  // Sign flip, bit flip, char flip or replace with hexa
  if (is_array_sub_script)
    // TODO: Improve this part. For now just assure value is not too large for
    // arrays
    return std::to_string(
        GrayCCustomRandom::GetInstance()->rnd_dice(b_upper - b_lower) +
        b_lower);
  
  if (GrayCCustomRandom::GetInstance()->rnd_yes_no(__CONSTANT_MUTATOR_INTEGER_EDITS_CONST))
    return ((GrayCCustomRandom::GetInstance()->rnd_yes_no(__CONSTANT_MUTATOR_INTEGER_EDITS_CONST))
                ? bit_flip(constant)
                : sign_flip(constant));
  else
    return ((GrayCCustomRandom::GetInstance()->rnd_yes_no(__CONSTANT_MUTATOR_INTEGER_EDITS_CONST))
                ? replace2hex(constant.length())
                : replace1char(constant));
}

cType ConstantMutatorVisitor::guessType(std::string const_str,
                                        bool is_sign_flip) {
  if (const_str.empty())
    return cUChar;
  
  // If zero can be any of the data types
  if (const_str.compare("0") == 0) {
    return (
        (cType)(GrayCCustomRandom::GetInstance()->rnd_dice() % MAX_CONST_TYPE));
  }

  // Negative number
  bool is_neg = (const_str.find("-") != std::string::npos);
  if (is_neg || is_sign_flip) {
    char *endptr;
    errno = 0; // init before using strtol
    const char *nptr = const_str.c_str();
    long long number = strtoll(nptr, &endptr, 10);
    if ((number == 0) || (nptr == endptr) || (errno == EINVAL) ||
        (errno == ERANGE)) {
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
    char *endptr;
    errno = 0; // init before using strtol
    const char *nptr = const_str.c_str();
    unsigned long long number = strtoull(nptr, &endptr, 10);
    if ((number == 0) || (nptr == endptr) || (errno == EINVAL) ||
        (errno == ERANGE)) {
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

bool ConstantMutatorVisitor::is_number(const std::string &s) {
  if (s.empty())
    return false;
  // Else continue
  std::string::const_iterator it = s.begin();
  while (it != s.end() && (std::isdigit(*it) || (*it == '-') || (*it == '+')))
    ++it;
  return (!s.empty() && it == s.end());
}

char ConstantMutatorVisitor::bit_flip_char(char constant) {
  std::bitset<std::numeric_limits<char>::digits> bits(constant);
  unsigned bit_flip_location =
      GrayCCustomRandom::GetInstance()->rnd_dice(bits.size());
  return static_cast<char>(bits.flip(bit_flip_location).to_ulong());
}

unsigned char ConstantMutatorVisitor::bit_flip_uchar(unsigned char constant) {
  std::bitset<std::numeric_limits<unsigned char>::digits> bits(constant);
  unsigned bit_flip_location =
      GrayCCustomRandom::GetInstance()->rnd_dice(bits.size());
  return static_cast<unsigned char>(bits.flip(bit_flip_location).to_ulong());
}

short ConstantMutatorVisitor::bit_flip_short(short constant) {
  std::bitset<std::numeric_limits<short>::digits> bits(constant);
  unsigned bit_flip_location =
      GrayCCustomRandom::GetInstance()->rnd_dice(bits.size());
  return static_cast<short>(bits.flip(bit_flip_location).to_ulong());
}

unsigned short
ConstantMutatorVisitor::bit_flip_ushort(unsigned short constant) {
  std::bitset<std::numeric_limits<unsigned short>::digits> bits(constant);
  unsigned bit_flip_location =
      GrayCCustomRandom::GetInstance()->rnd_dice(bits.size());
  return static_cast<unsigned short>(bits.flip(bit_flip_location).to_ulong());
}

int ConstantMutatorVisitor::bit_flip_int(int constant) {
  std::bitset<std::numeric_limits<int>::digits> bits(constant);
  unsigned bit_flip_location =
      GrayCCustomRandom::GetInstance()->rnd_dice(bits.size());
  return static_cast<int>(bits.flip(bit_flip_location).to_ulong());
}

unsigned ConstantMutatorVisitor::bit_flip_uint(unsigned constant) {
  std::bitset<std::numeric_limits<unsigned>::digits> bits(constant);
  unsigned bit_flip_location =
      GrayCCustomRandom::GetInstance()->rnd_dice(bits.size());
  return static_cast<unsigned>(bits.flip(bit_flip_location).to_ulong());
}

long ConstantMutatorVisitor::bit_flip_long(long constant) {
  std::bitset<std::numeric_limits<long>::digits> bits(constant);
  unsigned bit_flip_location =
      GrayCCustomRandom::GetInstance()->rnd_dice(bits.size());
  return static_cast<long>(bits.flip(bit_flip_location).to_ulong());
}

unsigned long ConstantMutatorVisitor::bit_flip_ulong(unsigned long constant) {
  std::bitset<std::numeric_limits<unsigned long>::digits> bits(constant);
  unsigned bit_flip_location =
      GrayCCustomRandom::GetInstance()->rnd_dice(bits.size());
  return (bits.flip(bit_flip_location).to_ulong());
}

long long ConstantMutatorVisitor::bit_flip_long_long(long long constant) {
  std::bitset<std::numeric_limits<long long>::digits> bits(constant);
  unsigned bit_flip_location =
      GrayCCustomRandom::GetInstance()->rnd_dice(bits.size());
  return static_cast<long long>(bits.flip(bit_flip_location).to_ulong());
}

unsigned long long
ConstantMutatorVisitor::bit_flip_ulong_long(unsigned long long constant) {
  std::bitset<std::numeric_limits<unsigned long long>::digits> bits(constant);
  unsigned bit_flip_location =
      GrayCCustomRandom::GetInstance()->rnd_dice(bits.size());
  return static_cast<unsigned long long>(
      bits.flip(bit_flip_location).to_ulong());
}

std::string ConstantMutatorVisitor::sign_flip(std::string constant) {
  if (constant.empty())
    return "-0";
    
  // Sign flip
  char *endptr;
  errno = 0; // init before using strtol
  long long number = strtoll(constant.c_str(), &endptr, 10);
  switch (guessType(constant, 1)) {
  case cChar:
    return std::to_string(sign_flip_char(static_cast<char>(number)));
  case cShort:
    return std::to_string(sign_flip_short(static_cast<short>(number)));
  case cInt:
    return std::to_string(sign_flip_int(static_cast<int>(number)));
  case cLong:
    return std::to_string(sign_flip_long(static_cast<long>(number)));
  case cLongLong:
    return std::to_string(sign_flip_long_long(static_cast<long long>(number)));
  default:
    return constant;
  }
}

std::string ConstantMutatorVisitor::bit_flip(std::string constant) {
  if (constant.empty())
    return "-0";
    
  // Bit flip
  cType t = guessType(constant);
  long long number = 0;
  unsigned long long unumber = 0;
  switch (t) {
  case cChar:
  case cShort:
  case cInt:
  case cLong:
  case cLongLong:
    char *endptr_0;
    errno = 0; // init before using strtol
    number = strtoll(constant.c_str(), &endptr_0, 10);
    break;
  default:
    char *endptr_1;
    errno = 0; // init before using strtol
    unumber = strtoll(constant.c_str(), &endptr_1, 10);
  }
  switch (t) {
  case cChar:
    return std::to_string(bit_flip_char(static_cast<char>(number)));
  case cShort:
    return std::to_string(bit_flip_short(static_cast<short>(number)));
  case cInt:
    return std::to_string(bit_flip_int(static_cast<int>(number)));
  case cLong:
    return std::to_string(bit_flip_long(static_cast<long>(number)));
  case cLongLong:
    return std::to_string(bit_flip_long_long(static_cast<long long>(number)));
  case cUChar:
    return std::to_string(bit_flip_uchar(static_cast<unsigned char>(unumber)));
  case cUShort:
    return std::to_string(
        bit_flip_ushort(static_cast<unsigned short>(unumber)));
  case cUInt:
    return std::to_string(bit_flip_uint(static_cast<unsigned>(unumber)));
  case cULong:
    return std::to_string(bit_flip_ulong(static_cast<unsigned long>(unumber)));
  case cULongLong:
    return std::to_string(
        bit_flip_ulong_long(static_cast<unsigned long long>(unumber)));
  }

  // default - return constant
  return constant;
}

std::string ConstantMutatorVisitor::replace1char(std::string const_str) {
  if (const_str.empty())
    return "-0";
    
  static std::string dec_characters = "0123456789";
  unsigned len = const_str.length();
  for (unsigned i = 1; i < len;
       i++) { // Starts from 1 and not 0, to avoid too large numbers
    if (std::isdigit(const_str[i]) &&
        GrayCCustomRandom::GetInstance()->rnd_yes_no(__CONSTANT_MUTATOR_FLIP_CHARS_CONST)) {
      const_str[i] =
          dec_characters[GrayCCustomRandom::GetInstance()->rnd_dice(dec_characters.size())];
      return const_str;
    }
  }
  return const_str;
}

std::string ConstantMutatorVisitor::replace2hex(unsigned length) {
  if (length < 1)
    return "0";
    
  // Else replace with hexa
  static std::string hex_characters = "0123456789ABCDEF";

  // Avoid creating always small numbers vs. too big - can be at most 15 digits
  std::string rand_str = "0x";
  unsigned new_length =
      (length + GrayCCustomRandom::GetInstance()->rnd_dice(5)) % hex_characters.size();
  for (unsigned i = 0; i < new_length; i++)
    rand_str.append(hex_characters,
                    GrayCCustomRandom::GetInstance()->rnd_dice(hex_characters.size()), 1);
  return rand_str;
}

int ConstantMutatorVisitor::mutate_constant_float() {
  return GrayCCustomRandom::GetInstance()->rnd_dice(10) + 1; // 1 ... 10 random
}

void ConstantMutatorFrontendAction::EndSourceFileAction() {
  SourceManager &src_mngr = m_rewriter->getSourceMgr();
  std::error_code error_code;
  std::string base_filename =
      std::string(src_mngr.getFileEntryForID(src_mngr.getMainFileID())->getName());
  std::string::size_type const p(base_filename.find_last_of('.'));
  std::string file_without_extension = base_filename.substr(0, p);
  llvm::raw_fd_ostream outFile(file_without_extension + ".mutated.c",
                               error_code);
  m_rewriter->getEditBuffer(src_mngr.getMainFileID()).write(outFile);
  outFile.close();
}

int main(int argc, const char **argv) {
  // parse the command-line args passed to your code
  int argc_new = argc - 1;
  CommonOptionsParser op(argc_new, argv, MyToolCategory);

  // Create Random Generaton, uniform real dist
  unsigned long Seed = std::stoi(argv[argc - 1]); // Seed is always in the end
  GrayCCustomRandom::CreateInstance(Seed, 65000); // Dice of 65000
  // std::cout << "Seed in mutator: " << Seed << "\n";

  // create a new Clang Tool instance (a LibTooling environment)
  ClangTool Tool(op.getCompilations(), op.getSourcePathList());

  // run the Clang Tool, creating a new FrontendAction (explained below)
  int result =
      Tool.run(&(*newFrontendActionFactory<ConstantMutatorFrontendAction>()));

  // Free the random manager before exit
  GrayCCustomRandom::DeleteInstance(Seed);

  return result;
}
