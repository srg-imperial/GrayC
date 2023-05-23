#include "csmith.h"
int make_global(char *);
int make_global_a_b_o_r_t();
int make_global_e_x_i_t();
char __wrapper_val[256]="I";


/* corpus/20050604-1.c */
/* PR regression/21897 */
/* This testcase generates MMX instructions together with x87 instructions.
   Currently, there is no "emms" generated to switch between register sets,
   so the testcase fails for targets where MMX insns are enabled.  */
/* { dg-options "-mno-mmx" { target { x86_64-*-* i?86-*-* } } } */

extern void abort (void);

typedef unsigned short v4hi __attribute__ ((vector_size (8)));
typedef float v4sf __attribute__ ((vector_size (16)));

union
{
  v4hi v;
  short s[4];
} u;

union
{
  v4sf v;
  float f[4];
} v;

void
foo (void)
{
  unsigned int i;
  for (i = 0; i < 2; i++)
    u.v += (v4hi) { 12, 32768 };
  for (i = 0; i < 2; i++)
    v.v += (v4sf) { 18.0, 20.0, 22 };
}

int func_0()
{
  foo ();
  if (u.s[0] != 24 || u.s[1] != 0 || u.s[2] || u.s[3])
    { make_global_a_b_o_r_t(); return 0; abort (); }
  if (v.f[0] != 36.0 || v.f[1] != 40.0 || v.f[2] != 44.0 || v.f[3] != 0.0)
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
	platform_main_end(crc32_context ^ 0xFFFFFFFFUL, i_print_hash_value);
	return 0;
}
	