/* corpus/0bc6ce7a6356b376e4dc9802b83464a5_849_test228030675.c */
#include "csmith.h"
union a {
  uint16_t b;
  uint32_t c;
};
static uint16_t d, aa = 1, m, n = 65535, g, f, e;
static int64_t *h = &g;
static uint16_t *k = &n;
static uint16_t *l;
static union a ab[2][1] = {29888};
static union a ac, ad = {17576};
static union a ag[10] = {65530, {}, {}, 65530};
int16_t am();
uint64_t at() {
  am(d);
  return 0;
}
int16_t am(ax) {
  uint64_t *ay = &m;
  e = safe_sub_func_int8_t_s_s(
      (*ay = safe_mul_func_int32_t_s_s((*k = h != ax) < 7, ax)) &&
          4073709551608,
      2);
  return 0;
}
int8_t ar() {
  uint16_t *br = &d;
  uint16_t *bs = &br;
  for (;;)
    l = bs;
}
int main() {
  int i, j, bt = 0;
  crc32_gentab();
  transparent_crc(e, "", bt);
  transparent_crc(f, "", bt);
  transparent_crc(n, "", bt);
  transparent_crc(m, "", bt);
  for (i = 0; i < 3; i++)
    for (j = 0; j < 10; j++)
      transparent_crc(aa, "", bt);
  for (i = 0; i < 2; i++)
    for (j = 0; j < 1; j++)
      transparent_crc(ab[i][j].b, "", bt);
  i = 0;
  transparent_crc(ac.c, "", bt);
  transparent_crc(ad.b, "", bt);
  for (; i < 10; i++)
    transparent_crc(ag[i].b, "", bt);
  platform_main_end(crc32_context ^ 4294967295, bt);
}
/* ProgramSourceCsmithReduce */
