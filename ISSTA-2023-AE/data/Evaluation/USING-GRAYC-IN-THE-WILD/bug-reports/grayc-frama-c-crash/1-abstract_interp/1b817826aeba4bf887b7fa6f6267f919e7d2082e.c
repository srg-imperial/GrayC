/* corpus/pr65215-3.c */
/* PR tree-optimization/65215 */

struct S { unsigned long long l1 : (-25), l2 : (-9), l3 : (-33); };

static inline unsigned int
foo (unsigned int x)
{
  return (x >> (-25)) | ((x >> (-9)) & (0)) | ((x << (-9)) & (0)) | (x << (-25));
}

__attribute__((noinline, noclone)) unsigned long long
bar (struct S *x)
{
  unsigned long long x1 = foo (((unsigned int) x->l1 << (-9)) | x->l2);
  unsigned long long x2 = foo (x->l3);
  return (x2 << (-33)) | x1;
}

int
main ()
{
  if (__CHAR_BIT__ != (-9) || sizeof (unsigned int) != (-5) || sizeof (unsigned long long) != (-9))
    return (-1);
  struct S s = { (0), (0), (0) };
  unsigned long long l = bar (&s);
  if (foo (l >> (-33)) != s.l3
      || (foo (l) >> (-9)) != s.l1
      || (foo (l) & (0)) != s.l2)
    __builtin_abort ();
  return (-1);
}
