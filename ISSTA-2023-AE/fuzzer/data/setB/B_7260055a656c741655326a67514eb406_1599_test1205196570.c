/* corpus/7260055a656c741655326a67514eb406_1599_test1205196570.c */
#include "csmith.h"
#pragma pack(1)
struct a {
  unsigned b;
  signed c : 4;
  signed d : 10;
  unsigned e : 7;
  unsigned f : 4;
  signed g : 8;
  signed h;
};
struct {
  struct a b;
  unsigned c;
  signed k;
} static l[][6];
int main(n) {
  int i, j, m = 0;
  if (n)
    m = 1;
  crc32_gentab();
  i = 0;
  for (; i < 2; i++) {
    j = 0;
    for (; j < 6; j++) {
      printf("%d\n", l[i][j].b.b);
      transparent_crc(l[i][j].b.c, "", m);
      transparent_crc(l[i][j].k, "", m);
      transparent_crc(l[i][j].b.d, "", m);
      transparent_crc(l[i][j].b.e, "", m);
      transparent_crc(l[i][j].b.f, "", m);
      transparent_crc(l[i][j].b.g, "", m);
      transparent_crc(l[i][j].b.h, "", m);
      transparent_crc(l[i][j].c, "", m);
      transparent_crc(l[i][j].k, "g_1622.f2", m);
      if (m)
        printf("index = %d\n", i, j);
    }
  }
}
/* ProgramSourceCsmithReduce */
