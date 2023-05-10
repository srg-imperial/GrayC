/* corpus/__restore_test3182018576.c */
struct {
  unsigned a;
} static b[][6];
int main() {
  int c = 0;
  for (; c < 6; c++)
    printf("%d\n", b[0][c].a);
}
/* ProgramSourceCsmithReduce */
