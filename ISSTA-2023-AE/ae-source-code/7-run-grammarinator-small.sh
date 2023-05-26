##!/bin/bash
counter=1
times=1

# Start the running for 24 Hours
build=/home/user42/fuzzers/copy_5/llvm-csmith-5/llvm-fuzzer-build/
setA=/home/user42/fuzzers/copy_5/setA/
setB=/home/user42/fuzzers/copy_5/setB/
seeds=/home/user42/seeds/seeds_out7.txt


# Set the coprus to be as in the expriments
cd $build/../../ ; rm -rf $setA $setB; cp -r setA-12-Nov-21 $setA ; cp -r setB-12-Nov-21 $setB

# CD into the folder of the fuzzer's installation
cd $build
#reset
#reset
rm setA-*.zip 2> /dev/null
rm -rf $build/fuzz* tar_prev_* 2> /dev/null
mkdir $build/fuzzer-output-directory-prev/


# Start the running for 24 Hours
curr_ts=`date -d '+0 day +0 hour +0 minutes' '+%F %T'`
end_ts=`date -d '+0 day +0 hour +10 minutes' '+%F %T'`
echo "Starts Grammarinator $curr_ts and will end at $end_ts"


# Run the fuzzer
cd $build/../../grammarinator/
while [ $counter -le $times ]
do
  mkdir segment
  # Run Grammarinator
  python3 run-ten-minutes.py
  mv segment "segment$counter"
  output_folder=segment$counter

  # Keep the data for inspection after fuzzing
  for i in $output_folder/*; do
    # echo "Copy to PREV. $i"
    cp "$i" $build/fuzzer-output-directory-prev/
  done

  # Next iteration
  ((counter++))
done
x=`ls -l $output_folder/*.c | wc -l`
echo "End Fuzzing with Grammarinator. Generated $x files in $output_folder"
