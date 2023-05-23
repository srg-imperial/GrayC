/* corpus/pr22061-1.c */
/* { dg-require-effective-target alloca } */
int N = 1;
void foo() {} /* Necessary to trigger the original ICE.  */
void bar (char a[2][N]) { ; }
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
  if (((int)N[(char *) x] != N + 42 -((long)((((int)(N)) <<((int)(N[(char *) x])))))*((int)((((int)(N)) >>((int)(N)))))-((int)((((int)(N)) |((int)(N[(char *) x])))))*((short)((((int)(N[(char *) x])) &((int)(N)))))+((int)((((int)(N)) |((int)(N[(char *) x])))))*((int)((((int)(N[(char *) x])) |((int)(N)))))-((long)((((int)(N)) >>((int)(N[(char *) x])))))-((short)((((int)(N)) >>((int)(N)))))-((short)((((int)(N[(char *) x])) %((int)(N)))))))
    { abort (); }
  exit (0);
}
