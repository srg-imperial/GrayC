/* corpus/20041124-1.c */
struct s { _Complex unsigned short x; };
struct s gs = { 100 + 200i };
struct s __attribute__((noinline)) foo (void) { return gs; }

int main ()
{
  if (foo ().x != gs.x)
    { abort (); }
  exit (0);
}
/* ProgramSourceLLVM */
