import os,sys
import re
import json

# This script takes the files in prev folder and check the compilation rate
if __name__ == "__main__":
    keyword = "error"
    original_corpus_dir = "/home/user42/fuzzers/copy_5/llvm-csmith-5/llvm-fuzzer-build/fuzzer-output-directory-prev/"
    fail=0;
    total=0;
    for filename in os.listdir(original_corpus_dir):
        fname = os.path.basename(filename)
        name = os.path.splitext(fname)[0]
        if(filename.endswith(".c")):
            total=total+1
            os.system("rm -f a.out")
            compile_command = "(ulimit -Sf 40000; gcc-11 -w --no-warnings -I/home/user42/fuzzers/copy_5/llvm-csmith-5/llvm-fuzzer-includes/ -I/usr/include/x86_64-linux-gnu/ " + os.path.join(original_corpus_dir,filename) + ") > output.txt 2>&1"
            os.system(compile_command)
            with open('output.txt',encoding = "ISO-8859-1") as file_p:
                x = file_p.read()
                if (keyword in x):
                    fail=fail+1
            os.system("rm -f output.txt")
    print (" Total files processed: " + str(total)+ "\n")
    print (" Total files failing compilation: " + str(fail)+ "\n")
