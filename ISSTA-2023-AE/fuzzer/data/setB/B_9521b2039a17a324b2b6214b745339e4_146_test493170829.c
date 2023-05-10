/* corpus/9521b2039a17a324b2b6214b745339e4_146_test493170829.c */
#include "csmith.h"
struct {
  signed a;
} b[];
int c, d;
int main() {
  int e, f, g;
  crc32_gentab();
  e = 0;
  for (;; e++) {
    f = 0;
    for (; f < 10; f++) {
      g = 0;
      for (; g < 8; g++) {
        transparent_crc(b[e + f * g].a, "", d);
      }
      transparent_crc(c, "", d);
    }
  }
}
/* ProgramSourceCsmithReduce */
