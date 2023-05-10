/* corpus/921019-1.c */
void *foo[]={(void *)&("X"[0])};

main ()
{
  if (((char*)foo[0])[0] != 'X')
    { abort (); }
  exit (0);
}
/* ProgramSourceLLVM */
