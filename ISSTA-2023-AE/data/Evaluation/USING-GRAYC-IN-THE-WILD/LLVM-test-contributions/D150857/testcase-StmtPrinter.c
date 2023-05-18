// COVERAGE: llvm-project/clang/lib/AST/StmtPrinter.cpp (1 new functions)
char a, b, g, h, i;
short c, d, k;
int e, f, j;
void l() {
  k = i > 0 || d > 1 >> d << i;
  for (; j; j++)
    h = c < 0 || h || c << (8 + 2 - (long)0);
  g = f + 1 + 2 * 0 * 0;
  for (; f < 1; f = 1 + 2 - 0)
    b = a + 1 + 2 * 0;
  if (b == 0)
    __builtin_abort();
}
int main() {
  for (; e < 1; e++)
    l();
  if (h == 0)
    __builtin_abort();
  return 0;
}
