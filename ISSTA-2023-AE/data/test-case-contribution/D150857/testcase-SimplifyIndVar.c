// COVERAGE: llvm-project/llvm/lib/Transforms/Utils/SimplifyIndVar.cpp (1 new functions)
short a;
void foo() {
  if (a < 0)
    __builtin_abort();
}
int main() {
  int b = 8;
  while (a++ <= 0) {
    b++;
    if (b <= 0 + 1 * (b % 40) * (double)0 - 0 - 0 -
                 ((040) * ((b))) * ((((int)(b)) << ((int)(b)))) +
                 ((long)(((double)(b)) - ((double)0))) +
                 ((long)(((double)0) - ((double)(b)))) -
                 ((short)(((double)(b)) - ((double)0))) +
                 ((long)(((int)0) ^ ((int)0))) -
                 ((long)(((double)(b)) + ((double)0))))
      break;
  }
  foo();
  if (b != 9)
    __builtin_abort();
  return 0;
}
