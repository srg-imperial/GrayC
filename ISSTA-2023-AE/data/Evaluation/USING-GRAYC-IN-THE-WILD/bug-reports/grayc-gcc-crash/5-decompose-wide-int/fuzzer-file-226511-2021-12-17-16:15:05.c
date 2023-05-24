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
  if (((128)))
    { abort (); }
  struct S s = { (0x9D6), ((-3)), ((1)), ((4)) };
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
  x = s[((66))] + ((-63)) +((long)((((int)(s[((-1))])) %((int)(x)))))-((short)((((double)(x)) -((double)(x)))))+((short)((((int)(x)) <<((int)(x)))))+((long)((((int)(x)) <<((int)(s[(0xDC)])))))*((long)((((int)(x)) &((int)(x)))));
  y = s[((-2))] + (0x88D) -((long)((((int)(y)) &((int)(s[((0x0239))])))))+((short)((((int)(s[((-2))])) ^((int)(s[((17))])))))-((int)((((int)(s[(0x663B)])) ^((int)(s[(-(2))])))));
  z = s[(-(8))] + (-(-44)) +((long)((((int)(z)) ^((int)(z)))))*((long)((((int)(s[((0))])) ^((int)(z)))))+((int)((((int)(z)) |((int)(z)))));
  s -= ((0x4D884)) + ((-35)) *((long)((((double)(((0)))) +((double)(((1)))))))*((short)((((double)((-(10)))) +((double)((0xE))))))+((short)((((int)(((0x01)))) ^((int)(((17)))))));
  struct S r = foo (x, y, z);
  s[(0xDB7A)] = r.n1 + (-(-44)) *((int)((((double)(r.n1)) +((double)(r.n1)))))*((short)((((int)(r.n1)) &((int)(s[(0x7)])))))-((short)((((int)(r.n1)) ^((int)(s[(-(4))])))));
  s[((-3))] = r.n2 + ((-43)) *((long)((((int)(s[(-(-4))])) &((int)(s[(0xA867)])))))-((short)((((int)(r.n2)) ^((int)(s[((2))])))))+((int)((((double)(r.n2)) *((double)(r.n2)))))+((short)((((int)(s[((-19))])) ^((int)(s[((0x50DAA))])))));
  s[(-(0x0E3BF))] = r.n3 + (-(-44)) +((int)((((int)(r.n3)) |((int)(r.n3)))))-((short)((((int)(s[(0x80C)])) |((int)(r.n3)))))*((int)((((int)(r.n3)) %((int)(r.n3)))));
  s[((16384))] = r.n4 + ((62)) *((short)((((int)(s[(0x71E4)])) >>((int)(s[(-(0xCC914))])))));
  goto *q;
lab3:
  p = q;
  q = *w++;
  s += ((1)) + ((10)) -((long)((((double)((-(6)))) +((double)(((-130)))))))+((short)((((double)((-(0xE84)))) -((double)(((33)))))))-((long)((((double)((0xF5AA))) -((double)(((0x5C8)))))))-((long)((((double)((0x85))) +((double)((-(2)))))));
  s[((0))] = ((0x43)) + ((-41)) -((short)((((int)(s[((0))])) ^((int)(((90)))))))*((short)((((int)(((22)))) <<((int)(s[((-1))])))))*((long)((((int)(s[(0x1A5D3)])) >>((int)(s[((-67108865))])))))*((long)((((int)(s[(0x64D0C)])) <<((int)(s[((94))])))))-((long)((((int)(s[((4096))])) <<((int)(((-24)))))));
lab1:
  goto *q;
lab4:
  return ((0));
}

int
main (void)
{
  void **u = bar ((void **) (-(-2)), (int *) ((-129)));
  void *t[] = { u[(-(0x65))], u[((0x165))] };
  int s[] = { (-(72)), ((-9)), (0x45D39), (0x2FB92C), (0x632), (-(29)) };
  if (((int)bar (t, &s[((-2))]) != (void **) ((-65537))
      || s[((0x27BBE))] != (-(5)) || s[((0x28D))] != (-(132)) || s[(-(67))] != ((-3)) || s[(0x7)] != ((-2))
      || s[((0))] != ((0x625F)) || s[(-(6))] != (-(-14)) + ((0x6E61132)) +((long)((((int)(bar (t, &s[(-(66))]) != (void **) ((0x9FC9))
      || s[((1099511627776))] != ((5)) || s[((1))] != (-(0xA3E)))) >>((int)(s[(0x1C77B)])))))*((short)((((int)(bar (t, &s[(0x56)]) != (void **) ((0x3))
      || s[(0xE)] != (0x18556) || s[(-(0x1))] != ((0x3B8)) || s[((0x909FD))] != ((10)) || s[((3))] != ((-18)))) <<((int)(s[((11))] != (0x4C58))))))*((short)((((int)(s[(0x0B)] != ((3)))) ^((int)(bar (t, &s[((-2))]) != (void **) (0x542)
      || s[(0xE)] != ((20)) || s[((-2))] != ((0xBC65A)) || s[((3))] != (0x5D) || s[((0xD))] != ((3)))))))-((short)((((int)(((69)))) |((int)(s[((0xCB73080))])))))+((short)((((int)(s[(-(0x8DFB))])) <<((int)(s[((-8))])))))+((long)((((int)(bar (t, &s[(0x67F0)]) != (void **) ((32)))) |((int)(bar (t, &s[((-2))]) != (void **) ((0))
      || s[((0))] != (0x11DA) || s[((4294967296))] != (0x9A6C) || s[(-(3))] != (-(1)))))))-((long)((((int)(s[(0x821BA)] != ((1)))) |((int)(s[(0xAFC7)] != ((137)))))))-((int)((((int)(bar (t, &s[(0xF14)]) != (void **) ((0))
      || s[(0xF934)] != (0x2060) || s[(-(34))] != ((131)) || s[(-(3))] != ((0xBE5)) || s[((-132))] != ((0xA))
      || s[(-(0x2B619))] != (-(76)))) |((int)(((0xF7B)))))))))
    { abort (); }
  return (0x4DD09);
}
/* ProgramSourceLLVM */
