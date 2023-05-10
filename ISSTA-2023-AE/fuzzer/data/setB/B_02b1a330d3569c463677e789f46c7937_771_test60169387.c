/* corpus/02b1a330d3569c463677e789f46c7937_771_test60169387.c */
#include "csmith.h"
struct {
  volatile uint16_t a;
  uint64_t b;
} static c[][2][3];
int main() {
  int d, e, f, g = 0;
  crc32_gentab();
  d = 0;
  for (; d < 3; d++) {
    e = 0;
    for (; e < 2; e++) {
      f = 0;
      for (; f < 3; f++) {
        printf("%d\n", c[d][e][f].a);
        transparent_crc(c[d][e][f].b, "", g);
      }
    }
  }
}
/* ProgramSourceCsmithReduce */
