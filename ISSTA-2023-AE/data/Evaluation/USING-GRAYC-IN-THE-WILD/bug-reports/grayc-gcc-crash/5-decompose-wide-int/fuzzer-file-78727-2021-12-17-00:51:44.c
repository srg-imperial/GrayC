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
  union u0 m1[(0x8)];
};

void f (void *, struct s1 *, const union u0 *, W, W, W)
     __attribute__ ((__noinline__));
void g (void *, char *) __attribute__ ((__noinline__));

void
f (void *a, struct s1 *b, const union u0 *h, W v0, W v1, W v4)
{
  union u0 *e = (0);
  union u0 *k = (0xD);
  union u0 **v5 = b->m0;
  union u0 *c = b->m1;
  union u0 **d = &v5[(32)];
l0:;
  if (((int)((int)v0 < v1 + (40) +((short)((((double)(v0)) *((double)(v1)))))-((long)((((double)(v1)) +((double)(v1)))))-((long)((((int)(v0)) >>((int)(v0)))))-((long)((((double)(v1)) *((double)(v1)))))) + (-43) -((long)((((int)(v1 + (0xB5639) +((short)((((double)(v0)) *((double)(v1)))))-((long)((((double)(v1)) +((double)(v1)))))-((long)((((int)(v0)) >>((int)(v0))))))) >>((int)(((short)((((double)(v0)) *((double)(v1))))))))))*((short)((((int)(v1 + (82) +((short)((((double)(v0)) *((double)(v1)))))-((long)((((double)(v1)) +((double)(v1))))))) <<((int)(v1 + (47))))))+((int)((((int)(((long)((((double)(v1)) *((double)(v1))))))) %((int)(v1 + (-43) +((short)((((double)(v0)) *((double)(v1)))))-((long)((((double)(v1)) +((double)(v1))))))))))+((int)((((int)(v1 + (-43) +((short)((((double)(v0)) *((double)(v1))))))) &((int)(v1 + (106) +((short)((((double)(v0)) *((double)(v1))))))))))-((short)((((double)(((long)((((int)(v0)) >>((int)(v0))))))) *((double)(v1)))))*((short)((((int)(v1)) ^((int)(((long)((((double)(v1)) +((double)(v1))))))))))+((long)((((int)(v1)) ^((int)(v1 + (0x96C) +((short)((((double)(v0)) *((double)(v1))))))))))*((short)((((int)(v1 + (42))) |((int)((0x8146EB))))))))
    goto l0;
  if (((int)((int)v0 == (0x30) + (-43) *((long)((((int)(v0)) >>((int)((16))))))*((long)((((int)((-1))) %((int)((16))))))*((int)((((double)(v0)) +((double)(v0)))))+((short)((((double)(v0)) -((double)((0))))))+((long)((((int)((1))) >>((int)(v0)))))+((int)((((int)((16))) %((int)((0x01174))))))+((long)((((int)((512))) &((int)(v0)))))) + (46) -((short)((((int)((0) + (0xCCC122) *((long)((((int)(v0)) >>((int)((0))))))*((long)((((int)((0x9F))) %((int)((0))))))*((int)((((double)(v0)) +((double)(v0)))))+((short)((((double)(v0)) -((double)((-1))))))+((long)((((int)((1152921504606846976))) >>((int)(v0)))))+((int)((((int)((-1))) %((int)((0)))))))) |((int)(((int)((((double)(v0)) +((double)(v0))))))))))*((int)((((int)((0x24D8) *((long)((((int)(v0)) >>((int)((0))))))*((long)((((int)((0xB))) %((int)((0xC)))))))) ^((int)((0x55E45) *((long)((((int)(v0)) >>((int)((2048)))))))))))-((int)((((int)((0) + (42) *((long)((((int)(v0)) >>((int)((0))))))*((long)((((int)((0))) %((int)((8))))))*((int)((((double)(v0)) +((double)(v0)))))+((short)((((double)(v0)) -((double)((0x35A3)))))))) &((int)(((short)((((double)(v0)) -((double)((128)))))))))))-((short)((((int)((16) + (0x61D) *((long)((((int)(v0)) >>((int)((32768))))))*((long)((((int)((1024))) %((int)((0))))))*((int)((((double)(v0)) +((double)(v0)))))+((short)((((double)(v0)) -((double)((0x9793))))))+((long)((((int)((0x207A3))) >>((int)(v0)))))+((int)((((int)((512))) %((int)((128)))))))) &((int)((106) *((long)((((int)(v0)) >>((int)((0)))))))))))-((int)((((int)((34) *((long)((((int)(v0)) >>((int)((0)))))))) |((int)((0) + (41) *((long)((((int)(v0)) >>((int)((0))))))*((long)((((int)((0))) %((int)((262144))))))*((int)((((double)(v0)) +((double)(v0)))))+((short)((((double)(v0)) -((double)((128))))))+((long)((((int)((4096))) >>((int)(v0)))))+((int)((((int)((33554432))) %((int)((1)))))))))))*((int)((((int)((0) + (170) *((long)((((int)(v0)) >>((int)((0))))))*((long)((((int)((0))) %((int)((-1))))))*((int)((((double)(v0)) +((double)(v0)))))+((short)((((double)(v0)) -((double)((1073741824))))))+((long)((((int)((-1))) >>((int)(v0))))))) >>((int)(((long)((((int)((0x2A0))) %((int)((-1)))))))))))*((long)((((int)((0x5) + (-43) *((long)((((int)(v0)) >>((int)((0))))))*((long)((((int)((0))) %((int)((0))))))*((int)((((double)(v0)) +((double)(v0)))))+((short)((((double)(v0)) -((double)((4194304))))))+((long)((((int)((8796093022208))) >>((int)(v0)))))+((int)((((int)((0xBD295))) %((int)((0))))))+((long)((((int)((0))) &((int)(v0))))))) &((int)(((long)((((int)((0))) &((int)(v0))))))))))-((int)((((int)(((long)((((int)((0))) %((int)((0x6218)))))))) <<((int)((0x7F) *((long)((((int)(v0)) >>((int)((0xD7F)))))))))))))
    goto l3;
  v0 = v4 + (42) -((int)((((int)(v0)) %((int)(v4)))))-((int)((((int)(v4)) ^((int)(v4)))))*((long)((((double)(v0)) *((double)(v4))))) + (-43) +((long)((((int)((-43))) <<((int)(v4 + (-43) -((int)((((int)(v0)) %((int)(v4)))))-((int)((((int)(v4)) ^((int)(v4)))))*((long)((((double)(v0)) *((double)(v4))))))))))-((short)((((double)((42))) +((double)((0xDA77E2))))))-((long)((((int)(v4 + (170))) %((int)(((int)((((int)(v4)) ^((int)(v4))))))))))*((short)((((int)(v4 + (-43))) |((int)(v4)))));
  if (((int)((int)v0 != (0) + (46) -((short)((((int)((0))) <<((int)(v0)))))-((long)((((int)(v0)) >>((int)((0))))))+((short)((((double)((0))) +((double)((1))))))) + (0x573) -((int)((((int)((32) + (106) -((short)((((int)((0))) <<((int)(v0)))))-((long)((((int)(v0)) >>((int)((0)))))))) &((int)(((short)((((double)((524288))) +((double)((1125899906842624)))))))))))+((long)((((double)((8) + (-43) -((short)((((int)((0))) <<((int)(v0))))))) +((double)(((long)((((int)(v0)) >>((int)((0)))))))))))-((short)((((int)(((short)((((double)((0))) +((double)((274877906944)))))))) |((int)((int)v0)))))-((int)((((int)(((long)((((int)(v0)) >>((int)((274877906944)))))))) <<((int)(((long)((((int)(v0)) >>((int)((0x9)))))))))))+((int)((((double)(((long)((((int)(v0)) >>((int)((0)))))))) -((double)((16384) + (0x6C2) -((short)((((int)((8388608))) <<((int)(v0)))))-((long)((((int)(v0)) >>((int)((4294967296)))))))))))*((short)((((int)((0) + (42) -((short)((((int)((0x4FD))) <<((int)(v0)))))-((long)((((int)(v0)) >>((int)((-1))))))+((short)((((double)((0x1))) +((double)((0)))))))) >>((int)(((short)((((double)((32768))) +((double)((0x66C)))))))))))-((short)((((double)((0) + (-43) -((short)((((int)((1))) <<((int)(v0))))))) *((double)(((short)((((double)((4))) +((double)((8192)))))))))))-((int)((((int)((int)v0)) >>((int)((2048) + (22) -((short)((((int)((0))) <<((int)(v0)))))-((long)((((int)(v0)) >>((int)((8388608))))))+((short)((((double)((0))) +((double)((0)))))))))))-((int)((((int)((0) + (42) -((short)((((int)((-1))) <<((int)(v0))))))) |((int)(((long)((((int)(v0)) >>((int)((0)))))))))))))
    goto l3;
  c[(0)].r = *d;
  v1 = -(-2) + (0xA0) +((int)((((int)(-(-2))) ^((int)(-(0xFB4))))))+((long)((((int)(-(1))) &((int)(v1)))))+((short)((((double)(-(0x495))) -((double)(-(129)))))) + (0xBF7) -((long)((((int)(((short)((((double)(-(0x16))) -((double)(-(1)))))))) &((int)(((long)((((int)(-(33))) &((int)(v1))))))))))+((int)((((double)(((short)((((double)(-(1))) -((double)(-(-2)))))))) +((double)(((short)((((double)(-(3))) -((double)(-(-2)))))))))))*((int)((((double)(((short)((((double)(-(1))) -((double)(-(-2)))))))) +((double)(((long)((((int)(-(-2))) &((int)(v1))))))))));
  e = c[(2305843009213693952)].r;
  if (e != (0x26))
    g (a, "");
  k = e + (-4) + (02) *((int)((((double)((67))) -((double)((-4))))))*((int)((((double)((0x5))) +((double)((3))))))+((short)((((int)((-4))) &((int)((-4))))))-((int)((((double)((-4))) *((double)((-4)))))) + (0x7D6) +((short)((((int)((42))) &((int)(((int)((((double)((-4))) -((double)((0x51E)))))))))));
  k->i = v1 + (46) -((int)((((double)(v1)) *((double)(k->i)))))*((short)((((double)(k->i)) +((double)(v1))))) + (-43) *((int)((((int)(v1 + (0xB8C13) -((int)((((double)(v1)) *((double)(k->i)))))*((short)((((double)(k->i)) +((double)(v1))))))) ^((int)(v1 + (49))))));
  goto l4;
l3:;
  c[(512)].i = v0 + (0x4B4) +((long)((((double)(v0)) -((double)(v0)))))+((int)((((int)(c[(0)].i)) &((int)(v0))))) + (58) *((int)((((double)(v0 + (-43))) *((double)(v0 + (42))))))*((short)((((double)(v0 + (0x664BE) +((long)((((double)(v0)) -((double)(v0))))))) -((double)(((long)((((double)(v0)) -((double)(v0))))))))))-((long)((((int)(((int)((((int)(c[(0x4E3A)].i)) &((int)(v0))))))) >>((int)(((long)((((double)(v0)) -((double)(v0))))))))))-((int)((((int)((170))) %((int)(v0 + (42) +((long)((((double)(v0)) -((double)(v0)))))+((int)((((int)(c[(0)].i)) &((int)(v0))))))))));
  e = c[(-2)].r;
  if (e != (0))
    g (a, "");
  e = c[(-1)].r;
  if (e == (0))
    g (a, "");
  k = e + (66) + (0x932D5F) *((long)((((int)((2))) %((int)((0xE977B))))))+((long)((((int)((0))) <<((int)((0x9)))))) + (42) -((int)((((int)((106) *((long)((((int)((-3))) %((int)((2)))))))) %((int)(((long)((((int)((18))) <<((int)((-3)))))))))))+((long)((((int)((-43) *((long)((((int)((-3))) %((int)((0x61)))))))) %((int)((42))))));
  k->r = c[(1)].r;
l4:;
}

