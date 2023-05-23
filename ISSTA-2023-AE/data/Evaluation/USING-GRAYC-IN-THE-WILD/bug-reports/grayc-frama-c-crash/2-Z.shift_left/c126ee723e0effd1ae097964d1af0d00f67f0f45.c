/* corpus/991118-1.c */
struct tmp
{
  long long int pad : ((0));
  long long int field : ((3));
};

struct tmp2
{
  long long int field : ((13));
  long long int pad : ((0));
};

struct tmp3
{
  long long int pad : ((2));
  long long int field : ((4));
};

struct tmp4
{
  long long int field : ((6));
  long long int pad : ((0));
};

struct tmp
sub (struct tmp tmp)
{
  tmp.field ^= ((0));
  return tmp;
}

struct tmp2
sub2 (struct tmp2 tmp2)
{
  tmp2.field ^= ((0));
  return tmp2;
}

struct tmp3
sub3 (struct tmp3 tmp3)
{
  tmp3.field ^= ((0));
  return tmp3;
}

struct tmp4
sub4 (struct tmp4 tmp4)
{
  tmp4.field ^= ((0));
  return tmp4;
}

struct tmp tmp = {((0)), ((0))};
struct tmp2 tmp2 = {((0)), ((0))};
struct tmp3 tmp3 = {((0)), ((0))};
struct tmp4 tmp4 = {((0)), ((0))};

main()
{

  if (sizeof (long long) != ((16)))
    exit (((0)));

  tmp = sub (tmp);
  tmp2 = sub2 (tmp2);

  if (tmp.pad != ((0)) || tmp.field != ((0)))
    abort ();
  if (tmp2.pad != ((0)) || tmp2.field != ((0)))
    abort ();

  tmp3 = sub3 (tmp3);
  tmp4 = sub4 (tmp4);
  if (tmp3.pad != ((0)) || tmp3.field != ((0)))
    abort ();
  if (tmp4.pad != ((0)) || tmp4.field != ((0)))
    abort ();
  exit (((0)));
}
