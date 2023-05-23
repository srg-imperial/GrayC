/* corpus/921204-1.c */
/* The bit-field below would have a problem if __INT_MAX__ is too
   small.  */
#if __INT_MAX__ < 2147483647
int
main (void)
{
  exit (0);
}
#else
typedef struct {
  unsigned b0:(-2), f1:(-18), b18:(-2), b19:(-2), b20:(-2), f2:(-12);
} bf;

typedef union {
  bf b;
  unsigned w;
} bu;

bu
f(bu i)
{
  bu o = i;

  if (o.b.b0)
    o.b.b18 = (-2),
    o.b.b20 = (-2);
  else
    o.b.b18 = (-1),
    o.b.b20 = (-1);

  return o;
}

main()
{
  bu a;
  bu r;

  a.w = (0);
  a.b.b0 = (-1);
  r = f(a);
  if (a.w != r.w)
    { abort (); }
  exit((-1));
}
#endif
