/* corpus/B_703bca68dcce73bf11c39eed707a19a5_2752_test29921419.c */
struct a {
  signed b : 4;
};
static volatile struct a c;
int main() { printf("%d\n", c.b); }
/* ProgramSourceCsmithReduce */
