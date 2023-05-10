/* corpus/70863bf894fc0768aa62dad4f56243ef_402_test1792490633.c */
#include "csmith.h"
struct a {
  unsigned b : 3;
  signed c : 14;
};
static uint32_t d[][9][2];
static struct a e[][25];
int main(j) {
  char a;
  int f, g, h, i = 0;
  if (j && strcmp(&a, "1"))
    i = 1;
  crc32_gentab();
  g = 0;
  for (; g < 7; g++) {
    h = 0;
    for (; h < 2; h++)
      printf("index = %d\n", h);
  }
  f = 0;
  for (; f < 2; f++) {
    g = 0;
    for (; g < 9; g++) {
      h = 0;
      for (; h < 2; h++) {
        printf("%d\n", d[f][g][h]);
        if (i)
          printf("index = %d\n", h);
      }
    }
  }
  for (; f < 10; f++) {
    g = 0;
    for (; g < 5; g++) {
      h = 0;
      for (; h < 5; h++) {
        transparent_crc(e[f][g * 5 + h].b, "", i);
        transparent_crc(e[f][g * 5 + h].c, "", i);
        if (i)
          printf("index = %d\n", f, g);
      }
    }
  }
}
/* ProgramSourceCsmithReduce */
