# I. GrayC: Greybox Fuzzing of Compilers and Analysers for C

GrayC is a greybox fuzzer for C compilers and analysers and is a libfuzzer-based tool. In brief, GrayC works as follows. Starting with an initial corpus of test programs, it uses libfuzzer to perform coverage-guided mutation-based fuzzing of the Clang/LLVM compiler for a time-limited period. Unconventionally, the purpose of this use of libfuzzer is not to find bugs at this stage but rather to generate a large corpus of interesting test programs. It is achieved by (a) using a custom mutator to yield an interesting space of compiler test programs that are statically-valid, and (b) saving every test program that libfuzzer produces to an external directory.

After the fuzzing run has completed, GrayC processes this external directory of test programs to test compilers (scripts) and code analysers and to extract new UB-free test programs for compilers test suites (via the enhanCer).

Implementation Details: we have implemented our approach as a set of tools, the direct coverage fuzzer, GrayC, the program transformer, enhanCer, and a set of bash scripts for crash and differential testing. GrayC and the code analysis part of enhanCer were implemented in the LLVM 12.0.1 Framework with additional C/C++ code implementing our mutators on top of ClangFuzzer/libtooling. The enhanCer code transformation was implemented in python3 with a set of bash scripts.

This repository contains the data and code to reproduce the results in the paper "GrayC: Greybox Fuzzing of Compilers and Analysers for C".

# II. GrayC Artifact ISSTA 2023 - Phase 1

## II.A Getting Started

This Docker image contains a pre-built version of GrayC. It also includes all the tools we comapred against in our controlled evaluation and includes to set ups of GrayC: aggressive and conservative modes. To start the docker container:
```
docker run -it grayc
```
Then you need to run all the experiments as user42 (just a random user name we picked for this artifact!). 
In case you are running as root (e.g., you see the home folder that way: root@96ac044ddeef:/home/user42/), please run this command within the docker image:
```
su - user42
```
(do not run it if you are already user42, e.g. you see the home folder that way: user42@96ac044ddeef:~/).

If you do not wish to use a docker image, we discuss in the next section how to install it from source GrayC. We recommend using our docker image since we are testing mature C compilers (i.e. the instrumented code is 50 GB). 

## II.B Artifact’s requirements - [SKIP](README.md#iic-steps-to-check-the-basic-functionality-of-the-artifact) THIS IF USING DOCKER IMAGE

