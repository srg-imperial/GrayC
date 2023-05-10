/* corpus/__restore_test2673927779.c */
struct {
  unsigned a;
} static b[][4];
int main() {
  int c = 0;
  for (; c < 4; c++)
    printf("%d\n", b[0][c].a);
}
/* ProgramSourceCsmithReduce */
