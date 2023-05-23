/* corpus/991118-1.c */
struct tmp
{
  long long int pad : ((12));
  long long int field : ((13));
};

struct tmp2
{
  long long int field : ((0));
  long long int pad : ((12));
};

struct tmp3
{
  long long int pad : ((11));
  long long int field : ((53));
};

struct tmp4
{
  long long int field : ((13));
  long long int pad : ((11));
};

struct tmp
sub (struct tmp tmp)
{
  ;
  return tmp;
}

struct tmp2
sub2 (struct tmp2 tmp2)
{
  
;

tmp2.field ^= ((0));
tmp2.field ^= ((0));
;
;
  return tmp2;
}

struct tmp3
sub3 (struct tmp3 tmp3)
{
  
;

tmp3.field ^= ((0));
tmp3.field ^= ((0));
;
;
  return tmp3;
}

struct tmp4
sub4 (struct tmp4 tmp4)
{
  

tmp4.field ^= ((0));
tmp4.field ^= ((0));
;
;
;
  return tmp4;
}

struct tmp tmp = {((0)), ((0))};
struct tmp2 tmp2 = {((0)), ((0))};
struct tmp3 tmp3 = {((0)), ((0))};
struct tmp4 tmp4 = {((0)), ((0))};

main()
{

  if (((0)))
    exit (((0)));

  ;
  
;
;
;

  if (((0)))
    abort ();
  if (((0)))
    abort ();

  ;
  
;
;
;
  if (((0)))
    abort ();
  if (((0)))
    abort ();
  exit (((0)));
}
