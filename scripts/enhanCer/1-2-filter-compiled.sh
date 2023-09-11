#!/bin/bash
##################
## This script check which of the single file programs we can 
## compile given a folder.
#################
testcaseDir=$1          #"/home/user42/git/directed-compiler-fuzzing-code/scripts/3-reduce-general-spots-reaching-files/corpus_weak+gen_feb/orig_1"
testcaseDir_output=$2		# Where to copy those that compiles
includes=$3			        # Add -I line: e.g., -I/home/user42/git/csmith/build/runtime/  -I/home/user42/git/csmith/runtime/

rm -rf $testcaseDir_output
mkdir $testcaseDir_output

for testcaseFile in $testcaseDir/* ; do
  (ulimit -St 50 -Sf 90000; clang -w -O0 $includes $testcaseFile) > basic_output.txt 2>&1
  warnings=`cat basic_output.txt | wc -l`
  errors=`grep "error:" basic_output.txt | wc -l`
  linker=`grep "error: linker command failed" basic_output.txt | wc -l`
  echo "--> Compile	$testcaseFile	$warnings	$errors	$linker" 
  rm basic_output.txt
  
  if [ $errors -eq 0 ] && [ $linker -eq 0 ]; then
  	cp $testcaseFile $testcaseDir_output
  fi
done

x=`ls -l $testcaseDir | wc -l`
y=`ls -l $testcaseDir_output | wc -l`
echo ">> Out of $x programs $y pass compilations <$testcaseDir_output>"
