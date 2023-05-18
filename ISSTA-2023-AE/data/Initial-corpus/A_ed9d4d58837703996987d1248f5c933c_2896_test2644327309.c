/* corpus/ed9d4d58837703996987d1248f5c933c_2896_test2644327309.c */
#include "csmith.h"
struct {
  int32_t a;
} b;
static uint64_t c[][8][2] = {6032641719, 5754035246, 62014162561,
                             5603239293, 6776681450, 24232514181};
int main_argc;
void main() {
  int d, e, f, g = 0;
  if (main_argc) {
    g = 1;
  }
  crc32_gentab();
  for (d = 0; d < 3; d++) {
    for (e = 0; e < 8; e++) {
      for (f = 0; f < 2; f++) {
        transparent_crc(c[d][e][f], "", g);
      }
    }
  }
  transparent_crc(b.a, "", g);
}
/* ProgramSourceCsmithReduce */
