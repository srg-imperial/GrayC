// COVERAGE: llvm-project/llvm/lib/CodeGen/SelectionDAG/SelectionDAG.cpp (1 new functions)
int a;
int main() {
  int b = 0;
  for (; a; a = 2 - (0 | a)) {
    b++;
    if (b <= 4)
      continue;
    break;
  }
  return b;
}
