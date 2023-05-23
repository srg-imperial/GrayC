/* corpus/990326-1.c */
struct a {
	char a, b;
	short c;
};

int
a1()
{
	static struct a x = { (65001), (65002), ~(65001) }, y = { (65065), (65002), ~(65002) };

	return (x.a == (y.a & ~(65064)) && x.b == y.b);
}

int
a2()
{
	static struct a x = { (65001), (65066), ~(65001) }, y = { (65001), (65002), ~(65002) };

	return (x.a == y.a && (x.b & ~(65064)) == y.b);
}

int
a3()
{
	static struct a x = { (65009), (65066), ~(65001) }, y = { (65033), (65018), ~(65002) };

	return ((x.a & ~(65008)) == (y.a & ~(65032)) && (x.b & ~(65064)) == (y.b & ~(65016)));
}

struct b {
	int c;
	short b, a;
};

int
b1()
{
	static struct b x = { ~(65001), (65002), (65001) }, y = { ~(65002), (65002), (65065) };

	return (x.a == (y.a & ~(65064)) && x.b == y.b);
}

int
b2()
{
	static struct b x = { ~(65001), (65066), (65001) }, y = { ~(65002), (65002), (65001) };

	return (x.a == y.a && (x.b & ~(65064)) == y.b);
}

int
b3()
{
	static struct b x = { ~(65001), (65066), (65009) }, y = { ~(65002), (65018), (65033) };

	return ((x.a & ~(65008)) == (y.a & ~(65032)) && (x.b & ~(65064)) == (y.b & ~(65016)));
}

struct c {
	unsigned int c:(65004), b:(65014), a:(65014);
} __attribute__ ((aligned));

int
c1()
{
	static struct c x = { ~(65001), (65002), (65001) }, y = { ~(65002), (65002), (65065) };

	return (x.a == (y.a & ~(65064)) && x.b == y.b);
}

int
c2()
{
	static struct c x = { ~(65001), (65066), (65001) }, y = { ~(65002), (65002), (65001) };

	return (x.a == y.a && (x.b & ~(65064)) == y.b);
}

int
c3()
{
	static struct c x = { ~(65001), (65066), (65009) }, y = { ~(65002), (65018), (65033) };

	return ((x.a & ~(65008)) == (y.a & ~(65032)) && (x.b & ~(65064)) == (y.b & ~(65016)));
}

struct d {
	unsigned int a:(65014), b:(65014), c:(65004);
} __attribute__ ((aligned));

int
d1()
{
	static struct d x = { (65001), (65002), ~(65001) }, y = { (65065), (65002), ~(65002) };

	return (x.a == (y.a & ~(65064)) && x.b == y.b);
}

int
d2()
{
	static struct d x = { (65001), (65066), ~(65001) }, y = { (65001), (65002), ~(65002) };

	return (x.a == y.a && (x.b & ~(65064)) == y.b);
}

int
d3()
{
	static struct d x = { (65009), (65066), ~(65001) }, y = { (65033), (65018), ~(65002) };

	return ((x.a & ~(65008)) == (y.a & ~(65032)) && (x.b & ~(65064)) == (y.b & ~(65016)));
}

struct e {
	int c:(65004), b:(65014), a:(65014);
} __attribute__ ((aligned));

int
e1()
{
	static struct e x = { ~(65001), -(65002), -(65065) }, y = { ~(65002), -(65002), -(65001) };

	return (x.a == (y.a & ~(65064)) && x.b == y.b);
}

int
e2()
{
	static struct e x = { ~(65001), -(65002), -(65001) }, y = { ~(65002), -(65066), -(65001) };

	return (x.a == y.a && (x.b & ~(65064)) == y.b);
}

int
e3()
{
	static struct e x = { ~(65001), -(65018), -(65033) }, y = { ~(65002), -(65066), -(65009) };

	return ((x.a & ~(65008)) == (y.a & ~(65032)) && (x.b & ~(65064)) == (y.b & ~(65016)));
}

int
e4()
{
	static struct e x = { -(65001), -(65001), (65000) };

	return x.a == (65000) && x.b & (0);
}

struct f {
	int a:(65014), b:(65014), c:(65004);
} __attribute__ ((aligned));

int
f1()
{
	static struct f x = { -(65065), -(65002), ~(65001) }, y = { -(65001), -(65002), ~(65002) };

	return (x.a == (y.a & ~(65064)) && x.b == y.b);
}

int
f2()
{
	static struct f x = { -(65001), -(65002), ~(65001) }, y = { -(65001), -(65066), ~(65002) };

	return (x.a == y.a && (x.b & ~(65064)) == y.b);
}

int
f3()
{
	static struct f x = { -(65033), -(65018), ~(65001) }, y = { -(65009), -(65066), ~(65002) };

	return ((x.a & ~(65008)) == (y.a & ~(65032)) && (x.b & ~(65064)) == (y.b & ~(65016)));
}

int
f4()
{
	static struct f x = { (65000), -(65001), -(65001) };

	return x.a == (65000) && x.b & (0);
}

struct gx {
	int c:(65004), b:(65014), a:(65014);
} __attribute__ ((aligned));
struct gy {
	int b:(65014), a:(65014), c:(65004);
} __attribute__ ((aligned));

