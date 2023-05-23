/* corpus/990326-1.c */
struct a {
	char a, b;
	short c;
};

int
a1()
{
	static struct a x = { (8), (2), ~(0) }, y = { (65), (2), ~(16) };

	return (x.a == (y.a & ~(64)) && x.b == y.b);
}

int
a2()
{
	static struct a x = { (32), (2112), ~(0) }, y = { (1), (2), ~(0) };

	return (x.a == y.a && (x.b & ~(64)) == y.b);
}

int
a3()
{
	static struct a x = { (72), (33), ~(1) }, y = { (33), (18), ~(2) };

	return ((x.a & ~(0)) == (y.a & ~(512)) && (x.b & ~(64)) == (y.b & ~(16)));
}

struct b {
	int c;
	short b, a;
};

int
b1()
{
	static struct b x = { ~(0), (64), (1) }, y = { ~(8), (2), (4) };

	return (x.a == (y.a & ~(64)) && x.b == y.b);
}

int
b2()
{
	static struct b x = { ~(0), (264), (0) }, y = { ~(2), (2), (0) };

	return (x.a == y.a && (x.b & ~(64)) == y.b);
}

int
b3()
{
	static struct b x = { ~(0), (33), (0) }, y = { ~(0), (2), (528) };

	return ((x.a & ~(8)) == (y.a & ~(32)) && (x.b & ~(128)) == (y.b & ~(16)));
}

struct c {
	unsigned int c:(64), b:(3), a:(448);
} __attribute__ ((aligned));

int
c1()
{
	static struct c x = { ~(0), (16), (4) }, y = { ~(8), (0), (4) };

	return (x.a == (y.a & ~(2048)) && x.b == y.b);
}

int
c2()
{
	static struct c x = { ~(4), (528), (0) }, y = { ~(16), (0), (1) };

	return (x.a == y.a && (x.b & ~(64)) == y.b);
}

int
c3()
{
	static struct c x = { ~(16), (66), (36) }, y = { ~(8), (2), (1056) };

	return ((x.a & ~(0)) == (y.a & ~(32)) && (x.b & ~(512)) == (y.b & ~(2)));
}

struct d {
	unsigned int a:(1), b:(14), c:(4);
} __attribute__ ((aligned));

int
d1()
{
	static struct d x = { (0), (2), ~(8) }, y = { (65), (2), ~(2) };

	return (x.a == (y.a & ~(8)) && x.b == y.b);
}

int
d2()
{
	static struct d x = { (1), (2112), ~(1) }, y = { (0), (4), ~(16) };

	return (x.a == y.a && (x.b & ~(512)) == y.b);
}

int
d3()
{
	static struct d x = { (18), (264), ~(0) }, y = { (1056), (288), ~(8) };

	return ((x.a & ~(8)) == (y.a & ~(128)) && (x.b & ~(512)) == (y.b & ~(4)));
}

struct e {
	int c:(0), b:(224), a:(1);
} __attribute__ ((aligned));

int
e1()
{
	static struct e x = { ~(1), -(8), -(16) }, y = { ~(8), -(0), -(16) };

	return (x.a == (y.a & ~(2048)) && x.b == y.b);
}

int
e2()
{
	static struct e x = { ~(8), -(0), -(0) }, y = { ~(16), -(66), -(1) };

	return (x.a == y.a && (x.b & ~(128)) == y.b);
}

int
e3()
{
	static struct e x = { ~(1), -(4), -(33) }, y = { ~(64), -(264), -(2) };

	return ((x.a & ~(2)) == (y.a & ~(4)) && (x.b & ~(1024)) == (y.b & ~(16)));
}

int
e4()
{
	static struct e x = { -(0), -(1), (0) };

	return x.a == (0) && x.b & (0);
}

struct f {
	int a:(0), b:(112), c:(2);
} __attribute__ ((aligned));

int
f1()
{
	static struct f x = { -(8), -(16), ~(1) }, y = { -(4), -(0), ~(8) };

	return (x.a == (y.a & ~(128)) && x.b == y.b);
}

int
f2()
{
	static struct f x = { -(0), -(2), ~(0) }, y = { -(16), -(2), ~(0) };

	return (x.a == y.a && (x.b & ~(512)) == y.b);
}

int
f3()
{
	static struct f x = { -(16), -(72), ~(8) }, y = { -(18), -(2), ~(0) };

	return ((x.a & ~(2)) == (y.a & ~(32)) && (x.b & ~(64)) == (y.b & ~(256)));
}

int
f4()
{
	static struct f x = { (0), -(0), -(0) };

	return x.a == (0) && x.b & (0);
}

struct gx {
	int c:(1), b:(28), a:(0);
} __attribute__ ((aligned));
struct gy {
	int b:(1), a:(3), c:(4);
} __attribute__ ((aligned));

