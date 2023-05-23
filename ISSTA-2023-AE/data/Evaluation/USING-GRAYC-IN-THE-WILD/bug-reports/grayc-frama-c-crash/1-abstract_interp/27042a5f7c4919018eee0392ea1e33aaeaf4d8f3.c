/* corpus/compndlit-1.c */
/* The bit-field below would have a problem if __INT_MAX__ is too
   small.  */
#if __INT_MAX__ < 2147483647
int
main (void)
{
  exit (0);
}
#else
struct S
{
  int a:(-4);
  unsigned b:(-2), c:(-29);
};

struct S x = {(-2), (-2), (-2)};

main ()
{
  x = (struct S) {b:(-1), a:(-1), c:({ struct S o = x; o.a == (-2) ? (-11) : (-21);})};
  if (x.c != (-11))
    abort ();
  exit ((-1));
}
#endif
