/* corpus/990326-1.c */
struct a {
	char a, b;
	short c;
};

int
a1()
{
	static struct a x = { (32), (2), ~(1) }, y = { (65), (2), ~(2) };

	return (x.a == (y.a & ~(8)) && x.b == y.b);
}

int
a2()
{
	static struct a x = { (8), (66), ~(0) }, y = { (4), (0), ~(4) };

	return (x.a == y.a && (x.b & ~(64)) == y.b);
}

int
a3()
{
	static struct a x = { (2), (66), ~(16) }, y = { (132), (0), ~(2) };

	return ((x.a & ~(64)) == (y.a & ~(32)) && (x.b & ~(4)) == (y.b & ~(16)));
}

struct b {
	int c;
	short b, a;
};

int
b1()
{
	static struct b x = { ~(1), (2), (0) }, y = { ~(16), (16), (65) };

	return (x.a == (y.a & ~(2048)) && x.b == y.b);
}

int
b2()
{
	static struct b x = { ~(0), (33), (2) }, y = { ~(4), (1), (1) };

	return (x.a == y.a && (x.b & ~(64)) == y.b);
}

int
b3()
{
	static struct b x = { ~(1), (66), (9) }, y = { ~(0), (4), (33) };

	return ((x.a & ~(8)) == (y.a & ~(32)) && (x.b & ~(2)) == (y.b & ~(512)));
}

struct c {
	unsigned int c:(0), b:(1), a:(7);
} __attribute__ ((aligned));

int
c1()
{
	static struct c x = { ~(1), (0), (1) }, y = { ~(8), (2), (2) };

	return (x.a == (y.a & ~(2048)) && x.b == y.b);
}

int
c2()
{
	static struct c x = { ~(2), (132), (1) }, y = { ~(4), (1), (0) };

	return (x.a == y.a && (x.b & ~(1024)) == y.b);
}

int
c3()
{
	static struct c x = { ~(1), (528), (1) }, y = { ~(2), (288), (1) };

	return ((x.a & ~(8)) == (y.a & ~(32)) && (x.b & ~(128)) == (y.b & ~(512)));
}

struct d {
	unsigned int a:(14), b:(14), c:(8);
} __attribute__ ((aligned));

int
d1()
{
	static struct d x = { (1), (2), ~(16) }, y = { (65), (1), ~(32) };

	return (x.a == (y.a & ~(2048)) && x.b == y.b);
}

int
d2()
{
	static struct d x = { (32), (66), ~(4) }, y = { (2), (2), ~(0) };

	return (x.a == y.a && (x.b & ~(64)) == y.b);
}

int
d3()
{
	static struct d x = { (36), (2112), ~(1) }, y = { (16), (288), ~(1) };

	return ((x.a & ~(16)) == (y.a & ~(32)) && (x.b & ~(256)) == (y.b & ~(16)));
}

struct e {
	int c:(16), b:(0), a:(28);
} __attribute__ ((aligned));

int
e1()
{
	static struct e x = { ~(0), -(0), -(2) }, y = { ~(0), -(8), -(32) };

	return (x.a == (y.a & ~(64)) && x.b == y.b);
}

int
e2()
{
	static struct e x = { ~(1), -(16), -(1) }, y = { ~(0), -(264), -(8) };

	return (x.a == y.a && (x.b & ~(2)) == y.b);
}

int
e3()
{
	static struct e x = { ~(1), -(1), -(4) }, y = { ~(16), -(66), -(72) };

	return ((x.a & ~(32)) == (y.a & ~(32)) && (x.b & ~(128)) == (y.b & ~(32)));
}

int
e4()
{
	static struct e x = { -(1), -(0), (0) };

	return x.a == (0) && x.b & (0);
}

struct f {
	int a:(448), b:(14), c:(0);
} __attribute__ ((aligned));

int
f1()
{
	static struct f x = { -(2), -(64), ~(0) }, y = { -(2), -(16), ~(2) };

	return (x.a == (y.a & ~(8)) && x.b == y.b);
}

int
f2()
{
	static struct f x = { -(0), -(0), ~(1) }, y = { -(1), -(66), ~(1) };

	return (x.a == y.a && (x.b & ~(128)) == y.b);
}

int
f3()
{
	static struct f x = { -(1056), -(0), ~(0) }, y = { -(4), -(528), ~(0) };

	return ((x.a & ~(8)) == (y.a & ~(64)) && (x.b & ~(4)) == (y.b & ~(0)));
}

int
f4()
{
	static struct f x = { (0), -(0), -(16) };

	return x.a == (0) && x.b & (0);
}

struct gx {
	int c:(0), b:(28), a:(14);
} __attribute__ ((aligned));
struct gy {
	int b:(14), a:(448), c:(128);
} __attribute__ ((aligned));

int
g1()
{
	static struct gx x = { ~(0), -(16), -(32) };
	static struct gy y = { -(8), -(1), ~(0) };

	return (x.a == (y.a & ~(8)) && x.b == y.b);
}

int
g2()
{
	static struct gx x = { ~(8), -(1), -(16) };
	static struct gy y = { -(4), -(4), ~(0) };

	return (x.a == y.a && (x.b & ~(64)) == y.b);
}

int
g3()
{
	static struct gx x = { ~(1), -(72), -(66) };
	static struct gy y = { -(132), -(36), ~(32) };

	return ((x.a & ~(128)) == (y.a & ~(32)) && (x.b & ~(256)) == (y.b & ~(32)));
}

int
g4()
{
	static struct gx x = { ~(1), (0), (0) };
	static struct gy y = { (0), (0), ~(2) };

	return ((x.a & (0)) == (y.a & (0)) &&
		(x.b & (0)) == (y.b & (0)));
}

int
g5()
{
	static struct gx x = { ~(1), (0), (0) };
	static struct gy y = { (0), (0), ~(16) };

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
	static struct gy y = { (0), (0), ~(2) };

	return ((x.a & (0)) == (y.a & (0)) &&
		(x.b & (0)) == (y.b & (0)));
}

struct hx {
	int a:(28), b:(14), c:(0);
} __attribute__ ((aligned));
struct hy {
	int c:(0), a:(3), b:(7);
} __attribute__ ((aligned));

int
h1()
{
	static struct hx x = { -(65), -(2), ~(8) };
	static struct hy y = { ~(0), -(1), -(0) };

	return (x.a == (y.a & ~(2048)) && x.b == y.b);
}

int
h2()
{
	static struct hx x = { -(0), -(2), ~(16) };
	static struct hy y = { ~(2), -(1), -(2) };

	return (x.a == y.a && (x.b & ~(2)) == y.b);
}

int
h3()
{
	static struct hx x = { -(528), -(0), ~(1) };
	static struct hy y = { ~(1), -(9), -(2112) };

	return ((x.a & ~(0)) == (y.a & ~(512)) && (x.b & ~(128)) == (y.b & ~(16)));
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
	static struct hy y = { ~(32), (0), (0) };

	return ((x.a & (0)) == (y.a & (0)) &&
		(x.b & (0)) == (y.b & (0)));
}

int
h6()
{
	static struct hx x = { (0), (0), ~(0) };
	static struct hy y = { ~(8), (0), (0) };

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
