# The LLVM test suite

There are two parts relevant to GrayC in the LLVM test suite.

- Single source folders: we use these as part of GrayC initial corpus.
- The whole LLVM test suite: we use this to compare GrayC performance and to locate under tested part of the compiler.

To get LLVM's single source tests, download these tests using this script:
```
sudo apt install fdupes ## if not yet installed
./coverage/llvm-test-suite/1-get-llvm-testsuite-single-source.sh <output-dir> 
```
