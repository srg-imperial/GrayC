#!/bin/bash 
current=`pwd`

input=$1"_input"    # Where are all the original tests
output=$1"_output"  # Where to put transformed tests - ready for diff-testing
error=$1"_error-programs-fuzzed" # where to put programs that failed the transformation: e.g. /home/user42/directed-compiler-fuzzing-code/scripts/7-diff-testing/error-programs-fuzzed
zipf=$2             # The tests can be in a single zip file or as a folder: 1 for zip, 2 for a folder.
corrected=$3        # e.g. /home/user42/directed-compiler-fuzzing-code/scripts/7-diff-testing/corrected
zip_or_folder=$4    # zip 1, folder 2
csmith=$5           # Add location of csmith installation if corpus tests contain csmith's generated tests fed to GrayC.

lib1=$csmith/runtime
lib2=$csmith/build/runtime
lib3=/usr/include/x86_64-linux-gnu/

## Prepare an input folder with all the files
rm -rf "$output/" "$input/" "$error/"
mkdir $output $input $error $output/compiled $output/include $output/transform

## Open files and change to csmith style prints
cd $input
if [[ $zip_or_folder -eq 1 ]] ; then
	tar -xf $zipf
elif [[ $zip_or_folder -eq 2 ]] ; then
	cp -r $zipf .
else
	echo "Is $zipf a tar (1) or a folder (2) ?. Exit."
	exit
fi

cd $current
anythingCompiled=0

## Remove name extension to get the right input folder
for input_d in $input/* ; do
	echo "$input_d"

	## Remove init corpus data
        rm $input_d/A_*.c
        rm $input_d/B_*.c

	fdupes -dN $input_d/.

	## Rename all to be .c in the end
	(./1-1-prepare-folder.sh $input_d 1 skip_me.data)

	## Remove all files we cannot compile
	(./1-2-filter-compiled.sh $input_d $output/compiled "-I$lib1 -I$lib2 -I$input_d -Werror=shift-count-negative -Werror=unsequenced")

	## Run script to add csmith's prints
	echo ">> Adding checksum to all files in $input_d, output to $output"
	for program in $output/compiled/*.c ; do
		filename=${program##*/}
		prog_to_path_name=${filename%.*}
		
		working_dir=$output/transform/$prog_to_path_name
		mkdir $working_dir
		cp $program $working_dir
    echo "(python3 1-3-transform.py $working_dir $working_dir $lib1 $lib2 $lib3 $input_d 2>&1 errors_transform_py.log)"
		(python3 1- 3-transform.py $working_dir $working_dir $lib1 $lib2 $lib3 $input_d 2>&1 errors_transform_py.log)
		cp $working_dir/*_copy.c $output 2>/dev/null
		cp errors_transform_py.log $working_dir 2>/dev/null
		cp Record-Info.txt $working_dir 2>/dev/null
		cp Main-Sign.txt $working_dir 2>/dev/null
		cp Global-Info.txt $working_dir 2>/dev/null
		rm Main-Sign.txt Global-Info.txt Record-Info.txt errors_transform_py.log 2>/dev/null # remove temp files from the python script
		
		## Prepare for later
		anythingCompiled=$((anythingCompiled+1))
		
		## Copying if missing (so we can compile later)
		cp -f $program $output/include/
		
		## If the original file does not contain exit or abort, can copy it
		exitORabort=`grep -e"exit()" -e"abort()" -e"fred.txt" $program | wc -l`
		if [[ "$exitORabort" -eq "0" ]] ; then 
			cp -f $program $output/
		fi
	done
	echo ">> Done with script 3-transform.py"
done

## Check if we managed to compile anything!
if [[ $anythingCompiled -le 1 ]] ; then
	echo ">> Cannot compile programs. Exit. ($sizeComp)"
	exit
fi

## Bring back files in corrected that we couldn't parse:
cp -f $corrected/*.c $output/

## Remove duplicates
fdupes -dN $output/.

## run script 5 now
mkdir $output/logger
touch $output/logger/output.log
compile_line="-I$lib1 -I$lib2 -I$output -I$output/include"

trans=`grep "Original main of the program " $output/*.c | wc -l`
gErrMain=`grep "Global but no valid main" $output/*.c | wc -l`
noGOKMain=`grep "No Global Variable but valid main" $output/*.c | wc -l`
noGErrMain=`grep "No Global Variable and no valid main" $output/*.c | wc -l`
echo "Compiled (initially): $anythingCompiled"
echo "Results - translated = $trans, valid without translating = $noGOKMain, error with main = $gErrMain and $noGErrMain"
echo "## DONE. Check Results in: <$output/logger/output.log>"
## ./1-main-enhanCer-option-1.sh /home/user42/directed-compiler-fuzzing-code/scripts/7-diff-testing/results /home/user42/corpus-zips-for-fuzzing/corpus-v0-compiled.tar.xz /home/user42/directed-compiler-fuzzing-code/scripts/7-diff-testing/corrected
