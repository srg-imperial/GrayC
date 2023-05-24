#!/bin/bash
gcc=/home/user42/data/gcc-csmith-1201/gcc-install/bin/gcc
src=fuzzer-file-12773.c

rm -rf *.out
rm -rf *out*.*
rm -rf *.err.*

ulimit -t 500

## creduce ./reduce.sh temp_orig_2976513859.c csmith_minimal.h  csmith.h config.h random_inc.h safe_math.h  platform_generic.h

! $gcc  -pedantic -w -O2 -I/home/user42/data/csmith/runtime/ -I/home/user42/data/csmith/build/runtime/  $src -o gcc.out >outa.txt 2>&1 &&\
! grep "error: expected expression at end of input" outa.txt &&\
! grep "error: expected ‘;’ before ‘}’ token" outa.txt &&\
! grep "warning: return type defaults to ‘int’" outa.txt &&\
! grep "error: expected ‘(’ before " outa.txt &&\
clang-11 -pedantic -w -O0 -I/home/user42/data/csmith/runtime/ -I/home/user42/data/csmith/build/runtime/  $src -o clang.out >outb.txt 2>&1 &&\
grep "internal compiler error: in as_a, at value-range.h:381" outa.txt
