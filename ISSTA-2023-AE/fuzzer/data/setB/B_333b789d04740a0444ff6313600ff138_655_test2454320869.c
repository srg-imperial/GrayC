/* corpus/333b789d04740a0444ff6313600ff138_655_test2454320869.c */
#include "csmith.h"
static int32_t a;
static uint8_t b[];
static int32_t *c = &a;
uint8_t d();
uint8_t *const e();
int64_t f() {
  uint8_t g = d(e());
  return g;
}
uint8_t d(uint8_t *h) {
  int i = 2;
  *h = safe_div_func_uint16_t_u_u(
      safe_div_func_int32_t_s_s(
          safe_lshift_func_int64_t_s_s(
              safe_div_func_uint32_t_u_u(safe_lshift_func_uint64_t_u_u(b[1], 0),
                                         *c),
              2),
          9),
      i);
  return 0;
}
uint8_t *const e() { return b; }
int main() {
  int j = f();
  platform_main_end(5, j);
}
/* ProgramSourceCsmithReduce */
