/* corpus/addsub_float_inexact.c */
/* SV-comp: addsub_float_inexact.c */
#include <assert.h>

int main()
{
  float x, y, z, r;

  x = 1e8f;
  y = x + 1.f;
  z = x - 1.f;
  r = y - z; 
  assert(r == 0.f);
  return 0;
}
/* ProgramSourceWild */
