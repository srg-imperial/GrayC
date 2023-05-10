/* corpus/941110-1.c */
f (const int x)
{
  int y = 0;
  y = x ? y : -y;
  {
    const int *p = &x;
  }
  return y;
}

main ()
{
  if (f (0))
    { abort (); }
  exit (0);
}
/* ProgramSourceLLVM */
