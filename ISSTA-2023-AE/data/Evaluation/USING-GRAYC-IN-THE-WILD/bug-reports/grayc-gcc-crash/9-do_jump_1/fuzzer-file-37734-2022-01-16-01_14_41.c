/* corpus/20020227-1.c */
/* This testcase failed on mmix-knuth-mmixware.  Problem was with storing
   to an unaligned mem:SC, gcc tried doing it by parts from a (concat:SC
   (reg:SF 293) (reg:SF 294)).  */

typedef __complex__ float cf;
struct x { char c; cf f; } __attribute__ ((__packed__));
extern void f2 (struct x*);
extern void f1 (void);
int
main (void)
{
  f1 ();
  exit (((0x6)));
}

void
f1 (void)
{
  struct x s;
  

s.f = ((1)) + (-43) +((long)((((int)(s.f)) |((int)(s.f)))))+((short)((((int)(s.f)) >>((int)(s.f)))))-((long)((((int)(s.f)) ^((int)(((-2)))))))-((short)((((int)(((-2)))) >>((int)(((1)))))));
s.f = ((-2)) + (42) *((long)((((double)(s.f)) *((double)(((17)))))))*((short)((((double)(((65)))) +((double)(s.f)))))+((long)((((double)(((9)))) -((double)(s.f)))));
;

s.f = ((-2)) + (0x20BD) +((long)((((int)(((17)))) &((int)(s.f)))));
s.f = ((33)) + (46) -((int)((((double)(((33)))) -((double)(((1)))))))+((short)((((int)(((0x5)))) >>((int)(s.f)))));
;
;
  
;
;
;
  f2 (&s);
}

void
f2 (struct x *y)
{
  if (((int)y->f != (-(130)) || y->c != (-(43)) + (170) +((long)((((int)(y->f != (-(-3)))) ^((int)(y->f)))))))
    { abort (); }
}
/* ProgramSourceLLVM */
