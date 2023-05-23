#!/bin/bash
gcc=/home/user42/data/gcc-csmith-12/gcc-install/bin/gcc
src=fuzzer-file-108673.c

rm -rf *.out
rm -rf *out*.*
rm -rf *.err.*

ulimit -t 100

## creduce ./reduce.sh temp_orig_2976513859.c csmith_minimal.h  csmith.h config.h random_inc.h safe_math.h  platform_generic.h

! /home/user42/data/gcc-csmith-12/gcc-install/bin/gcc -O2 -w -fsanitize=undefined $src -o gcc.out >outa.txt 2>&1 &&\
! grep "undefined reference to "  outa.txt &&\
 grep "main()" $src &&\
 grep "internal compiler error: in get_imports, at gimple-range-gori" outa.txt &&\
 grep "Please submit a full bug report" outa.txt
