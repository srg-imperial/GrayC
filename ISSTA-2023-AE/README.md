# GrayC: Greybox Fuzzing of Compilers and Analysers for C

GrayC is a greybox fuzzer for C compilers and analysers and is a libfuzzer-based tool. In brief, GrayC works as follows. Starting with an initial corpus of test programs, it uses libfuzzer to perform coverage-guided mutation-based fuzzing of the Clang/LLVM compiler for a time-limited period. Unconventionally, the purpose of this use of libfuzzer is not to find bugs at this stage but rather to generate a large corpus of interesting test programs. It is achieved by (a) using a custom mutator to yield an interesting space of compiler test programs that are statically-valid, and (b) saving every test program that libfuzzer produces to an external directory.

After the fuzzing run has completed, GrayC processes this external directory of test programs to test compilers (scripts) and code analysers and to extract new UB-free test programs for compilers test suites (via the enhanCer).

Implementation Details: we have implemented our approach as a set of tools, the direct coverage fuzzer, GrayC, the program transformer, enhanCer, and a set of bash scripts for crash and differential testing. GrayC and the code analysis part of enhanCer were implemented in the LLVM 12.0.1 Framework with additional C/C++ code implementing our mutators on top of ClangFuzzer/libtooling. The enhanCer code transformation was implemented in python3 with a set of bash scripts.

This repository contains the data and code to reproduce the results in the paper "GrayC: Greybox Fuzzing of Compilers and Analysers for C".

# GrayC Artifact ISSTA 2023

## 1. Getting Started

This Docker image contains a pre-built version of GrayC. It also includes all the tools we comapred against in our controlled evaluation and includes to set ups of GrayC: aggressive and conservative modes. To start the docker container:
```
docker run -it grayc
```

### Artifact’s requirements
git, python3, python3-pip, gfauto (under Google's graphicsfuzz), cmake, m4, ninja-build, curl, wget, zip, unzip, frama-c, creduce, openSSL (libcurl4-openssl-dev, libssl-dev), 

Note 1: CMake 3.13.4 or higher is required.

Note 2: creduce installed with this command:
```

```

Most of the packages required can be installed with (e.g.) brew or apt, however, some need to be build from source.
1. gfauto: https://github.com/google/graphicsfuzz.git
2. remove-parens (Git version: 1b2c68e): https://github.com/mc-imperial/remove-parens
3. Regexp based tool for mutating generic source code across numerous languages (for evaluation against other approaches): https://github.com/agroce/universalmutator/releases/tag/v1.0.18

### Steps to check the basic functionality of the artifact
todo

A copy of this README is in the working directory of the Docker image, ~/grayc/README.md.

## 2. Detailed Instructions

Here we describe how to reproduce all the tables and graphs data for section 5 in the paper: the controlled experiments with the additional tools compared against GrayC's performance.

### Step-by-Step instructions

We are comparing aginst many other fuzzers in our experiments. Here are links to thier Git repositories:
1. Csmith: 
2. 

## 3. Reusability of GrayC
First of all, GrayC can use to detect bugs in mature compilers. We discuss below the structure of the source code of GrayC and give detailed instructions on how to build the tool from the source. Note that compilers such as LLVM and GGC are very complex pieces of code; hence the build process of these with instrumentation is a heavy task, by definition. It can take several hours, even on a machine with 16 GB RAM. We recommend adding swap files.

### Build from source
GrayC was implemented on top of LibFuzzer, and so its build may take long, depending on your machine: it builds LLVM 12 with instrumentation.

Please follow the instructions in this README.md file.


### Project structure


### Original Testing Set-up

