#!/bin/bash
working_folder=$1
llvm_ver=$2

## Needed to compile later the llvm test-suite
## Help here: https://llvm.org/docs/TestSuiteGuide.html
## http://clang-developers.42468.n3.nabble.com/llvm-test-suite-build-failure-td4064173.html 
	
# Set gcc-10 as default
sudo rm /usr/bin/cpp /usr/bin/gcc /usr/bin/g++  /usr/bin/gcov  /usr/bin/c++
sudo rm /usr/local/bin/cpp /usr/local/bin/gcc /usr/local/bin/g++ /usr/local/bin/gcov  /usr/local/bin/c++
sudo ln -s /usr/bin/cpp-10 /usr/bin/cpp
sudo ln -s /usr/bin/gcc-10 /usr/bin/gcc
sudo ln -s /usr/bin/g++-10 /usr/bin/g++
sudo ln -s /usr/bin/g++-10 /usr/bin/c++
sudo ln -s /usr/bin/gcov-10 /usr/bin/gcov

# Downloading LLVM and Csmith sources, building Csmith
TMP_SOURCE_FOLDER=$(mktemp -d $working_folder/.sources.XXXXXXX.tmp)
cd $TMP_SOURCE_FOLDER
## LLVM
wget https://github.com/llvm/llvm-project/releases/download/llvmorg-"$llvm_ver".0.0/llvm-"$llvm_ver".0.0.src.tar.xz
tar -xvf llvm-"$llvm_ver".0.0.src.tar.xz
rm llvm-"$llvm_ver".0.0.src.tar.xz
mv llvm-"$llvm_ver".0.0.src llvm-source
cd ./llvm-source/tools
wget https://github.com/llvm/llvm-project/releases/download/llvmorg-"$llvm_ver".0.0/clang-"$llvm_ver".0.0.src.tar.xz
tar -xvf clang-"$llvm_ver".0.0.src.tar.xz
rm clang-"$llvm_ver".0.0.src.tar.xz
mv clang-"$llvm_ver".0.0.src clang
cd $TMP_SOURCE_FOLDER
## Get compiler-rt needed for XRay
wget https://github.com/llvm/llvm-project/releases/download/llvmorg-"$llvm_ver".0.0/compiler-rt-"$llvm_ver".0.0.src.tar.xz
tar -xvf compiler-rt-"$llvm_ver".0.0.src.tar.xz
rm compiler-rt-"$llvm_ver".0.0.src.tar.xz
mv compiler-rt-"$llvm_ver".0.0.src compiler-rt
cd $TMP_SOURCE_FOLDER
## Gets llvm test-suite
git clone https://github.com/llvm/llvm-test-suite.git test-suite
echo ">> Downloading LLVM with compiler-rt sources ($TMP_SOURCE_FOLDER)"
