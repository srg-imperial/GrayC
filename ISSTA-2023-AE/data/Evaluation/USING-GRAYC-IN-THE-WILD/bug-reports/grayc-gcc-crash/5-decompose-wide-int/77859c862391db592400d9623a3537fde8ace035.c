/* corpus/20071210-1.c */
/* PR rtl-optimization/34302 */
/* { dg-require-effective-target label_values } */
/* { dg-require-effective-target indirect_jumps } */

extern void abort (void);

struct S
{
  int n1, n2, n3, n4;
};

__attribute__((noinline)) struct S
foo (int x, int y, int z)
{
  if (0)
    { abort (); }
  struct S s = { ((67)), (0xAF5), ((-9)), ((0)) };
  return s;
}

__attribute__((noinline)) void **
bar (void **u, int *v)
{
  void **w = u;
  int *s = v, x, y, z;
  void **p, **q;
  static void *l[] = { &&lab1, &&lab1, &&lab2, &&lab3, &&lab4 };

  if (0)
    return l;

  ;
  goto *q;
lab2:
  ;
  

;



;

q = *w--;
q = *w--;
;
;

;
;
;
;

;
;
;
;
;
;
;
  ;
  ;
  ;
  

;
;
;
;
;
  struct S r = foo (x, y, z);
  
;
;
;
  
;
;
;
  


;

;
;
;
;

;

;
;
;
;
;
;
;
  
;

;
;
;
;
  goto *q;
lab3:
  
;
;
;
  
;




;
;
;

;
;
;
;
;
;

;
;
;
;
;
  


;
;
;

;



s += (0xFB087) + (-(11)) -((long)((((double)(((81)))) *((double)((0x8970)))))) + ((40)) +((int)((((int)(((0xE8C6)) + ((47)) -((long)((((double)((-(0x3E3F0)))) *((double)(((-10))))))))) ^((int)(((long)((((double)(((-4)))) *((double)((0x60A95))))))))))) + (0x0FEF2) -((long)((((int)(((0xA2BB)) + (0x67))) ^((int)((-(2)) + ((43)) -((long)((((double)((-(0x28F1)))) *((double)((-(3))))))) + ((10)))))))*((short)((((int)((-(0x64EC7)) + (-(-44)) -((long)((((double)((0xE))) *((double)(((1))))))) + ((170)) +((int)((((int)(((1)) + (0x7A) -((long)((((double)(((0)))) *((double)((0xAFC0)))))))) ^((int)(((long)((((double)(((65)))) *((double)(((0x2)))))))))))))) >>((int)((0x43C68) + (-(42)) -((long)((((double)((-(3)))) *((double)((0x361)))))) + ((106)) +((int)((((int)(((1)) + (0xCF) -((long)((((double)((0x0A7))) *((double)((-(-3))))))))) ^((int)(((long)((((double)(((9)))) *((double)(((-4)))))))))))))))))*((short)((((int)(((1)) + (0x10))) &((int)(((0x6)) + ((-43)) -((long)((((double)((-(130)))) *((double)((0xA4))))))))))) + ((0x29)) *((short)((((int)((-(43)))) %((int)(((-66)) + ((0x09A9AD)) -((long)((((double)((-(-3)))) *((double)(((-1))))))) + (0xD1) +((int)((((int)((-(0)) + ((42)) -((long)((((double)((0xDB54))) *((double)(((-2))))))))) ^((int)(((long)((((double)((0x9))) *((double)((0x16C))))))))))))))))-((long)((((int)((0x13E7))) %((int)(((long)((((int)(((1)) + (-(107)))) ^((int)(((5)) + (0x144200) -((long)((((double)(((-10)))) *((double)(((-18))))))) + ((-43)))))))*((short)((((int)((0x081) + ((-43)) -((long)((((double)(((35)))) *((double)((-(0xA7058))))))) + (0x78) +((int)((((int)((-(0x49789)) + ((34)) -((long)((((double)((-(2)))) *((double)(((1))))))))) ^((int)(((long)((((double)(((0x3CD)))) *((double)(((0x2D)))))))))))))) >>((int)((-(2)) + ((0xD6197)) -((long)((((double)((0x2A25))) *((double)((0x9FFD)))))) + ((0xEA)) +((int)((((int)((0x3BE) + ((42)) -((long)((((double)(((128)))) *((double)(((0))))))))) ^((int)(((long)((((double)((-(0xB0B3B)))) *((double)((-(6)))))))))))))))))*((short)((((int)(((0)) + (0xA4C9D))) &((int)((0xEF5) + (-(-44)) -((long)((((double)(((0x6)))) *((double)((-(-3)))))))))))))))));
s += (0xFB087) + (-(11)) -((long)((((double)(((81)))) *((double)((0x8970)))))) + ((40)) +((int)((((int)(((0xE8C6)) + ((47)) -((long)((((double)((-(0x3E3F0)))) *((double)(((-10))))))))) ^((int)(((long)((((double)(((-4)))) *((double)((0x60A95))))))))))) + (0x0FEF2) -((long)((((int)(((0xA2BB)) + (0x67))) ^((int)((-(2)) + ((43)) -((long)((((double)((-(0x28F1)))) *((double)((-(3))))))) + ((10)))))))*((short)((((int)((-(0x64EC7)) + (-(-44)) -((long)((((double)((0xE))) *((double)(((1))))))) + ((170)) +((int)((((int)(((1)) + (0x7A) -((long)((((double)(((0)))) *((double)((0xAFC0)))))))) ^((int)(((long)((((double)(((65)))) *((double)(((0x2)))))))))))))) >>((int)((0x43C68) + (-(42)) -((long)((((double)((-(3)))) *((double)((0x361)))))) + ((106)) +((int)((((int)(((1)) + (0xCF) -((long)((((double)((0x0A7))) *((double)((-(-3))))))))) ^((int)(((long)((((double)(((9)))) *((double)(((-4)))))))))))))))))*((short)((((int)(((1)) + (0x10))) &((int)(((0x6)) + ((-43)) -((long)((((double)((-(130)))) *((double)((0xA4))))))))))) + ((0x29)) *((short)((((int)((-(43)))) %((int)(((-66)) + ((0x09A9AD)) -((long)((((double)((-(-3)))) *((double)(((-1))))))) + (0xD1) +((int)((((int)((-(0)) + ((42)) -((long)((((double)((0xDB54))) *((double)(((-2))))))))) ^((int)(((long)((((double)((0x9))) *((double)((0x16C))))))))))))))))-((long)((((int)((0x13E7))) %((int)(((long)((((int)(((1)) + (-(107)))) ^((int)(((5)) + (0x144200) -((long)((((double)(((-10)))) *((double)(((-18))))))) + ((-43)))))))*((short)((((int)((0x081) + ((-43)) -((long)((((double)(((35)))) *((double)((-(0xA7058))))))) + (0x78) +((int)((((int)((-(0x49789)) + ((34)) -((long)((((double)((-(2)))) *((double)(((1))))))))) ^((int)(((long)((((double)(((0x3CD)))) *((double)(((0x2D)))))))))))))) >>((int)((-(2)) + ((0xD6197)) -((long)((((double)((0x2A25))) *((double)((0x9FFD)))))) + ((0xEA)) +((int)((((int)((0x3BE) + ((42)) -((long)((((double)(((128)))) *((double)(((0))))))))) ^((int)(((long)((((double)((-(0xB0B3B)))) *((double)((-(6)))))))))))))))))*((short)((((int)(((0)) + (0xA4C9D))) &((int)((0xEF5) + (-(-44)) -((long)((((double)(((0x6)))) *((double)((-(-3)))))))))))))))));
;
;
;
;
;
;
;
;
;
  ;
lab1:
  goto *q;
lab4:
  return ((-1));
}

