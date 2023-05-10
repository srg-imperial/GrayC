/* corpus/5fa27f0dce47eab411bccf1d25aa8ea5_2147_test4195491462.c */
#include "csmith.h"
struct a {
  unsigned b : 2;
  signed c : 4;
};
static volatile struct a d[][9][4];
static int e;
int main() {
  int f, g;
  f = 0;
  for (; f < 9; f++) {
    g = 0;
    for (; g < 4; g++) {
      transparent_crc(e, "", d[0][f][g].b);
      d[0][f][g].c;
      printf("index = \n");
    }
  }
}
/* ProgramSourceCsmithReduce */
