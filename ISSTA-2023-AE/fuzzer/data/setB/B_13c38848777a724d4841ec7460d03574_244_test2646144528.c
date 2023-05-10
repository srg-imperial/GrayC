/* corpus/13c38848777a724d4841ec7460d03574_244_test2646144528.c */
#include "csmith.h"
struct a {
  signed : 7;
  signed b : 28;
  unsigned c : 3;
  unsigned d : 21;
  uint32_t e;
  signed f;
};
static volatile struct a g[7][3][10];
int main(l) {
  char a;
  int h, i, k, j = 0;
  if (l && strcmp(&a, "1") == 0)
    j = 1;
  h = 0;
  for (; h < 7; h++) {
    i = 0;
    for (; i < 3; i++) {
      k = 0;
      for (; k < 10; k++) {
        printf("%d\n", g[h][i][k].b);
        printf("%d\n", g[h][i][k].c);
        printf("%d\n", g[h][i][k].d);
        printf("%d\n", g[h][i][k].e);
        transparent_crc(g[h][i][k].f, "", j);
        if (j)
          printf("index = \n");
      }
    }
  }
  platform_main_end(crc32_context, j);
}
/* ProgramSourceCsmithReduce */
