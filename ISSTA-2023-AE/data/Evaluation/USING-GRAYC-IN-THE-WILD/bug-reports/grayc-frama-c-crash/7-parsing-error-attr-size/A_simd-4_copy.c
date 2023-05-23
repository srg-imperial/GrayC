#include "csmith.h"
int make_global(char *);
int make_global_a_b_o_r_t();
int make_global_e_x_i_t();
char __wrapper_val[256]="I";


/* corpus/simd-4.c */
/* { dg-require-effective-target stdint_types } */
#include <stdint.h>
typedef int32_t __attribute__((vector_size(8))) v2si;
int64_t s64;

static inline int64_t
__ev_convert_s64 (v2si a)
{
  return (int64_t) a;
}

int func_0()
{
  union { int64_t ll; int32_t i[2]; } endianness_test;
  endianness_test.ll = 1;
  int32_t little_endian = endianness_test.i[0];
  s64 = __ev_convert_s64 ((v2si){1,0xffffffff});
  if (s64 != (little_endian ? 0xffffffff00000001LL : 0x1ffffffffLL))
    { make_global_a_b_o_r_t(); return 0; abort (); }
  return 0;
}

int i_csmith_transform = 0;
int i_print_hash_value = 0;
int make_global_a_b_o_r_t(){
	transparent_crc(i_csmith_transform, "abort call", i_print_hash_value);
	i_csmith_transform=i_csmith_transform+1;
	return 0;
} 

int make_global_e_x_i_t(){
	transparent_crc(i_csmith_transform, "abort exit", i_print_hash_value);
	i_csmith_transform=i_csmith_transform+1;
	return 0;
} 

int make_global(char *val){
	if ((val == 0) || (strlen(val) == 0)) {
		transparent_crc(i_csmith_transform, "empty string", i_print_hash_value);
	} else {
		char name[100]; sprintf(name, "gprnt%d", i_csmith_transform);
		transparent_crc_bytes(val, strlen(val), name , i_print_hash_value);
	}
	i_csmith_transform=i_csmith_transform+1;
	return 0;
} 
int main(int argc, char* argv[]){
	if (argc == 2 && strcmp(argv[1], "1") == 0) i_print_hash_value = 1;
	platform_main_begin();
	crc32_gentab();
	func_0(); /* Original main of the program */
	make_global(__wrapper_val); /* Print the last use of the wrapper, or if never used it will print empty string */
	transparent_crc(s64, "s64", i_print_hash_value);
	platform_main_end(crc32_context ^ 0xFFFFFFFFUL, i_print_hash_value);
	return 0;
}
	