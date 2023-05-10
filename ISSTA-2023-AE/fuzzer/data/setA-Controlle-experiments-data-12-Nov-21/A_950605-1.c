/* corpus/950605-1.c */
f (c)
    unsigned char c;
{
  if (c != 0xFF)
    { abort (); }
}

main ()
{
  f (-1);
  exit (0);
}
/* ProgramSourceLLVM */
