/* corpus/930916-1.c */
f (n)
     unsigned n;
{
  if ((int) n >= 0)
    { abort (); }
}

main ()
{
  unsigned x = ~0;
  f (x);
  exit (0);
}
/* ProgramSourceLLVM */
