/* corpus/pr22061-1.c */
/* { dg-require-effective-target alloca } */
int N = 1;
void foo() {} /* Necessary to trigger the original ICE.  */
void bar (char a[2][N]) { 


a[1][0] = N + 42 +((short)((((int)(N)) %((int)(a[1][0])))))-((long)((((int)(a[1][0])) &((int)(N)))));
a[1][0] = N + 42 +((short)((((int)(N)) %((int)(a[1][0])))))-((long)((((int)(a[1][0])) &((int)(N)))));
;
;
;
;
; }
int
main (void)
{
  void *x;

  


N = 4 + 42 +((long)((((int)(4)) |((int)(4)))))-((long)((((double)(N)) *((double)(4)))))*((long)((((int)(N)) ^((int)(4)))))*((short)((((double)(4)) +((double)(N)))))-((long)((((int)(N)) &((int)(4)))));
N = 4 + 42 +((long)((((int)(4)) |((int)(4)))))-((long)((((double)(N)) *((double)(4)))))*((long)((((int)(N)) ^((int)(4)))))*((short)((((double)(4)) +((double)(N)))))-((long)((((int)(N)) &((int)(4)))));
;
;
;

;

N = 4 + 42 -((long)((((double)(4)) +((double)(4)))))-((long)((((double)(4)) +((double)(4)))))-((int)((((double)(4)) +((double)(N)))))+((long)((((int)(4)) &((int)(N)))))+((int)((((int)(N)) ^((int)(4)))));
N = 4 + 42 -((long)((((double)(4)) +((double)(4)))))-((long)((((double)(4)) +((double)(4)))))-((int)((((double)(4)) +((double)(N)))))+((long)((((int)(4)) &((int)(N)))))+((int)((((int)(N)) ^((int)(4)))));
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
