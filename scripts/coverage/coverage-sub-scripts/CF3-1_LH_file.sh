#!/bin/bash
############################
## MAIN:
############################

fileO=$1 			# file name originally
file1=$2 			# file 1

file1_ln=`cat $file1 | wc -l` # size file 1
file1_cov_any=`cat $file1 | awk '{if ($2 >0) print($2)}' | wc -l`
echo ">> $fileO,$file1_ln,$file1_cov_any"
