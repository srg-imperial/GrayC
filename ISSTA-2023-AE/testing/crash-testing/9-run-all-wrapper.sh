#!/bin/bash 
input=$1
output=$2
zipf=$3
zip_or_folder=$4	# zip 1, folder 2

current=`pwd`

lib1=/home/user42/data/csmith/runtime/
lib2=/home/user42/data/csmith/build/runtime/

## Prepare an input folder with all the files
rm -rf $output $input
mkdir $output $input

## Open files and change to csmith style prints
cd $input
if [[ $zip_or_folder -eq 1 ]] ; then
	tar -xf $zipf
	cp -r fuzzer-output-directory/ .
	rm -rf fuzzer-output-directory/
elif [[ $zip_or_folder -eq 2 ]] ; then
	cp -r $zipf/* .
else
	echo "Is $zipf a tar (1) or a folder (2) ?. Exit."
	exit
fi
cd $current

## Remove name extension to get the right input folder
for input_d in $input/* ; do
	echo ">> Testing folder: $input_d"

	## Remove init corpus data
	rm $input_d/A_*.c 
        rm $input_d/B_*.c

        fdupes -dN $input_d/. 

	## Rename all to be .c in the end
	echo ">> $input_d"
	(./0-prepare-folder.sh $input_d 1 skip_me.log)

	## run script 8 now
	touch $output/output.log
	compile_line="-I$lib1 -I$lib2"
	(./8-testing_all.sh "$input_d" "$output" "$output/output.log" "$compile_line")
	## End
	wc -l $output/output.log
	./10-get-res.sh $output >> get_all_results.log
done
echo "## DONE. "
## ./9-run-all-wrapper.sh /home/user42/directed-compiler-fuzzing-code/scripts/8-crash-testing/input /home/user42/directed-compiler-fuzzing-code/scripts/8-crash-testing/output /home/user42/corpus-zips-for-fuzzing/corpus-v0-compiled.tar.xz