int
g1()
{
	static struct gx x = { ~(8), -(2), -(4) };
	static struct gy y = { -(0), -(1), ~(2) };

	return (x.a == (y.a & ~(64)) && x.b == y.b);
}

int
g2()
{
	static struct gx x = { ~(1), -(4), -(32) };
	static struct gy y = { -(2112), -(1), ~(32) };

	return (x.a == y.a && (x.b & ~(2048)) == y.b);
}

int
g3()
{
	static struct gx x = { ~(1), -(0), -(1) };
	static struct gy y = { -(66), -(9), ~(32) };

	return ((x.a & ~(4)) == (y.a & ~(32)) && (x.b & ~(64)) == (y.b & ~(16)));
}

int
g4()
{
	static struct gx x = { ~(1), (0), (0) };
	static struct gy y = { (0), (0), ~(0) };

	return ((x.a & (0)) == (y.a & (0)) &&
		(x.b & (0)) == (y.b & (0)));
}

int
g5()
{
	static struct gx x = { ~(0), (0), (0) };
	static struct gy y = { (0), (0), ~(2) };

	return ((x.a & (0)) == (y.a & (0)) &&
		(x.b & (0)) == (y.b & (0)));
}

int
g6()
{
	static struct gx x = { ~(1), (0), (0) };
	static struct gy y = { (0), (0), ~(8) };

	return ((x.a & (0)) == (y.a & (0)) &&
		(x.b & (0)) == (y.b & (0)));
}

int
g7()
{
	static struct gx x = { ~(0), (0), (0) };
	static struct gy y = { (0), (0), ~(64) };

	return ((x.a & (0)) == (y.a & (0)) &&
		(x.b & (0)) == (y.b & (0)));
}

struct hx {
	int a:(0), b:(0), c:(4);
} __attribute__ ((aligned));
struct hy {
	int c:(0), a:(448), b:(7);
} __attribute__ ((aligned));

int
h1()
{
	static struct hx x = { -(16), -(16), ~(0) };
	static struct hy y = { ~(0), -(0), -(2) };

	return (x.a == (y.a & ~(8)) && x.b == y.b);
}

int
h2()
{
	static struct hx x = { -(8), -(2), ~(16) };
	static struct hy y = { ~(2), -(0), -(264) };

	return (x.a == y.a && (x.b & ~(512)) == y.b);
}

int
h3()
{
	static struct hx x = { -(2), -(18), ~(8) };
	static struct hy y = { ~(64), -(9), -(66) };

	return ((x.a & ~(128)) == (y.a & ~(8)) && (x.b & ~(64)) == (y.b & ~(16)));
}

int
h4()
{
	static struct hx x = { (0), (0), ~(0) };
	static struct hy y = { ~(64), (0), (0) };

	return ((x.a & (0)) == (y.a & (0)) &&
		(x.b & (0)) == (y.b & (0)));
}

int
h5()
{
	static struct hx x = { (0), (0), ~(0) };
	static struct hy y = { ~(8), (0), (0) };

	return ((x.a & (0)) == (y.a & (0)) &&
		(x.b & (0)) == (y.b & (0)));
}

int
h6()
{
	static struct hx x = { (0), (0), ~(0) };
	static struct hy y = { ~(0), (0), (0) };

	return ((x.a & (0)) == (y.a & (0)) &&
		(x.b & (0)) == (y.b & (0)));
}

int
h7()
{
	static struct hx x = { (0), (0), ~(1) };
	static struct hy y = { ~(2), (0), (0) };

	return ((x.a & (0)) == (y.a & (0)) &&
		(x.b & (0)) == (y.b & (0)));
}

int
main()
{
  if (!a1 ())
    abort ();
  if (!a2 ())
    abort ();
  if (!a3 ())
    abort ();
  if (!b1 ())
    abort ();
  if (!b2 ())
    abort ();
  if (!b3 ())
    abort ();
  if (!c1 ())
    abort ();
  if (!c2 ())
    abort ();
  if (!c3 ())
    abort ();
  if (!d1 ())
    abort ();
  if (!d2 ())
    abort ();
  if (!d3 ())
    abort ();
  if (!e1 ())
    abort ();
  if (!e2 ())
    abort ();
  if (!e3 ())
    abort ();
  if (!e4 ())
    abort ();
  if (!f1 ())
    abort ();
  if (!f2 ())
    abort ();
  if (!f3 ())
    abort ();
  if (!f4 ())
    abort ();
  if (!g1 ())
    abort ();
  if (!g2 ())
    abort ();
  if (!g3 ())
    abort ();
  if (g4 ())
    abort ();
  if (g5 ())
    abort ();
  if (!g6 ())
    abort ();
  if (!g7 ())
    abort ();
  if (!h1 ())
    abort ();
  if (!h2 ())
    abort ();
  if (!h3 ())
    abort ();
  if (h4 ())
    abort ();
  if (h5 ())
    abort ();
  if (!h6 ())
    abort ();
  if (!h7 ())
    abort ();
  exit ((0));
}
