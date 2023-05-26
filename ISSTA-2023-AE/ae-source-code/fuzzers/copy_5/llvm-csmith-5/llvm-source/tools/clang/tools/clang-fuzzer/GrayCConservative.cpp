//===-- ClangFuzzer.cpp - Fuzz Clang --------------------------------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//
///
/// \file
/// This file implements a function that runs Clang on a single
///  input. This function is then linked into the Fuzzer library.
///
//===----------------------------------------------------------------------===//

#include "../mutators-GrayC-Cons/utils-fuzzer-cons/GrayCCustomRandom.h"
#include "../mutators-GrayC-Cons/utils-fuzzer-cons/GrayCUtils.h"
#include "CustomClangFuzzerCons.h"
#include "handle-cxx/handle_cxx.h"
#include <array>
#include <assert.h>
#include <cstdio>
#include <dirent.h>
#include <fstream>
#include <iostream>
#include <memory>
#include <sstream>
#include <stdexcept>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

using namespace clang_fuzzer;

// Debug mode - add more prints
// #define DEBUG_FUZZER 1 // uncomment if needed

unsigned FuzzerArgument::_counter = 0;

std::string FuzzerArgument::_fuzzer_output_temp_dir =
    "/home/user42/fuzzers/copy_5/llvm-csmith-5/llvm-fuzzer-build/fuzzer_ram-tmp/";
std::string FuzzerArgument::_fuzzer_output_directory =
    "/home/user42/fuzzers/copy_5/llvm-csmith-5/llvm-fuzzer-build/fuzzer-output-directory/";
std::string FuzzerArgument::_fuzzer_output_directory_fuzzed_files =
    "/home/user42/fuzzers/copy_5/llvm-csmith-5/llvm-fuzzer-build/"
    "fuzzer-output-directory-fuzzed-files/";
std::vector<std::string> FuzzerArgument::_mutator_options = {
    "bin/append-expression-cons",  "bin/jump-mutator-cons",      "bin/function-merger-cons",
    "bin/duplicate-mutator-cons",  "bin/constant-mutator-cons",  "bin/delete-mutator-cons",
    "bin/assignment-mutator-cons", "bin/expression-mutator-cons"};
std::string FuzzerArgument::_fuzzer_remove_parens =
    "(ulimit -Sf 2000 ; ulimit -St 30 ; /home/user42/fuzzers/copy_5/../remove-parens/build/remove-parens";

std::string FuzzerArgument::_fuzzer_csmith_cmd =
    "/home/user42/fuzzers/copy_5/llvm-csmith-5/csmith/build/src/csmith";
std::string FuzzerArgument::_fuzzer_csmith_temp_directory =
    "/home/user42/fuzzers/copy_5/llvm-csmith-5/llvm-fuzzer-build/fuzzer_csmith-tmp/";
std::string FuzzerArgument::_fuzzer_csmith_c_file =
    FuzzerArgument::_fuzzer_csmith_temp_directory + "csmith_output.c";
std::string FuzzerArgument::_fuzzer_csmith_decl_file =
    FuzzerArgument::_fuzzer_csmith_temp_directory + "csmith_decls.txt";
std::string FuzzerArgument::_fuzzer_csmith_expr_file =
    FuzzerArgument::_fuzzer_csmith_temp_directory + "csmith_expr.txt";
std::string FuzzerArgument::_csmith_exec_command =
    "(ulimit -Sf 2000 ; ulimit -St 30 ; " + FuzzerArgument::_fuzzer_csmith_cmd +
    " --max-struct-fields 2 --max-block-depth 2 --no-global-variables "
    "--no-structs --no-unions --no-pointers --max-expr-complexity 4 "
    "--concise --no-bitfields --no-checksum --no-jumps --no-volatile-pointers " 
    "--no-const-pointers --no-builtins --no-global-variables --compact-output "
    "--no-arrays --max-funcs 1 --seed ";
