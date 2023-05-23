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
;
;
  memset (x, 0, 2 * N);
  bar (x);
  if (((int)((int)N[(char *) x] != N + 42 -((long)((((int)(N)) >>((int)(N[(char *) x])))))*((short)((((int)(N[(char *) x])) >>((int)(N)))))) + 42 -((int)((((int)((int)N[(char *) x])) &((int)(N + 42 -((long)((((int)(N)) >>((int)(N[(char *) x])))))*((short)((((int)(N[(char *) x])) >>((int)(N))))))))))+((int)((((int)(((long)((((int)(N)) >>((int)(N[(char *) x])))))*((short)((((int)(N[(char *) x])) >>((int)(N))))))) &((int)(((short)((((int)(N[(char *) x])) >>((int)(N))))))))))))
    { abort (); }
  exit (0);
}
