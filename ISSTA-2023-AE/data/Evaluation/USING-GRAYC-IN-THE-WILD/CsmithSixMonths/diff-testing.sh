#!/bin/bash
base=/home/user42
csmith_location=$base/csmith							# csmith location
genrator=$csmith_location/build/src/csmith
csmith_flags=" --bitfields --packed-struct "
nb_progs_to_gen=100000
i=0
prog=csmith_test.c
build_folder=$csmith_location
echo "$build_folder"
######################################## Start Cov. ########################################
# Loop over compilation and coverage measurement
while true; do
	i=$(($i+1))
	## Generate
 	ulimit -St 50; $genrator $csmith_flags > $prog
 	seed=`grep "Seed: " $prog`
	filesize=`stat --printf="%s" $prog`
	
 	## Test -O0
	ulimit -St 45; clang-13 -O2 -w -I$build_folder/build/runtime/ -I$build_folder/runtime/ $prog
	res1=`ulimit -St 15; ./a.out` ## Csmith original paper offered 5 seconds.
 	## Test -O2
	ulimit -St 45; gcc-11 -O2 -w -I$build_folder/build/runtime/ -I$build_folder/runtime/ $prog
	res2=`ulimit -St 15; ./a.out` ## Csmith original paper offered 5 seconds.
	
	## Test diff
	echo "Generating Program $i with seed= $seed, size= $filesize :: Results $res1 <=> $res2"
	if [[ $res1 != $res2 ]] ; then
		echo ">> Diff: <$res1> vs. <$res2>"
	fi
done
time2=$(date +"%T")
echo "DONE."
