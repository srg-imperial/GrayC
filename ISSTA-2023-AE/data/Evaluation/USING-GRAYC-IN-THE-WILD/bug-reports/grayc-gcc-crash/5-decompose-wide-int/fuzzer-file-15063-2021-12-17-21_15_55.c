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
  union u0 m1[(6)];
};

void f (void *, struct s1 *, const union u0 *, W, W, W)
     __attribute__ ((__noinline__));
void g (void *, char *) __attribute__ ((__noinline__));

void
f (void *a, struct s1 *b, const union u0 *h, W v0, W v1, W v4)
{
  union u0 *e = (0);
  union u0 *k = (562949953421312);
  union u0 **v5 = b->m0;
  union u0 *c = b->m1;
  union u0 **d = &v5[(0x004)];
l0:;
  if ((0))
    goto l0;
  if ((134217728))
    goto l3;
  v0 = v4 + (10) *((short)((((int)(v4)) |((int)(v4)))))*((int)((((double)(v0)) *((double)(v0)))))*((short)((((double)(v4)) -((double)(v0)))))*((int)((((int)(v4)) |((int)(v4))))) + (10) +((long)((((int)((0x52344) *((short)((((int)(v4)) |((int)(v4)))))*((int)((((double)(v0)) *((double)(v0)))))*((short)((((double)(v4)) -((double)(v0)))))*((int)((((int)(v4)) |((int)(v4))))))) %((int)(v4 + (52) *((short)((((int)(v4)) |((int)(v4)))))*((int)((((double)(v0)) *((double)(v0)))))*((short)((((double)(v4)) -((double)(v0)))))*((int)((((int)(v4)) |((int)(v4))))))))))*((int)((((int)(v0)) ^((int)(v0)))))+((short)((((int)(v4 + (42) *((short)((((int)(v4)) |((int)(v4)))))*((int)((((double)(v0)) *((double)(v0)))))*((short)((((double)(v4)) -((double)(v0)))))*((int)((((int)(v4)) |((int)(v4))))))) &((int)(v4)))))+((short)((((int)(v4 + (42) *((short)((((int)(v4)) |((int)(v4)))))*((int)((((double)(v0)) *((double)(v0)))))*((short)((((double)(v4)) -((double)(v0)))))*((int)((((int)(v4)) |((int)(v4))))))) &((int)(v4)))))+((long)((((int)(v4)) ^((int)((42) *((short)((((int)(v4)) |((int)(v4)))))*((int)((((double)(v0)) *((double)(v0)))))*((short)((((double)(v4)) -((double)(v0)))))*((int)((((int)(v4)) |((int)(v4))))))))));
  if (((int)((int)v0 != (0x2) + (42) *((long)((((int)((-1))) <<((int)((0))))))+((long)((((int)((32))) ^((int)((0))))))) + (0x3FA) +((short)((((int)((10) *((long)((((int)((0xA9A1))) <<((int)((-1)))))))) %((int)((int)v0)))))*((long)((((int)((0x4C3) + (0x31) *((long)((((int)((0xDDCB9))) <<((int)((0))))))+((long)((((int)((-1))) ^((int)((0x9)))))))) ^((int)((0xF))))))-((long)((((int)((int)v0)) |((int)((4) + (42) *((long)((((int)((0))) <<((int)((0))))))+((long)((((int)((0x6D1))) ^((int)((3)))))))))))+((long)((((double)(((long)((((int)((35184372088832))) <<((int)((0x7E0E)))))))) -((double)((42))))))-((short)((((int)(((long)((((int)((-1))) <<((int)((0)))))))) %((int)((-43) *((long)((((int)((0xA2D5))) <<((int)((4611686018427387904)))))))))))+((short)((((int)((-1) + (-43) *((long)((((int)((128))) <<((int)((0x4CB84)))))))) &((int)(((long)((((int)((0x32CAA))) ^((int)((536870912)))))))))))-((short)((((int)((int)v0)) &((int)(((long)((((int)((-1))) <<((int)((0)))))))))))*((int)((((double)((int)v0)) -((double)((int)v0)))))+((short)((((int)(((long)((((int)((0xA86F8))) <<((int)((0x36)))))))) <<((int)((0))))))))
    goto l3;
  c[(-1)].r = *d;
  v1 = -(0x05) + (40) +((long)((((int)(-(0xA80A1))) |((int)(-(65))))))-((short)((((int)(v1)) &((int)(v1)))))+((short)((((int)(v1)) %((int)(-(-2)))))) + (-43) *((long)((((int)(((long)((((int)(-(-2))) |((int)(-(0x9B6F)))))))) |((int)(((short)((((int)(v1)) &((int)(v1))))))))))-((short)((((double)(-(4) + (42))) +((double)(-(0x172) + (-43) +((long)((((int)(-(0xF5AC))) |((int)(-(1))))))-((short)((((int)(v1)) &((int)(v1)))))+((short)((((int)(v1)) %((int)(-(-2)))))))))))*((long)((((int)(-(1) + (-43) +((long)((((int)(-(0x8))) |((int)(-(0x005A)))))))) <<((int)(((long)((((int)(-(-2))) |((int)(-(-2)))))))))))*((long)((((int)(((short)((((int)(v1)) %((int)(-(65)))))))) %((int)(-(0xB) + (0xB2))))))+((short)((((double)(-(0xEB6) + (-43) +((long)((((int)(-(-2))) |((int)(-(1)))))))) -((double)(((short)((((int)(v1)) %((int)(-(-2)))))))))));
  e = c[(4)].r;
  if ((18014398509481984))
    g (a, "");
  k = e + (-4) + (-43) -((short)((((double)((3))) +((double)((19))))))-((short)((((int)((2))) <<((int)((67))))))+((int)((((int)((-4))) <<((int)((-4))))))+((long)((((int)((7))) |((int)((1))))))-((int)((((int)((-4))) %((int)((0x0F)))))) + (0x63D0) -((int)((((int)(((short)((((double)((3))) +((double)((131)))))))) &((int)(((int)((((int)((3))) <<((int)((-4)))))))))))*((short)((((double)(((short)((((int)((-4))) <<((int)((35)))))))) +((double)(((int)((((int)((19))) <<((int)((-4)))))))))))-((int)((((int)(((short)((((double)((-4))) +((double)((2)))))))) <<((int)(((int)((((int)((0xF8F))) %((int)((0x25)))))))))))-((short)((((double)(((short)((((int)((-4))) <<((int)((-4)))))))) +((double)(((int)((((int)((35))) <<((int)((3)))))))))));
  k->i = v1 + (40) -((long)((((int)(v1)) ^((int)(v1)))))+((int)((((double)(v1)) -((double)(v1)))))+((short)((((double)(v1)) -((double)(v1))))) + (43) -((long)((((int)(v1 + (0x11E659))) %((int)(v1 + (-43) -((long)((((int)(v1)) ^((int)(v1)))))+((int)((((double)(v1)) -((double)(v1))))))))))-((short)((((double)(v1 + (42) -((long)((((int)(v1)) ^((int)(v1)))))+((int)((((double)(v1)) -((double)(v1)))))+((short)((((double)(v1)) -((double)(v1))))))) -((double)(v1 + (43) -((long)((((int)(v1)) ^((int)(v1)))))+((int)((((double)(v1)) -((double)(v1)))))+((short)((((double)(v1)) -((double)(v1))))))))))*((short)((((double)(k->i)) -((double)(((long)((((int)(v1)) ^((int)(v1))))))))));
  goto l4;
l3:;
  c[(0)].i = v0 + (-43) -((long)((((int)(v0)) >>((int)(c[(0)].i)))))+((int)((((int)(c[(0)].i)) >>((int)(v0))))) + (10) *((int)((((int)(v0 + (42) -((long)((((int)(v0)) >>((int)(c[(0xB6748)].i)))))+((int)((((int)(c[(1099511627776)].i)) >>((int)(v0))))))) &((int)(c[(0xF98)].i)))));
  e = c[(9)].r;
  if ((32))
    g (a, "");
  e = c[(128)].r;
  if ((256))
    g (a, "");
  k = e + (0) + (42) -((long)((((int)((-3))) >>((int)((3))))))+((int)((((int)((2))) &((int)((2))))))*((int)((((int)((0x0B))) <<((int)((6))))))-((int)((((double)((2))) *((double)((2)))))) + (46) +((short)((((int)(((int)((((int)((-3))) &((int)((0x8AF))))))*((int)((((int)((130))) <<((int)((0)))))))) &((int)(((int)((((int)((0xC391))) <<((int)((0)))))))))))-((int)((((double)((0x59))) -((double)(((int)((((int)((10))) &((int)((6)))))))))));
  k->r = c[(0x5A)].r;
l4:;
}

