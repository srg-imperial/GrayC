/* corpus/dbf103e85f5bd8c175ca4f10499bd57d_1536_test3319767039.c */
#include "csmith.h"
int32_t static a;
static int32_t *b = &a;
static int32_t **c = &b;
int32_t *d();
int32_t e() {
  int32_t *f;
  if ((f = d()) == 0)
    *f = 0;
  return 0;
}
int32_t *d() { return *c; }
int main() {
  int g = e();
  platform_main_end(5, g);
}
/* ProgramSourceCsmithReduce */
