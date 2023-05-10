/* corpus/634283c360539569e5b44b7fb745ac74_270_test1483518037.c */
#include "csmith.h"
struct a {
  volatile uint32_t b;
  signed c : 28;
  signed : 23;
  unsigned d : 9;
};
struct e {
  int32_t f;
};
static struct a g[][4][7];
static int h;
static struct e m[];
int main(n) {
  int i, j, k, l = 0;
  if (n)
    l = 1;
  i = 0;
  for (; i < 9; i++) {
    j = 0;
    for (; j < 4; j++) {
      k = 0;
      for (; k < 7; k++) {
        printf("%d\n", h);
        transparent_crc(g[i][j][k].b, "", l);
        printf("%d\n", g[i][j][k].c);
        printf("%d\n", g[i][j][k].d);
        if (l)
          printf("index = %d\n", j, k);
      }
    }
  }
  for (; i < 6;)
    transparent_crc(m[i].f, "", l);
}
/* ProgramSourceCsmithReduce */
