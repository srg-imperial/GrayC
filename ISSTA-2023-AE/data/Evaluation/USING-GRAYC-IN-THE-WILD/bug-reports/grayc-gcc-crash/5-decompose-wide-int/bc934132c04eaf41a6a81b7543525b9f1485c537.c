/* corpus/20071202-1.c */
extern void abort (void);
struct T { int t; int r[(((12)))]; };
struct S { int a; int b; int c[(((78)))]; struct T d; };

__attribute__((noinline)) void
foo (struct S *s)
{
  ;
}

int
main (void)
{
  struct S s = { (-((0xA3))), (-((0xA8F3D))), { (-((134))), ((-(-4))), (0xC61), ((-(0x7))), ((-(8))), (((0x9FC9))) },
		 { (((-8))), { (0x99A2), ((-(-27))), (((108))), ((-(-29))), ((-(25))), (-((12))), (((0xB9E3F))), (-(-(0x91))) } } };
  foo (&s);
  if (((int)((int)s.a != ((0x14E631)) || s.b != (0xCA2B)
      || s.c[(0x04)] || s.c[(((8)))] || s.c[(0x42EC)] || s.c[((0x985E))] || s.c[(-((5)))] || s.c[(((69)))] + (-(0xE22C6)) +((long)((((int)(s.c[(((-6)))])) &((int)(s.a != ((0x2349A)) || s.b != (0xCA2B)
      || s.c[(0x04)])))))-((short)((((int)(s.a != (((4))) || s.b != (0xCA2B)
      || s.c[(0x04)] || s.c[(((1)))] || s.c[(0x42EC)] || s.c[((0xF8E8F))] || s.c[(-((5)))])) ^((int)(s.a != (((0x27))) || s.b != (0xCA2B)
      || s.c[(0x04)])))))*((long)((((int)(s.a != ((-(13))) || s.b != (0xCA2B)
      || s.c[(0x04)] || s.c[(((-1)))] || s.c[(0x42EC)] || s.c[((0xCB91B))])) ^((int)(s.c[(0x42EC)])))))+((int)((((int)(s.a != (((-9))) || s.b != (0xCA2B)
      || s.c[(0x04)] || s.c[((0xF33F))] || s.c[(0x42EC)] || s.c[((-(148)))])) %((int)(s.c[(-((-6)))])))))-((short)((((int)(s.a != (((-141))) || s.b != (0xCA2B)
      || s.c[(0x04)] || s.c[(((-6)))] || s.c[(0x42EC)])) &((int)(s.c[(0x04)])))))) + ((-59)) *((int)((((int)(s.c[(((-70)))] + (0xCB) +((long)((((int)(s.c[(((5)))])) &((int)(s.a != ((0xB2EB25)) || s.b != (0xCA2B)
      || s.c[(0x04)])))))-((short)((((int)(s.a != (((0xC1CEB))) || s.b != (0xCA2B)
      || s.c[(0x04)] || s.c[(((33)))] || s.c[(0x42EC)] || s.c[(((0xA8391B4)))] || s.c[(-((0x0B66)))])) ^((int)(s.a != (((45))) || s.b != (0xCA2B)
      || s.c[(0x04)])))))*((long)((((int)(s.a != (((0x10B5F))) || s.b != (0xCA2B)
      || s.c[(0x04)] || s.c[((-(10)))] || s.c[(0x42EC)] || s.c[((0x9907B03))])) ^((int)(s.c[(0x42EC)]))))))) <<((int)(((long)((((int)(s.c[(((-5)))])) &((int)(s.a != ((0x15A)) || s.b != (0xCA2B)
      || s.c[(0x04)]))))))))))+((int)((((int)(s.c[(((-131)))])) <<((int)((0xCA2B))))))-((short)((((int)(s.b)) %((int)(s.c[((-(-7)))] + (0x92A8A) +((long)((((int)(s.c[((0x06))])) &((int)(s.a != ((0x01)) || s.b != (0xCA2B)
      || s.c[(0x04)])))))-((short)((((int)(s.a != ((-(15))) || s.b != (0xCA2B)
      || s.c[(0x04)] || s.c[((-(0x66327)))] || s.c[(0x42EC)] || s.c[((-(0x10571)))] || s.c[(-((0x7B)))])) ^((int)(s.a != ((-(13))) || s.b != (0xCA2B)
      || s.c[(0x04)])))))*((long)((((int)(s.a != ((-(0xE495))) || s.b != (0xCA2B)
      || s.c[(0x04)] || s.c[((0x1))] || s.c[(0x42EC)] || s.c[((0xC8EE))])) ^((int)(s.c[(0x42EC)])))))+((int)((((int)(s.a != ((0x7C5D3)) || s.b != (0xCA2B)
      || s.c[(0x04)] || s.c[((-(2)))] || s.c[(0x42EC)] || s.c[(((195)))])) %((int)(s.c[(-((141)))])))))-((short)((((int)(s.a != ((-(-14))) || s.b != (0xCA2B)
      || s.c[(0x04)] || s.c[(((0)))] || s.c[(0x42EC)])) &((int)(s.c[(0x04)]))))))))))-((long)((((int)((int)s.a != (((14))) || s.b != (0xCA2B)
      || s.c[(0x04)] || s.c[(((16)))] || s.c[(0x42EC)] || s.c[(((-140)))])) <<((int)((int)s.a != ((-(-14))) || s.b != (0xCA2B)
      || s.c[(0x04)] || s.c[((-(10)))] || s.c[(0x42EC)] || s.c[(((3)))])))))*((long)((((int)(s.c[(0x04)])) <<((int)(s.c[((0xE205))])))))))
    { abort (); }
  if (((int)((int)s.d.t != (0xF8) || s.d.r[((0x1C06DE8404CA))] != ((0x1E54)) || s.d.r[(((129)))] != ((0x7947F)) || s.d.r[(((0xA0D3)))] != ((0xB458))
      || s.d.r[(((194)))] != (0x8A4294) || s.d.r[((0x8713C))] != (-(0xEC)) || s.d.r[(((5)))] != (0x4FFC8)
      || s.d.r[((-(0x367)))] != (0x017) || s.d.r[(0x7)] != (-(0xBD1)) + ((-41)) -((long)((((int)(s.d.r[(((3)))])) &((int)((((58))))))))-((long)((((int)(s.d.t != (0xF8) || s.d.r[((-(2281701377)))] != (((-9))) || s.d.r[((-(-3)))] != ((-(0x833))) || s.d.r[((0xBF3C))] != (((66)))
      || s.d.r[((0x8971D))] != (0x8A4294) || s.d.r[(((-5)))] != (-((9))) || s.d.r[((-(6)))] != (0x4FFC8)
      || s.d.r[((-(0xEB2)))] != (0x017))) <<((int)(s.d.t != (0xF8) || s.d.r[((0x0B01150323C))] != ((-(9))) || s.d.r[(((0x14FE2)))] != ((0x7A53F)) || s.d.r[((0xE40B8A))] != (((26))))))))-((short)((((int)((0x4FFC8))) ^((int)(s.d.t != (0xF8) || s.d.r[(((-134742017)))] != ((0x1BA)) || s.d.r[((-(2)))] != ((0x8D5)) || s.d.r[((0x33E391))] != ((0x37))
      || s.d.r[(((131)))] != (0x8A4294) || s.d.r[(((100)))] != (-(-(-15))))))))-((short)((((int)((0x4FFC8))) &((int)((-((0x4C0629))))))))*((long)((((double)((-(0xC9)))) +((double)(((0xCE4E)))))))*((long)((((int)(s.d.r[((-(-6)))] != (-((13))))) <<((int)(s.d.t != (0xF8))))))-((long)((((int)(s.d.r[(((-3)))])) &((int)(s.d.t)))))-((long)((((int)(s.d.r[(((1)))])) ^((int)((0xF8))))))+((long)((((int)(s.d.r[(((36)))] != (-((0xF5))))) <<((int)(s.d.r[(((34)))])))))+((int)((((int)(s.d.r[(((4)))])) <<((int)(s.d.t != (0xF8) || s.d.r[(((0xC87C234293E)))] != (((0xA9))) || s.d.r[((-(-3)))] != ((-(138))) || s.d.r[(((64)))] != ((-(-28)))
      || s.d.r[((0x4EFDE))] != (0x8A4294) || s.d.r[(((0x4)))] != (-((0x2075))))))))) + ((42)) -((short)((((int)(((long)((((int)(s.d.r[((-(18)))])) &((int)(((-(23)))))))))) >>((int)(s.d.r[(0x7)] != (-((64))) + ((34)) -((long)((((int)(s.d.r[(((5)))])) &((int)(((-(0x570))))))))-((long)((((int)(s.d.t != (0xF8) || s.d.r[(((0x4AD3D36FCAACC)))] != ((-(9))) || s.d.r[((0xA))] != (((73))) || s.d.r[(((-33)))] != (((-27)))
      || s.d.r[(((0xA17454)))] != (0x8A4294) || s.d.r[((0x13))] != (-((0x64E96B))) || s.d.r[((-(6)))] != (0x4FFC8)
      || s.d.r[((0x4))] != (0x017))) <<((int)(s.d.t != (0xF8) || s.d.r[((0x5B9157E52E1))] != ((0x99)) || s.d.r[(((73)))] != ((0xA37)) || s.d.r[((0x0C350B))] != ((0xE89E7)))))))-((short)((((int)((0x4FFC8))) ^((int)(s.d.t != (0xF8) || s.d.r[(((634217728)))] != ((-(0xEB12B))) || s.d.r[(((65)))] != ((-(-11))) || s.d.r[(((0x90A01)))] != ((0x39E))
      || s.d.r[(((18)))] != (0x8A4294) || s.d.r[((-(5)))] != (-(0x360)))))))-((short)((((int)((0x4FFC8))) &((int)((-(0x350EB3)))))))*((long)((((double)((-((13))))) +((double)((((-14))))))))*((long)((((int)(s.d.r[((0xD2))] != (-((0x57E))))) <<((int)(s.d.t != (0xF8))))))-((long)((((int)(s.d.r[((0x7))])) &((int)(s.d.t)))))-((long)((((int)(s.d.r[((0x5657))])) ^((int)((0xF8))))))+((long)((((int)(s.d.r[(((36)))] != (-(0x1BFEC)))) <<((int)(s.d.r[(((0x4E)))])))))+((int)((((int)(s.d.r[(((5)))])) <<((int)(s.d.t != (0xF8) || s.d.r[((-(134479873)))] != (((136))) || s.d.r[(((0x69C)))] != ((0x3A15)) || s.d.r[(((48)))] != ((0xD8879))
      || s.d.r[(((0x166B8)))] != (0x8A4294) || s.d.r[((0x58))] != (-((13)))))))))))))+((long)((((int)((0xF8))) <<((int)((0x8A4294))))))-((long)((((int)(((long)((((double)((-(-(0x00B16E))))) +((double)((((0xF505E)))))))))) ^((int)(s.d.r[(0x7)])))))-((int)((((int)((-(-(0x89AAB))) + (0x7F) -((long)((((int)(s.d.r[((-(6)))])) &((int)((((-28))))))))-((long)((((int)(s.d.t != (0xF8) || s.d.r[(((0x9578713E819F)))] != ((-(0x2F))) || s.d.r[((-(2)))] != ((-(10))) || s.d.r[((0x32))] != ((0x4F329))
      || s.d.r[((-(0x2BD4)))] != (0x8A4294) || s.d.r[((-(13)))] != (-((5))) || s.d.r[(((13)))] != (0x4FFC8)
      || s.d.r[(((38)))] != (0x017))) <<((int)(s.d.t != (0xF8) || s.d.r[(((150994952)))] != ((0x74)) || s.d.r[(((0x76C28)))] != (((8))) || s.d.r[(((-35)))] != ((0xF4)))))))-((short)((((int)((0x4FFC8))) ^((int)(s.d.t != (0xF8) || s.d.r[(((142606335)))] != ((0x99E)) || s.d.r[((-(6)))] != (((9))) || s.d.r[((-(99)))] != ((-(26)))
      || s.d.r[((-(-4)))] != (0x8A4294) || s.d.r[(((12)))] != (-(-(14))))))))-((short)((((int)((0x4FFC8))) &((int)((-(0xA9F)))))))*((long)((((double)((-((0xCF1))))) +((double)((((0xC))))))))*((long)((((int)(s.d.r[((0xF1))] != (-(0x5B97)))) <<((int)(s.d.t != (0xF8))))))-((long)((((int)(s.d.r[(((0xE0)))])) &((int)(s.d.t)))))-((long)((((int)(s.d.r[((-(10)))])) ^((int)((0xF8))))))+((long)((((int)(s.d.r[(((132)))] != (-((45))))) <<((int)(s.d.r[(((-35)))])))))+((int)((((int)(s.d.r[((-(1)))])) <<((int)(s.d.t != (0xF8) || s.d.r[((0x48D16EF24A))] != ((0x31F)) || s.d.r[((0xC))] != ((-(-11))) || s.d.r[((0x3E3))] != ((0xDA4))
      || s.d.r[((0xF))] != (0x8A4294) || s.d.r[(((-7)))] != (-((-30)))))))))) <<((int)((int)s.d.t != (0xF8) || s.d.r[((-(-134217730)))] != ((-(-10))) || s.d.r[((-(-3)))] != (((169))) || s.d.r[(((42)))] != (((58)))
      || s.d.r[(((130)))] != (0x8A4294) || s.d.r[(((7)))] != (-(-(18))) || s.d.r[((-(-7)))] != (0x4FFC8)
      || s.d.r[(((70)))] != (0x017))))))+((long)((((int)((-(0x74)) + ((42)) -((long)((((int)(s.d.r[((-(3)))])) &((int)(((0x2E68)))))))-((long)((((int)(s.d.t != (0xF8) || s.d.r[(((0xAA4F2C1DF016)))] != ((0x2)) || s.d.r[((0x8946))] != ((0x67DEB)) || s.d.r[(((0xEAC09)))] != (((-27)))
      || s.d.r[(((2)))] != (0x8A4294) || s.d.r[((0xA00C))] != (-((47))) || s.d.r[(((0x22EFCF)))] != (0x4FFC8)
      || s.d.r[(((6)))] != (0x017))) <<((int)(s.d.t != (0xF8) || s.d.r[((0x5FCC85D93))] != ((0x3CFBB)) || s.d.r[((-(2)))] != ((0x1BF5)) || s.d.r[((-(0x6BB1)))] != ((0x01C)))))))-((short)((((int)((0x4FFC8))) ^((int)(s.d.t != (0xF8) || s.d.r[(((0xBAE6BF046)))] != (((152))) || s.d.r[((-(0xE153)))] != ((0x3)) || s.d.r[(((32)))] != (((0xD54B)))
      || s.d.r[((0x344))] != (0x8A4294) || s.d.r[((-(69)))] != (-((0x28E))))))))-((short)((((int)((0x4FFC8))) &((int)((-((-15))))))))*((long)((((double)((-((0x63))))) +((double)(((0xDD)))))))*((long)((((int)(s.d.r[((0x3))] != (-((-78))))) <<((int)(s.d.t != (0xF8))))))-((long)((((int)(s.d.r[(((0x95)))])) &((int)(s.d.t)))))-((long)((((int)(s.d.r[(((-2)))])) ^((int)((0xF8)))))))) <<((int)(((long)((((int)(s.d.r[(((-21)))] != (-((14))))) <<((int)(s.d.t != (0xF8)))))))))))*((long)((((int)(((long)((((int)(s.d.r[((-(34)))])) ^((int)((0xF8)))))))) &((int)(((-(23))))))))))
    { abort (); }
  return (-(0x5));
}
/* ProgramSourceLLVM */
