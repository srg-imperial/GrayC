/* corpus/697ce8b1cc587a30c897ce5674197eec_206_test1469835819.c */
#include "csmith.h"
#pragma pack(1)
struct {
  signed a : 10;
  volatile signed b : 2;
} static c[][4][1];
int main() {
  char a;
  int d, e, f, g = 0;
  if (strcmp(&a, "1"))
    g = 1;
  d = 0;
  for (; d < 4;)
    for (; d < 4; d++) {
      e = 0;
      for (; e < 4; e++) {
        f = 0;
        for (; f < 1; f++) {
          transparent_crc(c[d][e][f].a, "", g);
          transparent_crc(c[d][e][f].b, "", g);
          printf("index = %d\n", f);
        }
      }
    }
}
/* ProgramSourceCsmithReduce */
