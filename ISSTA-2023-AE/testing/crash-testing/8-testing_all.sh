#!/bin/bash

## Checks modified code for seg-fault (DEBUG)
function check_configuration {
	program_test=$1
	compiler_test=$2
	compile_line_test=$3
	compileoutput_test=$4
	test_san=$5

	# Skip if already got errors
	if [[ $time_out_flag -eq 0 ]]; then
	# echo "<$program_test> <$compiler_test> <$compile_line_test> <$compileoutput_test>"
	# PLAIN
	{
		rm -f a.out
		(ulimit -St 45 -Sf 90000; $compiler_test -pedantic -Wall -Wextra $compile_line_test $program_test) >> $compileoutput_test 2>&1
		if [[ ! -f "a.out" ]]; then ## check if the file exists
			isSimpleError=`tail -1 $compileoutput_test | grep -e'errors generated' -e'error generated' | wc -l`
			if [[ $isSimpleError -gt 0 ]] ; then
				time_out_flag=1
			fi
			echo ">> ERROR: <ulimit -St 45; $compiler_test -pedantic -Wall -Wextra $compile_line_test $program_test>"
			echo "($program_test) Recognized error in generating this test-case during plain compilation. Please check for any report of BUGS in the logs. (time_out_flag=$time_out_flag)"
		fi
	}
	else
		echo "Skip crashed before program $program (1)" >> $loggerCurr
	fi

	# Can skip testing sanitizers
	if [[ $test_san -eq 0 ]]; then
		return 1
	fi


        # Skip if already got errors
        if [[ $time_out_flag -eq 0 ]]; then
	# ASAN
	{
		rm -f a.out
		(ulimit -St 180 -Sf 90000; $compiler_test -fsanitize=address -g -w -fno-omit-frame-pointer $compile_line_test $program_test) >> $compileoutput_test 2>&1
		if [[ ! -f "a.out" ]]; then ## check if the file exists
			time_out_flag=1
			echo ">> ERROR: <ulimit -St 180; $compiler_test -fsanitize=address -g -w -fno-omit-frame-pointer $compile_line_test $program_test>"
			echo "($program_test) Recognized error in generating this test-case during compilation with ASAN. Please check for any report of BUGS in the logs. (time_out_flag=$time_out_flag)"
		fi
	}
	else
		echo "Skip crashed before program $program (2)" >> $loggerCurr
	fi

        # Skip if already got errors
        if [[ $time_out_flag -eq 0 ]]; then
	# UBSAN
	{
		rm -f a.out
               	if [[ $compiler_test == *"clang"* ]]; then
			(ulimit -St 180 -Sf 90000; $compiler_test -fsanitize=undefined -g -w -lgcc_s --rtlib=compiler-rt $compile_line_test $program_test) >> $compileoutput_test 2>&1
		else
			(ulimit -St 180 -Sf 90000; $compiler_test -fsanitize=undefined -g -w -lgcc_s $compile_line_test $program_test) >> $compileoutput_test 2>&1
		fi

		if [[ ! -f "a.out" ]]; then ## check if the file exists
			time_out_flag=1
			echo ">> ERROR: <ulimit -St 180; $compiler_test -fsanitize=undefined -g -w -lgcc_s <--rtlib=compiler-rt> $compile_line_test $program_test>"
			echo "($program_test) Recognized error in generating this test-case during compilation with UBSAN. Please check for any report of BUGS in the logs. (time_out_flag=$time_out_flag)"
		fi
	}
	else
                echo "Skip crashed before program $program (3)" >> $loggerCurr
	fi
}

## Checks modified code with Frama-C for seg-fault (DEBUG)
function check_wt_FramaC {
	progOrig=$1
	progName=$2
	output=$3
	progRMv=$framac_run_folder/_rmv_"$progName"

	# FRAMA-C
	cd $framac_run_folder
	sed 's/volatile/ /g' $progOrig > $progRMv
	(ulimit -St 300; frama-c -eva -eva-slevel 100 -eva-plevel 256 -eva-precision 5 -eva-warn-undefined-pointer-comparison pointer -eva-no-alloc-returns-null -warn-signed-overflow -eva-no-show-progress -machdep x86_64 $progRMv) > $output 2>&1
	rm -f $progRMv

	## Frama-C installation can easiliy be broken, test it:
	countError=`cat $output | grep "cannot load module" | wc -l`
	if [[ $countError -gt 0 ]]; then
		echo ">>>>>> PLEASE re-insall frama-C!"
		cat $output | grep "cannot load module"
		exit
	fi
	cd $curr_folder
}

