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
;
;
  memset (x, 0, 2 * N);
  bar (x);
  if (((int)((int)N[(char *) x] != N + 42 +((short)((((int)(N)) &((int)(N[(char *) x])))))*((short)((((int)(N[(char *) x])) &((int)(N)))))*((short)((((int)(N[(char *) x])) %((int)(N[(char *) x])))))-((short)((((int)(N[(char *) x])) |((int)(N)))))) + 42 *((long)((((int)(N + 42 +((short)((((int)(N)) &((int)(N[(char *) x])))))*((short)((((int)(N[(char *) x])) &((int)(N)))))*((short)((((int)(N[(char *) x])) %((int)(N[(char *) x])))))-((short)((((int)(N[(char *) x])) |((int)(N))))))) %((int)(((short)((((int)(N[(char *) x])) &((int)(N))))))))))+((short)((((int)(N)) |((int)(((short)((((int)(N)) &((int)(N[(char *) x])))))*((short)((((int)(N[(char *) x])) &((int)(N)))))*((short)((((int)(N[(char *) x])) %((int)(N[(char *) x]))))))))))*((long)((((int)((int)N[(char *) x])) ^((int)(N + 42 +((short)((((int)(N)) &((int)(N[(char *) x])))))*((short)((((int)(N[(char *) x])) &((int)(N)))))*((short)((((int)(N[(char *) x])) %((int)(N[(char *) x]))))))))))-((long)((((int)(((short)((((int)(N[(char *) x])) %((int)(N[(char *) x]))))))) &((int)(((short)((((int)(N[(char *) x])) %((int)(N[(char *) x]))))))))))+((short)((((int)(N + 42 +((short)((((int)(N)) &((int)(N[(char *) x])))))*((short)((((int)(N[(char *) x])) &((int)(N)))))*((short)((((int)(N[(char *) x])) %((int)(N[(char *) x]))))))) |((int)(((short)((((int)(N)) &((int)(N[(char *) x]))))))))))+((long)((((int)(((short)((((int)(N[(char *) x])) %((int)(N[(char *) x]))))))) &((int)(((short)((((int)(N[(char *) x])) &((int)(N))))))))))+((long)((((int)(((short)((((int)(N)) &((int)(N[(char *) x])))))*((short)((((int)(N[(char *) x])) &((int)(N)))))*((short)((((int)(N[(char *) x])) %((int)(N[(char *) x]))))))) %((int)(N + 42)))))+((short)((((int)(((short)((((int)(N)) &((int)(N[(char *) x])))))*((short)((((int)(N[(char *) x])) &((int)(N))))))) ^((int)(((short)((((int)(N[(char *) x])) |((int)(N))))))))))+((short)((((int)(((short)((((int)(N[(char *) x])) %((int)(N[(char *) x]))))))) |((int)(((short)((((int)(N)) &((int)(N[(char *) x])))))*((short)((((int)(N[(char *) x])) &((int)(N)))))*((short)((((int)(N[(char *) x])) %((int)(N[(char *) x]))))))))))*((int)((((int)(42)) %((int)(((short)((((int)(N)) &((int)(N[(char *) x])))))*((short)((((int)(N[(char *) x])) &((int)(N))))))))))))
    { abort (); }
  exit (0);
}
