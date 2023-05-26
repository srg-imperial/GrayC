./1-run-grayc-small.sh
ls -l /home/user42/fuzzers/copy_5/setA/*.c | wc -l
ls -l /home/user42/fuzzers/copy_5/llvm-csmith-5/llvm-fuzzer-build/fuzzer-output-directory-prev/* | wc -l
mkdir GrayC; cp /home/user42/fuzzers/copy_5/llvm-csmith-5/llvm-fuzzer-build/fuzzer-output-directory-prev/* GrayC

./2-run-grayc-conservative-small.sh
ls -l /home/user42/fuzzers/copy_5/setA/*.c | wc -l
ls -l /home/user42/fuzzers/copy_5/llvm-csmith-5/llvm-fuzzer-build/fuzzer-output-directory-prev/* | wc -l
mkdir grayc-conservative; cp /home/user42/fuzzers/copy_5/llvm-csmith-5/llvm-fuzzer-build/fuzzer-output-directory-prev/* grayc-conservative

./3-run-grayc-no-cov-guidance-small.sh
ls -l /home/user42/fuzzers/copy_5/setA/*.c | wc -l
ls -l /home/user42/fuzzers/copy_5/llvm-csmith-5/llvm-fuzzer-build/fuzzer-output-directory-prev/* | wc -l
mkdir grayc-no-cov-guidance ; cp /home/user42/fuzzers/copy_5/llvm-csmith-5/llvm-fuzzer-build/fuzzer-output-directory-prev/* grayc-no-cov-guidance

./4-run-grayc-fragments-fuzzing-small.sh
ls -l /home/user42/fuzzers/copy_5/setA/*.c | wc -l
ls -l /home/user42/fuzzers/copy_5/llvm-csmith-5/llvm-fuzzer-build/fuzzer-output-directory-prev/* | wc -l
mkdir grayc-fragments-fuzzing ; cp /home/user42/fuzzers/copy_5/llvm-csmith-5/llvm-fuzzer-build/fuzzer-output-directory-prev/* grayc-fragments-fuzzing

./5-run-clang-fuzzer-small.sh
ls -l /home/user42/fuzzers/copy_5/setA/*.c | wc -l
ls -l /home/user42/fuzzers/copy_5/llvm-csmith-5/llvm-fuzzer-build/fuzzer-output-directory-prev/* | wc -l
mkdir clang-fuzzer; cp /home/user42/fuzzers/copy_5/llvm-csmith-5/llvm-fuzzer-build/fuzzer-output-directory-prev/* clang-fuzzer

./6-run-csmith-small.sh
ls -l /home/user42/fuzzers/copy_5/setA/*.c | wc -l
ls -l /home/user42/fuzzers/copy_5/llvm-csmith-5/llvm-fuzzer-build/fuzzer-output-directory-prev/* | wc -l
mkdir csmith ; cp /home/user42/fuzzers/copy_5/llvm-csmith-5/llvm-fuzzer-build/fuzzer-output-directory-prev/* csmith

./7-run-grammarinator-small.sh
ls -l /home/user42/fuzzers/copy_5/setA/*.c | wc -l
ls -l /home/user42/fuzzers/copy_5/llvm-csmith-5/llvm-fuzzer-build/fuzzer-output-directory-prev/* | wc -l
mkdir grammarinator; cp /home/user42/fuzzers/copy_5/llvm-csmith-5/llvm-fuzzer-build/fuzzer-output-directory-prev/* grammarinator

./8-run-PolyGlot-small.sh
ls -l /home/user42/fuzzers/copy_5/setA/*.c | wc -l
ls -l /home/user42/fuzzers/copy_5/llvm-csmith-5/llvm-fuzzer-build/fuzzer-output-directory-prev/* | wc -l
mkdir PolyGlot; cp /home/user42/fuzzers/copy_5/llvm-csmith-5/llvm-fuzzer-build/fuzzer-output-directory-prev/* PolyGlot

./9-run-RegExpMutator-small.sh
ls -l /home/user42/fuzzers/copy_5/setA/*.c | wc -l
ls -l /home/user42/fuzzers/copy_5/llvm-csmith-5/llvm-fuzzer-build/fuzzer-output-directory-prev/* | wc -l
mkdir RegExpMutator; cp /home/user42/fuzzers/copy_5/llvm-csmith-5/llvm-fuzzer-build/fuzzer-output-directory-prev/* RegExpMutator

./10-run-AFLCompiler-small.sh
ls -l /home/user42/fuzzers/copy_5/setA/*.c | wc -l
ls -l /home/user42/fuzzers/copy_5/llvm-csmith-5/llvm-fuzzer-build/fuzzer-output-directory-prev/* | wc -l
mkdir AFLCompiler; cp /home/user42/fuzzers/copy_5/llvm-csmith-5/llvm-fuzzer-build/fuzzer-output-directory-prev/* AFLCompiler