################### TEST PROGRAM ###########
function test_program {
	program=$1
	program_file_name=${program##*/}

	## If program has too long expressions : skip it, anyhow we cannot reduce it.
	maxLine=`awk 'length > max_length { max_length = length; longest_line = $0 } END { print max_length }' $program`
	maxMem=`grep -P '\[.*\d{4}.*\]' $program | grep -ve"if" -ve"|" -ve">" -ve"builtin" -ve"return" -ve"(" | cut -d'=' -f1 | grep -P -o '\[.*\d{4}.*\]' | grep '.\{16\}' | grep -ve'[A-Za-z]'`
	if [[ "$maxLine" -lt "22000" ]] && [[ "$maxMem" -lt "1" ]] ; then
		## Check compilers
		for (( i=0; i<${#compilers[@]}; i++ ))
		do
			time_out_flag=0 # Reset the timeout flag!
			for (( j=0; j<${#compilerFlags[@]}; j++ ))
			do
				output="__temp_$program_file_name_$i_$j.log"
				check_configuration "$program" "${compilers[$i]}" "${compilerFlags[$j]} $compile_line" "$loggerCurr" "${compilers_san_flags[$i]}"
			done
		done

		## Test Frama-c crashes
		output=$program_file_name.framac.log
		touch $output
		check_wt_FramaC "$program" "$program_file_name" "$output"
		cat $output >> $loggerCurr
		rm -rf $output
	else
		echo "Skip bad program $program" >> $loggerCurr
	fi
}
################### MAIN ###################

## Parameters:
sourceFolder=$1					## /home/user42/dailydump/*.c
outputFolder=$2					## /home/user42/dailydump/output
loggerCurr=$3					## /home/user42/diff-test.log
compile_line=$4					## -w
curr_folder=`pwd`				## current folder
framac_run_folder=$curr_folder/Frama-C-zone	## frama-c folder
time_out_flag=0					## timeout flag to avoid running other test after program timed-out

## Check we have process number
if [ -z "$1" ]
  then
	echo "No source folder supplied."
	exit 1
fi
if [ -z "$2" ]
  then
	echo "No output folder supplied."
	exit 1
fi
if [ -z "$3" ]
  then
	echo "No logger file supplied."
	exit 1
fi
if [ -z "$4" ]
  then
	echo "No compile line parameters supplied."
	exit 1
fi

#### Test we have Frama-c, and not the system default ####
eval $(opam config env) ## Just to assure it gets it from the right place
frama-c --version
echo " ==> Frama-C version"
testIT=`frama-c --version`
if [ "$testIT" == "Phosphorus-20170501" ]; then
	echo ">> Frama-C version is too old. Please install version 20.0.0 or up."
	exit
fi
if [[ "$testIT" == "" ]]; then
	echo ">> Please install Frama-C version 20.0.0 or up."
	exit
fi
if [ ! -d "$framac_run_folder" ]; then
	echo ">> Please create a folder for Frama-C testing with all required headers for your testing."
	exit
fi
if [ ! -d "$sourceFolder" ]; then
	echo ">> Missing source folder: <$sourceFolder>. Exit."
	exit
fi

## clean prev. run
rm -rf $outputFolder
mkdir $outputFolder

## Testing inputs
compilerFlags=("-O0" "-O1" "-O2" "-O3" "-Os")

## Quick test
compilers=("/home/user42/data/gcc-csmith-1201/gcc-install/bin/gcc" "clang-15")

compilers_names=("gcc-13" "clang-15")

compilers_san_flags=("0" "0" "1" "1")
##

## dump script information
touch $loggerCurr
for (( i=0; i<${#compilers[@]}; i++ ))
do
	echo "##  - Compiler version:" `${compilers[$i]} --version | head -1` >> $loggerCurr
done
	echo "##  - Applying testing for compiler optimizations ${compilerFlags[0]} ${compilerFlags[1]} ${compilerFlags[2]} ${compilerFlags[3]} ${compilerFlags[4]}" >> $loggerCurr
	echo "##  - CSMITH_HOME: $csmith_location" >> $loggerCurr
	echo "##  - Compilation of testcase: $compile_line" >> $loggerCurr
	echo "##  - Source folder: $sourceFolder for process $process_number" >> $loggerCurr
	echo "##  - Date: $(date '+%Y-%m-%d at %H:%M.%S')" >> $loggerCurr
	echo "##  - Host name $(hostname -f)" >> $loggerCurr

## Run for all programs in folder:
for p in $sourceFolder/*.c
do
	test -f "$p" || continue
	echo " >> test $p"
	echo " ============ test $p ============ " >> $loggerCurr
	(test_program "$p")
done

## Diff again:
## Generating logger per test:
logger_checksum_0=$outputFolder/checksum_logger_"${compilers[0]}"_"${compilerFlags[0]}".log
echo "## DONE. ##" >> $loggerCurr
echo " >> Errors if exists logged into <$loggerCurr>"
