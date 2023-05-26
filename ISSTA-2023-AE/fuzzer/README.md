Installing GrayC (the fuzzer)
======================================

## 1. Download Software Packages

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

*Note:* GrayC can work with newer versions of all of the above. However, it requires LLVM-12 source code, as we discuss next.

## 2. Download LLVM/CLANG 12 

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
 >> Downloaded LLVM 12 and Csmith into /home/user42/.sources_12VL.Z5NTi89.tmp.
```
This script downloaded the source file of llvm 12 into /home/user42//.sources_12VL.Z5NTi89.tmp. Your folder will have a bit different name, but with a similar pattern.
Next, we need to create a folder where the fuzzer will be installed and edit few files.

## 3. Installing the GrayC 

We prepared wrapper scripts for the rest of the scripts to install several instances of the fuzzer (to fuzz in parallel). 
You may use the wrapper or run each of the script separatly. 

### 3.1 Quick Installation of GrayC
To run the wrapper for GrayC:
```
./install-fuzzers-grayc.sh <base-folder> <temp-folder-with-llvm-12> <GrayC-AE-folder> <number-of-copies>
```
for example:
```
./install-fuzzers-grayc.sh /home/user42/ /home/user42/.sources_12VL.9IeP8DH.tmp /home/user42/GrayC/ISSTA-2023-AE 3
```

You can also try an experimental version of GrayC, which we call Gray Conservative mode, that imposes more checks for higher dynamic validity of test programs.
To build it run the wrapper for GrayC-conservative:
```
./install-fuzzers-cons.sh <base-folder> <temp-folder-with-llvm-12> <GrayC-AE-folder> <number-of-copies>
```
The two wrapper scripts contains three other scripts. We describe them below.

Note: it is enough to run the two scripts above to have GrayC installed in your system. 


### 3.2 Additional Details
We disccus under the hood of install-fuzzers-grayc and install-fuzzers-cons.sh scipts. These contain two stages: pre-processing and installaton

#### 3.2.1 Pre-processing
Run first this script:
```
./2-prepare-env.sh <base-folder> <temp-folder-with-llvm-12> <copy-number>
```
We use copy-number '1' unless we want to run the fuzzer in parallel with several copies. For this AE, please always use 1. For example:
```
./2-prepare-env.sh /home/user42/ /home/user42/.sources_12VL.Z5NTi89.tmp 1
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
./3-copy-fuzzer-agg.sh <base-folder>/GrayC/ISSTA-2023-AE/fuzzer/tool/src/ <base-folder>/llvm-csmith-1/ <base-folder>
```
for example:
```
./3-copy-fuzzer-agg.sh /home/user42/GrayC/ISSTA-2023-AE/fuzzer/tool/src/ /home/user42/llvm-csmith-1/ /home/user42/
>> Done.
```

Last, check and apply (when needed) the following changes before compiling it:
* Check that the script added 'add_subdirectory(tools/mutator-name)' to the llvm-source/tools/clang/CMakeLists.txt
* Check that the script added mutator folders to llvm-source/tools/clang/tools/
* Check that the script updated settings.txt file with appropriate paths
* Check that the script updated CommonOptionsParser.h file so constructor is public instead of protected

At this stage, your folder llvm-csmith-1 should contain all files in place to be ready to build the fuzzer.

#### 3.2.2 Installaton of GrayC (the fuzzer)

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

### 3.3 Running GrayC (the fuzzer)

Run GrayC (the fuzzer):
```
cd <fuzzer-build> ; bin/clang-fuzzer <setA-path> -detect_leaks=0 -max_len=1000000 -rss_limit_mb=4096 -create_missing_dirs=1 -ignore_crashes=1 -ignore_timeouts=1 -ignore_ooms=1
```
for example:
```
cd /home/user42/llvm-csmith-1/llvm-fuzzer-build/ ; bin/clang-fuzzer /home/user42/llvm-csmith-1/../setA/ -detect_leaks=0 -max_len=1000000 -rss_limit_mb=4096 -create_missing_dirs=1 -ignore_crashes=1 -ignore_timeouts=1 -ignore_ooms=1
```
Both modes use the same commands, however, one might be installed in /home/user42/llvm-csmith-1/ while the othere in /home/user42/llvm-csmith-2/.

What happens when you run GrayC?

- The log is printed into the screen (or file, if you redirect it).
- Each time a statically invalid program produced, it will dump the errors to the screen like this:
```
#2303	NEW    cov: 46591 ft: 196387 corp: 1881/1447Kb lim: 1000000 exec/s: 11 rss: 579Mb L: 427/38752 MS: 3 Custom-Custom-Custom-
/home/user42/fuzzers//copy_1/llvm-csmith-1/llvm-fuzzer-build/fuzzer_ram-tmp//mutator-S94jRZ.c:12:19: error: expected ')'
loop_break_88894++;
                  ^
