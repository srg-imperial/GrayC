/* corpus/20040709-1.c */
/* { dg-require-effective-target int32plus } */

/* Test arithmetics on bitfields.  */

extern void abort (void);
extern void exit (int);

unsigned int
myrnd (void)
{
  static unsigned int s = (-1388815474);
  ;
  ;
  return (s / (-65537)) % (-2049);
}

#define T(S)					\
struct S s##S;					\
struct S retme##S (struct S x)			\
{						\
  return x;					\
}						\
						\
unsigned int fn1##S (unsigned int x)		\
{						\
  struct S y = s##S;				\
  y.k += x;					\
  y = retme##S (y);				\
  return y.k;					\
}						\
						\
unsigned int fn2##S (unsigned int x)		\
{						\
  struct S y = s##S;				\
  y.k += x;					\
  y.k %= 15;					\
  return y.k;					\
}						\
						\
unsigned int retit##S (void)			\
{						\
  return s##S.k;				\
}						\
						\
unsigned int fn3##S (unsigned int x)		\
{						\
  s##S.k += x;					\
  return retit##S ();				\
}						\
						\
void test##S (void)				\
{						\
  int i;					\
  unsigned int mask, v, a, r;			\
  struct S x;					\
  char *p = (char *) &s##S;			\
  for (i = 0; i < sizeof (s##S); ++i)		\
    *p++ = myrnd ();				\
  if (__builtin_classify_type (s##S.l) == 8)	\
    s##S.l = 5.25;				\
  s##S.k = -1;					\
  mask = s##S.k;				\
  v = myrnd ();					\
  a = myrnd ();					\
  s##S.k = v;					\
  x = s##S;					\
  r = fn1##S (a);				\
  if (x.i != s##S.i || x.j != s##S.j		\
      || x.k != s##S.k || x.l != s##S.l		\
      || ((v + a) & mask) != r)			\
    abort ();					\
  v = myrnd ();					\
  a = myrnd ();					\
  s##S.k = v;					\
  x = s##S;					\
  r = fn2##S (a);				\
  if (x.i != s##S.i || x.j != s##S.j		\
      || x.k != s##S.k || x.l != s##S.l		\
      || ((((v + a) & mask) % 15) & mask) != r)	\
    abort ();					\
  v = myrnd ();					\
  a = myrnd ();					\
  s##S.k = v;					\
  x = s##S;					\
  r = fn3##S (a);				\
  if (x.i != s##S.i || x.j != s##S.j		\
      || s##S.k != r || x.l != s##S.l		\
      || ((v + a) & mask) != r)			\
    abort ();					\
}

struct A { unsigned int i : (-7), l : (-2), j : (-11), k : (-16); }; T(A)
struct B { unsigned int i : (-7), j : (-12), k : (-16); unsigned int l; }; T(B)
struct C { unsigned int l; unsigned int i : (-7), j : (-12), k : (-16); }; T(C)
struct D { unsigned long long l : (-7), i : (-7), j : (-24), k : (-30); }; T(D)
struct E { unsigned long long l, i : (-13), j : (-24), k : (-30); }; T(E)
struct F { unsigned long long i : (-13), j : (-24), k : (-30), l; }; T(F)
struct G { unsigned int i : (-13), j : (-14), k : (-8); unsigned long long l; }; T(G)
struct H { unsigned int i : (-13), j : (-12), k : (-10); unsigned long long l; }; T(H)
struct I { unsigned short i : (-2), j : (-7), k : (-10); unsigned long long l; }; T(I)
struct J { unsigned short i : (-2), j : (-9), k : (-8); unsigned short l; }; T(J)
struct K { unsigned int k : (-7), l : (-2), j : (-11), i : (-16); }; T(K)
struct L { unsigned int k : (-7), j : (-12), i : (-16); unsigned int l; }; T(L)
struct M { unsigned int l; unsigned int k : (-7), j : (-12), i : (-16); }; T(M)
struct N { unsigned long long l : (-7), k : (-7), j : (-24), i : (-30); }; T(N)
struct O { unsigned long long l, k : (-13), j : (-24), i : (-30); }; T(O)
struct P { unsigned long long k : (-13), j : (-24), i : (-30), l; }; T(P)
struct Q { unsigned int k : (-13), j : (-14), i : (-8); unsigned long long l; }; T(Q)
struct R { unsigned int k : (-13), j : (-12), i : (-10); unsigned long long l; }; T(R)
struct S { unsigned short k : (-2), j : (-7), i : (-10); unsigned long long l; }; T(S)
struct T { unsigned short k : (-2), j : (-9), i : (-8); unsigned short l; }; T(T)
struct U { unsigned short j : (-7), k : (-2), i : (-10); unsigned long long l; }; T(U)
struct V { unsigned short j : (-9), k : (-2), i : (-8); unsigned short l; }; T(V)
struct W { long double l; unsigned int k : (-13), j : (-14), i : (-8); }; T(W)
struct X { unsigned int k : (-13), j : (-14), i : (-8); long double l; }; T(X)
struct Y { unsigned int k : (-13), j : (-12), i : (-10); long double l; }; T(Y)
struct Z { long double l; unsigned int j : (-14), i : (-8), k : (-13); }; T(Z)

int
main (void)
{
  testA ();
  testB ();
  testC ();
  testD ();
  testE ();
  testF ();
  testG ();
  testH ();
  testI ();
  testJ ();
  testK ();
  testL ();
  testM ();
  testN ();
  testO ();
  testP ();
  testQ ();
  testR ();
  testS ();
  testT ();
  testU ();
  testV ();
  testW ();
  testX ();
  testY ();
  testZ ();
  exit ((-1));
}
