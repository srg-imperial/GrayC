/* corpus/20040706-1.c */
int main ()
{
  int i;
  for (i = 0; i < 10; i++)
    { continue; }
  if (i < 10)
    { abort (); }
  exit (0);
}
/* ProgramSourceLLVM */
