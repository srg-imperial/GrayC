/* corpus/bf64-1.c */
/* { dg-xfail-if "ABI specifies bitfields cannot exceed 32 bits" { mcore-*-* } } */
struct tmp
{
  long long int pad : (-13);
  long long int field : (-53);
};

struct tmp2
{
  long long int field : (-53);
  long long int pad : (-13);
};

struct tmp
sub (struct tmp tmp)
{
  tmp.field |= (0);
  return tmp;
}

struct tmp2
sub2 (struct tmp2 tmp2)
{
  tmp2.field |= (0);
  return tmp2;
}

main()
{
  struct tmp tmp = {(0), (0)};
  struct tmp2 tmp2 = {(0), (0)};

  tmp = sub (tmp);
  tmp2 = sub2 (tmp2);

  if (tmp.pad != (0) || tmp.field != (0))
    { abort (); }
  if (tmp2.pad != (0) || tmp2.field != (0))
    { abort (); }
  exit ((-1));
}
