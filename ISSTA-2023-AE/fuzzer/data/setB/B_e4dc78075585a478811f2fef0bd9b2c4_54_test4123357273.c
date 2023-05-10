/* corpus/e4dc78075585a478811f2fef0bd9b2c4_54_test4123357273.c */
#include "csmith.h"
static uint16_t a[][6];
static int32_t b[3][5][2];
int main(g) {
  int c, d, e, f = 0;
  if (g)
    f = 1;
  crc32_gentab();
  for (c = 0; c < 4; c++)
    for (d = 0; d < 6; d++)
      transparent_crc(a[c][d], "", f);
  for (; c < 7; c++) {
    printf("%d\n", c);
    if (f)
      printf("index = \n");
  }
  for (c = 0; c < 3; c++)
    for (d = 0; d < 5; d++)
      for (e = 0; e < 2; e++)
        transparent_crc(b[c][d][e], "", f);
}
/* ProgramSourceCsmithReduce */
