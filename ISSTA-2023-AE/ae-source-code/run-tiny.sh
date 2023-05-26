./1-run-grayc-tiny.sh
ls -l /home/user42/fuzzers/copy_5/setA/*.c | wc -l
ls -l /home/user42/fuzzers/copy_5/llvm-csmith-5/llvm-fuzzer-build/fuzzer-output-directory-prev/* | wc -l
mkdir GrayC; cp /home/user42/fuzzers/copy_5/llvm-csmith-5/llvm-fuzzer-build/fuzzer-output-directory-prev/* GrayC

./2-run-grayc-conservative-tiny.sh
ls -l /home/user42/fuzzers/copy_5/setA/*.c | wc -l
ls -l /home/user42/fuzzers/copy_5/llvm-csmith-5/llvm-fuzzer-build/fuzzer-output-directory-prev/* | wc -l
mkdir grayc-conservative; cp /home/user42/fuzzers/copy_5/llvm-csmith-5/llvm-fuzzer-build/fuzzer-output-directory-prev/* grayc-conservative

./3-run-grayc-no-cov-guidance-tiny.sh
ls -l /home/user42/fuzzers/copy_5/setA/*.c | wc -l
ls -l /home/user42/fuzzers/copy_5/llvm-csmith-5/llvm-fuzzer-build/fuzzer-output-directory-prev/* | wc -l
mkdir grayc-no-cov-guidance ; cp /home/user42/fuzzers/copy_5/llvm-csmith-5/llvm-fuzzer-build/fuzzer-output-directory-prev/* grayc-no-cov-guidance

./4-run-grayc-fragments-fuzzing-tiny.sh
ls -l /home/user42/fuzzers/copy_5/setA/*.c | wc -l
ls -l /home/user42/fuzzers/copy_5/llvm-csmith-5/llvm-fuzzer-build/fuzzer-output-directory-prev/* | wc -l
mkdir grayc-fragments-fuzzing ; cp /home/user42/fuzzers/copy_5/llvm-csmith-5/llvm-fuzzer-build/fuzzer-output-directory-prev/* grayc-fragments-fuzzing

./5-run-clang-fuzzer-tiny.sh
ls -l /home/user42/fuzzers/copy_5/setA/*.c | wc -l
ls -l /home/user42/fuzzers/copy_5/llvm-csmith-5/llvm-fuzzer-build/fuzzer-output-directory-prev/* | wc -l
mkdir clang-fuzzer; cp /home/user42/fuzzers/copy_5/llvm-csmith-5/llvm-fuzzer-build/fuzzer-output-directory-prev/* clang-fuzzer

./6-run-csmith-tiny.sh
ls -l /home/user42/fuzzers/copy_5/setA/*.c | wc -l
ls -l /home/user42/fuzzers/copy_5/llvm-csmith-5/llvm-fuzzer-build/fuzzer-output-directory-prev/* | wc -l
mkdir csmith ; cp /home/user42/fuzzers/copy_5/llvm-csmith-5/llvm-fuzzer-build/fuzzer-output-directory-prev/* csmith

./7-run-grammarinator-tiny.sh
ls -l /home/user42/fuzzers/copy_5/setA/*.c | wc -l
ls -l /home/user42/fuzzers/copy_5/llvm-csmith-5/llvm-fuzzer-build/fuzzer-output-directory-prev/* | wc -l
mkdir grammarinator; cp /home/user42/fuzzers/copy_5/llvm-csmith-5/llvm-fuzzer-build/fuzzer-output-directory-prev/* grammarinator

./8-run-PolyGlot-tiny.sh
ls -l /home/user42/fuzzers/copy_5/setA/*.c | wc -l
ls -l /home/user42/fuzzers/copy_5/llvm-csmith-5/llvm-fuzzer-build/fuzzer-output-directory-prev/* | wc -l
mkdir PolyGlot; cp /home/user42/fuzzers/copy_5/llvm-csmith-5/llvm-fuzzer-build/fuzzer-output-directory-prev/* PolyGlot

./9-run-RegExpMutator-tiny.sh
ls -l /home/user42/fuzzers/copy_5/setA/*.c | wc -l
ls -l /home/user42/fuzzers/copy_5/llvm-csmith-5/llvm-fuzzer-build/fuzzer-output-directory-prev/* | wc -l
mkdir RegExpMutator; cp /home/user42/fuzzers/copy_5/llvm-csmith-5/llvm-fuzzer-build/fuzzer-output-directory-prev/* RegExpMutator

./10-run-AFLCompiler-tiny.sh
ls -l /home/user42/fuzzers/copy_5/setA/*.c | wc -l
ls -l /home/user42/fuzzers/copy_5/llvm-csmith-5/llvm-fuzzer-build/fuzzer-output-directory-prev/* | wc -l
mkdir AFLCompiler; cp /home/user42/fuzzers/copy_5/llvm-csmith-5/llvm-fuzzer-build/fuzzer-output-directory-prev/* AFLCompiler
