#!/bin/bash
clang=/home/user42/data/llvm-csmith-13/llvm-install/usr/local/bin/clang
clangx=/usr/lib/llvm-14/bin/clang
src=fuzzer-file-10430.c

rm -rf *.out
rm -rf *out*.*
rm -rf *.err.*

ulimit -t 500
! $clangx -cc1 -triple x86_64-pc-linux-gnu -emit-obj --mrelax-relocations -disable-free -clear-ast-before-backend -disable-llvm-verifier -discard-value-names -main-file-name fuzzer-file-10430.c -mrelocation-model static -mframe-pointer=none -fmath-errno -ffp-contract=on -fno-rounding-math -mconstructor-aliases -funwind-tables=2 -target-cpu x86-64 -tune-cpu generic -debugger-tuning=gdb -fcoverage-compilation-dir=/home/user42/directed-compiler-fuzzing-code/scripts/8-crash-testing -resource-dir /usr/lib/llvm-14/lib/clang/14.0.0 -I /home/user42/data/csmith/runtime/ -I /home/user42/data/csmith/build/runtime/ -internal-isystem /usr/lib/llvm-14/lib/clang/14.0.0/include -internal-isystem /usr/local/include -internal-isystem /usr/bin/../lib/gcc/x86_64-linux-gnu/11/../../../../x86_64-linux-gnu/include -internal-externc-isystem /usr/include/x86_64-linux-gnu -internal-externc-isystem /include -internal-externc-isystem /usr/include -Os -pedantic -w -fdebug-compilation-dir=/home/user42/directed-compiler-fuzzing-code/scripts/8-crash-testing -ferror-limit 19 -fgnuc-version=4.2.1 -vectorize-loops -vectorize-slp -faddrsig -D__GCC_HAVE_DWARF2_CFI_ASM=1 -o /tmp/fuzzer-file-10430-32ac98.o -x c $src >outa.txt 2>&1 &&\
  grep '2.	Optimizer' outa.txt &&\
  grep 'PLEASE submit a bug report to' outa.txt
