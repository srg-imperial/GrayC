/* corpus/pr22061-2.c */
int *x;
static void bar (char a[2][(*x)++]) {}
int
main (void)
{
  exit (0);
}
/* ProgramSourceLLVM */
