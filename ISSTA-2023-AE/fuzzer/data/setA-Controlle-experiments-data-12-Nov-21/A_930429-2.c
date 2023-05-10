/* corpus/930429-2.c */
int
f (b)
{
  return (b >> 1) > 0;
}

main ()
{
  if (!f (9))
    { abort (); }
  if (f (-9))
    { abort (); }
  exit (0);
}
/* ProgramSourceLLVM */
