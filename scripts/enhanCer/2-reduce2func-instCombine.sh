# This script is an interestingness test script for C-reduce to hit InstCombine functions.
gcc=gcc-11 
llvm=clang-13
llvminst=/home/user42/git/cov/llvm-csmith-113/llvm-build-test-cases # REPLACE THIS WITH YOUR OWN COVERAGE INSTRUMENTED PATH

src=instCombine.c
includes="-Wno-unused-parameter -Wstrict-prototypes"

rm -rf *.out
rm -rf *out*.*
rm -rf *.err.*

ulimit -t 40

$llvminst -O0 -pedantic -Wall -Wextra $includes $src -o llvminst.out >outc.txt 2>&1 &&\
$llvm -O0 -fsanitize=undefined -pedantic -Wall -Wextra $includes $src -o llvm.out >outa.txt 2>&1 &&\
  ! grep 'conversions than data arguments' outa.txt &&\
  ! grep 'incompatible redeclaration' outa.txt &&\
  ! grep 'ordered comparison between pointer' outa.txt &&\
  ! grep 'eliding middle term' outa.txt &&\
  ! grep 'end of non-void function' outa.txt &&\
  ! grep 'invalid in C99' outa.txt &&\
  ! grep 'specifies type' outa.txt &&\
  ! grep 'should return a value' outa.txt &&\
  ! grep 'uninitialized' outa.txt &&\
  ! grep 'incompatible pointer to' outa.txt &&\
  ! grep 'incompatible integer to' outa.txt &&\
  ! grep 'type specifier missing' outa.txt &&\
  ! grep 'non-void function does not return a value' outa.txt &&\
  ! grep 'missing-variable-declarations' outa.txt &&\
  ! grep 'linker command failed with exit code 1' outa.txt &&\
  ! grep 'at end of declaration list' outa.txt &&\
  ! grep 'Wc2x-extensions' outa.txt &&\
  ! grep 'was not declared, defaulting to type' outa.txt &&\
  ! grep 'used in loop condition not modified in loop body' outa.txt &&\
  ! grep 'Wgnu-empty-initializer' outa.txt &&\
  ! grep 'Wgnu-statement-expression' outa.txt &&\
  ! grep 'Wstrict-prototypes' outa.txt &&\
  ! grep 'empty struct is a GNU extension' outa.txt &&\
$gcc -O0 -pedantic -Wall -Wextra $src $includes -o gcc.out >outb.txt 2>&1 &&\
  ! grep 'ISO C does not support omitting parameter names in function definitions before C2X' outb.txt &&\
  ! grep 'parameter name omitted' outb.txt &&\
  ! grep '\-Wuninitialized' outb.txt &&\
  ! grep 'without a cast' outb.txt &&\
  ! grep 'expects a matching' outb.txt &&\
  ! grep 'control reaches end' outb.txt &&\
  ! grep 'no return statement' outb.txt &&\
  ! grep 'return type defaults' outb.txt &&\
  ! grep 'cast from pointer to integer' outb.txt &&\
  ! grep 'useless type name in empty declaration' outb.txt &&\
  ! grep 'no semicolon at end' outb.txt &&\
  ! grep 'type defaults to' outb.txt &&\
  ! grep 'too few arguments for format' outb.txt &&\
  ! grep 'incompatible pointer' outb.txt | grep -ve'transparent_crc_bytes' &&\
  ! grep 'ordered comparison of pointer with integer' outb.txt &&\
  ! grep 'declaration does not declare anything' outb.txt &&\
  ! grep 'expects type' outb.txt &&\
  ! grep 'pointer from integer' outb.txt &&\
  ! grep 'incompatible implicit' outb.txt &&\
  ! grep 'excess elements in struct initializer' outb.txt &&\
  ! grep 'comparison between pointer and integer' outb.txt &&\
  ! grep 'assumed to have' outb.txt &&\
  ! grep 'may be used uninitialized' outb.txt &&\
  ! grep 'Wstrict-prototypes' outb.txt &&\
  ! grep 'warning: excess elements in scalar initializer' outb.txt &&\
cat $src | grep 'puts("1");' &&\
cat $src | grep 'return 1;' &&\
! ./llvminst.out 2>llvminst.err.txt > llvminst.out.txt  	&&\
! ./llvm.out 2>llvm.err.txt > llvm.out.txt 		&&\
! ./gcc.out 2>gcc.err.txt > gcc.out.txt    		&&\
! cat llvminst.err.txt | grep "error"    		&&\
! cat llvm.err.txt | grep "error"    	 		&&\
! cat gcc.err.txt | grep "error"   	 		&&\
cat llvminst.out.txt | grep "__23__" 			&&\
diff llvminst.out.txt llvm.out.txt 	 		&&\
diff llvm.out.txt gcc.out.txt
