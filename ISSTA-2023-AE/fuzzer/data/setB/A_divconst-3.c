/* corpus/divconst-3.c */
long long
f (long long x)
{
  return x / 10000000000LL;
}

main ()
{
  if (f (10000000000LL) != 1 || f (100000000000LL) != 10)
    { abort (); }
  exit (0);
}
/* ProgramSourceLLVM */
