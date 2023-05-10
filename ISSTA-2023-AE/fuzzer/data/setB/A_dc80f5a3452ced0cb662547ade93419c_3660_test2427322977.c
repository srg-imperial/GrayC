/* corpus/dc80f5a3452ced0cb662547ade93419c_3660_test2427322977.c */
#include "csmith.h"
static int32_t a;
static int32_t *b = &a;
const int16_t c();
static int64_t d(int8_t);
int8_t e() {
  c(b);
  return 0;
}
const int16_t c(int32_t) {
  int64_t f = 4;
  d(f);
  return 0;
}
int64_t d(int8_t g) {
  for (; g >= 0; g--)
    if (g)
      if (*b)
        break;
  return g;
}
int main() {
  int h = e();
  platform_main_end(15, h);
}
/* ProgramSourceCsmithReduce */
