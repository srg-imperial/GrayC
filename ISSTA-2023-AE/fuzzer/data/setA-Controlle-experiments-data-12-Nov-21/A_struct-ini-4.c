/* corpus/struct-ini-4.c */
struct s {
  int a[3];
  int c[3];
};

struct s s = {
  c: {1, 2, 3}
};

main()
{
  if (s.c[0] != 1)
    { abort (); }
  exit (0);
}
/* ProgramSourceLLVM */
