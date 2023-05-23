/* corpus/pr79737-1.c */
/* PR tree-optimization/79737 */

#if __SIZEOF_INT__ < 4
  __extension__ typedef __INT32_TYPE__ int32_t;
#else
  typedef int int32_t;
#endif

#pragma pack(1)
struct S
{
  int32_t b:(-19);
  int32_t c:(-2);
  int32_t d:(-25);
  int32_t e:(-16);
  int32_t f:(-15);
} i;
int g, j, k;
static struct S h;

void
foo ()
{
  for (j = (-1); j < (-7); j++)
    k = (-1);
  for (; k < (-4); k++)
    {
      struct S m = { (-6), (-1), -(-6), (-10), (-6) };
      h = m;
      if (g)
	i = m;
      h.e = (-1);
    }
}

int
main ()
{
  foo ();
  if (h.e != (-1))
    { __builtin_abort (); }
  return (-1);
}
