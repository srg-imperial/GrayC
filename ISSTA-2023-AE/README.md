# I. GrayC: Greybox Fuzzing of Compilers and Analysers for C

This repository contains the data and code to reproduce the results in the paper "GrayC: Greybox Fuzzing of Compilers and Analysers for C".

## Experiment logs and Data:

Please see these links for bug reports and raw data [for the whole paper](data) and for [section 4](data/Evaluation/USING-GRAYC-IN-THE-WILD) and [section 5](data/Evaluation/EVALUATION-VIA-CONTROLLED-EXPERIMENTS/Bug-finding-trails). In addition, we included all the sets generated with the tools in the evaluation in our artifact as [10-sets-of-test-programs-tool-name.zip](https://zenodo.org/record/7978251).

NOTE: A copy of this README is in the working directory of the Docker image, ~/grayc/ISSTA-2023-AE/README.md.

## Test Contribution
 
We used the coverage measured for the whole llvm test suite (and compared it to our own fuzzed programs code coverage on the LLVM compiler) to find a newly covered code by our fuzzed programs and contribute them to the LLVM test suite.

We first measured coverage for the whole [LLVM test suite](https://github.com/llvm/llvm-test-suite) using the set of [scripts](testing/coverage). We then measured coverage with our fuzzed corpus, filtering statically or dynamically invalid programs, crossed with the coverage of the LLVM test suite, and reduced the test case if possible. The report data is available [here](data/Evaluation/USING-GRAYC-IN-THE-WILD/LLVM-test-contributions).
	
	
	
	

# II. GrayC Artifact ISSTA 2023 - Phase 1

**===> Docker Image can be found in [here](https://emckclac-my.sharepoint.com/:f:/g/personal/k1510625_kcl_ac_uk/Ep7kEJdbLLtJmi-nnnMSALUBTn-s5h3ovUaBg6aKFLRtbA?e=ZiF4Tk) in case Zenodo blocks the upload <===**

## II.A Loading the Docker Image

This Docker image contains a pre-built version of GrayC. It also includes all the tools we compared against in our controlled evaluation and the setting up of GrayC. To start the docker container:
```
cat GrayC-v3.tar | docker import - grayc-artifact 
docker run -it --user user42 grayc-artifact /bin/bash
```

Then you shall run all the experiments as user42 (just a random user name we picked for this artifact!). 
In case you are running as root (e.g., you see the home folder that way: root@96ac044ddeef:/home/user42/), please run this command within the docker image:
```
su - user42
```
(do not run it if you are already user42, e.g. you see the home folder that way: user42@96ac044ddeef:~/).
Then you need to install the tool:
```
cd ~
./install.sh
```
After installation, the docker image will be 70 GB. The GrayC-v1.tar is 20 GB before any installation.

We recommend using our docker image since we are testing mature C compilers (i.e. the instrumented code is 50 GB).

If you do not wish to use a docker image, we discuss later how to install GrayC from source (last section of this artifact).

## II.B Steps to check the basic functionality of the artifact

Once you load and attach the docker image of the GrayC artifact, do the following to test that all is working:

1. Inside the Docker image, execute the scripts with user42, not root. Please do not switch to root.
2. Run the following for each tool in our controlled experiments. There are several fuzzers in this study.
```
cd /home/user42/
./1-run-grayc-tiny.sh
./3-run-grayc-no-cov-guidance-tiny.sh
./4-run-grayc-fragments-fuzzing-tiny.sh
./5-run-clang-fuzzer-tiny.sh
./6-run-csmith-tiny.sh
./7-run-grammarinator-tiny.sh
./8-run-PolyGlot-tiny.sh
./9-run-RegExpMutator-tiny.sh
```
The *tiny.sh scripts run each for 1 minute. Do not worry if not all fuzzers produced data, as some of them (like Clang-fuzzer) have a longer loading time.

DO NOT WORRY IF YOU GET C ERROR MESSAGES. We test C compilers and hence do bad things to them. However, if a fuzzer does not start or stop suddenly, please let us know. For example, this is a valid output when fuzzing compilers:
```
Processed File: fuzzer-file-467 with mutation bin/constant-mutator
Processed File: fuzzer-file-470 with mutation bin/duplicate-mutator
#2362	NEW    cov: 46489 ft: 195611 corp: 1779/1260Kb lim: 1000000 exec/s: 10 rss: 585Mb L: 1371/38753 MS: 5 Custom-Custom-Custom-Custom-Custom-
/home/user42/fuzzers/copy_5/llvm-csmith-5/llvm-fuzzer-build/fuzzer_ram-tmp//mutator-Tt4q9a.mutated.c:146:2: error: use of undeclared identifier 'g_this'; did you mean 'this'?
;g_this.m_relPositioned = false;
 ^~~~~~
 this
/home/user42/fuzzers/copy_5/llvm-csmith-5/llvm-fuzzer-build/fuzzer_ram-tmp//mutator-Tt4q9a.mutated.c:93:14: note: 'this' declared here
  RenderBox *this = thisin;
             ^
/home/user42/fuzzers/copy_5/llvm-csmith-5/llvm-fuzzer-build/fuzzer_ram-tmp//mutator-Tt4q9a.mutated.c:146:8: error: member reference type 'RenderBox *' (aka 'struct RenderBox *') is a pointer; did you mean to use '->'?
;g_this.m_relPositioned = false;
 ~~~~~~^
       ->
2 errors generated.
Error while processing /home/user42/fuzzers/copy_5/llvm-csmith-5/llvm-fuzzer-build/fuzzer_ram-tmp//mutator-Tt4q9a.mutated.c.
```
It is a great result! Why? We generated a new fuzzed program via two mutators (constant-mutator and duplicate-mutator) and got new coverage: "#2362	NEW    cov: ". It is true even if you see errors printed. It means that the new coverage achieved in the parser or other front-end parts of the compiler, that's all. Nothing bad.

The results should look like this:
```
./6-run-csmith-tiny.sh
Starts Csmith 2023-05-25 12:31:43 and will end at 2023-05-25 12:32:43
End Fuzzing with Csmith. Generated 34 files in /home/user42/fuzzers/copy_5/llvm-csmith-5/csmith/../llvm-fuzzer-build/fuzzer-output-directory-prev/
```
Note: Polyglot works with an AFL-instrumented C compiler. Adding this to the docker container would impose a serious restriction on the size of the resultant tar (as the installation is over 100 GB). The authors of the paper do provide a docker image, which can be used to run the tool, and it follows our methodology.


	
	
	
	
	
# III. GrayC Artifact ISSTA 2023 - Phase 2

After you have successfully loaded our docker image, you can follow the instruction below to reproduce the results in Section 5 of our paper.

## III.A Results you can reproduce with this artifact

We now discuss how to reproduce the results with a short fuzzing campaign, each of which takes 10 minutes, for Section 5.
Note: in the paper, the fuzzing campaign is 24 hours long, repeated several times, which will bring the testing of this part to over 2000 hours of fuzzing (because we also have several different tools).
	
- Sets of test programs generated by each of the fuzzers in the evaluation
- Table 5: Throughput
- Figure 2: LLVM coverage
- Figure 2: GCC coverage
- Figure 3: LLVM middle-end coverage
- Figure 3: LLVM back-end coverage
- Table 6: BUG Rate in 24 hours

Seeds files for running fuzzers: we added some examples of such in [seeds folder](fuzzer/seeds) of the artifact because some fuzzers require seeds.

We give details below on how to reproduce each for the results. The scripts made no use of graphical terminals. Consequentially, the results are numbers and not the graphs in the paper. However, you can re-create these graphs and tables from the data (e.g. via Excel or GraphPad).

## III.B Detailed Instructions

Next, we describe the process of reproducing the tables and graphs' data for section 5 in the paper: the controlled experiments with the additional tools compared against GrayC's performance.

	
	
	
### Step-by-Step instructions

To reproduce the sets of test cases in Section 5.1, run the following scripts. 
These will run for 10 minutes each (a bit more than an hour for all the tools, as we skip PolyGlot).
In the docker image, run:
```
cd /home/user42/
```
You can see all the scripts to reproduce Section 5's results (ls -l).

**Build**. The fuzzers binaries are in /home/user42/fuzzers/copy_5/, but the data are in /home/user42/fuzzers/. 
The source code is in /home/user42/fuzzers/copy_5/llvm-csmith-5/llvm-source/tools/clang/tools/.
You can rebuild the code by:
```
cd /home/user42/fuzzers/copy_5/llvm-csmith-5/llvm-fuzzer-build
ninja
ninja clang-fuzzer
ninja grayc-aggressive
```
and for the rest of the tools (we compared them against several fuzzers):
```
ninja grayc-conservative
ninja regexp
ninja nofuss
```

	
	
	
**Test Case Generation** (Section 5.1). To generate the test programs with each of the fuzzers, starting with GrayC:
```
cd ~
./1-run-grayc-small.sh
mkdir GrayC
cp -r /home/user42/fuzzers/copy_5/llvm-csmith-5/llvm-fuzzer-build/fuzzer-output-directory-prev/* GrayC
```
and for the rest of the tools:
```
cd ~
./3-run-grayc-no-cov-guidance-small.sh
mkdir grayc-no-cov-guidance
cp -r /home/user42/fuzzers/copy_5/llvm-csmith-5/llvm-fuzzer-build/fuzzer-output-directory-prev/* grayc-no-cov-guidance

./4-run-grayc-fragments-fuzzing-small.sh
mkdir grayc-fragments
cp -r /home/user42/fuzzers/copy_5/llvm-csmith-5/llvm-fuzzer-build/fuzzer-output-directory-prev/* grayc-fragments

./5-run-clang-fuzzer-small.sh
mkdir clang-fuzzer
cp -r /home/user42/fuzzers/copy_5/llvm-csmith-5/llvm-fuzzer-build/fuzzer-output-directory-prev/* clang-fuzzer

./6-run-csmith-small.sh
mkdir csmith
cp -r /home/user42/fuzzers/copy_5/llvm-csmith-5/llvm-fuzzer-build/fuzzer-output-directory-prev/* csmith

./7-run-grammarinator-small.sh
mkdir grammarinator
cp -r /home/user42/fuzzers/copy_5/llvm-csmith-5/llvm-fuzzer-build/fuzzer-output-directory-prev/* grammarinator

./8-run-PolyGlot-small.sh
mkdir PolyGlot
cp -r /home/user42/fuzzers/copy_5/llvm-csmith-5/llvm-fuzzer-build/fuzzer-output-directory-prev/* PolyGlot

./9-run-RegExpMutator-small.sh
mkdir RegExpMutator
cp -r /home/user42/fuzzers/copy_5/llvm-csmith-5/llvm-fuzzer-build/fuzzer-output-directory-prev/* RegExpMutator
```
	
In addition to the above, we tried two experimental versions and have these installed in our artifact codebase because we believe these might be useful for future research; however, we did not get interesting results with these to include them fully in the artifact or the paper. You can also explore more conservative settings of GrayC via this script:
```
./2-run-grayc-conservative.sh
```
and a version of AFL compilers (no-fuss fuzzer work) embedded into LibFuzzer (excluding the AFL mechanism for dictionaries and other specific unique features of AFL):
```
./10-run-AFLCompiler.sh
```
Note: there is no AFL dictionary for C programming language.
	
Lastly, the experiments of **24 hours each**, repeated 10 times, can be reproduced with these scripts:	
```
./1-run-grayc.sh
./3-run-grayc-no-cov-guidance.sh
./4-run-grayc-fragments-fuzzing.sh
./5-run-clang-fuzzer.sh
./6-run-csmith.sh
./7-run-grammarinator.sh
./8-run-PolyGlot.sh
./9-run-RegExpMutator.sh
```
However, we do not expect the reviewers of the artifact to spend days running these scripts (each tool requires ten days(!!) of fuzzing).
	
	
	
	
**Throughput of Fuzzing** (Section 5.2). Next, we describe how to get the results for Section 5.2 and Table 5. For this, you need to use the results from *small.sh scripts.
Run the following scripts:
```
cd ~
./11-get-gen-comp-rate.sh GrayC
./11-get-gen-comp-rate.sh grayc-no-cov-guidance
./11-get-gen-comp-rate.sh grayc-fragments-fuzzing
./11-get-gen-comp-rate.sh clang-fuzzer
./11-get-gen-comp-rate.sh csmith
./11-get-gen-comp-rate.sh grammarinator
./11-get-gen-comp-rate.sh PolyGlot
./11-get-gen-comp-rate.sh RegExpMutator
```
Which outputs how many files are in the folder and how many **failed** compilations. For example:
```
./11-get-gen-comp-rate.sh grammarinator/
 Total files processed: 12
 Total files failing compilation: 12
	
./11-get-gen-comp-rate.sh csmith/
 Total files processed: 321
 Total files failing compilation: 0
```
Hence the compilation rate for Grammarinator is 0%, and for Csmith is 100%.
The rate is the number of hours the tool has run, dividing 12 and 321. 
	
	
	
	
**Coverage** (Section 5.3). We measure coverage for several sets when evaluating GrayC's ability to find additional new coverage in GCC-12 and LLVM-13. We measured the code coverage with gcov-10 and gfauto. Please check both are installed correctly before starting this part (including gcov, gcc and cc versions).

To generate Figure 2: You need to have 24 hours of fuzzing. To simplify the evaluation, the scripts below measure coverage only for the first hour only. The scripts for 24 hours are in the [coverage folder](testing/coverage).

The Docker image contains three files of the LLVM and GCC instrumented with coverage. You will need first to "un-tar" these to be able to measure coverage:
```
cd ~
tar -xf gcc-csmith-0.tar.gz
tar -xf gcc-csmith-1.tar.gz
tar -xf llvm-csmith-3.tar.gz
```
	
We provide two additional scripts to perform coverage runs on the provided <sets> for reproducibility. Run them using the following commands where `<sets>` is the path of the folder containing the fuzzer-generated sets.
```
./12-get-cov-gcc.sh <sets>
./13-get-cov-llvm.sh <sets>
```
Due to resource constraints in Docker images in general, we provide the aforementioned scripts that will allow for the coverage analysis to be carried out, but outside the Docker container. Check the [coverage](tools/coverage) folder for that.

With the pre-installed and pre-instrumented GCC compiler, you can expect this output inside the Docker image:
```
--> MEASURING COVERAGE... (20:27:14)
gfauto_cov_from_gcov --out run_gcov2cov.cov /home/user42//gcc-csmith-1/gcc-build/ --gcov_prefix_dir /home/user42//gcc-csmith-1/coverage_gcda_files/application_run/ --num_threads 32 --gcov_uses_json --gcov_functions >> gfauto.log 2>&1
gfauto_cov_from_gcov --out run_gcov2cov.cov /home/user42//gcc-csmith-1/gcc-build/ --gcov_prefix_dir /home/user42//gcc-csmith-1/coverage_gcda_files/application_run/ --num_threads 32 --gcov_uses_json >> gfauto.log 2>&1
total 5944
drwxr-xr-x 3 user42 user42    4096 May 26 20:27 cov.out
-rw-r--r-- 1 user42 user42  123691 May 26 20:27 gfauto.log
-rw-r--r-- 1 user42 user42 5951535 May 26 20:27 run_gcov2cov.cov
DONE. RESULTS (FUNCTION) AVAILABLE IN /home/user42//gcc-csmith-1/coverage_processed/x-0 for testcase </home/user42/grammarinator/test_96941268143176749374817493219626218736.c> (20:27:49)
DONE. RESULTS (LINE) AVAILABLE IN /home/user42//gcc-csmith-1/coverage_processed/x-line-0 for testcase </home/user42/grammarinator/test_96941268143176749374817493219626218736.c> (20:27:49)
rm: cannot remove 'a.out': No such file or directory
Get statistics for functions
rm: cannot remove '/home/user42/GCC-coverage/gcc-func-cov-out.csv': No such file or directory
rm: cannot remove 'list_gcov.txt': No such file or directory
Get statistics for lines
rm: cannot remove '/home/user42/GCC-coverage/gcc-line-cov-out.csv': No such file or directory
rm: cannot remove 'list_gcov.txt': No such file or directory
Results are in GCC-coverage folder. Summary of it below:
>> Total of files in coverage report: 151
Total files in /home/user42//gcc-csmith-1/coverage_processed/x-0/cov.out/: <2115>
 >> End extracting data for 2115 files.
#line 1 ................. ==> 4472800
#line 1 HIT ............. ==> 2461
Total files in /home/user42//gcc-csmith-1/coverage_processed/x-line-0/cov.out/: <2115>
 >> End extracting data for 2115 files.
#line 1 ................. ==> 4472800
#line 1 HIT ............. ==> 26200
user42@7a15342fc0b2:~$ 
```
Here we covered 26,200 lines in the GCC codebase with a set of fuzzed programs from Grammarinator.	
	
	
	
**Bug Finding (Crash testing only)** (Section 5.4). To check if a set of programs \<set-of-programs\> detects crashes in LLVM and GCC, run the script:
```
cd ~/fuzzers/crash-testing 
./8-testing_all.sh <set-of-programs> <output-folder> <log-file> <includes> > crash-testing.log 2>&1
```
For example:
```
cd ~/fuzzers/crash-testing 
./8-testing_all.sh /home/user42/grammarinator/ /home/user42/fuzzers/crash-testing/output /home/user42/fuzzers/crash-testing/output/output.log  "-I/home/user42/fuzzers/copy_5/llvm-csmith-5/csmith/runtime/ -I/home/user42/fuzzers/copy_5/llvm-csmith-5/csmith/build/runtime/" > crash-testing_grammarinator.log 2>&1
```
The rest of the bug report classification happens in Bugzilla and other reporting platforms and hence cannot be scripted.
	
	
	
	
# IV. Reusability of GrayC - Additional details
	
Firstly, GrayC can be used to detect bugs in mature compilers like GCC and LLVM. 
	
Secondly, we believe the data and the scripts are useful for the compiler testing community, like the coverage scripts and the installation of other fuzzers built on top of LibFuzzer. We shared all scripts for other researchers to use.

Thirdly, the artifact is highly automated and easy to use. Moreover, we believe our automated scripts are valuable (in general) for any project on testing C compilers and code analysers. Not many code coverage fully automated scripts are available online, and we hope this artifact will help close this gap. The scripts can be extended to support other compilers and code analysers, easily.

Lastly, the artifact is comprehensively documented. Each folder contains an extended README.md file to elaborate further on how to use our code.
	
We discuss below the structure of the source code of GrayC and give detailed instructions on how to build the tool from the source. Note that compilers such as LLVM and GGC are very complex pieces of code; hence the build process of these with instrumentation is a heavy task, by definition. It can take several hours, even on a machine with 16 GB RAM. We recommend adding swap files.

## IV.A GrayC

GrayC is a greybox fuzzer for C compilers and analysers and is a libfuzzer-based tool. In brief, GrayC works as follows. Starting with an initial corpus of test programs, it uses libfuzzer to perform coverage-guided mutation-based fuzzing of the Clang/LLVM compiler for a time-limited period. Unconventionally, the purpose of this use of libfuzzer is not to find bugs at this stage but rather to generate a large corpus of interesting test programs. It is achieved by (a) using a custom mutator to yield an interesting space of compiler test programs that are statically-valid, and (b) saving every test program that libfuzzer produces to an external directory.

After the fuzzing run has been completed, GrayC processes this external directory of test programs to test compilers (scripts) and code analysers and to extract new UB-free test programs for compiler test suites (via the enhanCer).

Implementation Details: we have implemented our approach as a set of tools, the direct coverage fuzzer, GrayC, the program transformer, enhanCer, and a set of bash scripts for a crash and differential testing. GrayC and the code analysis part of enhanCer were implemented in the LLVM 12.0.1 Framework with additional C/C++ code implementing our mutators on top of ClangFuzzer/libtooling. The enhanCer code transformation was implemented in python3 with a set of bash scripts.

	
## IV.B Software Requirements

*For installing from source,* you will need to install the following: gcc, gcov, g++, flex, bison, binutils, git, python3, python3-pip, gfauto (under Google's graphicsfuzz), cmake, m4, ninja-build, curl, wget, zip, unzip, frama-c, creduce, openSSL (libcurl4-openssl-dev, libssl-dev), frama-c, creduce, grammarinator. 

Note 1: CMake 3.13.4 or higher is required.

Note 2: GCC-10 or higher is required. We have tested our artifact with GCC-10 and GCC-11.

Most of the packages required can be installed with (e.g.) brew or apt, however, some need to be built from source.
1. gfauto: https://github.com/google/graphicsfuzz.git
2. remove-parens (Git version: 1b2c68e): https://github.com/mc-imperial/remove-parens
	
### gfauto tool
If you don't have gfauto installed, please follow the instructions here: https://github.com/google/graphicsfuzz.
You can try the following instruction we used to set up the tool:
```
git clone https://github.com/google/graphicsfuzz.git
cd graphicsfuzz/gfauto/
vi dev_shell.sh.template
EDIT TO YOUR LOCAL VERSION of Python3: PYTHON=${PYTHON-python3.6}
rm Pipfile.lock (if Python3.8 or above)
./dev_shell.sh.template
```

### remove-parens tool
Please follow the instructions here to install a small utility we use remove-parens tool:
```
git clone https://github.com/mc-imperial/remove-parens
cd remove-parens/third_party/
wget https://github.com/llvm/llvm-project/releases/download/llvmorg-13.0.1/clang+llvm-13.0.1-x86_64-linux-gnu-ubuntu-18.04.tar.xz
tar -xf clang+llvm-13.0.1-x86_64-linux-gnu-ubuntu-18.04.tar.xz
rm clang+llvm-13.0.1-x86_64-linux-gnu-ubuntu-18.04.tar.xz
mv clang+llvm-13.0.1-x86_64-linux-gnu-ubuntu-18.04 clang+llvm-13.0.1
ls -l clang+llvm-13.0.1
cd ../
mkdir build
cd build
cmake -G Ninja ..
ninja
```
	
A full installation of the artifact can be at least 60 GB and the experiments can take up to 100 GB as coverage information on LLVM and GCC can take many GBs.
	
	
## IV.C General Information - No Action Needed with Docker Image

We first describe the exact set-up of our machines for the controlled experiments.
Our docker image has all of them installed. We also supply [scripts to install each](testing), even if it is not our software.

During our evaluation, we installed the following tools (with the exact versions used in the experiments)
 1. Experiments on LLVM 12.0.1 (version from the 4th of October 2021)
 2. ninja 1.8.2
 3. cmake 3.20.0
 4. fdupes 1.6.1
 5. remove-parens (Git version: 1b2c68e)
 6. flex 2.6.4
 7. m4 1.4.18

We are comparing against many other fuzzers in our experiments. Here are links to their Git repositories.

### Evaluation with:
 1. Csmith 2.4.0: https://github.com/csmith-project/csmith
 2. ClangFuzzer/LLVM v12.0.1 x86: https://github.com/llvm-mirror/llvm/blob/master/docs/LibFuzzer.rst
 3. universalmutator v1.0.18: Regexp-based tool for mutating generic source code across numerous languages.
    
    3.1. GitHub https://github.com/agroce/universalmutator
    
    3.2. GitHub 1.0.18 release https://github.com/agroce/universalmutator/releases/tag/v1.0.18  
 4. Grammarinator version grammarinator-generate 19.3
    
    4.1. GitHub https://github.com/renatahodovan/grammarinator
    
    4.2. Pip https://pypi.org/project/grammarinator/
 5. PolyGlot from GitHub: https://github.com/s3team/Polyglot
	
NOTE: Polyglot was taken from the GitHub project with a few modifications made to the readme for a successful install, based on correspondence with the authors. Specifically, the clang compiler was supposed to be built with regular afl and then was supposed to be fuzzed by the polyglot binary available in the afl_replace_mutate folder.

Most of them are available via apt in Ubuntu OS or via pip but also easy to install from source. For example to install Grammarinator, run:
```
pip3 install grammarinator
```
Note: Csmith requires also m4; we used m4 1.4.18.

We measured the throughput of GrayC and other fuzzers on a 2-core, 8 GB, Intel, Ubuntu 20.04 virtual machine, for 24 hours.

	
## IV.D Build from Source and Project's Structure
GrayC was implemented on top of LibFuzzer, so its build may take a long, depending on your machine: it builds LLVM 12 with instrumentation.

Please follow the instructions in this README.md file (under GrayC/ISSTA-2023-AE/fuzzer/README.md).
```
nano GrayC/ISSTA-2023-AE/fuzzer/README.md
```	

The project contains several folders.
	
The [fuzzer](fuzzer) folder contains the code of GrayC and instructions on how to install GrayC with a detailed inner structure at the end of its [README.md](fuzzer/README.md) file.
	
The [data](data) folder contains all the logs and outputs collected during testing with the fuzzers. Larger files are omitted from the GitHub Repository but can be found in [our artifact in Zenodo](https://zenodo.org/record/7967714).

The [testing](testing) folder contains extra scripts to build instruments with coverage compilers and to install some of the fuzzers and code analysers used here. The code of our artifact with all the scripts in the Docker image is [here](ae-source-code).
