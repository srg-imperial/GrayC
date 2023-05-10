/* corpus/e0594b205bb91f030eae3b5dda5d9993_107_test3275613395.c */
#include "csmith.h"
struct a {
  uint16_t b;
  uint32_t c;
  uint16_t d;
  int64_t e;
} * f;
struct {
  struct a c;
} g;
struct a h() {
  struct a i = {6};
  return i;
}
int main() { g.c = *f = h(); }
/* ProgramSourceCsmithReduce */
