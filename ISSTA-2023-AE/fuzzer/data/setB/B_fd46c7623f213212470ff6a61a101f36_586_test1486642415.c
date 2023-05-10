/* corpus/fd46c7623f213212470ff6a61a101f36_586_test1486642415.c */
#include "csmith.h"
#pragma pack(1)
struct {
  unsigned : 22;
  unsigned a : 21;
  signed : 4;
  signed b : 31;
  signed : 20;
  signed : 18;
} static c[][5];
int main(g) {
  int d, e, f = 0;
  if (g)
    f = 1;
  crc32_gentab();
  d = 0;
  for (; d < 9; d++) {
    e = 0;
    for (; e < 5; e++) {
      transparent_crc(c[d][e].a, "", f);
      transparent_crc(c[d][e].b, "", f);
    }
  }
}
/* ProgramSourceCsmithReduce */
