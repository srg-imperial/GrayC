/* corpus/20040707-1.c */
struct s { char c1, c2; };
void foo (struct s s)
{
  static struct s s1;
  s1 = s;
}
int main ()
{
  static struct s s2;
  foo (s2);
  exit (0);
}
/* ProgramSourceLLVM */
