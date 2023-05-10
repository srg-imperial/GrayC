/* corpus/b754ac52a6ffdbc14c3fb07af9322f58_1702_test2047628085.c */
#include "csmith.h"
int32_t static a;
static int64_t b[][5];
uint8_t c() {
  for (a = 1; a >= 0; a--) {
    int32_t d = 1;
    b[0][a] &= d;
  }
  return 0;
}
int main() {
  int e, f, g = 0;
  crc32_gentab();
  for (e = 0; e < 8; e++)
    for (f = 0; f < 5; f++)
      transparent_crc(b[e][f], "", g);
  platform_main_end(15, 0);
}
/* ProgramSourceCsmithReduce */
