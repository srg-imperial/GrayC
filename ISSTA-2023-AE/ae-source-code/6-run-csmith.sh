#!/bin/bash

# Run Csmith
#cd /home/user42/fuzzers/copy_6/llvm-csmith-6/csmith/build

# Run in a loop for X time
#./csmith

csmith_location=/home/user42/fuzzers/copy_5/llvm-csmith-5/csmith			# csmith location
output_folder=$csmith_location/../llvm-fuzzer-build/fuzzer-output-directory-prev/	# where to put all the generated programs
genrator=$csmith_location/build/src/csmith
csmith_flags=" --bitfields --packed-struct "

rm -rf $output_folder
mkdir -p $output_folder
i=0

curr_ts=`date -d '+0 day +0 hour +0 minutes' '+%F %T'`
end_ts=`date -d '+0 day +24 hour +0 minutes' '+%F %T'`
echo "Starts Csmith $curr_ts and will end at $end_ts"

curr_total=`date -d "$curr_ts" +%s`
end_total=`date -d "$end_ts" +%s`
while [ "$curr_total" -lt "$end_total" ] ; do
	timestamp=`date +"%m-%d-%y-%T"`
	# Generate a test case; for example: fuzzer-file-0-2023-05-22-20:46:47.c
	(ulimit -St 50; $genrator $csmith_flags > $output_folder/fuzzer-file-$i-$timestamp.c)
	i=$((i+1)) # Update index of test cases
	curr_ts=`date -d '+0 day +0 hour +0 minutes' '+%F %T'` # Update current
	curr_total=`date -d "$curr_ts" +%s`
done
x=`ls -l $output_folder/*.c | wc -l`
echo "End Fuzzing with Csmith. Generated $x files in $output_folder"
