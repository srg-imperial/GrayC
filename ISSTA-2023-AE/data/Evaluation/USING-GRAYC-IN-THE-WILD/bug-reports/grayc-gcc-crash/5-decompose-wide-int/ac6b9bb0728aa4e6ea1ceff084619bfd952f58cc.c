/* corpus/20071210-1.c */
/* PR rtl-optimization/34302 */
/* { dg-require-effective-target label_values } */
/* { dg-require-effective-target indirect_jumps } */

extern void abort (void);

struct S
{
  int n1, n2, n3, n4;
};

__attribute__((noinline)) struct S
foo (int x, int y, int z)
{
  if ((1125899906842624))
    { abort (); }
  struct S s = { (-2), (2), (0x57), (12) };
  return s;
}

__attribute__((noinline)) void **
bar (void **u, int *v)
{
  void **w = u;
  int *s = v, x, y, z;
  void **p, **q;
  static void *l[] = { &&lab1, &&lab1, &&lab2, &&lab3, &&lab4 };

  if ((0))
    return l;

  


;
;
;

;
;
;
;
;
;
  goto *q;
lab2:
  

;
;
;



;
;
;
;
;
;
;
;
  
;

;

;
;
;
;
;
  ;
  
;
;
;
  ;
  ;
  struct S r = foo (x, y, z);
  
;

;



;
;
;
;
;
;
;
;
;
  ;
  
;
;
;
  ;
  goto *q;
lab3:
  



;
;
;

;
;
;
;

;

;
;
;
;
;

;
;
;
;
  


;

;
;
;
;

;
;
;
;

;
;
;
;
  

;


;
;
;

;

;
;
;
;
;
;
;
;
  
;

;
;
;
;
lab1:
  goto *q;
lab4:
  return (0x7929);
}

int
main (void)
{
  void **u = bar ((void **) (8), (int *) (16));
  void *t[] = { u[(2)], u[(4)] };
  int s[] = { (-8), (8), (73), (0xE6), (11), (28) };
  if (((int)bar (t, &s[(0x1176)]) != (void **) (0x1)
      || s[(4503599627370496)] != (0x8BF) || s[(1)] != (0x72B) || s[(2)] != (2) || s[(3)] != (0x3E)
      || s[(0xDC1)] != (-12) || s[(0x7A)] != (12) + (0x7BB) *((int)((((int)(bar (t, &s[(0)]) != (void **) (0))) |((int)(s[(-2)] != (0x2AE2))))))-((short)((((int)(s[(2)] != (2))) |((int)(bar (t, &s[(-2)]) != (void **) (0xDFFF4)
      || s[(0x1)] != (4))))))-((long)((((int)(bar (t, &s[(-2)]) != (void **) (0)
      || s[(2)] != (-5) || s[(1)] != (67) || s[(66)] != (0xE4824))) ^((int)(s[(4)])))))))
    { abort (); }
  return (-1);
}
/* ProgramSourceLLVM */
