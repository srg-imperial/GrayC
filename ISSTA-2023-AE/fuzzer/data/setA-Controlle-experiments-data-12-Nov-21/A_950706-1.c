/* corpus/950706-1.c */
int
f (int n)
{
  return (n > 0) - (n < 0);
}

main ()
{
  if (f (-1) != -1)
    { abort (); }
  if (f (1) != 1)
    { abort (); }
  if (f (0) != 0)
    { abort (); }
  exit (0);
}
/* ProgramSourceLLVM */
