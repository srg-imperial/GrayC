/* corpus/pr51877.c */
/* PR tree-optimization/51877 */

extern void abort (void);
struct A { int a; char b[(((0x6F4B7)))]; } a, b;

__attribute__((noinline, noclone))
struct A
bar (int x)
{
  struct A r;
  static int n;
  


r.a = ++n + (-(171)) -((int)((((int)(++n)) >>((int)(++n)))))*((short)((((double)(++n)) *((double)(++n)))))+((short)((((double)(r.a)) +((double)(++n)))))+((int)((((int)(++n)) >>((int)(r.a))))) + (0x884E) -((long)((((int)(++n)) &((int)(r.a)))))*((long)((((double)(r.a)) -((double)(++n + (-(0x1C881)))))))*((long)((((int)(((short)((((double)(r.a)) +((double)(++n))))))) >>((int)(++n))))) + (0x63D2B) *((long)((((int)(r.a)) ^((int)(++n + ((46)) -((int)((((int)(++n)) >>((int)(++n)))))*((short)((((double)(++n)) *((double)(++n)))))+((short)((((double)(r.a)) +((double)(++n)))))+((int)((((int)(++n)) >>((int)(r.a))))) + (-(-44)) -((long)((((int)(++n)) &((int)(r.a)))))*((long)((((double)(r.a)) -((double)(++n + (0xFDCE))))))*((long)((((int)(((short)((((double)(r.a)) +((double)(++n))))))) >>((int)(++n))))))))))-((short)((((int)(r.a)) >>((int)(++n + ((106)) -((int)((((int)(++n)) >>((int)(++n)))))*((short)((((double)(++n)) *((double)(++n)))))+((short)((((double)(r.a)) +((double)(++n)))))+((int)((((int)(++n)) >>((int)(r.a))))) + (0x69C8) -((long)((((int)(++n)) &((int)(r.a)))))*((long)((((double)(r.a)) -((double)(++n + ((0xBDDE1)))))))*((long)((((int)(((short)((((double)(r.a)) +((double)(++n))))))) >>((int)(++n))))))))))+((long)((((double)(r.a)) -((double)(r.a)))))*((long)((((int)(++n + ((0x19A9)) -((int)((((int)(++n)) >>((int)(++n)))))*((short)((((double)(++n)) *((double)(++n)))))+((short)((((double)(r.a)) +((double)(++n)))))+((int)((((int)(++n)) >>((int)(r.a))))) + ((-44)) -((long)((((int)(++n)) &((int)(r.a)))))*((long)((((double)(r.a)) -((double)(++n + (0xC97E6))))))*((long)((((int)(((short)((((double)(r.a)) +((double)(++n))))))) >>((int)(++n))))))) <<((int)(++n + (0x468E) -((int)((((int)(++n)) >>((int)(++n)))))*((short)((((double)(++n)) *((double)(++n)))))+((short)((((double)(r.a)) +((double)(++n)))))+((int)((((int)(++n)) >>((int)(r.a))))) + ((59)) -((long)((((int)(++n)) &((int)(r.a)))))*((long)((((double)(r.a)) -((double)(++n + ((0x56A496)))))))*((long)((((int)(((short)((((double)(r.a)) +((double)(++n))))))) >>((int)(++n))))))))));
r.a = ++n + (-(-44)) -((int)((((int)(++n)) >>((int)(++n)))))*((short)((((double)(++n)) *((double)(++n)))))+((short)((((double)(r.a)) +((double)(++n)))))+((int)((((int)(++n)) >>((int)(r.a))))) + (0x884E) -((long)((((int)(++n)) &((int)(r.a)))))*((long)((((double)(r.a)) -((double)(++n + (-(107)))))))*((long)((((int)(((short)((((double)(r.a)) +((double)(++n))))))) >>((int)(++n))))) + (0x63D2B) *((long)((((int)(r.a)) ^((int)(++n + ((42)) -((int)((((int)(++n)) >>((int)(++n)))))*((short)((((double)(++n)) *((double)(++n)))))+((short)((((double)(r.a)) +((double)(++n)))))+((int)((((int)(++n)) >>((int)(r.a))))) + (-(-44)) -((long)((((int)(++n)) &((int)(r.a)))))*((long)((((double)(r.a)) -((double)(++n + (0xFDCE))))))*((long)((((int)(((short)((((double)(r.a)) +((double)(++n))))))) >>((int)(++n))))))))))-((short)((((int)(r.a)) >>((int)(++n + ((42)) -((int)((((int)(++n)) >>((int)(++n)))))*((short)((((double)(++n)) *((double)(++n)))))+((short)((((double)(r.a)) +((double)(++n)))))+((int)((((int)(++n)) >>((int)(r.a))))) + (0x69C8) -((long)((((int)(++n)) &((int)(r.a)))))*((long)((((double)(r.a)) -((double)(++n + ((0x172A13)))))))*((long)((((int)(((short)((((double)(r.a)) +((double)(++n))))))) >>((int)(++n))))))))))+((long)((((double)(r.a)) -((double)(r.a)))))*((long)((((int)(++n + ((42)) -((int)((((int)(++n)) >>((int)(++n)))))*((short)((((double)(++n)) *((double)(++n)))))+((short)((((double)(r.a)) +((double)(++n)))))+((int)((((int)(++n)) >>((int)(r.a))))) + ((0x9B00F5)) -((long)((((int)(++n)) &((int)(r.a)))))*((long)((((double)(r.a)) -((double)(++n + (0xC97E6))))))*((long)((((int)(((short)((((double)(r.a)) +((double)(++n))))))) >>((int)(++n))))))) <<((int)(++n + (0x468E) -((int)((((int)(++n)) >>((int)(++n)))))*((short)((((double)(++n)) *((double)(++n)))))+((short)((((double)(r.a)) +((double)(++n)))))+((int)((((int)(++n)) >>((int)(r.a))))) + ((-44)) -((long)((((int)(++n)) &((int)(r.a)))))*((long)((((double)(r.a)) -((double)(++n + ((44)))))))*((long)((((int)(((short)((((double)(r.a)) +((double)(++n))))))) >>((int)(++n))))))))));
;

r.a = ++n + ((0x29E33)) -((int)((((int)(++n)) >>((int)(++n)))))*((short)((((double)(++n)) *((double)(++n)))))+((short)((((double)(r.a)) +((double)(++n)))))+((int)((((int)(++n)) >>((int)(r.a))))) + ((10)) +((int)((((int)(((int)((((int)(++n)) >>((int)(r.a))))))) &((int)(++n + ((0x2E555)) -((int)((((int)(++n)) >>((int)(++n)))))*((short)((((double)(++n)) *((double)(++n)))))+((short)((((double)(r.a)) +((double)(++n)))))+((int)((((int)(++n)) >>((int)(r.a))))))))))-((short)((((int)(((int)((((int)(++n)) >>((int)(++n)))))*((short)((((double)(++n)) *((double)(++n))))))) &((int)(((short)((((double)(++n)) *((double)(++n))))))))))+((long)((((int)(++n + ((42)) -((int)((((int)(++n)) >>((int)(++n)))))*((short)((((double)(++n)) *((double)(++n)))))+((short)((((double)(r.a)) +((double)(++n)))))+((int)((((int)(++n)) >>((int)(r.a))))))) %((int)(((int)((((int)(++n)) >>((int)(++n))))))))))+((long)((((int)(++n + (0x9886))) %((int)(++n))))) + (-(0xAE9)) *((int)((((int)(++n + ((-171)) -((int)((((int)(++n)) >>((int)(++n)))))*((short)((((double)(++n)) *((double)(++n)))))+((short)((((double)(r.a)) +((double)(++n)))))+((int)((((int)(++n)) >>((int)(r.a))))) + (-(0x37)) +((int)((((int)(((int)((((int)(++n)) >>((int)(r.a))))))) &((int)(++n + ((-43)) -((int)((((int)(++n)) >>((int)(++n)))))*((short)((((double)(++n)) *((double)(++n)))))+((short)((((double)(r.a)) +((double)(++n)))))+((int)((((int)(++n)) >>((int)(r.a))))))))))-((short)((((int)(((int)((((int)(++n)) >>((int)(++n)))))*((short)((((double)(++n)) *((double)(++n))))))) &((int)(((short)((((double)(++n)) *((double)(++n))))))))))+((long)((((int)(++n + ((-59)) -((int)((((int)(++n)) >>((int)(++n)))))*((short)((((double)(++n)) *((double)(++n)))))+((short)((((double)(r.a)) +((double)(++n)))))+((int)((((int)(++n)) >>((int)(r.a))))))) %((int)(((int)((((int)(++n)) >>((int)(++n))))))))))+((long)((((int)(++n + ((46)))) %((int)(++n))))))) ^((int)(r.a)))));
r.a = ++n + ((10)) -((int)((((int)(++n)) >>((int)(++n)))))*((short)((((double)(++n)) *((double)(++n)))))+((short)((((double)(r.a)) +((double)(++n)))))+((int)((((int)(++n)) >>((int)(r.a))))) + ((0x696B)) +((int)((((int)(((int)((((int)(++n)) >>((int)(r.a))))))) &((int)(++n + ((42)) -((int)((((int)(++n)) >>((int)(++n)))))*((short)((((double)(++n)) *((double)(++n)))))+((short)((((double)(r.a)) +((double)(++n)))))+((int)((((int)(++n)) >>((int)(r.a))))))))))-((short)((((int)(((int)((((int)(++n)) >>((int)(++n)))))*((short)((((double)(++n)) *((double)(++n))))))) &((int)(((short)((((double)(++n)) *((double)(++n))))))))))+((long)((((int)(++n + ((-43)) -((int)((((int)(++n)) >>((int)(++n)))))*((short)((((double)(++n)) *((double)(++n)))))+((short)((((double)(r.a)) +((double)(++n)))))+((int)((((int)(++n)) >>((int)(r.a))))))) %((int)(((int)((((int)(++n)) >>((int)(++n))))))))))+((long)((((int)(++n + (0x9886))) %((int)(++n))))) + (-(47)) *((int)((((int)(++n + ((-171)) -((int)((((int)(++n)) >>((int)(++n)))))*((short)((((double)(++n)) *((double)(++n)))))+((short)((((double)(r.a)) +((double)(++n)))))+((int)((((int)(++n)) >>((int)(r.a))))) + (-(0x1DAC)) +((int)((((int)(((int)((((int)(++n)) >>((int)(r.a))))))) &((int)(++n + ((42)) -((int)((((int)(++n)) >>((int)(++n)))))*((short)((((double)(++n)) *((double)(++n)))))+((short)((((double)(r.a)) +((double)(++n)))))+((int)((((int)(++n)) >>((int)(r.a))))))))))-((short)((((int)(((int)((((int)(++n)) >>((int)(++n)))))*((short)((((double)(++n)) *((double)(++n))))))) &((int)(((short)((((double)(++n)) *((double)(++n))))))))))+((long)((((int)(++n + ((58)) -((int)((((int)(++n)) >>((int)(++n)))))*((short)((((double)(++n)) *((double)(++n)))))+((short)((((double)(r.a)) +((double)(++n)))))+((int)((((int)(++n)) >>((int)(r.a))))))) %((int)(((int)((((int)(++n)) >>((int)(++n))))))))))+((long)((((int)(++n + ((110)))) %((int)(++n))))))) ^((int)(r.a)))));
;
;
;
;
  __builtin_memset (r.b, (-((0x1F8D))), sizeof (r.b));
  


r.b[(0x9)] = x + (-(43)) +((int)((((int)(r.b[(0x9)])) &((int)(x)))))*((long)((((int)(r.b[(0x9)])) |((int)(x)))))+((short)((((int)(r.b[(0x9)])) &((int)(x))))) + ((35)) *((long)((((int)(r.b[(0x9)])) &((int)(x + ((106)) +((int)((((int)(r.b[(0x9)])) &((int)(x)))))*((long)((((int)(r.b[(0x9)])) |((int)(x)))))+((short)((((int)(r.b[(0x9)])) &((int)(x))))))))))+((int)((((int)(r.b[(0x9)])) |((int)(r.b[(0x9)]))))) + ((-43)) -((long)((((int)(r.b[(0x9)])) %((int)(x + ((42)) +((int)((((int)(r.b[(0x9)])) &((int)(x)))))*((long)((((int)(r.b[(0x9)])) |((int)(x)))))+((short)((((int)(r.b[(0x9)])) &((int)(x))))) + (-(03)) *((long)((((int)(r.b[(0x9)])) &((int)(x + (-(42)) +((int)((((int)(r.b[(0x9)])) &((int)(x)))))*((long)((((int)(r.b[(0x9)])) |((int)(x)))))+((short)((((int)(r.b[(0x9)])) &((int)(x))))))))))+((int)((((int)(r.b[(0x9)])) |((int)(r.b[(0x9)]))))))))));
r.b[(0x9)] = x + (-(0x10C)) +((int)((((int)(r.b[(0x9)])) &((int)(x)))))*((long)((((int)(r.b[(0x9)])) |((int)(x)))))+((short)((((int)(r.b[(0x9)])) &((int)(x))))) + ((43)) *((long)((((int)(r.b[(0x9)])) &((int)(x + ((-43)) +((int)((((int)(r.b[(0x9)])) &((int)(x)))))*((long)((((int)(r.b[(0x9)])) |((int)(x)))))+((short)((((int)(r.b[(0x9)])) &((int)(x))))))))))+((int)((((int)(r.b[(0x9)])) |((int)(r.b[(0x9)]))))) + ((58)) -((long)((((int)(r.b[(0x9)])) %((int)(x + ((46)) +((int)((((int)(r.b[(0x9)])) &((int)(x)))))*((long)((((int)(r.b[(0x9)])) |((int)(x)))))+((short)((((int)(r.b[(0x9)])) &((int)(x))))) + (-(41)) *((long)((((int)(r.b[(0x9)])) &((int)(x + (-(-44)) +((int)((((int)(r.b[(0x9)])) &((int)(x)))))*((long)((((int)(r.b[(0x9)])) |((int)(x)))))+((short)((((int)(r.b[(0x9)])) &((int)(x))))))))))+((int)((((int)(r.b[(0x9)])) |((int)(r.b[(0x9)]))))))))));
;
;
;
;
;
  return r;
}

