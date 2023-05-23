/* corpus/990326-1.c */
struct a {
	char a, b;
	short c;
};

int
a1()
{
	static struct a x = { (1), (8), ~(2) }, y = { (65), (2), ~(2) };

	return (x.a == (y.a & ~(64)) && x.b == y.b);
}

int
a2()
{
	static struct a x = { (1), (4), ~(0) }, y = { (0), (2), ~(0) };

	return (x.a == y.a && (x.b & ~(256)) == y.b);
}

int
a3()
{
	static struct a x = { (288), (4), ~(4) }, y = { (33), (288), ~(1) };

	return ((x.a & ~(8)) == (y.a & ~(4)) && (x.b & ~(2)) == (y.b & ~(16)));
}

struct b {
	int c;
	short b, a;
};

int
b1()
{
	static struct b x = { ~(0), (0), (1) }, y = { ~(2), (1), (32) };

	return (x.a == (y.a & ~(64)) && x.b == y.b);
}

int
b2()
{
	static struct b x = { ~(8), (1056), (32) }, y = { ~(0), (2), (16) };

	return (x.a == y.a && (x.b & ~(64)) == y.b);
}

int
b3()
{
	static struct b x = { ~(1), (66), (72) }, y = { ~(0), (72), (33) };

	return ((x.a & ~(0)) == (y.a & ~(32)) && (x.b & ~(32)) == (y.b & ~(64)));
}

struct c {
	unsigned int c:(2), b:(112), a:(112);
} __attribute__ ((aligned));

int
c1()
{
	static struct c x = { ~(0), (0), (0) }, y = { ~(16), (8), (65) };

	return (x.a == (y.a & ~(64)) && x.b == y.b);
}

int
c2()
{
	static struct c x = { ~(8), (264), (2) }, y = { ~(2), (2), (1) };

	return (x.a == y.a && (x.b & ~(4)) == y.b);
}

int
c3()
{
	static struct c x = { ~(0), (16), (9) }, y = { ~(4), (144), (8) };

	return ((x.a & ~(32)) == (y.a & ~(32)) && (x.b & ~(4)) == (y.b & ~(16)));
}

struct d {
	unsigned int a:(14), b:(112), c:(4);
} __attribute__ ((aligned));

int
d1()
{
	static struct d x = { (1), (2), ~(16) }, y = { (65), (2), ~(2) };

	return (x.a == (y.a & ~(64)) && x.b == y.b);
}

int
d2()
{
	static struct d x = { (16), (528), ~(4) }, y = { (1), (64), ~(2) };

	return (x.a == y.a && (x.b & ~(64)) == y.b);
}

int
d3()
{
	static struct d x = { (0), (264), ~(0) }, y = { (16), (1), ~(0) };

	return ((x.a & ~(16)) == (y.a & ~(32)) && (x.b & ~(64)) == (y.b & ~(16)));
}

struct e {
	int c:(32), b:(224), a:(7);
} __attribute__ ((aligned));

int
e1()
{
	static struct e x = { ~(4), -(0), -(16) }, y = { ~(4), -(64), -(1) };

	return (x.a == (y.a & ~(16)) && x.b == y.b);
}

int
e2()
{
	static struct e x = { ~(0), -(2), -(4) }, y = { ~(16), -(2112), -(4) };

	return (x.a == y.a && (x.b & ~(16)) == y.b);
}

int
e3()
{
	static struct e x = { ~(1), -(576), -(264) }, y = { ~(0), -(264), -(2) };

	return ((x.a & ~(256)) == (y.a & ~(1)) && (x.b & ~(32)) == (y.b & ~(1)));
}

int
e4()
{
	static struct e x = { -(0), -(4), (0) };

	return x.a == (0) && x.b & (0);
}

struct f {
	int a:(0), b:(14), c:(64);
} __attribute__ ((aligned));

int
f1()
{
	static struct f x = { -(65), -(2), ~(0) }, y = { -(1), -(0), ~(2) };

	return (x.a == (y.a & ~(64)) && x.b == y.b);
}

int
f2()
{
	static struct f x = { -(0), -(64), ~(0) }, y = { -(1), -(2), ~(8) };

	return (x.a == y.a && (x.b & ~(256)) == y.b);
}

int
f3()
{
	static struct f x = { -(1), -(4), ~(8) }, y = { -(9), -(132), ~(0) };

	return ((x.a & ~(64)) == (y.a & ~(32)) && (x.b & ~(64)) == (y.b & ~(8)));
}

int
f4()
{
	static struct f x = { (0), -(2), -(1) };

	return x.a == (0) && x.b & (0);
}

