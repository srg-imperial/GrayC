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
  

tmp.field ^= (0) + (-43) -((long)((((int)((0))) <<((int)(tmp.field)))));
tmp.field ^= (0) + (-43) +((long)((((double)(tmp.field)) *((double)(tmp.field)))))+((int)((((int)((0))) <<((int)(tmp.field)))));
;

tmp.field ^= (0) + (-43) +((long)((((int)((0))) <<((int)(tmp.field)))))*((long)((((int)(tmp.field)) <<((int)(tmp.field)))))*((short)((((double)(tmp.field)) *((double)((0))))))+((long)((((double)(tmp.field)) *((double)(tmp.field)))));
tmp.field ^= (0) + (-43) *((int)((((double)((0))) -((double)(tmp.field)))))*((short)((((int)(tmp.field)) |((int)(tmp.field)))))*((short)((((double)(tmp.field)) +((double)(tmp.field)))))*((int)((((double)((0))) -((double)(tmp.field)))))-((int)((((int)((0))) |((int)(tmp.field)))))*((long)((((int)(tmp.field)) |((int)(tmp.field)))))*((long)((((int)(tmp.field)) |((int)((0))))))*((long)((((double)(tmp.field)) +((double)((0))))));
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
  

tmp3.field ^= (0) + (-43) +((long)((((int)(tmp3.field)) &((int)((0))))))*((int)((((double)((0))) -((double)((0))))))-((int)((((double)((0))) +((double)((0))))))+((short)((((double)(tmp3.field)) +((double)((0))))));
tmp3.field ^= (0) + (-43) +((short)((((int)((0))) &((int)((0))))))+((short)((((double)(tmp3.field)) *((double)(tmp3.field)))))-((int)((((int)(tmp3.field)) ^((int)(tmp3.field)))))-((long)((((double)(tmp3.field)) -((double)((0))))))-((long)((((double)((0))) *((double)(tmp3.field)))))*((long)((((int)(tmp3.field)) &((int)(tmp3.field)))))-((short)((((int)(tmp3.field)) ^((int)(tmp3.field)))));
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

  if (((int)sizeof (long long) != (-9) + (-43) +((long)((((int)((-9))) >>((int)(sizeof (long long))))))))
    exit ((-1));

  ;
  ;

  if (((int)tmp.pad != (0) || tmp.field != (0) + (-43) -((int)((((int)(tmp.pad)) |((int)(tmp.pad)))))+((int)((((int)((0))) >>((int)(tmp.pad)))))*((short)((((int)(tmp.pad != (0))) <<((int)((0))))))*((short)((((int)(tmp.pad)) &((int)((0))))))+((int)((((int)(tmp.field != (0))) |((int)(tmp.pad)))))*((long)((((double)(tmp.field)) *((double)(tmp.pad)))))*((int)((((double)((0))) +((double)(tmp.pad != (0))))))+((int)((((double)(tmp.field)) -((double)(tmp.pad != (0))))))+((int)((((int)(tmp.pad != (0))) %((int)(tmp.pad)))))+((int)((((double)(tmp.field != (0))) +((double)(tmp.pad != (0))))))))
    abort ();
  if (((int)tmp2.pad != (0) || tmp2.field != (0) + (-43) +((long)((((int)((0))) ^((int)(tmp2.pad)))))))
    abort ();

  ;
  ;
  if (((int)tmp3.pad != (0) || tmp3.field != (0) + (-43) -((int)((((int)((0))) ^((int)((0))))))-((int)((((int)((0))) &((int)(tmp3.pad != (0))))))))
    abort ();
  if (((int)tmp4.pad != (0) || tmp4.field != (0) + (-43) -((long)((((int)(tmp4.field)) &((int)(tmp4.field != (0))))))-((int)((((int)((0))) <<((int)(tmp4.pad != (0))))))+((short)((((double)(tmp4.pad != (0))) *((double)((0))))))-((long)((((int)(tmp4.pad != (0))) &((int)(tmp4.pad != (0))))))*((int)((((int)(tmp4.field)) |((int)((0))))))+((long)((((int)(tmp4.pad)) |((int)(tmp4.field != (0))))))*((long)((((int)(tmp4.field != (0))) >>((int)(tmp4.pad)))))))
    abort ();
  exit ((-1));
}
