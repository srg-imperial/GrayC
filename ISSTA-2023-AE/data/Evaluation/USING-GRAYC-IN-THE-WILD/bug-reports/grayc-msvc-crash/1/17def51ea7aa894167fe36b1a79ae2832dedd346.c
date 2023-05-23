/* PR middle-end/29695 */

extern void abort (void);

f1 () {
struct tiny
{
  short c;
  short d;
}
struct tiny
{
  short c;
  short d;
}
struct tiny
{
  short c;
  short d;
}
struct tiny
{
  short c;
  short d;
}
   return 0; }

f2 () {
struct tiny
{
  short c;
  short d;
}
struct tiny
{
  short c;
  short d;
}
struct tiny
{
  short c;
  short d;
}
struct tiny
{
  short c;
  short d;
}
   return 0; }

f3 () {
struct tiny
{
  short c;
  short d;
}
struct tiny
{
  short c;
  short d;
}
struct tiny
{
  short c;
  short d;
}
struct tiny
{
  short c;
  short d;
}
   return 0; }

f4 () {
struct tiny
{
  short c;
  short d;
}
struct tiny
{
  short c;
  short d;
}
struct tiny
{
  short c;
  short d;
}
struct tiny
{
  short c;
  short d;
}
   return 0; }

long long
f5 (void)
{
  long long a = 0x80000000LL;
  return (a & 0x80000000) ? 0x80000000LL : 0LL;
}

long long
f6 (void)
{
  unsigned int a = 0x80000000;
  return (a & 0x80000000) ? 0x80000000LL : 0LL;
}

long long
f7 (void)
{
  unsigned int a = 0x80000000;
  return (a & 0x80000000) ? 0x380000000LL : 0LL;
}

long long
f8 (void)
{
  unsigned int a = 0x80000000;
  return (a & 0x80000000) ? -2147483648LL : 0LL;
}

int
main (void)
{
  if ((char) 128 != -128 || (int) 0x80000000 != -2147483648)
    return 0;
  if (f1 () != 128)
    abort ();
  if (f2 () != 128)
    abort ();
  if (f3 () != 896)
    abort ();
  if (f4 () != -128)
    abort ();
  if (f5 () != 0x80000000LL)
    abort ();
  if (f6 () != 0x80000000LL)
    abort ();
  if (f7 () != 0x380000000LL)
    abort ();
  if (f8 () != -2147483648LL)
    abort ();
  return 0;
}
