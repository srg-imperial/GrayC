import os
import sys
import subprocess
import shutil
import glob,os
from os.path import isfile, join
from git import Repo
import time


# Before running the script plean remove the output directory
# The script does not store the files generated by the tool. Call analysis scripts from the check_for_crashes() method.
# The script deleted the file after processing it, hence at the end of 24hrs, the output folder will be empty


def check_for_compilation(output_dir,file):
    global FAILED
    FAILED=FAILED+1

def check_for_crashes(file):
    # Call crash testing scripts here
    pass

def get_coverage_info(file):
    # Call coverage information scripts here
    pass

def segments(file):
    # Save data in segments
    compile_command = "cp " + os.path.join(output_dir,file) + " segment/"
    os.system(compile_command)

def process_file(output_dir,file):
    segments(file)
    check_for_crashes(file)
    get_coverage_info(file)
    check_for_compilation(output_dir,file)



if __name__ == '__main__':
    # ANTLR4 C grammar URL used
    # https://github.com/antlr/grammars-v4/blob/master/c/C.g4

    start = time.time()
    PERIOD_OF_TIME = 600
    TOTAL=0
    FAILED=0
    output_dir = "output/"
    shutil.rmtree(output_dir, ignore_errors=True)
    os.mkdir(output_dir)

    while (1):
        if time.time() > start + PERIOD_OF_TIME:
            sys.exit(0)
        create_one_file_from_grammar = "/home/user42/.local/bin/grammarinator-generate -p CUnparser.py -l CUnlexer.py -o " + output_dir + "/test_%d.c -d 10"
        os.system(create_one_file_from_grammar)
        file_process = [f for f in os.listdir(output_dir) if os.path.isfile(join(output_dir, f))]
        process_file(output_dir,file_process[0])
        TOTAL=TOTAL+1
        os.system("rm output/" + file_process[0])

