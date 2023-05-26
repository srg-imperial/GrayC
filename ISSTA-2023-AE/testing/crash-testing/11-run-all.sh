#!/bin/bash
input=$1

count1=1

echo "Start Script with folder $input"

## Remove name extension to get the right input folder
for filegz in $input/* ; do
	count1=$(($count1+1))

	if [[ $count1 -gt 403 ]] ; then
		echo ">> Testing folder: $filegz"

		# Run wrapper for crash testing
		(./9-run-all-wrapper.sh /home/user42/directed-compiler-fuzzing-code/scripts/8-crash-testing/input /home/user42/directed-compiler-fuzzing-code/scripts/8-crash-testing/output "$filegz" 1) > crash_testing_current_log.log 2>&1

		# Collect results
		./10-get-res.sh /home/user42/directed-compiler-fuzzing-code/scripts/8-crash-testing/output/
        rm -rf Frama-C-zone/ ; cp -r ../7-diff-testing/Frama-C-zone/ .
	fi
done

