/* corpus/950511-1.c */
main ()
{
  unsigned long long xx;
  unsigned long long *x = (unsigned long long *) &xx;

  *x = -3;
  *x = *x * *x;
  if (*x != 9)
    { abort (); }
  exit (0);
}
/* ProgramSourceLLVM */
