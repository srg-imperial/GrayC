#ifndef __CUSTOM_CLANG_FUZZER_H
#define __CUSTOM_CLANG_FUZZER_H

#include <string>
#include <vector>

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
};
#endif // END OF __CUSTOM_CLANG_FUZZER_H
