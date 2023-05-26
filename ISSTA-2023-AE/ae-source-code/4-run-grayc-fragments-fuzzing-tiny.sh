#!/bin/bash
counter=1
times=1

# Start the running for 24 Hours
build=/home/user42/fuzzers/copy_5/llvm-csmith-5/llvm-fuzzer-build/
setA=/home/user42/fuzzers/copy_5/setA/
setB=/home/user42/fuzzers/copy_5/setB/
seeds=/home/user42/seeds/seeds_out4.txt
settings=/home/user42/fuzzers/copy_5/settings.txt

# Set the coprus to be as in the expriments
cd $build/../../ ; rm -rf $setA $setB; cp -r setA-12-Nov-21 $setA ; cp -r setB-12-Nov-21 $setB
rm -rf /home/user42/fuzzers/copy_5/llvm-csmith-5/llvm-fuzzer-build/fuzzer-output-directory-prev/
mkdir -p /home/user42/fuzzers/copy_5/llvm-csmith-5/llvm-fuzzer-build/fuzzer-output-directory-prev/
# CD into the folder of the fuzzer's installation
cd $build
#reset
rm setA-*.zip
rm -rf $build/fuzz* tar_prev_
rm -rf independent-grayc ; mkdir independent-grayc ; mkdir fuzzer_csmith-tmp
touch fuzzer_csmith-tmp/csmith_decls.txt

# Start the running for 24 Hours
curr_ts=`date -d '+0 day +0 hour +0 minutes' '+%F %T'`
end_ts=`date -d '+0 day +0 hour +1 minutes' '+%F %T'`
echo "Starts GrayC Fuzzer (No Coverage Guidance mode) $curr_ts and will end at $end_ts"


# 24h run
while [ $counter -le $times ] ; do
    # Run 1 hour
    echo "Running GrayC Fuzzer (Fragments fuzzing mode) with segment $counter"
    python3 $build/../../GrayC-Fragments-Fuzzing/run-grayc-fragments-fuzzing-1m.py $setA $setB/ $build grayc-output $settings

    if [[ `ls -l grayc-output/*.c | wc -l` -gt 0 ]] ; then
        # Keep the data
        mkdir independent-grayc/segment_${counter}
        cp grayc-output/* independent-grayc/segment_${counter}/
        zip -r independent-grayc/segment_${counter}.zip grayc-output > /dev/null 2>&1
        rm -rf grayc-output nohup.out

        # Keep the log
        mv grayc.log independent-grayc/grayc-log-segment-${counter}.log
        cd independent-grayc/
        zip -r grayc-log-segment-${counter}.zip grayc-log-segment-${counter}.log > /dev/null 2>&1
        rm grayc-log-segment-${counter}.log
        cd ..

        # Keep set-A
        zip -r setA-${counter}.zip $setA > /dev/null 2>&1
        mkdir -p /home/user42/fuzzers/copy_5/llvm-csmith-5/llvm-fuzzer-build/fuzzer-output-directory-prev/
	cp -r independent-grayc/* /home/user42/fuzzers/copy_5/llvm-csmith-5/llvm-fuzzer-build/fuzzer-output-directory-prev/
        # Next
        ((counter++))
    else
        echo "Repeating $counter, pyhon script crashed."
    fi
done
echo All done
