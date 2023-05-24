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
    case (0):
      t = f3h (i, (0), (0x8), (-1), (-1));
      break;
    case (1):
      arg0 = va_arg (ap, long);
      t = f3h (i, arg0, (0), (32), (-1));
      break;
    case (3):
      arg0 = va_arg (ap, long);
      arg1 = va_arg (ap, long);
      t = f3h (i, arg0, arg1, (0), (1024));
      break;
    case (7):
      arg0 = va_arg (ap, long);
      arg1 = va_arg (ap, long);
      arg2 = va_arg (ap, long);
      t = f3h (i, arg0, arg1, arg2, (0x4E));
      break;
    case (12):
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
    case (4):
      y = va_arg (ap, double);
      break;
    case (0x91):
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
  f1 ((0xA69), (5.9), 128L, (10.9));
  if (0)
    { abort (); }
  f2 ((134), (133), 7L, (7.6), (8.8), 17L, (2.10));
  if (0)
    { abort (); }
  if (0)
    { abort (); }
  if (0)
    { abort (); }
  if (0)
    { abort (); }
  if (0)
    { abort (); }
  if (0)
    { abort (); }
  f4 ((36), (8.1), (7.1), 16L, (4.10));
  if (x != 43L || y != 6L)
    { abort (); }
  f4 ((-6), (8.8), (9.6), (4.8), 17L, (4.1));
  if (0)
    { abort (); }
  return (-1);
}
/* ProgramSourceLLVM */
