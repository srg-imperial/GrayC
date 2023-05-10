/* corpus/ec6a972950a4d1939989af64b0932c84_582_test1328329240.c */
#include "csmith.h"
static uint32_t a[][2][6];
static uint32_t b[][1][1];
int main(h) {
  char g;
  int c, d, e, f = 0;
  if (h && strcmp(&g, "1"))
    f = 1;
  c = 0;
  for (; c < 2; c++) {
    d = 0;
    for (; d < 2; d++) {
      e = 0;
      for (; e < 6; e++) {
        transparent_crc(a[c][d][e], "", f);
        if (f)
          printf("index = \n");
      }
    }
  }
  for (d = e = 0; e < 1; e++)
    transparent_crc(b[c][d][e], "", f);
}
/* ProgramSourceCsmithReduce */
