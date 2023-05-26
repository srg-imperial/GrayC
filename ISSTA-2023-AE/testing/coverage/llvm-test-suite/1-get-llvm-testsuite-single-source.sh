#!/bin/bash 
location=$1		# /home/user42/git/data

# Create the output directory
rm -rf $location
mkdir $location

rm -rf $location/corpus
mkdir $location/corpus

## Copy from LLVM test-suite.
mkdir $location/llvm-tests
cd $location/llvm-tests
git clone https://github.com/llvm/llvm-test-suite.git
cd ..
cp $location/llvm-tests/llvm-test-suite/SingleSource/Regression/C/*.c $location/corpus/
cp $location/llvm-tests/llvm-test-suite/SingleSource/Regression/C/gcc-c-torture/execute/*.c $location/corpus/
cp $location/llvm-tests/llvm-test-suite/SingleSource/Regression/C/gcc-c-torture/execute/builtins/*.c $location/corpus/
cp $location/llvm-tests/llvm-test-suite/SingleSource/Regression/C/gcc-c-torture/execute/builtins/lib/*.c $location/corpus/
rm -rf $location/llvm-tests

## Remove benchmarks with floats
## filesWithFloats=`grep -l -e "double" -e "float" *.c`
## rm -f $filesWithFloats

## Remove duplicates
fdupes -dN corpus/
