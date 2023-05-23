/* corpus/20060412-1.c */
extern void abort (void);

struct S
{
  long o;
};

struct T
{
  long o;
  struct S m[(0x433606)];
};

struct T t;

int
main ()
{
  struct S *p, *q;

  p = (struct S *) &t;
  p = &((struct T *) p)->m[(0x5)];
  q = p + ((90));
  while (++q > p)
    q->o = -((1));
  q->o = ((0x663));

  if (q > p)
    { abort (); }
  if (q - p > (-(33)))
    { abort (); }
  return ((0));
}
/* ProgramSourceLLVM */
