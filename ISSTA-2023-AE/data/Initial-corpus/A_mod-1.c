/* corpus/mod-1.c */
f (x, y)
{
  if (x % y != 0)
    { abort (); }
}

main ()
{
  f (-5, 5);
  exit (0);
}
/* ProgramSourceLLVM */
