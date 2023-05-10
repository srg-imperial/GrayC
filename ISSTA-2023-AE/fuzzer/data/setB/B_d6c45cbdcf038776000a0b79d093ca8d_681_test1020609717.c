/* corpus/d6c45cbdcf038776000a0b79d093ca8d_681_test1020609717.c */
#include "csmith.h"
#pragma pack(1)
struct {
  unsigned a : 31;
  unsigned : 14;
  volatile signed b : 26;
} c, d;
uint32_t e;
int32_t f() {
  uint32_t g;
  uint32_t h;
  for (g = 0; g <= 3; g++)
    for (h = 0; h <= 3; h++) {
      uint64_t *i = &c;
      for (e = 0; e <= 3; e++)
        *i |= safe_rshift_func_int64_t_s_s(0, d.b) != d.a;
    }
}
int main() {}
/* ProgramSourceCsmithReduce */
