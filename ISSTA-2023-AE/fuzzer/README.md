Installing GrayC (the fuzzer)
======================================

## Download Software Packages

First download the prerequirements by running script 0:
```
./0-install-req.sh
```

Then please test that all installation were done:
```
clang --version
```
you should get something similar to this:
```
Ubuntu clang version 12.0.1-++20210630032957+fed41342a82f-1~exp1~20210630133716.134
Target: x86_64-pc-linux-gnu
Thread model: posix
InstalledDir: /usr/bin
```
The same goes to the rest of the packages:

Cmake:
```
cmake --version
cmake version 3.20.0

CMake suite maintained and supported by Kitware (kitware.com/cmake).
```

Python3:
```
python3 --version
Python 3.8.10
```

Ninja:
```
ninja --version
1.10.0
```

M4:
```
m4 --version
m4 (GNU M4) 1.4.18
Copyright (C) 2016 Free Software Foundation, Inc.
License GPLv3+: GNU GPL version 3 or later <http://gnu.org/licenses/gpl.html>.
This is free software: you are free to change and redistribute it.
There is NO WARRANTY, to the extent permitted by law.

Written by Rene' Seindal.
```

GCC:
```
gcc --version
gcc (Ubuntu 10.3.0-1ubuntu1~20.04) 10.3.0
Copyright (C) 2020 Free Software Foundation, Inc.
This is free software; see the source for copying conditions.  There is NO
warranty; not even for MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
```

GCOV:
```
gcov --version
gcov (Ubuntu 10.3.0-1ubuntu1~20.04) 10.3.0
Copyright (C) 2020 Free Software Foundation, Inc.
This is free software; see the source for copying conditions.
There is NO warranty; not even for MERCHANTABILITY or 
FITNESS FOR A PARTICULAR PURPOSE.
```

## Download LLVM/CLANG 12 

Use this script to download LLVM 12:
```
./1-download-llvm.sh <base-folder> <LLVM-ver-no>
```
for example:
```
./1-download-llvm.sh /home/user42/ 12
```
The output of this script is something like this:
```
 >> Checking out releases/gcc-12 tag
Cloning into 'llvm-project'...
remote: Enumerating objects: 105471, done.
remote: Counting objects: 100% (105471/105471), done.
remote: Compressing objects: 100% (90726/90726), done.
remote: Total 105471 (delta 18517), reused 59844 (delta 11269), pack-reused 0
Receiving objects: 100% (105471/105471), 142.49 MiB | 1.47 MiB/s, done.
Resolving deltas: 100% (18517/18517), done.
Updating files: 100% (100437/100437), done.
Cloning into 'csmith'...
remote: Enumerating objects: 5796, done.
remote: Counting objects: 100% (42/42), done.
remote: Compressing objects: 100% (33/33), done.
remote: Total 5796 (delta 16), reused 20 (delta 9), pack-reused 5754
Receiving objects: 100% (5796/5796), 9.10 MiB | 1.28 MiB/s, done.
Resolving deltas: 100% (3921/3921), done.
 >> Downloaded LLVM 12 and Csmith into /home/user42//.sources_12VL.Z5NTi89.tmp.
```
This script downloaded the source file of llvm 12 into /home/user42//.sources_12VL.Z5NTi89.tmp. Your folder will have a bit different name, but with a similar pattern.
Next, we need to create a folder where the fuzzer will be installed and edit few files.

We prepared wrapper scripts for the rest of the scripts to install several instances of the fuzzer (to fuzz in parallel), for the conservative and aggressive versions. You may use the wrapper or run each of the script separatly. To run the wrapper for GrayC-conservative:
```
./install-fuzzers.sh <base-folder> <temp-folder-with-llvm-12> <GrayC-AE-folder> <number-of-copies>
```
and for GrayC-aggeressive:
```
./install-fuzzers-agg.sh <base-folder> <temp-folder-with-llvm-12> <GrayC-AE-folder> <number-of-copies>
```
for example:
```
./install-fuzzers-agg.sh /home/user42/git /home/user42/git/.sources_12VL.9IeP8DH.tmp /home/user42/git/GrayC-AE 3
```

Run first this script:
```
./2-prepare-env.sh <base-folder> <temp-folder-with-llvm-12> <copy-number>
```
We use copy-number '1' unless we want to run the fuzzer in parallel with several copies. For this AE, please always use 1. For example:
```
./2-prepare-env.sh /home/user42/ /home/user42//.sources_12VL.Z5NTi89.tmp 1
```
and it looks like this when running it:
```
...
...
[ 95%] Building CXX object src/CMakeFiles/csmith.dir/platform.cpp.o
[ 96%] Building CXX object src/CMakeFiles/csmith.dir/random.cpp.o
[ 97%] Building CXX object src/CMakeFiles/csmith.dir/util.cpp.o
[ 98%] Building CXX object src/CMakeFiles/csmith.dir/git_version.cpp.o
[100%] Linking CXX executable csmith
[100%] Built target csmith
>> Done.
```

