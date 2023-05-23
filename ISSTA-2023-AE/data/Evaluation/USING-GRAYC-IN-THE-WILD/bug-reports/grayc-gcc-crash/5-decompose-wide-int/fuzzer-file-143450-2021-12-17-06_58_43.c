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
  union u0 m1[(0)];
};

void f (void *, struct s1 *, const union u0 *, W, W, W)
     __attribute__ ((__noinline__));
void g (void *, char *) __attribute__ ((__noinline__));

void
f (void *a, struct s1 *b, const union u0 *h, W v0, W v1, W v4)
{
  union u0 *e = (512);
  union u0 *k = (0x55);
  union u0 **v5 = b->m0;
  union u0 *c = b->m1;
  union u0 **d = &v5[(0x770C)];
l0:;
  if ((0x0))
    goto l0;
  if ((0xFC64))
    goto l3;
  v0 = v4 + (58) *((short)((((int)(v4)) |((int)(v4)))))*((int)((((double)(v0)) *((double)(v0)))))*((short)((((double)(v4)) -((double)(v0)))))*((int)((((int)(v4)) |((int)(v4))))) + (-43) -((short)((((double)(v4)) *((double)(v0)))));
  if (((int)((int)v0 != (1) + (42) *((long)((((int)((-1))) <<((int)((128))))))+((long)((((int)((0x3))) ^((int)((36028797018963968))))))) + (34) +((short)((((double)((0))) *((double)((int)v0)))))*((int)((((int)((43) *((long)((((int)((0))) <<((int)((0xE)))))))) >>((int)((0) + (-43) *((long)((((int)((-1))) <<((int)((0xCDB)))))))))))*((int)((((int)(((long)((((int)((0x8))) ^((int)((549755813888)))))))) |((int)((-43))))))+((long)((((double)(((long)((((int)((8))) ^((int)((0)))))))) +((double)((0xE0A))))))+((short)((((int)(((long)((((int)((0))) ^((int)((0x008)))))))) %((int)(((long)((((int)((5))) <<((int)((0)))))))))))-((int)((((int)(((long)((((int)((0))) ^((int)((0x85)))))))) ^((int)((512) + (42) *((long)((((int)((0))) <<((int)((0x03)))))))))))+((long)((((int)((42) *((long)((((int)((0x47))) <<((int)((-1)))))))) |((int)((134217728) + (0x29D24) *((long)((((int)((6))) <<((int)((0x5)))))))))))+((long)((((int)((0) + (-43) *((long)((((int)((0))) <<((int)((8))))))+((long)((((int)((0))) ^((int)((3)))))))) |((int)((int)v0)))))-((short)((((int)(((long)((((int)((-1))) ^((int)((68719476736)))))))) ^((int)((7) + (-43) *((long)((((int)((0))) <<((int)((0)))))))))))*((short)((((int)((42) *((long)((((int)((0x7))) <<((int)((-1)))))))) >>((int)((46) *((long)((((int)((0x9A60))) <<((int)((134217728)))))))))))))
    goto l3;
  c[(0xA)].r = *d;
  v1 = -(-2) + (02) +((long)((((int)(-(1))) |((int)(-(0xD4))))))-((short)((((int)(v1)) &((int)(v1)))))+((short)((((int)(v1)) %((int)(-(129)))))) + (0x9F) +((long)((((double)(-(3) + (-43) +((long)((((int)(-(0x6))) |((int)(-(1))))))-((short)((((int)(v1)) &((int)(v1))))))) +((double)(v1)))))+((int)((((int)(((short)((((int)(v1)) %((int)(-(0x8D16)))))))) >>((int)(((long)((((int)(-(1))) |((int)(-(0x751)))))))))));
  e = c[(0)].r;
  if ((0x0D))
    g (a, "");
  k = e + (3) + (-43) -((short)((((double)((131))) +((double)((0xB418))))))-((short)((((int)((67))) <<((int)((0x24))))))+((int)((((int)((-4))) <<((int)((131))))))+((long)((((int)((0x31F5))) |((int)((-4))))))-((int)((((int)((7))) %((int)((-4)))))) + (42) +((long)((((double)(((int)((((int)((-4))) %((int)((3)))))))) *((double)(((long)((((int)((-4))) |((int)((-4)))))))))));
  k->i = v1 + (0x854) -((long)((((int)(v1)) ^((int)(v1)))))+((int)((((double)(v1)) -((double)(v1)))))+((short)((((double)(v1)) -((double)(v1))))) + (0x1B) *((short)((((double)(v1 + (46))) *((double)((170))))));
  goto l4;
l3:;
  c[(0x55B)].i = v0 + (46) -((long)((((int)(v0)) >>((int)(c[(32)].i)))))+((int)((((int)(c[(0xB72)].i)) >>((int)(v0))))) + (43) -((short)((((int)(v0)) >>((int)(((long)((((int)(v0)) >>((int)(c[(1)].i))))))))))*((short)((((int)((0xA9B7A8))) |((int)(((int)((((int)(c[(0xE3D25)].i)) >>((int)(v0))))))))))*((long)((((int)(v0 + (10))) &((int)(v0 + (22) -((long)((((int)(v0)) >>((int)(c[(-1)].i)))))+((int)((((int)(c[(0)].i)) >>((int)(v0))))))))));
  e = c[(0)].r;
  if ((17179869184))
    g (a, "");
  e = c[(512)].r;
  if ((4))
    g (a, "");
  k = e + (10) + (106) -((long)((((int)((18))) >>((int)((34))))))+((int)((((int)((0x1C))) &((int)((0x4469))))))*((int)((((int)((2))) <<((int)((0xF54CF))))))-((int)((((double)((-3))) *((double)((2)))))) + (43) -((long)((((int)(((int)((((int)((0xD))) <<((int)((2)))))))) &((int)(((int)((((double)((2))) *((double)((-3)))))))))))+((long)((((int)(((int)((((int)((0x645E))) <<((int)((130)))))))) %((int)(((long)((((int)((0xF5B4))) >>((int)((2)))))))))));
  k->r = c[(-2)].r;
l4:;
}

