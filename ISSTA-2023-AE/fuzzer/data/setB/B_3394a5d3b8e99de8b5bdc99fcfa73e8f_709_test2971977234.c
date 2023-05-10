/* corpus/3394a5d3b8e99de8b5bdc99fcfa73e8f_709_test2971977234.c */
#include "csmith.h"
struct {
  volatile int32_t a;
  uint32_t b;
  signed c : 4;
  int32_t d;
  uint32_t e;
  uint64_t f;
} static g[][3][7];
int main(l) {
  int h, i, k, j = 0;
  if (l)
    j = 1;
  crc32_gentab();
  h = 0;
  for (; h < 3; h++) {
    i = 0;
    for (; i < 3; i++) {
      k = 0;
      for (; k < 7; k++) {
        printf("%d\n", g[h][i][k].a);
        printf("%d\n", g[h][i][k].b);
        transparent_crc(g[h][i][k].c, "", j);
        transparent_crc(g[h][i][k].d, "", j);
        transparent_crc(g[h][i][k].e, "", j);
        transparent_crc(g[h][i][k].f, "g_2519.f5", j);
        if (j)
          printf("index = %d\n", h, i, k);
      }
    }
  }
}
/* ProgramSourceCsmithReduce */
