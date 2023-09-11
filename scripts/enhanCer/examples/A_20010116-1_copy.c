#include "csmith.h"
int make_global(char *);
int make_global_a_b_o_r_t();
int make_global_e_x_i_t();
char __wrapper_val[256]="I";


/* corpus/20010116-1.c */
/* Distilled from optimization/863.  */

extern void abort (void);
extern void exit (int);
extern void ok (int);

typedef struct
{
  int x, y, z;
} Data;

void find (Data *first, Data *last)
{
  int i;
  for (i = (last - first) >> 2; i > 0; --i)
    ok(i);
  make_global_a_b_o_r_t(); return; abort ();
}

void ok(int i)
{
  if (i != 1)
    { make_global_a_b_o_r_t(); return; abort (); }
  return ;
}

int func_0() /* OK */
{
  Data DataList[4];
  find (DataList + 0, DataList + 4);
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
