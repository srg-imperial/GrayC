/* corpus/01d3664e71d14fd961a130472a523e1d_3435_test1508451437.c */
#include "csmith.h"
union a {
  uint32_t b;
  int8_t *c;
};
struct d {
  uint16_t b;
};
static union a e, f;
static struct d g;
static union a h[];
union a n() {
  union a j = {4208444235};
  j.b;
  for (; 0;)
    return e;
  return j;
}
uint32_t k() {
  union a *l = &f;
  *l = n();
  return g.b;
}
int main() {
  int i, m = 1;
  k();
  i = 0;
  transparent_crc(h[i].b, "", m);
}
/* ProgramSourceCsmithReduce */
