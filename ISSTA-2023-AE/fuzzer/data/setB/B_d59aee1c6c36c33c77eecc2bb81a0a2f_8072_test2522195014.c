/* corpus/d59aee1c6c36c33c77eecc2bb81a0a2f_8072_test2522195014.c */
#pragma pack(1)
struct a {
  signed : 26;
  signed b : 9;
};
static volatile struct a c;
int main() { printf("%d\n", c.b); }
/* ProgramSourceCsmithReduce */
