/* corpus/845cb1850cf37870c2388526fbe2ba04_345_test25641400.c */
#include "csmith.h"
static int32_t a;
static int32_t *b = &a;
static int32_t *c = &b;
static int32_t **d = &c;
int32_t *e();
int8_t f() {
  *d = e();
  return 2;
}
int32_t *e() {
  int16_t *g = 0;
  if (a) {
    int32_t h;
    int32_t *i = &a;
    if (*i &= 4) {
      int32_t *j = &h;
      d = j;
    }
  } else {
    int32_t k[] = {};
    *d = k;
  }
  return g;
}
int main() {
  int l = f();
  platform_main_end(5, l);
}
/* ProgramSourceCsmithReduce */
