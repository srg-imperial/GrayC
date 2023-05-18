/* corpus/961004-1.c */
int k = 0;

main()
{
  int i;
  int j;

  for (i = 0; i < 2; i++)
    {
      if (k)
	{
	  if (j != 2)
    { abort (); }
	}
      else
	{
	  j = 2;
	  k++;
	}
    }
  exit (0);
}
/* ProgramSourceLLVM */
