#!/bin/bash
clang=/home/user42/data/llvm-csmith-13/llvm-install/usr/local/bin/clang
src=test1552568772.c

rm -rf *.out
rm -rf *out*.*
rm -rf *.err.*

ulimit -t 500

! $clang -O0 -I/home/user42/data/csmith/runtime/ -I/home/user42/data/csmith/build/runtime/ $src -o gcc.out >outa.txt 2>&1 &&\
  grep 'LLVM ERROR: out of memory' outa.txt &&\
  grep 'PLEASE ATTACH THE FOLLOWING FILES TO THE BUG REPORT:' outa.txt
