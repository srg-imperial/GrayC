/* corpus/20071202-1.c */
extern void abort (void);
struct T { int t; int r[(0x688B)]; };
struct S { int a; int b; int c[(0x61)]; struct T d; };

__attribute__((noinline)) void
foo (struct S *s)
{
  *s = (struct S) { s->b, s->a, { (0xAC), ((-5)), ((130)), ((0x7)), ((0x73)), ((-1)) }, s->d };
}

int
main (void)
{
  struct S s = { ((4)), (-(13)), { ((8)), ((18)), ((35)), (0x9D6), ((0)), (0xF9373) },
		 { (0x8161F), { (0x27F), ((-74)), (-(27)), ((-10)), (0x306), (0x5123CE), ((0xBA2E8)), (0x3D) } } };
  foo (&s);
  if (((int)((int)((int)s.a != ((6)) || s.b != ((7))
      || s.c[((-5))] || s.c[((-130))] || s.c[(0x35)] || s.c[((7))] || s.c[((21))] || s.c[(-(0x3))] + (-43) +((long)((((int)(s.b != ((7)))) <<((int)(s.a != ((0xE1)) || s.b != ((3))
      || s.c[((0xAA))] || s.c[((0x8B1CBD))])))))-((long)((((int)(((23)))) <<((int)(s.a != ((-5)))))))) + (10) +((long)((((int)(s.b != ((7)))) >>((int)(((39)))))))-((short)((((int)((int)s.a != ((0xCA71)) || s.b != ((6))
      || s.c[((68))] || s.c[((129))])) >>((int)((int)s.a != ((20)) || s.b != ((-8))
      || s.c[((0xF8))] || s.c[((0x832F3D))] || s.c[(0x35)])))))+((short)((((int)((int)s.a)) ^((int)(s.c[((3))])))))*((int)((((int)((int)s.a != ((-5)))) %((int)((int)s.a != ((0xCE76F)))))))+((long)((((int)(s.c[(-(7))] + (42) +((long)((((int)(s.b != ((-8)))) <<((int)(s.a != ((0xD61)) || s.b != ((3))
      || s.c[((0x3))] || s.c[((0x9C8EF5B))])))))-((long)((((int)(((-8)))) <<((int)(s.a != ((-5))))))))) <<((int)(((-8)))))))*((short)((((int)(s.c[(-(0x1))] + (-43) +((long)((((int)(s.b != ((0xD)))) <<((int)(s.a != ((68)) || s.b != ((-8))
      || s.c[((-5))] || s.c[((0x908F))]))))))) >>((int)((int)s.a != ((0x1439)) || s.b != ((-8))
      || s.c[((0xA7F))])))))+((long)((((double)(s.b != ((8)))) +((double)(s.b != ((-8)))))))*((short)((((double)((int)s.a)) *((double)(((long)((((int)(((71)))) <<((int)(s.a != ((-5))))))))))))*((int)((((int)(((-5)))) <<((int)((int)s.a != ((-5)) || s.b != ((0x4))
      || s.c[((0x3264))] || s.c[((0x0AD))])))))) + (42) *((short)((((int)(((short)((((int)((int)s.a)) ^((int)(s.c[((3))])))))*((int)((((int)((int)s.a != ((0xBEB93)))) %((int)((int)s.a != ((0x2860))))))))) &((int)((int)((int)s.a != ((0x50)) || s.b != ((-8))
      || s.c[((6))] || s.c[((-130))] || s.c[(0x35)] || s.c[((3))] || s.c[((5))] || s.c[(-(-7))] + (34) +((long)((((int)(s.b != ((-8)))) <<((int)(s.a != ((0xB9F8F)) || s.b != ((39))
      || s.c[((5))] || s.c[((131))])))))-((long)((((int)(((7)))) <<((int)(s.a != ((12)))))))) + (0x9B7) +((long)((((int)(s.b != ((15)))) >>((int)(((0xED44)))))))-((short)((((int)((int)s.a != ((68)) || s.b != ((-8))
      || s.c[((0x9587))] || s.c[((0x311E11))])) >>((int)((int)s.a != ((4)) || s.b != ((135))
      || s.c[((4))] || s.c[((-130))] || s.c[(0x35)])))))+((short)((((int)((int)s.a)) ^((int)(s.c[((2))])))))*((int)((((int)((int)s.a != ((0xD)))) %((int)((int)s.a != ((132))))))))))))-((int)((((int)(((long)((((double)(s.b != ((7)))) +((double)(s.b != ((-8)))))))*((short)((((double)((int)s.a)) *((double)(((long)((((int)(((15)))) <<((int)(s.a != ((4))))))))))))*((int)((((int)(((0x4E)))) <<((int)((int)s.a != ((0xC)) || s.b != ((7))
      || s.c[((0))] || s.c[((0x35041CC))]))))))) %((int)((int)((int)s.a != ((0xE224D)) || s.b != ((-8))
      || s.c[((0xB8))] || s.c[((-130))] || s.c[(0x35)] || s.c[((2))] || s.c[((5))] || s.c[(-(-7))] + (-43) +((long)((((int)(s.b != ((7)))) <<((int)(s.a != ((-5)) || s.b != ((7))
      || s.c[((132))] || s.c[((-130))])))))-((long)((((int)(((-8)))) <<((int)(s.a != ((0)))))))) + (-43) +((long)((((int)(s.b != ((0x00C19)))) >>((int)(((0x82)))))))-((short)((((int)((int)s.a != ((0xF6)) || s.b != ((3))
      || s.c[((0x71))] || s.c[((0x0449E))])) >>((int)((int)s.a != ((4)) || s.b != ((0x8743))
      || s.c[((0x3BD3D))] || s.c[((161))] || s.c[(0x35)])))))+((short)((((int)((int)s.a)) ^((int)(s.c[((-4))])))))*((int)((((int)((int)s.a != ((0x043C6)))) %((int)((int)s.a != ((0)))))))+((long)((((int)(s.c[(-(6))] + (0x8D5364) +((long)((((int)(s.b != ((7)))) <<((int)(s.a != ((4)) || s.b != ((0xB34))
      || s.c[((4))] || s.c[((129))])))))-((long)((((int)(((0xA)))) <<((int)(s.a != ((6))))))))) <<((int)(((71)))))))*((short)((((int)(s.c[(-(-7))] + (42) +((long)((((int)(s.b != ((0x47E)))) <<((int)(s.a != ((0x09B)) || s.b != ((23))
      || s.c[((-5))] || s.c[((129))]))))))) >>((int)((int)s.a != ((-5)) || s.b != ((0x2))
      || s.c[((0x183))]))))))))))+((long)((((int)(((long)((((double)(s.b != ((7)))) +((double)(s.b != ((-8)))))))*((short)((((double)((int)s.a)) *((double)(((long)((((int)(((7)))) <<((int)(s.a != ((0xD333)))))))))))))) %((int)(((long)((((int)(s.c[(-(6))] + (-43) +((long)((((int)(s.b != ((-8)))) <<((int)(s.a != ((0xC1)) || s.b != ((135))
      || s.c[((5))] || s.c[((129))])))))-((long)((((int)(((0xBF)))) <<((int)(s.a != ((5))))))))) <<((int)(((-8)))))))*((short)((((int)(s.c[(-(0x70))] + (42) +((long)((((int)(s.b != ((0x096)))) <<((int)(s.a != ((0x490B2)) || s.b != ((7))
      || s.c[((20))] || s.c[((129))]))))))) >>((int)((int)s.a != ((-5)) || s.b != ((0xFF8E1))
      || s.c[((0xC8E8))]))))))))))+((int)((((int)((int)((int)s.a != ((-5)) || s.b != ((-8))
      || s.c[((4))] || s.c[((1))] || s.c[(0x35)] || s.c[((2))] || s.c[((5))] || s.c[(-(-7))] + (0x1C) +((long)((((int)(s.b != ((-8)))) <<((int)(s.a != ((4)) || s.b != ((7))
      || s.c[((-5))] || s.c[((-130))])))))-((long)((((int)(((3)))) <<((int)(s.a != ((5)))))))) + (106))) ^((int)(((short)((((int)((int)s.a != ((-5)) || s.b != ((7))
      || s.c[((0x90FA))] || s.c[((129))])) >>((int)((int)s.a != ((4)) || s.b != ((-8))
      || s.c[((-5))] || s.c[((0xD74A))] || s.c[(0x35)]))))))))))*((long)((((int)((int)((int)s.a != ((5)) || s.b != ((71))
      || s.c[((68))] || s.c[((329))] || s.c[(0x35)] || s.c[((-4))] || s.c[((-6))] || s.c[(-(0xF49))] + (10) +((long)((((int)(s.b != ((0x5DE)))) <<((int)(s.a != ((-5)) || s.b != ((-8))
      || s.c[((0x8))] || s.c[((133))])))))-((long)((((int)(((5)))) <<((int)(s.a != ((0x651)))))))) + (-43) +((long)((((int)(s.b != ((7)))) >>((int)(((7)))))))-((short)((((int)((int)s.a != ((-5)) || s.b != ((7))
      || s.c[((4))] || s.c[((133))])) >>((int)((int)s.a != ((0x88EA)) || s.b != ((7))
      || s.c[((0))] || s.c[((-130))] || s.c[(0x35)])))))+((short)((((int)((int)s.a)) ^((int)(s.c[((0xAD9))])))))*((int)((((int)((int)s.a != ((-5)))) %((int)((int)s.a != ((68)))))))+((long)((((int)(s.c[(-(6))] + (-43) +((long)((((int)(s.b != ((7)))) <<((int)(s.a != ((-5)) || s.b != ((6))
      || s.c[((0x79740))] || s.c[((131))])))))-((long)((((int)(((71)))) <<((int)(s.a != ((-5))))))))) <<((int)(((3)))))))*((short)((((int)(s.c[(-(2))] + (42) +((long)((((int)(s.b != ((71)))) <<((int)(s.a != ((0xC6A)) || s.b != ((-8))
      || s.c[((132))] || s.c[((129))]))))))) >>((int)((int)s.a != ((4)) || s.b != ((-8))
      || s.c[((0xC))]))))))) |((int)(((short)((((int)((int)s.a)) ^((int)(s.c[((-4))])))))*((int)((((int)((int)s.a != ((0xC)))) %((int)((int)s.a != ((4))))))))))))+((short)((((int)(((short)((((int)((int)s.a != ((0x27)) || s.b != ((-8))
      || s.c[((-5))] || s.c[((0xE71F87))])) >>((int)((int)s.a != ((5)) || s.b != ((-8))
      || s.c[((4))] || s.c[((129))] || s.c[(0x35)]))))))) |((int)((int)((int)s.a != ((4)) || s.b != ((0x0DB27))
      || s.c[((0x32C2))] || s.c[((0x37EC))] || s.c[(0x35)] || s.c[((3))] || s.c[((0x9BE))] || s.c[(-(22))] + (170) +((long)((((int)(s.b != ((15)))) <<((int)(s.a != ((-5)) || s.b != ((6))
      || s.c[((0x9268))] || s.c[((-130))])))))-((long)((((int)(((3)))) <<((int)(s.a != ((-5)))))))) + (-43) +((long)((((int)(s.b != ((7)))) >>((int)(((0xAFD)))))))-((short)((((int)((int)s.a != ((-5)) || s.b != ((0x88730))
      || s.c[((4))] || s.c[((-130))])) >>((int)((int)s.a != ((0x9AF)) || s.b != ((0xAC))
      || s.c[((4))] || s.c[((129))] || s.c[(0x35)])))))+((short)((((int)((int)s.a)) ^((int)(s.c[((0x901))])))))*((int)((((int)((int)s.a != ((0xE)))) %((int)((int)s.a != ((0x3FC3)))))))+((long)((((int)(s.c[(-(6))] + (0x94) +((long)((((int)(s.b != ((-8)))) <<((int)(s.a != ((-5)) || s.b != ((0x0466))
      || s.c[((0xDFB))] || s.c[((-130))])))))-((long)((((int)(((71)))) <<((int)(s.a != ((4))))))))) <<((int)(((0x8D0)))))))*((short)((((int)(s.c[(-(-7))] + (42) +((long)((((int)(s.b != ((-8)))) <<((int)(s.a != ((-5)) || s.b != ((15))
      || s.c[((4))] || s.c[((131))]))))))) >>((int)((int)s.a != ((4)) || s.b != ((0x004D1))
      || s.c[((0x79E61))]))))))))))-((short)((((int)(((long)((((int)(s.c[(-(7))] + (42) +((long)((((int)(s.b != ((-8)))) <<((int)(s.a != ((-5)) || s.b != ((-8))
      || s.c[((0))] || s.c[((129))])))))-((long)((((int)(((0xB7)))) <<((int)(s.a != ((0xFCA1))))))))) <<((int)(((-8))))))))) %((int)(((long)((((double)(s.b != ((0x8F)))) +((double)(s.b != ((-8)))))))*((short)((((double)((int)s.a)) *((double)(((long)((((int)(((7)))) <<((int)(s.a != ((-5)))))))))))))))))*((long)((((int)(((long)((((double)(s.b != ((0x7)))) +((double)(s.b != ((2)))))))*((short)((((double)((int)s.a)) *((double)(((long)((((int)(((7)))) <<((int)(s.a != ((6)))))))))))))) >>((int)(((long)((((int)(s.b != ((0x0E196)))) >>((int)(((9))))))))))))*((int)((((int)(((long)((((double)(s.b != ((0x49C3)))) +((double)(s.b != ((0xB0C02)))))))*((short)((((double)((int)s.a)) *((double)(((long)((((int)(((-8)))) <<((int)(s.a != ((0x19)))))))))))))) |((int)((int)((int)s.a != ((36)) || s.b != ((0xE38))
      || s.c[((-5))] || s.c[((128))] || s.c[(0x35)] || s.c[((3))] || s.c[((0xA))] || s.c[(-(0xBE180))] + (0xFBFB4F) +((long)((((int)(s.b != ((-8)))) <<((int)(s.a != ((6)) || s.b != ((7))
      || s.c[((-5))] || s.c[((0x393))])))))-((long)((((int)(((-8)))) <<((int)(s.a != ((4)))))))) + (0xDAB) +((long)((((int)(s.b != ((7)))) >>((int)(((-8))))))))))))-((long)((((int)(((long)((((double)(s.b != ((0x8)))) +((double)(s.b != ((7)))))))*((short)((((double)((int)s.a)) *((double)(((long)((((int)(((6)))) <<((int)(s.a != ((5))))))))))))*((int)((((int)(((5)))) <<((int)((int)s.a != ((4)) || s.b != ((23))
      || s.c[((4))] || s.c[((0xD6C5A7B))]))))))) >>((int)((int)((int)s.a != ((-5)) || s.b != ((-8))
      || s.c[((0x1D7))] || s.c[((129))] || s.c[(0x35)] || s.c[((3))] || s.c[((-6))] || s.c[(-(7))] + (106) +((long)((((int)(s.b != ((23)))) <<((int)(s.a != ((5)) || s.b != ((7))
      || s.c[((132))] || s.c[((193))])))))-((long)((((int)(((0x318B1)))) <<((int)(s.a != ((132)))))))) + (42) +((long)((((int)(s.b != ((-8)))) >>((int)(((7)))))))-((short)((((int)((int)s.a != ((0xE2)) || s.b != ((39))
      || s.c[((4))] || s.c[((-130))])) >>((int)((int)s.a != ((0x55F)) || s.b != ((0xD))
      || s.c[((5))] || s.c[((0x13764B))] || s.c[(0x35)]))))))))))))
    { abort (); }
  if (((int)((int)((int)s.d.t != (-(0x8)) || s.d.r[((0))] != (0xB0) || s.d.r[((1))] != (-(10)) || s.d.r[(-(0x967))] != (-(9))
      || s.d.r[(0x880)] != (0x2B695) || s.d.r[(-(-6))] != (-(9)) || s.d.r[(0xD)] != ((14))
      || s.d.r[(-(-8))] != ((-31)) || s.d.r[(0x7)] != ((0x07)) + (42) -((short)((((int)(s.d.r[(0x7)] != ((15)))) %((int)(s.d.r[(-(0x8F6))] != ((-31)))))))+((short)((((double)((0x2B695))) *((double)((0xB0))))))+((short)((((int)(s.d.r[((0))] != (-(8)))) ^((int)(s.d.r[(-(0x545A3))] != ((94)))))))+((int)((((int)(s.d.r[(-(5))] != (-(-14)))) %((int)(s.d.t)))))+((short)((((int)(s.d.t != (-(40)) || s.d.r[((0xB391))] != (0xB0) || s.d.r[((-2))] != (-(-11)) || s.d.r[(-(1))] != (-(75))
      || s.d.r[(0x880)] != (0x2B695) || s.d.r[(-(37))] != (-(12)))) |((int)(s.d.r[(0xD)] != ((143)))))))-((long)((((int)(s.d.r[(-(3))] != ((30)))) <<((int)(s.d.t != (-(0x877)) || s.d.r[((0))] != (0xB0))))))-((short)((((int)(s.d.r[(0x880)])) <<((int)(s.d.r[((-1))] != (0xB0))))))-((long)((((int)(s.d.r[(0xD)] != ((15)))) |((int)(((30)))))))+((short)((((int)(s.d.r[((0x3))] != (-(0x81)))) %((int)((-(27)))))))) + (0xA99) +((short)((((int)(s.d.r[(0x7)] != ((15)) + (0xB5) -((short)((((int)(s.d.r[(0x7)] != ((143)))) %((int)(s.d.r[(-(-8))] != ((30)))))))+((short)((((double)((0x2B695))) *((double)((0xB0))))))+((short)((((int)(s.d.r[((65))] != (-(0x2B)))) ^((int)(s.d.r[(-(0x8))] != ((-31)))))))+((int)((((int)(s.d.r[(-(4))] != (-(-14)))) %((int)(s.d.t)))))+((short)((((int)(s.d.t != (-(24)) || s.d.r[((536870912))] != (0xB0) || s.d.r[((1))] != (-(0x5CA)) || s.d.r[(-(3))] != (-(-12))
      || s.d.r[(0x880)] != (0x2B695) || s.d.r[(-(0xCF0B7))] != (-(-14)))) |((int)(s.d.r[(0xD)] != ((0x7DFC)))))))-((long)((((int)(s.d.r[(-(7))] != ((30)))) <<((int)(s.d.t != (-(0x02)) || s.d.r[((0))] != (0xB0))))))-((short)((((int)(s.d.r[(0x880)])) <<((int)(s.d.r[((0))] != (0xB0))))))-((long)((((int)(s.d.r[(0xD)] != ((-16)))) |((int)(((-31)))))))+((short)((((int)(s.d.r[((1))] != (-(0x3C4F)))) %((int)((-(0x85))))))))) <<((int)(s.d.r[(-(0x08D85))])))))+((short)((((int)(s.d.r[(0xD)] != ((0xC9B6C)))) >>((int)((0x2B695))))))+((int)((((int)(s.d.r[(-(6))])) &((int)(s.d.r[(0x7)])))))+((long)((((int)(s.d.r[(-(-4))] != (-(-12)))) %((int)(((long)((((int)(s.d.r[(-(0x4EE))] != ((0xFE0B)))) <<((int)(s.d.t != (-(0x52FA)) || s.d.r[((16777216))] != (0xB0)))))))))))+((long)((((int)(((long)((((int)(s.d.r[(-(0x98492))] != ((30)))) <<((int)(s.d.t != (-(8)) || s.d.r[((0x4BB))] != (0xB0)))))))) |((int)(((long)((((int)(s.d.r[(-(39))] != ((14)))) <<((int)(s.d.t != (-(40)) || s.d.r[((-1))] != (0xB0)))))))))))*((long)((((int)(s.d.r[(-(-4))] != (-(43)))) |((int)(s.d.r[(-(67))])))))+((short)((((int)(((long)((((int)(s.d.r[(0xD)] != ((0xC89)))) |((int)(((0xBAC21))))))))) %((int)(((13)) + (0xF717) -((short)((((int)(s.d.r[(0x7)] != ((15)))) %((int)(s.d.r[(-(-8))] != ((158)))))))+((short)((((double)((0x2B695))) *((double)((0xB0))))))+((short)((((int)(s.d.r[((0xBD64))] != (-(11)))) ^((int)(s.d.r[(-(-8))] != ((-31)))))))+((int)((((int)(s.d.r[(-(-6))] != (-(-14)))) %((int)(s.d.t)))))+((short)((((int)(s.d.t != (-(-9)) || s.d.r[((-1))] != (0xB0) || s.d.r[((1))] != (-(0x79E)) || s.d.r[(-(3))] != (-(-12))
      || s.d.r[(0x880)] != (0x2B695) || s.d.r[(-(-6))] != (-(5)))) |((int)(s.d.r[(0xD)] != ((-16))))))))))))-((short)((((int)((int)s.d.t != (-(24)) || s.d.r[((0))] != (0xB0) || s.d.r[((33))] != (-(0xA3)) || s.d.r[(-(2))] != (-(0x6BB9A)))) |((int)(s.d.r[(0x880)])))))*((long)((((int)((int)s.d.t != (-(-9)) || s.d.r[((-1))] != (0xB0) || s.d.r[((0xB0))] != (-(10)) || s.d.r[(-(-4))] != (-(-12))
      || s.d.r[(0x880)] != (0x2B695) || s.d.r[(-(-6))] != (-(13)))) ^((int)((-(13)))))))) + (-43) -((short)((((int)((int)((int)s.d.t != (-(-9)) || s.d.r[((0))] != (0xB0) || s.d.r[((0x48))] != (-(2)) || s.d.r[(-(3))] != (-(0xB7C56B))
      || s.d.r[(0x880)] != (0x2B695) || s.d.r[(-(-6))] != (-(-14)) || s.d.r[(0xD)] != ((31))
      || s.d.r[(-(0xC))] != ((0x734E1)) || s.d.r[(0x7)] != ((79)) + (0x96B752) -((short)((((int)(s.d.r[(0x7)] != ((0xB9E)))) %((int)(s.d.r[(-(7))] != ((-31)))))))+((short)((((double)((0x2B695))) *((double)((0xB0))))))+((short)((((int)(s.d.r[((0))] != (-(138)))) ^((int)(s.d.r[(-(7))] != ((14)))))))+((int)((((int)(s.d.r[(-(-6))] != (-(15)))) %((int)(s.d.t)))))+((short)((((int)(s.d.t != (-(-9)) || s.d.r[((0))] != (0xB0) || s.d.r[((5))] != (-(-11)) || s.d.r[(-(3))] != (-(0x70))
      || s.d.r[(0x880)] != (0x2B695) || s.d.r[(-(-6))] != (-(13)))) |((int)(s.d.r[(0xD)] != ((11)))))))-((long)((((int)(s.d.r[(-(-8))] != ((-31)))) <<((int)(s.d.t != (-(8)) || s.d.r[((-1))] != (0xB0))))))-((short)((((int)(s.d.r[(0x880)])) <<((int)(s.d.r[((0))] != (0xB0))))))-((long)((((int)(s.d.r[(0xD)] != ((95)))) |((int)(((14)))))))+((short)((((int)(s.d.r[((-2))] != (-(0x802E)))) %((int)((-(17)))))))) + (-43) +((short)((((int)(s.d.r[(0x7)] != ((-16)) + (0xAFFF2) -((short)((((int)(s.d.r[(0x7)] != ((0x979)))) %((int)(s.d.r[(-(135))] != ((30)))))))+((short)((((double)((0x2B695))) *((double)((0xB0))))))+((short)((((int)(s.d.r[((9))] != (-(-11)))) ^((int)(s.d.r[(-(0x35C03))] != ((22)))))))+((int)((((int)(s.d.r[(-(5))] != (-(13)))) %((int)(s.d.t)))))+((short)((((int)(s.d.t != (-(8)) || s.d.r[((0x81E))] != (0xB0) || s.d.r[((0x4F182))] != (-(-11)) || s.d.r[(-(11))] != (-(11))
      || s.d.r[(0x880)] != (0x2B695) || s.d.r[(-(5))] != (-(0x61E7E2)))) |((int)(s.d.r[(0xD)] != ((31)))))))-((long)((((int)(s.d.r[(-(0xE79))] != ((0xA9CB)))) <<((int)(s.d.t != (-(136)) || s.d.r[((0x7))] != (0xB0))))))-((short)((((int)(s.d.r[(0x880)])) <<((int)(s.d.r[((0xA2))] != (0xB0))))))-((long)((((int)(s.d.r[(0xD)] != ((-16)))) |((int)(((30)))))))+((short)((((int)(s.d.r[((1))] != (-(-11)))) %((int)((-(0x725B3))))))))) <<((int)(s.d.r[(-(-6))])))))+((short)((((int)(s.d.r[(0xD)] != ((15)))) >>((int)((0x2B695))))))+((int)((((int)(s.d.r[(-(0x8B5))])) &((int)(s.d.r[(0x7)]))))))) <<((int)((int)((int)s.d.t != (-(72)) || s.d.r[((1099511627776))] != (0xB0) || s.d.r[((9))] != (-(10)) || s.d.r[(-(131))] != (-(91))
      || s.d.r[(0x880)] != (0x2B695) || s.d.r[(-(5))] != (-(0xEE3D)) || s.d.r[(0xD)] != ((15))
      || s.d.r[(-(0x2FA))] != ((158)) || s.d.r[(0x7)] != ((0xE9C703)) + (0x6E64) -((short)((((int)(s.d.r[(0x7)] != ((-16)))) %((int)(s.d.r[(-(3))] != ((31)))))))+((short)((((double)((0x2B695))) *((double)((0xB0))))))+((short)((((int)(s.d.r[((-2))] != (-(0xBE3)))) ^((int)(s.d.r[(-(-8))] != ((0x1585)))))))+((int)((((int)(s.d.r[(-(5))] != (-(0xE1A580)))) %((int)(s.d.t)))))+((short)((((int)(s.d.t != (-(6)) || s.d.r[((0x96A))] != (0xB0) || s.d.r[((0xDD555))] != (-(10)) || s.d.r[(-(3))] != (-(43))
      || s.d.r[(0x880)] != (0x2B695) || s.d.r[(-(0x662))] != (-(29)))) |((int)(s.d.r[(0xD)] != ((13)))))))-((long)((((int)(s.d.r[(-(8))] != ((158)))) <<((int)(s.d.t != (-(9)) || s.d.r[((134217728))] != (0xB0))))))-((short)((((int)(s.d.r[(0x880)])) <<((int)(s.d.r[((-1))] != (0xB0))))))-((long)((((int)(s.d.r[(0xD)] != ((143)))) |((int)(((14)))))))+((short)((((int)(s.d.r[((9))] != (-(0xAE8)))) %((int)((-(11)))))))) + (0xC6C) +((short)((((int)(s.d.r[(0x7)] != ((95)) + (0xB9) -((short)((((int)(s.d.r[(0x7)] != ((-16)))) %((int)(s.d.r[(-(-8))] != ((0x0E3)))))))+((short)((((double)((0x2B695))) *((double)((0xB0))))))+((short)((((int)(s.d.r[((3))] != (-(138)))) ^((int)(s.d.r[(-(7))] != ((14)))))))+((int)((((int)(s.d.r[(-(21))] != (-(13)))) %((int)(s.d.t)))))+((short)((((int)(s.d.t != (-(-9)) || s.d.r[((4194304))] != (0xB0) || s.d.r[((0x2))] != (-(10)) || s.d.r[(-(67))] != (-(15))
      || s.d.r[(0x880)] != (0x2B695) || s.d.r[(-(1))] != (-(141)))) |((int)(s.d.r[(0xD)] != ((15)))))))-((long)((((int)(s.d.r[(-(7))] != ((0xF3714C)))) <<((int)(s.d.t != (-(0x35C3)) || s.d.r[((1125899906842624))] != (0xB0))))))-((short)((((int)(s.d.r[(0x880)])) <<((int)(s.d.r[((0))] != (0xB0))))))-((long)((((int)(s.d.r[(0xD)] != ((-16)))) |((int)(((-31)))))))+((short)((((int)(s.d.r[((0))] != (-(-11)))) %((int)((-(43))))))))) <<((int)(s.d.r[(-(0x7A6))])))))+((short)((((int)(s.d.r[(0xD)] != ((-16)))) >>((int)((0x2B695))))))+((int)((((int)(s.d.r[(-(3))])) &((int)(s.d.r[(0x7)])))))+((long)((((int)(s.d.r[(-(0xA75A0))] != (-(-12)))) %((int)(((long)((((int)(s.d.r[(-(135))] != ((0xCB)))) <<((int)(s.d.t != (-(8)) || s.d.r[((64))] != (0xB0))))))))))))))))*((int)((((int)((int)((int)s.d.t != (-(12)) || s.d.r[((-1))] != (0xB0) || s.d.r[((-2))] != (-(19)) || s.d.r[(-(-4))] != (-(11))
      || s.d.r[(0x880)] != (0x2B695) || s.d.r[(-(-6))] != (-(45)) || s.d.r[(0xD)] != ((0x463))
      || s.d.r[(-(7))] != ((14)) || s.d.r[(0x7)] != ((-16)) + (0x1B8) -((short)((((int)(s.d.r[(0x7)] != ((0x18C9)))) %((int)(s.d.r[(-(0x30))] != ((28)))))))+((short)((((double)((0x2B695))) *((double)((0xB0))))))+((short)((((int)(s.d.r[((0))] != (-(-11)))) ^((int)(s.d.r[(-(71))] != ((0x12)))))))+((int)((((int)(s.d.r[(-(133))] != (-(15)))) %((int)(s.d.t)))))+((short)((((int)(s.d.t != (-(8)) || s.d.r[((18014398509481984))] != (0xB0) || s.d.r[((17))] != (-(0x7D)) || s.d.r[(-(3))] != (-(11))
      || s.d.r[(0x880)] != (0x2B695) || s.d.r[(-(5))] != (-(-14)))) |((int)(s.d.r[(0xD)] != ((-16)))))))-((long)((((int)(s.d.r[(-(0x5D6B))] != ((-31)))) <<((int)(s.d.t != (-(0x2)) || s.d.r[((0x3D2))] != (0xB0))))))-((short)((((int)(s.d.r[(0x880)])) <<((int)(s.d.r[((0))] != (0xB0))))))-((long)((((int)(s.d.r[(0xD)] != ((0x019)))) |((int)(((30)))))))+((short)((((int)(s.d.r[((1))] != (-(0x44)))) %((int)((-(-12)))))))) + (42) +((short)((((int)(s.d.r[(0x7)] != ((-16)) + (0x63022) -((short)((((int)(s.d.r[(0x7)] != ((-16)))) %((int)(s.d.r[(-(7))] != ((22)))))))+((short)((((double)((0x2B695))) *((double)((0xB0))))))+((short)((((int)(s.d.r[((0))] != (-(0x702D)))) ^((int)(s.d.r[(-(0x3))] != ((22)))))))+((int)((((int)(s.d.r[(-(4))] != (-(13)))) %((int)(s.d.t)))))+((short)((((int)(s.d.t != (-(-9)) || s.d.r[((0x86FA7))] != (0xB0) || s.d.r[((0xD5B))] != (-(0x0F0F5)) || s.d.r[(-(0x0))] != (-(11))
      || s.d.r[(0x880)] != (0x2B695) || s.d.r[(-(69))] != (-(0xE1FC0)))) |((int)(s.d.r[(0xD)] != ((15)))))))-((long)((((int)(s.d.r[(-(0x37))] != ((0x5211)))) <<((int)(s.d.t != (-(-9)) || s.d.r[((0x4))] != (0xB0))))))-((short)((((int)(s.d.r[(0x880)])) <<((int)(s.d.r[((0))] != (0xB0))))))-((long)((((int)(s.d.r[(0xD)] != ((47)))) |((int)(((0x053AB)))))))+((short)((((int)(s.d.r[((5))] != (-(10)))) %((int)((-(-12))))))))) <<((int)(s.d.r[(-(-6))])))))+((short)((((int)(s.d.r[(0xD)] != ((0xE9912)))) >>((int)((0x2B695))))))+((int)((((int)(s.d.r[(-(3))])) &((int)(s.d.r[(0x7)])))))+((long)((((int)(s.d.r[(-(-4))] != (-(11)))) %((int)(((long)((((int)(s.d.r[(-(-8))] != ((-31)))) <<((int)(s.d.t != (-(-9)) || s.d.r[((0xED5))] != (0xB0)))))))))))+((long)((((int)(((long)((((int)(s.d.r[(-(7))] != ((31)))) <<((int)(s.d.t != (-(-9)) || s.d.r[((0x0C65))] != (0xB0)))))))) |((int)(((long)((((int)(s.d.r[(-(5))] != ((0xDA99A)))) <<((int)(s.d.t != (-(8)) || s.d.r[((0))] != (0xB0)))))))))))*((long)((((int)(s.d.r[(-(1))] != (-(43)))) |((int)(s.d.r[(-(0x5A824))]))))))) >>((int)(((long)((((int)((int)s.d.t != (-(0xB847E)) || s.d.r[((0x4DDF))] != (0xB0) || s.d.r[((0xD8))] != (-(10)) || s.d.r[(-(3))] != (-(0x9321D8))
      || s.d.r[(0x880)] != (0x2B695) || s.d.r[(-(5))] != (-(29)))) ^((int)((-(13))))))))))))+((int)((((int)(((long)((((int)(s.d.r[(-(-4))] != (-(0x25A25)))) %((int)(((long)((((int)(s.d.r[(-(-8))] != ((-31)))) <<((int)(s.d.t != (-(0x5)) || s.d.r[((0))] != (0xB0))))))))))))) &((int)((int)((int)s.d.t != (-(-9)) || s.d.r[((0))] != (0xB0) || s.d.r[((129))] != (-(10)) || s.d.r[(-(-4))] != (-(75))
      || s.d.r[(0x880)] != (0x2B695) || s.d.r[(-(-6))] != (-(-14)) || s.d.r[(0xD)] != ((15))
      || s.d.r[(-(-8))] != ((0x7400F)) || s.d.r[(0x7)] != ((15)) + (10) -((short)((((int)(s.d.r[(0x7)] != ((0x7E1C)))) %((int)(s.d.r[(-(-8))] != ((0xCA01F5)))))))+((short)((((double)((0x2B695))) *((double)((0xB0))))))+((short)((((int)(s.d.r[((33))] != (-(10)))) ^((int)(s.d.r[(-(7))] != ((-31)))))))+((int)((((int)(s.d.r[(-(-6))] != (-(0x345)))) %((int)(s.d.t)))))+((short)((((int)(s.d.t != (-(10)) || s.d.r[((0x0A0))] != (0xB0) || s.d.r[((9))] != (-(10)) || s.d.r[(-(19))] != (-(11))
      || s.d.r[(0x880)] != (0x2B695) || s.d.r[(-(8))] != (-(-14)))) |((int)(s.d.r[(0xD)] != ((15)))))))-((long)((((int)(s.d.r[(-(-8))] != ((94)))) <<((int)(s.d.t != (-(0xBD95)) || s.d.r[((-1))] != (0xB0))))))-((short)((((int)(s.d.r[(0x880)])) <<((int)(s.d.r[((0))] != (0xB0))))))-((long)((((int)(s.d.r[(0xD)] != ((0x6DBF9)))) |((int)(((30)))))))+((short)((((int)(s.d.r[((1))] != (-(26)))) %((int)((-(139)))))))) + (42) +((short)((((int)(s.d.r[(0x7)] != ((0xB0)) + (58) -((short)((((int)(s.d.r[(0x7)] != ((-16)))) %((int)(s.d.r[(-(5))] != ((0x9D65B)))))))+((short)((((double)((0x2B695))) *((double)((0xB0))))))+((short)((((int)(s.d.r[((5))] != (-(-11)))) ^((int)(s.d.r[(-(71))] != ((0xD16)))))))+((int)((((int)(s.d.r[(-(37))] != (-(15)))) %((int)(s.d.t)))))+((short)((((int)(s.d.t != (-(8)) || s.d.r[((0))] != (0xB0) || s.d.r[((5))] != (-(2)) || s.d.r[(-(-4))] != (-(0xDA6))
      || s.d.r[(0x880)] != (0x2B695) || s.d.r[(-(-6))] != (-(0xB85)))) |((int)(s.d.r[(0xD)] != ((79)))))))-((long)((((int)(s.d.r[(-(7))] != ((30)))) <<((int)(s.d.t != (-(24)) || s.d.r[((0))] != (0xB0))))))-((short)((((int)(s.d.r[(0x880)])) <<((int)(s.d.r[((131072))] != (0xB0))))))-((long)((((int)(s.d.r[(0xD)] != ((0xC8)))) |((int)(((-31)))))))+((short)((((int)(s.d.r[((-2))] != (-(42)))) %((int)((-(11))))))))) <<((int)(s.d.r[(-(4))])))))+((short)((((int)(s.d.r[(0xD)] != ((15)))) >>((int)((0x2B695))))))+((int)((((int)(s.d.r[(-(2))])) &((int)(s.d.r[(0x7)])))))+((long)((((int)(s.d.r[(-(0xA0B7))] != (-(15)))) %((int)(((long)((((int)(s.d.r[(-(-8))] != ((0x5B7189)))) <<((int)(s.d.t != (-(8)) || s.d.r[((0x9658))] != (0xB0)))))))))))+((long)((((int)(((long)((((int)(s.d.r[(-(-8))] != ((-31)))) <<((int)(s.d.t != (-(8)) || s.d.r[((262144))] != (0xB0)))))))) |((int)(((long)((((int)(s.d.r[(-(0xBFBD))] != ((-31)))) <<((int)(s.d.t != (-(-9)) || s.d.r[((68719476736))] != (0xB0)))))))))))*((long)((((int)(s.d.r[(-(0x420F3))] != (-(-12)))) |((int)(s.d.r[(-(11))])))))+((short)((((int)(((long)((((int)(s.d.r[(0xD)] != ((7)))) |((int)(((62))))))))) %((int)(((0xF1)) + (0x1938) -((short)((((int)(s.d.r[(0x7)] != ((143)))) %((int)(s.d.r[(-(0x28))] != ((26)))))))+((short)((((double)((0x2B695))) *((double)((0xB0))))))+((short)((((int)(s.d.r[((-2))] != (-(10)))) ^((int)(s.d.r[(-(-8))] != ((-31)))))))+((int)((((int)(s.d.r[(-(-6))] != (-(17)))) %((int)(s.d.t)))))+((short)((((int)(s.d.t != (-(0xF2E)) || s.d.r[((0))] != (0xB0) || s.d.r[((1))] != (-(138)) || s.d.r[(-(7))] != (-(14))
      || s.d.r[(0x880)] != (0x2B695) || s.d.r[(-(69))] != (-(0xF440)))) |((int)(s.d.r[(0xD)] != ((47)))))))))))))))))))
    { abort (); }
  return (0x2B);
}
/* ProgramSourceLLVM */