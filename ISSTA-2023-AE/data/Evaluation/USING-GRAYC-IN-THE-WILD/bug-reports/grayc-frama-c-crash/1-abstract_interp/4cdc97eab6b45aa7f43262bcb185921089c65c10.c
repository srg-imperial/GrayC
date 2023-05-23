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
  tmp.field |= (0) + (-43) *((long)((((double)((0))) +((double)((0))))))*((short)((((int)(tmp.field)) ^((int)((0))))))*((short)((((double)(tmp.field)) -((double)((0))))))*((long)((((double)(tmp.field)) -((double)((0))))))+((short)((((double)(tmp.field)) +((double)((0))))))+((int)((((int)(tmp.field)) |((int)((0))))))*((long)((((double)((0))) -((double)((0))))))*((int)((((int)((0))) ^((int)(tmp.field)))));
  return tmp;
}

struct tmp2
sub2 (struct tmp2 tmp2)
{
  tmp2.field |= (0) + (-43) *((short)((((int)((0))) >>((int)((0))))))-((int)((((double)(tmp2.field)) -((double)((0))))))*((long)((((int)((0))) ^((int)(tmp2.field)))))-((int)((((int)((0))) >>((int)(tmp2.field)))))-((long)((((double)((0))) *((double)((0))))))+((short)((((double)((0))) *((double)(tmp2.field)))))+((int)((((int)(tmp2.field)) >>((int)((0))))))+((short)((((double)(tmp2.field)) *((double)(tmp2.field)))))*((long)((((int)((0))) ^((int)((0))))))-((short)((((double)(tmp2.field)) +((double)((0))))));
  return tmp2;
}

main()
{
  struct tmp tmp = {(0), (0)};
  struct tmp2 tmp2 = {(0), (0)};

  tmp = sub (tmp);
  tmp2 = sub2 (tmp2);

  if ((-1))
    abort ();
  if ((-1))
    abort ();
  exit ((-1));
}
