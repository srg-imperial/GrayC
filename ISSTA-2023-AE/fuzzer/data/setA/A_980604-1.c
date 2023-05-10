/* corpus/980604-1.c */
int a = 1;
int b = -1;

int c = 1;
int d = 0;

main ()
{
  double e;
  double f;
  double g;

  f = c;
  g = d;
  e = (a < b) ? f : g;
  if (e)
    { abort (); }
  exit(0);
}
/* ProgramSourceLLVM */
