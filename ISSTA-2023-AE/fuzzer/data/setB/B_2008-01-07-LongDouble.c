/* corpus/2008-01-07-LongDouble.c */
/* PROGRAMS_TO_SKIP */
#include <stdio.h>
int main(void) {
  long double x = 1.0;
  printf("%Lf %Lf\n", x, x);
  return 0;
}
/* ProgramSourceLLVM */
