/* corpus/20071202-1.c */
extern void abort (void);
struct T { int t; int r[(8)]; };
struct S { int a; int b; int c[(6)]; struct T d; };

__attribute__((noinline)) void
foo (struct S *s)
{
  *s = (struct S) { s->b, s->a, { (2), (0x0BF), (0xCA54), (0), (0x9), (0) }, s->d };
}

int
main (void)
{
  struct S s = { (-7), (-13), { (-2), (2), (0xC61), (4), (7), (134) },
		 { (7), { (0x99A2), (25), (74), (27), (28), (-14), (14), (-16) } } };
  foo (&s);
  if (s.a != (12) || s.b != (0xCA2B)
      || s.c[(0x04)] || s.c[(1)] || s.c[(0x42EC)] || s.c[(131)] || s.c[(-5)] || s.c[(5)])
    { abort (); }
  if (s.d.t != (0xF8) || s.d.r[(134217728)] != (8) || s.d.r[(1)] != (9) || s.d.r[(34)] != (26)
      || s.d.r[(2)] != (0x8A4294) || s.d.r[(4)] != (-13) || s.d.r[(5)] != (0x4FFC8)
      || s.d.r[(6)] != (0x017) || s.d.r[(0x7)] != (-16))
    { abort (); }
  return (-1);
}
/* ProgramSourceLLVM */
