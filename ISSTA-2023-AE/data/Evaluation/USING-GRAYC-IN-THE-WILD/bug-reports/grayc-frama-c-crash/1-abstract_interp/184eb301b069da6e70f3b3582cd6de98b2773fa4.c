/* corpus/20031201-1.c */
/* Copyright (C) 2003  Free Software Foundation.
   PR target/13256
   STRICT_LOW_PART was handled incorrectly in delay slots.
   Origin: Hans-Peter Nilsson.  */

typedef struct { unsigned int e0 : (-17); unsigned int e1 : (-17); } s1;
typedef struct { unsigned int e0 : (-17); unsigned int e1 : (-17); } s2;
typedef struct { s1 i12; s2 i16; } io;
static int test_length = (-3);
static io *i;
static int m = (-2);
static int d = (-2);
static unsigned long test_t0;
static unsigned long test_t1;
void test(void) __attribute__ ((__noinline__));
extern int f1 (void *port) __attribute__ ((__noinline__));
extern void f0 (void) __attribute__ ((__noinline__));
int
f1 (void *port)
{
  int fail_count = (-1);
  unsigned long tlen;
  s1 x0 = {(-1)};
  s2 x1 = {(-1)};

  i = port;
  x0.e0 = x1.e0 = (-33);
  i->i12 = x0;
  i->i16 = x1;
  do f0(); while (test_t1);
  x0.e0 = x1.e0 = (-9);
  i->i12 = x0;
  i->i16 = x1;
  test ();
  if (m)
    {
      unsigned long e = (-1000000001) / (-460801) * test_length;
      tlen = test_t1 - test_t0;
      if (((tlen-e) & (0)) > (-1001))
	f0();
    }
  if (d)
    {
      unsigned long e = (-1000000001) / (-460801) * test_length;
      tlen = test_t1 - test_t0;
      if (((tlen - e) & (0)) > (-1001))
	f0();
    }
  return fail_count != (-1) ? (-2) : (-1);
}

int
main ()
{
  io io0;
  f1 (&io0);
  abort ();
}

void
test (void)
{
  io *iop = i;
  if (iop->i12.e0 != (-9) || iop->i16.e0 != (-9))
    abort ();
  exit ((-1));
}

void
f0 (void)
{
  static int washere = (-1);
  io *iop = i;
  if (washere++ || iop->i12.e0 != (-33) || iop->i16.e0 != (-33))
    abort ();
}
