input=$1	# Input folder

# Some quick manipulation to remove duplicate files
rm -rf /home/user42/fuzzers/copy_5/llvm-csmith-5/llvm-fuzzer-build/fuzzer-output-directory-prev/
mkdir -p /home/user42/fuzzers/copy_5/llvm-csmith-5/llvm-fuzzer-build/fuzzer-output-directory-prev/

cp /home/user42/fuzzers/copy_5/setA-12-Nov-21/A_* /home/user42/fuzzers/copy_5/llvm-csmith-5/llvm-fuzzer-build/fuzzer-output-directory-prev/
sleep 1m

./fuzzers/copy_5/add-c-extn.sh $1 2>&1 /dev/null
(for i in $1/*.c; do touch "$i" ; done)
cp $1/* /home/user42/fuzzers/copy_5/llvm-csmith-5/llvm-fuzzer-build/fuzzer-output-directory-prev/

fdupes -dN /home/user42/fuzzers/copy_5/llvm-csmith-5/llvm-fuzzer-build/fuzzer-output-directory-prev/ > black-list.log
rm -r /home/user42/fuzzers/copy_5/llvm-csmith-5/llvm-fuzzer-build/fuzzer-output-directory-prev/A_*
rm output.txt 2> /dev/null

# Found duplicates of A_* fuzzers claim it is a newly generated code
dupsA=`cat black-list.log | grep -e '-] /home/user42/fuzzers/copy_5/llvm-csmith-5/llvm-fuzzer-build/fuzzer-output-directory-prev/A_' | wc -l`
if [[ $dupsA -gt 0 ]] ; then
  echo "Remove from <Total files processed:> the number of files the fuzzers copied as is from the initial corpus: $dupsA"
fi
rm black-list.log 2> /dev/null

# Check the rate
python3 fuzzers/copy_5/rate.py
