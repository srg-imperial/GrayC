/* corpus/5aca23c895e89fa35bd8604b4a39d65a_2066_test2509630935.c */
#include "csmith.h"
struct {
  uint32_t a;
} b[];
int main(argc) {
  int c, d = 0;
  if (argc)
    for (c = 0; c < 6; c++)
      transparent_crc(b[c].a, "", d);
  platform_main_end(crc32_context, d);
}
/* ProgramSourceCsmithReduce */
