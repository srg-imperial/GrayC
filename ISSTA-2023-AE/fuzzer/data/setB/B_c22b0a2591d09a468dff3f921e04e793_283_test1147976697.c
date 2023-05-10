/* corpus/c22b0a2591d09a468dff3f921e04e793_283_test1147976697.c */
#include "csmith.h"
static uint8_t a[] = {1};
static volatile int32_t b[][5];
static int32_t c, f = 2, e, d;
int32_t g() {
  for (; c >= 0; c--)
    for (d = 5; d; d--)
      for (e = 4; e; e--) {
        int32_t *h = &f;
        *h &= a[0] ^ b[1][2];
      }
  return 0;
}
int main() {
  int i = g();
  platform_main_end(5, i);
}
/* ProgramSourceCsmithReduce */
