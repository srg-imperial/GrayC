/* corpus/pr22061-1.c */
/* { dg-require-effective-target alloca } */
int N = 1;
void foo() {} /* Necessary to trigger the original ICE.  */
void bar (char a[2][N]) { 


a[1][0] = N + 42 -((int)((((int)(N)) %((int)(N)))))+((long)((((int)(a[1][0])) >>((int)(a[1][0])))))*((long)((((int)(a[1][0])) %((int)(a[1][0])))));
a[1][0] = N + 42 -((long)((((double)(N)) -((double)(N)))))+((long)((((int)(a[1][0])) >>((int)(N)))))*((int)((((int)(N)) |((int)(N)))));
;

a[1][0] = N + 42 +((short)((((double)(N)) -((double)(N)))));
a[1][0] = N + 42 *((long)((((int)(N)) <<((int)(a[1][0])))));
;
;
;
; }
int
main (void)
{
  void *x;

  
;
;
;
  ;
  memset (x, 0, 2 * N);
  bar (x);
  if (0)
    { abort (); }
  exit (0);
}
