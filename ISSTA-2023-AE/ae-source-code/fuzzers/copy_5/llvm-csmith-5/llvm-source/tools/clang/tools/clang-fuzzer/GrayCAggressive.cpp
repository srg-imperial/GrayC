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
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <cstdio>
#include <memory>
#include <stdexcept>
#include <array>
#include <dirent.h>
#include <sstream>
#include <assert.h>
#include <time.h>

using namespace clang_fuzzer;

unsigned FuzzerArgument::_counter = 0;

std::string FuzzerArgument::_fuzzer_output_temp_dir = "/home/user42/fuzzers/copy_5/llvm-csmith-5/llvm-fuzzer-build/fuzzer_ram-tmp/";
std::string FuzzerArgument::_fuzzer_output_directory = "/home/user42/fuzzers/copy_5/llvm-csmith-5/llvm-fuzzer-build/fuzzer-output-directory/";
std::string FuzzerArgument::_fuzzer_output_directory_fuzzed_files = "/home/user42/fuzzers/copy_5/llvm-csmith-5/llvm-fuzzer-build/fuzzer-output-directory-fuzzed-files/";
std::vector<std::string> FuzzerArgument::_mutator_options = {"bin/jump-mutator","bin/function-merger","bin/duplicate-mutator","bin/constant-mutator","bin/delete-mutator","bin/assignment-mutator","bin/expression-mutator"};

std::string FuzzerArgument::_original_corpus_dir = "";
std::string FuzzerArgument::_mutator_path = "";
std::string FuzzerArgument::_lib_paths = "";
std::string FuzzerArgument::_comp_flags = "-O2"; // Default just in case this parameter is missing

