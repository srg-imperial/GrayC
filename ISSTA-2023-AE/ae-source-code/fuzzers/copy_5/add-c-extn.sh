#!/bin/bash
##################
## This script check which of the single file programs we can
## compile given a folder.
#################
testcaseDir=$1 #"/home/user42/git/directed-compiler-fuzzing-code/scripts/3-reduce-general-spots-reaching-files/corpus_weak+gen_feb/orig_1"
## Check if need rename of remove of empty
for p in $testcaseDir/*
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
