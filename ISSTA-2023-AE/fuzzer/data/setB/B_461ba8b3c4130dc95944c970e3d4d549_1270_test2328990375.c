/* corpus/461ba8b3c4130dc95944c970e3d4d549_1270_test2328990375.c */
#include "csmith.h"
union a {
  uint8_t b;
  int8_t *c;
} static d;
int8_t *e();
int32_t *f(uint16_t, uint8_t, union a);
uint8_t g() {
  e();
  return 0;
}
int8_t *e() {
  int h;
  union a i = {};
  int32_t *k = f(0, 0, i);
  *k = i.b;
  return &h;
}
int32_t *f(uint16_t, uint8_t, union a) { return &d; }
int main() {
  int j = g();
  platform_main_end(15, j);
}
/* ProgramSourceCsmithReduce */
