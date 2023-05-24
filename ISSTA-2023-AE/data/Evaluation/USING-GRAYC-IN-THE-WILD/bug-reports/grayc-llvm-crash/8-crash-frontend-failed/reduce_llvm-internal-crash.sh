#!/bin/bash
clang=/home/user42/data/builds_msan_13/llvm-130-build_NO_D_A_memsan/bin/clang-13
src=3abd6bfec6d4e7b15a96782462b8a08d50355bbf.c
includes="-I/usr/lib/gcc/x86_64-linux-gnu/11/../../../../x86_64-linux-gnu/include -I/home/user42/data/csmith/runtime/ -I/home/user42/data/csmith/build/runtime/"


rm -rf *.out
rm -rf *out*.*
rm -rf *.err.*

ulimit -t 500

! $clang -O0 -w -fsanitize=address $includes $src -o clang.out >outa.txt 2>&1 &&\
  ! grep 'LLVM ERROR: out of memory' outa.txt &&\
  grep 'clang frontend command failed due to signal' outa.txt &&\
  grep 'PLEASE ATTACH THE FOLLOWING FILES TO THE BUG REPORT:' outa.txt
