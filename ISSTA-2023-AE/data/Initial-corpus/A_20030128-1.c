/* corpus/20030128-1.c */
unsigned char x = 50;
volatile short y = -5;

int main ()
{
  x /= y;
  if (x != (unsigned char) -10)
    { abort (); }
  exit (0);
}
/* ProgramSourceLLVM */
