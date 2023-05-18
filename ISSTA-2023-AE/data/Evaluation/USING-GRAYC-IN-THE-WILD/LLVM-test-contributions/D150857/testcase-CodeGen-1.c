// COVERAGE: llvm-project/llvm/lib/Analysis/InlineCost.cpp (1 new functions)
// COVERAGE: llvm-project/llvm/lib/CodeGen/SelectionDAG/LegalizeIntegerTypes.cpp (2 new functions)
// COVERAGE: llvm-project/llvm/lib/CodeGen/TargetLoweringBase.cpp (2 new functions)
extern void abort();
#ifndef __SIZEOF_INT128__
#define __int128 long long // Appears in test case of pr61375.c
#endif
unsigned __int128 a;
void b() { a = (double)a + 0; }
int main() {
  b();
  if (a)
    abort();
  return 0;
}
