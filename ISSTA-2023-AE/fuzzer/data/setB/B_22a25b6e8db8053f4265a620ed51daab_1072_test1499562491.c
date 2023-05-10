/* corpus/22a25b6e8db8053f4265a620ed51daab_1072_test1499562491.c */
#include "csmith.h"
struct a {
  uint8_t b;
  int32_t c;
  int32_t d;
};
struct e {
  signed f : 10;
  struct a g;
  struct a b;
};
static volatile struct e h[9][4][7];
int main() {
  int i, j, k, l = 1;
  i = 0;
  for (; i < 9; i++) {
    j = 0;
    for (; j < 4; j++) {
      k = 0;
      for (; k < 7; k++) {
        printf("%d\n", h[i][j][k].f);
        printf("%d\n", h[i][j][k].f);
        printf("%d\n", h[i][j][k].f);
        printf("%d\n", h[i][j][k].g.b);
        transparent_crc(h[i][j][k].b.c, "", l);
        transparent_crc(h[i][j][k].b.d, "", k);
      }
    }
  }
}
/* ProgramSourceCsmithReduce */
