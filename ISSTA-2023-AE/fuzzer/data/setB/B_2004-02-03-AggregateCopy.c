/* corpus/2004-02-03-AggregateCopy.c */
/* PROGRAMS_TO_SKIP */
#include <stdio.h>

typedef struct {
  int X;
} agg;

int main() {
  agg A;  A.X = 123;
  agg B, C;
  B = C = A;

  printf("%d, %d, %d\n", A.X, B.X, C.X);
  return 0;
}

/* ProgramSourceLLVM */
