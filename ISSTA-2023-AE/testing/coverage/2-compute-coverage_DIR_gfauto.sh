#!/bin/bash 
################################################
## This scripts get a folder of test-cases and
## compute their coverage using GCOV and GFAUTO
## How to call?
## ./1-compute-coverage_basic_case_gfauto.sh /home/user42 /home/user42/allTestCases 5 0 /home/user42/csmith /home/user42/gfauto
################################################
base=$1			# /home/user42
testcaseDir=$2		# where is basic.c
process_number=$3	# 5
itr=$4			# 0 
csmith_location=$5	# Where are the runtime folder of csmith
gfauto=$6		# gfauto location, e.g., /home/user42/git/graphicsfuzz/gfauto
compiler=$7		# gcc or llvm?
old_version=$8		# 1 - yes, 0 - no
# $base $testcaseDir $process_number $itr $csmith_location $gfauto $compiler $gfauto_old_version

## Required parameters
working_folder=$base/$compiler-csmith-$process_number
configuration_location=$working_folder/csmith/scripts/compiler_test.in # config file location
compile_line_lib_default="-I$csmith_location/runtime -I$csmith_location/build/runtime -lgcov -w"

## Init
if [[ $itr -eq 0 ]]; then
	if [[ "$compiler" == "llvm" ]]; then
		rm -rf $working_folder/llvm-source/tools/clang/test
		rm -rf $working_folder/llvm-source/tools/clang/unittests
		rm -rf $working_folder/llvm-source/tools/clang/docs
		rm -rf $working_folder/llvm-source/tools/clang/www
	fi

	rm -rf $working_folder/coverage_processed
	rm -rf $working_folder/coverage_gcda_files/application_run
fi

## Start evaluation
time1=$(date +"%T")
echo "EVOLUTION OF LLVM COVERAGE WHEN COMPILING PROGRAM in folder: "$testcaseDir" ("$time1")"

# Loop over compilation and coverage measurement
current_folder=`pwd`

## Read which compiler to test:
compilerInfo=`head -1 $configuration_location`
if [[ "$compilerInfo" == "" ]] || [[ "$compilerInfo" == " " ]] ; then
	echo "no compiler info in file $configuration_location <$compilerInfo>" 
	exit
fi

# Set location to record the data
mkdir -p $working_folder/coverage_gcda_files/application_run

time2=$(date +"%T")
echo "--> COMPILING "$testcaseDir" ITERATION "$itr" with compiler info. "$compilerInfo" ("$time2")"

# Run compiler and save coverage data
export GCOV_PREFIX=$working_folder/coverage_gcda_files/application_run

echo "Folder: $testcaseDir"
for testcaseFile in $testcaseDir/* ; do
	compiler_flag="-w"
	is_math=`grep "math.h" $testcaseFile | wc -l`
	if [[ $is_math -gt 0 ]]; then
		compiler_flag="-w -lm"
	fi
	
	## Compile the test-case
	if [[ "$testcaseFile" == *".c" ]] ; then
		echo "--> PERFORMING (*.c)  <(ulimit -St 50; ${compilerInfo} $testcaseFile $compiler_flag) > basic_output.txt 2>&1>"
		(ulimit -St 50; ${compilerInfo} ${compile_line_lib_default} $testcaseFile $compiler_flag) > "basic_output.txt" 2>&1
	else
		echo "--> PERFORMING (missing *.c) <(ulimit -St 50; ${compilerInfo} $testcaseFile $compiler_flag) > basic_output.txt 2>&1>"
		mv "$testcaseFile" "$testcaseFile".c
		(ulimit -St 50; ${compilerInfo} ${compile_line_lib_default} $testcaseFile.c $compiler_flag) > "basic_output.txt" 2>&1
	fi
	grep "fatal error: csmith.h: No such file or directory" basic_output.txt

#	i=$((i+1))
#  	if [[ $i -eq 1 ]]; then
#    		break
#  	fi
done
unset GCOV_PREFIX

## Measure Coverage
time3=$(date +"%T")
echo "--> MEASURING COVERAGE... ("$time3")"
mkdir -p $working_folder/coverage_processed/x-$itr
mkdir -p $working_folder/coverage_processed/x-line-$itr
(
	source $gfauto/.venv/bin/activate
	
	## Function coverage
	cd $working_folder/coverage_processed/x-$itr
	if [ "$old_version" == "1" ]; then
		gfauto_cov_from_gcov --out run_gcov2cov.cov $working_folder/$compiler-build/ $working_folder/coverage_gcda_files/application_run/ --num_threads 32 --gcov_uses_json --gcov_functions >> gfauto.log 2>&1
	else
		echo "gfauto_cov_from_gcov --out run_gcov2cov.cov $working_folder/$compiler-build/ --gcov_prefix_dir $working_folder/coverage_gcda_files/application_run/ --num_threads 32 --gcov_uses_json --gcov_functions >> gfauto.log 2>&1"
		gfauto_cov_from_gcov --out run_gcov2cov.cov $working_folder/$compiler-build/ --gcov_prefix_dir $working_folder/coverage_gcda_files/application_run/ --num_threads 32 --gcov_uses_json --gcov_functions >> gfauto.log 2>&1
	fi
        gfauto_cov_to_source --coverage_out cov.out --cov run_gcov2cov.cov $working_folder/$compiler-build/ >> gfauto.log 2>&1
        
        ## Line coverage
        cd $working_folder/coverage_processed/x-line-$itr
        if [ "$old_version" == "1" ]; then
        	gfauto_cov_from_gcov --out run_gcov2cov.cov $working_folder/$compiler-build/ $working_folder/coverage_gcda_files/application_run/ --num_threads 32 --gcov_uses_json >> gfauto.log 2>&1
        else
		echo "gfauto_cov_from_gcov --out run_gcov2cov.cov $working_folder/$compiler-build/ --gcov_prefix_dir $working_folder/coverage_gcda_files/application_run/ --num_threads 32 --gcov_uses_json >> gfauto.log 2>&1"
        	gfauto_cov_from_gcov --out run_gcov2cov.cov $working_folder/$compiler-build/ --gcov_prefix_dir $working_folder/coverage_gcda_files/application_run/ --num_threads 32 --gcov_uses_json >> gfauto.log 2>&1
        fi
        gfauto_cov_to_source --coverage_out cov.out --cov run_gcov2cov.cov $working_folder/$compiler-build/ >> gfauto.log 2>&1
        ls -l
)
cd $current_folder

time2=$(date +"%T")
echo "DONE. RESULTS (FUNCTION) AVAILABLE IN $working_folder/coverage_processed/x-$itr for testcase <$testcaseFile> ($time2)"
echo "DONE. RESULTS (LINE) AVAILABLE IN $working_folder/coverage_processed/x-line-$itr for testcase <$testcaseFile> ($time2)"
#rm a.out "basic_output.txt" ## clean at the end
