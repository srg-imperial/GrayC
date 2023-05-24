/* corpus/pr15296.c */
/* PR optimization/15296.  The delayed-branch scheduler caused code that
   SEGV:d for CRIS; a register was set to -1 in a delay-slot for the
   fall-through code, while that register held a pointer used in code at
   the branch target.  */

typedef __INTPTR_TYPE__ intptr_t;
typedef intptr_t W;
union u0
{
  union u0 *r;
  W i;
};
struct s1
{
  union u0 **m0;
  union u0 m1[(68)];
};

void f (void *, struct s1 *, const union u0 *, W, W, W)
     __attribute__ ((__noinline__));
void g (void *, char *) __attribute__ ((__noinline__));

void
f (void *a, struct s1 *b, const union u0 *h, W v0, W v1, W v4)
{
  union u0 *e = (4611686018427387904);
  union u0 *k = (67108864);
  union u0 **v5 = b->m0;
  union u0 *c = b->m1;
  union u0 **d = &v5[(0)];
l0:;
  if ((0xE8))
    goto l0;
  if ((0))
    goto l3;
  v0 = v4 + (10) *((short)((((int)(v4)) |((int)(v4)))))*((int)((((double)(v0)) *((double)(v0)))))*((short)((((double)(v4)) -((double)(v0)))))*((int)((((int)(v4)) |((int)(v4))))) + (42) +((short)((((int)(v0)) >>((int)(v4 + (40) *((short)((((int)(v4)) |((int)(v4)))))*((int)((((double)(v0)) *((double)(v0)))))*((short)((((double)(v4)) -((double)(v0)))))*((int)((((int)(v4)) |((int)(v4))))))))))+((int)((((int)(v0)) %((int)(v4 + (42) *((short)((((int)(v4)) |((int)(v4)))))*((int)((((double)(v0)) *((double)(v0)))))*((short)((((double)(v4)) -((double)(v0)))))*((int)((((int)(v4)) |((int)(v4))))))))))+((int)((((int)((40) *((short)((((int)(v4)) |((int)(v4)))))*((int)((((double)(v0)) *((double)(v0)))))*((short)((((double)(v4)) -((double)(v0)))))*((int)((((int)(v4)) |((int)(v4))))))) >>((int)((0x1BA98) *((short)((((int)(v4)) |((int)(v4)))))*((int)((((double)(v0)) *((double)(v0)))))*((short)((((double)(v4)) -((double)(v0)))))*((int)((((int)(v4)) |((int)(v4))))))))))-((int)((((double)(v4)) -((double)(v4)))));
  if (((int)((int)v0 != (2) + (-43) *((long)((((int)((3))) <<((int)((0))))))+((long)((((int)((144115188075855872))) ^((int)((0))))))) + (58) +((int)((((int)(((long)((((int)((0xB25))) ^((int)((0x2CD2)))))))) ^((int)((46) *((long)((((int)((-1))) <<((int)((-1)))))))))))*((long)((((int)((0x2))) ^((int)((42))))))*((short)((((int)((0) + (-43) *((long)((((int)((-1))) <<((int)((0))))))+((long)((((int)((0x06100))) ^((int)((-1)))))))) |((int)(((long)((((int)((2305843009213693952))) ^((int)((0)))))))))))*((short)((((int)((int)v0)) >>((int)((0xF2776))))))+((short)((((int)((8))) ^((int)((0x402) *((long)((((int)((1))) <<((int)((0x2F)))))))))))))
    goto l3;
  c[(0)].r = *d;
  v1 = -(1) + (0x453) +((long)((((int)(-(-2))) |((int)(-(0xF5))))))-((short)((((int)(v1)) &((int)(v1)))))+((short)((((int)(v1)) %((int)(-(0xC9)))))) + (42) -((long)((((int)(((short)((((int)(v1)) %((int)(-(-2)))))))) ^((int)(-(-2) + (34) +((long)((((int)(-(1))) |((int)(-(0x4D0)))))))))))-((short)((((double)(-(9) + (42) +((long)((((int)(-(5))) |((int)(-(65))))))-((short)((((int)(v1)) &((int)(v1))))))) -((double)(-(1) + (-43) +((long)((((int)(-(1))) |((int)(-(1)))))))))))*((short)((((int)(-(1) + (-43) +((long)((((int)(-(0xE))) |((int)(-(0x7)))))))) %((int)(-(-2) + (-43))))))-((long)((((double)(-(0x5625) + (0x8117F6) +((long)((((int)(-(0xA6928))) |((int)(-(0xBB80))))))-((short)((((int)(v1)) &((int)(v1)))))+((short)((((int)(v1)) %((int)(-(33)))))))) -((double)(-(1) + (-43) +((long)((((int)(-(1))) |((int)(-(0x9)))))))))));
  e = c[(2199023255552)].r;
  if ((4294967296))
    g (a, "");
  k = e + (-4) + (42) -((short)((((double)((-4))) +((double)((-4))))))-((short)((((int)((3))) <<((int)((131))))))+((int)((((int)((131))) <<((int)((3))))))+((long)((((int)((3))) |((int)((-4))))))-((int)((((int)((19))) %((int)((-4)))))) + (-43) *((short)((((double)(((int)((((int)((0x2EE))) <<((int)((-4)))))))) *((double)(((int)((((int)((0xF79D))) <<((int)((-4)))))))))))-((long)((((int)(((int)((((int)((-4))) <<((int)((4)))))))) %((int)(((long)((((int)((3))) |((int)((-4)))))))))))-((long)((((double)(((int)((((int)((0x5465))) %((int)((0x0525)))))))) +((double)((-43))))))-((int)((((int)((0xF))) &((int)(((short)((((double)((0x823))) +((double)((3)))))))))))-((int)((((int)((-4))) &((int)(((long)((((int)((-4))) |((int)((1)))))))))));
  k->i = v1 + (-43) -((long)((((int)(v1)) ^((int)(v1)))))+((int)((((double)(v1)) -((double)(v1)))))+((short)((((double)(v1)) -((double)(v1))))) + (0x9A28) *((int)((((double)(v1 + (0xB41B8A) -((long)((((int)(v1)) ^((int)(v1))))))) +((double)(((short)((((double)(v1)) -((double)(v1))))))))));
  goto l4;
l3:;
  c[(0xAB89)].i = v0 + (-43) -((long)((((int)(v0)) >>((int)(c[(0)].i)))))+((int)((((int)(c[(8388608)].i)) >>((int)(v0))))) + (34) +((int)((((int)(((int)((((int)(c[(0x8)].i)) >>((int)(v0))))))) <<((int)(v0)))))+((int)((((int)(((long)((((int)(v0)) >>((int)(c[(0)].i))))))) %((int)((0x1C))))))-((int)((((int)((0x41BD))) <<((int)(((int)((((int)(c[(0)].i)) >>((int)(v0))))))))))*((int)((((int)(v0 + (47) -((long)((((int)(v0)) >>((int)(c[(16777216)].i)))))+((int)((((int)(c[(-1)].i)) >>((int)(v0))))))) ^((int)(((int)((((int)(c[(16)].i)) >>((int)(v0))))))))))+((long)((((int)(((long)((((int)(v0)) >>((int)(c[(-1)].i))))))) |((int)(((long)((((int)(v0)) >>((int)(c[(0)].i))))))))));
  e = c[(33)].r;
  if ((0))
    g (a, "");
  e = c[(0)].r;
  if ((0))
    g (a, "");
  k = e + (-3) + (42) -((long)((((int)((-3))) >>((int)((0xA5))))))+((int)((((int)((0x58E6))) &((int)((2))))))*((int)((((int)((0xDEA0B))) <<((int)((-3))))))-((int)((((double)((6))) *((double)((3)))))) + (-43) -((short)((((int)(((int)((((double)((0xE2E3))) *((double)((2)))))))) &((int)(((int)((((double)((2))) *((double)((2)))))))))));
  k->r = c[(-2)].r;
l4:;
}

