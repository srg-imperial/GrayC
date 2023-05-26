#!/bin/bash
############################
## MAIN:
############################

fileO=$1 			# file name originally
file1=$2 			# file 1

file1_cov_any=`cat $file1 | awk '{if ($2 >0) print($2)}' | wc -l`
if [[ $file1_cov_any -gt 0 ]] ; then
	lines=`cat $file1 | awk '{if ($2 >0) print($1)}'`
	while IFS= read -r line
	do
		rm __tmp_check_ret.txt; touch __tmp_check_ret.txt
    		awk -v myline=$line 'NR==myline' $fileO > __tmp_check_ret.txt
		issmall=`grep -e"}" __tmp_check_ret.txt | wc -l`
		if [[ $issmall -gt 0 ]] ; then
			echo ">> Found in $fileO"
			cat __tmp_check_ret.txt ## void foo() { } 
		else
			awk -v myline=$(($line+1)) 'NR==myline' $fileO >> __tmp_check_ret.txt
			isend=`grep -e"}" __tmp_check_ret.txt | wc -l`
			issmall=`grep -e"return " __tmp_check_ret.txt | wc -l`
			if [[ $isend -gt 0 ]] ; then
				echo ">> Found in $fileO"
				cat __tmp_check_ret.txt ## void foo() { \n } 
			elif [[ $issmall -gt 0 ]] ; then
				## void foo() { \n return \n } 
				awk -v myline=$(($line+2)) 'NR==myline' $fileO >> __tmp_check_ret.txt
				isend=`grep -e"}" __tmp_check_ret.txt | wc -l`
                        	if [[ $isend -gt 0 ]] ; then
                               		echo ">> Found in $fileO"
					cat __tmp_check_ret.txt
				fi
			fi
		fi
	done <<< "$lines"
	rm __tmp_check_ret.txt
fi
