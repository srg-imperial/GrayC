#!/bin/bash
working_folder=$1		# Add where gcov files are for compiler/test 1
output_table_file=$2		# Where to put the table
unitest_skip=utils/unittest	# unittest folder should not be part of cov measurements
## E.g., ./3-gen-statistic-gcov-diff-tab_gfauto.sh /home/user42/llvm-csmith-1/coverage_processed-1/x-10/cov.out/ table__all_1_0.csv

## INIT:
rm $output_table_file
rm list_gcov.txt

wf1_size=${#working_folder}

## START ##

## Constract the lines on the table
find $working_folder -type f | sort >> list_gcov.txt
linecount=`cat list_gcov.txt | wc -l`
if [ "$linecount" == "0" ]; then
	echo ">> ERROR: no file found in $working_folder"
	rm list_gcov.txt
	exit 1
fi

## If same population, continue:
echo "Total files in $working_folder: <$linecount>"

## file name: the name of the file we comapare
## #line 1: number of lines in file 1
## #line 1 hit: number of lines hit in file 1
echo ">> file name,#line 1,#line 1 hit" >> $output_table_file
while IFS= read -r -u 4 file_name ; do		
		fn=${file_name:$wf_size}
		if [[ ! "$fn" == *"$unitest_skip"* ]]; then 	
			## Add a row to the csv file
			tmp=__tmp_x.txt
			test=__test_x.txt
			cat $file_name | sed 's:^        :      0 :1' | sed -n 's/\(^......[0-9]*[0-9] \).*$/\1/p' | cat -n > $tmp
			cat -n $file_name > $test	
			./41-inner-LH_file.sh $fn $tmp $output_func_hit >> $output_table_file 
			rm -f $tmp $test
		fi
		
done 4<list_gcov.txt
echo " >> End extracting data for $linecount files."

resT=`sed '1d' $output_table_file | cut -d',' -f2 | awk '{ sum += $1 } END { print sum }'`
echo "#line 1 ................. ==> "$resT

resT=`sed '1d' $output_table_file | cut -d',' -f3 | awk '{ sum += $1 } END { print sum }'`
echo "#line 1 HIT ............. ==> "$resT

# cleaning
rm list_gcov.txt
