/* corpus/pr22061-1.c */
/* { dg-require-effective-target alloca } */
int N = 1;
void foo() {} /* Necessary to trigger the original ICE.  */
void bar (char a[2][N]) { 

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
  if (((int)((int)N[(char *) x] != N + 42 *((short)((((int)(N)) >>((int)(N)))))) + 42 +((long)((((double)(N)) +((double)(42)))))+((int)((((int)((int)N[(char *) x])) |((int)(42 *((short)((((int)(N)) >>((int)(N))))))))))-((short)((((int)(42 *((short)((((int)(N)) >>((int)(N))))))) &((int)(42)))))-((long)((((int)(42 *((short)((((int)(N)) >>((int)(N))))))) &((int)(((short)((((int)(N)) >>((int)(N))))))))))*((long)((((int)(((short)((((int)(N)) >>((int)(N))))))) |((int)(N + 42 *((short)((((int)(N)) >>((int)(N))))))))))-((short)((((int)(N + 42 *((short)((((int)(N)) >>((int)(N))))))) >>((int)(42)))))))
    { abort (); }
  exit (0);
}
