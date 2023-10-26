#!/bin/bash 
base=$1				              # /home/user42
process_number=$2		        # 5
itr=$3				              # 0
output_table_file_func=$4	  # Where to dump the results (table of the results per file int the working_folder
output_table_file_line=$5	  # Where to dump the results (table of the results per file int the working_folder
output_report=$6		        # Where to print the summary report to

working_folder=$base/$compiler-csmith-$process_number # the llvm or gcc installation we will measure coverage for
## ./4-cov-stat.sh /home/user42 15x 6 func_cov_v1.csv line_cov_v1.csv coverage_summary_v1.log

## Print inputs:
echo "base:=$base"
echo "process_number:=$process_number"
echo "itr:=$itr"
echo "output_table_file_func:=$output_table_file_func"
echo "output_table_file_line:=$output_table_file_line"
echo "output_report:=$output_report"
echo "working_folder:=$working_folder"

## Report for function coverage
echo "Get statistics for functions"
cov_func=$working_folder/coverage_processed/x-func-$process_number-$itr/cov.out/
(./coverage-sub-scripts/3-gen-statistic-gcov-diff-tab_gfauto.sh "$cov_func" $output_table_file_func >> $output_report)

## Report for line coverage
echo "Get statistics for lines"
cov_line=$working_folder/coverage_processed/x-line-$process_number-$itr/cov.out/
(./coverage-sub-scripts/3-gen-statistic-gcov-diff-tab_gfauto.sh "$cov_line" $output_table_file_line >> $output_report)
