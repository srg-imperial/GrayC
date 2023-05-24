#!/bin/bash
gcc=/home/user42/data/gcc-csmith-120411/gcc-install/bin/gcc
src=fuzzer-file-879.c

rm -rf *.out
rm -rf *out*.*
rm -rf *.err.*

ulimit -t 500

## creduce ./reduce.sh temp_orig_2976513859.c csmith_minimal.h  csmith.h config.h random_inc.h safe_math.h  platform_generic.h

! $gcc -O3 -I/home/user42/data/csmith/runtime/ -I/home/user42/data/csmith/build/runtime/  $src -o gcc.out >outa.txt 2>&1 &&\
! grep "error: expected expression at end of input" outa.txt &&\
! grep "error: expected ‘;’ before ‘}’ token" outa.txt &&\
! grep "warning: return type defaults to ‘int’" outa.txt &&\
! grep "error: expected ‘(’ before " outa.txt &&\
grep "internal compiler error: tree check: expected class ‘type’, have ‘exceptional’ (error_mark) in useless_type_conversion_p, at gimple-expr.cc:87" outa.txt
