#!/bin/bash
base=$1       	# /home/user42/git
seeds_folder=$2	# seeds folder: /home/user42/git/GrayC-AE/scripts/4-reduce-general-spots-reaching-files/
copies=$3       # 3

for (( i=1; i<=${copies}; i++ )) ; do
	build=$base/copy_$i/llvm-csmith-$i/llvm-fuzzer-build/	#  /home/user42/git/copy_1/llvm-csmith-1/llvm-fuzzer-build/
	setA=$build/../../setA/					#  /home/user42/git/copy_1/llvm-csmith-1/../setA/
	seeds=$seeds_folder/seeds_out$i.txt        		#  /home/user42/git/GrayC-AE/scripts/4-reduce-general-spots-reaching-files/seeds_out6.txt

        echo "Launch Copy $i in <$build>"
	(./5-run-fuzzer.sh $build $setA $seeds) > $base/run_copy_$i.log 2>&1 & # Run the background
	##echo "head $base/run_copy_$i.log"
	head $base/run_copy_$i.log
	echo "===="
done
