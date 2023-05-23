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
  exit ((4));
}

void
f1 (void)
{
  struct x s;
  

s.f = (1) + 42 +((long)((((int)(s.f)) |((int)(s.f)))))+((short)((((int)(s.f)) >>((int)(s.f)))))-((long)((((int)(s.f)) ^((int)((1))))))-((short)((((int)((1))) >>((int)((1))))));
s.f = (1) + 42 *((long)((((double)(s.f)) *((double)((1))))))*((short)((((double)((1))) +((double)(s.f)))))+((long)((((double)((1))) -((double)(s.f)))));
;

s.f = (1) + 42 +((long)((((int)((1))) &((int)(s.f)))));
s.f = (1) + 42 -((int)((((double)((1))) -((double)((1))))))+((short)((((int)((1))) >>((int)(s.f)))));
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
  if (((int)y->f != (-2) || y->c != (-43) + 42 +((long)((((int)(y->f != (-2))) ^((int)(y->f)))))))
    { abort (); }
}
/* ProgramSourceLLVM */
