/* corpus/pr22061-1.c */
/* { dg-require-effective-target alloca } */
int N = (-(-3));
void foo() {} /* Necessary to trigger the original ICE.  */
void bar (char a[(-(-4))][N]) { 
;

;

a[(-(-3))][(-(-2))] = N + (-43) +((short)((((int)(a[(-(-3))][(-(-2))])) <<((int)(a[(-(-3))][(-(-2))])))))+((short)((((int)(N)) <<((int)(a[(-(-3))][(-(-2))])))))-((long)((((int)(a[(-(-3))][(-(-2))])) %((int)(N)))))-((short)((((int)(N)) |((int)(a[(-(-3))][(-(-2))])))))-((short)((((int)(N)) <<((int)(a[(-(-3))][(-(-2))]))))) + 42 +((short)((((int)(a[(-(-3))][(-(-2))])) ^((int)(a[(-(-3))][(-(-2))])))))+((long)((((int)(N + (-43) +((short)((((int)(a[(-(-3))][(-(-2))])) <<((int)(a[(-(-3))][(-(-2))])))))+((short)((((int)(N)) <<((int)(a[(-(-3))][(-(-2))])))))-((long)((((int)(a[(-(-3))][(-(-2))])) %((int)(N)))))-((short)((((int)(N)) |((int)(a[(-(-3))][(-(-2))])))))-((short)((((int)(N)) <<((int)(a[(-(-3))][(-(-2))]))))))) %((int)(N + (-43) +((short)((((int)(a[(-(-3))][(-(-2))])) <<((int)(a[(-(-3))][(-(-2))])))))+((short)((((int)(N)) <<((int)(a[(-(-3))][(-(-2))])))))-((long)((((int)(a[(-(-3))][(-(-2))])) %((int)(N)))))-((short)((((int)(N)) |((int)(a[(-(-3))][(-(-2))])))))-((short)((((int)(N)) <<((int)(a[(-(-3))][(-(-2))]))))))))))-((long)((((int)(a[(-(-3))][(-(-2))])) &((int)(a[(-(-3))][(-(-2))])))))*((int)((((int)(N + (-43) +((short)((((int)(a[(-(-3))][(-(-2))])) <<((int)(a[(-(-3))][(-(-2))])))))+((short)((((int)(N)) <<((int)(a[(-(-3))][(-(-2))])))))-((long)((((int)(a[(-(-3))][(-(-2))])) %((int)(N)))))-((short)((((int)(N)) |((int)(a[(-(-3))][(-(-2))])))))-((short)((((int)(N)) <<((int)(a[(-(-3))][(-(-2))]))))))) &((int)(a[(-(-3))][(-(-2))])))))-((int)((((int)(N + (-43) +((short)((((int)(a[(-(-3))][(-(-2))])) <<((int)(a[(-(-3))][(-(-2))])))))+((short)((((int)(N)) <<((int)(a[(-(-3))][(-(-2))])))))-((long)((((int)(a[(-(-3))][(-(-2))])) %((int)(N)))))-((short)((((int)(N)) |((int)(a[(-(-3))][(-(-2))])))))-((short)((((int)(N)) <<((int)(a[(-(-3))][(-(-2))]))))))) &((int)(a[(-(-3))][(-(-2))]))))) + 42 +((int)((((int)(a[(-(-3))][(-(-2))])) &((int)(N + (-43) +((short)((((int)(a[(-(-3))][(-(-2))])) <<((int)(a[(-(-3))][(-(-2))])))))+((short)((((int)(N)) <<((int)(a[(-(-3))][(-(-2))])))))-((long)((((int)(a[(-(-3))][(-(-2))])) %((int)(N)))))-((short)((((int)(N)) |((int)(a[(-(-3))][(-(-2))])))))-((short)((((int)(N)) <<((int)(a[(-(-3))][(-(-2))]))))) + 42 +((short)((((int)(a[(-(-3))][(-(-2))])) ^((int)(a[(-(-3))][(-(-2))])))))+((long)((((int)(N + (-43) +((short)((((int)(a[(-(-3))][(-(-2))])) <<((int)(a[(-(-3))][(-(-2))])))))+((short)((((int)(N)) <<((int)(a[(-(-3))][(-(-2))])))))-((long)((((int)(a[(-(-3))][(-(-2))])) %((int)(N)))))-((short)((((int)(N)) |((int)(a[(-(-3))][(-(-2))])))))-((short)((((int)(N)) <<((int)(a[(-(-3))][(-(-2))]))))))) %((int)(N + (-43) +((short)((((int)(a[(-(-3))][(-(-2))])) <<((int)(a[(-(-3))][(-(-2))])))))+((short)((((int)(N)) <<((int)(a[(-(-3))][(-(-2))])))))-((long)((((int)(a[(-(-3))][(-(-2))])) %((int)(N)))))-((short)((((int)(N)) |((int)(a[(-(-3))][(-(-2))])))))-((short)((((int)(N)) <<((int)(a[(-(-3))][(-(-2))]))))))))))-((long)((((int)(a[(-(-3))][(-(-2))])) &((int)(a[(-(-3))][(-(-2))])))))*((int)((((int)(N + (-43) +((short)((((int)(a[(-(-3))][(-(-2))])) <<((int)(a[(-(-3))][(-(-2))])))))+((short)((((int)(N)) <<((int)(a[(-(-3))][(-(-2))])))))-((long)((((int)(a[(-(-3))][(-(-2))])) %((int)(N)))))-((short)((((int)(N)) |((int)(a[(-(-3))][(-(-2))])))))-((short)((((int)(N)) <<((int)(a[(-(-3))][(-(-2))]))))))) &((int)(a[(-(-3))][(-(-2))])))))-((int)((((int)(N + (-43) +((short)((((int)(a[(-(-3))][(-(-2))])) <<((int)(a[(-(-3))][(-(-2))])))))+((short)((((int)(N)) <<((int)(a[(-(-3))][(-(-2))])))))-((long)((((int)(a[(-(-3))][(-(-2))])) %((int)(N)))))-((short)((((int)(N)) |((int)(a[(-(-3))][(-(-2))])))))-((short)((((int)(N)) <<((int)(a[(-(-3))][(-(-2))]))))))) &((int)(a[(-(-3))][(-(-2))]))))))))))+((short)((((int)(a[(-(-3))][(-(-2))])) %((int)(N + (-43) +((short)((((int)(a[(-(-3))][(-(-2))])) <<((int)(a[(-(-3))][(-(-2))])))))+((short)((((int)(N)) <<((int)(a[(-(-3))][(-(-2))])))))-((long)((((int)(a[(-(-3))][(-(-2))])) %((int)(N)))))-((short)((((int)(N)) |((int)(a[(-(-3))][(-(-2))])))))-((short)((((int)(N)) <<((int)(a[(-(-3))][(-(-2))]))))) + 42 +((short)((((int)(a[(-(-3))][(-(-2))])) ^((int)(a[(-(-3))][(-(-2))])))))+((long)((((int)(N + (-43) +((short)((((int)(a[(-(-3))][(-(-2))])) <<((int)(a[(-(-3))][(-(-2))])))))+((short)((((int)(N)) <<((int)(a[(-(-3))][(-(-2))])))))-((long)((((int)(a[(-(-3))][(-(-2))])) %((int)(N)))))-((short)((((int)(N)) |((int)(a[(-(-3))][(-(-2))])))))-((short)((((int)(N)) <<((int)(a[(-(-3))][(-(-2))]))))))) %((int)(N + (-43) +((short)((((int)(a[(-(-3))][(-(-2))])) <<((int)(a[(-(-3))][(-(-2))])))))+((short)((((int)(N)) <<((int)(a[(-(-3))][(-(-2))])))))-((long)((((int)(a[(-(-3))][(-(-2))])) %((int)(N)))))-((short)((((int)(N)) |((int)(a[(-(-3))][(-(-2))])))))-((short)((((int)(N)) <<((int)(a[(-(-3))][(-(-2))]))))))))))-((long)((((int)(a[(-(-3))][(-(-2))])) &((int)(a[(-(-3))][(-(-2))])))))*((int)((((int)(N + (-43) +((short)((((int)(a[(-(-3))][(-(-2))])) <<((int)(a[(-(-3))][(-(-2))])))))+((short)((((int)(N)) <<((int)(a[(-(-3))][(-(-2))])))))-((long)((((int)(a[(-(-3))][(-(-2))])) %((int)(N)))))-((short)((((int)(N)) |((int)(a[(-(-3))][(-(-2))])))))-((short)((((int)(N)) <<((int)(a[(-(-3))][(-(-2))]))))))) &((int)(a[(-(-3))][(-(-2))])))))-((int)((((int)(N + (-43) +((short)((((int)(a[(-(-3))][(-(-2))])) <<((int)(a[(-(-3))][(-(-2))])))))+((short)((((int)(N)) <<((int)(a[(-(-3))][(-(-2))])))))-((long)((((int)(a[(-(-3))][(-(-2))])) %((int)(N)))))-((short)((((int)(N)) |((int)(a[(-(-3))][(-(-2))])))))-((short)((((int)(N)) <<((int)(a[(-(-3))][(-(-2))]))))))) &((int)(a[(-(-3))][(-(-2))]))))))))))+((short)((((int)(N + (-43) +((short)((((int)(a[(-(-3))][(-(-2))])) <<((int)(a[(-(-3))][(-(-2))])))))+((short)((((int)(N)) <<((int)(a[(-(-3))][(-(-2))])))))-((long)((((int)(a[(-(-3))][(-(-2))])) %((int)(N)))))-((short)((((int)(N)) |((int)(a[(-(-3))][(-(-2))])))))-((short)((((int)(N)) <<((int)(a[(-(-3))][(-(-2))]))))) + 42 +((short)((((int)(a[(-(-3))][(-(-2))])) ^((int)(a[(-(-3))][(-(-2))])))))+((long)((((int)(N + (-43) +((short)((((int)(a[(-(-3))][(-(-2))])) <<((int)(a[(-(-3))][(-(-2))])))))+((short)((((int)(N)) <<((int)(a[(-(-3))][(-(-2))])))))-((long)((((int)(a[(-(-3))][(-(-2))])) %((int)(N)))))-((short)((((int)(N)) |((int)(a[(-(-3))][(-(-2))])))))-((short)((((int)(N)) <<((int)(a[(-(-3))][(-(-2))]))))))) %((int)(N + (-43) +((short)((((int)(a[(-(-3))][(-(-2))])) <<((int)(a[(-(-3))][(-(-2))])))))+((short)((((int)(N)) <<((int)(a[(-(-3))][(-(-2))])))))-((long)((((int)(a[(-(-3))][(-(-2))])) %((int)(N)))))-((short)((((int)(N)) |((int)(a[(-(-3))][(-(-2))])))))-((short)((((int)(N)) <<((int)(a[(-(-3))][(-(-2))]))))))))))-((long)((((int)(a[(-(-3))][(-(-2))])) &((int)(a[(-(-3))][(-(-2))])))))*((int)((((int)(N + (-43) +((short)((((int)(a[(-(-3))][(-(-2))])) <<((int)(a[(-(-3))][(-(-2))])))))+((short)((((int)(N)) <<((int)(a[(-(-3))][(-(-2))])))))-((long)((((int)(a[(-(-3))][(-(-2))])) %((int)(N)))))-((short)((((int)(N)) |((int)(a[(-(-3))][(-(-2))])))))-((short)((((int)(N)) <<((int)(a[(-(-3))][(-(-2))]))))))) &((int)(a[(-(-3))][(-(-2))])))))-((int)((((int)(N + (-43) +((short)((((int)(a[(-(-3))][(-(-2))])) <<((int)(a[(-(-3))][(-(-2))])))))+((short)((((int)(N)) <<((int)(a[(-(-3))][(-(-2))])))))-((long)((((int)(a[(-(-3))][(-(-2))])) %((int)(N)))))-((short)((((int)(N)) |((int)(a[(-(-3))][(-(-2))])))))-((short)((((int)(N)) <<((int)(a[(-(-3))][(-(-2))]))))))) &((int)(a[(-(-3))][(-(-2))]))))))) <<((int)(N + (-43) +((short)((((int)(a[(-(-3))][(-(-2))])) <<((int)(a[(-(-3))][(-(-2))])))))+((short)((((int)(N)) <<((int)(a[(-(-3))][(-(-2))])))))-((long)((((int)(a[(-(-3))][(-(-2))])) %((int)(N)))))-((short)((((int)(N)) |((int)(a[(-(-3))][(-(-2))])))))-((short)((((int)(N)) <<((int)(a[(-(-3))][(-(-2))]))))) + 42 +((short)((((int)(a[(-(-3))][(-(-2))])) ^((int)(a[(-(-3))][(-(-2))])))))+((long)((((int)(N + (-43) +((short)((((int)(a[(-(-3))][(-(-2))])) <<((int)(a[(-(-3))][(-(-2))])))))+((short)((((int)(N)) <<((int)(a[(-(-3))][(-(-2))])))))-((long)((((int)(a[(-(-3))][(-(-2))])) %((int)(N)))))-((short)((((int)(N)) |((int)(a[(-(-3))][(-(-2))])))))-((short)((((int)(N)) <<((int)(a[(-(-3))][(-(-2))]))))))) %((int)(N + (-43) +((short)((((int)(a[(-(-3))][(-(-2))])) <<((int)(a[(-(-3))][(-(-2))])))))+((short)((((int)(N)) <<((int)(a[(-(-3))][(-(-2))])))))-((long)((((int)(a[(-(-3))][(-(-2))])) %((int)(N)))))-((short)((((int)(N)) |((int)(a[(-(-3))][(-(-2))])))))-((short)((((int)(N)) <<((int)(a[(-(-3))][(-(-2))]))))))))))-((long)((((int)(a[(-(-3))][(-(-2))])) &((int)(a[(-(-3))][(-(-2))])))))*((int)((((int)(N + (-43) +((short)((((int)(a[(-(-3))][(-(-2))])) <<((int)(a[(-(-3))][(-(-2))])))))+((short)((((int)(N)) <<((int)(a[(-(-3))][(-(-2))])))))-((long)((((int)(a[(-(-3))][(-(-2))])) %((int)(N)))))-((short)((((int)(N)) |((int)(a[(-(-3))][(-(-2))])))))-((short)((((int)(N)) <<((int)(a[(-(-3))][(-(-2))]))))))) &((int)(a[(-(-3))][(-(-2))])))))-((int)((((int)(N + (-43) +((short)((((int)(a[(-(-3))][(-(-2))])) <<((int)(a[(-(-3))][(-(-2))])))))+((short)((((int)(N)) <<((int)(a[(-(-3))][(-(-2))])))))-((long)((((int)(a[(-(-3))][(-(-2))])) %((int)(N)))))-((short)((((int)(N)) |((int)(a[(-(-3))][(-(-2))])))))-((short)((((int)(N)) <<((int)(a[(-(-3))][(-(-2))]))))))) &((int)(a[(-(-3))][(-(-2))]))))))))));
a[(-(-3))][(-(-2))] = N + (-43) +((short)((((int)(a[(-(-3))][(-(-2))])) <<((int)(a[(-(-3))][(-(-2))])))))+((short)((((int)(N)) <<((int)(a[(-(-3))][(-(-2))])))))-((long)((((int)(a[(-(-3))][(-(-2))])) %((int)(N)))))-((short)((((int)(N)) |((int)(a[(-(-3))][(-(-2))])))))-((short)((((int)(N)) <<((int)(a[(-(-3))][(-(-2))]))))) + 42 *((int)((((int)(a[(-(-3))][(-(-2))])) ^((int)(N + (-43) +((short)((((int)(a[(-(-3))][(-(-2))])) <<((int)(a[(-(-3))][(-(-2))])))))+((short)((((int)(N)) <<((int)(a[(-(-3))][(-(-2))])))))-((long)((((int)(a[(-(-3))][(-(-2))])) %((int)(N)))))-((short)((((int)(N)) |((int)(a[(-(-3))][(-(-2))])))))-((short)((((int)(N)) <<((int)(a[(-(-3))][(-(-2))])))))))))) + 42 +((long)((((int)(N + (-43) +((short)((((int)(a[(-(-3))][(-(-2))])) <<((int)(a[(-(-3))][(-(-2))])))))+((short)((((int)(N)) <<((int)(a[(-(-3))][(-(-2))])))))-((long)((((int)(a[(-(-3))][(-(-2))])) %((int)(N)))))-((short)((((int)(N)) |((int)(a[(-(-3))][(-(-2))])))))-((short)((((int)(N)) <<((int)(a[(-(-3))][(-(-2))]))))) + 42 *((int)((((int)(a[(-(-3))][(-(-2))])) ^((int)(N + (-43) +((short)((((int)(a[(-(-3))][(-(-2))])) <<((int)(a[(-(-3))][(-(-2))])))))+((short)((((int)(N)) <<((int)(a[(-(-3))][(-(-2))])))))-((long)((((int)(a[(-(-3))][(-(-2))])) %((int)(N)))))-((short)((((int)(N)) |((int)(a[(-(-3))][(-(-2))])))))-((short)((((int)(N)) <<((int)(a[(-(-3))][(-(-2))])))))))))))) |((int)(a[(-(-3))][(-(-2))])))));
;
;
; }
int
main (void)
{
  void *x;

  ;
  ;
  memset (x, (-(-2)), (-(-4)) * N);
  bar (x);
  if (((int)((int)((int)N[(char *) x] != N + (-43) -((short)((((int)(N[(char *) x])) ^((int)(N[(char *) x])))))+((long)((((int)(N)) >>((int)(N)))))+((short)((((int)(N)) ^((int)(N)))))) + 42 *((int)((((int)(N + (-43) -((short)((((int)(N[(char *) x])) ^((int)(N[(char *) x]))))))) <<((int)(N + (-43) -((short)((((int)(N[(char *) x])) ^((int)(N[(char *) x])))))+((long)((((int)(N)) >>((int)(N)))))+((short)((((int)(N)) ^((int)(N))))))))))-((short)((((int)(((long)((((int)(N)) >>((int)(N))))))) >>((int)(N + (-43) -((short)((((int)(N[(char *) x])) ^((int)(N[(char *) x])))))+((long)((((int)(N)) >>((int)(N))))))))))*((int)((((int)(N + (-43) -((short)((((int)(N[(char *) x])) ^((int)(N[(char *) x])))))+((long)((((int)(N)) >>((int)(N))))))) <<((int)(((short)((((int)(N)) ^((int)(N))))))))))-((short)((((int)(((short)((((int)(N)) ^((int)(N))))))) |((int)(((short)((((int)(N)) ^((int)(N))))))))))*((long)((((int)(((short)((((int)(N)) ^((int)(N))))))) &((int)(((long)((((int)(N)) >>((int)(N))))))))))*((int)((((int)(N + (-43) -((short)((((int)(N[(char *) x])) ^((int)(N[(char *) x])))))+((long)((((int)(N)) >>((int)(N)))))+((short)((((int)(N)) ^((int)(N))))))) &((int)(((short)((((int)(N)) ^((int)(N))))))))))*((int)((((int)((int)N[(char *) x])) &((int)((int)N[(char *) x])))))*((short)((((int)(((long)((((int)(N)) >>((int)(N))))))) |((int)(N + (-43) -((short)((((int)(N[(char *) x])) ^((int)(N[(char *) x])))))+((long)((((int)(N)) >>((int)(N))))))))))-((long)((((int)(((long)((((int)(N)) >>((int)(N))))))) <<((int)(N + (-43) -((short)((((int)(N[(char *) x])) ^((int)(N[(char *) x]))))))))))+((short)((((int)(N + (-43) -((short)((((int)(N[(char *) x])) ^((int)(N[(char *) x])))))+((long)((((int)(N)) >>((int)(N)))))+((short)((((int)(N)) ^((int)(N))))))) <<((int)((int)N[(char *) x])))))) + 42 +((int)((((int)((int)((int)N[(char *) x] != N + (-43) -((short)((((int)(N[(char *) x])) ^((int)(N[(char *) x])))))+((long)((((int)(N)) >>((int)(N)))))+((short)((((int)(N)) ^((int)(N)))))) + 42 *((int)((((int)(N + (-43) -((short)((((int)(N[(char *) x])) ^((int)(N[(char *) x]))))))) <<((int)(N + (-43) -((short)((((int)(N[(char *) x])) ^((int)(N[(char *) x])))))+((long)((((int)(N)) >>((int)(N)))))+((short)((((int)(N)) ^((int)(N))))))))))-((short)((((int)(((long)((((int)(N)) >>((int)(N))))))) >>((int)(N + (-43) -((short)((((int)(N[(char *) x])) ^((int)(N[(char *) x])))))+((long)((((int)(N)) >>((int)(N))))))))))*((int)((((int)(N + (-43) -((short)((((int)(N[(char *) x])) ^((int)(N[(char *) x])))))+((long)((((int)(N)) >>((int)(N))))))) <<((int)(((short)((((int)(N)) ^((int)(N))))))))))-((short)((((int)(((short)((((int)(N)) ^((int)(N))))))) |((int)(((short)((((int)(N)) ^((int)(N))))))))))*((long)((((int)(((short)((((int)(N)) ^((int)(N))))))) &((int)(((long)((((int)(N)) >>((int)(N))))))))))*((int)((((int)(N + (-43) -((short)((((int)(N[(char *) x])) ^((int)(N[(char *) x])))))+((long)((((int)(N)) >>((int)(N)))))+((short)((((int)(N)) ^((int)(N))))))) &((int)(((short)((((int)(N)) ^((int)(N))))))))))*((int)((((int)((int)N[(char *) x])) &((int)((int)N[(char *) x])))))*((short)((((int)(((long)((((int)(N)) >>((int)(N))))))) |((int)(N + (-43) -((short)((((int)(N[(char *) x])) ^((int)(N[(char *) x])))))+((long)((((int)(N)) >>((int)(N)))))))))))) &((int)(((int)((((int)(N + (-43) -((short)((((int)(N[(char *) x])) ^((int)(N[(char *) x])))))+((long)((((int)(N)) >>((int)(N)))))+((short)((((int)(N)) ^((int)(N))))))) &((int)(((short)((((int)(N)) ^((int)(N)))))))))))))))))
    { abort (); }
  exit ((-(-2)));
}
