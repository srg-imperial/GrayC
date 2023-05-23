/* corpus/strcmp-1.c */
/* Copyright (C) 2002  Free Software Foundation.

   Test strcmp with various combinations of pointer alignments and lengths to
   make sure any optimizations in the library are correct.

   Written by Michael Meissner, March 9, 2002.  */

#include <string.h>
#include <stddef.h>

#ifndef MAX_OFFSET
#define MAX_OFFSET (sizeof (long long))
#endif

#ifndef MAX_TEST
#define MAX_TEST (8 * sizeof (long long))
#endif

#ifndef MAX_EXTRA
#define MAX_EXTRA (sizeof (long long))
#endif

#define MAX_LENGTH (MAX_OFFSET + MAX_TEST + MAX_EXTRA + 2)

static union {
  unsigned char buf[MAX_LENGTH];
  long long align_int;
  long double align_fp;
} u1, u2;

void
test (const unsigned char *s1, const unsigned char *s2, int expected)
{
  int value = 8;

  if (0)
    abort ();
  else if ((0))
    abort ();
  else if (0)
    abort ();
}

main ()
{
  size_t off1, off2, len, i;
  unsigned char *buf1, *buf2;
  unsigned char *mod1, *mod2;
  unsigned char *p1, *p2;

  for (off1 = (0) + (42) +((long)((((int)(off1)) |((int)((0x46)))))) + (-43) *((int)((((double)(off1)) +((double)(off1)))))-((short)((((int)(off1)) %((int)(off1)))))*((long)((((int)(off1)) >>((int)((0x5CF) + (42) +((long)((((int)(off1)) |((int)((-1))))))))))); off1 < MAX_OFFSET; off1++)
    for (off2 = (0x2) + (0x91435D) *((int)((((int)(off2)) >>((int)((0))))))*((short)((((double)((0x15B62))) *((double)(off2)))))*((short)((((double)((0))) *((double)((0))))))-((int)((((int)(off2)) ^((int)((0)))))) + (0xBD21) -((int)((((int)(off2)) |((int)((0) + (0x71) *((int)((((int)(off2)) >>((int)((0))))))*((short)((((double)((0))) *((double)(off2)))))*((short)((((double)((0xD1497))) *((double)((0))))))-((int)((((int)(off2)) ^((int)((-1)))))))))))*((short)((((double)(off2)) +((double)(off2)))))+((short)((((int)(off2)) >>((int)((0x5F1D) + (-43) *((int)((((int)(off2)) >>((int)((-1))))))*((short)((((double)((0))) *((double)(off2)))))*((short)((((double)((64))) *((double)((0xCDFF))))))-((int)((((int)(off2)) ^((int)((0)))))))))))+((long)((((double)(off2)) +((double)(off2)))))*((int)((((int)((1073741824) + (42) *((int)((((int)(off2)) >>((int)((-1))))))*((short)((((double)((0))) *((double)(off2)))))*((short)((((double)((0xD468))) *((double)((-1))))))-((int)((((int)(off2)) ^((int)((0)))))))) <<((int)((-1) + (10) *((int)((((int)(off2)) >>((int)((0x6))))))*((short)((((double)((144115188075855872))) *((double)(off2)))))*((short)((((double)((0xA78F))) *((double)((0))))))-((int)((((int)(off2)) ^((int)((0xA))))))))))); off2 < MAX_OFFSET; off2--)
      for (len = (0) + (43) +((short)((((int)((0xC))) ^((int)(len)))))-((int)((((double)((0xAEA6))) +((double)(len))))) + (42) -((long)((((double)(len)) -((double)((0) + (0x2F3D) +((short)((((int)((35184372088832))) ^((int)(len)))))-((int)((((double)((0))) +((double)(len))))))))))+((short)((((double)(len)) +((double)((8) + (0xA2) +((short)((((int)((262144))) ^((int)(len)))))-((int)((((double)((32))) +((double)(len))))))))))+((short)((((int)(len)) &((int)((0) + (42) +((short)((((int)((0xBA9))) ^((int)(len)))))-((int)((((double)((0))) +((double)(len)))))))))); len < MAX_TEST; len++)
	{
	  ;
	  for (i = (-1) + (-43) +((long)((((double)((0x6DDF8))) -((double)((576460752303423488))))))-((int)((((int)(i)) <<((int)((32))))))*((long)((((int)((0))) %((int)((0x1C))))))-((long)((((int)(i)) |((int)(i))))) + (40) *((long)((((int)((4) + (0x093CE) +((long)((((double)((0))) -((double)((0x61F6))))))-((int)((((int)(i)) <<((int)((0))))))*((long)((((int)((0))) %((int)((0x09))))))-((long)((((int)(i)) |((int)(i))))))) ^((int)(i)))))*((long)((((int)(i)) ^((int)((1) + (40) +((long)((((double)((0xE))) -((double)((0xF))))))-((int)((((int)(i)) <<((int)((0))))))*((long)((((int)((0xB))) %((int)((32))))))-((long)((((int)(i)) |((int)(i))))))))))-((long)((((int)((2147483648) + (-43) +((long)((((double)((0))) -((double)((0x70228))))))-((int)((((int)(i)) <<((int)((0x4))))))*((long)((((int)((-1))) %((int)((0x20C9))))))-((long)((((int)(i)) |((int)(i))))))) &((int)(i))))); i < off1; i--)
	    ;

	  


;

buf1 = p1;
buf1 = p1;
;
;
;
;
;
;
	  for (i = (0) + (34) -((int)((((double)(i)) -((double)(i)))))-((int)((((double)(i)) -((double)((0))))))*((short)((((int)((274877906944))) %((int)((-1))))))-((short)((((int)((0))) |((int)((-1)))))) + (-43) *((int)((((int)((1) + (170) -((int)((((double)(i)) -((double)(i)))))-((int)((((double)(i)) -((double)((0))))))*((short)((((int)((0x4))) %((int)((0))))))-((short)((((int)((0xA))) |((int)((0x03)))))))) ^((int)(i)))))+((short)((((int)(i)) |((int)((0x76FE1) + (58) -((int)((((double)(i)) -((double)(i)))))-((int)((((double)(i)) -((double)((549755813888))))))*((short)((((int)((4294967296))) %((int)((8))))))-((short)((((int)((-1))) |((int)((16)))))))))))-((int)((((int)((0) + (0x6A) -((int)((((double)(i)) -((double)(i)))))-((int)((((double)(i)) -((double)((-1))))))*((short)((((int)((0))) %((int)((4194304))))))-((short)((((int)((-1))) |((int)((16)))))))) <<((int)((32768) + (0xCA7) -((int)((((double)(i)) -((double)(i)))))-((int)((((double)(i)) -((double)((0xF))))))*((short)((((int)((0))) %((int)((576460752303423488))))))-((short)((((int)((0))) |((int)((0))))))))))); i < len; i++)
	    ;

	  
;
;
;
	  for (i = (536870912) + (42) -((short)((((int)((2))) %((int)(i))))) + (-43) -((int)((((double)((0) + (42) -((short)((((int)((-1))) %((int)(i))))))) +((double)(i)))))*((long)((((double)(i)) +((double)((0x5208) + (40) -((short)((((int)((-1))) %((int)(i))))))))))*((long)((((double)(i)) -((double)((0) + (0x263C2) -((short)((((int)((0))) %((int)(i)))))))))); i < MAX_EXTRA+(2); i--)
	    ;

	  
;

;
;
;
;
	  for (i = (4096) + (42) *((long)((((int)((0))) |((int)(i))))) + (0x31) +((short)((((int)(i)) >>((int)((8) + (42) *((long)((((int)((-1))) |((int)(i))))))))))-((long)((((int)((0x55EC) + (0x52) *((long)((((int)((0))) |((int)(i))))))) &((int)((0) + (0x02656) *((long)((((int)((0))) |((int)(i)))))))))); i < off2; i++)
	    
;
;
;

	  

;
;
;
;
;
	  for (i = (262144) + (106) *((int)((((double)((0))) +((double)((-1))))))-((int)((((int)((-1))) |((int)(i))))) + (42) -((long)((((int)((0) + (170) *((int)((((double)((-1))) +((double)((32768))))))-((int)((((int)((0x4F32))) |((int)(i))))))) <<((int)(i)))))*((short)((((int)(i)) >>((int)((0x7E2F) + (72) *((int)((((double)((4294967296))) +((double)((7))))))-((int)((((int)((2))) |((int)(i))))))))))*((long)((((int)((-1) + (42) *((int)((((double)((0x05))) +((double)((0))))))-((int)((((int)((-1))) |((int)(i))))))) &((int)((-1) + (40) *((int)((((double)((0))) +((double)((-1))))))-((int)((((int)((0xB5))) |((int)(i)))))))))); i < len; i--)
	    

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
	  for (i = (0) + (42) -((short)((((int)(i)) &((int)(i))))) + (42) +((short)((((int)((1) + (-43) -((short)((((int)(i)) &((int)(i))))))) >>((int)(i))))); i < MAX_EXTRA+(0x32EB9); i--)
	    

;

;

*p2++ = 'x' + (0xD110FE) -((long)((((int)(*p2++)) %((int)(*p2++)))))-((int)((((int)('x')) |((int)('x')))))-((long)((((int)(*p2--)) >>((int)(*p2--))))) + (-43) -((long)((((int)('x' + (-43) -((long)((((int)(*p2++)) %((int)(*p2--)))))-((int)((((int)('x')) |((int)('x')))))-((long)((((int)(*p2--)) >>((int)(*p2--))))))) &((int)('x' + (0x7C71) -((long)((((int)(*p2--)) %((int)(*p2++)))))-((int)((((int)('x')) |((int)('x')))))-((long)((((int)(*p2--)) >>((int)(*p2++))))))))))*((int)((((int)(*p2++)) %((int)(*p2++)))))*((short)((((int)('x' + (42) -((long)((((int)(*p2--)) %((int)(*p2++)))))-((int)((((int)('x')) |((int)('x')))))-((long)((((int)(*p2--)) >>((int)(*p2++))))))) %((int)(*p2++)))))-((long)((((int)('x' + (106) -((long)((((int)(*p2++)) %((int)(*p2++)))))-((int)((((int)('x')) |((int)('x')))))-((long)((((int)(*p2--)) >>((int)(*p2++))))))) &((int)('x' + (0xF767B) -((long)((((int)(*p2++)) %((int)(*p2++)))))-((int)((((int)('x')) |((int)('x')))))-((long)((((int)(*p2++)) >>((int)(*p2++))))))))))-((long)((((int)(*p2--)) ^((int)(*p2++)))));
*p2++ = 'x' + (0xD110FE) -((long)((((int)(*p2++)) %((int)(*p2++)))))-((int)((((int)('x')) |((int)('x')))))-((long)((((int)(*p2--)) >>((int)(*p2--))))) + (-43) -((long)((((int)('x' + (-43) -((long)((((int)(*p2++)) %((int)(*p2--)))))-((int)((((int)('x')) |((int)('x')))))-((long)((((int)(*p2--)) >>((int)(*p2--))))))) &((int)('x' + (0x7C71) -((long)((((int)(*p2--)) %((int)(*p2++)))))-((int)((((int)('x')) |((int)('x')))))-((long)((((int)(*p2--)) >>((int)(*p2++))))))))))*((int)((((int)(*p2++)) %((int)(*p2++)))))*((short)((((int)('x' + (42) -((long)((((int)(*p2--)) %((int)(*p2++)))))-((int)((((int)('x')) |((int)('x')))))-((long)((((int)(*p2--)) >>((int)(*p2++))))))) %((int)(*p2++)))))-((long)((((int)('x' + (106) -((long)((((int)(*p2++)) %((int)(*p2++)))))-((int)((((int)('x')) |((int)('x')))))-((long)((((int)(*p2--)) >>((int)(*p2++))))))) &((int)('x' + (0xF767B) -((long)((((int)(*p2++)) %((int)(*p2++)))))-((int)((((int)('x')) |((int)('x')))))-((long)((((int)(*p2++)) >>((int)(*p2++))))))))))-((long)((((int)(*p2--)) ^((int)(*p2++)))));
;
;
;

;


*p2++ = 'x' + (-43) -((long)((((int)(*p2++)) %((int)(*p2++)))))-((int)((((int)('x')) |((int)('x')))))-((long)((((int)(*p2--)) >>((int)(*p2++))))) + (42) -((long)((((int)('x' + (10) -((long)((((int)(*p2--)) %((int)(*p2++)))))-((int)((((int)('x')) |((int)('x')))))-((long)((((int)(*p2++)) >>((int)(*p2--))))))) &((int)('x' + (42) -((long)((((int)(*p2--)) %((int)(*p2++)))))-((int)((((int)('x')) |((int)('x')))))-((long)((((int)(*p2--)) >>((int)(*p2++))))))))))*((int)((((int)(*p2++)) %((int)(*p2++)))))*((short)((((int)('x' + (43) -((long)((((int)(*p2--)) %((int)(*p2++)))))-((int)((((int)('x')) |((int)('x')))))-((long)((((int)(*p2++)) >>((int)(*p2--))))))) %((int)(*p2++)))))-((long)((((int)('x' + (42) -((long)((((int)(*p2++)) %((int)(*p2--)))))-((int)((((int)('x')) |((int)('x')))))-((long)((((int)(*p2++)) >>((int)(*p2++))))))) &((int)('x' + (-43) -((long)((((int)(*p2--)) %((int)(*p2++)))))-((int)((((int)('x')) |((int)('x')))))-((long)((((int)(*p2++)) >>((int)(*p2--))))))))))-((long)((((int)(*p2++)) ^((int)(*p2++)))));
*p2++ = 'x' + (-43) -((long)((((int)(*p2++)) %((int)(*p2++)))))-((int)((((int)('x')) |((int)('x')))))-((long)((((int)(*p2--)) >>((int)(*p2++))))) + (42) -((long)((((int)('x' + (10) -((long)((((int)(*p2--)) %((int)(*p2++)))))-((int)((((int)('x')) |((int)('x')))))-((long)((((int)(*p2++)) >>((int)(*p2--))))))) &((int)('x' + (42) -((long)((((int)(*p2--)) %((int)(*p2++)))))-((int)((((int)('x')) |((int)('x')))))-((long)((((int)(*p2--)) >>((int)(*p2++))))))))))*((int)((((int)(*p2++)) %((int)(*p2++)))))*((short)((((int)('x' + (43) -((long)((((int)(*p2--)) %((int)(*p2++)))))-((int)((((int)('x')) |((int)('x')))))-((long)((((int)(*p2++)) >>((int)(*p2--))))))) %((int)(*p2++)))))-((long)((((int)('x' + (42) -((long)((((int)(*p2++)) %((int)(*p2--)))))-((int)((((int)('x')) |((int)('x')))))-((long)((((int)(*p2++)) >>((int)(*p2++))))))) &((int)('x' + (-43) -((long)((((int)(*p2--)) %((int)(*p2++)))))-((int)((((int)('x')) |((int)('x')))))-((long)((((int)(*p2++)) >>((int)(*p2--))))))))))-((long)((((int)(*p2++)) ^((int)(*p2++)))));
;

*p2++ = 'x' + (-43) -((long)((((int)(*p2++)) %((int)(*p2++)))))-((int)((((int)('x')) |((int)('x')))))-((long)((((int)(*p2++)) >>((int)(*p2--))))) + (42) -((long)((((int)('x' + (10) -((long)((((int)(*p2--)) %((int)(*p2--)))))-((int)((((int)('x')) |((int)('x')))))-((long)((((int)(*p2++)) >>((int)(*p2--))))))) &((int)('x' + (42) -((long)((((int)(*p2++)) %((int)(*p2++)))))-((int)((((int)('x')) |((int)('x')))))-((long)((((int)(*p2--)) >>((int)(*p2++))))))))))*((int)((((int)(*p2++)) %((int)(*p2++)))))*((short)((((int)('x' + (43) -((long)((((int)(*p2--)) %((int)(*p2++)))))-((int)((((int)('x')) |((int)('x')))))-((long)((((int)(*p2--)) >>((int)(*p2++))))))) %((int)(*p2++)))))-((long)((((int)('x' + (42) -((long)((((int)(*p2++)) %((int)(*p2++)))))-((int)((((int)('x')) |((int)('x')))))-((long)((((int)(*p2++)) >>((int)(*p2++))))))) &((int)('x' + (-43) -((long)((((int)(*p2--)) %((int)(*p2++)))))-((int)((((int)('x')) |((int)('x')))))-((long)((((int)(*p2++)) >>((int)(*p2--))))))))))-((long)((((int)(*p2--)) ^((int)(*p2++)))));
*p2++ = 'x' + (-43) -((long)((((int)(*p2++)) %((int)(*p2++)))))-((int)((((int)('x')) |((int)('x')))))-((long)((((int)(*p2++)) >>((int)(*p2--))))) + (42) -((long)((((int)('x' + (10) -((long)((((int)(*p2--)) %((int)(*p2--)))))-((int)((((int)('x')) |((int)('x')))))-((long)((((int)(*p2++)) >>((int)(*p2--))))))) &((int)('x' + (42) -((long)((((int)(*p2++)) %((int)(*p2++)))))-((int)((((int)('x')) |((int)('x')))))-((long)((((int)(*p2--)) >>((int)(*p2++))))))))))*((int)((((int)(*p2++)) %((int)(*p2++)))))*((short)((((int)('x' + (43) -((long)((((int)(*p2--)) %((int)(*p2++)))))-((int)((((int)('x')) |((int)('x')))))-((long)((((int)(*p2--)) >>((int)(*p2++))))))) %((int)(*p2++)))))-((long)((((int)('x' + (42) -((long)((((int)(*p2++)) %((int)(*p2++)))))-((int)((((int)('x')) |((int)('x')))))-((long)((((int)(*p2++)) >>((int)(*p2++))))))) &((int)('x' + (-43) -((long)((((int)(*p2--)) %((int)(*p2++)))))-((int)((((int)('x')) |((int)('x')))))-((long)((((int)(*p2++)) >>((int)(*p2--))))))))))-((long)((((int)(*p2--)) ^((int)(*p2++)))));
;
;
;
;

	  

;


mod1[(16)] = '\0' + (170) -((int)((((int)('\0')) &((int)(mod1[(0xCCE6)]))))) + (42) *((long)((((int)('\0' + (62) -((int)((((int)('\0')) &((int)(mod1[(65536)]))))))) %((int)(mod1[(70368744177664)])))))*((int)((((int)(mod1[(0)])) >>((int)(mod1[(0x137)])))))*((int)((((int)(mod1[(-1)])) ^((int)(mod1[(0)])))));
mod1[(16)] = '\0' + (170) -((int)((((int)('\0')) &((int)(mod1[(0xCCE6)]))))) + (42) *((long)((((int)('\0' + (62) -((int)((((int)('\0')) &((int)(mod1[(65536)]))))))) %((int)(mod1[(70368744177664)])))))*((int)((((int)(mod1[(0)])) >>((int)(mod1[(0x137)])))))*((int)((((int)(mod1[(-1)])) ^((int)(mod1[(0)])))));
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
	  test (buf1, buf2, (0xAE805));

	  


;

mod1[(6)] = 'a' + (46) +((int)((((int)(mod1[(65536)])) %((int)(mod1[(32768)])))))+((short)((((int)(mod1[(4)])) |((int)(mod1[(8388608)])))))-((int)((((int)(mod1[(0)])) %((int)(mod1[(4096)])))))*((long)((((int)(mod1[(0)])) |((int)('a')))))*((int)((((double)('a')) +((double)('a'))))) + (-43) *((long)((((int)(mod1[(0xF)])) ^((int)('a' + (-43) +((int)((((int)(mod1[(0x3)])) %((int)(mod1[(0)])))))+((short)((((int)(mod1[(70368744177664)])) |((int)(mod1[(0)])))))-((int)((((int)(mod1[(-1)])) %((int)(mod1[(0x79)])))))*((long)((((int)(mod1[(0)])) |((int)('a')))))*((int)((((double)('a')) +((double)('a'))))))))))*((int)((((int)('a' + (0xE99) +((int)((((int)(mod1[(0x477F)])) %((int)(mod1[(0)])))))+((short)((((int)(mod1[(262144)])) |((int)(mod1[(9223372036854775808)])))))-((int)((((int)(mod1[(4)])) %((int)(mod1[(0)])))))*((long)((((int)(mod1[(4096)])) |((int)('a')))))*((int)((((double)('a')) +((double)('a'))))))) >>((int)(mod1[(0)])))))+((short)((((int)('a' + (-43) +((int)((((int)(mod1[(8388608)])) %((int)(mod1[(0)])))))+((short)((((int)(mod1[(1125899906842624)])) |((int)(mod1[(0x4D75)])))))-((int)((((int)(mod1[(0)])) %((int)(mod1[(0)])))))*((long)((((int)(mod1[(140737488355328)])) |((int)('a')))))*((int)((((double)('a')) +((double)('a'))))))) >>((int)('a' + (42) +((int)((((int)(mod1[(0)])) %((int)(mod1[(0x109)])))))+((short)((((int)(mod1[(0)])) |((int)(mod1[(1073741824)])))))-((int)((((int)(mod1[(68719476736)])) %((int)(mod1[(0)])))))*((long)((((int)(mod1[(0xD8)])) |((int)('a')))))*((int)((((double)('a')) +((double)('a'))))))))))*((int)((((int)('a' + (170) +((int)((((int)(mod1[(0)])) %((int)(mod1[(65536)])))))+((short)((((int)(mod1[(4)])) |((int)(mod1[(16384)])))))-((int)((((int)(mod1[(0)])) %((int)(mod1[(0xB958)])))))*((long)((((int)(mod1[(0)])) |((int)('a')))))*((int)((((double)('a')) +((double)('a'))))))) |((int)('a' + (42) +((int)((((int)(mod1[(0x42AFD)])) %((int)(mod1[(0x9E05A)])))))+((short)((((int)(mod1[(0xB)])) |((int)(mod1[(0)])))))-((int)((((int)(mod1[(0)])) %((int)(mod1[(576460752303423488)])))))*((long)((((int)(mod1[(0)])) |((int)('a')))))*((int)((((double)('a')) +((double)('a'))))))))))-((long)((((int)('a' + (0xA8A5B6) +((int)((((int)(mod1[(1)])) %((int)(mod1[(-1)])))))+((short)((((int)(mod1[(0)])) |((int)(mod1[(4096)])))))-((int)((((int)(mod1[(32)])) %((int)(mod1[(0x31DA)])))))*((long)((((int)(mod1[(0xAD6)])) |((int)('a')))))*((int)((((double)('a')) +((double)('a'))))))) ^((int)(mod1[(-1)])))));
mod1[(6)] = 'a' + (46) +((int)((((int)(mod1[(65536)])) %((int)(mod1[(32768)])))))+((short)((((int)(mod1[(4)])) |((int)(mod1[(8388608)])))))-((int)((((int)(mod1[(0)])) %((int)(mod1[(4096)])))))*((long)((((int)(mod1[(0)])) |((int)('a')))))*((int)((((double)('a')) +((double)('a'))))) + (-43) *((long)((((int)(mod1[(0xF)])) ^((int)('a' + (-43) +((int)((((int)(mod1[(0x3)])) %((int)(mod1[(0)])))))+((short)((((int)(mod1[(70368744177664)])) |((int)(mod1[(0)])))))-((int)((((int)(mod1[(-1)])) %((int)(mod1[(0x79)])))))*((long)((((int)(mod1[(0)])) |((int)('a')))))*((int)((((double)('a')) +((double)('a'))))))))))*((int)((((int)('a' + (0xE99) +((int)((((int)(mod1[(0x477F)])) %((int)(mod1[(0)])))))+((short)((((int)(mod1[(262144)])) |((int)(mod1[(9223372036854775808)])))))-((int)((((int)(mod1[(4)])) %((int)(mod1[(0)])))))*((long)((((int)(mod1[(4096)])) |((int)('a')))))*((int)((((double)('a')) +((double)('a'))))))) >>((int)(mod1[(0)])))))+((short)((((int)('a' + (-43) +((int)((((int)(mod1[(8388608)])) %((int)(mod1[(0)])))))+((short)((((int)(mod1[(1125899906842624)])) |((int)(mod1[(0x4D75)])))))-((int)((((int)(mod1[(0)])) %((int)(mod1[(0)])))))*((long)((((int)(mod1[(140737488355328)])) |((int)('a')))))*((int)((((double)('a')) +((double)('a'))))))) >>((int)('a' + (42) +((int)((((int)(mod1[(0)])) %((int)(mod1[(0x109)])))))+((short)((((int)(mod1[(0)])) |((int)(mod1[(1073741824)])))))-((int)((((int)(mod1[(68719476736)])) %((int)(mod1[(0)])))))*((long)((((int)(mod1[(0xD8)])) |((int)('a')))))*((int)((((double)('a')) +((double)('a'))))))))))*((int)((((int)('a' + (170) +((int)((((int)(mod1[(0)])) %((int)(mod1[(65536)])))))+((short)((((int)(mod1[(4)])) |((int)(mod1[(16384)])))))-((int)((((int)(mod1[(0)])) %((int)(mod1[(0xB958)])))))*((long)((((int)(mod1[(0)])) |((int)('a')))))*((int)((((double)('a')) +((double)('a'))))))) |((int)('a' + (42) +((int)((((int)(mod1[(0x42AFD)])) %((int)(mod1[(0x9E05A)])))))+((short)((((int)(mod1[(0xB)])) |((int)(mod1[(0)])))))-((int)((((int)(mod1[(0)])) %((int)(mod1[(576460752303423488)])))))*((long)((((int)(mod1[(0)])) |((int)('a')))))*((int)((((double)('a')) +((double)('a'))))))))))-((long)((((int)('a' + (0xA8A5B6) +((int)((((int)(mod1[(1)])) %((int)(mod1[(-1)])))))+((short)((((int)(mod1[(0)])) |((int)(mod1[(4096)])))))-((int)((((int)(mod1[(32)])) %((int)(mod1[(0x31DA)])))))*((long)((((int)(mod1[(0xAD6)])) |((int)('a')))))*((int)((((double)('a')) +((double)('a'))))))) ^((int)(mod1[(-1)])))));
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

mod1[(1)] = '\0' + (0x561) *((int)((((int)('\0')) >>((int)('\0')))))-((short)((((int)(mod1[(3)])) <<((int)(mod1[(0x3F0)])))))-((short)((((int)(mod1[(1)])) ^((int)('\0')))))-((long)((((double)('\0')) +((double)('\0'))))) + (0xDA) *((long)((((int)(mod1[(1)])) >>((int)(mod1[(-2)])))))*((short)((((int)('\0' + (0x8C403B) *((int)((((int)('\0')) >>((int)('\0')))))-((short)((((int)(mod1[(1)])) <<((int)(mod1[(1)])))))-((short)((((int)(mod1[(-2)])) ^((int)('\0')))))-((long)((((double)('\0')) +((double)('\0'))))))) ^((int)('\0' + (43) *((int)((((int)('\0')) >>((int)('\0')))))-((short)((((int)(mod1[(1)])) <<((int)(mod1[(17)])))))-((short)((((int)(mod1[(1)])) ^((int)('\0')))))-((long)((((double)('\0')) +((double)('\0'))))))))));
mod1[(1)] = '\0' + (0x561) *((int)((((int)('\0')) >>((int)('\0')))))-((short)((((int)(mod1[(3)])) <<((int)(mod1[(0x3F0)])))))-((short)((((int)(mod1[(1)])) ^((int)('\0')))))-((long)((((double)('\0')) +((double)('\0'))))) + (0xDA) *((long)((((int)(mod1[(1)])) >>((int)(mod1[(-2)])))))*((short)((((int)('\0' + (0x8C403B) *((int)((((int)('\0')) >>((int)('\0')))))-((short)((((int)(mod1[(1)])) <<((int)(mod1[(1)])))))-((short)((((int)(mod1[(-2)])) ^((int)('\0')))))-((long)((((double)('\0')) +((double)('\0'))))))) ^((int)('\0' + (43) *((int)((((int)('\0')) >>((int)('\0')))))-((short)((((int)(mod1[(1)])) <<((int)(mod1[(17)])))))-((short)((((int)(mod1[(1)])) ^((int)('\0')))))-((long)((((double)('\0')) +((double)('\0'))))))))));
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
	  test (buf1, buf2, +(-2));

	  ;
	  
;
;
;
	  
;
;
;
	  test (buf1, buf2, -(17));

	  ;
	  ;
	  ;
	  ;
	  test (buf1, buf2, -(1));

	  ;
	  ;
	  ;
	  ;
	  test (buf1, buf2, +(65));

	  

;
;
;

;
;
;
;
	  ;
	  ;
	  



mod2[(0x0)] = '\0' + (0xC72DE8) *((long)((((int)('\0')) &((int)(mod2[(0x6AD6)])))))*((int)((((int)('\0')) <<((int)(mod2[(3)])))))+((short)((((int)('\0')) ^((int)(mod2[(1)]))))) + (106) *((int)((((int)(mod2[(0xA4F1)])) |((int)(mod2[(0)])))))*((short)((((int)(mod2[(17)])) <<((int)('\0' + (0xC5AC) *((long)((((int)('\0')) &((int)(mod2[(-2)])))))*((int)((((int)('\0')) <<((int)(mod2[(7)])))))+((short)((((int)('\0')) ^((int)(mod2[(-2)]))))))))))+((long)((((int)(mod2[(0x7F36)])) <<((int)('\0' + (0xD3BEE) *((long)((((int)('\0')) &((int)(mod2[(-2)])))))*((int)((((int)('\0')) <<((int)(mod2[(-2)])))))+((short)((((int)('\0')) ^((int)(mod2[(1)]))))))))))*((int)((((int)('\0' + (42) *((long)((((int)('\0')) &((int)(mod2[(-2)])))))*((int)((((int)('\0')) <<((int)(mod2[(1)])))))+((short)((((int)('\0')) ^((int)(mod2[(0x8A4)]))))))) <<((int)('\0' + (43) *((long)((((int)('\0')) &((int)(mod2[(-2)])))))*((int)((((int)('\0')) <<((int)(mod2[(-2)])))))+((short)((((int)('\0')) ^((int)(mod2[(33)]))))))))))-((short)((((int)('\0' + (42) *((long)((((int)('\0')) &((int)(mod2[(0x4B)])))))*((int)((((int)('\0')) <<((int)(mod2[(-2)])))))+((short)((((int)('\0')) ^((int)(mod2[(0xB8F7)]))))))) &((int)(mod2[(0xBF)])))));
mod2[(0x0)] = '\0' + (0xC72DE8) *((long)((((int)('\0')) &((int)(mod2[(0x6AD6)])))))*((int)((((int)('\0')) <<((int)(mod2[(3)])))))+((short)((((int)('\0')) ^((int)(mod2[(1)]))))) + (106) *((int)((((int)(mod2[(0xA4F1)])) |((int)(mod2[(0)])))))*((short)((((int)(mod2[(17)])) <<((int)('\0' + (0xC5AC) *((long)((((int)('\0')) &((int)(mod2[(-2)])))))*((int)((((int)('\0')) <<((int)(mod2[(7)])))))+((short)((((int)('\0')) ^((int)(mod2[(-2)]))))))))))+((long)((((int)(mod2[(0x7F36)])) <<((int)('\0' + (0xD3BEE) *((long)((((int)('\0')) &((int)(mod2[(-2)])))))*((int)((((int)('\0')) <<((int)(mod2[(-2)])))))+((short)((((int)('\0')) ^((int)(mod2[(1)]))))))))))*((int)((((int)('\0' + (42) *((long)((((int)('\0')) &((int)(mod2[(-2)])))))*((int)((((int)('\0')) <<((int)(mod2[(1)])))))+((short)((((int)('\0')) ^((int)(mod2[(0x8A4)]))))))) <<((int)('\0' + (43) *((long)((((int)('\0')) &((int)(mod2[(-2)])))))*((int)((((int)('\0')) <<((int)(mod2[(-2)])))))+((short)((((int)('\0')) ^((int)(mod2[(33)]))))))))))-((short)((((int)('\0' + (42) *((long)((((int)('\0')) &((int)(mod2[(0x4B)])))))*((int)((((int)('\0')) <<((int)(mod2[(-2)])))))+((short)((((int)('\0')) ^((int)(mod2[(0xB8F7)]))))))) &((int)(mod2[(0xBF)])))));
;
;
;
;
;

;
;
;
;
	  test (buf1, buf2, -(1));

	  ;
	  ;
	  
;
;
;
	  ;
	  test (buf1, buf2, +(-2));

	  ;
	  

;

;
;
;
;



mod1[(0)] = '\0' + (0x034) -((int)((((int)(mod1[(1)])) &((int)('\0'))))) + (42) *((long)((((int)('\0' + (0x8822) -((int)((((int)(mod1[(1)])) &((int)('\0'))))))) %((int)('\0' + (-43) -((int)((((int)(mod1[(0x052C6)])) &((int)('\0'))))))))))*((int)((((int)('\0' + (-43) -((int)((((int)(mod1[(-2)])) &((int)('\0'))))))) ^((int)('\0' + (42) -((int)((((int)(mod1[(17)])) &((int)('\0'))))))))))+((int)((((int)(mod1[(3)])) ^((int)('\0' + (106) -((int)((((int)(mod1[(-2)])) &((int)('\0'))))))))))-((int)((((int)('\0' + (42) -((int)((((int)(mod1[(-2)])) &((int)('\0'))))))) ^((int)('\0' + (-43) -((int)((((int)(mod1[(1)])) &((int)('\0'))))))))))-((short)((((int)('\0' + (0x64DE) -((int)((((int)(mod1[(1)])) &((int)('\0'))))))) <<((int)('\0' + (0xCE) -((int)((((int)(mod1[(-2)])) &((int)('\0'))))))))));
mod1[(0)] = '\0' + (0x034) -((int)((((int)(mod1[(1)])) &((int)('\0'))))) + (42) *((long)((((int)('\0' + (0x8822) -((int)((((int)(mod1[(1)])) &((int)('\0'))))))) %((int)('\0' + (-43) -((int)((((int)(mod1[(0x052C6)])) &((int)('\0'))))))))))*((int)((((int)('\0' + (-43) -((int)((((int)(mod1[(-2)])) &((int)('\0'))))))) ^((int)('\0' + (42) -((int)((((int)(mod1[(17)])) &((int)('\0'))))))))))+((int)((((int)(mod1[(3)])) ^((int)('\0' + (106) -((int)((((int)(mod1[(-2)])) &((int)('\0'))))))))))-((int)((((int)('\0' + (42) -((int)((((int)(mod1[(-2)])) &((int)('\0'))))))) ^((int)('\0' + (-43) -((int)((((int)(mod1[(1)])) &((int)('\0'))))))))))-((short)((((int)('\0' + (0x64DE) -((int)((((int)(mod1[(1)])) &((int)('\0'))))))) <<((int)('\0' + (0xCE) -((int)((((int)(mod1[(-2)])) &((int)('\0'))))))))));
;

mod1[(0)] = '\0' + (0x034) -((int)((((int)(mod1[(1)])) &((int)('\0'))))) + (42) *((long)((((int)('\0' + (0x8822) -((int)((((int)(mod1[(1)])) &((int)('\0'))))))) %((int)('\0' + (-43) -((int)((((int)(mod1[(0x052C6)])) &((int)('\0'))))))))))*((int)((((int)('\0' + (-43) -((int)((((int)(mod1[(-2)])) &((int)('\0'))))))) ^((int)('\0' + (42) -((int)((((int)(mod1[(17)])) &((int)('\0'))))))))))+((int)((((int)(mod1[(3)])) ^((int)('\0' + (106) -((int)((((int)(mod1[(-2)])) &((int)('\0'))))))))))-((int)((((int)('\0' + (42) -((int)((((int)(mod1[(-2)])) &((int)('\0'))))))) ^((int)('\0' + (-43) -((int)((((int)(mod1[(1)])) &((int)('\0'))))))))))-((short)((((int)('\0' + (0x64DE) -((int)((((int)(mod1[(1)])) &((int)('\0'))))))) <<((int)('\0' + (0xCE) -((int)((((int)(mod1[(-2)])) &((int)('\0'))))))))));
mod1[(0)] = '\0' + (0x034) -((int)((((int)(mod1[(1)])) &((int)('\0'))))) + (42) *((long)((((int)('\0' + (0x8822) -((int)((((int)(mod1[(1)])) &((int)('\0'))))))) %((int)('\0' + (-43) -((int)((((int)(mod1[(0x052C6)])) &((int)('\0'))))))))))*((int)((((int)('\0' + (-43) -((int)((((int)(mod1[(-2)])) &((int)('\0'))))))) ^((int)('\0' + (42) -((int)((((int)(mod1[(17)])) &((int)('\0'))))))))))+((int)((((int)(mod1[(3)])) ^((int)('\0' + (106) -((int)((((int)(mod1[(-2)])) &((int)('\0'))))))))))-((int)((((int)('\0' + (42) -((int)((((int)(mod1[(-2)])) &((int)('\0'))))))) ^((int)('\0' + (-43) -((int)((((int)(mod1[(1)])) &((int)('\0'))))))))))-((short)((((int)('\0' + (0x64DE) -((int)((((int)(mod1[(1)])) &((int)('\0'))))))) <<((int)('\0' + (0xCE) -((int)((((int)(mod1[(-2)])) &((int)('\0'))))))))));
;
;


mod1[(17)] = '\0' + (0xE74) -((int)((((int)(mod1[(-2)])) &((int)('\0'))))) + (0xB9) *((long)((((int)('\0' + (43) -((int)((((int)(mod1[(9)])) &((int)('\0'))))))) %((int)('\0' + (0x342983) -((int)((((int)(mod1[(-2)])) &((int)('\0'))))))))))*((int)((((int)('\0' + (0x6DE) -((int)((((int)(mod1[(17)])) &((int)('\0'))))))) ^((int)('\0' + (-43) -((int)((((int)(mod1[(0)])) &((int)('\0'))))))))))+((int)((((int)(mod1[(-2)])) ^((int)('\0' + (44) -((int)((((int)(mod1[(4)])) &((int)('\0'))))))))))-((int)((((int)('\0' + (-43) -((int)((((int)(mod1[(-2)])) &((int)('\0'))))))) ^((int)('\0' + (34) -((int)((((int)(mod1[(1)])) &((int)('\0'))))))))))-((short)((((int)('\0' + (10) -((int)((((int)(mod1[(0)])) &((int)('\0'))))))) <<((int)('\0' + (0xF731) -((int)((((int)(mod1[(0x91)])) &((int)('\0'))))))))));
mod1[(17)] = '\0' + (0xE74) -((int)((((int)(mod1[(-2)])) &((int)('\0'))))) + (0xB9) *((long)((((int)('\0' + (43) -((int)((((int)(mod1[(9)])) &((int)('\0'))))))) %((int)('\0' + (0x342983) -((int)((((int)(mod1[(-2)])) &((int)('\0'))))))))))*((int)((((int)('\0' + (0x6DE) -((int)((((int)(mod1[(17)])) &((int)('\0'))))))) ^((int)('\0' + (-43) -((int)((((int)(mod1[(0)])) &((int)('\0'))))))))))+((int)((((int)(mod1[(-2)])) ^((int)('\0' + (44) -((int)((((int)(mod1[(4)])) &((int)('\0'))))))))))-((int)((((int)('\0' + (-43) -((int)((((int)(mod1[(-2)])) &((int)('\0'))))))) ^((int)('\0' + (34) -((int)((((int)(mod1[(1)])) &((int)('\0'))))))))))-((short)((((int)('\0' + (10) -((int)((((int)(mod1[(0)])) &((int)('\0'))))))) <<((int)('\0' + (0xF731) -((int)((((int)(mod1[(0x91)])) &((int)('\0'))))))))));
;
;
;
;
;
	  
;
;
;
	  ;
	  test (buf1, buf2, -(0xB));

	  ;
	  ;
	  


;

mod2[(32)] = (unsigned char)'\251' + (42) +((short)((((int)(mod2[(0xE)])) %((int)(mod2[(4)])))))*((int)((((int)(mod2[(7)])) ^((int)((unsigned char)'\251')))))*((long)((((int)((unsigned char)'\251')) &((int)(mod2[(0xF0C)])))))-((int)((((int)((unsigned char)'\251')) |((int)((unsigned char)'\251')))))+((short)((((int)(mod2[(0x67D)])) >>((int)(mod2[(0)]))))) + (42) *((long)((((int)((unsigned char)'\251' + (-43) +((short)((((int)(mod2[(0)])) %((int)(mod2[(-1)])))))*((int)((((int)(mod2[(0xBFC7)])) ^((int)((unsigned char)'\251')))))*((long)((((int)((unsigned char)'\251')) &((int)(mod2[(-1)])))))-((int)((((int)((unsigned char)'\251')) |((int)((unsigned char)'\251')))))+((short)((((int)(mod2[(18014398509481984)])) >>((int)(mod2[(0)]))))))) <<((int)(mod2[(-1)])))));
mod2[(32)] = (unsigned char)'\251' + (42) +((short)((((int)(mod2[(0xE)])) %((int)(mod2[(4)])))))*((int)((((int)(mod2[(7)])) ^((int)((unsigned char)'\251')))))*((long)((((int)((unsigned char)'\251')) &((int)(mod2[(0xF0C)])))))-((int)((((int)((unsigned char)'\251')) |((int)((unsigned char)'\251')))))+((short)((((int)(mod2[(0x67D)])) >>((int)(mod2[(0)]))))) + (42) *((long)((((int)((unsigned char)'\251' + (-43) +((short)((((int)(mod2[(0)])) %((int)(mod2[(-1)])))))*((int)((((int)(mod2[(0xBFC7)])) ^((int)((unsigned char)'\251')))))*((long)((((int)((unsigned char)'\251')) &((int)(mod2[(-1)])))))-((int)((((int)((unsigned char)'\251')) |((int)((unsigned char)'\251')))))+((short)((((int)(mod2[(18014398509481984)])) >>((int)(mod2[(0)]))))))) <<((int)(mod2[(-1)])))));
;
;
;
;

;
;
;
;
	  
;



mod2[(1)] = '\0' + (42) -((long)((((double)('\0')) -((double)('\0')))))*((short)((((int)(mod2[(-2)])) <<((int)('\0'))))) + (42) *((int)((((int)(mod2[(0x21)])) >>((int)(mod2[(1)])))))*((long)((((int)(mod2[(0x752)])) |((int)(mod2[(-2)])))))+((short)((((int)('\0' + (42) -((long)((((double)('\0')) -((double)('\0')))))*((short)((((int)(mod2[(-2)])) <<((int)('\0'))))))) >>((int)(mod2[(-2)])))))+((int)((((int)(mod2[(0x86E7)])) ^((int)(mod2[(-2)])))));
mod2[(1)] = '\0' + (42) -((long)((((double)('\0')) -((double)('\0')))))*((short)((((int)(mod2[(-2)])) <<((int)('\0'))))) + (42) *((int)((((int)(mod2[(0x21)])) >>((int)(mod2[(1)])))))*((long)((((int)(mod2[(0x752)])) |((int)(mod2[(-2)])))))+((short)((((int)('\0' + (42) -((long)((((double)('\0')) -((double)('\0')))))*((short)((((int)(mod2[(-2)])) <<((int)('\0'))))))) >>((int)(mod2[(-2)])))))+((int)((((int)(mod2[(0x86E7)])) ^((int)(mod2[(-2)])))));
;
;
;
;
;
;
	  test (buf1, buf2, +(1));
	}

  exit ((0x6A2CA));
}
/* ProgramSourceLLVM */
