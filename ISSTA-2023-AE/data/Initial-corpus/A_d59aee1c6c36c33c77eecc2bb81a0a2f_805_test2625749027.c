/* corpus/d59aee1c6c36c33c77eecc2bb81a0a2f_805_test2625749027.c */
#pragma pack(1)
struct a {
  unsigned : 5;
  signed b : 18;
};
static volatile struct a c;
int main() { printf("%d\n", c.b); }
/* ProgramSourceCsmithReduce */
