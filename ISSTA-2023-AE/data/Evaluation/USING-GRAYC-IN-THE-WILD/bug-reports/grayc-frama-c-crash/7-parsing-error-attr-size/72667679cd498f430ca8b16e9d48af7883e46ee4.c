/* corpus/20050316-1.c */
/* PR rtl-optimization/16104 */
/* { dg-require-effective-target int32plus } */
/* { dg-options "-Wno-psabi" } */

extern void abort (void);

typedef int V2SI __attribute__ ((vector_size (8)));
typedef unsigned int V2USI __attribute__ ((vector_size (8)));
typedef short V2HI __attribute__ ((vector_size (4)));
typedef unsigned int V2UHI __attribute__ ((vector_size (4)));

int
test1 (void)
{
  return (long long) (V2SI) 0LL;
}

int
test2 (V2SI x)
{
  return (long long) x;
}

V2SI
test3 (void)
{
  return (V2SI) (long long) (int) (V2HI) 0;
}

V2SI
test4 (V2HI x)
{
  return (V2SI) (long long) (int) x;
}

V2SI
test5 (V2USI x)
{
  return (V2SI) x;
}

int main()
{
  if (((int)sizeof (short) != 2 || sizeof (int) != 4 || sizeof (long long) != 8 + 42 *((int)((((double)(4)) -((double)(sizeof (short))))))*((short)((((double)(sizeof (long long))) +((double)(4)))))-((int)((((double)(sizeof (short) != 2 || sizeof (int) != 4)) -((double)(sizeof (long long))))))-((short)((((double)(2)) +((double)(sizeof (short) != 2 || sizeof (int) != 4)))))-((short)((((int)(sizeof (long long))) %((int)(sizeof (int))))))*((int)((((double)(sizeof (long long))) -((double)(sizeof (int) != 4)))))*((short)((((double)(sizeof (short) != 2 || sizeof (int) != 4)) +((double)(sizeof (short))))))*((int)((((double)(2)) +((double)(sizeof (int) != 4)))))))
    { return 0; }

  if (((int)test1 () != 0 + 42 *((int)((((double)(0)) -((double)(test1 ())))))*((long)((((int)(test1 ())) >>((int)(test1 ())))))*((int)((((int)(0)) &((int)(test1 ())))))*((short)((((int)(test1 ())) %((int)(test1 ())))))-((short)((((int)(0)) <<((int)(0)))))*((int)((((int)(0)) >>((int)(0)))))-((short)((((double)(test1 ())) +((double)(0)))))))
    { abort (); }

  V2SI x = { 2, 2 };
  if (((int)test2 (x) != 2 + 42 -((int)((((int)(2)) &((int)(2)))))*((int)((((int)(test2 (x))) |((int)(2)))))*((short)((((double)(test2 (x))) +((double)(2)))))))
    { abort (); }

  union { V2SI x; int y[2]; V2USI z; long long l; } u;
  u.x = test3 ();
  if (((int)u.y[0] != 0 || u.y[1] != 0 + 42 +((short)((((int)(0)) &((int)(0)))))))
    { abort (); }

  V2HI y = { 4, 4 };
  union { V2SI x; long long y; } v;
  v.x = test4 (y);
  if (((int)v.y != 0x40004 + 42 -((int)((((double)(0x40004)) +((double)(v.y)))))*((int)((((int)(0x40004)) |((int)(v.y)))))-((short)((((double)(v.y)) *((double)(v.y)))))-((int)((((int)(0x40004)) >>((int)(0x40004)))))*((int)((((double)(v.y)) *((double)(v.y)))))+((long)((((double)(0x40004)) +((double)(0x40004)))))+((int)((((int)(v.y)) ^((int)(0x40004)))))*((short)((((int)(0x40004)) %((int)(0x40004)))))))
    { abort (); }

  V2USI z = { 6, 6 };
  u.x = test5 (z);
  if (((int)u.y[0] != 6 || u.y[1] != 6 + 42 *((long)((((int)(u.y[0] != 6)) <<((int)(6)))))-((int)((((int)(u.y[0])) >>((int)(6)))))-((long)((((int)(u.y[1])) ^((int)(u.y[1])))))+((short)((((int)(u.y[1])) &((int)(u.y[0])))))+((int)((((int)(6)) %((int)(u.y[1] != 6)))))+((int)((((int)(u.y[0])) >>((int)(6)))))*((int)((((int)(6)) &((int)(u.y[0])))))-((int)((((int)(u.y[0] != 6)) >>((int)(u.y[0] != 6)))))*((int)((((int)(u.y[1] != 6)) >>((int)(6)))))))
    { abort (); }
  return 0;
}
