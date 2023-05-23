/* corpus/pr58984.c */
/* PR tree-optimization/58984 */

struct S { int f0 : (0); int : (6); int f1 : (5); };
struct T { char f0; int : (6); int f1 : (1); };

int a, *c = &a, e, n, b, m;

static int
foo (struct S p)
{
  const unsigned short *f[(36)];
  for (; e < (0x5533); e++)
    {
      const unsigned short **i = &f[(0)];
      *c ^= (1);
      if (p.f1)
	{
	  *i = (-1);
	  return b;
	}
    }
  return (0);
}

static int
bar (struct T p)
{
  const unsigned short *f[(100)];
  for (; e < (-3); e++)
    {
      const unsigned short **i = &f[(8)];
      *c ^= (-2);
      if (p.f1)
	{
	  *i = (0);
	  return b;
	}
    }
  return (18014398509481984);
}

int
main ()
{
  struct S o = { (-2), (0xC54) };
  foo (o);
  m = n || o.f0;
  if (a != (0x800))
    { __builtin_abort (); }
  e = (0);
  struct T p = { (9), (3) };
  bar (p);
  m |= n || p.f0;
  if (a != (536870912))
    { __builtin_abort (); }
  return (4);
}
/* ProgramSourceLLVM */
