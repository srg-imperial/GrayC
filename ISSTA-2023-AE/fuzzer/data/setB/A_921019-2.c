/* corpus/921019-2.c */
main()
{
  double x,y=0.5;
  x=y/0.2;
  if(x!=x)
    { abort (); }
  exit(0);
}
/* ProgramSourceLLVM */
