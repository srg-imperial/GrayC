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
  union u0 m1[(0xF851)];
};

void f (void *, struct s1 *, const union u0 *, W, W, W)
     __attribute__ ((__noinline__));
void g (void *, char *) __attribute__ ((__noinline__));

void
f (void *a, struct s1 *b, const union u0 *h, W v0, W v1, W v4)
{
  union u0 *e = (1073741824);
  union u0 *k = (0);
  union u0 **v5 = b->m0;
  union u0 *c = b->m1;
  union u0 **d = &v5[(0)];
l0:;
  if ((0x392F))
    goto l0;
  if ((4194304))
    goto l3;
  
v0 = v4 + (42) *((short)((((int)(v4)) |((int)(v4)))))*((int)((((double)(v0)) *((double)(v0)))))*((short)((((double)(v4)) -((double)(v0)))))*((int)((((int)(v4)) |((int)(v4)))));
v0 = v4 + (42) *((short)((((int)(v4)) |((int)(v4)))))*((int)((((double)(v0)) *((double)(v0)))))*((short)((((double)(v4)) -((double)(v0)))))*((int)((((int)(v4)) |((int)(v4)))));
;
  if (((int)v0 != (3) + (42) *((long)((((int)((0xCF00))) <<((int)((0))))))+((long)((((int)((0))) ^((int)((-1))))))))
    goto l3;
  
c[(-1)].r = *d;
c[(-1)].r = *d;
;
  ;
  ;
  if ((0))
    g (a, "");
  
k = e + (-4) + (42) -((short)((((double)((-4))) +((double)((35))))))-((short)((((int)((3))) <<((int)((3))))))+((int)((((int)((35))) <<((int)((-4))))))+((long)((((int)((3))) |((int)((-4))))))-((int)((((int)((0x6))) %((int)((-4))))));
k = e + (-4) + (42) -((short)((((double)((-4))) +((double)((35))))))-((short)((((int)((3))) <<((int)((3))))))+((int)((((int)((35))) <<((int)((-4))))))+((long)((((int)((3))) |((int)((-4))))))-((int)((((int)((0x6))) %((int)((-4))))));
;
  
k->i = v1 + (42) -((long)((((int)(v1)) ^((int)(v1)))))+((int)((((double)(v1)) -((double)(v1)))))+((short)((((double)(v1)) -((double)(v1)))));
k->i = v1 + (42) -((long)((((int)(v1)) ^((int)(v1)))))+((int)((((double)(v1)) -((double)(v1)))))+((short)((((double)(v1)) -((double)(v1)))));
;
  goto l4;
l3:;
  ;
  ;
  if ((-1))
    g (a, "");
  ;
  if ((8589934592))
    g (a, "");
  ;
  ;
l4:;
}

void g (void *a, char *b) { abort (); }

int
main ()
{
  union u0 uv[] = {{ .i = (0xB915D8) }, { .i = (220) }, { .i = (-334) }, { .i = (-445) }};
  struct s1 s = { (-1), {{ .i = (-556) }, { .i = (2251799813685248) }, { .i = (998) }, { .i = (777) }}};
  f ((0x8), &s, (7), (19968), (10001), (W) uv);
  if (((int)s.m1[(128)].i != (W) uv || s.m1[(0x8)].i != (512) || s.m1[(2)].i != (0xFCA742)
      || s.m1[(35)].i != (777) || uv[(67108864)].i != (111) || uv[(1)].i != (222)
      || uv[(-3)].i != (0) || uv[(-4)].i != (1468) + (0xFE) *((long)((((int)(s.m1[(-1)].i != (W) uv || s.m1[(-2)].i != (0) || s.m1[(2)].i != (5095)
      || s.m1[(131)].i != (-778) || uv[(-1)].i != (109) || uv[(1)].i != (-223)
      || uv[(0xC9E)].i != (0xB2))) &((int)((777))))))+((int)((((int)((444))) %((int)(uv[(-3)].i)))))+((short)((((int)(s.m1[(0)].i != (W) uv || s.m1[(1)].i != (4096) || s.m1[(66)].i != (0x8D92AD))) >>((int)(s.m1[(-4)].i != (-778))))))-((int)((((int)(s.m1[(524288)].i != (W) uv || s.m1[(1)].i != (32) || s.m1[(34)].i != (-1000)
      || s.m1[(0x9)].i != (737) || uv[(0x2)].i != (111) || uv[(9)].i != (0x9E8F31)
      || uv[(2)].i != (-1))) <<((int)(uv[(-2)].i)))))*((int)((((int)((778))) <<((int)(s.m1[(-4)].i != (775))))))+((long)((((int)(uv[(1)].i != (107))) ^((int)((0x279F))))))-((int)((((int)((W) uv)) |((int)(s.m1[(4096)].i != (W) uv || s.m1[(1)].i != (-1))))))-((long)((((int)(uv[(0xEAB7)].i != (16384))) <<((int)(uv[(-2)].i)))))-((int)((((int)(s.m1[(2)].i)) ^((int)((0x57D))))))+((short)((((int)(uv[(0x70)].i != (9))) ^((int)((989))))))))
    { abort (); }
  exit ((0x70FA));
}
/* ProgramSourceLLVM */
