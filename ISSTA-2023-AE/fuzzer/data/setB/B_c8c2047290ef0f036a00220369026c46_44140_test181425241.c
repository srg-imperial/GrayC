/* corpus/c8c2047290ef0f036a00220369026c46_44140_test181425241.c */
#include "csmith.h"
struct a {
  int32_t b;
  signed c;
  int32_t d;
  int32_t e;
  uint8_t f;
} static g, i, *j = &g;
static uint64_t h[][1];
static int32_t *k = &i;
static int32_t **l = &k;
int64_t m(struct a, uint8_t, int8_t *, uint32_t, int8_t);
uint32_t n() {
  int32_t o = 0;
  m(g, o, 0, h[0][0], 0);
  return 0;
}
int64_t m(struct a p, uint8_t, int8_t *, uint32_t, int8_t) {
  struct a q[3] = {};
  uint8_t *r = h;
  *j = q[2];
  if (**l) {
    *j = p;
    p.d = p.e;
  }
  *k = safe_lshift_func_uint16_t_u_s(safe_div_func_uint16_t_u_u(*r = p.b, g.d),
                                     p.f);
  return 0;
}
int main() {
  int s = n();
  platform_main_end(15, s);
}
/* ProgramSourceCsmithReduce */
