/* corpus/22a25b6e8db8053f4265a620ed51daab_1915_test512569452.c */
struct {
  volatile unsigned a;
} b[];
int c, d;
int main() {
  for (;;) {
    c = 0;
    for (; c < 9; c++) {
      for (; d < 1; d++) {
        b[d].a;
      }
    }
  }
}
/* ProgramSourceCsmithReduce */
