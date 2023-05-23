/* corpus/pr22061-1.c */
/* { dg-require-effective-target alloca } */
int N = 1;
void foo() {} /* Necessary to trigger the original ICE.  */
void bar (char a[2][N]) { 
;
;
; }
int
main (void)
{
  void *x;

  
;

N = 4 + 42 -((long)((((double)(4)) +((double)(4)))))-((long)((((double)(4)) +((double)(4)))))-((int)((((double)(4)) +((double)(N)))))+((long)((((int)(4)) &((int)(N)))))+((int)((((int)(N)) ^((int)(4))))) + 42 *((short)((((int)(4 + 42 -((long)((((double)(4)) +((double)(4)))))-((long)((((double)(4)) +((double)(4)))))-((int)((((double)(4)) +((double)(N)))))+((long)((((int)(4)) &((int)(N)))))+((int)((((int)(N)) ^((int)(4))))))) %((int)(N)))))+((short)((((double)(4 + 42 -((long)((((double)(4)) +((double)(4)))))-((long)((((double)(4)) +((double)(4)))))-((int)((((double)(4)) +((double)(N)))))+((long)((((int)(4)) &((int)(N)))))+((int)((((int)(N)) ^((int)(4))))))) +((double)(N)))))-((long)((((int)(4 + 42 -((long)((((double)(4)) +((double)(4)))))-((long)((((double)(4)) +((double)(4)))))-((int)((((double)(4)) +((double)(N)))))+((long)((((int)(4)) &((int)(N)))))+((int)((((int)(N)) ^((int)(4))))))) &((int)(4 + 42 -((long)((((double)(4)) +((double)(4)))))-((long)((((double)(4)) +((double)(4)))))-((int)((((double)(4)) +((double)(N)))))+((long)((((int)(4)) &((int)(N)))))+((int)((((int)(N)) ^((int)(4))))))))));
N = 4 + 42 -((long)((((double)(4)) +((double)(4)))))-((long)((((double)(4)) +((double)(4)))))-((int)((((double)(4)) +((double)(N)))))+((long)((((int)(4)) &((int)(N)))))+((int)((((int)(N)) ^((int)(4))))) + 42 *((short)((((int)(4 + 42 -((long)((((double)(4)) +((double)(4)))))-((long)((((double)(4)) +((double)(4)))))-((int)((((double)(4)) +((double)(N)))))+((long)((((int)(4)) &((int)(N)))))+((int)((((int)(N)) ^((int)(4))))))) %((int)(N)))))+((short)((((double)(4 + 42 -((long)((((double)(4)) +((double)(4)))))-((long)((((double)(4)) +((double)(4)))))-((int)((((double)(4)) +((double)(N)))))+((long)((((int)(4)) &((int)(N)))))+((int)((((int)(N)) ^((int)(4))))))) +((double)(N)))))-((long)((((int)(4 + 42 -((long)((((double)(4)) +((double)(4)))))-((long)((((double)(4)) +((double)(4)))))-((int)((((double)(4)) +((double)(N)))))+((long)((((int)(4)) &((int)(N)))))+((int)((((int)(N)) ^((int)(4))))))) &((int)(4 + 42 -((long)((((double)(4)) +((double)(4)))))-((long)((((double)(4)) +((double)(4)))))-((int)((((double)(4)) +((double)(N)))))+((long)((((int)(4)) &((int)(N)))))+((int)((((int)(N)) ^((int)(4))))))))));
;
;
  ;
  memset (x, 0, 2 * N);
  bar (x);
  if (((int)((int)N[(char *) x] != N + 42 +((int)((((int)(N[(char *) x])) <<((int)(N)))))-((short)((((int)(N[(char *) x])) %((int)(N[(char *) x])))))*((long)((((double)(N)) -((double)(N)))))-((short)((((int)(N[(char *) x])) ^((int)(N[(char *) x])))))-((short)((((int)(N)) &((int)(N[(char *) x])))))*((short)((((int)(N[(char *) x])) <<((int)(N[(char *) x])))))*((short)((((double)(N)) *((double)(N)))))+((int)((((double)(N)) -((double)(N)))))-((short)((((int)(N[(char *) x])) &((int)(N[(char *) x])))))) + 42 -((short)((((int)(N + 42 +((int)((((int)(N[(char *) x])) <<((int)(N)))))-((short)((((int)(N[(char *) x])) %((int)(N[(char *) x])))))*((long)((((double)(N)) -((double)(N)))))-((short)((((int)(N[(char *) x])) ^((int)(N[(char *) x]))))))) %((int)(((long)((((double)(N)) -((double)(N))))))))))*((short)((((int)(((short)((((int)(N[(char *) x])) ^((int)(N[(char *) x]))))))) &((int)((int)N[(char *) x])))))*((int)((((int)(N + 42 +((int)((((int)(N[(char *) x])) <<((int)(N))))))) |((int)(((short)((((int)(N[(char *) x])) ^((int)(N[(char *) x]))))))))))*((long)((((int)(((long)((((double)(N)) -((double)(N))))))) ^((int)(N + 42 +((int)((((int)(N[(char *) x])) <<((int)(N))))))))))))
    { abort (); }
  exit (0);
}
