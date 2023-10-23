#!/bin/bash
shopt -s extglob # Activate extended pattern matching in bash

#### This is a version for using LLVM with re-compilation of code with asserts(0) ####
#### First time will take longer, but re-build is quick. No coverage. ####

working_folder=$1 		## base folder
TMP_SOURCE_FOLDER=$2 		## Where is your llvm source code?
nb_processes=$3 		## which copy?

## Assure we are in gcc-11!
sudo apt install gcc-11 g++-11
sudo update-alternatives --install /usr/bin/gcc gcc /usr/bin/gcc-11 1100 --slave /usr/bin/g++ g++ /usr/bin/g++-11 --slave /usr/bin/gcov gcov /usr/bin/gcov-11
sudo rm -f /usr/bin/cpp /usr/bin/gcc /usr/bin/g++ /usr/bin/gcov
sudo rm -f /usr/local/bin/cpp /usr/local/bin/gcc /usr/local/bin/g++ /usr/local/bin/gcov
sudo ln -s /usr/bin/cpp-11 /usr/bin/cpp
sudo ln -s /usr/bin/gcc-11 /usr/bin/gcc
sudo ln -s /usr/bin/g++-11 /usr/bin/g++
sudo ln -s /usr/bin/gcov-11 /usr/bin/gcov
echo ">> End Settings"

timeB=$(date +"%T")
echo ">> Start Script <$timeB>"

# Copying LLVM source and Csmith exe to parallel execution folders, then install LLVM with coverage data in each folder
i=$nb_processes

### Create a working folder with LLVM source
rm -rf $working_folder/llvm-csmith-$i 	## Remove the old version
mkdir $working_folder/llvm-csmith-$i	## Create a new version
cp -rf $TMP_SOURCE_FOLDER/* $working_folder/llvm-csmith-$i	## Copy the data from the temp download folder

### Update Csmith settings
mkdir -p $working_folder/llvm-csmith-$i/csmith/scripts/ ## Just incase it isn't there
cd $working_folder/llvm-csmith-$i
mkdir -p ./csmith/scripts/
echo $working_folder/llvm-csmith-$i"/llvm-install/usr/local/bin/clang -O3" > $working_folder/llvm-csmith-$i/csmith/scripts/compiler_test.in

## Save information regarding the version and how we compile it
mkdir compilation_info
echo " - date: $(date '+%Y-%m-%d at %H:%M.%S')" > $working_folder/llvm-csmith-$i/compilation_info/llvm-version.txt
echo " - host name $(hostname -f)" >> $working_folder/llvm-csmith-$i/compilation_info/llvm-version.txt
echo " - current path: $(pwd)" >> $working_folder/llvm-csmith-$i/compilation_info/llvm-version.txt
gcc-11 --version >> $working_folder/llvm-csmith-$i/compilation_info/llvm-version.txt
g++-11 --version >> $working_folder/llvm-csmith-$i/compilation_info/llvm-version.txt
gcov-11 --version >> $working_folder/llvm-csmith-$i/compilation_info/llvm-version.txt
cpp-11 --version >> $working_folder/llvm-csmith-$i/compilation_info/llvm-version.txt
/usr/bin/cc --version >> $working_folder/llvm-csmith-$i/compilation_info/llvm-version.txt
/usr/bin/c++ --version >> $working_folder/llvm-csmith-$i/compilation_info/llvm-version.txt

### LLVM PART: with instrumentation
# Setting the env. + cov.
{
	mkdir llvm-build llvm-install
	cd ./llvm-build
	set CFLAGS='--coverage -ftest-coverage -fprofile-arcs -fno-inline'
	set CXXFLAGS='--coverage -ftest-coverage -fprofile-arcs -fno-inline'
	set LDFLAGS='-lgcov --coverage -ftest-coverage -fprofile-arcs'
	set CXX=g++-11
	set CC=gcc-11

	# Cmake and build of LLVM
	timeS=$(date +"%T")
	echo "Configuration: cmake -GNinja ../llvm-source -DCMAKE_BUILD_TYPE=Release -DLLVM_TARGETS_TO_BUILD=X86 -DLLVM_BUILD_EXAMPLES=OFF -DLLVM_BUILD_TESTS=OFF -DLLVM_BUILD_DOCS=OFF -DCMAKE_C_FLAGS=--coverage -DCMAKE_CXX_FLAGS=--coverage -DCMAKE_EXE_LINKER_FLAGS=--coverage <$timeS>" >> $working_folder/llvm-csmith-$i/compilation_info/llvm-version.txt
	cmake -GNinja ../llvm-source -DCMAKE_BUILD_TYPE="Release" -DLLVM_TARGETS_TO_BUILD="X86" -DLLVM_BUILD_EXAMPLES="OFF" -DLLVM_BUILD_TESTS="OFF" -DLLVM_BUILD_DOCS="OFF" -DCMAKE_C_FLAGS="--coverage" -DCMAKE_CXX_FLAGS="--coverage" -DCMAKE_EXE_LINKER_FLAGS="--coverage" > $working_folder/llvm-csmith-$i/compilation_info/config_output.txt 2>&1
	timeB=$(date +"%T")
	echo ">> Build LLVM with ninja to ./llvm-build <$timeB>"
	ninja > $working_folder/llvm-csmith-$i/compilation_info/build_output.txt 2>&1
	ninja check-clang >> $working_folder/llvm-csmith-$i/compilation_info/build_output.txt 2>&1
	grep "FAILED:" $working_folder/llvm-csmith-$i/compilation_info/build_output.txt
	timeI=$(date +"%T")
	echo ">> Install LLVM locallly with ninja to ./llvm-install <$timeI>"
	DESTDIR=../llvm-install ninja install -k 10 > $working_folder/llvm-csmith-$i/compilation_info/install_output.txt 2>&1
	grep "FAILED:" $working_folder/llvm-csmith-$i/compilation_info/install_output.txt

	# Cleaning after build
	unset CFLAGS
	unset CXXFLAGS
	unset LDFLAGS
	unset CXX
	unset CC
}
cd .. ; cd ..
timeT=$(date +"%T")
echo ">> Create .tar of LLVM local installation <$timeT>"
tar -czvf llvm-csmith-$i.tar.gz llvm-csmith-$i/ >> $working_folder/llvm-csmith-$i/compilation_info/install_output.txt 2>&1
timeE=$(date +"%T")
echo "Done. <$timeE>"
