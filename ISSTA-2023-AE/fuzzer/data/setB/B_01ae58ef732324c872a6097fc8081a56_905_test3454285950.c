/* corpus/01ae58ef732324c872a6097fc8081a56_905_test3454285950.c */
#include "csmith.h"
struct a {
  signed c;
};
struct {
  uint8_t b;
} static *volatile d, e;
static int f, g;
static struct a h;
uint16_t i() { return 0; }
int32_t *j() {
  volatile struct a *a = &e;
  *a = h;
  return &g;
}
uint8_t k() {
  for (; e.b <= 1; e.b++)
    *d = *d;
  return f;
}
int main() {
  int b = i();
  platform_main_end(5, b);
}
/* ProgramSourceCsmithReduce */
