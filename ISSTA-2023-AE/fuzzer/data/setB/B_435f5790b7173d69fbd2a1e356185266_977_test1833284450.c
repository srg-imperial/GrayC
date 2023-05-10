/* corpus/435f5790b7173d69fbd2a1e356185266_977_test1833284450.c */
#include "csmith.h"
union a {};
static int32_t b[];
static uint32_t c, m, h, e;
static int8_t d[8];
static int8_t *f = d;
static int8_t **g = &f;
static uint16_t *i;
static uint16_t *n = &i;
static uint16_t *j = &n;
static uint16_t *k = &j;
static uint16_t *volatile l = &k;
static const union a u(int32_t *, int32_t, uint8_t, int32_t *, int64_t);
int32_t o() { return m; }
int32_t p() {
  int *q = 0;
  u(q, 0, 0, 0, 0);
  return 0;
}
const union a u(int32_t *, int32_t r, uint8_t s, int32_t *, int64_t) {
  union a t = {};
  for (; c <= 2; c++) {
    int8_t *ab = d;
    for (e = 3; e <= 8; e++)
      for (h = 6; h; h--)
        b[0] ^=
            safe_rshift_func_uint32_t_u_u(
                safe_rshift_func_uint8_t_u_u((*i = 4 == ab, **g), r), r) == s;
    l;
  }
  return t;
}
int main() {
  int a = o();
  platform_main_end(15, a);
}
/* ProgramSourceCsmithReduce */
