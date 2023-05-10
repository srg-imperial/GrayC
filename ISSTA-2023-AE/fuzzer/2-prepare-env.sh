#!/bin/bash
working_folder=$1 	## base folder
TMP_SOURCE_FOLDER=$2 	## Input from 0- script
i=$3 			## installation number

mkdir -p $working_folder/llvm-csmith-$i
cp -rf $TMP_SOURCE_FOLDER/* $working_folder/llvm-csmith-$i

## Update Csmith settings
mkdir $working_folder/llvm-csmith-$i/csmith/scripts/ ## Just incase it isn't there
cd $working_folder/llvm-csmith-$i
echo $working_folder/llvm-csmith-$i"/llvm-install/usr/local/bin/clang -O3" > ./csmith/scripts/compiler_test.in

mkdir $working_folder/llvm-csmith-$i/csmith/build
cd $working_folder/llvm-csmith-$i/csmith/build
cmake ../
make -j$(nproc)
echo ">> Done."
