/* corpus/980602-1.c */
main()
{
  int i;
  for (i = 1; i < 100; i++)
    ;
  if (i == 100)
    { exit (0); }
  abort ();
}
/* ProgramSourceLLVM */
