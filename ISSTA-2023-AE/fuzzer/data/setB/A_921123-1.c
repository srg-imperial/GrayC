/* corpus/921123-1.c */
f(short *p)
{
  short x = *p;
  return (--x < 0);
}

main()
{
  short x = -10;
  if (!f(&x))
    { abort (); }
  exit(0);
}
/* ProgramSourceLLVM */
