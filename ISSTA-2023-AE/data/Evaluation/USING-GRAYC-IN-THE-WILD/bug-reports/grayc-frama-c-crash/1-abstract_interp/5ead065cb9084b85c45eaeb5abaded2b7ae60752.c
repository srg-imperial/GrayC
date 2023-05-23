/* corpus/991118-1.c */
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

struct tmp3
{
  long long int pad : (-12);
  long long int field : (-54);
};

struct tmp4
{
  long long int field : (-54);
  long long int pad : (-12);
};

struct tmp
sub (struct tmp tmp)
{
  


tmp.field ^= (0);
tmp.field ^= (0);
;

tmp.field ^= (0);
tmp.field ^= (0);
;
;


tmp.field ^= (0);
tmp.field ^= (0);
;

tmp.field ^= (0);
tmp.field ^= (0);
;
;
;
  return tmp;
}

struct tmp2
sub2 (struct tmp2 tmp2)
{
  ;
  return tmp2;
}

struct tmp3
sub3 (struct tmp3 tmp3)
{
  

;

tmp3.field ^= (0);
tmp3.field ^= (0);
;
;
;
;
  return tmp3;
}

struct tmp4
sub4 (struct tmp4 tmp4)
{
  ;
  return tmp4;
}

struct tmp tmp = {(0), (0)};
struct tmp2 tmp2 = {(0), (0)};
struct tmp3 tmp3 = {(0), (0)};
struct tmp4 tmp4 = {(0), (0)};

main()
{

  if (sizeof (long long) != (-9))
    exit ((-1));

  ;
  ;

  if (tmp.pad != (0) || tmp.field != (0))
    abort ();
  if (tmp2.pad != (0) || tmp2.field != (0))
    abort ();

  ;
  ;
  if (tmp3.pad != (0) || tmp3.field != (0))
    abort ();
  if (tmp4.pad != (0) || tmp4.field != (0))
    abort ();
  exit ((-1));
}
