// COVERAGE: llvm-project/llvm/lib/Transforms/Scalar/Float2Int.cpp (1 new functions)
#include "stdio.h"
char b = 32;
int main() {
  for (b = ((long)(((double)(b)) * ((double)(b)))); b >= -29; b--)
    printf("%d", (int)b);
  printf("\n");
  return 0;
}
