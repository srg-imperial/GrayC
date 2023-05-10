/* corpus/3394a5d3b8e99de8b5bdc99fcfa73e8f_891_test130279262.c */
#include "csmith.h"
struct {
  int8_t a;
  volatile int64_t b;
  volatile uint8_t c;
  uint32_t d;
} static e[4][6][10];
int main(j) {
  int f, g, h, i = 0;
  if (j)
    i = 1;
  f = 0;
  for (; f < 4; f++) {
    g = 0;
    for (; g < 6; g++) {
      h = 0;
      for (; h < 10; h++) {
        printf("%d\n", e[f][g][h].a);
        transparent_crc(e[f][g][h].b, "", i);
        transparent_crc(e[f][g][h].c, "", e[f][g][h].d);
        printf("index = %d\n", f, g, h);
      }
    }
  }
  platform_main_end(crc32_context, i);
}
/* ProgramSourceCsmithReduce */
