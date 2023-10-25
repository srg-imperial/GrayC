#!/bin/bash
shopt -s extglob # Activate extended pattern matching in bash
working_folder=$1 		## base folder
gfauto=$2			## gfauto path
i=$3 				## which copy

## Before running it, run: (1) ./0-download-git-llvm-wt-rt.sh /home/user42 11 and (2) ./1-install-csmith-llvm-ninja-cov.sh /home/user42 /home/user42/.sources.mhAmsGY.tmp 11
## put in comment: add_subdirectory(sqlite3) and add_subdirectory(XRay)
## test-suite/MultiSource/Applications/CMakeLists.txt
## test-suite/CTMark/CMakeLists.txt
## test-suite/MicroBenchmarks/CMakeLists.txt

########
llvm_folder=$working_folder/llvm-csmith-$i
gcda=$llvm_folder/coverage_gcda_files
cov_processed=$llvm_folder/coverage_processed
tests_build=$llvm_folder/test-suite-build
comp_info=$llvm_folder/compilation_info
######## 
rm -rf $gcda/
rm -rf $cov_processed/

## Save information regarding the version and how we compile it
cd $comp_info
echo " - date: $(date '+%Y-%m-%d at %H:%M.%S')" > $comp_info/llvm-test-suite-version.txt
echo " - host name $(hostname -f)" >> $comp_info/llvm-test-suite-version.txt
echo " - current path: $(pwd)" >> $comp_info/llvm-test-suite-version.txt
gcc-10 --version >> $comp_info/llvm-test-suite-version.txt; g++-10 --version >> $comp_info/llvm-test-suite-version.txt; gcov-10 --version >> $comp_info/llvm-test-suite-version.txt; cpp-10 --version >> $comp_info/llvm-test-suite-version.txt; /usr/bin/cc --version >> $comp_info/llvm-test-suite-version.txt; /usr/bin/c++ --version >> $comp_info/llvm-test-suite-version.txt 
	
Ccompiler="$llvm_folder/llvm-install/usr/local/bin/clang"
CXXcompiler="$llvm_folder/llvm-install/usr/local/bin/clang++"

## Set env. and compile to get coverage
(
	mkdir -p $gcda/application_run # Created once, to aggregate coverage form all configurations
	echo " - Creating temp output folder: <$gcda/application_run>"

	# LOOP over all configureation and collect coverage
	declare -a arr=("O3.cmake" "O0.cmake" "Os.cmake" "Oz.cmake" "ReleaseNoLTO.cmake" "Debug.cmake" )
	
	k=0
	for j in "${arr[@]}" ; do
		k=$((k+1))
		# Cmake and build of LLVM Test-suite
		cd $llvm_folder
		rm -rf $tests_build/ 
		mkdir $tests_build
		cd $tests_build

		set CXX=$CXXcompiler
		set CC=$Ccompiler
		time1=$(date +"%T")
		echo " --> Configure LLVM test-suite with cmake to $tests_build...  ("$time1")"
		echo "Configuration: cmake -DCMAKE_C_COMPILER=$llvm_folder/llvm-build/bin/clang -C../test-suite/cmake/caches/$j ../test-suite" > $comp_info/llvm-test-suite-version-$i-$k.txt
		cmake -DLLVM_TARGETS_TO_BUILD="X86" -DCMAKE_C_COMPILER="$Ccompiler" -DCMAKE_CXX_COMPILER="$CXXcompiler" -C../test-suite/cmake/caches/"$j" ../test-suite > $comp_info/config_test-suite_output-$i-$k.txt 2>&1
		
		# Run compiler and save coverage data
		time2=$(date +"%T")
		echo " --> Build LLVM test-suite with cmake to $tests_build...  ("$time2")"

		export GCOV_PREFIX=$gcda/application_run
		make > $comp_info/build_test-suite_output-$i-$k.txt 2>&1
 	 	
		# Cleaning after build
		unset GCOV_PREFIX	
		unset CC
		unset CXX
		

		## Measure Coverage
		time3=$(date +"%T")
		echo " --> MEASURING COVERAGE... ("$time3")"
		cd $llvm_folder
		mkdir -p $cov_processed/x-line-$i-$k 
		mkdir -p $cov_processed/x-func-$i-$k

		# Venv. start
		(
			source $gfauto/.venv/bin/activate

			## FUNCTION COVERAGE ##
			cd $cov_processed/x-func-$i-$k
			#gfauto_cov_from_gcov --out run_gcov2cov.cov $llvm_folder/llvm-build/ $gcda/application_run/ --num_threads 32 --gcov_uses_json --gcov_functions >> gfauto.log 2>&1 
			gfauto_cov_from_gcov --out run_gcov2cov.cov $llvm_folder/llvm-build/ --gcov_prefix_dir $gcda/application_run/ --num_threads 32 --gcov_uses_json --gcov_functions >> gfauto.log 2>&1
			gfauto_cov_to_source --coverage_out cov.out --cov run_gcov2cov.cov $llvm_folder/llvm-build/ >> gfauto.log 2>&1 

			## LINE COVERAGE ##
			cd $cov_processed/x-line-$i-$k
			#gfauto_cov_from_gcov --out run_gcov2cov.cov $llvm_folder/llvm-build/ $gcda/application_run/ --num_threads 32 --gcov_uses_json >> gfauto.log 2>&1 
			gfauto_cov_from_gcov --out run_gcov2cov.cov $llvm_folder/llvm-build/ --gcov_prefix_dir $gcda/application_run/ --num_threads 32 --gcov_uses_json >> gfauto.log 2>&1
			gfauto_cov_to_source --coverage_out cov.out --cov run_gcov2cov.cov $llvm_folder/llvm-build/ >> gfauto.log 2>&1 
		)
		cd $current_folder
	done
)
# End of Loop
ls -l $cov_processed/x-line-$i-*
ls -l $cov_processed/x-func-$i-*
echo " ## DONE. ##"

