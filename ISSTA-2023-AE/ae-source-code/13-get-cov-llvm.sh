files=$1	# A folders with files to get coverage

# For gfauto
export LC_ALL=C.UTF-8
export LANG=C.UTF-8

# Get absolute path of the files to measure coverage with
cd $1
data=`pwd`

# Create an output directory
cd ~
mkdir LLVM-coverage
cd LLVM-coverage
output_folder=`pwd`

# check coverage
cd /home/user42/fuzzers/coverage/
/home/user42/fuzzers/coverage/1-wrapper-get-coverage.sh /home/user42/ $data 3 0 /home/user42/fuzzers/copy_5/llvm-csmith-5/csmith/ /home/user42/graphicsfuzz/gfauto/ $output_folder/llvm-func-cov-out.csv $output_folder/llvm-line-cov-out.csv $output_folder/llvm-coverage_summary.log llvm 0
echo "Results are in LLVM-coverage folder. Summary of it below:"
cat $output_folder/llvm-coverage_summary.log
# DONE

