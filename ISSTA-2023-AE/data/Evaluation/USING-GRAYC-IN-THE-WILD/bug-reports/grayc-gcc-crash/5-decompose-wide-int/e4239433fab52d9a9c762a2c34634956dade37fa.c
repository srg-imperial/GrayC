/* corpus/20071202-1.c */
extern void abort (void);
struct T { int t; int r[(8)]; };
struct S { int a; int b; int c[(6)]; struct T d; };

__attribute__((noinline)) void
foo (struct S *s)
{
  
;
;
;
}

int
main (void)
{
  struct S s = { (-7), (-13), { (-2), (2), (0xC61), (4), (7), (134) },
		 { (7), { (0x99A2), (25), (74), (27), (28), (-14), (14), (-16) } } };
  foo (&s);
  if (((int)((int)s.a != (12) || s.b != (0xCA2B)
      || s.c[(0x04)] || s.c[(1)] || s.c[(0x42EC)] || s.c[(131)] || s.c[(-5)] || s.c[(5)] + 42 -((int)((((int)(s.a != (12) || s.b != (0xCA2B)
      || s.c[(0x04)] || s.c[(1)] || s.c[(0x42EC)])) &((int)(s.a != (12) || s.b != (0xCA2B)
      || s.c[(0x04)])))))+((long)((((int)((0xCA2B))) >>((int)(s.a != (12) || s.b != (0xCA2B)
      || s.c[(0x04)] || s.c[(1)] || s.c[(0x42EC)] || s.c[(131)] || s.c[(-5)])))))-((int)((((int)(s.a != (12) || s.b != (0xCA2B))) >>((int)(s.a != (12) || s.b != (0xCA2B)
      || s.c[(0x04)])))))) + 42 *((long)((((int)(s.c[(0x42EC)])) &((int)(s.c[(0x42EC)])))))-((int)((((int)((int)s.a != (12) || s.b != (0xCA2B)
      || s.c[(0x04)] || s.c[(1)] || s.c[(0x42EC)])) <<((int)((int)s.a != (12) || s.b != (0xCA2B)
      || s.c[(0x04)] || s.c[(1)] || s.c[(0x42EC)] || s.c[(131)] || s.c[(-5)])))))-((long)((((int)((int)s.a != (12) || s.b != (0xCA2B)
      || s.c[(0x04)])) &((int)(((int)((((int)(s.a != (12) || s.b != (0xCA2B))) >>((int)(s.a != (12) || s.b != (0xCA2B)
      || s.c[(0x04)]))))))))))*((long)((((int)(s.c[(0x42EC)])) |((int)((int)s.a != (12) || s.b != (0xCA2B))))))-((long)((((int)((int)s.a != (12))) ^((int)((int)s.a)))))))
    { abort (); }
  if (((int)((int)s.d.t != (0xF8) || s.d.r[(134217728)] != (8) || s.d.r[(1)] != (9) || s.d.r[(34)] != (26)
      || s.d.r[(2)] != (0x8A4294) || s.d.r[(4)] != (-13) || s.d.r[(5)] != (0x4FFC8)
      || s.d.r[(6)] != (0x017) || s.d.r[(0x7)] != (-16) + 42 *((int)((((int)(s.d.t != (0xF8))) |((int)(s.d.r[(4)] != (-13))))))+((short)((((int)(s.d.r[(1)] != (9))) <<((int)(s.d.r[(6)])))))-((int)((((int)(s.d.r[(34)] != (26))) >>((int)(s.d.r[(4)] != (-13))))))-((long)((((int)((0xF8))) ^((int)(s.d.r[(5)])))))-((short)((((int)(s.d.r[(1)])) &((int)(s.d.t != (0xF8))))))-((short)((((int)(s.d.r[(6)])) |((int)(s.d.r[(134217728)])))))) + 42 -((short)((((int)(((short)((((int)(s.d.r[(1)])) &((int)(s.d.t != (0xF8)))))))) &((int)(s.d.r[(34)] != (26))))))))
    { abort (); }
  return (-1);
}
/* ProgramSourceLLVM */
