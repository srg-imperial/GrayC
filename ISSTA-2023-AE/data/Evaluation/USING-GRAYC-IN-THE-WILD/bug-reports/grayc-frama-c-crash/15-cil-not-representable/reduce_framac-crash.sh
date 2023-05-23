#!/bin/bash
src=fuzzer-file-2359.c

rm -rf *.out
rm -rf *out*.*
rm -rf *.err.*

ulimit -t 150

! frama-c -eva $src >outa.txt 2>&1 &&\
  grep 'Unexpected error (Cil.Not_representable).' outa.txt &&\
  grep 'Your Frama-C version is 24.0 (Chromium)' outa.txt
