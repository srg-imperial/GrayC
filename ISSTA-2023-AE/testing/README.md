# Install Software (not our tool)

Install Frama-C:
```
sudo apt install frama-c
```
If this is not workig for your distribution, you can install it via this script:
```
./0-install-frama-c.sh
```

Install Grammarinator:
```
pip3 install grammarinator
```
If this is not working for your distribution, you can install it via this script:
```
./0-install-grammarinator.sh
```

Csmith installation instructions:
```
https://github.com/csmith-project/csmith#install-csmith
```
If this is not working for you, you need to install git, m4, and probably other packages. You can also try using our script:
```
./0-install-csmith.sh
```

Install remove-parens util instaructions:
```
https://github.com/mc-imperial/remove-parens
```
Or you can use our script:
```
./0-install-remove-parens.sh
```

# Code Coverage of Mature Compilers (Open Source Only)

We measure coverage for several sets when evaluating GrayC's ability to find new code coverage in GCC-12 and LLVM-13. We have measured it with gcov-10 and gfauto. Please check both are installed correctly before starting this part (including gcov, gcc and cc versions).

We describe next how to measure coverage for LLVM and GCC with specific versions. If you wish to use other versions, then please feel free to contact us.

Instrumentation of such a large codebase (15 Millions lines of code for GCC while LLVM is much larger) can take around 50 GB HD and around a day for all the scripts to finish.

## LLVM Code Coverage 
First, build a copy of LLVM 13 with coverage. First download llvm-13 (as above for the fuzzer):
```
./1-download-llvm.sh <base-folder> 13
```
Second, compile llvm-13 with coverage:
```
./coverage/0-install-csmith-llvm-ninja-cov.sh <base-folder> <temp-folder-with-llvm-13> 13
```
We recommend setting a large swap file for that (between 4 - 12 GB) for standard laptop configuration (servers and stronger machines do not have to follow this). 
Note: the output of the first script includes a name of a temporary folder where the LLVM source is, please use it as <temp-folder-with-llvm-13> as a parameter for the next script. 

```
cd ~
sudo fallocate -l 8G swapfile
sudo chmod 600 swapfile 
sudo mkswap swapfile 
sudo swapon swapfile
sudo swapon --show
```

Last, run this script per set to measure its coverage; no need to rebuild LLVM-13 between runs of this script.
```
./coverage/1-wrapper-get-coverage.sh <base-folder> <set-of-progs-path> 13 0 <csmith-folder> <gfauto-folder> <func-cov-out.csv> <line-cov-out.csv> <coverage_summary.log> llvm 0
```
Base-folder=where the installation of LLVM 13 with coverage is, that is, \<base-folder\>/llvm-csmith-13/
 
We use script 1-wrapper-get-coverage.sh to measure the coverage of setA, setB, and setA after 24 hours of fuzzing, and Csmith's generated test cases (also for 24 hours). We also present a comparison with the LLVM test suite (whole and single source) in the paper. For that, we prepared additional scripts.

### Coverage for LLVM test suite 
To measure LLVM's single source tests, first download these tests:
```
sudo apt install fdupes ## if not yet installed
./coverage/llvm-test-suite/1-get-llvm-testsuite-single-source.sh <output-dir> 
```
and then use script ./coverage/1-wrapper-get-coverage.sh with \<set-of-progs-path\>=\<output-dir\>.

To measure LLVM's coverage with its *complete* test suite, use these scripts. 

DO NOT MOVE SUB-FOLDERS OR RENAME FOLDERS WHILE RUNNING THESE SCRIPTS. 

Download the source code of both llvm and its test suite:
```
./coverage/llvm-test-suite/2-download-git-llvm-wt-rt.sh <base-folder> 13
```
The source files will be in a subfolder in the \<base-folder\>. The output is a temporary folder with all the source files needed. For example:
```
>> Downloading LLVM with compiler-rt sources (/home/user42/coverage//.sources.1zbBYGq.tmp)
```
Next, you need to compile llvm with at least 32 GB of RAM or 4 GB swap file (as before):
```
./coverage/0-install-csmith-llvm-ninja-cov.sh <base-folder> <temp-folder-with-llvm-13> 13
```
where temp-folder-with-llvm-13 is the folder "/home/user42/coverage//.sources.1zbBYGq.tmp" in the example above. Your machine will generate a different name but with a similar format; use it as an input for the script 0-install-csmith-llvm-ninja-cov.sh.
 
Then use this script to measure coverage for the whole llvm test suite:
```
./coverage/llvm-test-suite/3-llvm-testsuite-reg-cov.sh <base-folder> <gfauto-folder> 13
```
For X86, we had to put in comment few lines in the CMake files related to XRay and sqlute3:
```
vi <base-folder>/llvm-csmith-13/test-suite/MultiSource/Applications/CMakeLists.txt
Put in comment: add_subdirectory(sqlite3)
vi <base-folder>/llvm-csmith-13/test-suite/CTMark/CMakeLists.txt
Put in comment: add_subdirectory(sqlite3)
vi <base-folder>/llvm-csmith-13/test-suite/MicroBenchmarks/CMakeLists.txt
Put in comment: add_subdirectory(XRay)
```
That is, after the change, it should look like this:
```
grep -e"XRay" -e"sqlite3" /home/user42/coverage/llvm-csmith-13/test-suite/MultiSource/Applications/CMakeLists.txt 
# add_subdirectory(sqlite3)
grep -e"XRay" -e"sqlite3" /home/user42/coverage/llvm-csmith-13/test-suite/CTMark/CMakeLists.txt
# add_subdirectory(sqlite3)
grep -e"XRay" -e"sqlite3" /home/user42/coverage/llvm-csmith-13/test-suite/MicroBenchmarks/CMakeLists.txt
# add_subdirectory(XRay)
```

Last, use this script to get a human-readable summary of the results:
```
./coverage/4-gen-statistic-gcov-diff-tab_gfauto.sh <base-folder>/llvm-csmith-13/coverage_processed/x-line-13/ table__llvm-13-line.csv >> llvm-testsuit-13.log
./coverage/4-gen-statistic-gcov-diff-tab_gfauto.sh <base-folder>/llvm-csmith-13/coverage_processed/x-func-13/ table__llvm-13-func.csv >> llvm-testsuit-13.log
```
which will output a summary of a line and function coverage for the whole llvm test suite (in general and per file).

 
 
 
## GCC Code Coverage
 
Download the source code of GCC:
```
./coverage/1-download-gcc.sh <base-folder> 12 
```
The source files will be in a subfolder in the \<base-folder\>.
 
