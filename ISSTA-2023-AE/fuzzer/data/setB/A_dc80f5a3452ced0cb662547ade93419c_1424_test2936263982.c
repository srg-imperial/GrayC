/* corpus/dc80f5a3452ced0cb662547ade93419c_1424_test2936263982.c */
#include "csmith.h"
static int32_t a, b;
static int32_t *c = &a;
static int32_t **d = &c;
static uint8_t *e = &b;
static uint32_t f;
int8_t g() {
  *e = 255;
  for (; f <= 6; f++)
    **d ^= ++*e;
  return 0;
}
int main() {
  int h = g();
  platform_main_end(5, h);
}
/* ProgramSourceCsmithReduce */
