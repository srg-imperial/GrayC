files=$1	# A folders with files to get coverage

# For gfauto
export LC_ALL=C.UTF-8
export LANG=C.UTF-8

# Get absolute path of the files to measure coverage with
cd $1
data=`pwd`

# Create an output directory
cd ~
mkdir GCC-coverage
cd GCC-coverage
output_folder=`pwd`

# check coverage
cd /home/user42/fuzzers/coverage/
/home/user42/fuzzers/coverage/1-wrapper-get-coverage.sh /home/user42/ $data 1 0 /home/user42/fuzzers/copy_5/llvm-csmith-5/csmith/ /home/user42/graphicsfuzz/gfauto/ $output_folder/gcc-func-cov-out.csv $output_folder/gcc-line-cov-out.csv $output_folder/gcc-coverage_summary.log gcc 0
echo "Results are in GCC-coverage folder. Summary of it below:"
cat $output_folder/gcc-coverage_summary.log
# DONE

