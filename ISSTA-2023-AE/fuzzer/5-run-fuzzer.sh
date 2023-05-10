#!/bin/bash
build=$1	#  /home/user42/git/copy_1/llvm-csmith-1/llvm-fuzzer-build/
setA=$2		#  /home/user42/git/copy_1/llvm-csmith-1/../setA/
seeds=$3	#  /home/user42/git/GrayC-AE/scripts/4-reduce-general-spots-reaching-files/seeds_out6.txt

cd $build
while IFS= read -r seed ; do
	echo "Running Fuzzer with seed $seed"
	##echo "bin/clang-fuzzer $setA -detect_leaks=0 -max_len=1000000 -rss_limit_mb=4096 -create_missing_dirs=1 -ignore_crashes=1 -ignore_timeouts=1 -ignore_ooms=1 -seed=$seed"
	bin/clang-fuzzer $setA -detect_leaks=0 -max_len=1000000 -rss_limit_mb=4096 -create_missing_dirs=1 -ignore_crashes=1 -ignore_timeouts=1 -ignore_ooms=1 -seed=$seed

	# Keep the data and prepare for re-run
	fdupes -dN $setA # Remove duplicates
	tar -czvf fuzzed-files-$seed.tar.gz fuzzer-output-directory-fuzzed-files/
done < "$seeds"
