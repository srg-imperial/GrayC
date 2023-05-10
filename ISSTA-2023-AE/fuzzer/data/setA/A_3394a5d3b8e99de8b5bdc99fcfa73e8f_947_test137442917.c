/* corpus/3394a5d3b8e99de8b5bdc99fcfa73e8f_947_test137442917.c */
struct {
  unsigned a : 29;
  signed : 18;
  unsigned b : 19;
} static c[6][3][10];
int main(h) {
  int d, e, f, g = 0;
  if (h == 0)
    g = 1;
  d = 0;
  for (; d < 6; d++) {
    e = 0;
    for (; e < 3; e++) {
      f = 0;
      for (; f < 10; f++) {
        printf("%d\n", c[d][e][f].a);
        printf("%d\n", c[d][e][f].b);
        if (g)
          printf("index = %d\n", e);
      }
    }
  }
}
/* ProgramSourceCsmithReduce */
