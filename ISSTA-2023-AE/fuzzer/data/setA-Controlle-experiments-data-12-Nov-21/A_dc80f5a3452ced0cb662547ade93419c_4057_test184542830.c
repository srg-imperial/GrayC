/* corpus/A_dc80f5a3452ced0cb662547ade93419c_4057_test184542830.c */
struct {
  signed a : 5;
} static b[6];
int main() {
  int c = 0;
  for (; c < 6; c++)
    printf("%d\n", b[c].a);
}
/* ProgramSourceCsmithReduce */
