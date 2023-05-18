// COVERAGE: llvm-project/clang/lib/AST/ExprConstant.cpp (1 new functions)
// COVERAGE: llvm-project/llvm/lib/CodeGen/SelectionDAG/LegalizeIntegerTypes.cpp (1 new functions)
// COVERAGE: llvm-project/llvm/lib/CodeGen/TargetLoweringBase.cpp (1 new functions)
#include "stdio.h"
#ifdef __SIZEOF_INT128__
typedef __int128 L;  // Appears in pr49218.c test case
#else
typedef long long L;
#endif
float f;
int main() {
  L i = f;
  if (i <= 10 +
                41 * +((long)(((int)10) >> ((int)10))) *
                    ((long)(((int)(i)) % ((int)10))) -
                ((long)(((double)(i)) + ((double)10))) -
                ((long)(((int)10) ^ ((int)10))))
    do {
      ++i;
      printf("%lld", (long long) i);
    } while (i != 11);
  return 0;
}
