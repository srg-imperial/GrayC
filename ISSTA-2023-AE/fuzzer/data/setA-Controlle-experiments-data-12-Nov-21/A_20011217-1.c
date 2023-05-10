/* corpus/20011217-1.c */
int
main()
{
  double x = 1.0;
  double y = 2.0;

  if ((y > x--) != 1)
    { abort (); }
  exit (0);
}
/* ProgramSourceLLVM */
