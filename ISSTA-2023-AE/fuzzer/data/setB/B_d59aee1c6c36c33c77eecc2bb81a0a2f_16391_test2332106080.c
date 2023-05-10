/* corpus/d59aee1c6c36c33c77eecc2bb81a0a2f_16391_test2332106080.c */
#include "csmith.h"
static int32_t a;
static int32_t *b = &a;
int32_t c(int32_t **d) {
  int e;
  int32_t f[2];
  for (e = 0; e < 2; e++)
    f[e] = 2;
  if (*b)
    for (;;)
      ;
  *d = f;
  return 0;
}
int8_t g(int8_t h, int32_t *, uint32_t, int32_t *) { return h; }
int main() {
  int32_t i;
  g(0, &i, 0, &b);
  platform_main_end(15, 0);
}
/* ProgramSourceCsmithReduce */
