# The LLVM test suite

There are two parts relevant to GrayC in the LLVM test suite.

- Single source folders: we use these as part of GrayC initial corpus.
- The whole LLVM test suite: we use this to compare GrayC performance and to locate under tested part of the compiler.

To get LLVM's single source tests, download these tests using this script:
```
sudo apt install fdupes ## if not yet installed
./coverage/llvm-test-suite/1-get-llvm-testsuite-single-source.sh <output-dir> 
```
For the LLVM test suite: use this script to measure coverage for the whole llvm test suite:
```
./coverage/llvm-test-suite/3-llvm-testsuite-reg-cov.sh <base-folder> <gfauto-folder> 15
```
with LLVM 15. If you wish to use it with a different version, then replace the 15 with it.

Before using these scripts you will need to build LLVM with rt. You can find instructions [here]().
