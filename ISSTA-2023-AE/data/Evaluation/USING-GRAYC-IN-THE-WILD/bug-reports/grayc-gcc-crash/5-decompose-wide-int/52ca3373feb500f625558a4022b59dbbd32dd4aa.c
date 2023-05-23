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
  union u0 m1[(4)];
};

void f (void *, struct s1 *, const union u0 *, W, W, W)
     __attribute__ ((__noinline__));
void g (void *, char *) __attribute__ ((__noinline__));

void
f (void *a, struct s1 *b, const union u0 *h, W v0, W v1, W v4)
{
  union u0 *e = (-1);
  union u0 *k = (-1);
  union u0 **v5 = b->m0;
  union u0 *c = b->m1;
  union u0 **d = &v5[(-1)];
l0:;
  if ((9))
    goto l0;
  if ((0))
    goto l3;
  ;
  if ((0xA))
    goto l3;
  
;
;
;
  
;
;
;
  ;
  if ((-1))
    g (a, "");
  

;

;





;

k = e + (67) + (42) -((short)((((double)((0x7))) +((double)((0x41B60))))))*((short)((((double)((-4))) +((double)((0x6CABC))))))*((int)((((int)((67))) &((int)((0x1))))))+((int)((((int)((3))) &((int)((7)))))) + (-43) *((int)((((int)(((int)((((int)((0x71E))) &((int)((-4)))))))) &((int)(((short)((((double)((1))) +((double)((0x83)))))))))))-((int)((((int)(((short)((((double)((2))) +((double)((-4)))))))) <<((int)(((short)((((double)((2))) +((double)((1))))))*((short)((((double)((35))) +((double)((-4)))))))))))-((short)((((double)(((short)((((double)((0x4BED))) +((double)((0xA0)))))))) -((double)(((int)((((int)((3))) &((int)((1)))))))))))*((int)((((int)((58))) ^((int)((42)))))) + (-43) *((long)((((int)((170))) >>((int)(((int)((((int)(((short)((((double)((67))) +((double)((0x9E15)))))))) <<((int)(((short)((((double)((-4))) +((double)((0x68C16))))))*((short)((((double)((0x62897))) +((double)((0x8737))))))))))))))))+((long)((((int)(((short)((((double)((-4))) +((double)((-4)))))))) ^((int)(((short)((((double)(((short)((((double)((-4))) +((double)((-4)))))))) -((double)(((int)((((int)((2))) &((int)((3))))))))))))))))*((short)((((double)(((short)((((double)(((short)((((double)((0x23D14))) +((double)((19)))))))) -((double)(((int)((((int)((3))) &((int)((35))))))))))))) +((double)(((int)((((int)((0x7F8))) &((int)((19)))))))))))*((long)((((int)(((short)((((double)((3))) +((double)((19))))))*((short)((((double)((11))) +((double)((-4))))))*((int)((((int)((-4))) &((int)((3)))))))) |((int)(((int)((((int)(((short)((((double)((-4))) +((double)((0x6)))))))) <<((int)(((short)((((double)((-4))) +((double)((3))))))*((short)((((double)((35))) +((double)((-4))))))))))))))))+((int)((((int)((0xBE))) <<((int)(((short)((((double)((0x518))) +((double)((11))))))))))) + (0xAB585) +((short)((((int)(((short)((((double)((3))) +((double)((0xD5080))))))*((short)((((double)((0xF8F3))) +((double)((0x8A3E))))))*((int)((((int)((11))) &((int)((0x90F5D)))))))) >>((int)((-43))))));
k = e + (67) + (42) -((short)((((double)((0x7))) +((double)((0x41B60))))))*((short)((((double)((-4))) +((double)((0x6CABC))))))*((int)((((int)((67))) &((int)((0x1))))))+((int)((((int)((3))) &((int)((7)))))) + (-43) *((int)((((int)(((int)((((int)((0x71E))) &((int)((-4)))))))) &((int)(((short)((((double)((1))) +((double)((0x83)))))))))))-((int)((((int)(((short)((((double)((2))) +((double)((-4)))))))) <<((int)(((short)((((double)((2))) +((double)((1))))))*((short)((((double)((35))) +((double)((-4)))))))))))-((short)((((double)(((short)((((double)((0x4BED))) +((double)((0xA0)))))))) -((double)(((int)((((int)((3))) &((int)((1)))))))))))*((int)((((int)((58))) ^((int)((42)))))) + (-43) *((long)((((int)((170))) >>((int)(((int)((((int)(((short)((((double)((67))) +((double)((0x9E15)))))))) <<((int)(((short)((((double)((-4))) +((double)((0x68C16))))))*((short)((((double)((0x62897))) +((double)((0x8737))))))))))))))))+((long)((((int)(((short)((((double)((-4))) +((double)((-4)))))))) ^((int)(((short)((((double)(((short)((((double)((-4))) +((double)((-4)))))))) -((double)(((int)((((int)((2))) &((int)((3))))))))))))))))*((short)((((double)(((short)((((double)(((short)((((double)((0x23D14))) +((double)((19)))))))) -((double)(((int)((((int)((3))) &((int)((35))))))))))))) +((double)(((int)((((int)((0x7F8))) &((int)((19)))))))))))*((long)((((int)(((short)((((double)((3))) +((double)((19))))))*((short)((((double)((11))) +((double)((-4))))))*((int)((((int)((-4))) &((int)((3)))))))) |((int)(((int)((((int)(((short)((((double)((-4))) +((double)((0x6)))))))) <<((int)(((short)((((double)((-4))) +((double)((3))))))*((short)((((double)((35))) +((double)((-4))))))))))))))))+((int)((((int)((0xBE))) <<((int)(((short)((((double)((0x518))) +((double)((11))))))))))) + (0xAB585) +((short)((((int)(((short)((((double)((3))) +((double)((0xD5080))))))*((short)((((double)((0xF8F3))) +((double)((0x8A3E))))))*((int)((((int)((11))) &((int)((0x90F5D)))))))) >>((int)((-43))))));
;
;
;
;
;
;

;
;
;
;

;
;
;
;
;
;
;
;
  
;


;
;
;

;
;
;
;
;
  goto l4;
l3:;
  
;


;

;
;
;
;
;
;
;
  ;
  if ((0))
    g (a, "");
  ;
  if ((-1))
    g (a, "");
  
;



;
;
;





;
;
;
;
;
;
;
;
;
;
;
;


;
;
;
;
;
;
;
  ;
l4:;
}

