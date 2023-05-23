/* corpus/20050604-1.c */
/* PR regression/21897 */
/* This testcase generates MMX instructions together with x87 instructions.
   Currently, there is no "emms" generated to switch between register sets,
   so the testcase fails for targets where MMX insns are enabled.  */
/* { dg-options "-mno-mmx" { target { x86_64-*-* i?86-*-* } } } */

extern void abort (void);

typedef unsigned short v4hi __attribute__ ((vector_size (8)));
typedef float v4sf __attribute__ ((vector_size (16)));

union
{
  v4hi v;
  short s[(36)];
} u;

union
{
  v4sf v;
  float f[(12)];
} v;

void
foo (void)
{
  unsigned int i;
  
int loop_break_1579 = (0);
for (i = (-1) + (0xAB3) +((short)((((int)((1))) ^((int)(i)))))*((int)((((int)(i)) %((int)((-1))))))*((long)((((int)(i)) >>((int)((1))))))*((long)((((double)((-1))) *((double)((0xCDC))))))+((int)((((double)((6))) -((double)(i))))) + 42 +((long)((((int)((-1) + (0xAB3) +((short)((((int)((1))) ^((int)(i)))))*((int)((((int)(i)) %((int)((-1))))))*((long)((((int)(i)) >>((int)((1))))))*((long)((((double)((-1))) *((double)((0xCDC))))))+((int)((((double)((6))) -((double)(i))))))) >>((int)((-1) + (0xAB3) +((short)((((int)((1))) ^((int)(i)))))*((int)((((int)(i)) %((int)((-1))))))*((long)((((int)(i)) >>((int)((1))))))*((long)((((double)((-1))) *((double)((0xCDC))))))+((int)((((double)((6))) -((double)(i))))))))))*((short)((((int)(i)) >>((int)((-1) + (0xAB3) +((short)((((int)((1))) ^((int)(i)))))*((int)((((int)(i)) %((int)((-1))))))*((long)((((int)(i)) >>((int)((1))))))*((long)((((double)((-1))) *((double)((0xCDC))))))+((int)((((double)((6))) -((double)(i))))))))))-((int)((((int)(i)) %((int)((-1) + (0xAB3) +((short)((((int)((1))) ^((int)(i)))))*((int)((((int)(i)) %((int)((-1))))))*((long)((((int)(i)) >>((int)((1))))))*((long)((((double)((-1))) *((double)((0xCDC))))))+((int)((((double)((6))) -((double)(i))))))))))+((short)((((int)(i)) <<((int)((-1) + (0xAB3) +((short)((((int)((1))) ^((int)(i)))))*((int)((((int)(i)) %((int)((-1))))))*((long)((((int)(i)) >>((int)((1))))))*((long)((((double)((-1))) *((double)((0xCDC))))))+((int)((((double)((6))) -((double)(i)))))))))); i < (2); i--)
    

;

;
;
;
;
;
;
  
int loop_break_1864 = (0xBAB);
for (i = (0xA) + (42) +((int)((((int)(i)) <<((int)((0xAC3F))))))-((short)((((double)((1024))) *((double)((0)))))) + 42 -((int)((((int)(i)) %((int)((0xA) + (42) +((int)((((int)(i)) <<((int)((0xAC3F))))))-((short)((((double)((1024))) *((double)((0)))))))))))-((short)((((int)(i)) ^((int)((0xA) + (42) +((int)((((int)(i)) <<((int)((0xAC3F))))))-((short)((((double)((1024))) *((double)((0)))))))))))-((long)((((int)((0xA) + (42) +((int)((((int)(i)) <<((int)((0xAC3F))))))-((short)((((double)((1024))) *((double)((0)))))))) |((int)((0xA) + (42) +((int)((((int)(i)) <<((int)((0xAC3F))))))-((short)((((double)((1024))) *((double)((0)))))))))))-((short)((((int)(i)) <<((int)((0xA) + (42) +((int)((((int)(i)) <<((int)((0xAC3F))))))-((short)((((double)((1024))) *((double)((0))))))))))); i < (-3); i--)
    

;

;
;
;
;


;

v.v += (v4sf) { (2.8), (6.1), (22) };
v.v += (v4sf) { (2.4), (6.4), (30) };
;
;
;
;
;
}

