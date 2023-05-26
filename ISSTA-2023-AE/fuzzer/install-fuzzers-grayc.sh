#!/bin/bash

base=$1		# /home/user42/
llvm=$2		# /home/user42/.sources_12VL.9IeP8DH.tmp
dcovsrc=$3	# /home/user42/GrayC/ISSTA-2023-AE
copies=$4	# 3
## ./install-fuzzers-grayc.sh /home/user42/ /home/user42/.sources_12VL.9IeP8DH.tmp /home/user42/GrayC/ISSTA-2023-AE 3

current_folder=`pwd`
copy_folder="$base/copy_"
src="$dcovsrc/AE/tool/src/"
llvm_local="llvm-csmith-"

echo "base=$1"		# /home/user42/
echo "llvm=$2"		# /home/user42/.sources_12VL.9IeP8DH.tmp
echo "dcovsrc=$3"	# /home/user42/GrayC/ISSTA-2023-AE
echo "copies=$4"	# 3

## Install remove-parens util
echo "Installing fuzzers in $base"
if [ -d $base/remove-parens/third_party/ ]
then
	echo ">> Found remove-parens installation in $base/remove-parens/. Skip installation of remove-parens util."
else
	echo ">> Install remove-parens util."
	cd $base
	git clone https://github.com/mc-imperial/remove-parens
	cd remove-parens/third_party/
	wget https://github.com/llvm/llvm-project/releases/download/llvmorg-13.0.1/clang+llvm-13.0.1-x86_64-linux-gnu-ubuntu-18.04.tar.xz
	tar -xf clang+llvm-13.0.1-x86_64-linux-gnu-ubuntu-18.04.tar.xz
	rm clang+llvm-13.0.1-x86_64-linux-gnu-ubuntu-18.04.tar.xz
	mv clang+llvm-13.0.1-x86_64-linux-gnu-ubuntu-18.04 clang+llvm-13.0.1
	ls -l clang+llvm-13.0.1
	cd $base/remove-parens/
	mkdir build
	cd build
	cmake -G Ninja ..
	ninja
fi

## Install copies of the fuzzer - to run parallel GrayC you need to install more than one copy.
## Note: the default GrayC shall run with a single copy.
cd $current_folder
for (( i=1; i<=${copies}; i++ )) ; do
	c=$copy_folder$i
	l=$c/$llvm_local$i
	echo "Installing Copy $i in <$l>"
	./2-prepare-env.sh $c $llvm $i
	./3-copy-fuzzer-agg.sh $src $l $c
	./4-build-fuzzer.sh $l
done
