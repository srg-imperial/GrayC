#!/bin/bash
clang=clang-14
gcc=/home/user42/data/gcc-csmith-1201/gcc-install/bin/gcc
src=fuzzer-file-4642.c

rm -rf *.out
rm -rf *out*.*
rm -rf *.err.*

ulimit -t 30

## creduce ./reduce.sh temp_orig_2976513859.c csmith_minimal.h  csmith.h config.h random_inc.h safe_math.h  platform_generic.h

! $gcc -O1 -w $src -o gcc.out >outa.txt 2>&1 &&\
  cat outa.txt | grep "internal compiler error: Segmentation fault" 
