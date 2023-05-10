/* corpus/__restore_test2005217312.c */
struct {
  unsigned a : 30;
} static b[20];
int main() {
  int c = 0;
  for (; c < 10; c++)
    printf("%d\n", b[c].a);
}
/* ProgramSourceCsmithReduce */
