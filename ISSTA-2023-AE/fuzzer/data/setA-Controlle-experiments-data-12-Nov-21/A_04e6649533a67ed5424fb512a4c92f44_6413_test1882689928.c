/* corpus/04e6649533a67ed5424fb512a4c92f44_6413_test1882689928.c */
#include "csmith.h"
int32_t a() {
  int32_t *b[7][10][2];
  int c, d, e;
  for (c = 0; c < 7; c++)
    for (d = 0; d < 10; d++)
      for (e = 0; e < 2; e++)
        b[c][d][e] = b;
  return 0;
}
int main() {
  int f = a();
  platform_main_end(5, f);
}
/* ProgramSourceCsmithReduce */
