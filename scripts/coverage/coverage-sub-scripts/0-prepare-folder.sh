#!/bin/bash
## Parameters:
sourceFolder=$1					## /home/user42/dailydump/*.c

## Check we have process number
if [ -z "$1" ]
  then
	echo "No source folder supplied."
	exit 1
fi

## Run for all programs in folder:
# rm -f $sourceFolder/*.c 	## Only for opimization
for p in $sourceFolder/*
do
	if [[ ! $p == *.c ]]; then
		mv $p $p.c
		echo " >> rename $p to $p.c"
	fi
done
echo "## DONE. ##"
