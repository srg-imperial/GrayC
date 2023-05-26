import os, random
import argparse
import shutil
if __name__ == "__main__":
    parser = argparse.ArgumentParser(description='Universal mutator run')
    parser.add_argument('c_file',
                       metavar='c_file',
                       type=str,
                       help='the path to c program for which the fuzzing has to be done')
    args = parser.parse_args()
    c_file = args.c_file
    os.system("mkdir /home/user42/fuzzers/copy_5/llvm-csmith-5/llvm-fuzzer-build/fd/")
    um_comm = "/home/user42/.local/bin/mutate " + c_file + " --mutantDir /home/user42/fuzzers/copy_5/llvm-csmith-5/llvm-fuzzer-build/fd/ > l.txt"
    os.system("rm l.txt")
    os.system(um_comm)
    if (os.path.isdir("/home/user42/fuzzers/copy_5/llvm-csmith-5/llvm-fuzzer-build/fd/")):
        if ((len(os.listdir("/home/user42/fuzzers/copy_5/llvm-csmith-5/llvm-fuzzer-build/fd/")))>2):
            os.system("fdupes -dN /home/user42/fuzzers/copy_5/llvm-csmith-5/llvm-fuzzer-build/fd/.")
            random_file=random.choice(os.listdir("/home/user42/fuzzers/copy_5/llvm-csmith-5/llvm-fuzzer-build/fd"))
            source = '/home/user42/fuzzers/copy_5/llvm-csmith-5/llvm-fuzzer-build/fd/'
            c_file_wo = os.path.splitext(c_file)[0]
            c_file_wo = os.path.basename(c_file_wo)
            dest = '/home/user42/fuzzers/copy_5/llvm-csmith-5/llvm-fuzzer-build/fd/'+c_file_wo+".mutated.c"
            files = os.listdir(source)
            no_of_files = 1
            for file_name in random.sample(files, no_of_files):
                print (os.path.getsize(os.path.join(source, file_name)))
                if (os.path.getsize(os.path.join(source, file_name)))>5:
                    shutil.move(os.path.join(source, file_name), dest)
