/* corpus/5fa27f0dce47eab411bccf1d25aa8ea5_2147_test2127759821.c */
#include "csmith.h"
struct {
  signed a : 5;
  volatile unsigned b : 8;
} static c[][7][2];
int main(h) {
  int d, e, f, g = 0;
  if (h)
    g = 1;
  d = 0;
  for (; d < 9; d++) {
    e = 0;
    for (; e < 7; e++) {
      f = 0;
      for (; f < 2; f++) {
        transparent_crc(c[d][e][f].a, "", g);
        transparent_crc(c[d][e][f].b, "", g);
      }
    }
  }
}
/* ProgramSourceCsmithReduce */