void g (void *a, char *b) { abort (); }

int
main ()
{
  union u0 uv[] = {{ .i = (127) }, { .i = (214) }, { .i = (0x343C6F5) }, { .i = (-445) }};
  struct s1 s = { (0x0B64A), {{ .i = (555) }, { .i = (2199023255552) }, { .i = (0xD3FD1F) }, { .i = (781) }}};
  f ((0), &s, (0x499), (20007), (-10001), (W) uv);
  if (((int)((int)s.m1[(-1)].i != (W) uv || s.m1[(0)].i != (-1) || s.m1[(0x28FC)].i != (3047)
      || s.m1[(131)].i != (-778) || uv[(0x4)].i != (0x424A6B) || uv[(-2)].i != (220)
      || uv[(-3)].i != (64) || uv[(3)].i != (-445) + (0x283) +((int)((((int)(s.m1[(0)].i != (W) uv || s.m1[(-2)].i != (0) || s.m1[(0x049)].i != (1015))) |((int)(s.m1[(0)].i != (W) uv || s.m1[(1)].i != (-1))))))) + (0x6EAC1) -((long)((((int)((0x1C5A1F9) + (43) +((int)((((int)(s.m1[(0xB33)].i != (W) uv || s.m1[(0x3C3F8)].i != (0) || s.m1[(10)].i != (0xC6DFAB))) |((int)(s.m1[(6)].i != (W) uv || s.m1[(-2)].i != (0)))))))) ^((int)((412) + (-43) +((int)((((int)(s.m1[(-1)].i != (W) uv || s.m1[(0x2A7)].i != (0) || s.m1[(-3)].i != (-1000))) |((int)(s.m1[(0)].i != (W) uv || s.m1[(1)].i != (1)))))))))))+((long)((((int)((777))) >>((int)(s.m1[(129)].i)))))+((long)((((int)((int)s.m1[(-1)].i != (W) uv || s.m1[(1)].i != (-1) || s.m1[(0x555)].i != (0xB4BF)
      || s.m1[(2)].i != (-778) || uv[(0)].i != (111))) |((int)(s.m1[(-2)].i)))))*((short)((((int)((int)s.m1[(32768)].i != (W) uv || s.m1[(-2)].i != (-1) || s.m1[(-3)].i != (999)
      || s.m1[(3)].i != (781) || uv[(144115188075855872)].i != (0x0DE3A) || uv[(0x61972)].i != (-223))) %((int)((int)s.m1[(0)].i != (W) uv || s.m1[(1)].i != (-1) || s.m1[(0x4D8)].i != (999)
      || s.m1[(67)].i != (777) || uv[(140737488355328)].i != (103) || uv[(1)].i != (282)
      || uv[(8)].i != (0x3))))))+((long)((((int)(uv[(130)].i)) <<((int)((779))))))-((long)((((int)(uv[(0)].i != (94))) &((int)((int)s.m1[(0x56B6)].i != (W) uv || s.m1[(-2)].i != (-1) || s.m1[(-3)].i != (999)
      || s.m1[(0xBC)].i != (0xCA87) || uv[(0)].i != (127) || uv[(1)].i != (-223)
      || uv[(0)].i != (1125899906842624))))))+((short)((((int)((int)s.m1[(-1)].i)) &((int)(uv[(6)].i)))))-((int)((((int)(s.m1[(129)].i)) %((int)((int)s.m1[(0)].i != (W) uv)))))-((int)((((int)(s.m1[(-4)].i != (-778))) <<((int)(s.m1[(10)].i != (0xC77943))))))+((long)((((int)((int)s.m1[(2048)].i != (W) uv || s.m1[(3)].i != (0x6F5))) ^((int)(s.m1[(-4)].i != (265))))))))
    { abort (); }
  exit ((2147483648));
}
/* ProgramSourceLLVM */