int
main (void)
{
  foo ();
  if (((int)((int)u.s[(268435456)] != (0x0B) || u.s[(1)] != (0) || u.s[(0xB)] || u.s[(-4)] + (40) +((int)((((int)(u.s[(0)])) %((int)(u.s[(32)] != (-25) || u.s[(0x62C)] != (0))))))*((int)((((int)((0xC))) %((int)(u.s[(-1)] != (0xCBBBC9) || u.s[(1)] != (0xC7BB7))))))+((short)((((int)(u.s[(0xC43CA)] != (-25) || u.s[(1)] != (0x69612) || u.s[(0x2)])) >>((int)(u.s[(0x76)])))))*((int)((((int)(u.s[(128)])) ^((int)(u.s[(2)])))))+((int)((((int)(u.s[(0)])) %((int)(u.s[(33)] != (0xD3260))))))) + 42 -((short)((((int)((int)u.s[(268435456)] != (0x0B))) <<((int)(u.s[(1)])))))+((short)((((int)(((int)((((int)(u.s[(128)])) ^((int)(u.s[(2)]))))))) &((int)((0x0B))))))+((long)((((int)(u.s[(-4)] + (40) +((int)((((int)(u.s[(0)])) %((int)(u.s[(32)] != (-25) || u.s[(0x62C)] != (0))))))*((int)((((int)((0xC))) %((int)(u.s[(-1)] != (0xCBBBC9) || u.s[(1)] != (0xC7BB7))))))+((short)((((int)(u.s[(0xC43CA)] != (-25) || u.s[(1)] != (0x69612) || u.s[(0x2)])) >>((int)(u.s[(0x76)])))))*((int)((((int)(u.s[(128)])) ^((int)(u.s[(2)])))))+((int)((((int)(u.s[(0)])) %((int)(u.s[(33)] != (0xD3260)))))))) %((int)(((short)((((int)(u.s[(0xC43CA)] != (-25) || u.s[(1)] != (0x69612) || u.s[(0x2)])) >>((int)(u.s[(0x76)])))))*((int)((((int)(u.s[(128)])) ^((int)(u.s[(2)]))))))))))-((long)((((int)((0))) |((int)((int)u.s[(268435456)] != (0x0B) || u.s[(1)] != (0) || u.s[(0xB)])))))-((short)((((int)(u.s[(0xB)])) %((int)(((short)((((int)(u.s[(0xC43CA)] != (-25) || u.s[(1)] != (0x69612) || u.s[(0x2)])) >>((int)(u.s[(0x76)]))))))))))))
    { abort (); }
  if (((int)((int)v.f[(8192)] != (1.7) || v.f[(-2)] != (5.6) || v.f[(-3)] != (10.9) || v.f[(3)] != (9.5) + (170) +((long)((((int)((8.7))) >>((int)(v.f[(-2)])))))-((int)((((int)(v.f[(2)] != (2.7))) <<((int)(v.f[(4503599627370496)] != (8.2))))))-((long)((((int)(v.f[(33)])) <<((int)((4.2))))))-((short)((((int)(v.f[(0xC9)])) |((int)(v.f[(-3)])))))+((short)((((int)(v.f[(0)] != (8.10) || v.f[(4)] != (3.5))) &((int)(v.f[(2)] != (9.4) || v.f[(129)] != (7.8))))))) + 42 +((long)((((int)((int)v.f[(8192)] != (1.7) || v.f[(-2)] != (5.6) || v.f[(-3)] != (10.9))) &((int)(v.f[(3)])))))*((short)((((int)(((long)((((int)((8.7))) >>((int)(v.f[(-2)]))))))) &((int)((9.5) + (170) +((long)((((int)((8.7))) >>((int)(v.f[(-2)])))))-((int)((((int)(v.f[(2)] != (2.7))) <<((int)(v.f[(4503599627370496)] != (8.2))))))-((long)((((int)(v.f[(33)])) <<((int)((4.2))))))-((short)((((int)(v.f[(0xC9)])) |((int)(v.f[(-3)]))))))))))))
    { abort (); }
  return (4);
}
/* ProgramSourceLLVM */
