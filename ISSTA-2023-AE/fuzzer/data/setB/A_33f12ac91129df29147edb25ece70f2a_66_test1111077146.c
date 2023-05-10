/* corpus/33f12ac91129df29147edb25ece70f2a_66_test1111077146.c */
#include "csmith.h"
struct a {
  signed : 27;
  unsigned : 22;
  signed : 17;
  unsigned : 18;
  unsigned : 31;
};
struct b {
  int32_t c;
};
struct {
  struct b d;
} static e;
static int *f = &e, *g = &f;
static struct a h;
struct a i() {
  for (e.d.c = 0;;)
    return h;
}
int *j() { return g; }
int8_t k() {
  int32_t l = 1;
  i();
  return l;
}
int main() {
  int m = k();
  platform_main_end(15, m);
}
/* ProgramSourceCsmithReduce */