__attribute__((noinline, noclone))
void
baz (void)
{
  asm volatile ("" : : : "memory");
}

__attribute__((noinline, noclone))
void
foo (struct A *x, int y)
{
  if ((0x294))
    ;
  else
    ;
  baz ();
}

int
main ()
{
  

;
;
;
;
;
  
;
;
;
  if (((int)((int)((int)a.a != ((0x9)) || a.b[(((135)))] != (((19))) || b.a != (-((67))) || b.b[(-((1)))] != ((0x4)) + (-(53)) +((short)((((int)(a.a != (((-2))))) %((int)(a.a != ((0x7D)))))))+((long)((((int)(a.b[((-(17)))])) ^((int)((((36))))))))*((long)((((int)((-((-8))))) |((int)(a.b[((-(0)))])))))+((long)((((int)(a.a != (((129))))) <<((int)(a.a != ((-(2))) || a.b[(((15777216)))] != (((-4))))))))-((long)((((double)(a.a != (((33))))) +((double)(((-(-5))))))))*((int)((((int)(a.b[(((0)))] != (((18))))) <<((int)(b.a != (-(0x5D)))))))-((short)((((int)(b.a)) ^((int)(b.b[(-((13)))])))))*((short)((((int)(a.a != ((0x8)))) |((int)(a.b[((0xB15A))] != ((0xC)))))))) + (-(-44)) *((int)((((int)(a.b[((0x119C7))] != ((0x68)))) &((int)(((long)((((int)(a.b[(((-1)))])) ^((int)(((0xF)))))))*((long)((((int)((-(-(4))))) |((int)(a.b[(((-5)))]))))))))))*((int)((((int)(((0x8)) + ((0x4D6)) +((short)((((int)(a.a != (((0x5))))) %((int)(a.a != (((1))))))))+((long)((((int)(a.b[(((1)))])) ^((int)(((0x82E8)))))))*((long)((((int)((-(0xF98)))) |((int)(a.b[(((0)))])))))+((long)((((int)(a.a != ((0x625C5)))) <<((int)(a.a != ((-(0x9070))) || a.b[(((0)))] != (((0x6))))))))-((long)((((double)(a.a != ((-(0x7E7B))))) +((double)((((11))))))))*((int)((((int)(a.b[((-(0x0C14D)))] != ((-(0xD55F))))) <<((int)(b.a != (-((14))))))))-((short)((((int)(b.a)) ^((int)(b.b[(-((0xD046B)))])))))*((short)((((int)(a.a != (((65))))) |((int)(a.b[((0x6E08))] != (((-4)))))))))) &((int)(((int)((((int)(a.b[((-(5)))] != ((0x675)))) <<((int)(b.a != (-(0x2FA20))))))))))))-((int)((((int)((int)a.a != (((2))) || a.b[((0x9))] != (((-4))) || b.a != (-(0xC7EA1)))) |((int)((int)a.a != ((0x708)))))))*((short)((((int)((((8))) + ((62)) +((short)((((int)(a.a != (((-6))))) %((int)(a.a != ((0xA13)))))))+((long)((((int)(a.b[((0x2))])) ^((int)(((-(5))))))))*((long)((((int)((-((15))))) |((int)(a.b[(((0)))])))))+((long)((((int)(a.a != ((-(0xAF9))))) <<((int)(a.a != (((-2))) || a.b[(((-129)))] != ((0x3A280)))))))-((long)((((double)(a.a != ((0x4EEF4)))) +((double)(((0xCC735)))))))*((int)((((int)(a.b[(((0x35)))] != ((0x1F)))) <<((int)(b.a != (-(-(-5)))))))))) |((int)(((-(10))))))))) + ((-46)) +((long)((((int)((-(-44)))) |((int)(((int)((((int)((int)a.a != ((-(0x8))) || a.b[(((-4194305)))] != (((131))) || b.a != (-((7))))) |((int)((int)a.a != (((-66))))))))*((short)((((int)((((0x1))) + (0xF0D) +((short)((((int)(a.a != ((0x9CBC)))) %((int)(a.a != ((0xD)))))))+((long)((((int)(a.b[(((0x10620)))])) ^((int)((((-5))))))))*((long)((((int)((-((0x072E834))))) |((int)(a.b[((0xA))])))))+((long)((((int)(a.a != ((0xF4F34)))) <<((int)(a.a != ((0xB1E)) || a.b[((-(129)))] != (((0x0346))))))))-((long)((((double)(a.a != (((3))))) +((double)(((0x57EAC)))))))*((int)((((int)(a.b[(((0)))] != (((0x6CAEC))))) <<((int)(b.a != (-(0x4F79C))))))))) |((int)((((1)))))))))))))-((long)((((int)((int)((int)a.a != ((-(0x1B4))) || a.b[(((0)))] != (((0xA13E8))) || b.a != (-(0x9)) || b.b[(-(0xC))] != (((132))) + (0xF3) +((short)((((int)(a.a != (((1))))) %((int)(a.a != (((-2))))))))+((long)((((int)(a.b[((0x653E))])) ^((int)((((0xE1))))))))*((long)((((int)((-((0xC))))) |((int)(a.b[((0x01))])))))+((long)((((int)(a.a != (((-18))))) <<((int)(a.a != ((-(66))) || a.b[((0x38C))] != (((0x5F25))))))))-((long)((((double)(a.a != ((-(2))))) +((double)((((-4))))))))*((int)((((int)(a.b[((-(-2)))] != ((0x0B7)))) <<((int)(b.a != (-(-(20))))))))-((short)((((int)(b.a)) ^((int)(b.b[(-((0xB06)))])))))*((short)((((int)(a.a != (((-66))))) |((int)(a.b[(((0x950)))] != (((3))))))))) + ((0x0D1)) *((int)((((int)(a.b[((0x37))] != (((0x2A))))) &((int)(((long)((((int)(a.b[(((0)))])) ^((int)((((-5))))))))*((long)((((int)((-((11))))) |((int)(a.b[(((-274877906945)))]))))))))))*((int)((((int)(((-(-6))) + ((34)) +((short)((((int)(a.a != ((0x17C9)))) %((int)(a.a != ((0xEA)))))))+((long)((((int)(a.b[(((0)))])) ^((int)((((-37))))))))*((long)((((int)((-(0xDC)))) |((int)(a.b[(((0)))])))))+((long)((((int)(a.a != ((-(34))))) <<((int)(a.a != ((-(2))) || a.b[((-(-2)))] != (((0x8B0))))))))-((long)((((double)(a.a != (((17))))) +((double)((((3))))))))*((int)((((int)(a.b[((0x7A))] != ((-(36))))) <<((int)(b.a != (-((3))))))))-((short)((((int)(b.a)) ^((int)(b.b[(-((-2)))])))))*((short)((((int)(a.a != ((0x7C85)))) |((int)(a.b[(((0)))] != ((0xEEDC))))))))) &((int)(((int)((((int)(a.b[(((16)))] != ((0x8EF)))) <<((int)(b.a != (-(0xFC63)))))))))))))) <<((int)((0x0B1B))))))-((short)((((int)(((int)((((int)((int)a.a != ((0xA932)) || a.b[((0xF46E))] != ((0x78A9D)) || b.a != (-((147))))) |((int)((int)a.a != (((-2))))))))*((short)((((int)((((0xC))) + ((0x9F)) +((short)((((int)(a.a != ((-(-3))))) %((int)(a.a != ((-(0))))))))+((long)((((int)(a.b[(((0x225)))])) ^((int)(((-(0x49))))))))*((long)((((int)((-((27))))) |((int)(a.b[(((0)))])))))+((long)((((int)(a.a != ((-(0x77F3F))))) <<((int)(a.a != ((0xDC9)) || a.b[(((0x2289E)))] != ((0x1)))))))-((long)((((double)(a.a != ((-(-3))))) +((double)((((0xEEDA))))))))*((int)((((int)(a.b[((0xE))] != ((-(0x7250))))) <<((int)(b.a != (-(0x53))))))))) |((int)((((0xB0B1)))))))))) |((int)(((43)))))))-((short)((((int)(((int)((((int)(a.b[(((67108864)))] != (((0xEDD))))) &((int)(((long)((((int)(a.b[(((-1)))])) ^((int)(((0x26)))))))*((long)((((int)((-((0xBF))))) |((int)(a.b[(((0x4F)))])))))))))))) &((int)((int)((int)a.a != (((0xB27E))) || a.b[((0x8E00C))] != ((0xBF)) || b.a != (-((139))) || b.b[(-((9)))] != ((-(0x2A))) + ((-11)) +((short)((((int)(a.a != (((-10))))) %((int)(a.a != (((129))))))))+((long)((((int)(a.b[(((0)))])) ^((int)(((0x75BE2)))))))*((long)((((int)((-((5))))) |((int)(a.b[((0xEBF54))])))))+((long)((((int)(a.a != ((-(2))))) <<((int)(a.a != (((129))) || a.b[((0x9C336))] != ((0x416)))))))-((long)((((double)(a.a != ((-(2))))) +((double)((((2))))))))*((int)((((int)(a.b[((0xABDB1))] != (((1))))) <<((int)(b.a != (-(0xD085)))))))-((short)((((int)(b.a)) ^((int)(b.b[(-((0x506DD)))])))))*((short)((((int)(a.a != ((0x1)))) |((int)(a.b[(((-4398046511105)))] != (((3))))))))))))))-((short)((((int)(((int)((((int)(((-(21))) + (0xF8290) +((short)((((int)(a.a != ((-(0x08))))) %((int)(a.a != (((0x01))))))))+((long)((((int)(a.b[(((0xE4E5)))])) ^((int)(((-(5))))))))*((long)((((int)((-((0x2629))))) |((int)(a.b[((-(-2)))])))))+((long)((((int)(a.a != ((0x0E1)))) <<((int)(a.a != ((0x0123)) || a.b[(((0)))] != ((0x95CD)))))))-((long)((((double)(a.a != (((0xE75E))))) +((double)(((-(-5))))))))*((int)((((int)(a.b[((0xBBA3A))] != (((0xCCA))))) <<((int)(b.a != (-((4))))))))-((short)((((int)(b.a)) ^((int)(b.b[(-(0xA))])))))*((short)((((int)(a.a != (((-34))))) |((int)(a.b[(((0)))] != (((0x0)))))))))) &((int)(((int)((((int)(a.b[(((0)))] != ((0xE)))) <<((int)(b.a != (-((139))))))))))))))) |((int)(((int)((((int)((int)a.a != ((0xCBACD)) || a.b[(((64)))] != (((0x7098))) || b.a != (-((0x3DEB))))) |((int)((int)a.a != (((0x5)))))))))))))-((int)((((int)(((int)((((int)((((4))) + (-(43)) +((short)((((int)(a.a != ((0xA)))) %((int)(a.a != (((0x1))))))))+((long)((((int)(a.b[((0x6A8))])) ^((int)(((0xF)))))))*((long)((((int)((-((-68))))) |((int)(a.b[((-(0x81C55)))])))))+((long)((((int)(a.a != (((-2))))) <<((int)(a.a != ((0x1E009)) || a.b[(((536870912)))] != (((-4))))))))-((long)((((double)(a.a != (((0xB2F))))) +((double)(((-(0x70))))))))*((int)((((int)(a.b[(((-1)))] != ((-(132))))) <<((int)(b.a != (-(0x15B32)))))))-((short)((((int)(b.a)) ^((int)(b.b[(-((3)))])))))*((short)((((int)(a.a != ((-(2))))) |((int)(a.b[((0x926))] != ((-(0x5B32)))))))))) &((int)(((int)((((int)(a.b[(((0x5)))] != (((0x152B6))))) <<((int)(b.a != (-((131))))))))))))))) >>((int)((int)((int)a.a != (((8))) || a.b[((0xFEC6B))] != (((19))) || b.a != (-(0x374)) || b.b[(-(0xBCFB))] != ((-(0xBA64))) + (-(43)) +((short)((((int)(a.a != (((129))))) %((int)(a.a != ((-(0xC36))))))))+((long)((((int)(a.b[((-(1)))])) ^((int)(((-(0x5E9))))))))*((long)((((int)((-(0x68F)))) |((int)(a.b[(((0)))])))))+((long)((((int)(a.a != ((-(0x1A6))))) <<((int)(a.a != (((1))) || a.b[(((0x6F417)))] != ((0x2522)))))))-((long)((((double)(a.a != ((-(66))))) +((double)((((3))))))))*((int)((((int)(a.b[(((136)))] != (((-4))))) <<((int)(b.a != (-((7))))))))-((short)((((int)(b.a)) ^((int)(b.b[(-((-4)))])))))*((short)((((int)(a.a != ((-(6))))) |((int)(a.b[((0xD88))] != ((-(-5))))))))))))))+((int)((((int)(((42)))) <<((int)(((short)((((int)(((-(5))) + ((104)) +((short)((((int)(a.a != (((0xFE25))))) %((int)(a.a != (((0x5F))))))))+((long)((((int)(a.b[((-(1)))])) ^((int)(((-(0x89))))))))*((long)((((int)((-((0x73162))))) |((int)(a.b[(((0x14C)))])))))+((long)((((int)(a.a != (((-66))))) <<((int)(a.a != (((-2))) || a.b[((0x8))] != ((-(-5))))))))-((long)((((double)(a.a != ((-(2))))) +((double)(((0x5)))))))*((int)((((int)(a.b[(((17)))] != ((0x233)))) <<((int)(b.a != (-((17)))))))))) |((int)(((-(2)))))))))))))*((short)((((int)(((0x1F9)))) %((int)((int)((int)a.a != (((0))) || a.b[((0x954))] != ((-(0xE))) || b.a != (-((-4))) || b.b[(-(-(2)))] != ((0xB)) + ((34)) +((short)((((int)(a.a != (((9))))) %((int)(a.a != (((6))))))))+((long)((((int)(a.b[((0xD563))])) ^((int)(((-(69))))))))*((long)((((int)((-(-(4))))) |((int)(a.b[(((0)))])))))+((long)((((int)(a.a != (((-1))))) <<((int)(a.a != (((-2))) || a.b[((0x7C9))] != (((-36))))))))-((long)((((double)(a.a != ((0x9)))) +((double)((((23))))))))*((int)((((int)(a.b[((0xF8451))] != ((-(4))))) <<((int)(b.a != (-((-12))))))))-((short)((((int)(b.a)) ^((int)(b.b[(-((0x79AF)))])))))*((short)((((int)(a.a != (((17))))) |((int)(a.b[(((-33)))] != (((4))))))))))))))))
    { abort (); }
  foo (&b, (((0x4B20))));
  if (((int)((int)((int)a.a != ((0x2E)) || a.b[((-(0x00D5C)))] != (0x7) || b.a != ((-(7))) || b.b[((-(33)))] != (0x9) + (0x2F) -((int)((((int)(a.b[((-(0)))])) <<((int)(a.b[(((-2)))] != (0x7))))))) + (0xC2C) *((int)((((int)(b.b[(((0x1731)))] != (0x9) + (0xCC36) -((int)((((int)(a.b[((0x926C))])) <<((int)(a.b[(((-1099511627777)))] != (0x7)))))))) >>((int)(((int)((((int)(a.b[(((16)))])) <<((int)(a.b[((-(3)))] != (0x7)))))))))))*((int)((((int)((((5))))) ^((int)(a.b[(((117438953472)))] != (0x7))))))+((short)((((int)((int)a.a != ((0xE8D)) || a.b[(((1342177280)))] != (0x7))) |((int)((0xE28FFE))))))+((int)((((int)(b.b[(((0x76AC9)))])) &((int)((0x7))))))+((int)((((int)((int)a.a != (((0x7))) || a.b[((0x729))] != (0x7))) ^((int)((int)a.a != ((0x4EE77)) || a.b[(((0)))] != (0x7) || b.a != (((35184372088832))))))))*((int)((((int)((int)a.a != (((35))) || a.b[((-(0x9C)))] != (0x7) || b.a != (((0xE15B5))))) |((int)(b.a)))))-((long)((((int)((0x7))) &((int)((-(-44)))))))*((int)((((int)((((71))))) <<((int)(a.b[(((-549755813889)))])))))) + ((42)) +((int)((((int)((int)((int)a.a != (((33))) || a.b[((-(0x9)))] != (0x7) || b.a != (((3))) || b.b[((0x2A))] != (0x9) + (-(41)) -((int)((((int)(a.b[((-(0x69)))])) <<((int)(a.b[((0xE9D))] != (0x7))))))) + (-(43)) *((int)((((int)(b.b[((-(41)))] != (0x9) + ((46)) -((int)((((int)(a.b[(((8)))])) <<((int)(a.b[((0xA))] != (0x7)))))))) >>((int)(((int)((((int)(a.b[(((-1)))])) <<((int)(a.b[((-(0xD06)))] != (0x7)))))))))))*((int)((((int)(((0x6)))) ^((int)(a.b[(((0x5)))] != (0x7))))))+((short)((((int)((int)a.a != ((0xD)) || a.b[(((0x909C76)))] != (0x7))) |((int)((-(41)))))))+((int)((((int)(b.b[(((0x99)))])) &((int)((0x7))))))+((int)((((int)((int)a.a != (((63))) || a.b[((0x727))] != (0x7))) ^((int)((int)a.a != (((-2))) || a.b[((-(0x6D744)))] != (0x7) || b.a != (((-16))))))))*((int)((((int)((int)a.a != ((-(18))) || a.b[((0xB287))] != (0x7) || b.a != (((0x38CF2))))) |((int)(b.a))))))) ^((int)((int)((int)a.a != ((-(10))) || a.b[(((160)))] != (0x7) || b.a != (((21))) || b.b[((-(33)))] != (0x9) + ((-47)) -((int)((((int)(a.b[(((144115188075755872)))])) <<((int)(a.b[((-(0)))] != (0x7))))))) + (0x6A24A) *((int)((((int)(b.b[((-(-34)))] != (0x9) + (0x7CA) -((int)((((int)(a.b[(((0xBC2)))])) <<((int)(a.b[((0xE41DA))] != (0x7)))))))) >>((int)(((int)((((int)(a.b[(((0)))])) <<((int)(a.b[((0x1E))] != (0x7)))))))))))*((int)((((int)(((-(0))))) ^((int)(a.b[((-(-2)))] != (0x7))))))+((short)((((int)((int)a.a != (((-2))) || a.b[(((0x5)))] != (0x7))) |((int)(((42)))))))+((int)((((int)(b.b[(((40)))])) &((int)((0x7))))))+((int)((((int)((int)a.a != (((5))) || a.b[(((0x4D21)))] != (0x7))) ^((int)((int)a.a != (((17))) || a.b[(((6)))] != (0x7) || b.a != (((-8))))))))*((int)((((int)((int)a.a != ((0xF)) || a.b[((0x489B0))] != (0x7) || b.a != ((0xF)))) |((int)(b.a))))))))))))
    { abort (); }
  foo (&b, (0xC));
  if (((int)((int)((int)a.a != ((-(-7))) || a.b[(0x51B8)] != (((-66))) || b.a != (0x7744) || b.b[(0xA)] != ((0x8)) + ((58)) -((long)((((int)(b.a)) <<((int)(a.a != (((39))) || a.b[(0x51B8)] != (((1))))))))-((short)((((double)((((68))))) -((double)(a.a != (((0x8C47B))))))))*((short)((((int)(b.a != (0x7744))) &((int)(a.a != (((-6))) || a.b[(0x51B8)] != (((81))) || b.a != (0x7744))))))+((short)((((int)(a.a != (((0xC9DB))) || a.b[(0x51B8)] != (((0x24606))))) <<((int)(a.a != ((0xE1)))))))*((long)((((int)(a.a != ((-(2))))) >>((int)(b.a != (0x7744))))))*((int)((((double)(((0x284A6)))) +((double)(a.a != (((-6))))))))-((long)((((int)(a.b[(0x51B8)])) |((int)(a.a != (((0x786301))) || a.b[(0x51B8)] != (((129))) || b.a != (0x7744))))))) + (0xE97) +((short)((((int)(((short)((((double)(((-(70))))) -((double)(a.a != ((-(-7))))))))*((short)((((int)(b.a != (0x7744))) &((int)(a.a != ((-(6))) || a.b[(0x51B8)] != ((0xD)) || b.a != (0x7744)))))))) <<((int)((((0x88))) + (0x7BCAAA))))))+((int)((((int)(((-(0x938A))) + (0x6493) -((long)((((int)(b.a)) <<((int)(a.a != (((2))) || a.b[(0x51B8)] != (((0xDE76)))))))))) <<((int)(((long)((((int)(a.b[(0x51B8)])) |((int)(a.a != (((3))) || a.b[(0x51B8)] != ((-(-3))) || b.a != (0x7744)))))))))))) + ((-43)) +((short)((((int)((int)((int)a.a != (((-134))) || a.b[(0x51B8)] != (((0x8))) || b.a != (0x7744) || b.b[(0xA)] != (((-24))) + ((42)) -((long)((((int)(b.a)) <<((int)(a.a != (((5))) || a.b[(0x51B8)] != (((0x99))))))))-((short)((((double)((((0x4D865))))) -((double)(a.a != (((65))))))))*((short)((((int)(b.a != (0x7744))) &((int)(a.a != ((0x279)) || a.b[(0x51B8)] != ((0x69)) || b.a != (0x7744))))))+((short)((((int)(a.a != (((69))) || a.b[(0x51B8)] != (((-66))))) <<((int)(a.a != (((13))))))))*((long)((((int)(a.a != (((0x2))))) >>((int)(b.a != (0x7744))))))*((int)((((double)(((0xFF)))) +((double)(a.a != (((4))))))))-((long)((((int)(a.b[(0x51B8)])) |((int)(a.a != ((-(7))) || a.b[(0x51B8)] != ((-(2))) || b.a != (0x7744))))))) + (-(43)))) >>((int)((int)((int)a.a != ((0xBF2)) || a.b[(0x51B8)] != (((97))) || b.a != (0x7744) || b.b[(0xA)] != ((-(8))) + ((170)) -((long)((((int)(b.a)) <<((int)(a.a != (((5))) || a.b[(0x51B8)] != (((0x0287))))))))-((short)((((double)(((0x01)))) -((double)(a.a != (((3))))))))*((short)((((int)(b.a != (0x7744))) &((int)(a.a != ((0x52E3)) || a.b[(0x51B8)] != (((129))) || b.a != (0x7744))))))+((short)((((int)(a.a != ((-(0xE4BE))) || a.b[(0x51B8)] != ((0x6D2D)))) <<((int)(a.a != (((0xC6))))))))*((long)((((int)(a.a != (((0x8))))) >>((int)(b.a != (0x7744))))))*((int)((((double)((((135))))) +((double)(a.a != (((-38))))))))-((long)((((int)(a.b[(0x51B8)])) |((int)(a.a != (((45))) || a.b[(0x51B8)] != ((-(0xBC606))) || b.a != (0x7744))))))))))))*((long)((((int)((int)((int)a.a != ((-(70))) || a.b[(0x51B8)] != ((0x99)) || b.a != (0x7744) || b.b[(0xA)] != ((-(-9))) + (0x90) -((long)((((int)(b.a)) <<((int)(a.a != (((0x4E))) || a.b[(0x51B8)] != (((129))))))))-((short)((((double)(((0x42D09)))) -((double)(a.a != (((0xE1))))))))*((short)((((int)(b.a != (0x7744))) &((int)(a.a != ((0xBB78)) || a.b[(0x51B8)] != (((0x42E))) || b.a != (0x7744))))))+((short)((((int)(a.a != ((-(0x164A))) || a.b[(0x51B8)] != ((0x149C3)))) <<((int)(a.a != (((4))))))))*((long)((((int)(a.a != ((-(-7))))) >>((int)(b.a != (0x7744))))))*((int)((((double)((((-8))))) +((double)(a.a != (((-6))))))))-((long)((((int)(a.b[(0x51B8)])) |((int)(a.a != ((-(-7))) || a.b[(0x51B8)] != ((-(-3))) || b.a != (0x7744))))))) + ((0xF07)) +((short)((((int)(((short)((((double)((((0x9B14))))) -((double)(a.a != ((0x3BE)))))))*((short)((((int)(b.a != (0x7744))) &((int)(a.a != (((-8))) || a.b[(0x51B8)] != ((0x7E72)) || b.a != (0x7744)))))))) <<((int)(((0xD2A9C)) + (-(0x545A))))))))) &((int)((int)((int)a.a != (((0xC7B7))) || a.b[(0x51B8)] != (((19))) || b.a != (0x7744) || b.b[(0xA)] != (((135))) + ((46)) -((long)((((int)(b.a)) <<((int)(a.a != (((-6))) || a.b[(0x51B8)] != ((-(2))))))))-((short)((((double)((((1))))) -((double)(a.a != ((-(6))))))))*((short)((((int)(b.a != (0x7744))) &((int)(a.a != (((7))) || a.b[(0x51B8)] != (((0xAC7F))) || b.a != (0x7744))))))+((short)((((int)(a.a != (((5))) || a.b[(0x51B8)] != (((1))))) <<((int)(a.a != ((0x6)))))))*((long)((((int)(a.a != (((141))))) >>((int)(b.a != (0x7744))))))*((int)((((double)((((0x80))))) +((double)(a.a != ((-(0x5CA))))))))-((long)((((int)(a.b[(0x51B8)])) |((int)(a.a != ((-(-7))) || a.b[(0x51B8)] != (((0x7))) || b.a != (0x7744))))))) + ((-43)) +((short)((((int)(((short)((((double)(((0x91F0A)))) -((double)(a.a != ((-(6))))))))*((short)((((int)(b.a != (0x7744))) &((int)(a.a != (((-6))) || a.b[(0x51B8)] != ((-(-3))) || b.a != (0x7744)))))))) <<((int)(((-(-9))) + ((42))))))))))))-((int)((((int)((int)((int)a.a != (((0x5B))) || a.b[(0x51B8)] != (((1))) || b.a != (0x7744) || b.b[(0xA)] != ((0xDC)) + (0xF872) -((long)((((int)(b.a)) <<((int)(a.a != ((-(0xCE))) || a.b[(0x51B8)] != ((-(10))))))))-((short)((((double)(((0xF9F8)))) -((double)(a.a != (((0x935))))))))*((short)((((int)(b.a != (0x7744))) &((int)(a.a != ((-(0x3EB8))) || a.b[(0x51B8)] != ((-(0x6AA))) || b.a != (0x7744))))))+((short)((((int)(a.a != (((1))) || a.b[(0x51B8)] != ((0xC)))) <<((int)(a.a != (((21))))))))*((long)((((int)(a.a != (((-6))))) >>((int)(b.a != (0x7744))))))*((int)((((double)((((0x3))))) +((double)(a.a != (((-2))))))))-((long)((((int)(a.b[(0x51B8)])) |((int)(a.a != (((5))) || a.b[(0x51B8)] != (((-18))) || b.a != (0x7744))))))) + (-(47)))) %((int)(((int)((((int)(((0x9)) + ((92)) -((long)((((int)(b.a)) <<((int)(a.a != (((0x7))) || a.b[(0x51B8)] != (((65)))))))))) <<((int)(((long)((((int)(a.b[(0x51B8)])) |((int)(a.a != ((0xFCBF)) || a.b[(0x51B8)] != (((1))) || b.a != (0x7744))))))))))))))))-((int)((((int)(((short)((((int)(((short)((((double)(((-(-7))))) -((double)(a.a != (((13))))))))*((short)((((int)(b.a != (0x7744))) &((int)(a.a != ((-(6))) || a.b[(0x51B8)] != ((0xF)) || b.a != (0x7744)))))))) <<((int)(((0xBCE02)) + ((0x8E))))))))) <<((int)(((int)((((int)(((-(-9))) + ((-59)) -((long)((((int)(b.a)) <<((int)(a.a != (((-14))) || a.b[(0x51B8)] != (((0xF6D6)))))))))) <<((int)(((long)((((int)(a.b[(0x51B8)])) |((int)(a.a != ((-(38))) || a.b[(0x51B8)] != ((0x47C)) || b.a != (0x7744))))))))))))))))-((long)((((int)((int)((int)a.a != ((-(-7))) || a.b[(0x51B8)] != ((0x3E28)) || b.a != (0x7744) || b.b[(0xA)] != ((0x1D5CE)) + (0xC84A96) -((long)((((int)(b.a)) <<((int)(a.a != ((0xA4D32)) || a.b[(0x51B8)] != (((0xC80))))))))-((short)((((double)((((-14))))) -((double)(a.a != (((21))))))))*((short)((((int)(b.a != (0x7744))) &((int)(a.a != ((-(7))) || a.b[(0x51B8)] != ((0x5)) || b.a != (0x7744))))))+((short)((((int)(a.a != ((0xAB2)) || a.b[(0x51B8)] != ((0xC693B)))) <<((int)(a.a != (((135))))))))*((long)((((int)(a.a != ((-(6))))) >>((int)(b.a != (0x7744))))))*((int)((((double)((((-7))))) +((double)(a.a != (((5))))))))-((long)((((int)(a.b[(0x51B8)])) |((int)(a.a != ((0x4E)) || a.b[(0x51B8)] != ((0xCFAB5)) || b.a != (0x7744))))))) + ((-47)) +((short)((((int)(((short)((((double)((((0xB9))))) -((double)(a.a != (((0x4607F))))))))*((short)((((int)(b.a != (0x7744))) &((int)(a.a != ((-(-7))) || a.b[(0x51B8)] != ((0x7D0BF)) || b.a != (0x7744)))))))) <<((int)(((-(-9))) + ((-47))))))))) &((int)(((40)))))))*((long)((((int)(((short)((((int)(((short)((((double)((((1))))) -((double)(a.a != ((0x18FD)))))))*((short)((((int)(b.a != (0x7744))) &((int)(a.a != (((133))) || a.b[(0x51B8)] != (((-2))) || b.a != (0x7744)))))))) <<((int)((((7))) + ((114))))))))) ^((int)((0x27EE2))))))-((short)((((int)(((-11)))) >>((int)(((int)((((int)((((55))) + ((40)) -((long)((((int)(b.a)) <<((int)(a.a != ((0xD7)) || a.b[(0x51B8)] != ((0xA6))))))))) <<((int)(((long)((((int)(a.b[(0x51B8)])) |((int)(a.a != ((-(-7))) || a.b[(0x51B8)] != (((65))) || b.a != (0x7744))))))))))))))))+((long)((((int)((int)((int)a.a != (((0x2))) || a.b[(0x51B8)] != (((7))) || b.a != (0x7744) || b.b[(0xA)] != ((-(8))) + ((-59)) -((long)((((int)(b.a)) <<((int)(a.a != ((0x19)) || a.b[(0x51B8)] != (((-2))))))))-((short)((((double)((((36))))) -((double)(a.a != (((0))))))))*((short)((((int)(b.a != (0x7744))) &((int)(a.a != (((0xC93CC1))) || a.b[(0x51B8)] != (((129))) || b.a != (0x7744))))))+((short)((((int)(a.a != ((0x4FFC)) || a.b[(0x51B8)] != ((-(0xD1))))) <<((int)(a.a != (((37))))))))*((long)((((int)(a.a != ((0x703)))) >>((int)(b.a != (0x7744))))))*((int)((((double)((((5))))) +((double)(a.a != (((-38))))))))-((long)((((int)(a.b[(0x51B8)])) |((int)(a.a != (((0x089F))) || a.b[(0x51B8)] != ((-(2))) || b.a != (0x7744))))))))) <<((int)((-(41)))))))-((int)((((int)((int)((int)a.a != ((-(6))) || a.b[(0x51B8)] != ((0xE00)) || b.a != (0x7744) || b.b[(0xA)] != (((23))) + ((42)) -((long)((((int)(b.a)) <<((int)(a.a != ((-(0x44))) || a.b[(0x51B8)] != ((-(130))))))))-((short)((((double)((((13))))) -((double)(a.a != (((-22))))))))*((short)((((int)(b.a != (0x7744))) &((int)(a.a != (((0x91))) || a.b[(0x51B8)] != ((0x8)) || b.a != (0x7744))))))+((short)((((int)(a.a != (((101))) || a.b[(0x51B8)] != ((-(10))))) <<((int)(a.a != (((-70))))))))*((long)((((int)(a.a != ((0x92F)))) >>((int)(b.a != (0x7744))))))*((int)((((double)(((-(0x6))))) +((double)(a.a != ((0x6D2)))))))-((long)((((int)(a.b[(0x51B8)])) |((int)(a.a != ((0x1)) || a.b[(0x51B8)] != (((8))) || b.a != (0x7744))))))) + ((0xC71326)))) ^((int)(((short)((((int)(((short)((((double)((((0x7688))))) -((double)(a.a != ((-(4))))))))*((short)((((int)(b.a != (0x7744))) &((int)(a.a != ((0x6B5B0)) || a.b[(0x51B8)] != ((0x025)) || b.a != (0x7744)))))))) <<((int)(((-(-9))) + ((34))))))))))))))
    { abort (); }
  return (-(-(0x1DEF)));
}
/* ProgramSourceLLVM */
