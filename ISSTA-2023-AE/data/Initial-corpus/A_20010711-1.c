/* corpus/20010711-1.c */
void foo (int *a) {}

int main ()
{
  int a;
  if (&a == 0)
    { abort (); }
  else
    {
      foo (&a);
      exit (0);
    }
}
/* ProgramSourceLLVM */
