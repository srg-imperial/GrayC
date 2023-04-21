# GrayC: A fuzzer for C compilers and code analyzers

The GrayC approach involves using mutation-based fuzzing as a program generation technique, and then using the generated programs to test compilers and analysers.

## Description
GrayC is a greybox fuzzer for C compilers and a libfuzzer-based tool. In brief, GrayC works as follows. Starting with an initial corpus of test programs, it uses libfuzzer to perform coverage-guided mutation-based fuzzing of the Clang/LLVM compiler, for a time-limited period. Unconventionally, the purpose of this use of libfuzzer is not to find bugs at this stage, but rather to generate a large corpus of interesting test programs. This is achieved by
 (a) using a custom mutator to yield an interesting space of compiler test programs that are statically-valid, and
 (b) saving every test program that libfuzzer produces to an external directory.

After the fuzzing run has completed, GrayC processes this external directory of test programs to test compilers (scripts) and code analysers and to extract new UB-free test programs for compilers test suites (via the enhanCer).

Implementation Details: we have implemented our approach as a set of tools, the direct coverage fuzzer, GrayC, the program transformer, enhanCer, and a set of bash scripts for crash and differential testing. GrayC and the code analysis part of enhanCer were implemented in the LLVM 12.0.1 Framework with additional C/C++ code implementing our mutators on top of ClangFuzzer/libtooling. The enhanCer code transformation was implemented in python3 with a set of bash scripts.

## Installation

Out-of-tree for LLVM-12
