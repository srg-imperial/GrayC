#!/bin/bash
##################
## This script check which of the single file programs we can with gcc-11
## compile given a folder.
#################
testcaseDir=$1  #"/home/user42/git/grayc-aggressive/set1"
seg=$2          # 1
includes=$3     # "-I/home/user42/git/cov/llvm-csmith-115/csmith/build/runtime/ -I/home/user42/git/cov/llvm-csmith-115/csmith/runtime/"
y=0

for testcaseFile in $testcaseDir/segment_"$seg"/*fuzzer-file-* ; do
  ( ulimit -t 50 -Sf 90000; gcc-11 -w -O0 $includes $testcaseFile > basic_output.txt 2>&1 )
  cat basic_output.txt
  warnings=`cat basic_output.txt | wc -l`
  errors=`grep "error:" basic_output.txt | wc -l`
  linker=`grep "error: linker command failed" basic_output.txt | wc -l`
  compiler_timeout=`grep "CPU time limit exceeded" basic_output.txt | wc -l`
  echo "--> Compile	$testcaseFile | $warnings | $errors | $linker | $compiler_timeout"

  if [ $errors -eq 0 ] && [ $linker -eq 0 ] && [ $compiler_timeout -eq 0 ] ; then
    #echo y: $y
    ((y=y+1))
  fi
  rm basic_output.txt
  touch basic_output.txt
done

# statistics
x=`ls -l $testcaseDir/segment_"$seg"/*fuzzer-file-* | wc -l`
echo ">> Out of $x programs $y pass compilations"