void g (void *a, char *b) { abort (); }

int
main ()
{
  union u0 uv[] = {{ .i = (-112) }, { .i = (220) }, { .i = (0x4666D1) }, { .i = (0x72A7) }};
  struct s1 s = { (0xD), {{ .i = (555) }, { .i = (0x5) }, { .i = (-1000) }, { .i = (-778) }}};
  f ((0), &s, (0), (-20001), (-10001), (W) uv);
  if (((int)((int)s.m1[(0x2)].i != (W) uv || s.m1[(33)].i != (140737488355328) || s.m1[(-3)].i != (0x1EE0E)
      || s.m1[(0xBB90)].i != (-778) || uv[(70368744177664)].i != (-112) || uv[(1)].i != (222)
      || uv[(-3)].i != (-1) || uv[(-4)].i != (444) + (46) *((long)((((int)(s.m1[(0)].i != (W) uv || s.m1[(33)].i != (0) || s.m1[(2)].i != (0x4EC)
      || s.m1[(-4)].i != (777) || uv[(-1)].i != (0x384DA9E) || uv[(0xF42F)].i != (222)
      || uv[(2)].i != (0))) &((int)((0x4F11))))))+((int)((((int)((0x626C69))) %((int)(uv[(2)].i)))))+((short)((((int)(s.m1[(0)].i != (W) uv || s.m1[(1)].i != (0) || s.m1[(0xDBF)].i != (743))) >>((int)(s.m1[(3)].i != (33545))))))-((int)((((int)(s.m1[(0x504A8)].i != (W) uv || s.m1[(0x966)].i != (0) || s.m1[(0x322AE)].i != (999)
      || s.m1[(3)].i != (-778) || uv[(1073741824)].i != (107) || uv[(129)].i != (-223)
      || uv[(2)].i != (-1))) <<((int)(uv[(0x360)].i)))))*((int)((((int)((-778))) <<((int)(s.m1[(0xB)].i != (521))))))+((long)((((int)(uv[(-1)].i != (0x1277))) ^((int)((-1))))))-((int)((((int)((W) uv)) |((int)(s.m1[(0)].i != (W) uv || s.m1[(9)].i != (7))))))-((long)((((int)(uv[(-3)].i != (-1))) <<((int)(uv[(-2)].i)))))-((int)((((int)(s.m1[(0xE)].i)) ^((int)((0x8F))))))+((short)((((int)(uv[(2)].i != (0xC63))) ^((int)((-1000))))))) + (43) +((long)((((int)((W) uv)) ^((int)((-43))))))-((long)((((int)(((long)((((int)(uv[(0x38C6)].i != (127))) ^((int)((0x9)))))))) %((int)((int)s.m1[(-1)].i != (W) uv || s.m1[(8)].i != (0) || s.m1[(2)].i != (999)
      || s.m1[(0xCF95)].i != (8969) || uv[(0x479D5)].i != (0x17638B) || uv[(1)].i != (-223))))))+((int)((((int)((int)s.m1[(-1)].i != (W) uv)) &((int)(((int)((((int)(s.m1[(2)].i)) ^((int)((8192)))))))))))*((short)((((int)(s.m1[(0x35)].i != (0))) &((int)(s.m1[(33)].i != (2))))))))
    { abort (); }
  exit ((0));
}
/* ProgramSourceLLVM */
