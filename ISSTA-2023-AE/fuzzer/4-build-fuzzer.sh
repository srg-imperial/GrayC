#!/bin/bash
llvm_folder=$1

## Build the fuzzer
rm -rf $llvm_folder/llvm-fuzzer-build $llvm_folder/llvm-install $llvm_folder/build_info
mkdir  $llvm_folder/llvm-fuzzer-build $llvm_folder/llvm-install $llvm_folder/build_info
cd $llvm_folder/llvm-fuzzer-build
cmake  ../llvm-source/ -GNinja -DCMAKE_C_COMPILER=clang-12 -DCMAKE_CXX_COMPILER=clang++-12 -DLLVM_USE_SANITIZE_COVERAGE=YES -DLLVM_USE_SANITIZER=Address -DCMAKE_BUILD_TYPE=Release -Wno-dev > $llvm_folder/build_info/configure.log 2>&1 
ninja > $llvm_folder/build_info/build.log 2>&1
ninja clang-fuzzer > $llvm_folder/build_info/fuzzer_build.log 2>&1
DESTDIR=../llvm-install ninja install -k 10 > $llvm_folder/build_info/install.log 2>&1
## Create temp Dir
mkdir $llvm_folder/llvm-fuzzer-build/fuzzer_ram-tmp

## Check output
echo "Please check compilation here:"
ls -l $llvm_folder/build_info/
tail $llvm_folder/build_info/configure.log
tail $llvm_folder/build_info/build.log
tail $llvm_folder/build_info/fuzzer_build.log
tail $llvm_folder/build_info/install.log

## Instructions how to run the fuzzer:
echo "Run fuzzer: cd $llvm_folder/llvm-fuzzer-build/ ; bin/clang-fuzzer $llvm_folder/../setA/ -detect_leaks=0 -max_len=1000000 -rss_limit_mb=4096 -create_missing_dirs=1 -ignore_crashes=1 -ignore_timeouts=1 -ignore_ooms=1"
