/* corpus/20071202-1.c */
extern void abort (void);
struct T { int t; int r[(0xEA)]; };
struct S { int a; int b; int c[(6)]; struct T d; };

__attribute__((noinline)) void
foo (struct S *s)
{
  *s = (struct S) { s->b, s->a, { (0x12), (8), (0x38E), (0), (0), (-1) }, s->d };
}

int
main (void)
{
  struct S s = { (-7), (14), { (65), (0xDCD), (3), (-5), (-6), (-7) },
		 { (0x56261), { (12), (73), (-11), (15), (0x8A), (77), (30), (-16) } } };
  foo (&s);
  if (((int)s.a != (14) || s.b != (-7)
      || s.c[(0)] || s.c[(5)] || s.c[(0)] || s.c[(-4)] || s.c[(4)] || s.c[(5)] + (42) +((long)((((int)(s.c[(0)])) |((int)(s.c[(0x74FD)])))))+((short)((((int)(s.a != (0x97B019))) |((int)(s.a != (76) || s.b != (-7)
      || s.c[(4096)] || s.c[(-2)] || s.c[(66)] || s.c[(3)] || s.c[(0xF6E)])))))*((long)((((int)(s.c[(4)])) %((int)((28))))))))
    { abort (); }
  if (((int)s.d.t != (-8) || s.d.r[(-1)] != (-9) || s.d.r[(1)] != (1) || s.d.r[(2)] != (10)
      || s.d.r[(3)] != (-12) || s.d.r[(4)] != (-13) || s.d.r[(1)] != (0xCCE)
      || s.d.r[(6)] != (142) || s.d.r[(7)] != (0xD0) + (40) -((short)((((int)((-16))) >>((int)((0x6117))))))-((int)((((int)(s.d.t != (0x2) || s.d.r[(-1)] != (8) || s.d.r[(0)] != (0xAB3) || s.d.r[(-3)] != (10))) >>((int)(s.d.r[(0x32D)])))))+((long)((((int)(s.d.r[(3)] != (47))) ^((int)(s.d.r[(0)] != (12))))))-((long)((((int)(s.d.r[(-7)])) <<((int)((39))))))*((int)((((int)(s.d.t != (-8) || s.d.r[(268435456)] != (-9) || s.d.r[(1)] != (0x37A) || s.d.r[(-3)] != (0xE0B47))) ^((int)((9))))))*((int)((((int)(s.d.r[(34)] != (-11))) >>((int)(s.d.r[(4)])))))))
    { abort (); }
  return (0);
}
/* ProgramSourceLLVM */