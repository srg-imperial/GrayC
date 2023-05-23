#!/bin/bash
clang=clang-14
src=5523daed847ab69918007c2c696bec546984c2d8.c

rm -rf *.out
rm -rf *out*.*
rm -rf *.err.*

ulimit -t 500

## creduce ./reduce.sh temp_orig_2976513859.c csmith_minimal.h  csmith.h config.h random_inc.h safe_math.h  platform_generic.h

$clang $opt -fsanitize=undefined -pedantic -Wall -Wextra -I/home/user42/directed-compiler-fuzzing-code/scripts/8-crash-testing/Frama-C-zone/ $src -o clang.out >outb.txt 2>&1 &&\
  ! grep 'conversions than data arguments' outb.txt &&\
  ! grep 'incompatible redeclaration' outb.txt &&\
  ! grep 'ordered comparison between pointer' outb.txt &&\
  ! grep 'eliding middle term' outb.txt &&\
  ! grep 'end of non-void function' outb.txt &&\
  ! grep 'invalid in C99' outb.txt &&\
  ! grep 'specifies type' outb.txt &&\
  ! grep 'should return a value' outb.txt &&\
  ! grep 'uninitialized' outb.txt &&\
  ! grep 'incompatible pointer to' outb.txt &&\
  ! grep 'incompatible integer to' outb.txt &&\
  ! grep 'type specifier missing' outb.txt &&\
    ls -l clang.out >out_lost.txt &&\
  ! frama-c -eva -slevel 100 -plevel 255 -eva-precision 5 -val-warn-undefined-pointer-comparison pointer -no-val-alloc-returns-null -warn-signed-overflow -val -no-val-show-progress -machdep x86_64 $src >outa.txt 2>&1 &&\
  grep 'Your Frama-C version is 24.0 (Chromium)' outa.txt >out_lost.txt
