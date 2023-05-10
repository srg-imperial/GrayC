/* corpus/990324-1.c */
void f(long i)
{
  if ((signed char)i < 0 || (signed char)i == 0)
    { abort (); }
  else
    { exit (0); }
}

main()
{
  f(0xffffff01);
}
/* ProgramSourceLLVM */
