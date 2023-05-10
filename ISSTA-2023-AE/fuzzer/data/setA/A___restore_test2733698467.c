/* corpus/__restore_test2733698467.c */
struct {
  unsigned a : 1;
} static b[5];
int main() {
  int c = 0;
  for (; c < 5; c++)
    printf("%d\n", b[c].a);
}
/* ProgramSourceCsmithReduce */
