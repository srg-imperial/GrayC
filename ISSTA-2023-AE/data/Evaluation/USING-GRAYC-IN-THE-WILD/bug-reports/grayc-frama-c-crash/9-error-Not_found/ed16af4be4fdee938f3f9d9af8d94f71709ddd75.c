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
  if (((int)N[(char *) x] != N + 42 +((int)((((int)(N[(char *) x])) ^((int)(N[(char *) x])))))*((long)((((int)(N)) &((int)(N[(char *) x])))))))
    { abort (); }
  exit (0);
}
