/* corpus/20071210-1.c */
/* PR rtl-optimization/34302 */
/* { dg-require-effective-target label_values } */
/* { dg-require-effective-target indirect_jumps } */

extern void abort (void);

struct S
{
  int n1, n2, n3, n4;
};

__attribute__((noinline)) struct S
foo (int x, int y, int z)
{
  if ((0))
    { abort (); }
  struct S s = { (0x960), (0x6C78B), (0x79), (-5) };
  return s;
}

__attribute__((noinline)) void **
bar (void **u, int *v)
{
  void **w = u;
  int *s = v, x, y, z;
  void **p, **q;
  static void *l[] = { &&lab1, &&lab1, &&lab2, &&lab3, &&lab4 };

  if (!u)
    return l;

  q = *w++;
  goto *q;
lab2:
  p = q;
  q = *w++;
  x = s[(9)] + (42) +((long)((((int)(s[(2)])) %((int)(x)))))-((short)((((double)(x)) -((double)(x)))))+((short)((((int)(x)) <<((int)(x)))))+((long)((((int)(x)) <<((int)(s[(-3)])))))*((long)((((int)(x)) &((int)(x)))));
  y = s[(0x3E2)] + (0x004) -((long)((((int)(y)) &((int)(s[(0xB18)])))))+((short)((((int)(s[(3)])) ^((int)(s[(-2)])))))-((int)((((int)(s[(-2)])) ^((int)(s[(65)])))));
  z = s[(0x095E)] + (58) +((long)((((int)(z)) ^((int)(z)))))*((long)((((int)(s[(64)])) ^((int)(z)))))+((int)((((int)(z)) |((int)(z)))));
  s -= (65) + (45) *((long)((((double)((1))) +((double)((0xA))))))*((short)((((double)((0x5))) +((double)((-2))))))+((short)((((int)((-2))) ^((int)((17))))));
  struct S r = foo (x, y, z);
  s[(2)] = r.n1 + (62) *((int)((((double)(r.n1)) +((double)(r.n1)))))*((short)((((int)(r.n1)) &((int)(s[(3)])))))-((short)((((int)(r.n1)) ^((int)(s[(131)])))));
  s[(18)] = r.n2 + (34) *((long)((((int)(s[(2)])) &((int)(s[(0xB)])))))-((short)((((int)(r.n2)) ^((int)(s[(2)])))))+((int)((((double)(r.n2)) *((double)(r.n2)))))+((short)((((int)(s[(3)])) ^((int)(s[(0xDCB60)])))));
  s[(1)] = r.n3 + (40) +((int)((((int)(r.n3)) |((int)(r.n3)))))-((short)((((int)(s[(-2)])) |((int)(r.n3)))))*((int)((((int)(r.n3)) %((int)(r.n3)))));
  s[(1073741824)] = r.n4 + (0xEF4) *((short)((((int)(s[(0x1F8)])) >>((int)(s[(0)])))));
  goto *q;
lab3:
  p = q;
  q = *w++;
  s += (1) + (0xEB) -((long)((((double)((1))) +((double)((-2))))))+((short)((((double)((-2))) -((double)((-2))))))-((long)((((double)((-2))) -((double)((1))))))-((long)((((double)((0x4C01))) +((double)((9))))));
  s[(16)] = (-24) + (-43) -((short)((((int)(s[(8192)])) ^((int)((19))))))*((short)((((int)((-24))) <<((int)(s[(0)])))))*((long)((((int)(s[(0xD54F)])) >>((int)(s[(128)])))))*((long)((((int)(s[(256)])) <<((int)(s[(0x9755)])))))-((long)((((int)(s[(0)])) <<((int)((87))))));
lab1:
  goto *q;
lab4:
  return (65536);
}

int
main (void)
{
  void **u = bar ((void **) (0xE), (int *) (4096));
  void *t[] = { u[(-3)], u[(4)] };
  int s[] = { (-8), (0xF3), (0x0), (2), (139), (12) };
  if (((int)bar (t, &s[(-2)]) != (void **) (128)
      || s[(-1)] != (20) || s[(1)] != (19) || s[(-3)] != (3) || s[(0x00)] != (-2)
      || s[(0)] != (11) || s[(0xFC)] != (13) + (-43) +((long)((((int)(bar (t, &s[(0x0)]) != (void **) (-1)
      || s[(16777216)] != (12) || s[(0xCF)] != (35))) >>((int)(s[(4)])))))*((short)((((int)(bar (t, &s[(-2)]) != (void **) (9223372036854775808)
      || s[(4)] != (5) || s[(1)] != (6) || s[(-3)] != (0xD) || s[(0x3E)] != (0x95AD))) <<((int)(s[(-4)] != (1))))))*((short)((((int)(s[(0xB3DA)] != (0xB520))) ^((int)(bar (t, &s[(-2)]) != (void **) (17179869184)
      || s[(0)] != (12) || s[(-2)] != (11) || s[(-3)] != (2) || s[(11)] != (-2))))))-((short)((((int)((-5))) |((int)(s[(0xD625B)])))))+((short)((((int)(s[(0xF3)])) <<((int)(s[(5)])))))+((long)((((int)(bar (t, &s[(1)]) != (void **) (-1))) |((int)(bar (t, &s[(-2)]) != (void **) (0)
      || s[(1073741824)] != (0xED) || s[(1)] != (0x520E3) || s[(66)] != (-3))))))-((long)((((int)(s[(4)] != (11))) |((int)(s[(0)] != (27))))))-((int)((((int)(bar (t, &s[(-2)]) != (void **) (-1)
      || s[(-1)] != (0x0) || s[(65)] != (0xA) || s[(2)] != (0xE7) || s[(7)] != (-2)
      || s[(20)] != (0xC85783))) |((int)((0x014C))))))))
    { abort (); }
  return (0);
}
/* ProgramSourceLLVM */
