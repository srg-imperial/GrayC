/* corpus/20000519-2.c */
long x = -1L;

int main()
{
  long b = (x != -1L);

  if (b)
    { abort (); }

  exit(0);
}
/* ProgramSourceLLVM */
