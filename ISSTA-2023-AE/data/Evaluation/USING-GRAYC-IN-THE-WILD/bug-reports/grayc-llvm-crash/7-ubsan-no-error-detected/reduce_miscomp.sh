#!/bin/bash
xgcc=/home/user42/data/gcc-csmith-12/gcc-install/bin/gcc
#gccok=gcc-11
#clang=clang-13
clangok=clang-14
src=8e588485791c300e738ae2773f5d270b24789c80_v1.c
includes="-I/home/user42/data/csmith/runtime/ -I/home/user42/data/csmith/build/runtime/ -I/home/user42/directed-compiler-fuzzing-code/scripts/7-diff-testing/results_output -I/home/user42/directed-compiler-fuzzing-code/scripts/7-diff-testing/results_output/include"

rm -rf *.out
rm -rf *out*.*
rm -rf *.err.*

$xgcc -O0 -fsanitize=undefined -pedantic -Wall -Wextra $includes $src -o gcc.out >outa.txt 2>&1 &&\
  ! grep '\-Wuninitialized' outa.txt &&\
  ! grep 'without a cast' outa.txt &&\
  ! grep 'expects a matching' outa.txt &&\
  ! grep 'control reaches end' outa.txt &&\
  ! grep 'no return statement' outa.txt &&\
  ! grep 'return type defaults' outa.txt &&\
  ! grep 'cast from pointer to integer' outa.txt &&\
  ! grep 'useless type name in empty declaration' outa.txt &&\
  ! grep 'no semicolon at end' outa.txt &&\
  ! grep 'type defaults to' outa.txt &&\
  ! grep 'too few arguments for format' outa.txt &&\
  ! grep 'incompatible pointer' outa.txt &&\
  ! grep 'ordered comparison of pointer with integer' outa.txt &&\
  ! grep 'declaration does not declare anything' outa.txt &&\
  ! grep 'expects type' outa.txt &&\
  ! grep 'pointer from integer' outa.txt &&\
  ! grep 'incompatible implicit' outa.txt &&\
  ! grep 'excess elements in struct initializer' outa.txt &&\
  ! grep 'comparison between pointer and integer' outa.txt &&\
$clangok -O0 -fsanitize=undefined -pedantic -Wall -Wextra $includes $src -o clangok.out >outc.txt 2>&1 &&\
  ! grep 'conversions than data arguments' outc.txt &&\
  ! grep 'incompatible redeclaration' outc.txt &&\
  ! grep 'ordered comparison between pointer' outc.txt &&\
  ! grep 'eliding middle term' outc.txt &&\
  ! grep 'end of non-void function' outc.txt &&\
  ! grep 'invalid in C99' outc.txt &&\
  ! grep 'specifies type' outc.txt &&\
  ! grep 'should return a value' outc.txt &&\
  ! grep 'uninitialized' outc.txt &&\
  ! grep 'incompatible pointer to' outc.txt &&\
  ! grep 'incompatible integer to' outc.txt &&\
  ! grep 'type specifier missing' outc.txt &&\
  ! grep 'non-void function does not return a value' outc.txt &&\
  ! grep 'missing-variable-declarations' outc.txt &&\
  ! grep 'linker command failed with exit code 1' outc.txt &&\
  ! grep 'at end of declaration list' outc.txt &&\
 ./clangok.out 2>clangok.err.txt > clangok.out.txt &&\
 ! cat clangok.err.txt | grep "error" &&\
 (! ./gcc.out 2>gcc.err.txt > gcc.out.txt) &&\
 cat gcc.err.txt | grep "error"
