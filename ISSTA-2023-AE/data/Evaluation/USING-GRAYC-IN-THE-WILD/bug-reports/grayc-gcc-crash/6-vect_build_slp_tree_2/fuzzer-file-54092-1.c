/* corpus/20050119-1.c */
/* PR c/19342 */
typedef enum { A, B, C, D } E;

struct S {
  E __attribute__ ((mode (__byte__))) a;
  E __attribute__ ((mode (__byte__))) b;
  E __attribute__ ((mode (__byte__))) c;
  E __attribute__ ((mode (__byte__))) d;
};

extern void abort (void);
extern void exit (int);

void
foo (struct S *s)
{
  if (((int)((int)((int)s->a != s->b + (-(49)) +((short)((((double)(s->a)) -((double)(s->b)))))+((int)((((double)(s->b)) +((double)(s->a)))))*((long)((((int)(s->b)) >>((int)(s->a)))))-((long)((((int)(s->b)) ^((int)(s->b)))))) + (0x85E9A) +((long)((((int)(s->b + ((104)) +((short)((((double)(s->a)) -((double)(s->b)))))+((int)((((double)(s->b)) +((double)(s->a)))))*((long)((((int)(s->b)) >>((int)(s->a))))))) <<((int)(((int)((((double)(s->b)) +((double)(s->a))))))))))+((int)((((int)(((long)((((int)(s->b)) >>((int)(s->a))))))) <<((int)(((int)((((double)(s->b)) +((double)(s->a)))))*((long)((((int)(s->b)) >>((int)(s->a))))))))))-((int)((((int)(((int)((((double)(s->b)) +((double)(s->a)))))*((long)((((int)(s->b)) >>((int)(s->a))))))) |((int)(s->b + ((62)) +((short)((((double)(s->a)) -((double)(s->b)))))+((int)((((double)(s->b)) +((double)(s->a)))))*((long)((((int)(s->b)) >>((int)(s->a)))))-((long)((((int)(s->b)) ^((int)(s->b))))))))))+((int)((((int)(((int)((((double)(s->b)) +((double)(s->a)))))*((long)((((int)(s->b)) >>((int)(s->a))))))) %((int)(s->b + (-(0x9A220)) +((short)((((double)(s->a)) -((double)(s->b))))))))))-((long)((((int)(s->b + (0xF129) +((short)((((double)(s->a)) -((double)(s->b)))))+((int)((((double)(s->b)) +((double)(s->a)))))*((long)((((int)(s->b)) >>((int)(s->a)))))-((long)((((int)(s->b)) ^((int)(s->b))))))) ^((int)(((long)((((int)(s->b)) >>((int)(s->a))))))))))-((short)((((double)(s->b + ((0xF4965)) +((short)((((double)(s->a)) -((double)(s->b))))))) *((double)(((long)((((int)(s->b)) ^((int)(s->b))))))))))+((short)((((int)(s->b + (0x2899B) +((short)((((double)(s->a)) -((double)(s->b)))))+((int)((((double)(s->b)) +((double)(s->a)))))*((long)((((int)(s->b)) >>((int)(s->a)))))-((long)((((int)(s->b)) ^((int)(s->b))))))) >>((int)(((long)((((int)(s->b)) ^((int)(s->b))))))))))*((long)((((int)(s->b + ((42)) +((short)((((double)(s->a)) -((double)(s->b)))))+((int)((((double)(s->b)) +((double)(s->a)))))*((long)((((int)(s->b)) >>((int)(s->a))))))) |((int)(((long)((((int)(s->b)) ^((int)(s->b))))))))))) + (-43) *((int)((((int)((int)((int)s->a != s->b + (-(-44)) +((short)((((double)(s->a)) -((double)(s->b)))))+((int)((((double)(s->b)) +((double)(s->a)))))*((long)((((int)(s->b)) >>((int)(s->a)))))-((long)((((int)(s->b)) ^((int)(s->b)))))) + (0x85E9A) +((long)((((int)(s->b + ((40)) +((short)((((double)(s->a)) -((double)(s->b)))))+((int)((((double)(s->b)) +((double)(s->a)))))*((long)((((int)(s->b)) >>((int)(s->a))))))) <<((int)(((int)((((double)(s->b)) +((double)(s->a))))))))))+((int)((((int)(((long)((((int)(s->b)) >>((int)(s->a))))))) <<((int)(((int)((((double)(s->b)) +((double)(s->a)))))*((long)((((int)(s->b)) >>((int)(s->a))))))))))-((int)((((int)(((int)((((double)(s->b)) +((double)(s->a)))))*((long)((((int)(s->b)) >>((int)(s->a))))))) |((int)(s->b + ((0x7F)) +((short)((((double)(s->a)) -((double)(s->b)))))+((int)((((double)(s->b)) +((double)(s->a)))))*((long)((((int)(s->b)) >>((int)(s->a)))))-((long)((((int)(s->b)) ^((int)(s->b))))))))))+((int)((((int)(((int)((((double)(s->b)) +((double)(s->a)))))*((long)((((int)(s->b)) >>((int)(s->a))))))) %((int)(s->b + (-(43)) +((short)((((double)(s->a)) -((double)(s->b))))))))))-((long)((((int)(s->b + (0xF129) +((short)((((double)(s->a)) -((double)(s->b)))))+((int)((((double)(s->b)) +((double)(s->a)))))*((long)((((int)(s->b)) >>((int)(s->a)))))-((long)((((int)(s->b)) ^((int)(s->b))))))) ^((int)(((long)((((int)(s->b)) >>((int)(s->a))))))))))-((short)((((double)(s->b + ((10)) +((short)((((double)(s->a)) -((double)(s->b))))))) *((double)(((long)((((int)(s->b)) ^((int)(s->b)))))))))))) <<((int)(((long)((((int)(s->b + (0xF129) +((short)((((double)(s->a)) -((double)(s->b)))))+((int)((((double)(s->b)) +((double)(s->a)))))*((long)((((int)(s->b)) >>((int)(s->a)))))-((long)((((int)(s->b)) ^((int)(s->b))))))) ^((int)(((long)((((int)(s->b)) >>((int)(s->a)))))))))))))))+((long)((((int)((int)((int)s->a != s->b + (-(0x56246)) +((short)((((double)(s->a)) -((double)(s->b)))))+((int)((((double)(s->b)) +((double)(s->a)))))*((long)((((int)(s->b)) >>((int)(s->a)))))-((long)((((int)(s->b)) ^((int)(s->b)))))) + (0x85E9A) +((long)((((int)(s->b + ((-41)) +((short)((((double)(s->a)) -((double)(s->b)))))+((int)((((double)(s->b)) +((double)(s->a)))))*((long)((((int)(s->b)) >>((int)(s->a))))))) <<((int)(((int)((((double)(s->b)) +((double)(s->a)))))))))))) %((int)((int)((int)s->a != s->b + (-(43)) +((short)((((double)(s->a)) -((double)(s->b)))))+((int)((((double)(s->b)) +((double)(s->a)))))*((long)((((int)(s->b)) >>((int)(s->a)))))-((long)((((int)(s->b)) ^((int)(s->b)))))) + (0x85E9A) +((long)((((int)(s->b + ((0xA88)) +((short)((((double)(s->a)) -((double)(s->b)))))+((int)((((double)(s->b)) +((double)(s->a)))))*((long)((((int)(s->b)) >>((int)(s->a))))))) <<((int)(((int)((((double)(s->b)) +((double)(s->a))))))))))+((int)((((int)(((long)((((int)(s->b)) >>((int)(s->a))))))) <<((int)(((int)((((double)(s->b)) +((double)(s->a)))))*((long)((((int)(s->b)) >>((int)(s->a))))))))))-((int)((((int)(((int)((((double)(s->b)) +((double)(s->a)))))*((long)((((int)(s->b)) >>((int)(s->a))))))) |((int)(s->b + ((66)) +((short)((((double)(s->a)) -((double)(s->b)))))+((int)((((double)(s->b)) +((double)(s->a)))))*((long)((((int)(s->b)) >>((int)(s->a)))))-((long)((((int)(s->b)) ^((int)(s->b))))))))))+((int)((((int)(((int)((((double)(s->b)) +((double)(s->a)))))*((long)((((int)(s->b)) >>((int)(s->a))))))) %((int)(s->b + (-(42)) +((short)((((double)(s->a)) -((double)(s->b)))))))))))))))))
    { abort (); }
  if (((int)((int)((int)s->c != C + (-(23)) *((long)((((double)(C)) +((double)(C)))))-((int)((((int)(s->c)) ^((int)(s->c)))))-((long)((((double)(C)) +((double)(C)))))+((short)((((double)(C)) *((double)(C)))))*((int)((((double)(C)) -((double)(s->c)))))+((int)((((int)(s->c)) ^((int)(s->c)))))*((long)((((double)(s->c)) +((double)(s->c)))))-((long)((((double)(C)) +((double)(s->c)))))-((short)((((double)(C)) -((double)(s->c)))))) + (0x0B337) +((int)((((int)(C + (-(-44)) *((long)((((double)(C)) +((double)(C)))))-((int)((((int)(s->c)) ^((int)(s->c)))))-((long)((((double)(C)) +((double)(C)))))+((short)((((double)(C)) *((double)(C)))))*((int)((((double)(C)) -((double)(s->c)))))+((int)((((int)(s->c)) ^((int)(s->c)))))*((long)((((double)(s->c)) +((double)(s->c)))))-((long)((((double)(C)) +((double)(s->c)))))-((short)((((double)(C)) -((double)(s->c))))))) <<((int)((int)s->c)))))+((int)((((int)(((int)((((int)(s->c)) ^((int)(s->c)))))*((long)((((double)(s->c)) +((double)(s->c))))))) %((int)(C + ((-43)) *((long)((((double)(C)) +((double)(C)))))-((int)((((int)(s->c)) ^((int)(s->c))))))))))*((int)((((int)(C + (0x2F2C6) *((long)((((double)(C)) +((double)(C)))))-((int)((((int)(s->c)) ^((int)(s->c))))))) >>((int)((0x2A784))))))-((long)((((int)(((int)((((int)(s->c)) ^((int)(s->c)))))*((long)((((double)(s->c)) +((double)(s->c))))))) <<((int)(((long)((((double)(C)) +((double)(C))))))))))+((short)((((int)(((long)((((double)(s->c)) +((double)(s->c))))))) >>((int)(C + (-(43)) *((long)((((double)(C)) +((double)(C)))))-((int)((((int)(s->c)) ^((int)(s->c)))))-((long)((((double)(C)) +((double)(C)))))+((short)((((double)(C)) *((double)(C)))))*((int)((((double)(C)) -((double)(s->c)))))+((int)((((int)(s->c)) ^((int)(s->c)))))*((long)((((double)(s->c)) +((double)(s->c)))))-((long)((((double)(C)) +((double)(s->c)))))-((short)((((double)(C)) -((double)(s->c))))))))))) + (34) -((int)((((int)(((long)((((int)(((int)((((int)(s->c)) ^((int)(s->c)))))*((long)((((double)(s->c)) +((double)(s->c))))))) <<((int)(((long)((((double)(C)) +((double)(C)))))))))))) <<((int)(((short)((((int)(((long)((((double)(s->c)) +((double)(s->c))))))) >>((int)(C + (-(0xB5B1)) *((long)((((double)(C)) +((double)(C)))))-((int)((((int)(s->c)) ^((int)(s->c)))))-((long)((((double)(C)) +((double)(C)))))+((short)((((double)(C)) *((double)(C)))))*((int)((((double)(C)) -((double)(s->c)))))+((int)((((int)(s->c)) ^((int)(s->c)))))*((long)((((double)(s->c)) +((double)(s->c)))))-((long)((((double)(C)) +((double)(s->c)))))-((short)((((double)(C)) -((double)(s->c)))))))))))))))+((long)((((int)(((long)((((int)(((int)((((int)(s->c)) ^((int)(s->c)))))*((long)((((double)(s->c)) +((double)(s->c))))))) <<((int)(((long)((((double)(C)) +((double)(C)))))))))))) &((int)(((long)((((int)(((int)((((int)(s->c)) ^((int)(s->c)))))*((long)((((double)(s->c)) +((double)(s->c))))))) <<((int)(((long)((((double)(C)) +((double)(C)))))))))))))))))
    { abort (); }
}

