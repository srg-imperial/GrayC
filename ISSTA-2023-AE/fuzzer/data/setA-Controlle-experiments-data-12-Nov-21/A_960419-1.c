/* corpus/960419-1.c */
static int i;

void
check(x)
     int x;
{
  if (!x)
    { abort (); }
}

main()
{
  int *p = &i;

  check(p != (void *)0);
  exit (0);
}
/* ProgramSourceLLVM */
