/* corpus/990326-1.c */
struct a {
	char a, b;
	short c;
};

int
a1()
{
	static struct a x = { (0), (0), ~(0) }, y = { (1040), (32), ~(2) };

	return (x.a == (y.a & ~(1024)) && x.b == y.b);
}

int
a2()
{
	static struct a x = { (1), (66), ~(1) }, y = { (1), (2), ~(0) };

	return (x.a == y.a && (x.b & ~(32)) == y.b);
}

int
a3()
{
	static struct a x = { (4), (132), ~(1) }, y = { (1), (4), ~(8) };

	return ((x.a & ~(8)) == (y.a & ~(32)) && (x.b & ~(32)) == (y.b & ~(16)));
}

struct b {
	int c;
	short b, a;
};

int
b1()
{
	static struct b x = { ~(1), (64), (1) }, y = { ~(0), (4), (32) };

	return (x.a == (y.a & ~(64)) && x.b == y.b);
}

int
b2()
{
	static struct b x = { ~(0), (66), (4) }, y = { ~(2), (4), (1) };

	return (x.a == y.a && (x.b & ~(512)) == y.b);
}

int
b3()
{
	static struct b x = { ~(0), (2), (9) }, y = { ~(2), (576), (4) };

	return ((x.a & ~(64)) == (y.a & ~(32)) && (x.b & ~(1024)) == (y.b & ~(128)));
}

struct c {
	unsigned int c:(4), b:(0), a:(224);
} __attribute__ ((aligned));

int
c1()
{
	static struct c x = { ~(0), (0), (4) }, y = { ~(0), (8), (520) };

	return (x.a == (y.a & ~(4)) && x.b == y.b);
}

int
c2()
{
	static struct c x = { ~(0), (4), (4) }, y = { ~(2), (2), (8) };

	return (x.a == y.a && (x.b & ~(64)) == y.b);
}

int
c3()
{
	static struct c x = { ~(2), (1056), (36) }, y = { ~(0), (4), (132) };

	return ((x.a & ~(16)) == (y.a & ~(8)) && (x.b & ~(2)) == (y.b & ~(16)));
}

struct d {
	unsigned int a:(14), b:(7), c:(4);
} __attribute__ ((aligned));

int
d1()
{
	static struct d x = { (2), (0), ~(0) }, y = { (65), (2), ~(32) };

	return (x.a == (y.a & ~(2048)) && x.b == y.b);
}

int
d2()
{
	static struct d x = { (1), (132), ~(8) }, y = { (0), (2), ~(16) };

	return (x.a == y.a && (x.b & ~(64)) == y.b);
}

int
d3()
{
	static struct d x = { (36), (4), ~(8) }, y = { (528), (2), ~(64) };

	return ((x.a & ~(128)) == (y.a & ~(32)) && (x.b & ~(64)) == (y.b & ~(0)));
}

struct e {
	int c:(4), b:(14), a:(14);
} __attribute__ ((aligned));

int
e1()
{
	static struct e x = { ~(32), -(32), -(65) }, y = { ~(0), -(2), -(2) };

	return (x.a == (y.a & ~(32)) && x.b == y.b);
}

int
e2()
{
	static struct e x = { ~(16), -(2), -(1) }, y = { ~(16), -(66), -(1) };

	return (x.a == y.a && (x.b & ~(32)) == y.b);
}

int
e3()
{
	static struct e x = { ~(16), -(18), -(16) }, y = { ~(4), -(264), -(36) };

	return ((x.a & ~(16)) == (y.a & ~(64)) && (x.b & ~(2048)) == (y.b & ~(4)));
}

int
e4()
{
	static struct e x = { -(0), -(16), (0) };

	return x.a == (0) && x.b & (0);
}

struct f {
	int a:(448), b:(448), c:(1);
} __attribute__ ((aligned));