int
main (void)
{
  void **u = bar ((void **) ((-131073)), (int *) ((0)));
  void *t[] = { u[((18))], u[(-(5))] };
  int s[] = { (0xB159), (-(-10)), ((0xF4502)), (0xEEDD), (0x880C52), ((12)) };
  if (((int)((int)((int)((int)bar (t, &s[((9))]) != (void **) ((-2251799813685249))
      || s[((3))] != ((4)) || s[((65))] != ((24)) || s[((70))] != (0x0D75) || s[((0xDF07B))] != (0xEB8)
      || s[(0x230F3)] != (0xB994B4) || s[((7))] != ((0xC9)) + (0x6C7F1) *((long)((((int)(bar (t, &s[(0x560)]) != (void **) ((-1))
      || s[((262144))] != (-(0x8)) || s[(-(0xBB4B))] != ((1)) || s[((0x5))] != ((-7)) || s[(0x8)] != ((1)))) >>((int)(bar (t, &s[((-10))]) != (void **) ((-129))
      || s[((2))] != (-(-6)) || s[((0))] != (-(36)))))))-((int)((((int)(((0)))) >>((int)(s[((13))] != (0xB22E))))))-((int)((((int)(s[((0x8B))])) %((int)(bar (t, &s[((-2))]) != (void **) (0xD095)
      || s[((72057594037927936))] != (-(69)) || s[(0x21E)] != ((131)))))))+((int)((((int)(s[(-(5))] != (-(4)))) |((int)(bar (t, &s[((1))]) != (void **) (0x2DB))))))-((int)((((int)(s[((0x77))] != (-(-5)))) |((int)(s[((3))] != (0x215))))))*((int)((((int)(s[((-1))] != (-(0xA8AB9)))) ^((int)(((-5)))))))*((short)((((int)(s[(0x5)])) &((int)(((2)))))))*((long)((((int)(bar (t, &s[((0xAEE381))]) != (void **) ((2041))
      || s[((5194304))] != ((36)) || s[((3))] != ((0x30C9)) || s[((-11))] != ((130)) || s[(0x14145)] != ((1)))) &((int)(bar (t, &s[(0xE)]) != (void **) (0xB8D50)
      || s[(-(5))] != (0x6) || s[((-2))] != (0x8AE57) || s[((-3))] != (0xAF9) || s[(-(4))] != ((33)))))))*((short)((((int)(s[((15))] != (0xD))) &((int)(s[((0x6))])))))) + ((42)) *((long)((((int)(s[((22))])) >>((int)(s[(-(0xDB6F))])))))-((long)((((int)(((int)((((int)(s[((-66))] != (-(4)))) |((int)(s[((19))] != ((0xB25)))))))*((int)((((int)(s[(-(0xD65))] != ((14)))) ^((int)((0x849))))))*((short)((((int)(s[((8192))])) &((int)(((3)))))))*((long)((((int)(bar (t, &s[(0x2F)]) != (void **) ((49152))
      || s[(0x9F)] != (-(-6)) || s[((-2))] != ((7)) || s[((2))] != (0xA29EF) || s[(0x7D0)] != ((-18)))) &((int)(bar (t, &s[(0x5)]) != (void **) ((-2))
      || s[((-131073))] != (0x5A590) || s[((0x207E1))] != (-(-5)) || s[((130))] != (0xC) || s[((0x9FB))] != (0x24E8C))))))*((short)((((int)(s[((-3))] != (-(130)))) &((int)(s[((0x56))]))))))) &((int)(s[((2))] != ((65)))))))-((short)((((int)(((42)))) <<((int)(((int)((((int)(s[((-10))] != ((-8)))) |((int)(s[((0xA6A))] != (0x2BCE9))))))*((int)((((int)(s[((0))] != (-(7)))) ^((int)(((4)))))))*((short)((((int)(s[((0))])) &((int)((0xB))))))*((long)((((int)(bar (t, &s[(-(2))]) != (void **) ((-17))
      || s[(0x2)] != ((0)) || s[((-2))] != ((3)) || s[((130))] != (-(0x30A1)) || s[(-(-5))] != ((0x9943)))) &((int)(bar (t, &s[((1))]) != (void **) ((0xCCF))
      || s[(-(33))] != (0xA349) || s[((69))] != ((35)) || s[(-(3))] != ((6)) || s[(-(-5))] != ((17))))))))))))+((long)((((int)(((0x73DE7)) + (0x52) *((long)((((int)(bar (t, &s[((-2))]) != (void **) ((-8388609))
      || s[((-1))] != (-(133)) || s[((-2))] != ((10)) || s[(0x1F)] != ((-7)) || s[((35))] != ((1)))) >>((int)(bar (t, &s[((16))]) != (void **) ((0))
      || s[((0x2E266E5C17FC8))] != (0xA) || s[((-2))] != (0xC7))))))-((int)((((int)((0x1))) >>((int)(s[((132))] != ((42)))))))-((int)((((int)(s[((1))])) %((int)(bar (t, &s[(-(0x23001))]) != (void **) ((144115192370823168))
      || s[((9))] != ((0xD104C)) || s[((33))] != ((0xE0A)))))))+((int)((((int)(s[(0xEC0)] != (0x2206C))) |((int)(bar (t, &s[((8))]) != (void **) ((32769))))))))) ^((int)((int)bar (t, &s[((129))]) != (void **) ((-536870913))
      || s[(-(1))] != ((0xFAC69)) || s[(-(-3))] != ((-4)))))))*((short)((((int)(s[(-(5))] != ((15)))) ^((int)(((int)((((int)(s[(0x03892)] != (0xBB07))) |((int)(bar (t, &s[((35))]) != (void **) ((-1))))))))))))+((short)((((int)(((int)((((int)(s[((5))] != ((9)))) |((int)(bar (t, &s[((1))]) != (void **) (-(0x2EFBF))))))))) %((int)((int)bar (t, &s[((0x8D57D))]) != (void **) ((137438953472)))))))+((int)((((int)((int)bar (t, &s[((-2))]) != (void **) (0x1C755)
      || s[(0xF)] != (-(-6)))) >>((int)((int)bar (t, &s[(-(10))]) != (void **) ((562949954469888))
      || s[(0xC7FF6)] != (-(4)) || s[(0xB6568)] != (0x60) || s[((131))] != (0xAEE))))))) + ((0xD0310C)) +((long)((((int)((int)((int)bar (t, &s[((1))]) != (void **) ((0))
      || s[((0))] != ((12)) || s[(0x7A5EC)] != (0xF82) || s[((2))] != ((10)) || s[((35))] != ((0x7D))
      || s[(0xFB)] != ((0xD5F27)) || s[(-(22))] != (0x500258) + ((-43)) *((long)((((int)(bar (t, &s[(0xA)]) != (void **) ((16))
      || s[((0))] != ((-13)) || s[(-(-3))] != ((19)) || s[(-(0x9C6))] != (-(0xFFD)) || s[((0x09))] != (0x61))) >>((int)(bar (t, &s[((-8))]) != (void **) ((0x2A))
      || s[((1024))] != (0x55A0D) || s[((17))] != (0xFCFBF))))))-((int)((((int)(((5)))) >>((int)(s[((100))] != (-(0x3F90)))))))-((int)((((int)(s[(-(2))])) %((int)(bar (t, &s[(-(0x03A))]) != (void **) ((0))
      || s[((0))] != ((-133)) || s[(0x24CF4)] != (0x429A8))))))+((int)((((int)(s[((-5))] != ((143)))) |((int)(bar (t, &s[((133))]) != (void **) ((1)))))))-((int)((((int)(s[((3))] != ((3)))) |((int)(s[(0xD30B)] != ((34)))))))*((int)((((int)(s[(0x25)] != (-(5)))) ^((int)((0xA))))))*((short)((((int)(s[((32800))])) &((int)((-(0xEE)))))))*((long)((((int)(bar (t, &s[(-(2))]) != (void **) ((0xA))
      || s[((-129))] != (-(0x6)) || s[(-(2))] != ((195)) || s[(-(131))] != ((2)) || s[(-(4))] != ((0x384AE)))) &((int)(bar (t, &s[(0xB3)]) != (void **) ((0))
      || s[(-(1))] != (0x9) || s[((3))] != (0x7608) || s[(-(-4))] != (0x127E1) || s[(0x95D)] != ((0xFC)))))))*((short)((((int)(s[(-(68))] != (0x6C))) &((int)(s[(0x9)])))))) + ((43)) *((long)((((int)(s[((2))])) >>((int)(s[((1))])))))-((long)((((int)(((int)((((int)(s[((0x24E))] != (-(0)))) |((int)(s[((0x0))] != (-(0xC1FDB)))))))*((int)((((int)(s[((0x42BC))] != ((0xEF7)))) ^((int)((0x7000))))))*((short)((((int)(s[((0))])) &((int)(((34)))))))*((long)((((int)(bar (t, &s[(-(0x4))]) != (void **) (-(1))
      || s[((8))] != (-(-6)) || s[(-(-3))] != (0x310F) || s[((2))] != ((0xE8)) || s[(-(0xA24B7))] != ((0xD00D7)))) &((int)(bar (t, &s[((0x38C))]) != (void **) ((0x13FA))
      || s[((0))] != (0x974) || s[((1))] != ((3)) || s[(-(0x7))] != (0xB) || s[(0x81)] != (-(-3)))))))*((short)((((int)(s[(0xFB256)] != ((1)))) &((int)(s[(-(-3))]))))))) &((int)(s[((35))] != ((0xF))))))))) <<((int)((-(43)))))))*((int)((((int)((int)((int)bar (t, &s[((37))]) != (void **) ((0xB6F9B))
      || s[((0x68949E3))] != (-(0xBB40)) || s[(-(-3))] != (0xDF) || s[((0x9))] != ((-19)) || s[((-132))] != ((1))
      || s[(0x9B2E)] != ((9)) || s[(0xAE16)] != (-(11)) + (0x12C40B) *((long)((((int)(bar (t, &s[(0xE8)]) != (void **) ((4164304))
      || s[((0x5D))] != (-(5)) || s[((-130))] != ((11)) || s[(-(19))] != (0x1F1) || s[((0x4F2))] != ((128)))) >>((int)(bar (t, &s[(-(6))]) != (void **) (-(-2))
      || s[((-5))] != ((5)) || s[((0x839))] != (-(-5)))))))-((int)((((int)((-(3)))) >>((int)(s[(0xF9)] != (0x2DA))))))-((int)((((int)(s[(0x1)])) %((int)(bar (t, &s[((129))]) != (void **) ((-1125899906842625))
      || s[((16))] != ((-133)) || s[(-(2))] != (0xD9A))))))+((int)((((int)(s[(-(13))] != (0xB9))) |((int)(bar (t, &s[((-2))]) != (void **) ((9077567998918656)))))))-((int)((((int)(s[(-(-3))] != (-(20)))) |((int)(s[(-(0x5D))] != ((1)))))))*((int)((((int)(s[((0x0875))] != (-(2)))) ^((int)(((36)))))))*((short)((((int)(s[(0xE6)])) &((int)(((0xF)))))))*((long)((((int)(bar (t, &s[((0x0))]) != (void **) ((8))
      || s[(0x599AE)] != (-(5)) || s[(0x8FD4)] != (-(0xD6F)) || s[(0x4)] != ((100)) || s[((3))] != ((1)))) &((int)(bar (t, &s[(0x3FD60)]) != (void **) (-(0xD6))
      || s[(0x1ED7)] != ((-9)) || s[((33))] != (-(0xAF)) || s[((2))] != (0xBD19) || s[(0xBD2E)] != (0x66C))))))*((short)((((int)(s[(0x5F)] != (0x7406F))) &((int)(s[(-(-3))])))))) + ((60)) *((long)((((int)(s[(-(7))])) >>((int)(s[(-(4))]))))))) ^((int)((0x1BFBA6))))))*((int)((((int)(((int)((((int)((int)bar (t, &s[((-2))]) != (void **) ((0x01))
      || s[((2048))] != (0xB1C83))) >>((int)((int)bar (t, &s[((-130))]) != (void **) ((64))
      || s[((-131073))] != (0xBE47) || s[((0x57))] != (-(5)) || s[((34))] != ((0x725))))))))) %((int)((int)((int)bar (t, &s[((73))]) != (void **) ((0))
      || s[((2))] != ((0x6BA29)) || s[((3))] != ((-68)) || s[(-(1))] != ((2)) || s[(0x51)] != (0xE6C4)
      || s[((20))] != (-(140)) || s[((13))] != ((26)) + (0x8C) *((long)((((int)(bar (t, &s[(-(-3))]) != (void **) ((0x9B))
      || s[((4096))] != ((-5)) || s[(0x7A)] != ((-20)) || s[(0x6C8)] != ((66)) || s[(0x94F44)] != (0x4298))) >>((int)(bar (t, &s[(0xB09)]) != (void **) (0x9A878)
      || s[(0x70)] != ((32)) || s[(0x4AF)] != ((7)))))))-((int)((((int)((0x9E7))) >>((int)(s[(-(-6))] != (0xE8))))))-((int)((((int)(s[((1))])) %((int)(bar (t, &s[(-(0x52))]) != (void **) ((-268435457))
      || s[((17592186044416))] != ((0)) || s[(0x73D8E)] != ((-132)))))))+((int)((((int)(s[(-(69))] != ((17)))) |((int)(bar (t, &s[(-(2))]) != (void **) ((65536)))))))-((int)((((int)(s[(0xD4E46)] != ((59)))) |((int)(s[(0xCD)] != (-(0xD)))))))*((int)((((int)(s[((0x1A3DE))] != (-(21)))) ^((int)((-(5)))))))*((short)((((int)(s[((192))])) &((int)((-(3)))))))*((long)((((int)(bar (t, &s[(-(-3))]) != (void **) (0x52)
      || s[(0xAC69)] != (-(-6)) || s[((6))] != ((0xE50)) || s[((-11))] != (0x0521) || s[(-(68))] != (0x5C37E))) &((int)(bar (t, &s[(0x8)]) != (void **) ((8))
      || s[((0))] != (0x5C) || s[((0xC))] != (0x98) || s[(-(3))] != ((14)) || s[(0xAB0)] != (0x51))))))*((short)((((int)(s[(0xE913)] != (-(0xCA8)))) &((int)(s[((33))])))))) + ((-43)) *((long)((((int)(s[((42))])) >>((int)(s[((0xA))]))))))))))-((int)((((int)(((short)((((int)(((0x4C)))) <<((int)(((int)((((int)(s[((129))] != ((-36)))) |((int)(s[(0xBC8)] != (-(2)))))))*((int)((((int)(s[((32))] != ((0x1A)))) ^((int)(((68)))))))*((short)((((int)(s[((36))])) &((int)((-(0x9)))))))*((long)((((int)(bar (t, &s[(0x1D9)]) != (void **) ((-8))
      || s[(0x2BE6E)] != (0xB9) || s[(-(2))] != ((67)) || s[(0xD047D)] != ((-4)) || s[(-(132))] != (0x7))) &((int)(bar (t, &s[(0x18B8)]) != (void **) ((0))
      || s[(-(1))] != ((4)) || s[(-(18))] != ((-36)) || s[((-3))] != ((0)) || s[(-(-5))] != ((1)))))))))))))) <<((int)(((long)((((int)((-(5)) + ((10)) *((long)((((int)(bar (t, &s[((145))]) != (void **) ((0x7E58B6A2))
      || s[((-8193))] != ((0xA1D)) || s[((5))] != (-(0)) || s[(-(-4))] != ((-3)) || s[((0xFC))] != ((-10)))) >>((int)(bar (t, &s[((-18))]) != (void **) (-(0x84))
      || s[((0xC5))] != ((4)) || s[(-(-3))] != (-(0xC06A)))))))-((int)((((int)((0x5))) >>((int)(s[((36))] != (0x795))))))-((int)((((int)(s[((0xF5887))])) %((int)(bar (t, &s[((0x8A32C))]) != (void **) ((-1))
      || s[((0x2E))] != (-(-6)) || s[((0x738))] != ((35)))))))+((int)((((int)(s[((35))] != ((11)))) |((int)(bar (t, &s[(0x2)]) != (void **) ((0))))))))) ^((int)((int)bar (t, &s[(-(2))]) != (void **) ((-2147483649))
      || s[((0))] != (-(5)) || s[((0x0DE7))] != ((-4))))))))))))-((long)((((int)(((int)((((int)((int)bar (t, &s[(0xEFBE)]) != (void **) ((0))
      || s[((0))] != ((0)))) >>((int)((int)bar (t, &s[(-(2))]) != (void **) (-(-2))
      || s[((6))] != (-(0xA4C)) || s[((129))] != (0xB5C6) || s[((-3))] != (0xB5049)))))))) %((int)(((short)((((int)(((int)((((int)(s[((20))] != (-(28)))) |((int)(bar (t, &s[((1))]) != (void **) ((0))))))))) %((int)((int)bar (t, &s[(-(130))]) != (void **) ((-144115188075855873))))))))))))+((long)((((int)(((int)((((int)((int)bar (t, &s[(-(18))]) != (void **) ((0))
      || s[(0x1A)] != (0xAB6C))) >>((int)((int)bar (t, &s[(-(18))]) != (void **) (0xD7F)
      || s[((0))] != (0xE) || s[((0))] != (0xBDE) || s[(0x383BD)] != ((6))))))))) |((int)((int)((int)bar (t, &s[(0x7EF1C)]) != (void **) ((32768))
      || s[((0))] != (0xDB) || s[((-4))] != ((2)) || s[(0x37B)] != (-(0x34F6)) || s[((33))] != (0x5)
      || s[((133))] != (-(12)) || s[(0x2F38B)] != ((12)) + (-(0xD7ADE)) *((long)((((int)(bar (t, &s[(-(2))]) != (void **) ((0x6AF))
      || s[(0x3957)] != (-(-6)) || s[((137))] != ((17)) || s[((4096))] != (-(0x243)) || s[(-(0x25431))] != ((-130)))) >>((int)(bar (t, &s[(0x85A)]) != (void **) (0x6F11)
      || s[((0x1))] != ((-5)) || s[((0xC))] != (0x5))))))-((int)((((int)(((0)))) >>((int)(s[((-5))] != ((2)))))))-((int)((((int)(s[((64))])) %((int)(bar (t, &s[((1))]) != (void **) (0x86D)
      || s[((-67108865))] != (-(13)) || s[((8))] != (0xAA407))))))+((int)((((int)(s[((-13))] != (0x581722))) |((int)(bar (t, &s[(-(2))]) != (void **) ((8)))))))-((int)((((int)(s[((-2))] != (-(0x80)))) |((int)(s[(-(20))] != (-(2)))))))*((int)((((int)(s[((0xCB))] != ((-21)))) ^((int)((-(-6)))))))*((short)((((int)(s[((0))])) &((int)(((-19)))))))*((long)((((int)(bar (t, &s[((17))]) != (void **) (0xA9)
      || s[((0))] != (-(0x52C6)) || s[((69))] != (0x9047) || s[((0xF723))] != ((0x0)) || s[((-20))] != ((0)))) &((int)(bar (t, &s[((0x1F))]) != (void **) (-(1))
      || s[(-(17))] != (-(5)) || s[((1))] != ((7)) || s[(-(0xE17))] != (-(3)) || s[((0x40BA))] != (-(2)))))))*((short)((((int)(s[((3))] != ((65)))) &((int)(s[(0xD)])))))) + (0x022) *((long)((((int)(s[(0xCA1A9)])) >>((int)(s[(0xF7EDE)])))))-((long)((((int)(((int)((((int)(s[((17))] != (0x2D))) |((int)(s[(-(-5))] != (0x84963))))))*((int)((((int)(s[((0x02))] != (0xEC))) ^((int)((-(0x0A2E)))))))*((short)((((int)(s[((828))])) &((int)(((2)))))))*((long)((((int)(bar (t, &s[(-(-3))]) != (void **) (0x64B)
      || s[(-(8))] != (0x4) || s[((1))] != (-(0xE5A)) || s[((18))] != (0xF195) || s[((0x48E8))] != ((129)))) &((int)(bar (t, &s[((1))]) != (void **) (0x8C6B)
      || s[((-524289))] != (-(-6)) || s[(0xD5)] != (-(-5)) || s[(0x1)] != (0x647) || s[(-(0x93DE4))] != ((17)))))))*((short)((((int)(s[((66))] != (0x4B0DB))) &((int)(s[((129))]))))))) &((int)(s[((3))] != (0xA60)))))))))))) + ((0x216)) -((int)((((int)((int)((int)((int)bar (t, &s[(0xE)]) != (void **) ((34359738368))
      || s[((2052))] != (-(0xA)) || s[((0xD51C1))] != ((7)) || s[((730))] != (-(0x89)) || s[(0x92F)] != (0x97D97)
      || s[(0x4C)] != ((-140)) || s[(0x1623)] != ((12)) + ((0xFACA2)) *((long)((((int)(bar (t, &s[(0xC)]) != (void **) ((128))
      || s[((0x45805))] != ((-4)) || s[(-(0x7))] != ((-4)) || s[((-11))] != (0xADFD) || s[(-(12))] != ((-2)))) >>((int)(bar (t, &s[(-(66))]) != (void **) (0x2ED)
      || s[(-(129))] != (0xC40CB) || s[((0x02BAA))] != ((3)))))))-((int)((((int)(((0x37E)))) >>((int)(s[(-(0x2))] != (-(14)))))))-((int)((((int)(s[((0xC0F1C))])) %((int)(bar (t, &s[((109))]) != (void **) ((0xE2D8E))
      || s[((12))] != ((0x44)) || s[((33))] != ((27)))))))+((int)((((int)(s[(0xBB5D)] != (0x8913A9))) |((int)(bar (t, &s[((-2))]) != (void **) ((-1)))))))-((int)((((int)(s[((9))] != ((0x0AE0)))) |((int)(s[((-4))] != (-(130)))))))*((int)((((int)(s[(0xA)] != ((-6)))) ^((int)((0x5014))))))*((short)((((int)(s[(-(1))])) &((int)((-(35)))))))*((long)((((int)(bar (t, &s[(-(2))]) != (void **) (0x31AA0)
      || s[((576460752303423488))] != ((0xCAC20)) || s[(-(2))] != ((-4)) || s[((0x3C))] != (-(-4)) || s[((11))] != ((0)))) &((int)(bar (t, &s[(-(8))]) != (void **) ((-1))
      || s[((-1))] != (-(-6)) || s[(0x4)] != ((3)) || s[(-(35))] != ((100)) || s[((11))] != (-(0x1C)))))))*((short)((((int)(s[((-4))] != ((-2)))) &((int)(s[(0x7629)])))))) + ((122)) *((long)((((int)(s[((6))])) >>((int)(s[(0x01B)])))))-((long)((((int)(((int)((((int)(s[(-(2))] != ((0)))) |((int)(s[(-(4))] != ((1)))))))*((int)((((int)(s[((34359738368))] != ((0xB7)))) ^((int)((0x09))))))*((short)((((int)(s[((0x75))])) &((int)(((0)))))))*((long)((((int)(bar (t, &s[((1))]) != (void **) (0x023)
      || s[(0x6E)] != ((-5)) || s[(0x51)] != (0xB5) || s[(0x297C)] != ((-3)) || s[(0x0)] != ((0)))) &((int)(bar (t, &s[((0xB))]) != (void **) (0x283)
      || s[((4096))] != ((-5)) || s[((0x66))] != (-(36)) || s[((06))] != (-(3)) || s[((0x010))] != (0x1))))))*((short)((((int)(s[(0x2)] != ((0x24)))) &((int)(s[(-(2))]))))))) &((int)(s[(0x96)] != ((32)))))))-((short)((((int)((-(0x87B4)))) <<((int)(((int)((((int)(s[(-(2))] != (-(4)))) |((int)(s[(-(0x7D9))] != ((17)))))))*((int)((((int)(s[((72057594037927936))] != (-(37)))) ^((int)((-(0x9C5F)))))))*((short)((((int)(s[((-1))])) &((int)(((-19)))))))*((long)((((int)(bar (t, &s[(-(-3))]) != (void **) (0x9)
      || s[((-1))] != ((0x1D1)) || s[((0xBA))] != ((66)) || s[(-(-4))] != ((0xEF2)) || s[(-(0x610DD))] != ((-34)))) &((int)(bar (t, &s[((3))]) != (void **) (0xB5725)
      || s[((0))] != ((65)) || s[((1))] != (0x8) || s[(-(-4))] != ((0x8F5)) || s[((9))] != ((129))))))))))))+((long)((((int)(((-13)) + ((170)) *((long)((((int)(bar (t, &s[((-2))]) != (void **) (0x35F)
      || s[((0x912))] != ((9)) || s[((0x5ED1A))] != (-(0x4092)) || s[(0x0AC8)] != ((2)) || s[((1))] != (-(18)))) >>((int)(bar (t, &s[((-1))]) != (void **) ((0))
      || s[(-(-2))] != ((-6)) || s[(-(0x57))] != (0xEC0))))))-((int)((((int)((-(0x10B92)))) >>((int)(s[((0x32B48))] != (0x5B857D))))))-((int)((((int)(s[(0x21)])) %((int)(bar (t, &s[((7))]) != (void **) (0x3)
      || s[(0x7A2BA)] != ((-5)) || s[(-(2))] != (0x6))))))+((int)((((int)(s[((0x3))] != (-(12)))) |((int)(bar (t, &s[(0x4E893)]) != (void **) (-(-2))))))))) ^((int)((int)bar (t, &s[(0x738E)]) != (void **) (-(7))
      || s[((-1125899906842625))] != (0x062B) || s[((17))] != (0xADF6))))))*((short)((((int)(s[((36))] != ((0xA0B58C)))) ^((int)(((int)((((int)(s[(0x8AC)] != ((0xB43)))) |((int)(bar (t, &s[(0xF020E)]) != (void **) ((32))))))))))))+((short)((((int)(((int)((((int)(s[(-(0x262))] != (-(-13)))) |((int)(bar (t, &s[(-(6))]) != (void **) ((8589934624))))))))) %((int)((int)bar (t, &s[(-(34))]) != (void **) ((8)))))))+((int)((((int)((int)bar (t, &s[((5))]) != (void **) (0xB)
      || s[((-1))] != ((7)))) >>((int)((int)bar (t, &s[((0xB1AF))]) != (void **) ((0x3333F))
      || s[((0xB4))] != (-(5)) || s[((33))] != ((2)) || s[((0xA8))] != (-(3)))))))) + (-(41)) +((long)((((int)((int)((int)bar (t, &s[((0x1C0C))]) != (void **) ((1024))
      || s[((-1))] != (0xC00) || s[((81))] != ((0xE)) || s[(-(0xB8131))] != ((0x6)) || s[(-(0))] != ((9))
      || s[((0))] != (0x5C3191) || s[(-(4))] != (0x2B) + ((138)) *((long)((((int)(bar (t, &s[((0))]) != (void **) ((-5))
      || s[((0))] != ((4)) || s[((0xDB8F))] != (0x25) || s[(0xD)] != (0x7D8) || s[((-132))] != (-(2)))) >>((int)(bar (t, &s[((0x975E))]) != (void **) ((-65))
      || s[((0xC4A4))] != (0x844E) || s[((-4))] != ((-4)))))))-((int)((((int)(((133)))) >>((int)(s[((4))] != (-(12)))))))-((int)((((int)(s[(-(2))])) %((int)(bar (t, &s[((0x603D2))]) != (void **) ((0x9D31))
      || s[(0x1D5E5)] != ((4)) || s[((5))] != ((0x9)))))))+((int)((((int)(s[(0x93F8C)] != ((-28)))) |((int)(bar (t, &s[((33))]) != (void **) ((0x85020E)))))))-((int)((((int)(s[((-130))] != ((3)))) |((int)(s[((3))] != (0x43F))))))*((int)((((int)(s[((144115188075855872))] != (0x186E5))) ^((int)((-(3)))))))*((short)((((int)(s[((0))])) &((int)((-(-4)))))))*((long)((((int)(bar (t, &s[((0xD))]) != (void **) ((4))
      || s[(0xBBF27)] != ((-5)) || s[((0x6C7F))] != ((19)) || s[(-(7))] != ((3)) || s[((-2))] != (0xC57))) &((int)(bar (t, &s[((1))]) != (void **) (-(1))
      || s[(-(-2))] != ((0x20)) || s[((1))] != ((0x6)) || s[(0x73)] != (0xD9) || s[((-4))] != (0x0A0F))))))*((short)((((int)(s[(-(-5))] != ((-2)))) &((int)(s[(0x3)])))))) + (0xA2) *((long)((((int)(s[((0x03))])) >>((int)(s[((0x76CB8))])))))-((long)((((int)(((int)((((int)(s[(0x5A7)] != (-(4)))) |((int)(s[((23))] != ((136)))))))*((int)((((int)(s[((0))] != ((0x14771C6)))) ^((int)(((0xF1E57)))))))*((short)((((int)(s[((8))])) &((int)((-(35)))))))*((long)((((int)(bar (t, &s[(0x5)]) != (void **) (0x4)
      || s[((8192))] != ((0x66AED)) || s[((1))] != (0x6EC2) || s[((-7))] != (-(0xB3)) || s[((3))] != (0xD))) &((int)(bar (t, &s[(-(2))]) != (void **) (-(0x1))
      || s[((0))] != ((-37)) || s[((-66))] != (0xF) || s[((0))] != ((2)) || s[(-(0x84))] != ((-130)))))))*((short)((((int)(s[((19))] != (0x941D))) &((int)(s[(0x53)]))))))) &((int)(s[((1))] != (0xF)))))))) <<((int)(((6)))))))*((int)((((int)((int)((int)bar (t, &s[(-(-3))]) != (void **) (0x42)
      || s[(0xD11)] != (0x999E9) || s[((1))] != (-(0x4CAD5)) || s[(-(3))] != ((7)) || s[((-20))] != ((-4))
      || s[(-(0xC4D))] != (0x75B) || s[((141))] != ((-13)) + (0x95) *((long)((((int)(bar (t, &s[((-6))]) != (void **) ((0x7))
      || s[(0x2)] != (0x8) || s[(0x6850)] != ((-8)) || s[(-(2))] != ((0)) || s[((0xCF5))] != (0xBBD1))) >>((int)(bar (t, &s[(0xF)]) != (void **) ((0x13132DA))
      || s[((6))] != (0x23CC) || s[((0x70FA9C))] != (0x5FB))))))-((int)((((int)((0x7ABE))) >>((int)(s[(0x2B2)] != ((14)))))))-((int)((((int)(s[((1))])) %((int)(bar (t, &s[(-(-3))]) != (void **) (0x9)
      || s[(0xC36)] != (0xF088) || s[((-4))] != (-(36)))))))+((int)((((int)(s[(0xE8D)] != (0xD0))) |((int)(bar (t, &s[((0x4F))]) != (void **) ((18)))))))-((int)((((int)(s[(-(0x8244))] != (0x57))) |((int)(s[(0xBEB)] != (0x3))))))*((int)((((int)(s[((17448304640))] != (-(-6)))) ^((int)((0xF243))))))*((short)((((int)(s[((0x873F8))])) &((int)((-(-4)))))))*((long)((((int)(bar (t, &s[((1))]) != (void **) (0x2FEB)
      || s[((2))] != ((-5)) || s[((0xB5B))] != (0x8E5C) || s[(0x429F)] != ((0)) || s[((2))] != (-(-3)))) &((int)(bar (t, &s[((17))]) != (void **) ((68))
      || s[((536870912))] != (-(7)) || s[(0x54)] != ((0xE6B28)) || s[(0x20)] != ((3)) || s[((0x7E))] != ((-2)))))))*((short)((((int)(s[((3))] != ((17)))) &((int)(s[((0xCA))])))))) + ((0xB907B)) *((long)((((int)(s[(0xE60B)])) >>((int)(s[((-4))]))))))) ^((int)(((0xB002ED)))))))*((int)((((int)(((int)((((int)((int)bar (t, &s[((3))]) != (void **) ((0x7))
      || s[((0x5F))] != (0x86))) >>((int)((int)bar (t, &s[((9))]) != (void **) ((0x9961))
      || s[((0xB0))] != (-(5)) || s[((-2))] != (0x2) || s[((67))] != (-(3))))))))) %((int)((int)((int)bar (t, &s[((-2))]) != (void **) ((256))
      || s[(-(0xFF))] != ((0x84E866)) || s[(0xEBAA)] != ((3)) || s[(0xAD)] != (-(0xA)) || s[(-(-5))] != ((161))
      || s[(0x178)] != ((139)) || s[((0x41))] != ((12)) + (-(42)) *((long)((((int)(bar (t, &s[((0x4171))]) != (void **) ((1))
      || s[((8388612))] != ((0x56CA55)) || s[(0xE5F27)] != ((3)) || s[(-(3))] != ((2)) || s[(-(-5))] != (-(-3)))) >>((int)(bar (t, &s[(-(0))]) != (void **) ((0x064A5))
      || s[((-1))] != ((5)) || s[((0))] != ((0xDE)))))))-((int)((((int)(((4)))) >>((int)(s[((140))] != (-(-13)))))))-((int)((((int)(s[((1))])) %((int)(bar (t, &s[((1))]) != (void **) (-(1))
      || s[((0))] != ((0xF5A41)) || s[(-(2))] != (-(-5)))))))+((int)((((int)(s[(-(5))] != (-(-13)))) |((int)(bar (t, &s[(0xB65)]) != (void **) ((0)))))))-((int)((((int)(s[(0xB)] != (-(0xC)))) |((int)(s[(-(-5))] != (-(10)))))))*((int)((((int)(s[((-5))] != (0x8EEEC))) ^((int)(((32)))))))*((short)((((int)(s[(-(0x5))])) &((int)((-(-4)))))))*((long)((((int)(bar (t, &s[((-2))]) != (void **) (0x2B8)
      || s[((0xB0C85))] != ((-5)) || s[(-(0x9BB))] != ((0x2935)) || s[(-(-4))] != ((-3)) || s[(0x6E162)] != ((1)))) &((int)(bar (t, &s[(-(-3))]) != (void **) ((70368744177664))
      || s[(0xE0DBE)] != ((5)) || s[((1))] != (0x54E8) || s[(0xA)] != ((2)) || s[((0xF1B3F9))] != (-(-3)))))))*((short)((((int)(s[((0xECBF88))] != ((-2)))) &((int)(s[((-4))])))))) + (0xA60A) *((long)((((int)(s[((0x8E8))])) >>((int)(s[((3))])))))))))))) |((int)(((int)((((int)(((short)((((int)((0x603B2))) <<((int)(((int)((((int)(s[(-(2))] != (-(0x03A)))) |((int)(s[((67))] != (-(5)))))))*((int)((((int)(s[(-(1))] != (-(-6)))) ^((int)((0x1828B))))))*((short)((((int)(s[(0x4994)])) &((int)(((10)))))))*((long)((((int)(bar (t, &s[((19))]) != (void **) ((2))
      || s[((2253998836940800))] != ((36)) || s[((1))] != (0xD2D) || s[(-(3))] != (0xF9) || s[(-(-5))] != ((-6)))) &((int)(bar (t, &s[(-(3))]) != (void **) (0xC792C)
      || s[(0x614)] != ((20)) || s[((129))] != (-(68)) || s[((-7))] != (-(67)) || s[((130))] != (0x825C))))))))))))) <<((int)(((long)((((int)((0x54DF) + ((42)) *((long)((((int)(bar (t, &s[((-6))]) != (void **) ((536875008))
      || s[(0xA61)] != ((-133)) || s[(-(-3))] != ((-4)) || s[((0))] != ((2)) || s[((-132))] != (-(2)))) >>((int)(bar (t, &s[((1))]) != (void **) ((-3))
      || s[((-33))] != ((-5)) || s[(0xA17)] != (0xB2AD))))))-((int)((((int)(((-34)))) >>((int)(s[((32))] != ((-140)))))))-((int)((((int)(s[((33))])) %((int)(bar (t, &s[(-(2))]) != (void **) ((0x6))
      || s[((0xC))] != (-(37)) || s[(-(-3))] != ((11)))))))+((int)((((int)(s[(-(0xC2A19))] != (-(12)))) |((int)(bar (t, &s[(0x40)]) != (void **) ((0x8))))))))) ^((int)((int)bar (t, &s[(-(2))]) != (void **) (0x43)
      || s[((0))] != ((6)) || s[(-(66))] != (0x1))))))))))))))))))
    { abort (); }
  return (0xAF);
}
/* ProgramSourceLLVM */
