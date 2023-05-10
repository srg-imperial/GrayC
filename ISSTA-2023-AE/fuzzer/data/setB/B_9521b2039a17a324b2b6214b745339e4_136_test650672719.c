/* corpus/9521b2039a17a324b2b6214b745339e4_136_test650672719.c */
#include "csmith.h"
#pragma pack(1)
struct a {
  unsigned : 27;
  signed b : 18;
  unsigned c : 20;
};
struct {
  uint8_t b;
  struct a d;
} static e[][5];
static int f;
int main(j) {
  int g, h, i = 0;
  if (j)
    i = 1;
  crc32_gentab();
  g = 0;
  for (; g < 7; g++) {
    h = 0;
    for (; h < 5; h++) {
      transparent_crc(e[g][h].b, "", i);
      transparent_crc(f, "", i);
      transparent_crc(e[g][h].d.b, "", i);
      transparent_crc(e[g][h].d.c, "g_142.f3.f2", i);
      printf("index = %d\n", g, h);
    }
  }
}
/* ProgramSourceCsmithReduce */
