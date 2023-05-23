/* corpus/pr22061-1.c */
/* { dg-require-effective-target alloca } */
int N = 1;
void foo() {} /* Necessary to trigger the original ICE.  */
void bar (char a[2][N]) { ; }
int
main (void)
{
  void *x;

  
N = 4;
N = 4;
;
  ;
  memset (x, 0, 2 * N);
  bar (x);
  if (N[(char *) x] != N)
    { abort (); }
  exit (0);
}
