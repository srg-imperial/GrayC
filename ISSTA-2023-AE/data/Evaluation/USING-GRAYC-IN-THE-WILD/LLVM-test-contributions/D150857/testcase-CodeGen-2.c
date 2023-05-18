// COVERAGE: llvm-project/llvm/lib/CodeGen/SelectionDAG/LegalizeIntegerTypes.cpp (1 new functions)
// COVERAGE: llvm-project/llvm/lib/CodeGen/TargetLoweringBase.cpp (1 new functions)
extern void abort();
#ifndef __SIZEOF_INT128__
#define __int128 long long // Appears in test case of pr61375.c
#endif
float a;
int main() {
  __int128 b = a;
  if (b + (double)10)
    ++b;
  while (b != 1)
    abort();
  return 0;
}
