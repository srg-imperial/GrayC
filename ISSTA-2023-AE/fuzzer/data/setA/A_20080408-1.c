/* corpus/20080408-1.c */
extern void abort (void);
int main ()
{
  short ssi = 126;
  unsigned short usi = 65280;
  int fail = !(ssi < usi);
  if (fail)
    { abort (); }
  return 0;
}
/* ProgramSourceLLVM */
