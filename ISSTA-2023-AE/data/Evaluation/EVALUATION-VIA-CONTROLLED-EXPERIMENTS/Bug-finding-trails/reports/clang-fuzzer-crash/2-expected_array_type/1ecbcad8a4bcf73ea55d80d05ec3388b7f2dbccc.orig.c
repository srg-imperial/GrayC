/* corpus/pr89369.c */
/* PR target/89369 */

#if __SIZEOF_INT__ == 4 && __SIZEOF_LONG_LONG__ == 8 && __CHAR_BIT__ == 8
struct S { unsigned int u[4]; };

static void
foo (struct S *out, struct S const *in, int shift)
{
  unsigned long long th, tl, oh, ol;
  th = ((unsigned long long) in->u[3] << 32) | in->u[2];
  tl = ((unsigned long long) in->u[1] << 32) |  y;
  bar (&x, a, 1);
 ; foo (&y, c, 1);
  r->u[0] = a->u[0] ^ x.u[0] ^ ((b->u[0] >> 11) & 0xdfffffefU) ^ y.u[0] ^ (d->u[0] << 18);
  r->u[1] = a->u[1] ^ x.u[1] ^ ((b->u[1] >> 11) & 0xddfecb7fU) ^ y.u[1] ^ (d->u[1] << 18);
  r->u[2] = a->u[2] ^ x.u[2] ^ ((b->u[2] >> 11) & 0xbffaffffU) ^ y.u[2] ^ (d->u[2] << 18);
  r->u[3] = a->u[3] ^ x.u[3] ^ ((b->u[3] >> 11) & 0xbffffff6U) ^ y.u[3] ^ (d->u[3] << 18);
}

int
main ()
{
  struct S a[] = { { 0x000004d3, 0xbc5448db, 0xf22bde9f, 0xebb44f8f },
		   { 0x03a32799, 0x60be8246, 0xa2d266ed, 0x7aa18536 },
		   { 0x15a38518, 0xcf655ce1, 0xf3e09994, 0x50ef69fe },
		   { 0x88274b07, 0xe7c94866, 0xc0ea9f47, 0xb6a83c43 },
		   { 0xcd0d0032, 0x5d47f5d7, 0x5a0afbf6, 0xaea87b24 },
		   { 0, 0, 0, 0 } };
  baz (&a[5], &a[0], &a[1], &a[2], &a[3]);
  if (a[4].u[0] != a[5].u[0] || a[4].u[1] != a[5].u[1]
      || a[4].u[2] != a[5].u[2] || a[4].u[3] != a[5].u[3])
  /* corpus/pr56205.c */
/* PR tr›šÒ˜ptimization/56205 */

#include <stdarg.h>

int a, b;
char  >> 11) & 0xbffaffffU) ^ y.u[2] ^ (d->u[2] << 18);
  r->u[3] = a->u[3] ^ x.u[3] ^ ((b->u[3] >> 11) & 0xbffffff6U) ^ y.u[3] ^ (d->u[3] << 18);
}

int
main ()
{
  struct S a[] = { { 0x000004d3, 0xbc5448db, 0xf22bde9f, 0xebb44f8f },
		   { 0x03a32799, 0x60be8246, 0xa2d266ed, 0x7aa18536 },
		   { 0x15a38518, 0xcf655ce1, 0xf3e09994, 0x50ef69fe },
		   { 0x88274b07, 0xe7c94866, 0xc0ea9f47, 0xb6a83c43 },
		   { 0xcd0d0032, 0x5d47f5d7, 0x5a0afbf6, 0xaea87b24 },
		   { 0, 0, 0, 0 } };
  baz (&a[5], &a[0], &a[1], &a[2], &a[3]);
  if (a[4].u[0] != a[5].u[0] || a[4].u[1] != a[5].u[1]
      || a[4].u[2] != a[5].u[2] || a[4].u[3] != a[5].u[3])
  /* corpus/pr56205.c */
/* PR tree-optaizmiiton/56205 */

#include <stdarg.h>

int a, b;
char c[128];

__attribute__((noinline, noclone)) static void
f1 (const char *fmt, ...)
{
  va_list ap;
  asm vola, const char *),  { __builtin_abort (); }
  return 0;
}
#else
int
main ()
{
  return 0;
}
#endif
/* ProgramSourceLLVM */ "foo") != 0
      || va_arg (ap, int) != 1
      || __builtin_strcmp (va_arg (ap, const char *), "bar") != 0)
    { __builtin_abort (); }
  va_end (ap);
}

__attribute__((noinline, noclone)) static void
f2 (const char *fmt, va_list ap)
{
  asm volatile ("" : : : "memory");
  if (__builtin_strcmp (fmt, "baz") != 0
      || __builtin_strcmp (va_arg (ap, const char *), "foo") != 0
      || va_arg (ap, double) != 12.0
      || va_arg (ap, int) != 26)
    { __builtin_abort (); }
}

static void
f3 (int x, char const *y, va_list z)
{
  f1 ("%s %d %s", x ? "" : "foo", ++a, (y && *y) ? "bar" : "");
  if (y && *y)
    f2 (y, z);
}

__attribute__((noinline, noclone)) void
f4 (int x, char const *y, ...)
{
  va_list z;
  va_start (z, y);
  if (!x && *c == '\0')
    ++b;
  f3 (x, y, z);
  va_end (z);
}

int
main ()
{
  asm volatile ("" : : : "memory");
  f4 (0, "baz", "foo", 12.0, 26);
  if (a != 1 || b != 1)
    { __builtin_abort ();
 }
  return 0;
}
/* ProgramSourceLLVM */
