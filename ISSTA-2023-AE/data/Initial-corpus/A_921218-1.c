/* corpus/921218-1.c */
f()
{
  return (unsigned char)("\377"[0]);
}

main()
{
  if (f() != (unsigned char)(0377))
    { abort (); }
  exit (0);
}
/* ProgramSourceLLVM */
