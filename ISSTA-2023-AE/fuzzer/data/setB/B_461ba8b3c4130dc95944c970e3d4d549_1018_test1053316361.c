/* corpus/461ba8b3c4130dc95944c970e3d4d549_1018_test1053316361.c */
#include "csmith.h"
static uint64_t g_100[];
int main() {
  int i;
  int print_hash_value = 0;
  for (i = 0; i < 7; i++)
    transparent_crc(g_100[i], "g_100", print_hash_value);
  for (i = 0; i < 4; i++)
    platform_main_end(crc32_context ^ 0xFFFFFFFFUL, print_hash_value);
}
/* ProgramSourceCsmithReduce */
