/* corpus/931110-2.c */
main ()
{
  static int a[] = {3, 4};
  register int *b;
  int c;

  b = a;
  c = *b++ % 8;
  if (c != 3)
    { abort (); }
  exit (0);
}
/* ProgramSourceLLVM */
