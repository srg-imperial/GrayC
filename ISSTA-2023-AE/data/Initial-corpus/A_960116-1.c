/* corpus/960116-1.c */
static inline
p (int *p)
{
  return !((long) p & 1);
}

int
f (int *q)
{
  if (p (q) && *q)
    { return 1; }
  return 0;
}

main ()
{
  if (f ((int*) 0xffffffff) != 0)
    { abort (); }
  exit (0);
}
/* ProgramSourceLLVM */
