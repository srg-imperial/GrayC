/* corpus/970217-1.c */
sub (int i, int array[i++])
{
  return i;
}

main()
{
  int array[10];
  exit (sub (10, array) != 11);
}
/* ProgramSourceLLVM */
