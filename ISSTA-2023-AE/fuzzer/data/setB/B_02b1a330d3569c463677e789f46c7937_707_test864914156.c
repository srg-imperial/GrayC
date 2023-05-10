/* corpus/02b1a330d3569c463677e789f46c7937_707_test864914156.c */
#include "csmith.h"
struct {
  signed a;
} b[];
int main() {
  int c, d, e;
  crc32_gentab();
  for (;;) {
    c = 0;
    for (; c < 2; c++) {
      d = 0;
      for (; d < 10; d++) {
        e = 0;
        for (; e < 10; e++) {
          transparent_crc(b[d * e].a, "", 1);
        }
      }
    }
  }
}
/* ProgramSourceCsmithReduce */