*For installing from source,* you will need to install the following: gcc, gcov, g++, git, python3, python3-pip, gfauto (under Google's graphicsfuzz), cmake, m4, ninja-build, curl, wget, zip, unzip, frama-c, creduce, openSSL (libcurl4-openssl-dev, libssl-dev), frama-c, creduce, grammarinator. 

Note 1: CMake 3.13.4 or higher is required.

Note 2: GCC-10 or higher is required. We have tested our artifact with GCC-10 and GCC-11.

Most of the packages required can be installed with (e.g.) brew or apt, however, some need to be build from source.
1. gfauto: https://github.com/google/graphicsfuzz.git
2. remove-parens (Git version: 1b2c68e): https://github.com/mc-imperial/remove-parens
3. Regexp based tool for mutating generic source code across numerous languages (for evaluation against other approaches): https://github.com/agroce/universalmutator/releases/tag/v1.0.18
4. Grammarinator, which can be installed: (https://pypi.org/project/grammarinator/)
```
pip3 install grammarinator
```

You can then need to continue and follow the instructions in "VI. Reusability of GrayC - Additional details" (the last part of this README.md file).

## II.C Steps to check the basic functionality of the artifact

If you choose to install from source or use our docker image (recommanded), you can test if all is working by running the fuzzer.

1. Docker. Run the following:
```
cd /home/user42/
./run-grayc-conservative.sh
```
DO NOT WORRY IF YOU GET C ERROR MESSAGES, we test C compilers, and hence do bad things to it. However, if you fuzzer does not start or stop suddenly, please contact us.

2. Installing from source scripts, prints a command at the end of the installation, please use this command "as is" to test all is working well.

Once starting the fuzzer it should print into the screen or logger file (if you redirect it), something like these messages:
```
-I/home/user42/fuzzers//copy_1/llvm-csmith-1/llvm-fuzzer-includes/ -I/usr/include/x86_64-linux-gnu/ 
INFO: found LLVMFuzzerCustomMutator (0x678f00). Disabling -len_control by default.
INFO: Running with entropic power schedule (0xFF, 100).
INFO: Seed: 1262126277
INFO: Loaded 1 modules   (1580480 inline 8-bit counters): 1580480 [0xbc29090, 0xbdaae50),
INFO: Loaded 1 PC tables (1580480 PCs): 1580480 [0xbdaae50,0xd5c8a50),
INFO:     2005 files found in /home/user42/fuzzers//copy_1/llvm-csmith-1/../setA/
INFO: seed corpus: files: 2005 min: 108b max: 38752b total: 1483224b rss: 108Mb
#128	pulse  cov: 25891 ft: 50183 corp: 124/20Kb exec/s: 42 rss: 296Mb
#256	pulse  cov: 30047 ft: 67200 corp: 242/44Kb exec/s: 28 rss: 451Mb
#512	pulse  cov: 35096 ft: 85253 corp: 469/100Kb exec/s: 25 rss: 500Mb
#1024	pulse  cov: 40160 ft: 115514 corp: 912/252Kb exec/s: 23 rss: 510Mb
#2006	INITED cov: 46427 ft: 195668 corp: 1814/1356Kb exec/s: 16 rss: 547Mb
Processed File: fuzzer-file-0 with mutation bin/delete-mutator
	NEW_FUNC[1/3]: 0x67daca0 in llvm::opt::Arg::getAsString[abi:cxx11](llvm::opt::ArgList const&) const /home/user42/fuzzers/copy_1/llvm-csmith-1/llvm-source/lib/Option/Arg.cpp:68
	NEW_FUNC[2/3]: 0x9328810 in llvm::AttributeSet::removeAttribute(llvm::LLVMContext&, llvm::Attribute::AttrKind) const /home/user42/fuzzers/copy_1/llvm-csmith-
```
and so on.

NOTE: A copy of this README is in the working directory of the Docker image, ~/grayc/README.md.

# III. GrayC Artifact ISSTA 2023 - Phase 2

After you loaded succesfull our docker image or installed from source GrayC. You can follow the instruction below to reproduce the results in Section 5 of our paper.

## III.A General Information

We first describe the exact set up of our machines for the controlled experiments.

During our evaluation, we installed the following tools (with the exact versions used in the experiments)
 1. Experiments on LLVM 12.0.1 (version from the 4th of October 2021)
 2. ninja 1.8.2
 3. cmake 3.20.0
 4. fdupes 1.6.1
 5. remove-parens (Git version: 1b2c68e)
 6. flex 2.6.4
 7. m4 1.4.18
 
We are comparing aginst many other fuzzers in our experiments. Here are links to thier Git repositories.

### Evaluation with:
 1. Csmith 2.4.0: https://github.com/csmith-project/csmith ([our own script to install Csmith](fuzzer/0-install-csmith.sh))
 2. ClangFuzzer/LLVM v12.0.1 x86: https://github.com/llvm-mirror/llvm/blob/master/docs/LibFuzzer.rst
 3. universalmutator v1.0.18: TODO
 4. grammarinator-generate 19.3: via apt or with [our own script to install Grammarinator](fuzzer/0-install-grammarinator.sh))
 5. TODO: add the rest of them.
 
Note: Csmith requires also m4; we used m4 1.4.18.

## III.B Results you can reproduced with this artifact

We now discuss how to reproduce the results with short fuzzing campaign, each of which takes 5 minutes. 
Note: in the paper the fuzzing campaign are 24 hours longs, repeated 10 times, which will bring the testing of this part to 2400 hours of fuzzing (because we also have 10 differnet tools).

- Table 5: Throughput
- Figure 2: LLVM coverage
- Figure 2: GCC coverage
- Figure 3: LLVM middle-end coverage
- Figure 3: LLVM back-end coverage
- Table 6: BUG Rate in 24 hours

Seeds files for running fuzzers: we added some examples of such in [seeds folder](fuzzer/seeds) of the artifact as some of the fuzzers require seeds.

We give details below how to reproduce each for the results. The scripts require no graphical terminal, and hence, the results are numbers and not the graphs in the paper. However, you can re-create the graphs yourself (e.g. via excel or graphPad).

## III.C Detailed Instructions

We describe now how to reproduce all the tables and graphs' data for section 5 in the paper: the controlled experiments with the additional tools compared against GrayC's performance.

### Step-by-Step instructions

--- OLD TEXT --- NEED TO RUN AND MOVE UP
Tools' Evaluation in the paper
==============================

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

	
Bug Rate:
	This table describes the total confirmed unique bugs found by each tool during 24 h of fuzzing (union over 10 repetitions) in the middle- and front-end components. In the script, we will summarised the number of bugs found per unique error message, however, to properly classify these into UNIQUE BUGS, there is a manual stage of the LLVM developers feedback (that is, present the bug and ask if it is unique, and get a confirmation by the bug reporting system of LLVM, which no one (yet) can automate!).
--- END of Old text ---


# VI. Reusability of GrayC - Additional details
	
First of all, GrayC can use to detect bugs in mature compilers. We discuss below the structure of the source code of GrayC and give detailed instructions on how to build the tool from the source. Note that compilers such as LLVM and GGC are very complex pieces of code; hence the build process of these with instrumentation is a heavy task, by definition. It can take several hours, even on a machine with 16 GB RAM. We recommend adding swap files.

### Build from source
GrayC was implemented on top of LibFuzzer, and so its build may take long, depending on your machine: it builds LLVM 12 with instrumentation.

Please follow the instructions in this README.md file (under GrayC/ISSTA-2023-AE/fuzzer/README.md).
```
nano GrayC/ISSTA-2023-AE/fuzzer/README.md
```

### Project structure

The project contains several folders.
	
The [fuzzer](fuzzer) folder contains the code of GrayC and instructions how to install GrayC with a detailed inner structure at the end of its [README.md](fuzzer/README.md) file.

### Original Testing Set-up

