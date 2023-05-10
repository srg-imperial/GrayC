/* corpus/07f4e7fd0236a669aede3b306ac84f78_466_test2742588455.c */
#include "csmith.h"
static volatile uint16_t a[][5][9];
int main(f) {
  int b, c, d, e = 0;
  if (f)
    e = 1;
  b = 0;
  for (; b < 2; b++) {
    c = 0;
    for (; c < 5; c++) {
      d = 0;
      for (; d < 9; d++) {
        transparent_crc(a[b][c][d], "", e);
        printf("index = %d\n", b, c, d);
      }
    }
    transparent_crc(b, "", e);
  }
}
/* ProgramSourceCsmithReduce */
