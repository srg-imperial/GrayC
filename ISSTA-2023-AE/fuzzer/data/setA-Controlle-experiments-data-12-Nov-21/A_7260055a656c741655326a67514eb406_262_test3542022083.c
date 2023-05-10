/* corpus/A_7260055a656c741655326a67514eb406_262_test3542022083.c */
#include "csmith.h"
struct a {
  uint32_t b;
};
static uint32_t c = 2994669794;
static int32_t d[2][9][5] = {1};
static struct a e[5] = {4294967289};
static struct a f[10] = {2180879496};
uint8_t g() {
  uint32_t *h[] = {0, &c};
  return 2;
}
int main(m) {
  int i, j, k, l = 0;
  if (m)
    l = 1;
  crc32_gentab();
  transparent_crc(c, "", l);
  i = 0;
  for (; i < 32; i++)
    for (; i < 2; i++) {
      j = 0;
      for (; j < 9; j++) {
        k = 0;
        for (; k < 5; k++) {
          transparent_crc(d[i][j][k], "", l);
          if (l)
            printf("index = %d\n", k);
        }
      }
    }
  for (i = 0; i < 5; i++)
    transparent_crc(e[i].b, "", l);
  i = 0;
  for (; i < 10; i++) {
    transparent_crc(f[i].b, "", l);
    if (l)
      printf("index = \n");
  }
}
/* ProgramSourceCsmithReduce */
