/* corpus/3394a5d3b8e99de8b5bdc99fcfa73e8f_1584_test2055279976.c */
#include "csmith.h"
static uint64_t a[][1][9] = {5,
                             32293156399,
                             9961496422,
                             17419635196354704036,
                             68099708703,
                             10836100453127451466,
                             10836100453127451466,
                             17419635196354704036};
int main(f) {
  int b, c, d, e = 0;
  if (f)
    e = 1;
  crc32_gentab();
  b = 0;
  for (; b < 3; b++)
    transparent_crc(b, "", e);
  b = c = d = 0;
  for (; d < 9; d++) {
    transparent_crc(a[b][c][d], "", e);
    if (e)
      printf("index = \n");
  }
}
/* ProgramSourceCsmithReduce */
