/* corpus/70863bf894fc0768aa62dad4f56243ef_386_test1792490633.c */
#include "csmith.h"
struct {
  unsigned a : 3;
  signed b : 14;
  unsigned c : 25;
} static d[6][10][4] = {{{{}}}};
int main(i) {
  int e, f, g, h = 0;
  if (i)
    h = 1;
  crc32_gentab();
  e = 0;
  for (; e < 6; e++) {
    f = 0;
    for (; f < 10; f++) {
      g = 0;
      for (; g < 4; g++) {
        printf("%d\n", d[e][f][g].a);
        transparent_crc(d[e][f][g].b, "", h);
        transparent_crc(d[e][f][g].c, "", h);
        if (h)
          printf("index = %d\n", e, f);
      }
    }
  }
}
/* ProgramSourceCsmithReduce */