std::string FuzzerArgument::_original_corpus_dir = "";
std::string FuzzerArgument::_mutator_path = "";
std::string FuzzerArgument::_lib_paths = "";
std::string FuzzerArgument::_comp_flags =
    "-O2"; // Default just in case this parameter is missing

std::string exec_get_output(const char *cmd) {
  std::string result("");
  if (!cmd)
    return result; // Exit if null

  std::array<char, 128> buffer;
  std::unique_ptr<FILE, decltype(&pclose)> pipe(popen(cmd, "r"), pclose);
  while (fgets(buffer.data(), buffer.size(), pipe.get()) != nullptr) {
    result += buffer.data();
  }
  std::string::size_type i = 0;
  while (i < result.length()) {
    i = result.find('\n', i);
    if (i == std::string::npos) {
      break;
    }
    result.erase(i);
  }
  return result;
}

void read_directory(const std::string &name, std::vector<std::string> &v) {
  DIR *dirp = opendir(name.c_str());
  assert(dirp && std::string("Cannot read library in " + name));

  struct dirent *dp;
  while ((dp = readdir(dirp)) != NULL) {
    if (!dp)
      break; // Do not access dp if null and just break the loop
    v.push_back(dp->d_name);
  }
  closedir(dirp);
}

bool recreateFolder(std::string folder_path) {
  if (folder_path.empty())
    return false;

  // Else delete and mkdir again
  std::system(std::string("rm -rf " + folder_path).c_str());
  std::system(std::string("mkdir " + folder_path).c_str());
  return true;
}

extern "C" int LLVMFuzzerInitialize(int *argc, char ***argv) {
  FuzzerArgument::_original_corpus_dir = argv[0][1];
  std::string m_path = "";
  std::string l_path = "";
  std::string c_flags = "-O2";
  std::ifstream settings_file("/home/user42/fuzzers/copy_5/settings.txt");
  if (settings_file.is_open()) {
    std::string line;
    while (std::getline(settings_file, line)) {
      std::string value = line.substr(line.find(":") + 1);
      std::string key = line.substr(0, line.find(":"));
      if (key == "mutator_path") {
        m_path = value;
      } else if (key == "lib_paths") {
        std::istringstream instream(value);
        std::string val = "";
        while (std::getline(instream, val, '\t')) {
          l_path = l_path + "-\I" + val + " ";
        }
      } else if (key == "compilation_flags") {
        c_flags = value;
      }
    }
    settings_file.close();
  }
  FuzzerArgument::_mutator_path = m_path;
  FuzzerArgument::_lib_paths = l_path;
  FuzzerArgument::_comp_flags = c_flags;
#ifdef DEBUG_FUZZER
  std::cerr << FuzzerArgument::_mutator_path;
#endif
  std::cerr << FuzzerArgument::_lib_paths;

  std::string hook_file_path =
      FuzzerArgument::_mutator_path + "Mutation-Hooks-Functions.txt";
  std::string hook_file_path_global =
      FuzzerArgument::_mutator_path + "Global-Info.txt";
  std::string hook_file_path_statement =
      FuzzerArgument::_mutator_path + "Statement-Info.txt";
#ifdef DEBUG_FUZZER
  bool remove_failed =
#endif
      (remove(hook_file_path.c_str()) != 0 ||
       remove(hook_file_path_global.c_str()) != 0 ||
       remove(hook_file_path_statement.c_str()) != 0);
#ifdef DEBUG_FUZZER
  if (remove_failed)
    std::cerr << "Buggy remove (Location 1)"
              << "\n";
#endif

  // Remove and make folders before start fuzzing
  if (!recreateFolder(FuzzerArgument::_fuzzer_output_directory))
    std::cerr
        << "Empty folder name in FuzzerArgument::_fuzzer_output_directory\n";
  if (!recreateFolder(FuzzerArgument::_fuzzer_output_directory_fuzzed_files))
    std::cerr << "Empty folder name in "
                 "FuzzerArgument::_fuzzer_output_directory_fuzzed_files\n";
  if (!recreateFolder(FuzzerArgument::_fuzzer_output_temp_dir))
    std::cerr
        << "Empty folder name in FuzzerArgument::_fuzzer_output_temp_dir\n";
  if (!recreateFolder(FuzzerArgument::_fuzzer_csmith_temp_directory))
    std::cerr << "Empty folder name in "
                 "FuzzerArgument::_fuzzer_csmith_temp_directory\n";
  return 0;
}

