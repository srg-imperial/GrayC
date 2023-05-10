/* corpus/c8c2047290ef0f036a00220369026c46_42545_test466309667.c */
#include "csmith.h"
#pragma pack(1)
struct a {
  unsigned b : 14;
  uint32_t c;
  unsigned : 9;
  unsigned d : 12;
  signed e : 12;
};
static volatile struct a f[];
static volatile int g;
int main(j) {
  int h, i = 0;
  if (j)
    i = 1;
  h = 0;
  for (; h < 8; h++) {
    printf("%d\n", f[h].b);
    transparent_crc(f[h].c, "", i);
    transparent_crc(g, "", i);
    transparent_crc(f[h].d, "", i);
    printf("%d\n", f[h].e);
    if (i)
      printf("index = \n");
  }
  for (; h < 10; h++)
    transparent_crc(h, "", i);
  h = 0;
  for (; h < 10; h++)
    transparent_crc(h, "", i);
}
/* ProgramSourceCsmithReduce */
