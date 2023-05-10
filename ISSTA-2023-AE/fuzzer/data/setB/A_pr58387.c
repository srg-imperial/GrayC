/* corpus/pr58387.c */
extern void abort(void);

int a = -1;

int main ()
{
  int b = a == 0 ? 0 : -a;
  if (b < 1)
    { abort (); }
  return 0;
}
/* ProgramSourceLLVM */
