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

#include "CustomClangFuzzer.h"
#include "../mutators-GrayC-Agg/random-manager/ClangFuzzerCustomRandom.h"
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

unsigned FuzzerArgument::_counter = 0;

std::string FuzzerArgument::_fuzzer_output_temp_dir =
    "/home/user42/fuzzers/copy_5/llvm-csmith-5/llvm-fuzzer-build/"
    "fuzzer_ram-tmp/";
std::string FuzzerArgument::_fuzzer_output_directory =
    "/home/user42/fuzzers/copy_5/llvm-csmith-5/llvm-fuzzer-build/"
    "fuzzer-output-directory/";
std::string FuzzerArgument::_fuzzer_output_directory_fuzzed_files =
    "/home/user42/fuzzers/copy_5/llvm-csmith-5/llvm-fuzzer-build/"
    "fuzzer-output-directory-fuzzed-files/";
std::vector<std::string> FuzzerArgument::_mutator_options = {
    "bin/jump-mutator",      "bin/function-merger", "bin/duplicate-mutator",
    "bin/constant-mutator",  "bin/delete-mutator",  "bin/assignment-mutator",
    "bin/expression-mutator"};
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
  if (sanity_checks) { // Single file mutation

    // Mutate file
    std::string Seed_str = std::to_string(Seed);


    int result_libtooling = -99;
    if (Size) {
      result_libtooling = std::system(
          std::string("./no-fuss " + temp_file_name + " " + "/home/user42/no-fuss.mutated.c").c_str());
    } else {
      return Size;
    }

    // If mutations did not fail
    if (result_libtooling == 0) {
	    printf("Mutation successful\n");
      std::string rawname = "no-fuss";
          //temp_file_name.substr(0, temp_file_name.find_last_of("."));

            // Load mutated program from file
      std::ifstream in("/home/user42/" + rawname + ".mutated.c");
      create_file(copy_filename + "-" + get_date() + ".c", Data, Size);
      std::string contents((std::istreambuf_iterator<char>(in)),
                           std::istreambuf_iterator<char>());
      if (contents.size() <= MaxSize) {
        strncpy((char *)Data, contents.c_str(), contents.size());
        Size = contents.size();
	printf("Creating file from %s\n",rawname.c_str());
        create_fuzzed_file(copy_filename, "/home/user42/" + rawname + ".mutated.c");
      } else {
        std::cerr << " failed"
                  << "\n";
      }
      in.close();
      //std::system(std::string("rm /home/user42/no-fuss.mutated.c").c_str());
    }
  }
  size_t lastindex = temp_file_name.find_last_of(".");
  std::string rawname = temp_file_name.substr(0, lastindex);
  std::ifstream mutated_file((rawname + ".mutated.c").c_str());
  if (mutated_file.good()) {
    const std::string command_remove_file_mutated =
        "rm " + rawname + ".mutated.c";
    std::system(command_remove_file_mutated.c_str());
  }
  const std::string command_remove_file_original = "rm " + temp_file_name;
  std::system(command_remove_file_original.c_str());
  FuzzerArgument::_counter = FuzzerArgument::_counter + 1;
  return Size;
}
