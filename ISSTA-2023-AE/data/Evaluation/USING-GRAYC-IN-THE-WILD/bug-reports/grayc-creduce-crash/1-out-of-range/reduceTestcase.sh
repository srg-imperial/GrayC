rm -rf *.out
rm -rf *out*.*
rm -rf *.err.*
ulimit -t 20
compiler="/home/user42/llvm-csmith-1/llvm-install/usr/local/bin/clang -O3"
csmith_runtime="-I/home/user42/llvm-csmith-1/csmith/runtime/ -I/home/user42/llvm-csmith-1/csmith/build/runtime/"
testcase=test2240686269.c

clang -O0 -g -pedantic -Wall -Wextra $csmith_runtime $testcase -o clangA.out >outA.txt 2>&1 &&\
   ! grep 'conversions than data arguments' outA.txt &&\
   ! grep 'linker command failed with exit code 1' outA.txt &&\
   ! grep 'at end of declaration list' outA.txt &&\
   ! grep 'incompatible redeclaration' outA.txt &&\
   ! grep 'ordered comparison between pointer' outA.txt &&\
   ! grep 'eliding middle term' outA.txt &&\
   ! grep 'end of non-void function' outA.txt &&\
   ! grep 'invalid in C99' outA.txt &&\
   ! grep 'specifies type' outA.txt &&\
   ! grep 'should return a value' outA.txt &&\
   ! grep 'uninitialized' outA.txt &&\
   ! grep 'incompatible pointer to' outA.txt &&\
   ! grep 'incompatible integer to' outA.txt &&\
   ! grep 'type specifier missing' outA.txt &&\
! $compiler $csmith_runtime $testcase -o clang.out >outb.txt 2>&1 &&\
cat $testcase | grep "int main" &&\
ls -l clangA.out &&\
! ls -l clang.out
