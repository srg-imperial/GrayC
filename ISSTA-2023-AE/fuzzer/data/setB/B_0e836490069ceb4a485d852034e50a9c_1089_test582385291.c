/* corpus/B_0e836490069ceb4a485d852034e50a9c_1089_test582385291.c */
#pragma pack(1)
struct a {
  signed b : 22;
};
static volatile struct a c;
int main() { printf("%d\n", c.b); }
/* ProgramSourceCsmithReduce */
