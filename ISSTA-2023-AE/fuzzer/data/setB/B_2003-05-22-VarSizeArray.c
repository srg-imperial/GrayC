/* corpus/2003-05-22-VarSizeArray.c */
/* PROGRAMS_TO_SKIP */
#include <stdio.h>

int test(int Num) {
  int Arr[Num];
  Arr[2] = 0;
  return Arr[2];
}

int main() {
  printf("%d\n", test(4));
  return 0;
}
/* ProgramSourceLLVM */
