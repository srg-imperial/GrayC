#!/bin/bash 
base=$1				        # /home/user42
testcaseDir=$2			  # where is basic.c
process_number=$3		  # 5
itr=$4				        # 0
csmith_location=$5		# Where are the runtime folder of csmith
gfauto=$6			        # gfauto location, e.g., /home/user42/git/graphicsfuzz/gfauto
output_table_file_func=$7	# Where to dump the results (table of the results per file int the working_folder
output_table_file_line=$8	# Where to dump the results (table of the results per file int the working_folder
output_report=$9		   # Where to print the summary report to
compiler=${10}               # llvm or gcc?
gfauto_old_version=${11}  	# Is old or new version of gfauto
working_folder=$base/$compiler-csmith-$process_number # the llvm or gcc installation we will measure coverage for
## E.g., ./4-cov-stat.sh /home/user42 /home/user42/git/data/reduced/corpus_all_v1_2021-02-15 5 0 /home/user42/git/csmith /home/user42/git/graphicsfuzz/gfauto func_cov_v1.csv line_cov_v1.csv coverage_summary_v1.log gcc 0
## ./4-cov-stat.sh /home/user42 /home/user42/Documents/cov_float 5 0 /home/user42/git/csmith /home/user42/git/graphicsfuzz/gfauto func_cov_v1.csv line_cov_v1.csv coverage_summary_v1.log llvm 0

## Print inputs:
echo "base:=$base"
echo "testcaseDir:=$testcaseDir"
echo "process_number:=$process_number"
echo "itr:=$itr"
echo "csmith_location:=$csmith_location"
echo "gfauto:=$gfauto"
echo "output_table_file_func:=$output_table_file_func"
echo "output_table_file_line:=$output_table_file_line"
echo "output_report:=$output_report"
echo "compiler:=$compiler"
echo "gfauto_old_version:=$gfauto_old_version"
echo "working_folder:=$working_folder"

## Report for function coverage
echo "Get statistics for functions"
cov_func=$working_folder/coverage_processed/x-func-$process_number-$itr/cov.out/
(./coverage-sub-scripts/3-gen-statistic-gcov-diff-tab_gfauto.sh "$cov_func" $output_table_file_func >> $output_report)

## Report for line coverage
echo "Get statistics for lines"
cov_line=$working_folder/coverage_processed/x-line-$process_number-$itr/cov.out/
(./coverage-sub-scripts/3-gen-statistic-gcov-diff-tab_gfauto.sh "$cov_line" $output_table_file_line >> $output_report)
