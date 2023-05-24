#!/bin/bash
clang=clang-10
gcc=/home/user42/data/gcc-csmith-1201/gcc-install/bin/gcc 
src=1ecbcad8a4bcf73ea55d80d05ec3388b7f2dbccc.c

rm -rf *.out
rm -rf *out*.*
rm -rf *.err.*

ulimit -t 500

## creduce ./reduce.sh temp_orig_2976513859.c csmith_minimal.h  csmith.h config.h random_inc.h safe_math.h  platform_generic.h

! $gcc -I/home/user42/data/csmith/runtime/ -I/home/user42/data/csmith/build/runtime/ $src -o gcc.out >outa.txt 2>&1 &&\
 ! grep "array size missing in" outa.txt &&\
 ! grep "at end of input" outa.txt &&\
 ! grep "Wimplicit-int" outa.txt &&\
 ! grep "expected ‘;’ before ‘)’ token" outa.txt &&\
 ! grep "error: expected ‘]’ before ‘)’ token" outa.txt &&\
 ! grep "expected expression before ‘)’" outa.txt &&\
 ! grep "expected expression before ‘:’ token" outa.txt &&\
 grep "tree check: expected array_type, have error_mark in array_ref_low_bound" outa.txt &&\
 grep "Please submit a full bug report" outa.txt
