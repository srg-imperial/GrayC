#ifndef __CUSTOM_CLANG_FUZZER_H
#define __CUSTOM_CLANG_FUZZER_H

#include <string>
#include <vector>

#define _O_FLAG_SIZE 5
#define _COMP_FLAG_SIZE 12

class FuzzerArgument {
public:
  static unsigned _counter;

  static std::string _original_corpus_dir;
  static std::string _mutator_path;
  static std::string _lib_paths;
  static std::string _comp_flags;

  static std::string _fuzzer_output_temp_dir;
  static std::string _fuzzer_output_directory;
  static std::string _fuzzer_output_directory_fuzzed_files;
  static std::vector<std::string> _mutator_options;
  static std::string _fuzzer_remove_parens;

  // Hybrid mutator constants
  static std::string _fuzzer_csmith_cmd;
  static std::string _fuzzer_csmith_temp_directory;
  static std::string _fuzzer_csmith_c_file;
  static std::string _fuzzer_csmith_decl_file;
  static std::string _fuzzer_csmith_expr_file;
  static std::string _csmith_exec_command;
};
#endif // END OF __CUSTOM_CLANG_FUZZER_H
