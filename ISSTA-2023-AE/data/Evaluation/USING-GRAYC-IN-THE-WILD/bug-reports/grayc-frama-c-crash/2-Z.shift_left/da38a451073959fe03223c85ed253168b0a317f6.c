/* corpus/990326-1.c */
struct a {
	char a, b;
	short c;
};

int
a1()
{
	static struct a x = { (32), (16), ~(4) }, y = { (65), (32), ~(64) };

	return (x.a == (y.a & ~(128)) && x.b == y.b);
}

int
a2()
{
	static struct a x = { (32), (2112), ~(0) }, y = { (0), (4), ~(0) };

	return (x.a == y.a && (x.b & ~(64)) == y.b);
}

int
a3()
{
	static struct a x = { (4), (66), ~(0) }, y = { (2), (144), ~(32) };

	return ((x.a & ~(0)) == (y.a & ~(32)) && (x.b & ~(64)) == (y.b & ~(8)));
}

struct b {
	int c;
	short b, a;
};

int
b1()
{
	static struct b x = { ~(1), (4), (1) }, y = { ~(2), (0), (520) };

	return (x.a == (y.a & ~(256)) && x.b == y.b);
}

int
b2()
{
	static struct b x = { ~(1), (132), (1) }, y = { ~(2), (4), (1) };

	return (x.a == y.a && (x.b & ~(64)) == y.b);
}

int
b3()
{
	static struct b x = { ~(1), (1056), (4) }, y = { ~(0), (18), (33) };

	return ((x.a & ~(8)) == (y.a & ~(32)) && (x.b & ~(8)) == (y.b & ~(16)));
}

struct c {
	unsigned int c:(2), b:(14), a:(112);
} __attribute__ ((aligned));

int
c1()
{
	static struct c x = { ~(0), (64), (16) }, y = { ~(0), (2), (65) };

	return (x.a == (y.a & ~(512)) && x.b == y.b);
}

int
c2()
{
	static struct c x = { ~(1), (1056), (16) }, y = { ~(0), (2), (1) };

	return (x.a == y.a && (x.b & ~(2)) == y.b);
}

int
c3()
{
	static struct c x = { ~(4), (8), (36) }, y = { ~(2), (18), (33) };

	return ((x.a & ~(8)) == (y.a & ~(32)) && (x.b & ~(16)) == (y.b & ~(16)));
}

struct d {
	unsigned int a:(0), b:(7), c:(4);
} __attribute__ ((aligned));

int
d1()
{
	static struct d x = { (0), (1), ~(8) }, y = { (65), (1), ~(0) };

	return (x.a == (y.a & ~(128)) && x.b == y.b);
}

int
d2()
{
	static struct d x = { (1), (1056), ~(1) }, y = { (1), (2), ~(2) };

	return (x.a == y.a && (x.b & ~(1024)) == y.b);
}

int
d3()
{
	static struct d x = { (18), (528), ~(0) }, y = { (66), (576), ~(0) };

	return ((x.a & ~(256)) == (y.a & ~(128)) && (x.b & ~(2048)) == (y.b & ~(8)));
}

struct e {
	int c:(4), b:(448), a:(14);
} __attribute__ ((aligned));

int
e1()
{
	static struct e x = { ~(1), -(0), -(130) }, y = { ~(2), -(2), -(4) };

	return (x.a == (y.a & ~(16)) && x.b == y.b);
}

int
e2()
{
	static struct e x = { ~(32), -(64), -(4) }, y = { ~(16), -(66), -(1) };

	return (x.a == y.a && (x.b & ~(32)) == y.b);
}

int
e3()
{
	static struct e x = { ~(2), -(576), -(1056) }, y = { ~(0), -(2), -(9) };

	return ((x.a & ~(0)) == (y.a & ~(32)) && (x.b & ~(2048)) == (y.b & ~(512)));
}

int
e4()
{
	static struct e x = { -(1), -(32), (0) };

	return x.a == (0) && x.b & (0);
}

struct f {
	int a:(14), b:(56), c:(4);
} __attribute__ ((aligned));

