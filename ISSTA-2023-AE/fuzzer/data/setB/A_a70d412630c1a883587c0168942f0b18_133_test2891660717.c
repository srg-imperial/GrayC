/* corpus/a70d412630c1a883587c0168942f0b18_133_test2891660717.c */
#include "csmith.h"
struct a {
  uint64_t b;
  uint64_t c;
  uint32_t d;
  uint32_t e;
};
struct f {
  uint32_t b;
  struct a e;
};
struct g {
  int32_t b;
};
static struct a h, j = {4294967293};
static struct a o[] = {5496374835597733511, 4073709551615, 0, 6,
                       5496374835597733511, 4073709551615, 0, 6,
                       5496374835597733511, 4073709551615, 0, 6,
                       884688817170345607};
static int64_t k;
static struct f l, n = {377364212};
static struct a m = {4073709551615, 16628217138730297598};
static struct g aa = {1};
struct f ab() {
  k ^= ~0;
  return l;
}
uint32_t c() {
  for (;;)
    ab();
}
int main() {
  int i, aj = 0;
  crc32_gentab();
  transparent_crc(h.d, "", aj);
  for (i = 0; i < 4; i++)
    transparent_crc(o[i].b, "", aj);
  for (; i < 6; i++)
    transparent_crc(j.b, "", aj);
  transparent_crc(m.c, "", aj);
  transparent_crc(n.b, "", aj);
  transparent_crc(aa.b, "", aj);
  platform_main_end(crc32_context ^ 4294967295, aj);
}
/* ProgramSourceCsmithReduce */
