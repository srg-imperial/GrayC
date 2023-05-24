#!/bin/bash
clang=clang-12
gcc=/home/user42/data/gcc-csmith-1112/gcc-install/bin/gcc
src=test874084080-f2f58a.c

rm -rf *.out
rm -rf *out*.*
rm -rf *.err.*

ulimit -t 500

## creduce ./reduce.sh temp_orig_2976513859.c csmith_minimal.h  csmith.h config.h random_inc.h safe_math.h  platform_generic.h
$gcc -O2 -g -pedantic -Wall -Wextra -I/home/user42/data/csmith/runtime/ -I/home/user42/data/csmith/build/runtime/ $src -o gcc.out >outa.txt 2>&1

! $clang $opt -fsanitize=undefined -g -pedantic -Wall -Wextra -I/home/user42/data/csmith/runtime/ -I/home/user42/data/csmith/build/runtime/ $src -o clang.out >outb.txt 2>&1 &&\
#$gcc -O2 -g -pedantic -Wall -Wextra -I/home/user42/data/csmith/runtime/ -I/home/user42/data/csmith/build/runtime/ $src -o gcc.out >outa.txt 2>&1 &&\
  ! grep '\-Wuninitialized' outa.txt &&\
  ! grep 'without a cast' outa.txt &&\
  ! grep 'expects a matching' outa.txt &&\
  ! grep 'control reaches end' outa.txt &&\
#  ! grep 'no return statement' outa.txt &&\
  ! grep 'return type defaults' outa.txt &&\
  ! grep 'cast from pointer to integer' outa.txt &&\
  ! grep 'useless type name in empty declaration' outa.txt &&\
  ! grep 'no semicolon at end' outa.txt &&\
  ! grep 'type defaults to' outa.txt &&\
  ! grep 'too few arguments for format' outa.txt &&\
 # ! grep 'incompatible pointer' outa.txt &&\
  ! grep 'ordered comparison of pointer with integer' outa.txt &&\
  ! grep 'declaration does not declare anything' outa.txt &&\
  ! grep 'expects type' outa.txt &&\
  ! grep 'pointer from integer' outa.txt &&\
  ! grep 'incompatible implicit' outa.txt &&\
  ! grep 'excess elements in struct initializer' outa.txt &&\
  ! grep 'comparison between pointer and integer' outa.txt &&\
  ! cat outa.txt | grep "Please submit a full bug report" &&\
  cat outb.txt | grep "PLEASE ATTACH THE FOLLOWING FILES TO THE BUG REPORT"