extern "C" int LLVMFuzzerTestOneInput(uint8_t *data, size_t size) {
#ifdef DEBUG_FUZZER
  std::cerr << ">> Testing LLVMFuzzerTestOneInput with options: "
            << FuzzerArgument::_comp_flags << std::endl;
#endif
  std::string s((const char *)data, size);
  HandleCXX(s, "./test.cc", {FuzzerArgument::_comp_flags.c_str()});
  return 0;
}

bool hasEnding(std::string const &fullString, std::string const &ending) {
  return (fullString.length() >= ending.length())
             ? (0 == fullString.compare(fullString.length() - ending.length(),
                                        ending.length(), ending))
             : false;
}

void create_file(std::string filename, uint8_t *Data, size_t Size) {
  if (!Data)
    return; // Do not access data if null

  std::system(std::string("touch " + FuzzerArgument::_fuzzer_output_directory +
                          "/" + filename)
                  .c_str());
  std::ofstream tmpfile(FuzzerArgument::_fuzzer_output_directory + "/" +
                        filename);
  for (size_t i = 0; i < Size; i++)
    tmpfile << (char)Data[i];
  tmpfile.flush();
  tmpfile.close();
}

std::string randomize_comp_op(unsigned int Seed) {
  // Choose optimisation flag
  static std::string _opt_flags[_O_FLAG_SIZE] = {"-O1", "-O2", "-O3", "-Os",
                                                 "-Oz"};
  GrayCCustomRandom::CreateInstance(Seed, _O_FLAG_SIZE);
  std::string ret_op =
      _opt_flags[GrayCCustomRandom::GetInstance()->rnd_dice() % _O_FLAG_SIZE];
  GrayCCustomRandom::DeleteInstance(Seed);

  // Select a random amount of flags and flags
  static std::string _options_flags[_COMP_FLAG_SIZE] = {
      "-fno-unroll-loops",
      "-freroll-loops",
      "-funroll-loops",
      "-fwrapv",
      "-lgcc_s",
      "-fno-omit-frame-pointer",
      "-Wjump-misses-init",
      "-pedantic -Wall -Wextra",
      "-ffast-math",
      "-finline-functions",
      "-fno-strict-return",
      "-fvectorize"};
  GrayCCustomRandom::CreateInstance(Seed, _COMP_FLAG_SIZE);
  int max_i = GrayCCustomRandom::GetInstance()->rnd_dice();
  bool is_unroll_selected = false;
  bool is_no_unroll_selected = false;
  for (int i = 0; i < max_i; i++) {
    if (GrayCCustomRandom::GetInstance()->rnd_yes_no(0.5)) {
      unsigned int i_op =
          GrayCCustomRandom::GetInstance()->rnd_dice() % _COMP_FLAG_SIZE;
      if ((i_op == 0 && !is_unroll_selected) ||
          ((i_op == 1 || i_op == 2) && !is_no_unroll_selected) || (i_op > 2))
        ret_op = ret_op + " " + _options_flags[i_op] + " ";
      // Else, we skip the option to avoid crashing LLVMFuzzerTestOneInput.
      // If LLVMFuzzerTestOneInput crashed, check the options to avoid
      // combinations it does not like.

      if (i_op == 1 || i_op == 2)
        is_unroll_selected = true;
      if (i_op == 0)
        is_no_unroll_selected = true;
    }
  }
  GrayCCustomRandom::DeleteInstance(Seed);

  // Add general warnings that we do not want to get + return string
  // ret_op = ret_op + " " + "-Werror=shift-count-negative -Werror=unsequenced
  // -ferror-limit=5"; ==> crash because of -cc1 flag
  return ret_op;
}

