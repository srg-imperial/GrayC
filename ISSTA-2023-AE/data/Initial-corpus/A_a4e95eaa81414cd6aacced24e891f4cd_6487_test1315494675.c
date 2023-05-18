/* corpus/A_a4e95eaa81414cd6aacced24e891f4cd_6487_test1315494675.c */
struct {
  signed a : 10;
} static b[4];
int main() {
  int c = 0;
  for (; c < 4; c++)
    printf("%d\n", b[c].a);
}
/* ProgramSourceCsmithReduce */
