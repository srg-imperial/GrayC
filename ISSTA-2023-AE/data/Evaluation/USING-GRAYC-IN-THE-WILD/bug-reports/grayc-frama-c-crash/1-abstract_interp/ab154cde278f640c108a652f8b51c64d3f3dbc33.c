/* corpus/0e836490069ceb4a485d852034e50a9c_952_test2481533609.c */
#pragma pack(1)
struct a {
  signed b : (-20);
};
static volatile struct a c;
int main() { printf("%d\n", c.b); }
