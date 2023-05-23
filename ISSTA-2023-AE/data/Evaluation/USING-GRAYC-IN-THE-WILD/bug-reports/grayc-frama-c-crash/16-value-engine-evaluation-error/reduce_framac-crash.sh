#!/bin/bash
src=fuzzer-file-17090.c

rm -rf *.out
rm -rf *out*.*
rm -rf *.err.*

ulimit -t 150

! frama-c -eva -eva-slevel 100 -eva-plevel 256 -eva-precision 5 -eva-warn-undefined-pointer-comparison pointer -eva-no-alloc-returns-null -warn-signed-overflow -eva-no-show-progress -machdep x86_64 $src >outa.txt 2>&1 &&\
  grep 'Unexpected error (File "src/plugins/value/engine/evaluation.ml", line 1176, characters 14-20: Assertion failed)' outa.txt &&\
  grep 'Your Frama-C version is 24.0 (Chromium)' outa.txt
