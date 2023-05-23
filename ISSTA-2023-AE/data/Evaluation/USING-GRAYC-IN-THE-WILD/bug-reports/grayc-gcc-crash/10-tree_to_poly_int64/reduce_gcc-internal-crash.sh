#!/bin/bash
gcc=/home/user42/data/gcc-csmith-120411/gcc-install/bin/gcc
src=fuzzer-file-3200-1.c

rm -rf *.out
rm -rf *out*.*
rm -rf *.err.*

ulimit -t 500

## creduce ./reduce.sh temp_orig_2976513859.c csmith_minimal.h  csmith.h config.h random_inc.h safe_math.h  platform_generic.h

! $gcc -O3 $src -o gcc.out >outa.txt 2>&1 &&\
 grep "internal compiler error: in tree_to_poly_int64, at tree.c:3091" outa.txt