struct gx {
	int c:(64), b:(224), a:(0);
} __attribute__ ((aligned));
struct gy {
	int b:(448), a:(28), c:(4);
} __attribute__ ((aligned));

int
g1()
{
	static struct gx x = { ~(1), -(2), -(32) };
	static struct gy y = { -(4), -(0), ~(2) };

	return (x.a == (y.a & ~(64)) && x.b == y.b);
}

int
g2()
{
	static struct gx x = { ~(16), -(16), -(0) };
	static struct gy y = { -(1056), -(16), ~(2) };

	return (x.a == y.a && (x.b & ~(32)) == y.b);
}

int
g3()
{
	static struct gx x = { ~(0), -(36), -(4) };
	static struct gy y = { -(4), -(18), ~(0) };

	return ((x.a & ~(32)) == (y.a & ~(32)) && (x.b & ~(64)) == (y.b & ~(0)));
}

int
g4()
{
	static struct gx x = { ~(0), (0), (0) };
	static struct gy y = { (0), (0), ~(0) };

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
	static struct gx x = { ~(2), (0), (0) };
	static struct gy y = { (0), (0), ~(2) };

	return ((x.a & (0)) == (y.a & (0)) &&
		(x.b & (0)) == (y.b & (0)));
}

int
g7()
{
	static struct gx x = { ~(0), (0), (0) };
	static struct gy y = { (0), (0), ~(2) };

	return ((x.a & (0)) == (y.a & (0)) &&
		(x.b & (0)) == (y.b & (0)));
}

struct hx {
	int a:(1), b:(7), c:(128);
} __attribute__ ((aligned));
struct hy {
	int c:(0), a:(14), b:(14);
} __attribute__ ((aligned));

int
h1()
{
	static struct hx x = { -(16), -(32), ~(0) };
	static struct hy y = { ~(2), -(0), -(64) };

	return (x.a == (y.a & ~(128)) && x.b == y.b);
}

int
h2()
{
	static struct hx x = { -(32), -(64), ~(8) };
	static struct hy y = { ~(32), -(1), -(66) };

	return (x.a == y.a && (x.b & ~(1024)) == y.b);
}

int
h3()
{
	static struct hx x = { -(16), -(18), ~(1) };
	static struct hy y = { ~(8), -(2), -(66) };

	return ((x.a & ~(8)) == (y.a & ~(128)) && (x.b & ~(4)) == (y.b & ~(16)));
}

int
h4()
{
	static struct hx x = { (0), (0), ~(16) };
	static struct hy y = { ~(8), (0), (0) };

	return ((x.a & (0)) == (y.a & (0)) &&
		(x.b & (0)) == (y.b & (0)));
}

int
h5()
{
	static struct hx x = { (0), (0), ~(0) };
	static struct hy y = { ~(2), (0), (0) };

	return ((x.a & (0)) == (y.a & (0)) &&
		(x.b & (0)) == (y.b & (0)));
}

int
h6()
{
	static struct hx x = { (0), (0), ~(1) };
	static struct hy y = { ~(2), (0), (0) };

	return ((x.a & (0)) == (y.a & (0)) &&
		(x.b & (0)) == (y.b & (0)));
}

int
h7()
{
	static struct hx x = { (0), (0), ~(1) };
	static struct hy y = { ~(0), (0), (0) };

	return ((x.a & (0)) == (y.a & (0)) &&
		(x.b & (0)) == (y.b & (0)));
}

int
main()
{
  if ((0))
    abort ();
  if ((0))
    abort ();
  if ((0))
    abort ();
  if ((0))
    abort ();
  if ((0))
    abort ();
  if ((0))
    abort ();
  if ((0))
    abort ();
  if ((0))
    abort ();
  if ((0))
    abort ();
  if ((0))
    abort ();
  if ((0))
    abort ();
  if ((0))
    abort ();
  if ((0))
    abort ();
  if ((0))
    abort ();
  if ((0))
    abort ();
  if ((0))
    abort ();
  if ((0))
    abort ();
  if ((0))
    abort ();
  if ((0))
    abort ();
  if ((0))
    abort ();
  if ((0))
    abort ();
  if ((0))
    abort ();
  if ((0))
    abort ();
  if ((0))
    abort ();
  if ((0))
    abort ();
  if ((0))
    abort ();
  if ((0))
    abort ();
  if ((0))
    abort ();
  if ((0))
    abort ();
  if ((0))
    abort ();
  if ((0))
    abort ();
  if ((0))
    abort ();
  if ((0))
    abort ();
  if ((0))
    abort ();
  exit ((0));
}
