/* corpus/__restore_test540207536.c */
struct {
  unsigned a;
} static b[][4][1];
int main() {
  int c = 0;
  for (; c < 4; c++)
    printf("%d\n", b[0][c][0].a);
}
/* ProgramSourceCsmithReduce */