At this stage please check that your base-folder contains the following files:
```
ls -l /home/user42
total 11718764
drwxrwxr-x 6 user42 user42        4096 Jul 21 11:17 GrayC-AE
drwxrwxr-x 4 user42 user42        4096 Jul 21 11:33 llvm-csmith-1
-rw------- 1 root   root   12000000000 May 20 14:43 swapfile
```

Then copy the fuzzer files into the llvm-csmith-1 folder, using this script:
```
./3-copy-fuzzer.sh <base-folder>/GrayC-AE/AE/tool/src/ <base-folder>/llvm-csmith-1/ <base-folder>
```
for example:
```
./3-copy-fuzzer.sh /home/user42/GrayC-AE/AE/tool/src/ /home/user42/llvm-csmith-1/ /home/user42/
>> Done.
```
To install the GrayC aggressive, use this script instead:
```
./3-copy-fuzzer-agg.sh <base-folder>/GrayC-AE/AE/tool/src/ <base-folder>/llvm-csmith-1/ <base-folder>
```

Last, check and apply (when needed) the following changes before compiling it:
* Check that the script added 'add_subdirectory(tools/mutator-name)' to the llvm-source/tools/clang/CMakeLists.txt
* Check that the script added mutator folders to llvm-source/tools/clang/tools/
* Check that the script updated settings.txt file with appropriate paths
* Check that the script updated CommonOptionsParser.h file so constructor is public instead of protected

At this stage, your folder llvm-csmith-1 should contain all files in place to be ready to build the fuzzer.

## Building and Running GrayC (the fuzzer)

Build GrayC (the fuzzer):
```
./4-build-fuzzer.sh <llvm-main-folder>
```
for example:
```
./4-build-fuzzer.sh /home/user42/llvm-csmith-1
```

Troubleshooting:
1. Incase you cannot pass cmake configue with the following message: 
"/usr/bin/ld: cannot find -lstdc++ "
try edit the library symbolic link:
```
sudo ln -s /usr/lib/x86_64-linux-gnu/libstdc++.so.6 /usr/lib/libstdc++.so
```
2. Running out of memory: increase the size of your swap file.

If script 4 ended with no error, you can expect the following output:
```
Please check compilation here:
total 640
-rw-rw-r-- 1 user42 user42 393524 Sep 29 18:47 build.log
-rw-rw-r-- 1 user42 user42  14276 Sep 29 11:52 configure.log
-rw-rw-r-- 1 user42 user42    469 Sep 29 18:48 fuzzer_build.log
-rw-rw-r-- 1 user42 user42 232515 Sep 29 18:49 install.log
-- Performing Test HAVE_GNU_POSIX_REGEX -- failed to compile
-- Performing Test HAVE_POSIX_REGEX
-- Performing Test HAVE_POSIX_REGEX
-- Performing Test HAVE_POSIX_REGEX -- success
-- Performing Test HAVE_STEADY_CLOCK
-- Performing Test HAVE_STEADY_CLOCK
-- Performing Test HAVE_STEADY_CLOCK -- success
-- Configuring done
-- Generating done
-- Build files have been written to: /home/user42/llvm-csmith-1/llvm-fuzzer-build
[4136/4145] Building CXX object utils/benchmark/src/CMakeFiles/benchmark.dir/json_reporter.cc.o
[4137/4145] Building CXX object utils/benchmark/src/CMakeFiles/benchmark.dir/sleep.cc.o
[4138/4145] Building CXX object utils/benchmark/src/CMakeFiles/benchmark.dir/reporter.cc.o
[4139/4145] Building CXX object utils/benchmark/src/CMakeFiles/benchmark.dir/string_util.cc.o
[4140/4145] Building CXX object utils/benchmark/src/CMakeFiles/benchmark.dir/statistics.cc.o
[4141/4145] Building CXX object utils/benchmark/src/CMakeFiles/benchmark.dir/timers.cc.o
[4142/4145] Copying llvm-locstats into /home/user42/llvm-csmith-1/llvm-fuzzer-build/./bin
[4143/4145] Building CXX object utils/benchmark/src/CMakeFiles/benchmark.dir/sysinfo.cc.o
[4144/4145] Linking CXX static library lib/libbenchmark.a
[4145/4145] Linking CXX static library lib/libbenchmark_main.a
[1/2] Building CXX object tools/clang/tools/clang-fuzzer/CMakeFiles/clang-fuzzer.dir/ClangFuzzer.cpp.o
/home/user42/llvm-csmith-1/llvm-source/tools/clang/tools/clang-fuzzer/ClangFuzzer.cpp:92:26: warning: unknown escape sequence '\I' [-Wunknown-escape-sequence]
                                        l_path = l_path + "-\I" + val + " ";
                                                            ^~
1 warning generated.
[2/2] Linking CXX executable bin/clang-fuzzer
-- Installing: ../llvm-install/usr/local/lib/cmake/llvm/./FindGRPC.cmake
-- Installing: ../llvm-install/usr/local/lib/cmake/llvm/./TensorFlowCompile.cmake
-- Installing: ../llvm-install/usr/local/lib/cmake/llvm/./AddOCaml.cmake
-- Installing: ../llvm-install/usr/local/lib/cmake/llvm/./CheckCompilerVersion.cmake
-- Installing: ../llvm-install/usr/local/lib/cmake/llvm/./LLVM-Build.cmake
-- Installing: ../llvm-install/usr/local/lib/cmake/llvm/./HandleLLVMStdlib.cmake
-- Installing: ../llvm-install/usr/local/lib/cmake/llvm/./AddSphinxTarget.cmake
-- Installing: ../llvm-install/usr/local/lib/cmake/llvm/./CrossCompile.cmake
-- Installing: ../llvm-install/usr/local/lib/cmake/llvm/./GetLibraryName.cmake
-- Installing: ../llvm-install/usr/local/lib/cmake/llvm/./LLVMProcessSources.cmake
Run fuzzer: cd /home/user42/llvm-csmith-1/llvm-fuzzer-build/ ; bin/clang-fuzzer /home/user42/llvm-csmith-1/../setA/ -detect_leaks=0 -max_len=1000000 -rss_limit_mb=4096 -create_missing_dirs=1 -ignore_crashes=1 -ignore_timeouts=1 -ignore_ooms=1
```

