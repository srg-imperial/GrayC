# The LLVM test suite

There are two parts relevant to GrayC in the LLVM test suite.

- Single source folders: we use these as part of GrayC initial corpus.
- The whole LLVM test suite: we use this to compare GrayC performance and to locate under tested part of the compiler.

Requirement: download and build from source LLVM 15 with compiler-rt and clang parts. You can find how to do so [here](https://github.com/srg-imperial/GrayC/blob/main/scripts/coverage).

## Single tests of the LLVM test suite
To download LLVM's single source tests, use this script:
```
sudo apt install fdupes ## if not yet installed
./1-get-llvm-testsuite-single-source.sh <output-dir> 
```
You can then measure coverage for this folder as with any other folder of tests as explained [here](https://github.com/srg-imperial/GrayC/blob/main/scripts/coverage).

## The Whole LLVM Test suite.
For the LLVM test suite: use this script to measure coverage for the whole llvm test suite:
```
./2-llvm-testsuite-reg-cov.sh <base-folder> <gfauto-folder> 15
```
with LLVM 15. If you wish to use it with a different version, then replace the 15 with it.

Before using these scripts you will need to build LLVM with rt. You can find instructions [here](https://github.com/srg-imperial/GrayC/blob/main/scripts/coverage).
