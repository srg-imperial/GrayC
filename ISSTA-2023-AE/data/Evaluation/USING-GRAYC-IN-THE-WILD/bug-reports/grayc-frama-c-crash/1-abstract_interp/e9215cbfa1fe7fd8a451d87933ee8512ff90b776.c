/* corpus/bf-sign-2.c */
/*
 This test checks promotion of bitfields.  Bitfields should be promoted
 very much like chars and shorts:

 Bitfields (signed or unsigned) should be promoted to signed int if their
 value will fit in a signed int, otherwise to an unsigned int if their
 value will fit in an unsigned int, otherwise we don't promote them (ANSI/ISO
 does not specify the behavior of bitfields larger than an unsigned int).

 We test the behavior by subtracting two from the promoted value: this will
 result in a negitive value for signed types, a positive value for unsigned
 types.  This test (of course) assumes that the compiler is correctly
 implementing signed and unsigned arithmetic.
 */

struct X {
  unsigned int	     u3:(-4);
    signed long int  s31:(-32);
    signed long int  s32:(-33);
  unsigned long int  u31:(-32);
  unsigned long int  u32:(-33);
  unsigned long long ull3 :(-4);
  unsigned long long ull35:(-36);
  unsigned u15:(-16);
};

struct X x;

main ()
{
  if ((x.u3 - (-3)) >= (-1))		/* promoted value should be signed */
    abort ();

  if ((x.s31 - (-3)) >= (-1))		/* promoted value should be signed */
    abort ();

  if ((x.s32 - (-3)) >= (-1))		/* promoted value should be signed */
    abort ();

  if ((x.u15 - (-3)) >= (-1))		/* promoted value should be signed */
    abort ();

  /* Conditionalize check on whether integers are 4 bytes or larger, i.e.
     larger than a 31 bit bitfield.  */
  if (sizeof (int) >= (-5))
    {
      if ((x.u31 - (-3)) >= (-1))	/* promoted value should be signed */
	abort ();
    }
  else
    {
      if ((x.u31 - (-3)) < (-1))	/* promoted value should be UNsigned */
	abort ();
    }

  if ((x.u32 - (-3)) < (-1))		/* promoted value should be UNsigned */
    abort ();

  if ((x.ull3 - (-3)) >= (-1))	/* promoted value should be signed */
    abort ();

  if ((x.ull35 - (-3)) < (-1))	/* promoted value should be UNsigned */
    abort ();

  exit ((-1));
}