int
main (void)
{
  struct S s[(0x6FB)];
  s[(0x371)].a = B + ((42)) +((short)((((int)(s[((134479872))].a)) >>((int)(B))))) + ((40)) -((int)((((int)(s[(0xF11)].a)) ^((int)(B + (-(-44)) +((short)((((int)(s[((0))].a)) >>((int)(B))))))))))-((short)((((int)(s[((0xBC5))].a)) ^((int)(B + (-(0xA9)) +((short)((((int)(s[((0xB7))].a)) >>((int)(B)))))))))) + (0x9D6F01) *((int)((((int)(s[(0x371)].a)) ^((int)(s[(0x371)].a)))))*((long)((((int)(s[(0x371)].a)) %((int)(B + ((0x0F)) +((short)((((int)(s[((134217744))].a)) >>((int)(B))))) + ((40)) -((int)((((int)(s[(0xF11)].a)) ^((int)(B + (-(35)) +((short)((((int)(s[((0x1A5))].a)) >>((int)(B))))))))))-((short)((((int)(s[((0))].a)) ^((int)(B + (-(0xC37D6)) +((short)((((int)(s[((0))].a)) >>((int)(B)))))))))))))))*((long)((((int)(s[(0x371)].a)) |((int)(B + ((46)) +((short)((((int)(s[((124217728))].a)) >>((int)(B))))) + ((40)) -((int)((((int)(s[(0xF11)].a)) ^((int)(B + (-(-44)) +((short)((((int)(s[((1))].a)) >>((int)(B))))))))))-((short)((((int)(s[((2))].a)) ^((int)(B + (-(41)) +((short)((((int)(s[((0))].a)) >>((int)(B)))))))))))))))*((long)((((int)(s[(0x371)].a)) <<((int)(s[(0x371)].a)))));
  s[((-1))].b = B + (-(-44)) *((short)((((int)(B)) %((int)(s[((0x0))].b)))))*((short)((((int)(B)) ^((int)(s[((0x813))].b)))))-((short)((((int)(s[((32768))].b)) <<((int)(B)))))-((int)((((int)(s[((68719476736))].b)) %((int)(B)))))-((short)((((double)(B)) -((double)(B))))) + (0xA6EAC) *((long)((((int)(s[(0xD)].b)) &((int)(B + (-(43)) *((short)((((int)(B)) %((int)(s[(-(-2))].b)))))*((short)((((int)(B)) ^((int)(s[(0x6377)].b)))))-((short)((((int)(s[((0x97A8C))].b)) <<((int)(B)))))-((int)((((int)(s[((0x07))].b)) %((int)(B)))))-((short)((((double)(B)) -((double)(B))))))))))-((long)((((int)(s[(-(1))].b)) %((int)(B + ((-43)) *((short)((((int)(B)) %((int)(s[(-(-2))].b)))))*((short)((((int)(B)) ^((int)(s[(0x3AF52)].b)))))-((short)((((int)(s[((0))].b)) <<((int)(B)))))-((int)((((int)(s[((7))].b)) %((int)(B)))))-((short)((((double)(B)) -((double)(B))))))))))-((short)((((int)(s[((0))].b)) >>((int)(s[((0))].b)))))-((short)((((int)(s[((0))].b)) &((int)(s[(0x2E)].b))))) + (42) -((int)((((int)(B + (-(-44)) *((short)((((int)(B)) %((int)(s[((-1))].b)))))*((short)((((int)(B)) ^((int)(s[((-1))].b)))))-((short)((((int)(s[((0))].b)) <<((int)(B)))))-((int)((((int)(s[((0xC9))].b)) %((int)(B)))))-((short)((((double)(B)) -((double)(B))))) + (0xA6EAC) *((long)((((int)(s[(0xD)].b)) &((int)(B + (-(43)) *((short)((((int)(B)) %((int)(s[(-(-2))].b)))))*((short)((((int)(B)) ^((int)(s[(0x6377)].b)))))-((short)((((int)(s[((37))].b)) <<((int)(B)))))-((int)((((int)(s[((0))].b)) %((int)(B)))))-((short)((((double)(B)) -((double)(B))))))))))-((long)((((int)(s[(-(129))].b)) %((int)(B + ((0x7A9)) *((short)((((int)(B)) %((int)(s[(-(1))].b)))))*((short)((((int)(B)) ^((int)(s[(0x3AF52)].b)))))-((short)((((int)(s[((65536))].b)) <<((int)(B)))))-((int)((((int)(s[((0))].b)) %((int)(B)))))-((short)((((double)(B)) -((double)(B))))))))))-((short)((((int)(s[((536870912))].b)) >>((int)(s[((0))].b)))))-((short)((((int)(s[((2097152))].b)) &((int)(s[(0x2E)].b))))))) >>((int)(s[((0))].b)))))-((int)((((int)(s[((0))].b)) ^((int)(B + (-(59)) *((short)((((int)(B)) %((int)(s[((0))].b)))))*((short)((((int)(B)) ^((int)(s[((64))].b)))))-((short)((((int)(s[((16))].b)) <<((int)(B)))))-((int)((((int)(s[((524288))].b)) %((int)(B)))))-((short)((((double)(B)) -((double)(B))))) + (0xA6EAC) *((long)((((int)(s[(0xD)].b)) &((int)(B + (-(41)) *((short)((((int)(B)) %((int)(s[(-(0xA5A))].b)))))*((short)((((int)(B)) ^((int)(s[(0x6377)].b)))))-((short)((((int)(s[((5))].b)) <<((int)(B)))))-((int)((((int)(s[((-1))].b)) %((int)(B)))))-((short)((((double)(B)) -((double)(B))))))))))-((long)((((int)(s[(-(1))].b)) %((int)(B + ((34)) *((short)((((int)(B)) %((int)(s[(-(-2))].b)))))*((short)((((int)(B)) ^((int)(s[(0x3AF52)].b)))))-((short)((((int)(s[((0x96))].b)) <<((int)(B)))))-((int)((((int)(s[((0))].b)) %((int)(B)))))-((short)((((double)(B)) -((double)(B))))))))))-((short)((((int)(s[((68719476736))].b)) >>((int)(s[((0))].b)))))-((short)((((int)(s[((4611686018427387904))].b)) &((int)(s[(0x2E)].b))))))))))*((long)((((int)(B + (-(-44)) *((short)((((int)(B)) %((int)(s[((0xFEA3))].b)))))*((short)((((int)(B)) ^((int)(s[((0))].b)))))-((short)((((int)(s[((-1))].b)) <<((int)(B)))))-((int)((((int)(s[((0x2B))].b)) %((int)(B)))))-((short)((((double)(B)) -((double)(B))))) + (0xA6EAC) *((long)((((int)(s[(0xD)].b)) &((int)(B + (-(-44)) *((short)((((int)(B)) %((int)(s[(-(0xB1B46))].b)))))*((short)((((int)(B)) ^((int)(s[(0x6377)].b)))))-((short)((((int)(s[((-6))].b)) <<((int)(B)))))-((int)((((int)(s[((0))].b)) %((int)(B)))))-((short)((((double)(B)) -((double)(B))))))))))-((long)((((int)(s[(-(3))].b)) %((int)(B + ((0x802)) *((short)((((int)(B)) %((int)(s[(-(129))].b)))))*((short)((((int)(B)) ^((int)(s[(0x3AF52)].b)))))-((short)((((int)(s[((0xEF7))].b)) <<((int)(B)))))-((int)((((int)(s[((0))].b)) %((int)(B)))))-((short)((((double)(B)) -((double)(B))))))))))-((short)((((int)(s[((128))].b)) >>((int)(s[((0))].b)))))-((short)((((int)(s[((0))].b)) &((int)(s[(0x2E)].b))))))) |((int)(s[((-1))].b)))));
  s[(-(-2))].c = C + (-(43)) *((short)((((int)(s[(0xB5)].c)) <<((int)(s[(0x79)].c)))))*((long)((((int)(s[((0xFBCD2))].c)) %((int)(C)))))-((long)((((double)(C)) +((double)(C)))))*((long)((((int)(s[((0xC789B))].c)) >>((int)(C)))))+((long)((((double)(C)) *((double)(C))))) + (0x466) -((long)((((int)(C + ((0x5F9)) *((short)((((int)(s[((-2))].c)) <<((int)(s[((-16385))].c)))))*((long)((((int)(s[(-(0xAB2))].c)) %((int)(C)))))-((long)((((double)(C)) +((double)(C)))))*((long)((((int)(s[((-1))].c)) >>((int)(C)))))+((long)((((double)(C)) *((double)(C))))))) ^((int)(s[((536870912))].c)))))+((int)((((int)(C + ((43)) *((short)((((int)(s[((-1))].c)) <<((int)(s[((1))].c)))))*((long)((((int)(s[(-(3))].c)) %((int)(C)))))-((long)((((double)(C)) +((double)(C)))))*((long)((((int)(s[(0xFD)].c)) >>((int)(C)))))+((long)((((double)(C)) *((double)(C))))))) |((int)(C + ((138)) *((short)((((int)(s[((0xBF37632F8CD49))].c)) <<((int)(s[((2147483904))].c)))))*((long)((((int)(s[((0x3642F9E))].c)) %((int)(C)))))-((long)((((double)(C)) +((double)(C)))))*((long)((((int)(s[((0))].c)) >>((int)(C)))))+((long)((((double)(C)) *((double)(C)))))))))) + (106) *((long)((((int)(C + (-(41)) *((short)((((int)(s[(0xB5)].c)) <<((int)(s[(0x79)].c)))))*((long)((((int)(s[((2))].c)) %((int)(C)))))-((long)((((double)(C)) +((double)(C)))))*((long)((((int)(s[((0x539B))].c)) >>((int)(C)))))+((long)((((double)(C)) *((double)(C))))) + (0x466) -((long)((((int)(C + ((02)) *((short)((((int)(s[((4))].c)) <<((int)(s[((16384))].c)))))*((long)((((int)(s[(-(0))].c)) %((int)(C)))))-((long)((((double)(C)) +((double)(C)))))*((long)((((int)(s[((-1))].c)) >>((int)(C)))))+((long)((((double)(C)) *((double)(C))))))) ^((int)(s[((288230376151711744))].c)))))+((int)((((int)(C + ((42)) *((short)((((int)(s[((0))].c)) <<((int)(s[((-2))].c)))))*((long)((((int)(s[(-(9))].c)) %((int)(C)))))-((long)((((double)(C)) +((double)(C)))))*((long)((((int)(s[(0xFD)].c)) >>((int)(C)))))+((long)((((double)(C)) *((double)(C))))))) |((int)(C + ((42)) *((short)((((int)(s[((0xE7A1B4260824E24))].c)) <<((int)(s[((2147483648))].c)))))*((long)((((int)(s[((-8388609))].c)) %((int)(C)))))-((long)((((double)(C)) +((double)(C)))))*((long)((((int)(s[((06))].c)) >>((int)(C)))))+((long)((((double)(C)) *((double)(C)))))))))))) %((int)(C + (-(47)) *((short)((((int)(s[(0xB5)].c)) <<((int)(s[(0x79)].c)))))*((long)((((int)(s[((1))].c)) %((int)(C)))))-((long)((((double)(C)) +((double)(C)))))*((long)((((int)(s[((0x68EE7))].c)) >>((int)(C)))))+((long)((((double)(C)) *((double)(C))))) + (0x466) -((long)((((int)(C + ((02)) *((short)((((int)(s[((-2))].c)) <<((int)(s[((16640))].c)))))*((long)((((int)(s[(-(-2))].c)) %((int)(C)))))-((long)((((double)(C)) +((double)(C)))))*((long)((((int)(s[((16384))].c)) >>((int)(C)))))+((long)((((double)(C)) *((double)(C))))))) ^((int)(s[((0))].c)))))+((int)((((int)(C + ((58)) *((short)((((int)(s[((7))].c)) <<((int)(s[((5))].c)))))*((long)((((int)(s[(-(0x58A))].c)) %((int)(C)))))-((long)((((double)(C)) +((double)(C)))))*((long)((((int)(s[(0xFD)].c)) >>((int)(C)))))+((long)((((double)(C)) *((double)(C))))))) |((int)(C + ((26)) *((short)((((int)(s[((0x719B06709D604))].c)) <<((int)(s[((2147783648))].c)))))*((long)((((int)(s[((-8388609))].c)) %((int)(C)))))-((long)((((double)(C)) +((double)(C)))))*((long)((((int)(s[((-17))].c)) >>((int)(C)))))+((long)((((double)(C)) *((double)(C)))))))))))))));
  s[((-129))].d = D + ((-11)) *((short)((((int)(D)) ^((int)(D)))))+((int)((((double)(D)) -((double)(D))))) + (0x20E02) -((short)((((int)(D + (0x8FF) *((short)((((int)(D)) ^((int)(D)))))+((int)((((double)(D)) -((double)(D))))))) %((int)(s[((0x12E5D4BC))].d)))))-((short)((((int)(s[((1))].d)) >>((int)(D + ((0x9E8)) *((short)((((int)(D)) ^((int)(D)))))+((int)((((double)(D)) -((double)(D)))))))))) + (42) +((int)((((int)(D + ((-11)) *((short)((((int)(D)) ^((int)(D)))))+((int)((((double)(D)) -((double)(D))))) + (0x20E02) -((short)((((int)(D + (0x8FF) *((short)((((int)(D)) ^((int)(D)))))+((int)((((double)(D)) -((double)(D))))))) %((int)(s[((-1025))].d)))))-((short)((((int)(s[((0))].d)) >>((int)(D + ((0x81491)) *((short)((((int)(D)) ^((int)(D)))))+((int)((((double)(D)) -((double)(D)))))))))))) <<((int)(D + ((10)) *((short)((((int)(D)) ^((int)(D)))))+((int)((((double)(D)) -((double)(D))))) + (0x20E02) -((short)((((int)(D + (0x8FF) *((short)((((int)(D)) ^((int)(D)))))+((int)((((double)(D)) -((double)(D))))))) %((int)(s[((1024))].d)))))-((short)((((int)(s[((4096))].d)) >>((int)(D + ((-47)) *((short)((((int)(D)) ^((int)(D)))))+((int)((((double)(D)) -((double)(D)))))))))))))))*((long)((((int)(D + ((14)) *((short)((((int)(D)) ^((int)(D)))))+((int)((((double)(D)) -((double)(D))))) + (0x20E02) -((short)((((int)(D + (0x8FF) *((short)((((int)(D)) ^((int)(D)))))+((int)((((double)(D)) -((double)(D))))))) %((int)(s[((0x9BDD9))].d)))))-((short)((((int)(s[((-1))].d)) >>((int)(D + ((0x2B17A5)) *((short)((((int)(D)) ^((int)(D)))))+((int)((((double)(D)) -((double)(D)))))))))))) %((int)(s[((-129))].d)))));
  s[(-(2))].a = D + ((0xE1B)) -((long)((((int)(D)) &((int)(s[(0x2958)].a)))))*((int)((((int)(s[(-(0xC352C))].a)) ^((int)(s[(-(2))].a))))) + ((0xF2E)) *((long)((((int)(D + (0xD7A99B) -((long)((((int)(D)) &((int)(s[((0xC18))].a)))))*((int)((((int)(s[((-6))].a)) ^((int)(s[(-(2))].a))))))) ^((int)(D + ((42)) -((long)((((int)(D)) &((int)(s[((41))].a)))))*((int)((((int)(s[((-18))].a)) ^((int)(s[((4))].a))))))))))+((short)((((int)(D + ((00)) -((long)((((int)(D)) &((int)(s[((-2))].a)))))*((int)((((int)(s[((17))].a)) ^((int)(s[((161))].a))))))) >>((int)(s[(0xF)].a)))))*((long)((((int)(s[(0x15669)].a)) %((int)(D + ((-43)) -((long)((((int)(D)) &((int)(s[(0xDA19)].a)))))*((int)((((int)(s[(-(3))].a)) ^((int)(s[((0x0BC))].a))))))))))*((int)((((int)(D + (0x8E7) -((long)((((int)(D)) &((int)(s[(0x30CF9)].a)))))*((int)((((int)(s[((1))].a)) ^((int)(s[((0x871E))].a))))))) <<((int)(D + ((0x9E93)) -((long)((((int)(D)) &((int)(s[(-(2))].a)))))*((int)((((int)(s[(0x1FA71)].a)) ^((int)(s[(-(10))].a)))))))))) + (-43) -((short)((((int)(s[(-(0x7))].a)) &((int)(s[(-(-3))].a)))));
  s[(0x2BF7D)].b = C + (0x46A2A) -((short)((((int)(s[(0xF71AE)].b)) %((int)(s[(0x15D)].b)))))-((short)((((int)(C)) >>((int)(s[(-(-3))].b)))))+((long)((((double)(C)) +((double)(C)))))+((int)((((int)(s[((1))].b)) <<((int)(C))))) + (0x807516) *((int)((((int)(s[(-(0xD))].b)) <<((int)(C + (-(-44)) -((short)((((int)(s[((1))].b)) %((int)(s[((64))].b)))))-((short)((((int)(C)) >>((int)(s[((9))].b)))))+((long)((((double)(C)) +((double)(C)))))+((int)((((int)(s[(0x4)].b)) <<((int)(C))))))))))+((int)((((int)(s[(-(2))].b)) &((int)(s[((-2))].b))))) + (43) +((long)((((int)(C + (0x46A2A) -((short)((((int)(s[(0xF71AE)].b)) %((int)(s[(0x15D)].b)))))-((short)((((int)(C)) >>((int)(s[(-(0))].b)))))+((long)((((double)(C)) +((double)(C)))))+((int)((((int)(s[((73))].b)) <<((int)(C))))) + (0x807516) *((int)((((int)(s[(-(0xFE))].b)) <<((int)(C + (-(-44)) -((short)((((int)(s[((0xA4390))].b)) %((int)(s[((65))].b)))))-((short)((((int)(C)) >>((int)(s[((0x5))].b)))))+((long)((((double)(C)) +((double)(C)))))+((int)((((int)(s[(0x4)].b)) <<((int)(C))))))))))+((int)((((int)(s[(-(2))].b)) &((int)(s[((3))].b))))))) &((int)(C + (0x46A2A) -((short)((((int)(s[(0xF71AE)].b)) %((int)(s[(0x15D)].b)))))-((short)((((int)(C)) >>((int)(s[(-(4))].b)))))+((long)((((double)(C)) +((double)(C)))))+((int)((((int)(s[((-66))].b)) <<((int)(C))))) + (0x807516) *((int)((((int)(s[(-(2))].b)) <<((int)(C + (-(40)) -((short)((((int)(s[((81))].b)) %((int)(s[((65))].b)))))-((short)((((int)(C)) >>((int)(s[((-10))].b)))))+((long)((((double)(C)) +((double)(C)))))+((int)((((int)(s[(0x4)].b)) <<((int)(C))))))))))+((int)((((int)(s[(-(34))].b)) &((int)(s[((0x4))].b))))))))))+((short)((((int)(C + (0x46A2A) -((short)((((int)(s[(0xF71AE)].b)) %((int)(s[(0x15D)].b)))))-((short)((((int)(C)) >>((int)(s[(-(0x1))].b)))))+((long)((((double)(C)) +((double)(C)))))+((int)((((int)(s[((-66))].b)) <<((int)(C))))) + (0x807516) *((int)((((int)(s[(-(-3))].b)) <<((int)(C + (-(11)) -((short)((((int)(s[((65))].b)) %((int)(s[((97))].b)))))-((short)((((int)(C)) >>((int)(s[((0x914F))].b)))))+((long)((((double)(C)) +((double)(C)))))+((int)((((int)(s[(0x4)].b)) <<((int)(C))))))))))+((int)((((int)(s[(-(0xF476))].b)) &((int)(s[((1))].b))))))) &((int)(s[(0x2BF7D)].b)))));
  s[(0xCD2BB)].c = B + ((-43)) +((int)((((int)(B)) |((int)(s[(-(-3))].c)))))-((long)((((int)(B)) |((int)(B)))))*((short)((((int)(s[(0xA04)].c)) %((int)(s[((-2))].c)))))+((int)((((int)(s[(0x0332)].c)) >>((int)(s[((-66))].c))))) + ((-11)) *((int)((((int)(B + (0xB68BC) +((int)((((int)(B)) |((int)(s[((-66))].c)))))-((long)((((int)(B)) |((int)(B)))))*((short)((((int)(s[(-(-3))].c)) %((int)(s[(-(-3))].c)))))+((int)((((int)(s[((0x87))].c)) >>((int)(s[(0xBB04)].c))))))) >>((int)(s[((-2))].c)))))-((long)((((int)(s[(0x98D9)].c)) |((int)(B + ((-59)) +((int)((((int)(B)) |((int)(s[((1))].c)))))-((long)((((int)(B)) |((int)(B)))))*((short)((((int)(s[((16777216))].c)) %((int)(s[((0x935))].c)))))+((int)((((int)(s[((0))].c)) >>((int)(s[(0x6)].c))))))))))*((short)((((int)(B + ((10)) +((int)((((int)(B)) |((int)(s[(0xF5BB)].c)))))-((long)((((int)(B)) |((int)(B)))))*((short)((((int)(s[((17))].c)) %((int)(s[(0x9)].c)))))+((int)((((int)(s[(-(0x815))].c)) >>((int)(s[(-(0x5D4))].c))))))) %((int)(B + (0x916EDD) +((int)((((int)(B)) |((int)(s[((-2))].c)))))-((long)((((int)(B)) |((int)(B)))))*((short)((((int)(s[(0x0482)].c)) %((int)(s[((-2))].c)))))+((int)((((int)(s[((0x7109D))].c)) >>((int)(s[((3))].c))))))))))+((int)((((int)(s[(-(6))].c)) <<((int)(s[((-2))].c)))))+((int)((((int)(s[((-8))].c)) ^((int)(s[((32))].c))))) + (02) +((short)((((int)(s[(0xCD2BB)].c)) >>((int)(B + ((0x2E531)) +((int)((((int)(B)) |((int)(s[(-(-3))].c)))))-((long)((((int)(B)) |((int)(B)))))*((short)((((int)(s[(0xA04)].c)) %((int)(s[((129))].c)))))+((int)((((int)(s[(0x0332)].c)) >>((int)(s[((-66))].c))))) + ((10)) *((int)((((int)(B + (0xB68BC) +((int)((((int)(B)) |((int)(s[((67))].c)))))-((long)((((int)(B)) |((int)(B)))))*((short)((((int)(s[(-(0x16334))].c)) %((int)(s[(-(0x306))].c)))))+((int)((((int)(s[((0x6D))].c)) >>((int)(s[(0xBB04)].c))))))) >>((int)(s[((-2))].c)))))-((long)((((int)(s[(0x98D9)].c)) |((int)(B + ((-59)) +((int)((((int)(B)) |((int)(s[((-2))].c)))))-((long)((((int)(B)) |((int)(B)))))*((short)((((int)(s[((1))].c)) %((int)(s[((0x0F8))].c)))))+((int)((((int)(s[((18014398509481984))].c)) >>((int)(s[(0x6)].c))))))))))*((short)((((int)(B + ((0xE0)) +((int)((((int)(B)) |((int)(s[(0xF5BB)].c)))))-((long)((((int)(B)) |((int)(B)))))*((short)((((int)(s[((-18))].c)) %((int)(s[(0x9)].c)))))+((int)((((int)(s[(-(2))].c)) >>((int)(s[(-(2))].c))))))) %((int)(B + (0x916EDD) +((int)((((int)(B)) |((int)(s[((-2))].c)))))-((long)((((int)(B)) |((int)(B)))))*((short)((((int)(s[(0x0482)].c)) %((int)(s[((1))].c)))))+((int)((((int)(s[((9))].c)) >>((int)(s[((0xEB44))].c))))))))))+((int)((((int)(s[(-(3))].c)) <<((int)(s[((-2))].c)))))+((int)((((int)(s[((39))].c)) ^((int)(s[((33))].c))))))))))-((long)((((int)(s[(0xCD2BB)].c)) %((int)(s[(0xCD2BB)].c)))))+((long)((((int)(B + ((0x270A3)) +((int)((((int)(B)) |((int)(s[(-(-3))].c)))))-((long)((((int)(B)) |((int)(B)))))*((short)((((int)(s[(0xA04)].c)) %((int)(s[((0x0C94))].c)))))+((int)((((int)(s[(0x0332)].c)) >>((int)(s[((73))].c))))) + ((0x4B9F19)) *((int)((((int)(B + (0xB68BC) +((int)((((int)(B)) |((int)(s[((64))].c)))))-((long)((((int)(B)) |((int)(B)))))*((short)((((int)(s[(-(-3))].c)) %((int)(s[(-(2))].c)))))+((int)((((int)(s[((18))].c)) >>((int)(s[(0xBB04)].c))))))) >>((int)(s[((-2))].c)))))-((long)((((int)(s[(0x98D9)].c)) |((int)(B + ((58)) +((int)((((int)(B)) |((int)(s[((0x90A5))].c)))))-((long)((((int)(B)) |((int)(B)))))*((short)((((int)(s[((0))].c)) %((int)(s[((0x5F28))].c)))))+((int)((((int)(s[((0))].c)) >>((int)(s[(0x6)].c))))))))))*((short)((((int)(B + ((0x2138)) +((int)((((int)(B)) |((int)(s[(0xF5BB)].c)))))-((long)((((int)(B)) |((int)(B)))))*((short)((((int)(s[((0x05))].c)) %((int)(s[(0x9)].c)))))+((int)((((int)(s[(-(0xFB))].c)) >>((int)(s[(-(0x96ED))].c))))))) %((int)(B + (0x916EDD) +((int)((((int)(B)) |((int)(s[((65))].c)))))-((long)((((int)(B)) |((int)(B)))))*((short)((((int)(s[(0x0482)].c)) %((int)(s[((0x2))].c)))))+((int)((((int)(s[((129))].c)) >>((int)(s[((-2))].c))))))))))+((int)((((int)(s[(-(66))].c)) <<((int)(s[((3))].c)))))+((int)((((int)(s[((-8))].c)) ^((int)(s[((0x14BA1))].c))))))) >>((int)(s[(0xCD2BB)].c)))))-((int)((((int)(B + ((42)) +((int)((((int)(B)) |((int)(s[(-(3))].c)))))-((long)((((int)(B)) |((int)(B)))))*((short)((((int)(s[(0xA04)].c)) %((int)(s[((1))].c)))))+((int)((((int)(s[(0x0332)].c)) >>((int)(s[((0x86EBB2))].c))))) + ((10)) *((int)((((int)(B + (0xB68BC) +((int)((((int)(B)) |((int)(s[((0x41))].c)))))-((long)((((int)(B)) |((int)(B)))))*((short)((((int)(s[(-(34))].c)) %((int)(s[(-(0))].c)))))+((int)((((int)(s[((-18))].c)) >>((int)(s[(0xBB04)].c))))))) >>((int)(s[((-2))].c)))))-((long)((((int)(s[(0x98D9)].c)) |((int)(B + ((62)) +((int)((((int)(B)) |((int)(s[((3))].c)))))-((long)((((int)(B)) |((int)(B)))))*((short)((((int)(s[((0))].c)) %((int)(s[((1))].c)))))+((int)((((int)(s[((2097152))].c)) >>((int)(s[(0x6)].c))))))))))*((short)((((int)(B + ((17)) +((int)((((int)(B)) |((int)(s[(0xF5BB)].c)))))-((long)((((int)(B)) |((int)(B)))))*((short)((((int)(s[((49))].c)) %((int)(s[(0x9)].c)))))+((int)((((int)(s[(-(-3))].c)) >>((int)(s[(-(0x5))].c))))))) %((int)(B + (0x916EDD) +((int)((((int)(B)) |((int)(s[((-2))].c)))))-((long)((((int)(B)) |((int)(B)))))*((short)((((int)(s[(0x0482)].c)) %((int)(s[((0xC))].c)))))+((int)((((int)(s[((-2))].c)) >>((int)(s[((0x53400))].c))))))))))+((int)((((int)(s[(-(-3))].c)) <<((int)(s[((-2))].c)))))+((int)((((int)(s[((39))].c)) ^((int)(s[((-34))].c))))))) <<((int)(B + ((0x3EA)) +((int)((((int)(B)) |((int)(s[(-(-3))].c)))))-((long)((((int)(B)) |((int)(B)))))*((short)((((int)(s[(0xA04)].c)) %((int)(s[((33))].c)))))+((int)((((int)(s[(0x0332)].c)) >>((int)(s[((193))].c))))) + ((0x94B8)) *((int)((((int)(B + (0xB68BC) +((int)((((int)(B)) |((int)(s[((0x35F))].c)))))-((long)((((int)(B)) |((int)(B)))))*((short)((((int)(s[(-(66))].c)) %((int)(s[(-(0x9))].c)))))+((int)((((int)(s[((17))].c)) >>((int)(s[(0xBB04)].c))))))) >>((int)(s[((0))].c)))))-((long)((((int)(s[(0x98D9)].c)) |((int)(B + ((0x61)) +((int)((((int)(B)) |((int)(s[((-2))].c)))))-((long)((((int)(B)) |((int)(B)))))*((short)((((int)(s[((64))].c)) %((int)(s[((0))].c)))))+((int)((((int)(s[((0x97))].c)) >>((int)(s[(0x6)].c))))))))))*((short)((((int)(B + ((-11)) +((int)((((int)(B)) |((int)(s[(0xF5BB)].c)))))-((long)((((int)(B)) |((int)(B)))))*((short)((((int)(s[((-18))].c)) %((int)(s[(0x9)].c)))))+((int)((((int)(s[(-(-3))].c)) >>((int)(s[(-(0))].c))))))) %((int)(B + (0x916EDD) +((int)((((int)(B)) |((int)(s[((0xAC96))].c)))))-((long)((((int)(B)) |((int)(B)))))*((short)((((int)(s[(0x0482)].c)) %((int)(s[((129))].c)))))+((int)((((int)(s[((1))].c)) >>((int)(s[((-2))].c))))))))))+((int)((((int)(s[(-(6))].c)) <<((int)(s[((3))].c)))))+((int)((((int)(s[((39))].c)) ^((int)(s[((97))].c))))))))))+((int)((((int)(B + ((0x4900BC)) +((int)((((int)(B)) |((int)(s[(-(2))].c)))))-((long)((((int)(B)) |((int)(B)))))*((short)((((int)(s[(0xA04)].c)) %((int)(s[((9))].c)))))+((int)((((int)(s[(0x0332)].c)) >>((int)(s[((-66))].c))))) + ((0xE9128)) *((int)((((int)(B + (0xB68BC) +((int)((((int)(B)) |((int)(s[((67))].c)))))-((long)((((int)(B)) |((int)(B)))))*((short)((((int)(s[(-(18))].c)) %((int)(s[(-(-3))].c)))))+((int)((((int)(s[((0x4EA75))].c)) >>((int)(s[(0xBB04)].c))))))) >>((int)(s[((-2))].c)))))-((long)((((int)(s[(0x98D9)].c)) |((int)(B + ((0xF7F7F6)) +((int)((((int)(B)) |((int)(s[((33))].c)))))-((long)((((int)(B)) |((int)(B)))))*((short)((((int)(s[((2251799813685248))].c)) %((int)(s[((3))].c)))))+((int)((((int)(s[((0))].c)) >>((int)(s[(0x6)].c))))))))))*((short)((((int)(B + ((0x29)) +((int)((((int)(B)) |((int)(s[(0xF5BB)].c)))))-((long)((((int)(B)) |((int)(B)))))*((short)((((int)(s[((17))].c)) %((int)(s[(0x9)].c)))))+((int)((((int)(s[(-(-3))].c)) >>((int)(s[(-(2))].c))))))) %((int)(B + (0x916EDD) +((int)((((int)(B)) |((int)(s[((1))].c)))))-((long)((((int)(B)) |((int)(B)))))*((short)((((int)(s[(0x0482)].c)) %((int)(s[((0x400))].c)))))+((int)((((int)(s[((9))].c)) >>((int)(s[((3))].c))))))))))+((int)((((int)(s[(-(-3))].c)) <<((int)(s[((1))].c)))))+((int)((((int)(s[((0x290F5))].c)) ^((int)(s[((41))].c))))))) <<((int)(s[(0xCD2BB)].c)))));
  s[((8))].d = A + ((38)) -((int)((((int)(s[(-(-3))].d)) |((int)(A)))))*((long)((((int)(A)) >>((int)(A))))) + ((171)) *((short)((((int)(s[(0x927)].d)) &((int)(A + ((10)) -((int)((((int)(s[((21))].d)) |((int)(A)))))*((long)((((int)(A)) >>((int)(A))))))))))+((long)((((int)(A + ((-33)) -((int)((((int)(s[(-(2))].d)) |((int)(A)))))*((long)((((int)(A)) >>((int)(A))))))) &((int)(A + (0x7B) -((int)((((int)(s[((81))].d)) |((int)(A)))))*((long)((((int)(A)) >>((int)(A)))))))))) + (42) -((short)((((int)(A + ((47)) -((int)((((int)(s[(-(0xD4A9B))].d)) |((int)(A)))))*((long)((((int)(A)) >>((int)(A))))) + ((0x2E)) *((short)((((int)(s[(0x927)].d)) &((int)(A + ((-43)) -((int)((((int)(s[((0xB60FD))].d)) |((int)(A)))))*((long)((((int)(A)) >>((int)(A))))))))))+((long)((((int)(A + ((-33)) -((int)((((int)(s[(-(0x393))].d)) |((int)(A)))))*((long)((((int)(A)) >>((int)(A))))))) &((int)(A + (0x7B) -((int)((((int)(s[((-66))].d)) |((int)(A)))))*((long)((((int)(A)) >>((int)(A)))))))))))) &((int)(A + ((-47)) -((int)((((int)(s[(-(6))].d)) |((int)(A)))))*((long)((((int)(A)) >>((int)(A))))) + ((-44)) *((short)((((int)(s[(0x927)].d)) &((int)(A + ((0x7E)) -((int)((((int)(s[((0xF54A3))].d)) |((int)(A)))))*((long)((((int)(A)) >>((int)(A))))))))))+((long)((((int)(A + ((0)) -((int)((((int)(s[(-(-3))].d)) |((int)(A)))))*((long)((((int)(A)) >>((int)(A))))))) &((int)(A + (0x7B) -((int)((((int)(s[((0xA3B))].d)) |((int)(A)))))*((long)((((int)(A)) >>((int)(A)))))))))))))))+((short)((((int)(s[((0x6FF8))].d)) >>((int)(A + ((46)) -((int)((((int)(s[(-(2))].d)) |((int)(A)))))*((long)((((int)(A)) >>((int)(A))))) + ((-44)) *((short)((((int)(s[(0x927)].d)) &((int)(A + ((0x2E)) -((int)((((int)(s[((16))].d)) |((int)(A)))))*((long)((((int)(A)) >>((int)(A))))))))))+((long)((((int)(A + ((0x91C18)) -((int)((((int)(s[(-(0x9))].d)) |((int)(A)))))*((long)((((int)(A)) >>((int)(A))))))) &((int)(A + (0x7B) -((int)((((int)(s[((193))].d)) |((int)(A)))))*((long)((((int)(A)) >>((int)(A)))))))))))))));
  foo (s);
  exit ((0x1EC));
}
/* ProgramSourceLLVM */