/* corpus/00053ab3438bd1ac975e7d5be74ddd04_3353_test3265897119.c */
#include "csmith.h"
static uint16_t a;
static uint32_t b = 3826258657;
static int8_t c = 190;
static uint64_t d[][5][9] = {{}, 18446744073709551615, 6448662444215188141, 1};
static int8_t e[10][1][9];
static int32_t f = 3970379725;
int main() {
  int g, h, i, j = 0;
  crc32_gentab();
  transparent_crc(a, "", j);
  g = 0;
  transparent_crc(b, "", j);
  transparent_crc(c, "", j);
  for (; g < 2; g++)
    for (h = 0; h < 5; h++)
      for (i = 0; i < 9; i++)
        transparent_crc(d[g][h][i], "", j);
  for (h = i = 0; i < 9; i++)
    transparent_crc(e[g][h][i], "", j);
  transparent_crc(f, "", j);
  platform_main_end(crc32_context ^ 4294967295, j);
}
/* ProgramSourceCsmithReduce */
