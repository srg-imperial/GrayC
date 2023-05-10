/* corpus/22a25b6e8db8053f4265a620ed51daab_1154_test2225762118.c */
#include "csmith.h"
struct a {
  uint64_t b;
  unsigned c : 14;
  unsigned d : 10;
  signed e : 4;
  unsigned f : 5;
  unsigned g : 1;
  int32_t h;
} r, s[][9][3];
struct v {
  uint8_t b;
  uint32_t c;
  uint8_t d;
  struct a e;
  uint32_t f;
  int32_t g;
  int16_t l;
  uint64_t h;
  uint32_t m;
  struct a n;
};
static uint64_t o, q, p;
int y;
static struct v t[1][3][1];
static int8_t u[1][1][1];
int main_argc;
char *w;
void main() {
  int i, j, k, x = 0;
  if (main_argc && strcmp(&w[1], ""))
    x = 1;
  crc32_gentab();
  transparent_crc(o, "", x);
  transparent_crc(p, "", x);
  transparent_crc(q, "", x);
  transparent_crc(r.h, "", x);
  j = 0;
  for (; j < 9; j++) {
    k = 0;
    for (; k < 3; k++) {
      printf("%d\n", s[i][j][k].b);
      printf("%d\n", s[i][j][k].c);
      printf("%d\n", y);
      printf("%d\n", s[i][j][k].e);
      transparent_crc(t[i][j][k].d, "", x);
      transparent_crc(t[i][j][k].b, "", x);
      transparent_crc(t[i][j][k].c, "", x);
      transparent_crc(t[i][j][k].e.d, "", x);
      transparent_crc(t[i][j][k].e.e, "", x);
      transparent_crc(t[i][j][k].f, "", x);
      transparent_crc(t[i][j][k].e.g, "", x);
      transparent_crc(t[i][j][k].n.d, "", x);
      transparent_crc(t[i][j][k].n.e, "", x);
      transparent_crc(t[i][j][k].n.f, "", x);
      if (x)
        printf("index = %d\n", i, j, k);
    }
  }
  i = 0;
  for (; i < 3; i++) {
    j = 0;
    for (; j < 10; j++) {
      k = 0;
      for (; k < 2; k++) {
        transparent_crc(u[i][j][k], "", x);
        printf("index = \n");
      }
    }
  }
  transparent_crc(i, "g_1645", x);
}
/* ProgramSourceCsmithReduce */
