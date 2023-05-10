/* corpus/ed9d4d58837703996987d1248f5c933c_2086_test4282948520.c */
#include "csmith.h"
static uint64_t a[][9] = {32212418727, 5697323487,  32623401574,
                          7740891391,  44255353003, 5260439018};
int b;
int main_argc;
void main() {
  int c, d, e = 0;
  if (main_argc)
    e = 1;
  crc32_gentab();
  for (c = 0; c < 4; c++)
    for (d = 0; d < 9; d++)
      transparent_crc(a[c][d], "", e);
  transparent_crc(b, "", e);
}
/* ProgramSourceCsmithReduce */