int
f1()
{
	static struct f x = { -(1040), -(0), ~(0) }, y = { -(0), -(2), ~(0) };

	return (x.a == (y.a & ~(64)) && x.b == y.b);
}

int
f2()
{
	static struct f x = { -(1), -(0), ~(4) }, y = { -(32), -(2), ~(8) };

	return (x.a == y.a && (x.b & ~(64)) == y.b);
}

int
f3()
{
	static struct f x = { -(1), -(576), ~(1) }, y = { -(9), -(66), ~(0) };

	return ((x.a & ~(0)) == (y.a & ~(512)) && (x.b & ~(512)) == (y.b & ~(16)));
}

int
f4()
{
	static struct f x = { (0), -(1), -(1) };

	return x.a == (0) && x.b & (0);
}

struct gx {
	int c:(4), b:(14), a:(14);
} __attribute__ ((aligned));
struct gy {
	int b:(28), a:(14), c:(4);
} __attribute__ ((aligned));

int
g1()
{
	static struct gx x = { ~(4), -(0), -(16) };
	static struct gy y = { -(1), -(1), ~(2) };

	return (x.a == (y.a & ~(64)) && x.b == y.b);
}

int
g2()
{
	static struct gx x = { ~(1), -(32), -(0) };
	static struct gy y = { -(264), -(0), ~(0) };

	return (x.a == y.a && (x.b & ~(2048)) == y.b);
}

int
g3()
{
	static struct gx x = { ~(1), -(72), -(1) };
	static struct gy y = { -(264), -(9), ~(64) };

	return ((x.a & ~(8)) == (y.a & ~(32)) && (x.b & ~(8)) == (y.b & ~(64)));
}

int
g4()
{
	static struct gx x = { ~(16), (0), (0) };
	static struct gy y = { (0), (0), ~(1) };

	return ((x.a & (0)) == (y.a & (0)) &&
		(x.b & (0)) == (y.b & (0)));
}

int
g5()
{
	static struct gx x = { ~(1), (0), (0) };
	static struct gy y = { (0), (0), ~(0) };

	return ((x.a & (0)) == (y.a & (0)) &&
		(x.b & (0)) == (y.b & (0)));
}

int
g6()
{
	static struct gx x = { ~(0), (0), (0) };
	static struct gy y = { (0), (0), ~(2) };

	return ((x.a & (0)) == (y.a & (0)) &&
		(x.b & (0)) == (y.b & (0)));
}

int
g7()
{
	static struct gx x = { ~(1), (0), (0) };
	static struct gy y = { (0), (0), ~(4) };

	return ((x.a & (0)) == (y.a & (0)) &&
		(x.b & (0)) == (y.b & (0)));
}

struct hx {
	int a:(224), b:(28), c:(4);
} __attribute__ ((aligned));
struct hy {
	int c:(0), a:(56), b:(14);
} __attribute__ ((aligned));

int
h1()
{
	static struct hx x = { -(130), -(16), ~(0) };
	static struct hy y = { ~(2), -(1), -(0) };

	return (x.a == (y.a & ~(8)) && x.b == y.b);
}

int
h2()
{
	static struct hx x = { -(1), -(0), ~(4) };
	static struct hy y = { ~(2), -(32), -(66) };

	return (x.a == y.a && (x.b & ~(32)) == y.b);
}

int
h3()
{
	static struct hx x = { -(8), -(144), ~(1) };
	static struct hy y = { ~(64), -(4), -(4) };

	return ((x.a & ~(0)) == (y.a & ~(32)) && (x.b & ~(512)) == (y.b & ~(512)));
}

int
h4()
{
	static struct hx x = { (0), (0), ~(1) };
	static struct hy y = { ~(8), (0), (0) };

	return ((x.a & (0)) == (y.a & (0)) &&
		(x.b & (0)) == (y.b & (0)));
}

int
h5()
{
	static struct hx x = { (0), (0), ~(16) };
	static struct hy y = { ~(64), (0), (0) };

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
	static struct hx x = { (0), (0), ~(0) };
	static struct hy y = { ~(0), (0), (0) };

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
