#!/bin/bash
clang=clang-12
gcc=/home/user42/data/gcc-csmith-1201/gcc-install/bin/gcc
src=3f985ea6ca098a09555bf6e694c514a506f3eadd.c #1934d6e2aee70d21f4a7d16c0d1ff2867764c085.c

rm -rf *.out
rm -rf *out*.*
rm -rf *.err.*

ulimit -t 500

! $gcc -O0 -g -pedantic -Wall -Wextra -I/home/user42/data/csmith/runtime/ -I/home/user42/data/csmith/build/runtime/ $src -o gcc.out >outa.txt 2>&1 &&\
  cat outa.txt | grep "Please submit a full bug report" &&\
  cat outa.txt | grep "internal compiler error: in constant_byte_string, at expr.cc" 
