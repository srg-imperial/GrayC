/* corpus/00053ab3438bd1ac975e7d5be74ddd04_3106_test2128829647.c */
#include "csmith.h"
struct a {
  int32_t b;
};
union c {
  int32_t b;
};
struct d {
  uint64_t b;
};
struct e {
  int32_t b;
};
static int8_t f, u, n;
static int16_t g[] = {12955, 12955, 12955, 12955, 12955};
static int32_t h[][1];
static int32_t l;
static uint64_t m[6][1] = {7, {}, 6582792564536515963};
static uint64_t q;
static uint8_t o[8][10][3];
static struct d p = {3367204280954093479};
static uint32_t *r, *v = &u;
static struct a s[] = {683375954};
static struct e t[][8][4] = {{},
                             {{2962800004, 3890828997}, 1403498158},
                             {{}, {3890828997}, 7, 395915323, 395915323}};
static struct a ab = {489532903};
int8_t *ad();
uint8_t af() {
  uint64_t ag = 7;
  uint64_t *ah = m[1];
  uint32_t ak = ad(*ah = ag)[0];
  return ak;
}
int8_t *ad() {
  uint32_t ar[1];
  int32_t at = 0;
  int8_t *av = &n;
  int i;
  for (i = 0; i < 1; i++)
    ar[i] = 2;
  for (l = 0; l >= -25; --l) {
    union c aw = {};
    int32_t *ax = h[1];
    uint32_t *ay = ar;
    *v ^= safe_mul_func_int32_t_s_s(safe_sub_func_int16_t_s_s(ar[0], at), aw.b);
    *ax = safe_mod_func_int8_t_s_s(1, at);
    if ((*ay)--) {
      uint32_t *ba = ar;
      r = ba;
    }
    uint64_t *bb = &q;
    *bb = 5597975524275466245;
  }
  return av;
}
int main() {
  int i, j, k, be = 0;
  crc32_gentab();
  af();
  transparent_crc(f, "", be);
  for (i = 0; i < 5; i++)
    transparent_crc(g[i], "", be);
  for (i = 0; i < 5; i++)
    for (j = 0; j < 1; j++)
      transparent_crc(h[i][j], "", be);
  for (i = 0; i < 6; i++)
    for (j = 0; j < 1; j++)
      transparent_crc(m[i][j], "", be);
  transparent_crc(q, "", be);
  for (i = 0; i < 8; i++)
    for (j = 0; j < 10; j++)
      for (k = 0; k < 3; k++)
        transparent_crc(o[i][j][k], "", be);
  i = 0;
  transparent_crc(p.b, "", be);
  transparent_crc(s[i].b, "", be);
  for (; i < 3; i++)
    for (j = 0; j < 8; j++)
      for (k = 0; k < 4; k++)
        transparent_crc(t[i][j][k].b, "", be);
  transparent_crc(ab.b, "", be);
  platform_main_end(crc32_context ^ 4294967295, be);
}
/* ProgramSourceCsmithReduce */
