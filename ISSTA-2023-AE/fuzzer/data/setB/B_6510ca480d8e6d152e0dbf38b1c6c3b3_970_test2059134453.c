/* corpus/6510ca480d8e6d152e0dbf38b1c6c3b3_970_test2059134453.c */
#include "csmith.h"
static uint32_t a, f, e, b;
static uint16_t *c = &b;
static uint16_t **volatile d = &c;
static uint32_t *g = &f;
int32_t h(uint16_t, int16_t, uint8_t);
uint16_t i(int8_t, uint8_t, uint32_t);
int32_t j() {
  int64_t k = 0;
  int16_t l = 1;
  if (h(i(a, 0, k), g++ && 0, l))
    ++e;
  return 0;
}
int32_t h(uint16_t m, int16_t, uint8_t) { return m; }
uint16_t i(int8_t, uint8_t, uint32_t) { return **d; }
int main() {
  int n = j();
  platform_main_end(15, n);
}
/* ProgramSourceCsmithReduce */
