# GrayC: A fuzzer for C compilers and code analyzers
<a href="https://srg.doc.ic.ac.uk/files/papers/grayc-issta-23.pdf" target="_blank"><img src="grayc.png" align="right" width="250"></a>
The GrayC approach involves using mutation-based fuzzing as a program generation technique, and then using the generated programs to test compilers and analysers.  

See the following links for the ISSTA 2023 [artifact](https://zenodo.org/record/7973856), 
[code](ISSTA-2023-AE) and [general instructions](ISSTA-2023-AE/README.md) 
of the "GrayC: Greybox Fuzzing of Compilers and Analysers for C" publication.

## Description
GrayC is a greybox fuzzer for C compilers and a libfuzzer-based tool. In brief, GrayC works as follows. Starting with an initial corpus of test programs, it uses libfuzzer to perform coverage-guided mutation-based fuzzing of the Clang/LLVM compiler, for a time-limited period. Unconventionally, the purpose of this use of libfuzzer is not to find bugs at this stage, but rather to generate a large corpus of interesting test programs. This is achieved by
 (a) using a custom mutator to yield an interesting space of compiler test programs that are statically-valid, and
 (b) saving every test program that libfuzzer produces to an external directory.

After the fuzzing run has completed, GrayC processes this external directory of test programs to test compilers (scripts) and code analysers and to extract new UB-free test programs for compilers test suites (via the enhanCer).

Implementation Details: we have implemented our approach as a set of tools, the direct coverage fuzzer, GrayC, the program transformer, enhanCer, and a set of bash scripts for crash and differential testing. GrayC and the code analysis part of enhanCer were implemented in the LLVM 12.0.1 Framework with additional C/C++ code implementing our mutators on top of ClangFuzzer/libtooling. The enhanCer code transformation was implemented in python3 with a set of bash scripts.

## Installation

```
wget -O - https://apt.llvm.org/llvm-snapshot.gpg.key | sudo apt-key add -
sudo apt-add-repository "deb http://apt.llvm.org/bionic/ llvm-toolchain-bionic-12 main"
sudo apt-get update
sudo apt-get install -y llvm-12 llvm-12-dev llvm-12-tools clang-12 libclang-common-12-dev libclang-12-dev 

This builds both LLVM and Clang on Ubuntu

git clone https://github.com/srg-imperial/GrayC.git
cd GrayC
mkdir build
cd build
cmake -GNinja -DCMAKE_C_COMPILER=gcc-11 -DCMAKE_CXX_COMPILER=g++-11 -DLLVM_CONFIG_BINARY=llvm-config-12 ../
ninja
```

