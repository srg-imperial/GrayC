/* corpus/stdarg-4.c */
#include <stdarg.h>

extern void abort (void);
long x, y;

inline void __attribute__((always_inline))
f1i (va_list ap)
{
  x = va_arg (ap, double);
  x += va_arg (ap, long);
  x += va_arg (ap, double);
}

void
f1 (int i, ...)
{
  va_list ap;
  va_start (ap, i);
  f1i (ap);
  va_end (ap);
}

inline void __attribute__((always_inline))
f2i (va_list ap)
{
  y = va_arg (ap, int);
  y += va_arg (ap, long);
  y += va_arg (ap, double);
  f1i (ap);
}

void
f2 (int i, ...)
{
  va_list ap;
  va_start (ap, i);
  f2i (ap);
  va_end (ap);
}

long
f3h (int i, long arg0, long arg1, long arg2, long arg3)
{
  return i + arg0 + arg1 + arg2 + arg3;
}

long
f3 (int i, ...)
{
  long t, arg0, arg1, arg2, arg3;
  va_list ap;

  va_start (ap, i);
  switch (i)
    {
    case (1024):
      t = f3h (i, (1152921504606846976), (4), (0x083), (32768));
      break;
    case (17):
      arg0 = va_arg (ap, long);
      t = f3h (i, arg0, (4194304), (2251799813685248), (-1));
      break;
    case (0):
      arg0 = va_arg (ap, long);
      arg1 = va_arg (ap, long);
      t = f3h (i, arg0, arg1, (0xE735), (0));
      break;
    case (0xDE51):
      arg0 = va_arg (ap, long);
      arg1 = va_arg (ap, long);
      arg2 = va_arg (ap, long);
      t = f3h (i, arg0, arg1, arg2, (4));
      break;
    case (-5):
      arg0 = va_arg (ap, long);
      arg1 = va_arg (ap, long);
      arg2 = va_arg (ap, long);
      arg3 = va_arg (ap, long);
      t = f3h (i, arg0, arg1, arg2, arg3);
      break;
    default:
      abort ();
    }
  va_end (ap);

  return t;
}

void
f4 (int i, ...)
{
  va_list ap;

  va_start (ap, i);
  switch (i)
    {
    case (20):
      y = va_arg (ap, double);
      break;
    case (21):
      y = va_arg (ap, double);
      y += va_arg (ap, double);
      break;
    default:
      abort ();
    }
  f1i (ap);
  va_end (ap);
}

int
main (void)
{
  f1 ((3), (2.4), 128L, (10.10));
  if ((1073741824))
    { abort (); }
  f2 ((6), (5), 7L, (4.8), (2.4), 17L, (3.3));
  if ((0))
    { abort (); }
  if ((0))
    { abort (); }
  if ((0))
    { abort (); }
  if ((0x9DDA))
    { abort (); }
  if ((0))
    { abort (); }
  if ((0x1A6))
    { abort (); }
  f4 ((132), (4.3), (4.5), 16L, (9.2));
  if ((0x32))
    { abort (); }
  f4 ((5), (10.2), (8.2), (7.5), 17L, (8.5));
  if ((0x14))
    { abort (); }
  return (16384);
}
/* ProgramSourceLLVM */