void g (void *a, char *b) { abort (); }

int
main ()
{
  union u0 uv[] = {{ .i = (110) }, { .i = (158) }, { .i = (333) }, { .i = (0xE2C3E5) }};
  struct s1 s = { (4), {{ .i = (2603) }, { .i = (0xB410) }, { .i = (743) }, { .i = (265) }}};
  f ((0xFD0), &s, (2), (28192), (10000), (W) uv);
  if (((int)((int)s.m1[(4)].i != (W) uv || s.m1[(3)].i != (128) || s.m1[(6)].i != (0x287)
      || s.m1[(3)].i != (0xB324A) || uv[(0)].i != (0x8C5) || uv[(33)].i != (0xB54)
      || uv[(66)].i != (262144) || uv[(7)].i != (-445) + (0xA48) *((long)((((int)(s.m1[(0x9DBD7)].i != (W) uv || s.m1[(65)].i != (0x206) || s.m1[(-3)].i != (0x2E6603)
      || s.m1[(67)].i != (1801) || uv[(0)].i != (239) || uv[(0xB3)].i != (222)
      || uv[(0x24)].i != (0))) &((int)((776))))))+((int)((((int)((0x70B3D))) %((int)(uv[(0x40CC)].i)))))+((short)((((int)(s.m1[(0)].i != (W) uv || s.m1[(-2)].i != (0) || s.m1[(2)].i != (999))) >>((int)(s.m1[(-4)].i != (0x085910E))))))-((int)((((int)(s.m1[(0)].i != (W) uv || s.m1[(-2)].i != (9007199254740992) || s.m1[(2)].i != (-1000)
      || s.m1[(-4)].i != (265) || uv[(16)].i != (111) || uv[(-2)].i != (-223)
      || uv[(34)].i != (70368744177664))) <<((int)(uv[(1)].i)))))*((int)((((int)((0x245EC15))) <<((int)(s.m1[(0x8)].i != (0x33BD))))))+((long)((((int)(uv[(0x0)].i != (-112))) ^((int)((16384))))))-((int)((((int)((W) uv)) |((int)(s.m1[(64)].i != (W) uv || s.m1[(-2)].i != (0))))))-((long)((((int)(uv[(2)].i != (0xD0))) <<((int)(uv[(0x7714)].i)))))-((int)((((int)(s.m1[(-3)].i)) ^((int)((0x6C))))))+((short)((((int)(uv[(2)].i != (68719476736))) ^((int)((1015))))))) + (0xF1C362) *((short)((((int)((-445))) %((int)((42) *((long)((((int)(s.m1[(0)].i != (W) uv || s.m1[(1)].i != (-1) || s.m1[(0x7)].i != (0x82BE7)
      || s.m1[(0xD9657)].i != (8969) || uv[(0x883)].i != (0x3A8) || uv[(3)].i != (0x6FB788)
      || uv[(0x1F0)].i != (0xA))) &((int)((0x999A)))))))))))*((short)((((int)(uv[(0x9F5F6)].i != (110))) &((int)(uv[(-4)].i != (0x95C1) + (34) *((long)((((int)(s.m1[(288230376151711744)].i != (W) uv || s.m1[(-2)].i != (0xE3EA) || s.m1[(-3)].i != (-1000)
      || s.m1[(-4)].i != (0x7B3BF) || uv[(0)].i != (-112) || uv[(-2)].i != (-223)
      || uv[(4)].i != (0))) &((int)((0x28A79D))))))+((int)((((int)((0xE30C4))) %((int)(uv[(8)].i)))))+((short)((((int)(s.m1[(0x68)].i != (W) uv || s.m1[(65)].i != (0) || s.m1[(0x2E2B)].i != (1015))) >>((int)(s.m1[(2)].i != (265))))))-((int)((((int)(s.m1[(0xFCD9)].i != (W) uv || s.m1[(-2)].i != (1) || s.m1[(-3)].i != (871)
      || s.m1[(0xA8)].i != (0x5CEB004) || uv[(8192)].i != (0x78410C) || uv[(-2)].i != (-223)
      || uv[(0xCD)].i != (-1))) <<((int)(uv[(0x3)].i)))))*((int)((((int)((777))) <<((int)(s.m1[(8)].i != (4873))))))+((long)((((int)(uv[(0x39)].i != (0xCF1AC))) ^((int)((1099511627776))))))-((int)((((int)((W) uv)) |((int)(s.m1[(0xD4C6)].i != (W) uv || s.m1[(-2)].i != (0))))))-((long)((((int)(uv[(-3)].i != (0x6CFB))) <<((int)(uv[(65)].i)))))-((int)((((int)(s.m1[(0x52656)].i)) ^((int)((0xD3D5))))))+((short)((((int)(uv[(0xD9F)].i != (4))) ^((int)((-1000)))))))))))-((short)((((int)(uv[(0x29)].i != (103))) ^((int)((42) *((long)((((int)(s.m1[(-1)].i != (W) uv || s.m1[(3)].i != (0x4C02) || s.m1[(2)].i != (871)
      || s.m1[(3)].i != (4873) || uv[(4503599627370496)].i != (0x4010) || uv[(1)].i != (-223)
      || uv[(2)].i != (0xC))) &((int)((-778)))))))))))*((long)((((int)((int)s.m1[(-1)].i != (W) uv)) %((int)((int)s.m1[(17179869184)].i != (W) uv)))))-((long)((((int)((int)s.m1[(0x441C6)].i != (W) uv || s.m1[(1)].i != (0xB) || s.m1[(2)].i != (871))) &((int)(((short)((((int)(s.m1[(0)].i != (W) uv || s.m1[(-2)].i != (-1) || s.m1[(10)].i != (999))) >>((int)(s.m1[(-4)].i != (0x164E)))))))))))-((short)((((int)((int)s.m1[(-1)].i != (W) uv || s.m1[(-2)].i != (2048))) >>((int)(uv[(3)].i != (0x332CF86))))))+((short)((((int)(s.m1[(6)].i != (999))) |((int)((int)s.m1[(2)].i != (W) uv || s.m1[(-2)].i != (9007199254740992) || s.m1[(0x64C)].i != (1007)
      || s.m1[(0xC)].i != (-778))))))-((short)((((int)(s.m1[(-2)].i != (0xFAD30))) <<((int)(((long)((((int)(s.m1[(0x1)].i != (W) uv || s.m1[(-2)].i != (0) || s.m1[(0x5C1E2)].i != (-1000)
      || s.m1[(131)].i != (778) || uv[(8192)].i != (-112) || uv[(-2)].i != (282)
      || uv[(66)].i != (0))) &((int)((777)))))))))))+((long)((((int)(uv[(0)].i)) ^((int)((-445) + (40) *((long)((((int)(s.m1[(2)].i != (W) uv || s.m1[(0xF0)].i != (2305843009213693952) || s.m1[(2)].i != (995)
      || s.m1[(-4)].i != (-778) || uv[(0)].i != (111) || uv[(0xAF)].i != (0x571)
      || uv[(0x8F)].i != (0x13))) &((int)((-778)))))))))))+((short)((((int)(uv[(0)].i != (109))) <<((int)(uv[(3)].i != (254))))))))
    { abort (); }
  exit ((-1));
}
/* ProgramSourceLLVM */
