/* corpus/pr22061-1.c */
/* { dg-require-effective-target alloca } */
int N = 1;
void foo() {} /* Necessary to trigger the original ICE.  */
void bar (char a[2][N]) { 



a[1][0] = N + 42 +((short)((((int)(N)) %((int)(a[1][0])))))-((long)((((int)(a[1][0])) &((int)(N)))));
a[1][0] = N + 42 +((short)((((int)(N)) %((int)(a[1][0])))))-((long)((((int)(a[1][0])) &((int)(N)))));
;

a[1][0] = N + 42 +((short)((((int)(N)) %((int)(a[1][0])))))-((long)((((int)(a[1][0])) &((int)(N)))));
a[1][0] = N + 42 +((short)((((int)(N)) %((int)(a[1][0])))))-((long)((((int)(a[1][0])) &((int)(N)))));
;
;


a[1][0] = N + 42 +((short)((((int)(N)) %((int)(a[1][0])))))-((long)((((int)(a[1][0])) &((int)(N)))));
a[1][0] = N + 42 +((short)((((int)(N)) %((int)(a[1][0])))))-((long)((((int)(a[1][0])) &((int)(N)))));
;
;
;
;

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
  if (((int)N[(char *) x] != N + 42 +((int)((((int)(N[(char *) x])) <<((int)(N)))))-((short)((((int)(N[(char *) x])) %((int)(N[(char *) x])))))*((long)((((double)(N)) -((double)(N)))))-((short)((((int)(N[(char *) x])) ^((int)(N[(char *) x])))))-((short)((((int)(N)) &((int)(N[(char *) x])))))*((short)((((int)(N[(char *) x])) <<((int)(N[(char *) x])))))*((short)((((double)(N)) *((double)(N)))))+((int)((((double)(N)) -((double)(N)))))-((short)((((int)(N[(char *) x])) &((int)(N[(char *) x])))))))
    { abort (); }
  exit (0);
}
