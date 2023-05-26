# Corpus of C programs for fuzzing with GrayC

We have collected a large set of C single files for fuzzing with GrayC from the following sources:

1. LLVM test-suite (Single files, UB-free): https://github.com/llvm/llvm-test-suite/tree/main/SingleSource
2. Programiz webpage: https://www.programiz.com/c-programming
3. GitHub C test suite project: https://github.com/c-testsuite/c-testsuite
4. Csmith programs reduced via Creduce: https://github.com/csmith-project/csmith and https://github.com/csmith-project/creduce

Each program in the corpus contains a comment stating its source.
