#!/bin/bash
shopt -s extglob # Activate extended pattern matching in bash

working_folder=$1	# e.g. /home/user42/coverage
TMP_SOURCE_FOLDER=$2	# Input from 0- script
nb_processes=1		# Cannot really be controlled because of how we build gcc
current_folder=`pwd`	# current folder

cd $current_folder
# Copying GCC source and Csmith exe to parallel execution folders, then install GCC with coverage data in each folder
i=0 # compile a basic one - never to use.
while (( $i <= $nb_processes ));
do
	## Start loop i
	echo ">> Copy gcc folder-$i of gcc"

	### Create a working folder with GCC source
	rm -rf $working_folder/gcc-csmith-$i 				## Remove the old version
	mkdir $working_folder/gcc-csmith-$i				## Create a new version
	cp -r $TMP_SOURCE_FOLDER/* $working_folder/gcc-csmith-$i	## Copy the data from the temp download folder

	### Update Csmith settings
	cd $working_folder/gcc-csmith-$i
	mkdir -p ./csmith/scripts/
	echo $working_folder/gcc-csmith-$i"/gcc-build/gcc/xgcc -B"$working_folder/gcc-csmith-$i"/gcc-build/gcc/. -O3" > ./csmith/scripts/compiler_test.in

 	### GCC PART: with instrumentation
	# Setting the env. + cov. and keeping information of the versions
	cd $working_folder/gcc-csmith-$i; mkdir compilation_info; mv $working_folder/gcc-csmith-$i/gcc $working_folder/gcc-csmith-$i/gcc-source
	cd gcc-source; git status > $working_folder/gcc-csmith-$i/compilation_info/git_info.txt; git log | head -10 >> $working_folder/gcc-csmith-$i/compilation_info/git_info.txt
	gcc --version > $working_folder/gcc-csmith-$i/compilation_info/gcc-version.txt; g++ --version >> $working_folder/gcc-csmith-$i/compilation_info/gcc-version.txt; gcov --version >> $working_folder/gcc-csmith-$i/compilation_info/gcc-version.txt; cpp --version >> $working_folder/gcc-csmith-$i/compilation_info/gcc-version.txt
	cd $working_folder/gcc-csmith-$i ## Assure we are now here.

	## Finish settings and moving files
	echo ">> gcc folder-$i is set"

	if (( 0 < $i )); then
		## Compile with coverage
		(
			## Set output folders
			TMP_GCOV_FOLDER=$(mktemp -d .sources_gcc.XXXXXXX.tmp)
			mkdir -p $TMP_GCOV_FOLDER/coverage_gcda_files/application_run-init
			mkdir gcc-build gcc-install
	 		cd ./gcc-build

			## Assure we are using the built gcc:
        		(
				usrLib=$working_folder/gcc-csmith-0/gcc-install
        			sudo rm -f /usr/bin/cpp /usr/bin/gcc /usr/bin/g++ /usr/bin/gcov
        			sudo rm -f /usr/local/bin/cpp /usr/local/bin/gcc /usr/local/bin/g++ /usr/local/bin/gcov
        			sudo ln -s $usrLib/bin/cpp /usr/bin/cpp
        			sudo ln -s $usrLib/bin/gcc /usr/bin/gcc
        			sudo ln -s $usrLib/bin/g++ /usr/bin/g++
        			sudo ln -s $usrLib/bin/gcov /usr/bin/gcov
			)

			# Covarage flags:
			export GCOV_PREFIX=$TMP_GCOV_FOLDER/coverage_gcda_files/application_run-init ## Send gcda of build to temp.
			export GCOV_PREFIX_STRIP=0
		 	export CFLAGS='-g -O0 --coverage -ftest-coverage -fprofile-arcs'
			export CXXFLAGS='-g -O0 --coverage -ftest-coverage -fprofile-arcs'
			export LDFLAGS='-lgcov --coverage -ftest-coverage -fprofile-arcs'

			./../gcc-source/configure --disable-multilib --disable-bootstrap --disable-install-libiberty --enable-coverage=noopt --enable-targets='X86' --enable-languages='c,c++,lto,objc,obj-c++' --with-gmp=/tmp/gcc/ --with-mpfr=/tmp/gcc/ --with-mpc=/tmp/gcc/ --with-isl=/tmp/isl --prefix=$working_folder/gcc-csmith-$i/gcc-install/ CFLAGS_FOR_TARGET='-g -O0 --coverage -ftest-coverage -fprofile-arcs' CXXFLAGS_FOR_TARGET='-g -O0 --coverage -ftest-coverage -fprofile-arcs' > $working_folder/gcc-csmith-$i/compilation_info/config_output.txt 2>&1

		 	make -j$(nproc) > $working_folder/gcc-csmith-$i/compilation_info/build_output.txt 2>&1
			make -j$(nproc) install > $working_folder/gcc-csmith-$i/compilation_info/install_output.txt 2>&1
			#### WE KEEP build, install and source folders sperated. ####

			# Cleaning after build
			rm -rf $TMP_GCOV_FOLDER
			unset CFLAGS
			unset CXXFLAGS
			unset LDFLAGS
			unset GCOV_PREFIX
			unset GCOV_PREFIX_STRIP
		)
		## Shall be here: cd $working_folder/gcc-csmith-$i/gcc
		cd $working_folder/gcc-csmith-$i/gcc-source

		## Remove other languages: brig, fortran, go, d
		rm -rf libgfortran		# FORTRAN
		rm -rf libgo gotools 	# GO
		rm -rf libphobos		# D (also GDC is D)
		rm -rf libada			# ADA
		## Remove testsuite folders (gcc does not include these into coverage)
		rm -rf gcc/testsuite libatomic/testsuite libffi/testsuite libgomp/testsuite libiberty/testsuite libitm/testsuite
		rm -rf libstdc++-v3/testsuite libvtv/testsuite

		# stat for core:
		c1=`find  $working_folder/gcc-csmith-$i/gcc-source/ -name *.c | wc -l`
		c2=`find  $working_folder/gcc-csmith-$i/gcc-source/ -name *.h | wc -l`
		c3=`find  $working_folder/gcc-csmith-$i/gcc-build/ -name *.gcno | wc -l`
		c4=`find  $working_folder/gcc-csmith-$i/gcc-build/ -name *.gcda | wc -l`
		echo ">> Built GCC in $working_folder/gcc-csmith-$i/gcc-build/, installed in $working_folder/gcc-csmith-$i/gcc-install/."
		echo ">> Compilation info. in $working_folder/gcc-csmith-$i/compilation_info/."
		echo ">> Total ($c1) C-files, ($c2) header files, ($c3) gcno files, ($c4) gcda files."
		find  $working_folder/gcc-csmith-$i/gcc-source/ -name *.c > $working_folder/gcc-csmith-$i/compilation_info/gcc_c_files.txt
		find  $working_folder/gcc-csmith-$i/gcc-source/ -name *.h > $working_folder/gcc-csmith-$i/compilation_info/gcc_h_files.txt
		find  $working_folder/gcc-csmith-$i/gcc-build/ -name *.gcno > $working_folder/gcc-csmith-$i/compilation_info/gcc_gcno_files.txt
		find . -name *.gcda -exec rm -rf {} \;
		echo "	--> Removed $c4 gcda files."
		#### TESTS ####
	else
		## Compile without coverage
		(
			## Set output folders
			mkdir gcc-build ; mkdir gcc-install
			cd ./gcc-build

			## Config, compile and install:
			./../gcc-source/configure --disable-multilib --disable-bootstrap --disable-install-libiberty --enable-targets='X86' --enable-languages='c,c++,lto,objc,obj-c++' --with-gmp=/tmp/gcc --with-mpfr=/tmp/gcc --with-mpc=/tmp/gcc --with-isl=/tmp/isl --prefix=$working_folder/gcc-csmith-$i/gcc-install/ > $working_folder/gcc-csmith-$i/compilation_info/config_output.txt 2>&1

			make -j$(nproc) > $working_folder/gcc-csmith-$i/compilation_info/build_output.txt 2>&1
			make -j$(nproc) install > $working_folder/gcc-csmith-$i/compilation_info/install_output.txt 2>&1
			#### WE KEEP build, install and source folders sperated. ####
		)
	fi

	## Zip it with soft links - unzip with h option: tar -xhzvf gcc-csmith-0.tar.gz
	cd $working_folder
	tar -czvf gcc-csmith-$i.tar.gz gcc-csmith-$i/ > $working_folder/tar_me-$i.txt 2>&1
	# Next core
	i=$(($i+1))
done

## Revert back all gcc changes:
sudo rm -f /usr/bin/cpp /usr/bin/gcc /usr/bin/g++ /usr/bin/gcov
sudo rm -f /usr/local/bin/cpp /usr/local/bin/gcc /usr/local/bin/g++ /usr/local/bin/gcov
sudo ln -s /usr/bin/cpp-10 /usr/bin/cpp
sudo ln -s /usr/bin/gcc-10 /usr/bin/gcc
sudo ln -s /usr/bin/g++-10 /usr/bin/g++
sudo ln -s /usr/bin/gcov-10 /usr/bin/gcov

#rm -rf $TMP_SOURCE_FOLDER
