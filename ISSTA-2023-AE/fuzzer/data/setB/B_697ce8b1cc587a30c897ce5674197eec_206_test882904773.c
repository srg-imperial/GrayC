/* corpus/697ce8b1cc587a30c897ce5674197eec_206_test882904773.c */
#include "csmith.h"
struct {
  unsigned a : 6;
  signed b : 1;
} c[][2];
int d;
int main_argc;
void main() {
  int e, f, g = 0;
  if (main_argc) {
    g = 1;
  }
  e = 0;
  for (; e < 9; e++) {
    f = 0;
    for (; f < 2; f++) {
      transparent_crc(c[e][f].a, "", g);
      printf("%d\n", c[e][f].b);
      if (g) {
        printf("index = %d\n", e);
      }
    }
  }
  for (;;) {
    transparent_crc(d, "", g);
  }
}
/* ProgramSourceCsmithReduce */