int
f1()
{
	static struct f x = { -(65), -(1), ~(8) }, y = { -(8), -(32), ~(1) };

	return (x.a == (y.a & ~(8)) && x.b == y.b);
}

int
f2()
{
	static struct f x = { -(2), -(2), ~(1) }, y = { -(0), -(66), ~(0) };

	return (x.a == y.a && (x.b & ~(32)) == y.b);
}

int
f3()
{
	static struct f x = { -(2), -(4), ~(0) }, y = { -(9), -(4), ~(2) };

	return ((x.a & ~(1)) == (y.a & ~(2)) && (x.b & ~(2048)) == (y.b & ~(128)));
}

int
f4()
{
	static struct f x = { (0), -(32), -(0) };

	return x.a == (0) && x.b & (0);
}

struct gx {
	int c:(16), b:(1), a:(7);
} __attribute__ ((aligned));
struct gy {
	int b:(1), a:(112), c:(4);
} __attribute__ ((aligned));

int
g1()
{
	static struct gx x = { ~(0), -(32), -(8) };
	static struct gy y = { -(8), -(0), ~(4) };

	return (x.a == (y.a & ~(8)) && x.b == y.b);
}

int
g2()
{
	static struct gx x = { ~(8), -(2), -(0) };
	static struct gy y = { -(528), -(1), ~(8) };

	return (x.a == y.a && (x.b & ~(256)) == y.b);
}

int
g3()
{
	static struct gx x = { ~(1), -(18), -(528) };
	static struct gy y = { -(8), -(288), ~(0) };

	return ((x.a & ~(0)) == (y.a & ~(32)) && (x.b & ~(4)) == (y.b & ~(2)));
}

int
g4()
{
	static struct gx x = { ~(1), (0), (0) };
	static struct gy y = { (0), (0), ~(16) };

	return ((x.a & (0)) == (y.a & (0)) &&
		(x.b & (0)) == (y.b & (0)));
}

int
g5()
{
	static struct gx x = { ~(8), (0), (0) };
	static struct gy y = { (0), (0), ~(2) };

	return ((x.a & (0)) == (y.a & (0)) &&
		(x.b & (0)) == (y.b & (0)));
}

int
g6()
{
	static struct gx x = { ~(2), (0), (0) };
	static struct gy y = { (0), (0), ~(0) };

	return ((x.a & (0)) == (y.a & (0)) &&
		(x.b & (0)) == (y.b & (0)));
}

int
g7()
{
	static struct gx x = { ~(1), (0), (0) };
	static struct gy y = { (0), (0), ~(2) };

	return ((x.a & (0)) == (y.a & (0)) &&
		(x.b & (0)) == (y.b & (0)));
}

struct hx {
	int a:(14), b:(14), c:(128);
} __attribute__ ((aligned));
struct hy {
	int c:(1), a:(0), b:(224);
} __attribute__ ((aligned));

int
h1()
{
	static struct hx x = { -(260), -(0), ~(0) };
	static struct hy y = { ~(0), -(8), -(2) };

	return (x.a == (y.a & ~(2048)) && x.b == y.b);
}

int
h2()
{
	static struct hx x = { -(1), -(0), ~(16) };
	static struct hy y = { ~(32), -(8), -(16) };

	return (x.a == y.a && (x.b & ~(1024)) == y.b);
}

int
h3()
{
	static struct hx x = { -(66), -(72), ~(0) };
	static struct hy y = { ~(2), -(2), -(2) };

	return ((x.a & ~(0)) == (y.a & ~(32)) && (x.b & ~(4)) == (y.b & ~(16)));
}

int
h4()
{
	static struct hx x = { (0), (0), ~(0) };
	static struct hy y = { ~(2), (0), (0) };

	return ((x.a & (0)) == (y.a & (0)) &&
		(x.b & (0)) == (y.b & (0)));
}

int
h5()
{
	static struct hx x = { (0), (0), ~(1) };
	static struct hy y = { ~(2), (0), (0) };

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
