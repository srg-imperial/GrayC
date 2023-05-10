/* corpus/5cafabb539b16d4d0703ce9d1708b3dd_322_test2801732319.c */
#include "csmith.h"
struct {
  int8_t a;
  int8_t b;
  volatile int8_t c;
  uint32_t d;
  volatile uint16_t e;
  uint32_t f;
  uint16_t g;
} static h[][5][6];
static int l;
int main() {
  int i, j, k, m = 1;
  i = 0;
  for (; i < 4; i++) {
    j = 0;
    for (; j < 5; j++) {
      k = 0;
      for (; k < 6; k++) {
        printf("%d\n", h[i][j][k].a);
        printf("%d\n", h[i][j][k].b);
        transparent_crc(h[i][j][k].c, "", h[i][j][k].d);
        transparent_crc(h[i][j][k].e, "", m);
        transparent_crc(l, "", h[i][j][k].f);
        transparent_crc(h[i][j][k].g, "", m);
        printf("index = %d\n", i, j, k);
      }
    }
  }
  platform_main_end(crc32_context, m);
}
/* ProgramSourceCsmithReduce */
