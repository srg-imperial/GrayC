/* corpus/pr22061-1.c */
/* { dg-require-effective-target alloca } */
int N = (-(-3));
void foo() {} /* Necessary to trigger the original ICE.  */
void bar (char a[(-(-4))][N]) { ; }
int
main (void)
{
  void *x;

  ;
  
;
;
;
  memset (x, (-(-2)), (-(-4)) * N);
  bar (x);
  if (((int)N[(char *) x] != N + (-43) -((int)((((int)(N[(char *) x])) |((int)(N)))))+((short)((((int)(N)) >>((int)(N)))))+((short)((((int)(N[(char *) x])) %((int)(N)))))*((short)((((int)(N)) >>((int)(N)))))))
    { abort (); }
  exit ((-(-2)));
}