Then run GrayC (the fuzzer):
```
cd <fuzzer-build> ; bin/clang-fuzzer <setA-path> -detect_leaks=0 -max_len=1000000 -rss_limit_mb=4096 -create_missing_dirs=1 -ignore_crashes=1 -ignore_timeouts=1 -ignore_ooms=1
```
for example:
```
cd /home/user42/llvm-csmith-1/llvm-fuzzer-build/ ; bin/clang-fuzzer /home/user42/llvm-csmith-1/../setA/ -detect_leaks=0 -max_len=1000000 -rss_limit_mb=4096 -create_missing_dirs=1 -ignore_crashes=1 -ignore_timeouts=1 -ignore_ooms=1
```

Tools' Evaluation in the paper
==============================

Seeds files for running fuzzers: we added some examples of such in seeds folder.

## Throughput

We measured the throughput of Csmith vs. GrayC on 2-core, 8 GB, Intel, Ubuntu 20.04, virtual machine for 24 hours.

Using the following commands with the installation above of GrayC
```
(ulimit -St 86400; ./throughput/GrayC-24H.sh <fuzzer-build> <setA-path> <seeds-file>) > run_24h.log 2>&1 &
```
and with a wrapper to run Csmith for 24H
```
git clone https://github.com/csmith-project/csmith.git
cd csmith; git checkout 900729a; mkdir build; cd build; cmake ../ ; make;
(ulimit -St 86400; ./throughput/csmith-24H.sh <csmith-folder> <output-folder>)
```
which generates sets of programs from each of the tools for a period of 24 hours with timeout per generated program is set to be 50 s.

## Coverage

We measure coverage for several sets when evaluationg GrayC ability to find additional new coverage in GCC-12 and LLVM-13. We measure coveage with gcov-10 and gfauto. Please check both are installed correctly before starting this part (including gcov, gcc and cc versions).

### gfauto tool
If you don't have gfauto installed, please follow the instructions here: https://github.com/google/graphicsfuzz.
You can try the following instruction we used to set the tool:
```
git clone https://github.com/google/graphicsfuzz.git
cd graphicsfuzz/gfauto/
vi dev_shell.sh.template
EDIT TO YOUR LOCAL VERSION of Python3: PYTHON=${PYTHON-python3.6}
rm Pipfile.lock (if Python3.8 or above)
./dev_shell.sh.template
```