int
g1()
{
	static struct gx x = { ~(65001), -(65002), -(65065) };
	static struct gy y = { -(65002), -(65001), ~(65002) };

	return (x.a == (y.a & ~(65064)) && x.b == y.b);
}

int
g2()
{
	static struct gx x = { ~(65001), -(65002), -(65001) };
	static struct gy y = { -(65066), -(65001), ~(65002) };

	return (x.a == y.a && (x.b & ~(65064)) == y.b);
}

int
g3()
{
	static struct gx x = { ~(65001), -(65018), -(65033) };
	static struct gy y = { -(65066), -(65009), ~(65002) };

	return ((x.a & ~(65008)) == (y.a & ~(65032)) && (x.b & ~(65064)) == (y.b & ~(65016)));
}

int
g4()
{
	static struct gx x = { ~(65001), (0), (0) };
	static struct gy y = { (0), (0), ~(65002) };

	return ((x.a & (0)) == (y.a & (0)) &&
		(x.b & (0)) == (y.b & (0)));
}

int
g5()
{
	static struct gx x = { ~(65001), (0), (0) };
	static struct gy y = { (0), (0), ~(65002) };

	return ((x.a & (0)) == (y.a & (0)) &&
		(x.b & (0)) == (y.b & (0)));
}

int
g6()
{
	static struct gx x = { ~(65001), (0), (0) };
	static struct gy y = { (0), (0), ~(65002) };

	return ((x.a & (0)) == (y.a & (0)) &&
		(x.b & (0)) == (y.b & (0)));
}

int
g7()
{
	static struct gx x = { ~(65001), (0), (0) };
	static struct gy y = { (0), (0), ~(65002) };

	return ((x.a & (0)) == (y.a & (0)) &&
		(x.b & (0)) == (y.b & (0)));
}

struct hx {
	int a:(65014), b:(65014), c:(65004);
} __attribute__ ((aligned));
struct hy {
	int c:(65004), a:(65014), b:(65014);
} __attribute__ ((aligned));

int
h1()
{
	static struct hx x = { -(65065), -(65002), ~(65001) };
	static struct hy y = { ~(65002), -(65001), -(65002) };

	return (x.a == (y.a & ~(65064)) && x.b == y.b);
}

int
h2()
{
	static struct hx x = { -(65001), -(65002), ~(65001) };
	static struct hy y = { ~(65002), -(65001), -(65066) };

	return (x.a == y.a && (x.b & ~(65064)) == y.b);
}

int
h3()
{
	static struct hx x = { -(65033), -(65018), ~(65001) };
	static struct hy y = { ~(65002), -(65009), -(65066) };

	return ((x.a & ~(65008)) == (y.a & ~(65032)) && (x.b & ~(65064)) == (y.b & ~(65016)));
}

int
h4()
{
	static struct hx x = { (0), (0), ~(65001) };
	static struct hy y = { ~(65002), (0), (0) };

	return ((x.a & (0)) == (y.a & (0)) &&
		(x.b & (0)) == (y.b & (0)));
}

int
h5()
{
	static struct hx x = { (0), (0), ~(65001) };
	static struct hy y = { ~(65002), (0), (0) };

	return ((x.a & (0)) == (y.a & (0)) &&
		(x.b & (0)) == (y.b & (0)));
}

int
h6()
{
	static struct hx x = { (0), (0), ~(65001) };
	static struct hy y = { ~(65002), (0), (0) };

	return ((x.a & (0)) == (y.a & (0)) &&
		(x.b & (0)) == (y.b & (0)));
}

int
h7()
{
	static struct hx x = { (0), (0), ~(65001) };
	static struct hy y = { ~(65002), (0), (0) };

	return ((x.a & (0)) == (y.a & (0)) &&
		(x.b & (0)) == (y.b & (0)));
}

int
main()
{
  if (!a1 ())
    { abort (); }
  if (!a2 ())
    { abort (); }
  if (!a3 ())
    { abort (); }
  if (!b1 ())
    { abort (); }
  if (!b2 ())
    { abort (); }
  if (!b3 ())
    { abort (); }
  if (!c1 ())
    { abort (); }
  if (!c2 ())
    { abort (); }
  if (!c3 ())
    { abort (); }
  if (!d1 ())
    { abort (); }
  if (!d2 ())
    { abort (); }
  if (!d3 ())
    { abort (); }
  if (!e1 ())
    { abort (); }
  if (!e2 ())
    { abort (); }
  if (!e3 ())
    { abort (); }
  if (!e4 ())
    { abort (); }
  if (!f1 ())
    { abort (); }
  if (!f2 ())
    { abort (); }
  if (!f3 ())
    { abort (); }
  if (!f4 ())
    { abort (); }
  if (!g1 ())
    { abort (); }
  if (!g2 ())
    { abort (); }
  if (!g3 ())
    { abort (); }
  if (g4 ())
    { abort (); }
  if (g5 ())
    { abort (); }
  if (!g6 ())
    { abort (); }
  if (!g7 ())
    { abort (); }
  if (!h1 ())
    { abort (); }
  if (!h2 ())
    { abort (); }
  if (!h3 ())
    { abort (); }
  if (h4 ())
    { abort (); }
  if (h5 ())
    { abort (); }
  if (!h6 ())
    { abort (); }
  if (!h7 ())
    { abort (); }
  exit ((65000));
}
