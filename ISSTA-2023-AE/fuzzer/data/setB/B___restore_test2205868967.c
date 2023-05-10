/* corpus/__restore_test2205868967.c */
struct {
  signed a;
} static b[][2][1];
int main() {
  int c = 0;
  for (; c < 2; c++)
    printf("%d\n", b[0][c][0].a);
}
/* ProgramSourceCsmithReduce */
