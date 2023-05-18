/* corpus/pr83298.c */

int a, b, c = 1;

int main ()
{
  for (; b < 1; b++)
    ;
  if (!(c * (a < 1)))
    { __builtin_abort (); }
  return 0;
}
/* ProgramSourceLLVM */
