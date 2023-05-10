/* corpus/49846596e2e284c1bdd04191eaf17b54_166_test2666877218.c */
#include "csmith.h"
struct a {
  int8_t b;
};
struct c {
  uint64_t d;
  signed : 8;
  int32_t e;
  int32_t f;
};
struct g {
  struct c h;
};
struct {
  uint16_t b;
} static i, l, *j = &l;
static volatile struct g k;
void n() {
  volatile struct a *m = &i;
  for (; l.b;)
    *m;
}
struct g p() {
  n(j);
  return k;
}
int main() {
  p();
  platform_main_end(15, 0);
}
/* ProgramSourceCsmithReduce */
