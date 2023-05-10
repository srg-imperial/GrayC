/* corpus/96b731cfbf206288394b001a5f117e0a_1000_test1685993806.c */
#include "csmith.h"
#pragma pack(1)
struct a {
  int32_t b;
  unsigned c : 15;
  unsigned : 24;
};
static int32_t d[][1][1];
uint16_t e() {
  struct a f;
  uint8_t g;
  int h;
  int32_t *i = d;
  for (h = 0;;)
    for (g = 0; g <= 2; g++) {
      d[g][0][0] = f.c;
      for (; h < 5; h++)
        for (; f.b; f.b--)
          *i |= f.c = 1;
    }
}
int main() { platform_main_end(15, 0); }
/* ProgramSourceCsmithReduce */
