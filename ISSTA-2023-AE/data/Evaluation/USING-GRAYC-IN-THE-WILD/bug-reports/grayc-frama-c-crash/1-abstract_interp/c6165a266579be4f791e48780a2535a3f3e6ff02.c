/* corpus/pr79737-2.c */
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
} i, j;

void
foo ()
{
  i.e = (-1);
  i.b = (-6);
  i.c = (-1);
  i.d = -(-6);
  i.f = (-6);
}

void
bar ()
{
  j.b = (-6);
  j.c = (-1);
  j.d = -(-6);
  j.e = (-1);
  j.f = (-6);
}

int
main ()
{
  foo ();
  bar ();
  asm volatile ("" : : : "memory");
  if (i.b != j.b || i.c != j.c || i.d != j.d || i.e != j.e || i.f != j.f)
    { __builtin_abort (); }
}
