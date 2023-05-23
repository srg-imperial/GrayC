#!/bin/bash
clang=clang-14
gcc=/home/user42/data/gcc-csmith-1201/gcc-install/bin/gcc
src=fuzzer-file-37734.c

rm -rf *.out
rm -rf *out*.*
rm -rf *.err.*

ulimit -t 500

## creduce ./reduce.sh temp_orig_2976513859.c csmith_minimal.h  csmith.h config.h random_inc.h safe_math.h  platform_generic.h

$clang $opt -fsanitize=undefined -g -pedantic -Wall -Wextra -I/home/user42/data/csmith/runtime/ -I/home/user42/data/csmith/build/runtime/ $src -o clang.out >outb.txt 2>&1 &&\
  ! grep 'conversions than data arguments' outb.txt &&\
  ! grep 'incompatible redeclaration' outb.txt &&\
  ! grep 'ordered comparison between pointer' outb.txt &&\
  ! grep 'eliding middle term' outb.txt &&\
  ! grep 'end of non-void function' outb.txt &&\
  ! grep 'invalid in C99' outb.txt &&\
  ! grep 'specifies type' outb.txt &&\
  ! grep 'should return a value' outb.txt &&\
  #! grep 'uninitialized' outb.txt &&\
  ! grep 'incompatible pointer to' outb.txt &&\
  ! grep 'incompatible integer to' outb.txt &&\
  ! grep 'type specifier missing' outb.txt &&\
  ! $gcc -O2 -g -pedantic -Wall -Wextra -I/home/user42/data/csmith/runtime/ -I/home/user42/data/csmith/build/runtime/ $src -o gcc.out >outa.txt 2>&1 &&\
  cat outa.txt | grep "Please submit a full bug report" &&\
  cat outa.txt | grep "internal compiler error: in do_jump_1, at dojump.c" 