void g (void *a, char *b) { abort (); }

int
main ()
{
  union u0 uv[] = {{ .i = (0x592) }, { .i = (-223) }, { .i = (0x9C4) }, { .i = (444) }};
  struct s1 s = { (0), {{ .i = (8747) }, { .i = (0) }, { .i = (-1000) }, { .i = (776) }}};
  f ((0xCC), &s, (0xE), (0x135AF), (0x8B009), (W) uv);
  if (((int)((int)s.m1[(0)].i != (W) uv || s.m1[(3)].i != (18014398509481984) || s.m1[(-3)].i != (999)
      || s.m1[(0x0C)].i != (777) || uv[(0)].i != (-112) || uv[(1)].i != (0x047)
      || uv[(-3)].i != (0) || uv[(131)].i != (0x1B943) + (-43) *((long)((((int)(s.m1[(1)].i != (W) uv || s.m1[(0xFDDD9)].i != (128) || s.m1[(34)].i != (995)
      || s.m1[(1)].i != (0xD814) || uv[(549755813888)].i != (111) || uv[(1)].i != (0x9BDF337)
      || uv[(10)].i != (-1))) &((int)((0x8984B9))))))+((int)((((int)((8636))) %((int)(uv[(34)].i)))))+((short)((((int)(s.m1[(0x654A1)].i != (W) uv || s.m1[(1)].i != (4) || s.m1[(2)].i != (0xCC7240))) >>((int)(s.m1[(7)].i != (-778))))))-((int)((((int)(s.m1[(0xF)].i != (W) uv || s.m1[(129)].i != (0) || s.m1[(-3)].i != (998)
      || s.m1[(-4)].i != (-778) || uv[(4)].i != (107) || uv[(0)].i != (222)
      || uv[(0xD)].i != (2305843009213693952))) <<((int)(uv[(0)].i)))))*((int)((((int)((2825))) <<((int)(s.m1[(-4)].i != (0xC9654F))))))+((long)((((int)(uv[(0x7)].i != (141))) ^((int)((35184372088832))))))-((int)((((int)((W) uv)) |((int)(s.m1[(0xB)].i != (W) uv || s.m1[(1)].i != (0))))))-((long)((((int)(uv[(-3)].i != (16777216))) <<((int)(uv[(-2)].i)))))-((int)((((int)(s.m1[(2)].i)) ^((int)((0x99))))))+((short)((((int)(uv[(2)].i != (0xB9C3F))) ^((int)((-1000))))))) + (170) +((long)((((int)((-223))) ^((int)((int)s.m1[(0)].i != (W) uv || s.m1[(-2)].i != (0x035) || s.m1[(2)].i != (-1000)
      || s.m1[(-4)].i != (0xDB89AED) || uv[(0xD135)].i != (239) || uv[(1)].i != (222)
      || uv[(0)].i != (0))))))-((short)((((int)(((short)((((int)(uv[(130)].i != (16))) ^((int)((0x7117)))))))) <<((int)((22))))))+((short)((((int)(((short)((((int)(s.m1[(0)].i != (W) uv || s.m1[(1)].i != (0) || s.m1[(18)].i != (0xAAC1B))) >>((int)(s.m1[(-4)].i != (-778)))))))) %((int)((41) *((long)((((int)(s.m1[(0)].i != (W) uv || s.m1[(3)].i != (0) || s.m1[(-3)].i != (999)
      || s.m1[(0x71)].i != (776) || uv[(0xA)].i != (0xED486) || uv[(0xF3)].i != (022)
      || uv[(2)].i != (256))) &((int)((0x2310FC3)))))))))))-((short)((((int)((int)s.m1[(-1)].i != (W) uv || s.m1[(0xB68)].i != (-1) || s.m1[(-3)].i != (487)
      || s.m1[(11)].i != (-778) || uv[(-1)].i != (111) || uv[(3)].i != (222)
      || uv[(2)].i != (0))) &((int)((int)s.m1[(0)].i != (W) uv || s.m1[(0xB2B3)].i != (32768) || s.m1[(0x0)].i != (743)
      || s.m1[(-4)].i != (781) || uv[(0x9F0)].i != (0xA0B3) || uv[(1)].i != (220)
      || uv[(2)].i != (4096))))))+((long)((((int)((0x4A20AF) + (-43) *((long)((((int)(s.m1[(0x39)].i != (W) uv || s.m1[(-2)].i != (0) || s.m1[(66)].i != (-1000)
      || s.m1[(1)].i != (776) || uv[(-1)].i != (127) || uv[(-2)].i != (0x9607E6B)
      || uv[(0x2B0)].i != (-1))) &((int)((0xD9A59D5))))))+((int)((((int)((0xB7DCD28))) %((int)(uv[(0x9F09)].i)))))+((short)((((int)(s.m1[(-1)].i != (W) uv || s.m1[(9)].i != (0) || s.m1[(0x2C)].i != (-1000))) >>((int)(s.m1[(0x9E5)].i != (777))))))-((int)((((int)(s.m1[(16)].i != (W) uv || s.m1[(-2)].i != (0) || s.m1[(-3)].i != (743)
      || s.m1[(-4)].i != (0xD68) || uv[(128)].i != (-112) || uv[(1)].i != (-223)
      || uv[(66)].i != (6))) <<((int)(uv[(65)].i)))))*((int)((((int)((-778))) <<((int)(s.m1[(3)].i != (-778)))))))) |((int)(((short)((((int)(uv[(0x08)].i != (0x9918))) ^((int)((1015)))))))))))*((long)((((int)(((int)((((int)(s.m1[(0x5AE)].i != (W) uv || s.m1[(-2)].i != (0xAD) || s.m1[(-3)].i != (-1000)
      || s.m1[(-4)].i != (0x1A7658) || uv[(2097152)].i != (0xBF0) || uv[(1)].i != (0x34F369)
      || uv[(-3)].i != (0xDD15D))) <<((int)(uv[(1)].i)))))*((int)((((int)((777))) <<((int)(s.m1[(3)].i != (-778)))))))) >>((int)((-223))))))-((int)((((int)((int)s.m1[(562949953421312)].i != (W) uv || s.m1[(1)].i != (1) || s.m1[(10)].i != (0x8700745))) <<((int)((445) + (-43) *((long)((((int)(s.m1[(0)].i != (W) uv || s.m1[(0x56A)].i != (0) || s.m1[(-3)].i != (0x4A8D57F)
      || s.m1[(0x578E)].i != (0xFAB1BB) || uv[(512)].i != (239) || uv[(1)].i != (0x68227)
      || uv[(-3)].i != (-1))) &((int)((777))))))+((int)((((int)((444))) %((int)(uv[(0xB8D6C)].i)))))+((short)((((int)(s.m1[(268435456)].i != (W) uv || s.m1[(33)].i != (-1) || s.m1[(0xCA9E)].i != (0x075A98))) >>((int)(s.m1[(0x8)].i != (0x42B24CA))))))-((int)((((int)(s.m1[(0x2)].i != (W) uv || s.m1[(3)].i != (0) || s.m1[(-3)].i != (919)
      || s.m1[(0x95B12)].i != (4873) || uv[(512)].i != (-112) || uv[(-2)].i != (0xC35BD)
      || uv[(-3)].i != (34359738368))) <<((int)(uv[(65)].i)))))*((int)((((int)((777))) <<((int)(s.m1[(-4)].i != (-778)))))))))))*((short)((((int)((int)s.m1[(65536)].i != (W) uv)) >>((int)((265))))))))
    { abort (); }
  exit ((0));
}
/* ProgramSourceLLVM */