void create_fuzzed_file(std::string filename, std::string original_filename) {
  std::system(
      std::string("touch " +
                  FuzzerArgument::_fuzzer_output_directory_fuzzed_files + "/" +
                  filename)
          .c_str());
  std::system(
      std::string("mv " + original_filename + " " +
                  FuzzerArgument::_fuzzer_output_directory_fuzzed_files + "/" +
                  filename)
          .c_str());
}

bool is_empty(std::ifstream &pFile) {
  return pFile.peek() == std::ifstream::traits_type::eof();
}

bool does_compile(std::string fname, std::string lib_paths) {
  return ((std::system(
              std::string("clang --no-warnings " + lib_paths + " " + (fname))
                  .c_str())) == 0);
}

std::string get_date(void) {
  char ft[256];
  struct tm *tmp;
  time_t curtime;

  time(&curtime);
  tmp = localtime(&curtime);

  strftime(ft, 256, "%F-%T", tmp);

  return std::string(ft);
}

extern "C" size_t LLVMFuzzerCustomMutator(uint8_t *Data, size_t Size,
                                          size_t MaxSize, unsigned int Seed) {
  // Rand a new set of flags each time we rand a new seed
  FuzzerArgument::_comp_flags = randomize_comp_op(Seed);
  // Randomise mutators
  GrayCCustomRandom::CreateInstance(Seed,
                                    FuzzerArgument::_mutator_options.size());
  std::string mutation_chosen =
      FuzzerArgument::_mutator_options[GrayCCustomRandom::GetInstance()
                                           ->rnd_dice()];
  GrayCCustomRandom::DeleteInstance(Seed);

  // Print the seed we are using and compilation options
#ifdef DEBUG_FUZZER
  std::cerr << ">> Using SEED: " << Seed << " and counter "
            << FuzzerArgument::_counter << " with options: (" << mutation_chosen
            << ") " << FuzzerArgument::_comp_flags << " <" << get_date() << ">"
            << std::endl;
#endif

  // Outout to RAM folder
  std::string temp_file_name = exec_get_output(
      std::string("mktemp " + FuzzerArgument::_fuzzer_output_temp_dir +
                  "/mutator-XXXXXX.c")
          .c_str());
  std::ofstream tmpfile(temp_file_name);
  for (size_t i = 0; i < Size; i++) {
    tmpfile << (char)Data[i];
  }
  tmpfile.flush();
  tmpfile.close();

  // Mark if we use Csmith with the current mutations
  bool need_csmith = (mutation_chosen == "bin/append-expression");
  // Add Csmith Header when needed
  if (need_csmith && (temp_file_name.size() > 0)) {
    std::string append_header_command =
        "if [ `grep 'csmith' " + temp_file_name +
        " | wc -l` -eq 0 ] ; then (sed -i '1s:^:#include \"csmith.h\":' " +
        temp_file_name + ") ; fi";
    system(append_header_command.c_str());
  }

  bool sanity_checks = true;
  if (!hasEnding(temp_file_name, ".c")) {
    sanity_checks = false;
  } else {
    std::ifstream file(temp_file_name);
    if (file.peek() == EOF) {
      sanity_checks = false;
    }
    file.close();
  }

  const std::string copy_filename =
      "fuzzer-file-" + std::to_string(FuzzerArgument::_counter);
  std::string original_corpus_dir = FuzzerArgument::_original_corpus_dir;
  std::string mutator_path = FuzzerArgument::_mutator_path;
  std::string lib_paths = FuzzerArgument::_lib_paths;
  bool is_mutation_multi_file = (mutation_chosen == "bin/function-merger");
  if (is_mutation_multi_file && sanity_checks) {
    std::vector<std::string> files;
    std::string hook_file_path =
        FuzzerArgument::_mutator_path + "Mutation-Hooks-Functions.txt";
    std::string hook_file_path_global =
        FuzzerArgument::_mutator_path + "Global-Info.txt";
    std::string hook_file_path_statement =
        FuzzerArgument::_mutator_path + "Statement-Info.txt";
    std::string hook_file_path_statement_san =
        FuzzerArgument::_mutator_path + "Statement-Info-San.txt";
#ifdef DEBUG_FUZZER
    bool remove_failed =
#endif
        (remove(hook_file_path.c_str()) != 0 ||
         remove(hook_file_path_global.c_str()) != 0 ||
         remove(hook_file_path_statement.c_str()) != 0 ||
         remove(hook_file_path_statement_san.c_str()) != 0);
#ifdef DEBUG_FUZZER
    if (remove_failed)
      std::cerr << "Buggy remove (Location 2)"
                << "\n";
#endif

    // Read random file from SetB
    static std::string second_corpus_path = "/home/user42/fuzzers/copy_5/setB";
    read_directory(second_corpus_path, files);
    GrayCCustomRandom::CreateInstance(Seed, files.size());
    std::string mutation_src_file_name =
        files[GrayCCustomRandom::GetInstance()->rnd_dice()];
    while (!hasEnding(mutation_src_file_name, ".c")) {
      read_directory(second_corpus_path, files);
      mutation_src_file_name =
          files[GrayCCustomRandom::GetInstance()->rnd_dice()];
    }
    GrayCCustomRandom::DeleteInstance(Seed);

    // Try to combine
    int result_hook_extractor = -99;
    int result_rename_transform = -99;
    int result_function_mutator = -99;
    if (Size) {
      std::string Seed_str = std::to_string(Seed);
      std::string mutation_src_file_rawname =
          mutation_src_file_name.substr(
              0, mutation_src_file_name.find_last_of(".")) +
          "_rename_output.c";

      // Command libtooling rename transformer
      result_rename_transform = std::system(
          std::string(mutator_path + "bin/rename-transform " +
                      second_corpus_path + "/" + mutation_src_file_name +
                      " -- --no-warnings " + lib_paths + " " + Seed_str + " ")
              .c_str());
      std::ifstream f(
          std::string(second_corpus_path + "/" + mutation_src_file_rawname)
              .c_str());
      if (f.good()) {
        result_hook_extractor = std::system(
            std::string(mutator_path + "bin/function-extractor " +
                        second_corpus_path + "/" + mutation_src_file_rawname +
                        " -- --no-warnings " + lib_paths + " " + Seed_str + " ")
                .c_str());
        result_function_mutator = std::system(
            std::string(mutator_path + "bin/function-merger " + temp_file_name +
                        " -- --no-warnings " + lib_paths + " " + Seed_str + " ")
                .c_str());
      }
      // std::cerr<<result_rename_transform<<"\n";
    } else {
      return Size;
    }
    if ((result_function_mutator == 0) && (result_hook_extractor == 0) &&
        (result_rename_transform == 0)) {
      // Load mutated program from file
      std::string rawname =
          temp_file_name.substr(0, temp_file_name.find_last_of("."));
      std::cerr << "Processed File: " << copy_filename << " with mutation "
                << mutation_chosen << "\n";
      create_file(copy_filename + "-" + get_date() + ".c", Data, Size);
      std::ifstream in(rawname + ".mutated.c");
      std::string contents((std::istreambuf_iterator<char>(in)),
                           std::istreambuf_iterator<char>());
      if (contents.size() <= MaxSize) {
        strncpy((char *)Data, contents.c_str(), contents.size());
        Size = contents.size();
        create_fuzzed_file(copy_filename, rawname + ".mutated.c");
      } else {
        std::cerr << " failed"
                  << "\n";
      }
      in.close();
    }
  } else if (sanity_checks) { // Single file mutation

    // Mutate file
    std::string Seed_str = std::to_string(Seed);

    // ADD CSMITH EXPR.
    if (need_csmith) {
      // Generate Csmith test case
      std::system(std::string(FuzzerArgument::_csmith_exec_command +
                              std::to_string(Seed) + " > " +
                              FuzzerArgument::_fuzzer_csmith_c_file + ")")
                      .c_str());

      // Call extract expression mutator
      std::system(std::string(mutator_path + "bin/extract-expression " +
                              FuzzerArgument::_fuzzer_csmith_c_file +
                              " -- --no-warnings " + lib_paths + " " +
                              Seed_str + " ")
                      .c_str());
    }
    int result_libtooling = -99;
    if (Size) {
      result_libtooling = std::system(
          std::string(mutator_path + mutation_chosen + " " + temp_file_name +
                      " -- --no-warnings " + lib_paths + " " + Seed_str + " ")
              .c_str());
    } else {
      return Size;
    }

    // If mutations did not fail
    if (result_libtooling == 0) {
      std::string rawname =
          temp_file_name.substr(0, temp_file_name.find_last_of("."));

      // Fix mutated file - parentheses - remove any extra
      std::system(std::string(FuzzerArgument::_fuzzer_remove_parens + 
                            " " + rawname + ".mutated.c" + " -- -w " + 
                            FuzzerArgument::_lib_paths + 
                            " -\I/home/user42/fuzzers/copy_5/../remove-parens/third_party/clang+llvm-13.0.1/lib/clang/13.0.1/include/)")
                            .c_str());

      // Load mutated program from file
      std::ifstream in(rawname + ".mutated.c");
      std::cerr << "Processed File: " << copy_filename << " with mutation "
                << mutation_chosen << "\n";
      create_file(copy_filename + "-" + get_date() + ".c", Data, Size);
      std::string contents((std::istreambuf_iterator<char>(in)),
                           std::istreambuf_iterator<char>());
      if (contents.size() <= MaxSize) {
        strncpy((char *)Data, contents.c_str(), contents.size());
        Size = contents.size();
        create_fuzzed_file(copy_filename, rawname + ".mutated.c");
      } else {
        std::cerr << " failed"
                  << "\n";
      }
      in.close();
    }
    // Clean-up for csmith files
    if (need_csmith) {
      if (!GrayCUtils::delete_mutator_file(
              FuzzerArgument::_fuzzer_csmith_c_file))
        std::cerr << "remove of " << FuzzerArgument::_fuzzer_csmith_c_file
                  << " failed"
                  << "\n";
      if (!GrayCUtils::delete_mutator_file(
              FuzzerArgument::_fuzzer_csmith_decl_file))
        std::cerr << "remove of " << FuzzerArgument::_fuzzer_csmith_decl_file
                  << " failed"
                  << "\n";
      if (!GrayCUtils::delete_mutator_file(
              FuzzerArgument::_fuzzer_csmith_expr_file))
        std::cerr << "remove of " << FuzzerArgument::_fuzzer_csmith_expr_file
                  << " failed"
                  << "\n";
    }
  }

  // Clean-up
  if (!temp_file_name.empty()) {
    if (!GrayCUtils::delete_mutator_file(temp_file_name))
      std::cerr << "remove of " << temp_file_name << " failed"
                << "\n";

    std::string rawname =
        temp_file_name.substr(0, temp_file_name.find_last_of("."));
    if (!rawname.empty()) {
      std::string mutated_file_rawname = std::string(rawname + ".mutated.c");
      std::ifstream mutated_file(mutated_file_rawname.c_str());
      if (mutated_file.good())
        if (!GrayCUtils::delete_mutator_file(mutated_file_rawname))
          std::cerr << "remove of " << mutated_file_rawname << " failed"
                    << "\n";
    }
  }

  // Counter++ and return
  FuzzerArgument::_counter = FuzzerArgument::_counter + 1;
  return Size;
}
