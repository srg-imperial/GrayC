/* corpus/921104-1.c */
main ()
{
  unsigned long val = 1;

  if (val > (unsigned long) ~0)
    { abort (); }
  exit (0);
}
/* ProgramSourceLLVM */
