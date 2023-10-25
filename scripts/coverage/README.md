# Coverage Scripts

To use these scripts to measure coverage for GrayC follow the steps below.

## Software Requirements

*For installing from source,* you will need to install the following: gcc, gcov, g++, flex, bison, binutils, git, python3, python3-pip, gfauto (under Google's graphicsfuzz), cmake, m4, ninja-build, curl, wget, zip, unzip, frama-c, creduce, openSSL (libcurl4-openssl-dev, libssl-dev). Commonly these packages are installed if you work with compilers' source code.

Note 1: CMake 3.13.4 or higher is required.

Note 2: GCC-11 is required.

Note 3: gfauto: https://github.com/google/graphicsfuzz.git
	
### gfauto tool
If you don't have gfauto installed, please follow the instructions here: https://github.com/google/graphicsfuzz.
You can try the following instructions we used to set up the tool:
```
git clone https://github.com/google/graphicsfuzz.git
cd graphicsfuzz/gfauto/
vi dev_shell.sh.template
EDIT TO YOUR LOCAL VERSION of Python3: PYTHON=${PYTHON-python3.6}
rm Pipfile.lock (if Python3.8 or above)
./dev_shell.sh.template
```

## Download GCC and LLVM source code

Follow the instructions [here](https://github.com/srg-imperial/GrayC/blob/main/scripts/general).

## LLVM Code Coverage 

To build a copy of LLVM with coverage use this script:
```
./0-install-llvm-cov.sh <base-folder> <path-to-llvm-project-source-code-folder> <version>
```
We recommend setting a large swap file (between 4 - 12 GB) for standard laptop configuration (servers do not have to follow this).  

```
cd ~
sudo fallocate -l 8G swapfile
sudo chmod 600 swapfile 
sudo mkswap swapfile 
sudo swapon swapfile
sudo swapon --show
```

After building LLVM with coverage successfully, run this script per set to measure its coverage; no need to rebuild LLVM between runs of this script.
```
./1-wrapper-get-coverage.sh <base-folder> <set-of-progs-path> 15 0 <csmith-folder> <gfauto-folder> <func-cov-out.csv> <line-cov-out.csv> <coverage_summary.log> llvm 0
```
Base-folder=where the installation of LLVM 15 with coverage is, that is, \<base-folder\>/llvm-csmith-15/

## LLVM Code Coverage with Compiler-rt parts

To compare the addition of a set of files to the coverage of LLVM on top of the LLVM test suite, you will need to do the following.

First, get the source code of LLVM; see [here](https://github.com/srg-imperial/GrayC/blob/main/scripts/general) how.

Second, build with compiler-rt and coverage:
```
./0-install-llvm-cov-rt.sh <base-folder> <path-to-llvm-project-source-code-folder> <version>
```
Third, see here how to measure coverage for the whole LLVM test suite.

Last, you will need to create a folder with all the files you have fuzzed, and run this script:
```
```
