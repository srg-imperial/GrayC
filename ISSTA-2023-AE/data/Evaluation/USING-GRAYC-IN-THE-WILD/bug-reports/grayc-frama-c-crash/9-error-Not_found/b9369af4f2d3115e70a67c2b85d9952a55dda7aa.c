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
  if (0)
    { abort (); }
  exit (0);
}
