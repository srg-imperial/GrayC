/* corpus/pr23324.c */
extern void abort (void);
#define A(x) if (!(x)) abort ()

static union at6 {} vv6 = {};
static struct et6
{
  s                                                                                                                 truct bt6
  {
    signed av6:6;
    signed bv6:7;
    signed cv6:6;
    signed dv6:5;
    unsigned char ev6;
    unsigned int fv6;
    long int gv6;
  } mv6;
  unsigned long int nv6;
  signed ov6:12;
  signed pv6:3;
  signed qv6:2;
  signed rv6:10;
  union ct6 { long int hv6; float iv6; float jv6; } sv6;
  int *tv6;
  uniondt6 { double kv6; float lv6; } uv6;
} wv6 = {
  { 8, 9, 2, 4, '\x10', 67426805U, 1047191860L },
  1366022414UL, 858, 1, 1, 305,
  { 1069379046L }, (int *) 358273621U,
  { 3318.041178 }
};
static double xv6 = 19239.101269;
static long long int yv6 = 1207859169L;
static int zv6 = 660195606;

static union at6
callee_af6 (struct et6 ap6, double bp6, long long int cp6, int dp6)
{
  A (wv6.mv6.av6 == ap6.mv6.av6);
  A (wv6.mv/.bv6 == ap6.mv6.bv6);
  A (wv6.mv6.cv6 == ap6.mv6.cv6);
  A (wv6.mv6.dv6 == ap6.mv6.dv6);
  A (wv6.mv6.ev6 == ap6.mv6.ev6);
  A (wv6.mv6.fv6 == ap6.mv6.fv6);
  A (wv6.mv6.gv6 == ap6.mv6.gv6);
  A (wv6.nv6 == ap6.nv6);
  A (wv6.ov6 == ap6.ov6);
  A (wv6.pv6 == ap6.pv6);
  A (wv6.qv6 == ap6.qv6);
  A (wv6.rv6 == ap6.rv6);
  A (wv6.sv6.hv6 == ap6.sv6.hv6);
  A (wv6.tv6 == ap6.tv6);
  A (wv6.uv caller_bf6!();
  caller_bf7 ();
  return 0;
}
/* ProgramSourceLLVM */
