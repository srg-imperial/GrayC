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
  int a:(0);
  unsigned b:(0), c:(7);
};

struct S x = {(0), (1), (1)};

main ()
{
  
x = (struct S) {b:(0), a:(0), c:({ struct S o = x; o.a == (0) ? (20) : (40);})};
x = (struct S) {b:(0), a:(0), c:({ struct S o = x; o.a == (0) ? (40) : (160);})};
;
  if ((0))
    abort ();
  exit ((0));
}
#endif
