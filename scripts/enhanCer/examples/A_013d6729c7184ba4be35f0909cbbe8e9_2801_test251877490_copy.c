#include "csmith.h"
int make_global(char *);
int make_global_a_b_o_r_t();
int make_global_e_x_i_t();
char __wrapper_val[256]="I";


/* corpus/013d6729c7184ba4be35f0909cbbe8e9_2801_test251877490.c */
#include "csmith.h"
union a {
  uint32_t b;
};
static uint8_t c[][1]={1};
static uint32_t d = 5;
static int32_t e=0;
static uint64_t f=0;
static uint64_t *g = &f;
static uint64_t *h = &g;
static uint64_t ***i = &h;
static uint16_t j=0;
static uint32_t k=0;
static uint16_t l=0;
static uint16_t volatile *m = &l;
static int32_t *n(union a, uint64_t, uint32_t);
int32_t o() {
  union a p = {7};
  n(p, ***i, 0);
  return 8;
}
int32_t *n(union a q, uint64_t r, uint32_t s) {
  int32_t t = &k == d;
  if(t ^= c[e][j] != q.b)
    *m;
  return 0;
}
int func_0() /* OK */ {
  int u = o();
  platform_main_end(5, u);
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
	for (int i_0_0 = 0 ; i_0_0 < 1; i_0_0++){
		for (int i_0_1 = 0 ; i_0_1 < 1; i_0_1++){
		transparent_crc(c[i_0_0][i_0_1], "c[i_0_0][i_0_1]", i_print_hash_value);
	}
	}
	transparent_crc(d, "d", i_print_hash_value);
	transparent_crc(e, "e", i_print_hash_value);
	transparent_crc(f, "f", i_print_hash_value);
	if (g != 0)
		transparent_crc((*g), "(*g)", i_print_hash_value);
	if (h != 0)
		transparent_crc((*h), "(*h)", i_print_hash_value);
	if (i != 0)
		transparent_crc((***i), "(***i)", i_print_hash_value);
	transparent_crc(j, "j", i_print_hash_value);
	transparent_crc(k, "k", i_print_hash_value);
	transparent_crc(l, "l", i_print_hash_value);
	if (m != 0)
		transparent_crc((*m), "(*m)", i_print_hash_value);
	platform_main_end(crc32_context ^ 0xFFFFFFFFUL, i_print_hash_value);
	return 0;
}
