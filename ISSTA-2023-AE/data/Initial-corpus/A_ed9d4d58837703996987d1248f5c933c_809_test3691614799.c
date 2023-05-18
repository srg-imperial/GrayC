/* corpus/ed9d4d58837703996987d1248f5c933c_809_test3691614799.c */
#include "csmith.h"
struct a {
  uint32_t b;
};
static uint32_t c[] = {4294967295, 3568996969, 3568996969, 4294967295};
static struct a d[] = {3759749925, 3759749925};
char *e;
int main_argc;
void main() {
  int f, g = 0;
  if (main_argc && strcmp(e, "")) {
    g = 1;
  }
  crc32_gentab();
  f = 0;
  for (; f < 10; f++) {
    transparent_crc(c[f], "", g);
    transparent_crc(d[f].b, "", g);
    if (g) {
      printf("index = \n");
    }
  }
}
/* ProgramSourceCsmithReduce */
