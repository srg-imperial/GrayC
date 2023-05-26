#!/bin/bash
counter=1
times=24

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
rm -rf independent-grayc 2> /dev/null; mkdir independent-grayc


# Start the running for 24 Hours
curr_ts=`date -d '+0 day +0 hour +0 minutes' '+%F %T'`
end_ts=`date -d '+0 day +0 hour +1 minutes' '+%F %T'`
echo "Starts Grammarinator $curr_ts and will end at $end_ts"


# Run the fuzzer
cd $build/../../grammarinator/
while [ $counter -le $times ]
do
  echo $counter
  mkdir segment
  # Run Grammarinator
  python3 run-one-hour.py
  mv segment "segment$counter"
  ((counter++))
done
echo All done