### LLVM Coverage
First, build a copy of LLVM 13 with coveage. First download llvm-13 (as above for the fuzzer):
```
./1-download-llvm.sh <base-folder> 13
```
Second, compile llvm-13 with coverage:
```
./coverage/0-install-csmith-llvm-ninja-cov.sh <base-folder> <temp-folder-with-llvm-13> 13
```
We recommand to set a large swap file for that (between 4 - 12 GB) for standard laptop configuration (serves and stronger machines do not have to follow this). 
Note that, the output of the first script includes a name of a temporary folder where llvm source is, use it as <temp-folder-with-llvm-13> parameter for the next script. 

```
cd ~
sudo fallocate -l 8G swapfile
sudo chmod 600 swapfile 
sudo mkswap swapfile 
sudo swapon swapfile
sudo swapon --show
```

Last, run this script per set to measure its coverage; no need to rebuild llvm-13 between runs of this script.
```
./coverage/1-wrapper-get-coverage.sh <base-folder> <set-of-progs-path> 13 0 <csmith-folder> <gfauto-folder> <func-cov-out.csv> <line-cov-out.csv> <coverage_summary.log> llvm 0
```
Base-folder=where the installation of LLVM 13 with coverage is, that is, \<base-folder\>/llvm-csmith-13/
 
We use script 1-wrapper-get-coverage.sh to measure the coverage of setA, setB, setA after 24 hours of fuzzing, and Csmith's generated test-cases (also for 24 hours). We also present a comparison with llvm test suite (whole and single source) in the paper. For that, we prepared additional scripts.

#### Coverage for LLVM test suite 
To measure LLVM's single source tests, first download these tests:
```
sudo apt install fdupes ## if not yet installed
./coverage/llvm-test-suite/1-get-llvm-testsuite-single-source.sh <output-dir> 
```
and then use script ./coverage/1-wrapper-get-coverage.sh with \<set-of-progs-path\>=\<output-dir\>.

To measure LLVM's coverage with its *complete* test suite, use these scripts. 

DO NOT MOVE SUB-FOLDERS OR RENAME FOLDERS WHILE RUNNING THESE SCRIPTS. 

Download the source code first, of both llvm and its test suite:
```
./coverage/llvm-test-suite/2-download-git-llvm-wt-rt.sh <base-folder> 13
```
The source files will be in a subfolder in the \<base-folder\>. The output is a temporary forlder with all the source files needed. For example:
```
>> Downloading LLVM with compiler-rt sources (/home/user42/coverage//.sources.1zbBYGq.tmp)
```
Next, you need to compile llvm with at least 32 GB of RAM or 4 GB swap file (as before):
```
./coverage/0-install-csmith-llvm-ninja-cov.sh <base-folder> <temp-folder-with-llvm-13> 13
```
where temp-folder-with-llvm-13 is the folder "/home/user42/coverage//.sources.1zbBYGq.tmp" in the example above. Your machine will generate a different name but with similar format; use it as an input for the script 0-install-csmith-llvm-ninja-cov.sh.
 
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
That is, after the change it should look like this:
```
grep -e"XRay" -e"sqlite3" /home/user42/coverage/llvm-csmith-13/test-suite/MultiSource/Applications/CMakeLists.txt 
#  add_subdirectory(sqlite3)
grep -e"XRay" -e"sqlite3" /home/user42/coverage/llvm-csmith-13/test-suite/CTMark/CMakeLists.txt
#add_subdirectory(sqlite3)
grep -e"XRay" -e"sqlite3" /home/user42/coverage/llvm-csmith-13/test-suite/MicroBenchmarks/CMakeLists.txt
#add_subdirectory(XRay)
```

Last, use this script to get a human-readable summary of the results:
```
./coverage/4-gen-statistic-gcov-diff-tab_gfauto.sh <base-folder>/llvm-csmith-13/coverage_processed/x-line-13/ table__llvm-13-line.csv >> llvm-testsuit-13.log
./coverage/4-gen-statistic-gcov-diff-tab_gfauto.sh <base-folder>/llvm-csmith-13/coverage_processed/x-func-13/ table__llvm-13-func.csv >> llvm-testsuit-13.log
```
which will output a summary of a line and function coverage for the whole llvm test suite (in general and per file).
 
## Test Contribution
 
We used the coverage measured above for the whole llvm test suite, to find a newly covered code by our fuzzed programs. 

We first measure coverage for the whole llvm test suite (git ) using the set of scripts above (./coverage/llvm-test-suite/2-download-git-llvm-wt-rt.sh, ./coverage/0-install-csmith-llvm-ninja-cov.sh, ./coverage/llvm-test-suite/3-llvm-testsuite-reg-cov.sh, ./coverage/4-gen-statistic-gcov-diff-tab_gfauto.sh).

Then we measure coverage with the fuzzed corpus too (setA), filter statically or dynamically invalid programs, cross with the coverage from script 4 and reduce the test case if possible.