/home/user42/fuzzers//copy_1/llvm-csmith-1/llvm-fuzzer-build/fuzzer_ram-tmp//mutator-S94jRZ.c:11:8: note: to match this '('
    if (
       ^
/home/user42/fuzzers//copy_1/llvm-csmith-1/llvm-fuzzer-build/fuzzer_ram-tmp//mutator-S94jRZ.c:14:1: error: 'break' statement not in loop or switch statement
break;
^
/home/user42/fuzzers//copy_1/llvm-csmith-1/llvm-fuzzer-build/fuzzer_ram-tmp//mutator-S94jRZ.c:17:25: error: expected ';' after expression
e != ((29283) != (*b)--))
                        ^
                        ;
/home/user42/fuzzers//copy_1/llvm-csmith-1/llvm-fuzzer-build/fuzzer_ram-tmp//mutator-S94jRZ.c:17:25: error: expected expression
4 errors generated.
Error while processing /home/user42/fuzzers//copy_1/llvm-csmith-1/llvm-fuzzer-build/fuzzer_ram-tmp//mutator-S94jRZ.c.
```
BUT THIS IS A NORMAL BEHAVIOUR OF GRAYC - WHY? these errors can help tune the aggresivness of the tool, and hence it is useful to have them there. 
- GrayC also logs the mutators activated and state on which program (fuzz/resultant program):
```
Processed File: fuzzer-file-277 with mutation bin/duplicate-mutator
Processed File: fuzzer-file-278 with mutation bin/delete-mutator
Processed File: fuzzer-file-279 with mutation bin/append-expression
Processed File: fuzzer-file-280 with mutation bin/append-expression
Processed File: fuzzer-file-281 with mutation bin/assignment-mutator
Processed File: fuzzer-file-282 with mutation bin/jump-mutator
Processed File: fuzzer-file-285 with mutation bin/duplicate-mutator
Processed File: fuzzer-file-286 with mutation bin/expression-mutator
#2293	NEW    cov: 46589 ft: 196382 corp: 1879/1446Kb lim: 1000000 exec/s: 11 rss: 579Mb L: 1830/38752 MS: 5 Custom-Custom-Custom-Custom-Custom-
Processed File: fuzzer-file-287 with mutation bin/assignment-mutator
Processed File: fuzzer-file-288 with mutation bin/append-expression
#2295	NEW    cov: 46589 ft: 196383 corp: 1880/1447Kb lim: 1000000 exec/s: 11 rss: 579Mb L: 318/38752 MS: 2 Custom-Custom-
```

## 4. Structure of the Source files of GrayC (fuzzer part)

This folder contains the code (tool), corpus (data), and seeds for randomisatin (seeds).
The folder tool, contains include library for GrayC (llvm-fuzzer-includes/), and the sourc files of GrayC (mutator_zips-v4) 
and GrayC conservative (mutator_zips-v6).

The full structure is:
```
.
└── fuzzer/
    ├── data/
    │   ├── setA-Controlle-experiments-data-12-Nov-21
    │   ├── setA
    │   └── setB
    ├── seeds
    └── tool/
        ├── llvm-fuzzer-includes/
        │   └── lib
        └── src/
            ├── mutator_zips-v4/
            │   ├── assignment-mutator
            │   ├── clang-fuzzer
            │   ├── constant-mutator
            │   ├── delete-mutator
            │   ├── duplicate-mutator
            │   ├── expression-mutator
            │   ├── function-extractor
            │   ├── function-merger
            │   ├── jump-mutator
            │   ├── random-manager
            │   └── rename-transform
            └── mutator_zips-v6/
                ├── append-expression
                ├── assignment-mutator
                ├── clang-fuzzer
                ├── constant-mutator
                ├── delete-mutator
                ├── duplicate-mutator
                ├── expression-mutator
                ├── extract-expression
                ├── function-extractor
                ├── function-merger
                ├── global-extractor
                ├── jump-mutator
                ├── rename-transform
                └── utils-fuzzer
```
