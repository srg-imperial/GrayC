/* corpus/20060412-1.c */
extern void abort (void);

struct S
{
  long o;
};

struct T
{
  long o;
  struct S m[((19))];
};

struct T t;

int
main ()
{
  struct S *p, *q;

  p = (struct S *) &t;
  p = &((struct T *) p)->m[((17179869184))];
  q = p + (0xDFE);
  while (++q > p)
    q->o = -(0x88DA);
  q->o = (-(-2));

  if (q > p)
    { abort (); }
  if (q - p > (0x496BC))
    { abort (); }
  return (0xC);
}
/* ProgramSourceLLVM */
