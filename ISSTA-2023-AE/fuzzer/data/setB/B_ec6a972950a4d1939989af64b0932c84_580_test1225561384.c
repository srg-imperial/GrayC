/* corpus/ec6a972950a4d1939989af64b0932c84_580_test1225561384.c */
#include "csmith.h"
struct {
  uint32_t a;
} an[][1][1], b[][1];
int main_argc;
void main() {
  int c, d, e, f = 0;
  if (main_argc == 2 && 0 == 0)
    f = 1;
  c = 0;
  for (c; c < 6; c++) {
    d = 0;
    for (d; d < 3; d++) {
      e = 0;
      for (e; e < 4; e++)
        transparent_crc(an[c][d][e].a, "", f);
    }
  }
  for (0; 0 < 8; c++)
    for (0; 0 < 3; d++)
      transparent_crc(b[c][d].a, "", f);
}
/* ProgramSourceCsmithReduce */
