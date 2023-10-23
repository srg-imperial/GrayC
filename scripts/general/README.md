# Download compilers source 

GrayC works with compiler source code. To download LLVM:
```
./1-download-llvm.sh <base-folder> <version>
```
and GCC:
```
./1-download-gcc.sh <base-folder> <version>
```

We recommend using swap files when building from source of these compilers.

Example of expected output (for LLVM 15):
```
./1-download-llvm.sh /home/ubuntu/grayc/ 15
 >> Checking out releases/gcc-15 tag
Cloning into 'llvm-project'...
remote: Enumerating objects: 124785, done.
remote: Counting objects: 100% (124785/124785), done.
remote: Compressing objects: 100% (104201/104201), done.
remote: Total 124785 (delta 22733), reused 70966 (delta 16632), pack-reused 0
Receiving objects: 100% (124785/124785), 176.11 MiB | 10.15 MiB/s, done.
Resolving deltas: 100% (22733/22733), done.
Updating files: 100% (118554/118554), done.
Cloning into 'csmith'...
remote: Enumerating objects: 5801, done.
remote: Counting objects: 100% (626/626), done.
remote: Compressing objects: 100% (63/63), done.
remote: Total 5801 (delta 606), reused 563 (delta 563), pack-reused 5175
Receiving objects: 100% (5801/5801), 8.93 MiB | 18.66 MiB/s, done.
Resolving deltas: 100% (3993/3993), done.
 >> Downloaded LLVM 15 and Csmith into /home/ubuntu/grayc//.sources_15VL.NYWmZbP.tmp.
```
