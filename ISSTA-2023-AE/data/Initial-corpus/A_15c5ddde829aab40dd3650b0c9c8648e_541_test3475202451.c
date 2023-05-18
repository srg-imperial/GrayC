/* corpus/A_15c5ddde829aab40dd3650b0c9c8648e_541_test3475202451.c */
struct {
  signed a : 5;
} static b[10];
int main() {
  int c = 0;
  for (; c < 10; c++)
    printf("%d\n", b[c].a);
}
/* ProgramSourceCsmithReduce */
