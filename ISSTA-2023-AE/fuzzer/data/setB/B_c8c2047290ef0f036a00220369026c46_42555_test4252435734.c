/* corpus/c8c2047290ef0f036a00220369026c46_42555_test4252435734.c */
#include "csmith.h"
#pragma pack(1)
struct a {
  signed b : 9;
  signed c : 6;
  signed d : 7;
};
struct e {
  signed b : 21;
  signed c;
  unsigned d : 23;
  unsigned f;
  unsigned g : 30;
  struct a h;
  signed : 9;
  unsigned : 24;
};
static volatile struct e m[];
static volatile int j;
static volatile uint64_t k[];
int main(n) {
  int i, l = 0;
  if (n)
    l = 1;
  i = 0;
  for (; i < 9; i++) {
    printf("%d\n", m[i].b);
    printf("%d\n", m[i].c);
    printf("%d\n", m[i].d);
    printf("%d\n", m[i].f);
    printf("%d\n", m[i].g);
    transparent_crc(j, "", l);
    transparent_crc(m[i].h.b, "", l);
    printf("%d\n", m[i].h.c);
    printf("%d\n", m[i].h.d);
  }
  for (i = 0; i < 3; i++)
    transparent_crc(k[i], "", l);
}
/* ProgramSourceCsmithReduce */
