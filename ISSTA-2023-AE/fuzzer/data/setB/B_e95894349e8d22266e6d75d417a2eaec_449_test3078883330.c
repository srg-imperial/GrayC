/* corpus/e95894349e8d22266e6d75d417a2eaec_449_test3078883330.c */
#include "csmith.h"
struct a {
  int32_t b;
} e;
struct c {
  struct a d;
};
struct {
  struct c f;
} g;
struct {
  int32_t h;
} l, m;
int32_t *p();
int32_t n() {
  int32_t *o = &e;
  for (;;) {
    o;
    for (; g.f.d.b;) {
      for (; m.h;) {
        o = p();
      }
    }
  }
}
int32_t *p() {
  int32_t *s[2][8][6];
  int i, j, k;
  for (i = 0; i < 2; i++) {
    for (j = 0; j < 8; j++) {
      for (k = 0; k < 6; k++) {
        s[i][j][k] = &l;
      }
    }
  }
  return s;
}
int main() {}
/* ProgramSourceCsmithReduce */
