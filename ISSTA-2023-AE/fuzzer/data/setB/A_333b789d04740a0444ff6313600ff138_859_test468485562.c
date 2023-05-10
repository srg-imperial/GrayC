/* corpus/333b789d04740a0444ff6313600ff138_859_test468485562.c */
#include "csmith.h"
struct a {
  int16_t b;
};
static uint64_t c = 6;
static uint8_t d = 187;
static uint32_t e = 1811361613;
static struct a f[3][8][8];
static int32_t g[] = {-1L, 1, 1, 1, 1};
static int8_t h = 203;
static struct a n[2][6][4] = {1, 111};
int32_t l() {
  int q = 0, m = 0, i;
  uint8_t o[7];
  for (i = 0;; i++)
    o[i] = safe_rshift_func_int8_t_s_u(
        safe_mul_func_int32_t_s_s(
            safe_mod_func_int64_t_s_s(
                safe_lshift_func_uint32_t_u_u(
                    safe_lshift_func_uint32_t_u_s(6 && 5, 3), o[1]),
                6828154824),
            m),
        q);
}
int main() {
  int i, j, k, p = 0;
  crc32_gentab();
  transparent_crc(c, "", p);
  transparent_crc(d, "", p);
  i = 0;
  transparent_crc(e, "", p);
  for (; i < 3; i++)
    for (j = 0; j < 8; j++)
      for (k = 0; k < 8; k++)
        transparent_crc(f[i][j][k].b, "", p);
  for (i = 0; i < 5; i++)
    transparent_crc(g[i], "", p);
  transparent_crc(h, "", p);
  for (i = 0; i < 2; i++)
    for (j = 0; j < 6; j++)
      for (k = 0; k < 4; k++)
        transparent_crc(n[i][j][k].b, "", p);
  platform_main_end(crc32_context ^ 4294967295, p);
}
/* ProgramSourceCsmithReduce */
