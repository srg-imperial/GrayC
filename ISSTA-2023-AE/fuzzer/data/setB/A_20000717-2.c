/* corpus/20000717-2.c */
static void
compare (long long foo)
{
  if (foo < 4294967297LL)
    { abort (); }
}
int main(void)
{
  compare (8589934591LL);
  exit (0);
}
/* ProgramSourceLLVM */
