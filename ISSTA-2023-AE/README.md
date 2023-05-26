# I. GrayC: Greybox Fuzzing of Compilers and Analysers for C

This repository contains the data and code to reproduce the results in the paper "GrayC: Greybox Fuzzing of Compilers and Analysers for C".

## Experiment logs and Data:

Please see these links for bug reports and raw data [for the whole paper](data) and for [section 4](data/Evaluation/USING-GRAYC-IN-THE-WILD) and [section 5](data/Evaluation/EVALUATION-VIA-CONTROLLED-EXPERIMENTS/Bug-finding-trails). In addtion we included all the sets generated with the tools in the evaluation in our artifact as [10-sets-of-test-programs-tool-name.zip](https://zenodo.org/record/7967714).

NOTE: A copy of this README is in the working directory of the Docker image, ~/grayc/ISSTA-2023-AE/README.md.

## Test Contribution
 
We used the coverage measured for the whole llvm test suite (and compared it to our own fuzzed programs code coverage on the LLVM compiler) to find a newly covered code by our fuzzed programs and contribute them to the LLVM test suite.

We first measured coverage for the whole [LLVM test suite](https://github.com/llvm/llvm-test-suite) using the set of [scripts](testing/coverage). We then measured coverage with our fuzzed corpus, filtering statically or dynamically invalid programs, crossed with the coverage of the LLVM test suite, and reduced the test case if possible. The report data is available [here](data/Evaluation/USING-GRAYC-IN-THE-WILD/LLVM-test-contributions).
	
	
	
	

# II. GrayC Artifact ISSTA 2023 - Phase 1

## II.A Loading the Docker Image

This Docker image contains a pre-built version of GrayC. It also includes all the tools we compared against in our controlled evaluation and the setting up of GrayC. To start the docker container:
```
cat GrayC-v1.tar | docker import - grayc-artifact 
docker run -i -t grayc-artifact  /bin/bash
```

Then you need to run all the experiments as user42 (just a random user name we picked for this artifact!). 
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
After installation the docker image will be 70 GB. The GrayC-v1.tar is 20 GB before any installation.

We recommend using our docker image since we are testing mature C compilers (i.e. the instrumented code is 50 GB).

If you do not wish to use a docker image, we discuss later how to install GrayC from source (last section of this artifact).

## II.B Steps to check the basic functionality of the artifact

Once you load and attached the docker image of GrayC artifact, do the following to test all is working:

1. Inside the docker the main user is user42, not root. Please do not switch to root.
2. Run the following for each of the tools in our controlled experiments. There are several fuzzers in this study.
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
The *tiny.sh scripts run each for 1 minute. Do not worry if not all fuzzers produced data, as some of them (like Clang-fuzzer) has a longer loading time.

DO NOT WORRY IF YOU GET C ERROR MESSAGES. we test C compilers, and hence do bad things to it. However, if you fuzzer does not start or stop suddenly, please contact us. For example, this is a normal output when fuzzing compilers:
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
This is great results! why? We generated a new fuzzed program via two mutators (constant-mutator and duplicate-mutator) and got new coverage: "#2362	NEW    cov: ". It is true even if you see errors printed. It means that the new coverage achieved in the parser or other front-end parts of the compiler, that's all. Nothing bad.

The results should look like this:
```
./6-run-csmith-tiny.sh
Starts Csmith 2023-05-25 12:31:43 and will end at 2023-05-25 12:32:43
End Fuzzing with Csmith. Generated 34 files in /home/user42/fuzzers/copy_5/llvm-csmith-5/csmith/../llvm-fuzzer-build/fuzzer-output-directory-prev/
```
Note: Polyglot works with an AFL-instrumented C compiler. Adding this to the docker container would impose a serious restriction on the size of the resultant tar (as the install is over 100Gb). The authors of the paper do provide a docker image which can be used to run the tool and it follows our methodology.


	
	
	
	
	
# III. GrayC Artifact ISSTA 2023 - Phase 2

After you have successfully loaded our docker image (or installed it from source GrayC), you can follow the instruction below to reproduce the results in Section 5 of our paper.

## III.A Results you can reproduce with this artifact

We now discuss how to reproduce the results with a short fuzzing campaign, each of which takes 10 minutes, for Section 5.
Note: in the paper, the fuzzing campaign is 24 hours long, repeated several times, which will bring the testing of this part to over 2000 hours of fuzzing (because we also have several different tools).
	
- Table 5: Throughput
- Figure 2: LLVM coverage
- Figure 2: GCC coverage
- Figure 3: LLVM middle-end coverage
- Figure 3: LLVM back-end coverage
- Table 6: BUG Rate in 24 hours

Seeds files for running fuzzers: we added some examples of such in [seeds folder](fuzzer/seeds) of the artifact because some fuzzers require seeds.

We give details below on how to reproduce each for the results. The scripts made no use of graphical terminals. Consequentially, the results are numbers and not the graphs in the paper. However, you can re-create these graphs and table from the data (e.g. via Excel or GraphPad).

## III.B Detailed Instructions

Next, we describe the process of reproducing the tables and graphs' data for section 5 in the paper: the controlled experiments with the additional tools compared against GrayC's performance.

	
	
	
### Step-by-Step instructions

To reproduce the sets of test cases in Section 5.1, run the following scripts. 
These will run for 10 minutes each (a bit more than an hour for all the tools, as we skip PolyGlot).
In the docker image run:
```
cd /home/user42/
```
You can see all the scripts to reproduce Section 5's results (ls -l).

**Build**. The fuzzers are installed in /home/user42/fuzzers/copy_5/, but the data are in /home/user42/fuzzers/. 
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
	
In addition to the above, we tried two experimental versions and have these installed in our artifact codebase because we believe these migh be useful for future research; however, we did not get interesting results with these to include them fully in the artifact or the paper. You can also explore more conservative settings of GrayC via this script:
```
./2-run-grayc-conservative.sh
```
and a version of AFL compilers (no-fuss fuzzer work) embedded into LibFuzzer (excluding the AFL mechanism for dictionaries and other specific unique fetchures of AFL):
```
./10-run-AFLCompiler.sh
```
Note: there is no AFL dictionary for C programming language.
	
Lastly, the full experiments, of **24 hour each**, repeated 10 times, can be reproduce with these scripts:	
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
However, we do not expect the reviewers of the artifact to spend days to run these scripts (each tools requires 10 days(!!) of fuzzing).
	
	
	
	
**Throughput of Fuzzing** (Section 5.2). Next, we describe how to get the results for Section 5.2 and Table 5. For this you need to use the results from *small.sh scripts.
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
Which outputs how many files are in the folder and how many **failed** compilation. For example:
```
./11-get-gen-comp-rate.sh grammarinator/
 Total files processed: 12
 Total files failing compilation: 12
	
./11-get-gen-comp-rate.sh csmith/
 Total files processed: 321
 Total files failing compilation: 0
```
Hence the compilation rate for Grammarinator is 0% and for Csmith is 100%.
The rate is the number of hours ran dividing 12 and 321. 
	
**Coverage** (Section 5.3). We measure coverage for several sets when evaluationg GrayC ability to find additional new coverage in GCC-12 and LLVM-13. We measure coveage with gcov-10 and gfauto. Please check both are installed correctly before starting this part (including gcov, gcc and cc versions).

The Docker image contains 3 files of the LLVM and GCC instrumented with coverage. You will need first to "un-tar" these to be able to measure coverage:
```
cd ~
tar -xf gcc-csmith-0.tar.gz
tar -xf gcc-csmith-1.tar.gz
tar -xf llvm-csmith-2.tar.gz
```
	
We provide 2 additional scripts to perform coverage runs on the provided <sets> for reproducibility. They can be run using the following commands where `<sets>` is the path of the folder containing the fuzzer-generated sets.
```
./12-get-cov-gcc.sh <sets>
./13-get-cov-llvm.sh <sets>
```
Due to resource constraints, we provide the aforementioned scripts that will allow for the coverage analysis to be carried out, but outside the docker container. 

	
	
# IV. Reusability of GrayC - Additional details
	
First of all, GrayC can use to detect bugs in mature compilers. We discuss below the structure of the source code of GrayC and give detailed instructions on how to build the tool from the source. Note that compilers such as LLVM and GGC are very complex pieces of code; hence the build process of these with instrumentation is a heavy task, by definition. It can take several hours, even on a machine with 16 GB RAM. We recommend adding swap files.

Second, we believe the data and the scripts are very useful for the compiler testing community as the coverage scripts and the installation of all the other fuzzers on top of LibFuzzer. We shared all our scripts here for other researchers to use.
	
## IV.A GrayC

GrayC is a greybox fuzzer for C compilers and analysers and is a libfuzzer-based tool. In brief, GrayC works as follows. Starting with an initial corpus of test programs, it uses libfuzzer to perform coverage-guided mutation-based fuzzing of the Clang/LLVM compiler for a time-limited period. Unconventionally, the purpose of this use of libfuzzer is not to find bugs at this stage but rather to generate a large corpus of interesting test programs. It is achieved by (a) using a custom mutator to yield an interesting space of compiler test programs that are statically-valid, and (b) saving every test program that libfuzzer produces to an external directory.

After the fuzzing run has completed, GrayC processes this external directory of test programs to test compilers (scripts) and code analysers and to extract new UB-free test programs for compilers test suites (via the enhanCer).

Implementation Details: we have implemented our approach as a set of tools, the direct coverage fuzzer, GrayC, the program transformer, enhanCer, and a set of bash scripts for crash and differential testing. GrayC and the code analysis part of enhanCer were implemented in the LLVM 12.0.1 Framework with additional C/C++ code implementing our mutators on top of ClangFuzzer/libtooling. The enhanCer code transformation was implemented in python3 with a set of bash scripts.

	
## IV.B Software Requirements

*For installing from source,* you will need to install the following: gcc, gcov, g++, flex, bison, binutils, git, python3, python3-pip, gfauto (under Google's graphicsfuzz), cmake, m4, ninja-build, curl, wget, zip, unzip, frama-c, creduce, openSSL (libcurl4-openssl-dev, libssl-dev), frama-c, creduce, grammarinator. 

Note 1: CMake 3.13.4 or higher is required.

Note 2: GCC-10 or higher is required. We have tested our artifact with GCC-10 and GCC-11.

Most of the packages required can be installed with (e.g.) brew or apt, however, some need to be build from source.
1. gfauto: https://github.com/google/graphicsfuzz.git
2. remove-parens (Git version: 1b2c68e): https://github.com/mc-imperial/remove-parens
	
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

We first describe the exact set up of our machines for the controlled experiments.
Our docker image has all of them installed. We also supply [scripts to install each](testing), even if it is not our software.

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
 1. Csmith 2.4.0: https://github.com/csmith-project/csmith
 2. ClangFuzzer/LLVM v12.0.1 x86: https://github.com/llvm-mirror/llvm/blob/master/docs/LibFuzzer.rst
 3. universalmutator v1.0.18: Regexp based tool for mutating generic source code across numerous languages.
    
    3.1. GitHub https://github.com/agroce/universalmutator
    
    3.2. GitHub 1.0.18 release https://github.com/agroce/universalmutator/releases/tag/v1.0.18  
 4. Grammarinator version grammarinator-generate 19.3
    
    4.1. GitHub https://github.com/renatahodovan/grammarinator
    
    4.2. Pip https://pypi.org/project/grammarinator/
 5. PolyGlot: TODO

Most of them are available via apt in Ubuntu OS or via pip but also easy to install from source. For example to install Grammarinator, run:
```
pip3 install grammarinator
```
Note: Csmith requires also m4; we used m4 1.4.18.

We measured the throughput of GrayC and other fuzzers on 2-core, 8 GB, Intel, Ubuntu 20.04, virtual machine for 24 hours.

	
## IV.D Build from Source and Project's Structure
GrayC was implemented on top of LibFuzzer, and so its build may take long, depending on your machine: it builds LLVM 12 with instrumentation.

Please follow the instructions in this README.md file (under GrayC/ISSTA-2023-AE/fuzzer/README.md).
```
nano GrayC/ISSTA-2023-AE/fuzzer/README.md
```	

The project contains several folders.
	
The [fuzzer](fuzzer) folder contains the code of GrayC and instructions how to install GrayC with a detailed inner structure at the end of its [README.md](fuzzer/README.md) file.
	
The [data](data) folder contains all the logs and outputs collected during testing with the fuzzers. Larger files are omitted from the GitHub Repository, but can be found in [our artifact in Zenodo](https://zenodo.org/record/7967714).

The [testing](testing) folder contains extra scripts to build instrumented with coverage compilers and to install some of the fuzzers and code analysers used here.
