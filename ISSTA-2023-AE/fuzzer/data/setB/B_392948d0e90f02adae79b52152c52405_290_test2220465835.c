/* corpus/392948d0e90f02adae79b52152c52405_290_test2220465835.c */
#include "csmith.h"
static int32_t a, d;
static int32_t *b = &a;
static int32_t **c = &b;
static int64_t *e = &d;
static int64_t **f = &e;
static int32_t g();
uint64_t h() {
  **f = safe_div_func_int32_t_s_s(g(c), 0);
  return 0;
}
int32_t g(int32_t **j) {
  int i = 0;
  for (; i < 1; i++)
    ;
  return **j;
}
int main() {
  int k = h();
  platform_main_end(5, k);
}
/* ProgramSourceCsmithReduce */
