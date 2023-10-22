#!/bin/bash
## Parameters:
sourceFolder=$1					## /home/user42/dailydump/*.c
skip=$2						## to skip original test-cases? 1-yes
skipFiles=$3					## skip_me.log

## Check we have process number
if [ -z "$1" ]
  then
	echo "No source folder supplied."
	exit 1
fi

## Run for all programs in folder:
# rm -f $sourceFolder/*.c 	## Only for opimization
rm -f $sourceFolder/*.zip

## Shall we skip it? (original code)
if [[ "$skip" -eq "1" ]] ; then
	for p in $sourceFolder/*
	do
		prog=${p%.*}
		program_file_name=${prog##*/}
		exists=`grep -x "$program_file_name" $skipFiles | wc -l`
		if [[ "$exists" -eq "1" ]] ; then
			rm $p
			echo "Remove file in original set $p"
		fi
		exists=`grep -x "$program_file_name.c" $skipFiles | wc -l`
                if [[ "$exists" -eq "1" ]] ; then
                        rm $p
                        echo "Remove file in original set $p"
                fi
	done
fi

## Check if need rename of remove of empty
for p in $sourceFolder/*
do
	## Check if need to rename or remove if size 0
	sizeF=`cat $p | wc -l`
	if [[ "$sizeF" -eq "0" ]] ; then
		rm $p
		echo "remove zero size file $p"	
	elif [[ ! $p == *.c ]]; then
		mv $p $p.c
		echo " >> rename $p to $p.c"
	elif [[ $p == *.c.c ]]; then
		prog=${p%.*}
		mv $p $prog
		echo " >> rename $p to $prog"
	fi
done
echo "## DONE. ##"
