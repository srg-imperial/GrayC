/* corpus/d59aee1c6c36c33c77eecc2bb81a0a2f_6537_test83361595.c */
#include "csmith.h"
#pragma pack(1)
struct {
  signed : 28;
  signed : 3;
  signed : 26;
  unsigned : 29;
  unsigned : 26;
  unsigned a : 25;
} static b[][6];
static int c;
int main() {
  int d, e;
  d = 0;
  for (; d < 6; d++) {
    e = 0;
    for (; e < 6; e++) {
      transparent_crc(c, "", 1);
      printf("%d\n", b[d][e].a);
    }
  }
}
/* ProgramSourceCsmithReduce */
