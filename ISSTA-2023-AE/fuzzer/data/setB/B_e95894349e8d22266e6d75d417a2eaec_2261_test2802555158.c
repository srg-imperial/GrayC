/* corpus/e95894349e8d22266e6d75d417a2eaec_2261_test2802555158.c */
#include "csmith.h"
static int32_t a, d, c;
static uint16_t b[][1][4];
uint32_t e();
uint32_t f() {
  int32_t *g = &a;
  if (*g)
    e();
  return 0;
}
uint32_t e() {
  int h = 0;
  int32_t *m = &a;
  uint16_t *l = b;
  for (c = 0; c != 19; c = safe_add_func_int64_t_s_s(c, 1))
    for (d = 0; d <= 2; d++)
      *m = h ^= safe_div_func_int64_t_s_s(1, b[0][d][0]);
  *l = 0;
  return 0;
}
int main() {
  int i, j, k;
  for (i = j = k = 0; k < 4; k++)
    printf("%d\n", b[i][j][k]);
}
/* ProgramSourceCsmithReduce */