std::string exec_get_output(const char* cmd) {
    std::array<char, 128> buffer;
    std::string result("");
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

void read_directory(const std::string& name, std::vector <std::string> & v) {
	DIR* dirp = opendir(name.c_str());
	assert(dirp && std::string("Cannot read library in " + name));

	struct dirent * dp;
	while((dp = readdir(dirp)) != NULL) {
		v.push_back(dp->d_name);
	}
	closedir(dirp);
}

extern "C" int LLVMFuzzerInitialize(int *argc, char ***argv) {
	FuzzerArgument::_original_corpus_dir = argv[0][1];
	std::string m_path = "";
	std::string l_path = "";
	std::string c_flags="-O2";
	std::ifstream settings_file("/home/user42/fuzzers/copy_5/settings.txt");
	if (settings_file.is_open()) {
		std::string line;
		while (std::getline(settings_file, line)) {
			std::string value = line.substr(line.find(":") + 1); 
			std::string key = line.substr(0,line.find(":"));
			if (key == "mutator_path") {
				m_path = value;
			} else if (key == "lib_paths") {
				std::istringstream instream(value);
				std::string val;
				while (std::getline(instream,val,'\t')) {
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
	//std::cerr << FuzzerArgument::_mutator_path;
	std::cerr << FuzzerArgument::_lib_paths;
	//read_directory(FuzzerArgument::_original_corpus_dir,files);
	std::string hook_file_path = FuzzerArgument::_mutator_path + "Mutation-Hooks-Functions.txt";
	std::string hook_file_path_global = FuzzerArgument::_mutator_path + "Global-Info.txt";
	std::string hook_file_path_statement = FuzzerArgument::_mutator_path + "Statement-Info.txt";
	if(remove(hook_file_path.c_str())!=0 || remove(hook_file_path_global.c_str())!=0 || remove(hook_file_path_statement.c_str())!=0){
		//std::cerr << "Buggy remove" << "\n";
	}
	const std::string remove_directory_command = "rm -rf " + FuzzerArgument::_fuzzer_output_directory;
	std::system(remove_directory_command.c_str());
	const std::string create_fuzzer_directory = "mkdir " + FuzzerArgument::_fuzzer_output_directory;
	std::system(create_fuzzer_directory.c_str());

	const std::string remove_directory_command_fuzzed_files = "rm -rf " + FuzzerArgument::_fuzzer_output_directory_fuzzed_files;
	std::system(remove_directory_command_fuzzed_files.c_str());
	const std::string create_fuzzer_directory_fuzzed_files = "mkdir " + FuzzerArgument::_fuzzer_output_directory_fuzzed_files;
	std::system(create_fuzzer_directory_fuzzed_files.c_str());

	const std::string remove_tmp_directory_command_fuzzed_files = "rm -rf " + FuzzerArgument::_fuzzer_output_temp_dir;
	std::system(remove_tmp_directory_command_fuzzed_files.c_str());
	const std::string create_fuzzer_tmp_directory_fuzzed_files = "mkdir " + FuzzerArgument::_fuzzer_output_temp_dir;
	std::system(create_fuzzer_tmp_directory_fuzzed_files.c_str());

	return 0; 
}

extern "C" int LLVMFuzzerTestOneInput(uint8_t *data, size_t size) {
	std::string s((const char *)data, size);
	HandleCXX(s,"./test.cc" ,{FuzzerArgument::_comp_flags.c_str()});
	return 0;
}

bool hasEnding(std::string const &fullString, std::string const &ending){
	return (fullString.length() >= ending.length()) 
		? (0 == fullString.compare(fullString.length() - ending.length(), ending.length(), ending)) 
		: false;
}

void create_file (std::string filename, uint8_t *Data, size_t Size){
	const std::string command_create_copy_file = "touch " + FuzzerArgument::_fuzzer_output_directory + "/" + filename;
	std::system(command_create_copy_file.c_str());
	std::ofstream tmpfile (FuzzerArgument::_fuzzer_output_directory + "/" + filename);
	for (size_t i = 0; i<Size; i++) 
		tmpfile << (char) Data[i];

	tmpfile.flush();
	tmpfile.close();
}

void create_fuzzed_file (std::string filename, std::string original_filename){
	const std::string command_create_copy_file = "touch " + FuzzerArgument::_fuzzer_output_directory_fuzzed_files + "/" + filename;
	std::system(command_create_copy_file.c_str());
	const std::string command_move_fuzzed_file = "mv " + original_filename + " " + FuzzerArgument::_fuzzer_output_directory_fuzzed_files + "/" + filename;
	std::system(command_move_fuzzed_file.c_str());
}

bool is_empty(std::ifstream& pFile) {
	return pFile.peek() == std::ifstream::traits_type::eof();
}

bool does_compile(std::string fname, std::string lib_paths) {
	std::string comp_command = "clang --no-warnings " + lib_paths + " " + (fname);
	return ((std::system(comp_command.c_str())) == 0);
}

std::string get_date(void)
{
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
	// Print the seed we are using
	// std::cerr << ">> Using SEED: " << Seed << " and counter " << FuzzerArgument::_counter << std::endl;

	// Output program to mutate to RAM file
	
	ClangFuzzerCustomRandom::CreateInstance(Seed, FuzzerArgument::_mutator_options.size());
	std::string mutation_chosen = FuzzerArgument::_mutator_options[ClangFuzzerCustomRandom::GetInstance()->rnd_dice()];
	ClangFuzzerCustomRandom::DeleteInstance(Seed);

	const std::string command_create_temp_file = "mktemp " + FuzzerArgument::_fuzzer_output_temp_dir + "/mutator-XXXXXX.c";
	const std::string copy_filename = "fuzzer-file-" + std::to_string(FuzzerArgument::_counter);
	std::string temp_file_name = exec_get_output(command_create_temp_file.c_str());
	std::ofstream tmpfile (temp_file_name);
	for (size_t i = 0; i<Size; i++) {
		tmpfile << (char) Data[i];
	}
	tmpfile.flush();
	tmpfile.close();
	bool sanity_checks = true;
	
	if (!hasEnding(temp_file_name,".c")) {
		sanity_checks = false;
	}
	std::ifstream file(temp_file_name);
        if (file.peek() == EOF) {
        	sanity_checks = false;
	}
	file.close();

	std::string original_corpus_dir = FuzzerArgument::_original_corpus_dir;
	std::string mutator_path = FuzzerArgument::_mutator_path;
	std::string lib_paths = FuzzerArgument::_lib_paths;
	
	bool is_mutation_multi_file = (mutation_chosen == "bin/function-merger");
	if (is_mutation_multi_file && sanity_checks) {
		std::vector <std::string> files;
		std::string hook_file_path = mutator_path + "Mutation-Hooks-Functions.txt";
		std::string hook_file_path_global = mutator_path + "Global-Info.txt";
		std::string hook_file_path_statement = FuzzerArgument::_mutator_path + "Statement-Info.txt";
		std::string hook_file_path_statement_san = FuzzerArgument::_mutator_path + "Statement-Info-San.txt";
		if(remove(hook_file_path.c_str())!=0 || remove(hook_file_path_global.c_str())!=0 || remove(hook_file_path_statement.c_str())!=0 || remove(hook_file_path_statement_san.c_str())!=0){
			//std::cerr << "Buggy remove" << "\n";
		}

		std::string second_corpus_path = "/home/user42/fuzzers/copy_5/setB";
		read_directory(second_corpus_path, files);

		ClangFuzzerCustomRandom::CreateInstance(Seed, files.size());
		std::string mutation_src_file_name = files[ClangFuzzerCustomRandom::GetInstance()->rnd_dice()];
		while(!hasEnding(mutation_src_file_name,".c")) {
			read_directory(second_corpus_path,files);
			mutation_src_file_name = files[ClangFuzzerCustomRandom::GetInstance()->rnd_dice()];
		}
		ClangFuzzerCustomRandom::DeleteInstance(Seed);

		size_t lastindex = mutation_src_file_name.find_last_of("."); 
		std::string Seed_str = std::to_string(Seed);
		std::string mutation_src_file_rawname = mutation_src_file_name.substr(0, lastindex) + "_rename_output.c"; 
		const std::string command_libtooling_rename_transform = mutator_path+"bin/rename-transform " + second_corpus_path  + "/" +  mutation_src_file_name + " -- --no-warnings " + lib_paths + " " + Seed_str + " ";
		const std::string command_libtooling_hook_extractor = mutator_path+"bin/function-extractor " + second_corpus_path  + "/" +  mutation_src_file_rawname + " -- --no-warnings " + lib_paths + " " + Seed_str + " ";
		const std::string command_libtooling_function_mutator = mutator_path+"bin/function-merger " + temp_file_name + " -- --no-warnings " + lib_paths + " " + Seed_str + " ";
		int result_hook_extractor = -99;
		int result_rename_transform = -99;
		int result_function_mutator = -99;
		if (Size) {
			result_rename_transform = std::system(command_libtooling_rename_transform.c_str());
			std::string rename_name = second_corpus_path  + "/" +  mutation_src_file_rawname;
			std::ifstream f(rename_name.c_str());
			if (f.good()) {
				result_hook_extractor = std::system(command_libtooling_hook_extractor.c_str());
				result_function_mutator = std::system(command_libtooling_function_mutator.c_str());
			}
			//std::cerr<<result_rename_transform<<"\n";
		} else {
			return Size;
		}
		if (result_function_mutator == 0 && result_hook_extractor == 0 && result_rename_transform == 0) {
			// Load mutated program from file
			size_t lastindex = temp_file_name.find_last_of(".");
			std::string rawname = temp_file_name.substr(0, lastindex);
			std::cerr<<"Processed File: "<< copy_filename << " with mutation " << mutation_chosen <<"\n";
			create_file (copy_filename + "-" + get_date()+".c", Data, Size);
			std::ifstream in(rawname+".mutated.c");
			std::string contents((std::istreambuf_iterator<char>(in)), std::istreambuf_iterator<char>());
			if (contents.size()<=MaxSize) {
				strncpy((char *) Data, contents.c_str(), contents.size());
				Size = contents.size();
				create_fuzzed_file(copy_filename,rawname+".mutated.c");
			} else {
				std::cerr<<"failed"<<"\n";
			}
			in.close();
		}
	} else if (sanity_checks) {
		
        // Mutate file
		
		std::string Seed_str = std::to_string(Seed);
		std::string command_libtooling = "";	
		command_libtooling = mutator_path + mutation_chosen + " " + temp_file_name + " -- --no-warnings "+lib_paths+" " + Seed_str + " ";
		int result_libtooling = -99;
		if (Size) {
			result_libtooling = std::system(command_libtooling.c_str());
		} else{
			return Size;
		}
		if (result_libtooling == 0) {
		// Load mutated program from file
			size_t lastindex = temp_file_name.find_last_of(".");
        		std::string rawname = temp_file_name.substr(0, lastindex);
			std::ifstream in(rawname+".mutated.c");
			std::cerr<<"Processed File: "<< copy_filename << " with mutation " << mutation_chosen <<"\n";
			create_file (copy_filename + "-" + get_date()+".c", Data, Size);
			std::string contents((std::istreambuf_iterator<char>(in)), std::istreambuf_iterator<char>());
			if (contents.size()<=MaxSize) {
				strncpy((char *) Data, contents.c_str(), contents.size());
				Size = contents.size();
				create_fuzzed_file(copy_filename,rawname+".mutated.c");
			} else {
				std::cerr<<"failed"<<"\n";
			}
			in.close();
		}
	}
	size_t lastindex = temp_file_name.find_last_of(".");
	std::string rawname = temp_file_name.substr(0, lastindex);
	std::ifstream mutated_file((rawname+".mutated.c").c_str());
	if (mutated_file.good()) {
		const std::string command_remove_file_mutated = "rm " + rawname + ".mutated.c";
		std::system(command_remove_file_mutated.c_str());
	}
	const std::string command_remove_file_original = "rm "+temp_file_name;
	std::system(command_remove_file_original.c_str());
	FuzzerArgument::_counter = FuzzerArgument::_counter + 1;
	return Size;
}
