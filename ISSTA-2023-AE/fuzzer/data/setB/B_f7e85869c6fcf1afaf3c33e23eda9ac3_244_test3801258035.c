/* corpus/B_f7e85869c6fcf1afaf3c33e23eda9ac3_244_test3801258035.c */
#include "csmith.h"
struct {
  unsigned a : 23;
} static b[];
int main() {
  char a;
  int c, d, e, f = 0;
  if (strcmp(&a, "1"))
    f = 1;
  crc32_gentab();
  c = 0;
  for (; c < 3; c++) {
    d = 0;
    for (; d < 3; d++) {
      e = 0;
      for (; e < 9; e++)
        transparent_crc(b[c * d * e].a, "", f);
    }
  }
}
/* ProgramSourceCsmithReduce */
