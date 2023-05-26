#!/bin/bash
build=/home/user42/fuzzers/copy_5/llvm-csmith-5/llvm-fuzzer-build/
setA=/home/user42/fuzzers/copy_5/setA/
setB=/home/user42/fuzzers/copy_5/setB/
seeds=/home/user42/seeds/seeds_out5.txt

# Set the coprus to be as in the expriments
cd $build/../../ ; rm -rf $setA $setB; cp -r setA-12-Nov-21 $setA ; cp -r setB-12-Nov-21 $setB


# Start the running for 24 Hours
curr_ts=`date -d '+0 day +0 hour +0 minutes' '+%F %T'`
end_ts=`date -d '+0 day +0 hour +10 minutes' '+%F %T'`
echo "Starts RegExp (UM) $curr_ts and will end at $end_ts"
end_total=`date -d "$end_ts" +%s`

# Use this script to run RegExp for 24 Hours, or any other fuzzer that is LibFuzzer based
cd $build
rm -rf $build/fuzz* $build/tar_prev_* $build/independent-grayc/ independent-grayc/crash-*
mkdir $build/fuzzer-output-directory-prev/
while IFS= read -r seed ; do
  timestamp=`date +"%m-%d-%y-%T"`
  echo "Running RegExp (UM) with seed $seed $timestamp"
  (bin/regexp $setA -detect_leaks=0 -max_len=1000000 -rss_limit_mb=4096 -create_missing_dirs=1 -ignore_crashes=1 -ignore_timeouts=1 -ignore_ooms=1 -seed=$seed -timeout=50 -max_total_time=600)

  # Keep the data and prepare for re-run
  fdupes -dN $setA # Remove duplicates
  tar -czvf $build/fuzzed-files-$seed.tar.gz $build/fuzzer-output-directory/ > tar_prev_$seed.txt 2>&1

  for i in $build/fuzzer-output-directory/*; do
    echo "Copy to PREV. $i"
    cp "$i" $build/fuzzer-output-directory-prev/
  done

  # Check if we need to exit
  curr_ts=`date -d '+0 day +0 hour +0 minutes' '+%F %T'` # Update current
  curr_total=`date -d "$curr_ts" +%s`
  if [ "$curr_total" -ge "$end_total" ] ; then
    echo "DONE: bin/regexp $setA ... "
    exit
  fi
done < "$seeds"
echo "DONE: bin/regexp $setA ... "
