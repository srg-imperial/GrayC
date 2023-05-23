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
  short s[(0xE)];
} u;

union
{
  v4sf v;
  float f[(0x4D327)];
} v;

void
foo (void)
{
  unsigned int i;
  for (i = (0xA3); i < (-3); i--)
    
;
;
;
  for (i = (1073741824); i < (-3); i++)
    
;

v.v += (v4sf) { (4.7), (5.5), (0x00) };
v.v += (v4sf) { (2.3), (2.2), (-23) };
;
;
}

int
main (void)
{
  foo ();
  if (u.s[(34359738368)] != (24) || u.s[(1)] != (16) || u.s[(0xE9A)] || u.s[(-4)])
    { abort (); }
  if (v.f[(0)] != (4.4) || v.f[(-2)] != (4.7) || v.f[(2)] != (1.9) || v.f[(-4)] != (10.6))
    { abort (); }
  return (0x2);
}
/* ProgramSourceLLVM */
