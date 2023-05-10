/* corpus/__restore_test2638255912.c */
#include "csmith.h"
static uint8_t g_42[];
int main() {
  int i;
  int print_hash_value = 0;
  for (i = 0; i < 4; i++)
    transparent_crc(g_42[i], "g_42", print_hash_value);
  platform_main_end(crc32_context ^ 0xFFFFFFFFUL, print_hash_value);
}
/* ProgramSourceCsmithReduce */
