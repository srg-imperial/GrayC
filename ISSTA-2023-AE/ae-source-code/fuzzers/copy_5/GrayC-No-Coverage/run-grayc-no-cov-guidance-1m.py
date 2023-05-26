import os
import sys
import shutil
import os
from os.path import isfile, join
import time
import random
from random import randint
import logging
import argparse
import re
from datetime import datetime

# GrayC aggressive mutators
MUTATORS =["jump-mutator","duplicate-mutator","constant-mutator","delete-mutator","assignment-mutator","expression-mutator"]

def random_with_N_digits(n):
    range_start = 10**(n-1)
    range_end = (10**n)-1
    return randint(range_start, range_end)

def get_split_filename(filename):
    return os.path.splitext(filename)[0]

def pick_mutation():
    return random.choice(MUTATORS)

def pick_file(dir_path):
    return random.choice(os.listdir(dir_path))

def single_file_mutation(mutation):
    if (mutation == "function-merger"):
        return False
    else:
        return True
def create_singlefile_mutator_command(TOOL_BIN_PATH,source_file_setA,LIB_PATHS,SEED,mutation):
    mutator_command_elements = [os.path.join(TOOL_BIN_PATH,mutation),source_file_setA,"--","--no-warnings",LIB_PATHS,SEED]
    mutator_command = " ".join(mutator_command_elements)
    return "timeout 5s " + mutator_command

def get_date():
    now = datetime.now()
    return now.strftime("%Y-%m-%d-%H-%M-%S")

def get_lib_paths(lib_paths_file):
    settings_file = open(lib_paths_file, 'r')
    lines = settings_file.readlines()
    lib_paths_line = ""
    for line in lines:
        if ("lib_paths" in line):
            lib_paths_line = line
            break
    lib_paths = lib_paths_line[lib_paths_line.find(":")+1:]
    lib_paths = re.split(r'\t+', lib_paths)
    return (" ".join(["-I"+path for path in lib_paths if path!="\n"]))

def create_multifile_mutator_command(TOOL_BUILD_PATH,TOOL_BIN_PATH,source_file_setB,LIB_PATHS,SEED):
    hooks_filename = os.path.join(TOOL_BUILD_PATH,"Mutation-Hooks-Functions.txt")
    globals_filename = os.path.join(TOOL_BUILD_PATH,"Global-Info.txt")
    statement_filename = os.path.join(TOOL_BUILD_PATH,"Statement-Info.txt")
    statement_filename_sanitised = os.path.join(TOOL_BUILD_PATH,"Statement-Info-San.txt")

    rename_command_elements = [os.path.join(TOOL_BIN_PATH,"rename-transform"),source_file_setB,"--","--no-warnings",LIB_PATHS,SEED]
    rename_command = " ".join(rename_command_elements)

    extractor_command_elements = [os.path.join(TOOL_BIN_PATH,"function-extractor"),os.path.join(get_split_filename(source_file_setB),"_rename_output.c"),"--","--no-warnings",LIB_PATHS,SEED]
    extractor_command = " ".join(extractor_command_elements)

    merger_command_elements = [os.path.join(TOOL_BIN_PATH,"function-merger"),source_file_setB,"--","--no-warnings",LIB_PATHS,SEED]
    merger_command = " ".join(merger_command_elements)

    return "timeout 5s" + rename_command,"timeout 5s" + extractor_command,"timeout 5s" + merger_command


if __name__ == '__main__':
    logging.basicConfig(filename='grayc.log', level=logging.INFO, filemode='w', format='%(name)s - %(levelname)s - %(message)s')
    parser = argparse.ArgumentParser(
        description='Python wrapper script that runs the GrayC tool',epilog="Example usage: python3 run-grayc.py /home/user42/git/copy_i/setA/ /home/user42/git/copy_i/setB/ /home/user42/git/copy_i/llvm-csmith-1/llvm-fuzzer-build/ grayc-output /home/user42/git/copy_i/settings.txt")
    parser.add_argument('setA',
                        metavar='setA',
                        type=str,
                        help='Full path to folder containing the seed corpus of C programs')
    parser.add_argument('setB',
                        metavar='setB',
                        type=str,
                        help='Full path to folder containing the secondary corpus of C programs for multi-file mutations')
    parser.add_argument('tool_build_path',
                        metavar='tool_build_path',
                        type=str,
                        help='Full path to folder containing the build directory of the tool')
    parser.add_argument('output_directory',
                        metavar='output_directory',
                        type=str,
                        help='Full path to folder where the results of the fuzzer need to be stored')
    parser.add_argument('lib_paths_file',
                        metavar='lib_paths_file',
                        type=str,
                        help='Full path to file containing the external library paths to be used by the fuzzer-produced files')
    args = parser.parse_args()
    start = time.time()
    PERIOD_OF_TIME = 60 # in seconds
    TOTAL=0
    FAILED=0
    TOOL_BUILD_PATH = args.tool_build_path
    TOOL_BIN_PATH = os.path.join(TOOL_BUILD_PATH,"bin")
    SETA = args.setA
    SETB = args.setB
    LIB_PATHS = get_lib_paths(args.lib_paths_file)
    OUTPUT_DIR = args.output_directory
    shutil.rmtree(OUTPUT_DIR, ignore_errors=True)
    os.mkdir(OUTPUT_DIR)
    SEED = str(random_with_N_digits(6))

    while (1):
        if time.time() > start + PERIOD_OF_TIME:
            print("Ran job for: {t} sec".format(t=PERIOD_OF_TIME))
            print("Processed files {n}".format(n=TOTAL))
            print("Compilation failed files {n}".format(n=FAILED))
            sys.exit(0)

        mutation = pick_mutation()
        source_file_setA = os.path.join(SETA,pick_file(SETA))
        source_file_setB = os.path.join(SETB,pick_file(SETB))
        mutated_filename = get_split_filename(source_file_setA) + ".mutated.c"
        mutated_filepath = os.path.join(SETA,mutated_filename)
        fuzzed_filename = "fuzzer-file-" + str(TOTAL) + "-" + get_date() + ".c"
        fuzzed_filepath = os.path.join(OUTPUT_DIR,fuzzed_filename)

        if (single_file_mutation(mutation)):
            mutate = create_singlefile_mutator_command(TOOL_BIN_PATH,source_file_setA,LIB_PATHS,SEED,mutation)
            logging.info("SINGLE-FILE MUTATOR PICKED")
            logging.info("\tCOMMAND: " + mutate)
            os.system(mutate)
            if os.path.isfile(mutated_filepath):
                logging.info("\tMUTATED FILE at {src} moved to {dest}: ".format(src=mutated_filepath,dest=fuzzed_filepath))
                shutil.copy(mutated_filepath,fuzzed_filepath)
        else:
            multifile_commands = create_multifile_mutator_command(TOOL_BUILD_PATH,TOOL_BIN_PATH,source_file_setB,LIB_PATHS,SEED)
            rename = multifile_commands[0]
            extract = multifile_commands[1]
            merge = multifile_commands[2]
            logging.info("MULTI-FILE MUTATOR PICKED")
            logging.info("\t 1. RENAME COMMAND: " + rename)
            logging.info("\t 2. EXTRACT COMMAND: " + extract)
            logging.info("\t 3. MERGE COMMAND: " + merge)
            os.system(rename)
            os.system(extract)
            os.system(merge)
        os.system("fdupes -dN grayc-output")
        TOTAL=TOTAL+1

