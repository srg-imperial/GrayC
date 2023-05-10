/* corpus/fd46c7623f213212470ff6a61a101f36_950_test1169404779.c */
#include "csmith.h"
#pragma pack(1)
struct a {
  unsigned : 19;
  unsigned : 20;
  unsigned b : 22;
  signed : 27;
  signed : 17;
  unsigned : 19;
  signed : 28;
  signed : 19;
  unsigned : 29;
};
struct {
  volatile struct a c;
} d, e;
int32_t *f;
uint32_t g() {
  int32_t h = 103;
  for (; h; h--) {
    uint64_t *i = &d;
    uint64_t **k = &i;
    int32_t j = 9;
    **k = 89;
    *f = e.c.b || (*i = j);
  }
}
int main() {}
/* ProgramSourceCsmithReduce */