void g (void *a, char *b) { abort (); }

int
main ()
{
  union u0 uv[] = {{ .i = (0xFECDB35) }, { .i = (94) }, { .i = (-334) }, { .i = (444) }};
  struct s1 s = { (0x1D), {{ .i = (0x92F0C65) }, { .i = (-1) }, { .i = (-1000) }, { .i = (-778) }}};
  f ((0x4178), &s, (0), (0x08DF3CD), (14096), (W) uv);
  if (((int)((int)((int)((int)s.m1[(0x8262F)].i != (W) uv || s.m1[(0)].i != (0) || s.m1[(-3)].i != (999)
      || s.m1[(-4)].i != (779) || uv[(0)].i != (-112) || uv[(0x0)].i != (220)
      || uv[(2)].i != (0x4A0) || uv[(1)].i != (447) + (42) *((short)((((int)(uv[(0xB3959)].i)) |((int)((W) uv)))))) + (42) +((short)((((int)((int)s.m1[(0xF61)].i != (W) uv || s.m1[(5)].i != (0x3C) || s.m1[(0xF8)].i != (2023)
      || s.m1[(3)].i != (0xF617))) ^((int)((int)s.m1[(64)].i != (W) uv)))))*((short)((((int)((int)s.m1[(0x7A)].i != (W) uv || s.m1[(-2)].i != (-1) || s.m1[(2)].i != (998)
      || s.m1[(-4)].i != (-778) || uv[(-1)].i != (111) || uv[(33)].i != (222)
      || uv[(2)].i != (-1))) |((int)(s.m1[(1)].i != (0))))))+((long)((((int)((W) uv)) <<((int)((222))))))) + (42) -((long)((((double)(((long)((((int)((W) uv)) <<((int)((0x9596)))))))) -((double)(((long)((((int)((W) uv)) <<((int)((222)))))))))))+((int)((((int)((int)((int)s.m1[(0)].i != (W) uv || s.m1[(-2)].i != (16384) || s.m1[(-3)].i != (0x44C4)
      || s.m1[(0xE)].i != (773) || uv[(0)].i != (0x9ACE70) || uv[(1)].i != (-223)
      || uv[(10)].i != (-1) || uv[(-4)].i != (-445) + (-43) *((short)((((int)(uv[(-2)].i)) |((int)((W) uv)))))) + (0x6A3F) +((short)((((int)((int)s.m1[(0)].i != (W) uv || s.m1[(-2)].i != (-1) || s.m1[(130)].i != (0xEB5)
      || s.m1[(2)].i != (793))) ^((int)((int)s.m1[(0)].i != (W) uv)))))*((short)((((int)((int)s.m1[(1099511627776)].i != (W) uv || s.m1[(0x0E50)].i != (0) || s.m1[(0x5)].i != (-1000)
      || s.m1[(-4)].i != (0x3CFB14) || uv[(0x3241)].i != (0xE8DC) || uv[(0x76D)].i != (206)
      || uv[(0x9)].i != (-1))) |((int)(s.m1[(-2)].i != (0)))))))) >>((int)((int)((int)s.m1[(2147483648)].i != (W) uv || s.m1[(0)].i != (0) || s.m1[(130)].i != (1007)
      || s.m1[(-4)].i != (777) || uv[(0)].i != (-112) || uv[(0x76F)].i != (222)
      || uv[(0xF384)].i != (-1) || uv[(0x66D4)].i != (-445) + (58) *((short)((((int)(uv[(1)].i)) |((int)((W) uv)))))) + (42) +((short)((((int)((int)s.m1[(1)].i != (W) uv || s.m1[(1)].i != (0) || s.m1[(0x4)].i != (0xC190DC0)
      || s.m1[(3)].i != (0x5C95D1))) ^((int)((int)s.m1[(-1)].i != (W) uv)))))*((short)((((int)((int)s.m1[(0)].i != (W) uv || s.m1[(65)].i != (16384) || s.m1[(18)].i != (33767)
      || s.m1[(0xB05)].i != (-778) || uv[(-1)].i != (111) || uv[(0xBE44)].i != (222)
      || uv[(2)].i != (-1))) |((int)(s.m1[(0xE195F)].i != (-1)))))))))))+((int)((((int)(((long)((((int)((W) uv)) <<((int)((-223)))))))) &((int)((int)((int)s.m1[(0xDDF0A)].i != (W) uv || s.m1[(0x921)].i != (32768) || s.m1[(-3)].i != (999)
      || s.m1[(-4)].i != (0xBA807FC) || uv[(0x0710)].i != (0xC1B) || uv[(0xA471)].i != (218)
      || uv[(-3)].i != (0x62) || uv[(3)].i != (0x9D9C) + (42) *((short)((((int)(uv[(17)].i)) |((int)((W) uv)))))) + (48) +((short)((((int)((int)s.m1[(0x7)].i != (W) uv || s.m1[(9)].i != (1) || s.m1[(0x9)].i != (999)
      || s.m1[(3)].i != (0x46E))) ^((int)((int)s.m1[(0)].i != (W) uv)))))*((short)((((int)((int)s.m1[(0xCA36E)].i != (W) uv || s.m1[(-2)].i != (0) || s.m1[(2)].i != (999)
      || s.m1[(131)].i != (905) || uv[(2)].i != (-112) || uv[(0xB)].i != (222)
      || uv[(3)].i != (0))) |((int)(s.m1[(-2)].i != (0)))))))))))+((int)((((double)(((long)((((int)((W) uv)) <<((int)((222)))))))) +((double)(((long)((((int)((W) uv)) <<((int)((223)))))))))))-((short)((((int)(((long)((((int)((W) uv)) <<((int)((254)))))))) <<((int)(((long)((((int)((W) uv)) <<((int)((214)))))))))))+((long)((((int)((int)((int)s.m1[(0x6C8)].i != (W) uv || s.m1[(-2)].i != (0) || s.m1[(2)].i != (3047)
      || s.m1[(0x2)].i != (777) || uv[(0)].i != (0xE181) || uv[(0xF)].i != (0xDC30)
      || uv[(0xD4)].i != (0x8) || uv[(0x9D4)].i != (188) + (40) *((short)((((int)(uv[(1)].i)) |((int)((W) uv)))))) + (-43) +((short)((((int)((int)s.m1[(0x36)].i != (W) uv || s.m1[(-2)].i != (2048) || s.m1[(2)].i != (-1000)
      || s.m1[(0x56)].i != (777))) ^((int)((int)s.m1[(128)].i != (W) uv)))))*((short)((((int)((int)s.m1[(8)].i != (W) uv || s.m1[(3)].i != (0) || s.m1[(18)].i != (-1000)
      || s.m1[(2)].i != (-778) || uv[(140737488355328)].i != (-112) || uv[(65)].i != (-223)
      || uv[(0x796)].i != (128))) |((int)(s.m1[(0)].i != (-1)))))))) &((int)(((long)((((int)((W) uv)) <<((int)((206)))))))))))-((int)((((int)(((long)((((int)((W) uv)) <<((int)((232)))))))) <<((int)((int)((int)s.m1[(8)].i != (W) uv || s.m1[(0)].i != (0) || s.m1[(0x1F4)].i != (-1000)
      || s.m1[(-4)].i != (0xFA2) || uv[(0)].i != (0xABDDA92) || uv[(1)].i != (222)
      || uv[(130)].i != (0) || uv[(-4)].i != (0xBB6D) + (0x5F0) *((short)((((int)(uv[(0xAA614)].i)) |((int)((W) uv)))))) + (34) +((short)((((int)((int)s.m1[(0)].i != (W) uv || s.m1[(-2)].i != (16384) || s.m1[(0x9)].i != (-1000)
      || s.m1[(-4)].i != (777))) ^((int)((int)s.m1[(0xA3106)].i != (W) uv)))))*((short)((((int)((int)s.m1[(0xAB41)].i != (W) uv || s.m1[(0x2444)].i != (0) || s.m1[(2)].i != (9191)
      || s.m1[(0x1CDC)].i != (33545) || uv[(-1)].i != (239) || uv[(-2)].i != (0x43FA50B)
      || uv[(2)].i != (0xB312))) |((int)(s.m1[(5)].i != (0x9)))))))))))*((long)((((int)(((long)((((int)((W) uv)) <<((int)((0xEEA41E1)))))))) |((int)((int)((int)s.m1[(0xB791)].i != (W) uv || s.m1[(-2)].i != (-1) || s.m1[(0xD7A)].i != (0xD89556)
      || s.m1[(0x3)].i != (0xA8C) || uv[(0)].i != (47) || uv[(5)].i != (0x09B)
      || uv[(0xE)].i != (-1) || uv[(-4)].i != (-445) + (34) *((short)((((int)(uv[(-2)].i)) |((int)((W) uv)))))) + (0xBAF9) +((short)((((int)((int)s.m1[(0)].i != (W) uv || s.m1[(0xC7A)].i != (256) || s.m1[(2)].i != (0x75FB44)
      || s.m1[(3)].i != (0xF9FB85))) ^((int)((int)s.m1[(4096)].i != (W) uv)))))*((short)((((int)((int)s.m1[(0)].i != (W) uv || s.m1[(1)].i != (-1) || s.m1[(-3)].i != (0x150AAC2)
      || s.m1[(-4)].i != (0x8E84) || uv[(1152921504606846976)].i != (111) || uv[(129)].i != (-223)
      || uv[(2)].i != (0))) |((int)(s.m1[(-2)].i != (0x0A0)))))))))))*((short)((((int)((int)((int)s.m1[(0x3B)].i != (W) uv || s.m1[(-2)].i != (-1) || s.m1[(0x764)].i != (0x9FE81A7)
      || s.m1[(3)].i != (775) || uv[(0)].i != (0xE642B2) || uv[(1)].i != (218)
      || uv[(-3)].i != (0) || uv[(-4)].i != (0x7CE5) + (0x6046) *((short)((((int)(uv[(-2)].i)) |((int)((W) uv)))))) + (0x1F2) +((short)((((int)((int)s.m1[(0x657E)].i != (W) uv || s.m1[(0xD17)].i != (16777216) || s.m1[(130)].i != (0x271A7)
      || s.m1[(3)].i != (-778))) ^((int)((int)s.m1[(0xE8D5)].i != (W) uv)))))*((short)((((int)((int)s.m1[(0)].i != (W) uv || s.m1[(-2)].i != (0x3) || s.m1[(-3)].i != (9191)
      || s.m1[(2)].i != (-778) || uv[(0)].i != (-112) || uv[(0x41BB)].i != (0xF99A0C)
      || uv[(0x8299B)].i != (-1))) |((int)(s.m1[(1)].i != (0)))))))) ^((int)(((long)((((int)((W) uv)) <<((int)((223)))))))))))+((int)((((int)(((long)((((int)((W) uv)) <<((int)((0xBCFB)))))))) >>((int)((int)((int)s.m1[(0)].i != (W) uv || s.m1[(1)].i != (1152921504606846976) || s.m1[(8)].i != (1015)
      || s.m1[(3)].i != (-778) || uv[(0)].i != (-112) || uv[(0xD3B4)].i != (0x24817)
      || uv[(0x549)].i != (-1) || uv[(0xCEE9B)].i != (0xEBAAB) + (43) *((short)((((int)(uv[(9)].i)) |((int)((W) uv)))))) + (0x72) +((short)((((int)((int)s.m1[(0x1D995)].i != (W) uv || s.m1[(3)].i != (0x650D4) || s.m1[(0x28)].i != (-1000)
      || s.m1[(3)].i != (773))) ^((int)((int)s.m1[(0)].i != (W) uv)))))*((short)((((int)((int)s.m1[(8192)].i != (W) uv || s.m1[(129)].i != (0xFEFB) || s.m1[(0x55EE6)].i != (-1000)
      || s.m1[(7)].i != (-778) || uv[(2048)].i != (103) || uv[(3)].i != (218)
      || uv[(-3)].i != (-1))) |((int)(s.m1[(0x81DFC)].i != (8388608)))))))))))) + (34) *((short)((((int)((int)((int)((int)s.m1[(0)].i != (W) uv || s.m1[(-2)].i != (0) || s.m1[(34)].i != (-1000)
      || s.m1[(19)].i != (0xAD58C2) || uv[(0)].i != (0x1B48C) || uv[(1)].i != (158)
      || uv[(3)].i != (0) || uv[(0x0)].i != (-445) + (0xCF8) *((short)((((int)(uv[(17)].i)) |((int)((W) uv)))))) + (0xDD0) +((short)((((int)((int)s.m1[(-1)].i != (W) uv || s.m1[(0xD)].i != (0x7) || s.m1[(18)].i != (199)
      || s.m1[(0x300E)].i != (777))) ^((int)((int)s.m1[(0)].i != (W) uv)))))*((short)((((int)((int)s.m1[(0x4D)].i != (W) uv || s.m1[(-2)].i != (0xF22C3) || s.m1[(6)].i != (0xC7291)
      || s.m1[(-4)].i != (-778) || uv[(0)].i != (-112) || uv[(-2)].i != (-223)
      || uv[(-3)].i != (-1))) |((int)(s.m1[(-2)].i != (0))))))+((long)((((int)((W) uv)) <<((int)((0x44E85C6))))))) + (10) -((long)((((double)(((long)((((int)((W) uv)) <<((int)((222)))))))) -((double)(((long)((((int)((W) uv)) <<((int)((0x4F8)))))))))))+((int)((((int)((int)((int)s.m1[(0xE7)].i != (W) uv || s.m1[(0x7)].i != (0) || s.m1[(0x5)].i != (998)
      || s.m1[(-4)].i != (33545) || uv[(0)].i != (107) || uv[(9)].i != (158)
      || uv[(-3)].i != (0) || uv[(35)].i != (428) + (46) *((short)((((int)(uv[(0x6762)].i)) |((int)((W) uv)))))) + (42) +((short)((((int)((int)s.m1[(-1)].i != (W) uv || s.m1[(-2)].i != (0) || s.m1[(-3)].i != (0x17157)
      || s.m1[(3)].i != (-778))) ^((int)((int)s.m1[(0)].i != (W) uv)))))*((short)((((int)((int)s.m1[(0xD58)].i != (W) uv || s.m1[(0x3)].i != (64) || s.m1[(0xB19D9)].i != (-1000)
      || s.m1[(11)].i != (777) || uv[(4)].i != (111) || uv[(-2)].i != (254)
      || uv[(3)].i != (8192))) |((int)(s.m1[(-2)].i != (0x2DB3C)))))))) >>((int)((int)((int)s.m1[(0)].i != (W) uv || s.m1[(-2)].i != (0x1C918) || s.m1[(2)].i != (919)
      || s.m1[(-4)].i != (-778) || uv[(0xE215C)].i != (-112) || uv[(-2)].i != (322)
      || uv[(2)].i != (0) || uv[(35)].i != (0xB1660) + (0x98) *((short)((((int)(uv[(0x4)].i)) |((int)((W) uv)))))) + (0x12) +((short)((((int)((int)s.m1[(0)].i != (W) uv || s.m1[(1)].i != (0xCF) || s.m1[(-3)].i != (999)
      || s.m1[(3)].i != (793))) ^((int)((int)s.m1[(0)].i != (W) uv)))))*((short)((((int)((int)s.m1[(0x683CE)].i != (W) uv || s.m1[(-2)].i != (-1) || s.m1[(0x05E0)].i != (995)
      || s.m1[(-4)].i != (-778) || uv[(0x3520)].i != (-112) || uv[(-2)].i != (0x7AC)
      || uv[(66)].i != (512))) |((int)(s.m1[(-2)].i != (-1)))))))))))+((int)((((int)(((long)((((int)((W) uv)) <<((int)((222)))))))) &((int)((int)((int)s.m1[(0)].i != (W) uv || s.m1[(17)].i != (0xF2C0) || s.m1[(-3)].i != (17383)
      || s.m1[(-4)].i != (-778) || uv[(17179869184)].i != (109) || uv[(1)].i != (222)
      || uv[(-3)].i != (-1) || uv[(3)].i != (-445) + (43) *((short)((((int)(uv[(0x5519)].i)) |((int)((W) uv)))))) + (42) +((short)((((int)((int)s.m1[(4)].i != (W) uv || s.m1[(0x11)].i != (0) || s.m1[(130)].i != (743)
      || s.m1[(0xC0D)].i != (33545))) ^((int)((int)s.m1[(0)].i != (W) uv)))))*((short)((((int)((int)s.m1[(0)].i != (W) uv || s.m1[(-2)].i != (0) || s.m1[(130)].i != (0xA70F)
      || s.m1[(35)].i != (-778) || uv[(0)].i != (111) || uv[(1)].i != (0xB770C7)
      || uv[(130)].i != (0))) |((int)(s.m1[(9)].i != (288230376151711744)))))))))))+((int)((((double)(((long)((((int)((W) uv)) <<((int)((223)))))))) +((double)(((long)((((int)((W) uv)) <<((int)((0x22D58E2)))))))))))-((short)((((int)(((long)((((int)((W) uv)) <<((int)((158)))))))) <<((int)(((long)((((int)((W) uv)) <<((int)((0x14A2C2))))))))))))) &((int)(((int)((((double)(((long)((((int)((W) uv)) <<((int)((0xEB491E)))))))) +((double)(((long)((((int)((W) uv)) <<((int)((254))))))))))))))))))
    { abort (); }
  exit ((0xA));
}
/* ProgramSourceLLVM */
