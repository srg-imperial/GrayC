#!/bin/bash
build=$1	#  /home/user42/git/copy_1/llvm-csmith-1/llvm-fuzzer-build/
setA=$2		#  /home/user42/git/copy_1/llvm-csmith-1/../setA/
seeds=$3	#  /home/user42/git/directed-compiler-fuzzing-code/scripts/4-reduce-general-spots-reaching-files/seeds_out6.txt

# Use this script to run GrayC for 24 Hours, or any other fuzzer that is LibFuzzer based
cd $build
mkdir $build/fuzzer-output-directory-prev/
while IFS= read -r seed ; do
	timestamp=`date +"%m-%d-%y-%T"`
	echo "Running Fuzzer with seed $seed $timestamp"
	(bin/clang-fuzzer $setA -detect_leaks=0 -max_len=1000000 -rss_limit_mb=4096 -create_missing_dirs=1 -ignore_crashes=1 -ignore_timeouts=1 -ignore_ooms=1 -seed=$seed -timeout=50 -max_total_time=8640
0)

	# Keep the data and prepare for re-run
	fdupes -dN $setA # Remove duplicates
	tar -czvf $build/fuzzed-files-$seed.tar.gz $build/fuzzer-output-directory/ > tar_prev_$seed.txt 2>&1

	#cp $build/fuzzer-output-directory/* $build/fuzzer-output-directory-prev/
	for i in $build/fuzzer-output-directory/*; do
		echo "Copy to PREV. $i"
		cp "$i" $build/fuzzer-output-directory-prev/
	done
done < "$seeds"
