#!/bin/bash
clang=clang-12
src=fuzzer-file-9946.c

rm -rf *.out
rm -rf *out*.*
rm -rf *.err.*

ulimit -t 500

! $clang  $src -o llvm.out >outa.txt 2>&1 &&\
  grep 'deregister_tm_clones' outa.txt &&\
  grep 'clang: error: linker command failed with exit code 1 (use -v to see invocation)' outa.txt
