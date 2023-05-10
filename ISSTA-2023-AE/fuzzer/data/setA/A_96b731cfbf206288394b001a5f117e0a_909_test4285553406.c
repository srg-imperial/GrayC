/* corpus/96b731cfbf206288394b001a5f117e0a_909_test4285553406.c */
#include "csmith.h"
struct {
  int32_t a;
} b;
struct c {
  unsigned : 4;
  signed : 31;
  uint32_t d;
};
struct e {
  struct c a;
  unsigned : 7;
  uint32_t f;
};
struct e g();
int32_t h();
uint32_t i() { g(); }
struct e g() {
  struct e j = {};
  h();
  return j;
}
int32_t h() { b.a = 8; }
int main() { i(); }
/* ProgramSourceCsmithReduce */
