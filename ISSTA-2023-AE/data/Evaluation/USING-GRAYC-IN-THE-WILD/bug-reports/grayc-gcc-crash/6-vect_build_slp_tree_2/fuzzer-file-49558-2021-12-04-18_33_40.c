/* corpus/pr38051.c */
typedef __SIZE_TYPE__ size_t;
static int mymemcmp1 (unsigned long int, unsigned long int)
  __attribute__ ((__nothrow__));

__inline static int
mymemcmp1 (unsigned long int a, unsigned long int b)
{
  long int srcp1 = (long int) &a;
  long int srcp2 = (long int) &b;
  unsigned long int a0, b0;
  do
    {
      


a0 = ((unsigned char *) srcp1)[(0x7)] + (10) *((int)((((int)(((unsigned char *) srcp1)[(0)])) >>((int)(((unsigned char *) srcp1)[(0x8C8B)])))))*((short)((((double)(a0)) +((double)(a0)))))+((short)((((int)(a0)) >>((int)(((unsigned char *) srcp1)[(0xF9)])))))+((long)((((int)(((unsigned char *) srcp1)[(8388608)])) %((int)(a0)))))-((int)((((int)(((unsigned char *) srcp1)[(0xBA2BC)])) %((int)(((unsigned char *) srcp1)[(-1)]))))) + (0xAE0EF) -((short)((((int)(((unsigned char *) srcp1)[(-1)] + (0xA87CD5) *((int)((((int)(((unsigned char *) srcp1)[(0)])) >>((int)(((unsigned char *) srcp1)[(5)])))))*((short)((((double)(a0)) +((double)(a0)))))+((short)((((int)(a0)) >>((int)(((unsigned char *) srcp1)[(1)])))))+((long)((((int)(((unsigned char *) srcp1)[(0xB14)])) %((int)(a0)))))-((int)((((int)(((unsigned char *) srcp1)[(-1)])) %((int)(((unsigned char *) srcp1)[(2048)]))))))) &((int)(((unsigned char *) srcp1)[(0x9B)] + (10) *((int)((((int)(((unsigned char *) srcp1)[(0xA)])) >>((int)(((unsigned char *) srcp1)[(8388608)])))))*((short)((((double)(a0)) +((double)(a0)))))+((short)((((int)(a0)) >>((int)(((unsigned char *) srcp1)[(2)])))))+((long)((((int)(((unsigned char *) srcp1)[(4294967296)])) %((int)(a0)))))-((int)((((int)(((unsigned char *) srcp1)[(0)])) %((int)(((unsigned char *) srcp1)[(-1)]))))))))))*((int)((((int)(a0)) %((int)(((unsigned char *) srcp1)[(0x9C5D0)] + (42) *((int)((((int)(((unsigned char *) srcp1)[(2)])) >>((int)(((unsigned char *) srcp1)[(2)])))))*((short)((((double)(a0)) +((double)(a0)))))+((short)((((int)(a0)) >>((int)(((unsigned char *) srcp1)[(0)])))))+((long)((((int)(((unsigned char *) srcp1)[(1073741824)])) %((int)(a0)))))-((int)((((int)(((unsigned char *) srcp1)[(16777216)])) %((int)(((unsigned char *) srcp1)[(536870912)]))))))))))-((int)((((int)(((unsigned char *) srcp1)[(-1)] + (0x20A04) *((int)((((int)(((unsigned char *) srcp1)[(16384)])) >>((int)(((unsigned char *) srcp1)[(0xD84B)])))))*((short)((((double)(a0)) +((double)(a0)))))+((short)((((int)(a0)) >>((int)(((unsigned char *) srcp1)[(0x9)])))))+((long)((((int)(((unsigned char *) srcp1)[(-1)])) %((int)(a0)))))-((int)((((int)(((unsigned char *) srcp1)[(8589934592)])) %((int)(((unsigned char *) srcp1)[(0xF655)]))))))) |((int)(((unsigned char *) srcp1)[(16)] + (43) *((int)((((int)(((unsigned char *) srcp1)[(-1)])) >>((int)(((unsigned char *) srcp1)[(0x3)])))))*((short)((((double)(a0)) +((double)(a0)))))+((short)((((int)(a0)) >>((int)(((unsigned char *) srcp1)[(0x93DC)])))))+((long)((((int)(((unsigned char *) srcp1)[(144115188075855872)])) %((int)(a0)))))-((int)((((int)(((unsigned char *) srcp1)[(0)])) %((int)(((unsigned char *) srcp1)[(8)]))))))))))*((int)((((int)(((unsigned char *) srcp1)[(0)] + (40) *((int)((((int)(((unsigned char *) srcp1)[(0xC)])) >>((int)(((unsigned char *) srcp1)[(0x4)])))))*((short)((((double)(a0)) +((double)(a0)))))+((short)((((int)(a0)) >>((int)(((unsigned char *) srcp1)[(268435456)])))))+((long)((((int)(((unsigned char *) srcp1)[(-1)])) %((int)(a0)))))-((int)((((int)(((unsigned char *) srcp1)[(0xDD4)])) %((int)(((unsigned char *) srcp1)[(0)]))))))) >>((int)(a0)))));
a0 = ((unsigned char *) srcp1)[(-1)] + (34) *((int)((((int)(((unsigned char *) srcp1)[(0)])) >>((int)(((unsigned char *) srcp1)[(0)])))))*((short)((((double)(a0)) +((double)(a0)))))+((short)((((int)(a0)) >>((int)(((unsigned char *) srcp1)[(2097152)])))))+((long)((((int)(((unsigned char *) srcp1)[(0xB)])) %((int)(a0)))))-((int)((((int)(((unsigned char *) srcp1)[(1024)])) %((int)(((unsigned char *) srcp1)[(0)]))))) + (-43) -((short)((((int)(((unsigned char *) srcp1)[(0xA664)] + (0x97D2B2) *((int)((((int)(((unsigned char *) srcp1)[(0xDAC2D)])) >>((int)(((unsigned char *) srcp1)[(-1)])))))*((short)((((double)(a0)) +((double)(a0)))))+((short)((((int)(a0)) >>((int)(((unsigned char *) srcp1)[(0)])))))+((long)((((int)(((unsigned char *) srcp1)[(32768)])) %((int)(a0)))))-((int)((((int)(((unsigned char *) srcp1)[(0)])) %((int)(((unsigned char *) srcp1)[(0)]))))))) &((int)(((unsigned char *) srcp1)[(0x99226)] + (42) *((int)((((int)(((unsigned char *) srcp1)[(0xD19D)])) >>((int)(((unsigned char *) srcp1)[(0)])))))*((short)((((double)(a0)) +((double)(a0)))))+((short)((((int)(a0)) >>((int)(((unsigned char *) srcp1)[(0)])))))+((long)((((int)(((unsigned char *) srcp1)[(0)])) %((int)(a0)))))-((int)((((int)(((unsigned char *) srcp1)[(-1)])) %((int)(((unsigned char *) srcp1)[(1)]))))))))))*((int)((((int)(a0)) %((int)(((unsigned char *) srcp1)[(-1)] + (106) *((int)((((int)(((unsigned char *) srcp1)[(8)])) >>((int)(((unsigned char *) srcp1)[(-1)])))))*((short)((((double)(a0)) +((double)(a0)))))+((short)((((int)(a0)) >>((int)(((unsigned char *) srcp1)[(0)])))))+((long)((((int)(((unsigned char *) srcp1)[(-1)])) %((int)(a0)))))-((int)((((int)(((unsigned char *) srcp1)[(-1)])) %((int)(((unsigned char *) srcp1)[(8796093022208)]))))))))))-((int)((((int)(((unsigned char *) srcp1)[(512)] + (0x5C) *((int)((((int)(((unsigned char *) srcp1)[(8192)])) >>((int)(((unsigned char *) srcp1)[(6)])))))*((short)((((double)(a0)) +((double)(a0)))))+((short)((((int)(a0)) >>((int)(((unsigned char *) srcp1)[(0)])))))+((long)((((int)(((unsigned char *) srcp1)[(0)])) %((int)(a0)))))-((int)((((int)(((unsigned char *) srcp1)[(8)])) %((int)(((unsigned char *) srcp1)[(-1)]))))))) |((int)(((unsigned char *) srcp1)[(16)] + (0xAAB) *((int)((((int)(((unsigned char *) srcp1)[(0)])) >>((int)(((unsigned char *) srcp1)[(8)])))))*((short)((((double)(a0)) +((double)(a0)))))+((short)((((int)(a0)) >>((int)(((unsigned char *) srcp1)[(0)])))))+((long)((((int)(((unsigned char *) srcp1)[(16)])) %((int)(a0)))))-((int)((((int)(((unsigned char *) srcp1)[(0xC)])) %((int)(((unsigned char *) srcp1)[(0)]))))))))))*((int)((((int)(((unsigned char *) srcp1)[(-1)] + (58) *((int)((((int)(((unsigned char *) srcp1)[(0)])) >>((int)(((unsigned char *) srcp1)[(0)])))))*((short)((((double)(a0)) +((double)(a0)))))+((short)((((int)(a0)) >>((int)(((unsigned char *) srcp1)[(0x39)])))))+((long)((((int)(((unsigned char *) srcp1)[(0x51)])) %((int)(a0)))))-((int)((((int)(((unsigned char *) srcp1)[(0)])) %((int)(((unsigned char *) srcp1)[(0)]))))))) >>((int)(a0)))));
;

a0 = ((unsigned char *) srcp1)[(2305843009213693952)] + (42) *((int)((((int)(((unsigned char *) srcp1)[(0)])) >>((int)(((unsigned char *) srcp1)[(0x5D49)])))))*((short)((((double)(a0)) +((double)(a0)))))+((short)((((int)(a0)) >>((int)(((unsigned char *) srcp1)[(0xF6126)])))))+((long)((((int)(((unsigned char *) srcp1)[(32)])) %((int)(a0)))))-((int)((((int)(((unsigned char *) srcp1)[(0x5E26)])) %((int)(((unsigned char *) srcp1)[(0)]))))) + (42) -((short)((((int)(((unsigned char *) srcp1)[(-1)] + (0x7E) *((int)((((int)(((unsigned char *) srcp1)[(0x8B)])) >>((int)(((unsigned char *) srcp1)[(0x8AA)])))))*((short)((((double)(a0)) +((double)(a0)))))+((short)((((int)(a0)) >>((int)(((unsigned char *) srcp1)[(0)])))))+((long)((((int)(((unsigned char *) srcp1)[(0)])) %((int)(a0)))))-((int)((((int)(((unsigned char *) srcp1)[(-1)])) %((int)(((unsigned char *) srcp1)[(0xC141A)]))))))) &((int)(((unsigned char *) srcp1)[(0)] + (0xFBA4B0) *((int)((((int)(((unsigned char *) srcp1)[(-1)])) >>((int)(((unsigned char *) srcp1)[(4)])))))*((short)((((double)(a0)) +((double)(a0)))))+((short)((((int)(a0)) >>((int)(((unsigned char *) srcp1)[(549755813888)])))))+((long)((((int)(((unsigned char *) srcp1)[(1)])) %((int)(a0)))))-((int)((((int)(((unsigned char *) srcp1)[(9)])) %((int)(((unsigned char *) srcp1)[(0)]))))))))))*((int)((((int)(a0)) %((int)(((unsigned char *) srcp1)[(-1)] + (0xFD) *((int)((((int)(((unsigned char *) srcp1)[(0)])) >>((int)(((unsigned char *) srcp1)[(0xC6)])))))*((short)((((double)(a0)) +((double)(a0)))))+((short)((((int)(a0)) >>((int)(((unsigned char *) srcp1)[(0)])))))+((long)((((int)(((unsigned char *) srcp1)[(0)])) %((int)(a0)))))-((int)((((int)(((unsigned char *) srcp1)[(0)])) %((int)(((unsigned char *) srcp1)[(0x70BAC)]))))))))))-((int)((((int)(((unsigned char *) srcp1)[(0)] + (0xF1E) *((int)((((int)(((unsigned char *) srcp1)[(0)])) >>((int)(((unsigned char *) srcp1)[(8)])))))*((short)((((double)(a0)) +((double)(a0)))))+((short)((((int)(a0)) >>((int)(((unsigned char *) srcp1)[(0x58)])))))+((long)((((int)(((unsigned char *) srcp1)[(-1)])) %((int)(a0)))))-((int)((((int)(((unsigned char *) srcp1)[(0)])) %((int)(((unsigned char *) srcp1)[(64)]))))))) |((int)(((unsigned char *) srcp1)[(-1)] + (42) *((int)((((int)(((unsigned char *) srcp1)[(0)])) >>((int)(((unsigned char *) srcp1)[(0)])))))*((short)((((double)(a0)) +((double)(a0)))))+((short)((((int)(a0)) >>((int)(((unsigned char *) srcp1)[(0)])))))+((long)((((int)(((unsigned char *) srcp1)[(0x6)])) %((int)(a0)))))-((int)((((int)(((unsigned char *) srcp1)[(32768)])) %((int)(((unsigned char *) srcp1)[(0)]))))))))))*((int)((((int)(((unsigned char *) srcp1)[(4)] + (-43) *((int)((((int)(((unsigned char *) srcp1)[(0)])) >>((int)(((unsigned char *) srcp1)[(0xE)])))))*((short)((((double)(a0)) +((double)(a0)))))+((short)((((int)(a0)) >>((int)(((unsigned char *) srcp1)[(0)])))))+((long)((((int)(((unsigned char *) srcp1)[(-1)])) %((int)(a0)))))-((int)((((int)(((unsigned char *) srcp1)[(4)])) %((int)(((unsigned char *) srcp1)[(0)]))))))) >>((int)(a0)))));
a0 = ((unsigned char *) srcp1)[(0)] + (34) *((int)((((int)(((unsigned char *) srcp1)[(0)])) >>((int)(((unsigned char *) srcp1)[(0x49B)])))))*((short)((((double)(a0)) +((double)(a0)))))+((short)((((int)(a0)) >>((int)(((unsigned char *) srcp1)[(0)])))))+((long)((((int)(((unsigned char *) srcp1)[(1)])) %((int)(a0)))))-((int)((((int)(((unsigned char *) srcp1)[(0x3CF)])) %((int)(((unsigned char *) srcp1)[(0xF)]))))) + (43) -((short)((((int)(((unsigned char *) srcp1)[(8)] + (-43) *((int)((((int)(((unsigned char *) srcp1)[(0xB1)])) >>((int)(((unsigned char *) srcp1)[(64)])))))*((short)((((double)(a0)) +((double)(a0)))))+((short)((((int)(a0)) >>((int)(((unsigned char *) srcp1)[(1)])))))+((long)((((int)(((unsigned char *) srcp1)[(0)])) %((int)(a0)))))-((int)((((int)(((unsigned char *) srcp1)[(8796093022208)])) %((int)(((unsigned char *) srcp1)[(0x111C)]))))))) &((int)(((unsigned char *) srcp1)[(-1)] + (46) *((int)((((int)(((unsigned char *) srcp1)[(2199023255552)])) >>((int)(((unsigned char *) srcp1)[(1)])))))*((short)((((double)(a0)) +((double)(a0)))))+((short)((((int)(a0)) >>((int)(((unsigned char *) srcp1)[(262144)])))))+((long)((((int)(((unsigned char *) srcp1)[(0)])) %((int)(a0)))))-((int)((((int)(((unsigned char *) srcp1)[(0x79D01)])) %((int)(((unsigned char *) srcp1)[(0xF4914)]))))))))))*((int)((((int)(a0)) %((int)(((unsigned char *) srcp1)[(0)] + (42) *((int)((((int)(((unsigned char *) srcp1)[(-1)])) >>((int)(((unsigned char *) srcp1)[(0x39A7D)])))))*((short)((((double)(a0)) +((double)(a0)))))+((short)((((int)(a0)) >>((int)(((unsigned char *) srcp1)[(0xCEF62)])))))+((long)((((int)(((unsigned char *) srcp1)[(1024)])) %((int)(a0)))))-((int)((((int)(((unsigned char *) srcp1)[(0)])) %((int)(((unsigned char *) srcp1)[(512)]))))))))))-((int)((((int)(((unsigned char *) srcp1)[(0xF1D7)] + (0xD91A) *((int)((((int)(((unsigned char *) srcp1)[(65536)])) >>((int)(((unsigned char *) srcp1)[(0xD3)])))))*((short)((((double)(a0)) +((double)(a0)))))+((short)((((int)(a0)) >>((int)(((unsigned char *) srcp1)[(1024)])))))+((long)((((int)(((unsigned char *) srcp1)[(16)])) %((int)(a0)))))-((int)((((int)(((unsigned char *) srcp1)[(0)])) %((int)(((unsigned char *) srcp1)[(0x77A)]))))))) |((int)(((unsigned char *) srcp1)[(64)] + (-43) *((int)((((int)(((unsigned char *) srcp1)[(0xF90B5)])) >>((int)(((unsigned char *) srcp1)[(0xD622)])))))*((short)((((double)(a0)) +((double)(a0)))))+((short)((((int)(a0)) >>((int)(((unsigned char *) srcp1)[(0)])))))+((long)((((int)(((unsigned char *) srcp1)[(0x7A)])) %((int)(a0)))))-((int)((((int)(((unsigned char *) srcp1)[(524288)])) %((int)(((unsigned char *) srcp1)[(0)]))))))))))*((int)((((int)(((unsigned char *) srcp1)[(0)] + (34) *((int)((((int)(((unsigned char *) srcp1)[(0xE680)])) >>((int)(((unsigned char *) srcp1)[(0xFCBAE)])))))*((short)((((double)(a0)) +((double)(a0)))))+((short)((((int)(a0)) >>((int)(((unsigned char *) srcp1)[(-1)])))))+((long)((((int)(((unsigned char *) srcp1)[(0xEF)])) %((int)(a0)))))-((int)((((int)(((unsigned char *) srcp1)[(288230376151711744)])) %((int)(((unsigned char *) srcp1)[(0xF8)]))))))) >>((int)(a0)))));
;
;

;

a0 = ((unsigned char *) srcp1)[(0x3)] + (106) *((int)((((int)(((unsigned char *) srcp1)[(0)])) >>((int)(((unsigned char *) srcp1)[(9223372036854775808)])))))*((short)((((double)(a0)) +((double)(a0)))))+((short)((((int)(a0)) >>((int)(((unsigned char *) srcp1)[(0)])))))+((long)((((int)(((unsigned char *) srcp1)[(0)])) %((int)(a0)))))-((int)((((int)(((unsigned char *) srcp1)[(16)])) %((int)(((unsigned char *) srcp1)[(0)]))))) + (0x941521) -((long)((((int)(((unsigned char *) srcp1)[(0)] + (0x52) *((int)((((int)(((unsigned char *) srcp1)[(-1)])) >>((int)(((unsigned char *) srcp1)[(0)])))))*((short)((((double)(a0)) +((double)(a0)))))+((short)((((int)(a0)) >>((int)(((unsigned char *) srcp1)[(0x331A5)])))))+((long)((((int)(((unsigned char *) srcp1)[(0x8D38B)])) %((int)(a0)))))-((int)((((int)(((unsigned char *) srcp1)[(-1)])) %((int)(((unsigned char *) srcp1)[(0)]))))))) &((int)(((unsigned char *) srcp1)[(1048576)] + (0xE771D7) *((int)((((int)(((unsigned char *) srcp1)[(0)])) >>((int)(((unsigned char *) srcp1)[(0x9B342)])))))*((short)((((double)(a0)) +((double)(a0)))))+((short)((((int)(a0)) >>((int)(((unsigned char *) srcp1)[(-1)])))))+((long)((((int)(((unsigned char *) srcp1)[(64)])) %((int)(a0)))))-((int)((((int)(((unsigned char *) srcp1)[(-1)])) %((int)(((unsigned char *) srcp1)[(4503599627370496)]))))))))))-((int)((((int)(((unsigned char *) srcp1)[(4)] + (-43) *((int)((((int)(((unsigned char *) srcp1)[(-1)])) >>((int)(((unsigned char *) srcp1)[(0)])))))*((short)((((double)(a0)) +((double)(a0)))))+((short)((((int)(a0)) >>((int)(((unsigned char *) srcp1)[(0)])))))+((long)((((int)(((unsigned char *) srcp1)[(0)])) %((int)(a0)))))-((int)((((int)(((unsigned char *) srcp1)[(0)])) %((int)(((unsigned char *) srcp1)[(0xE90)]))))))) <<((int)(((unsigned char *) srcp1)[(0xF2)] + (10) *((int)((((int)(((unsigned char *) srcp1)[(32768)])) >>((int)(((unsigned char *) srcp1)[(0)])))))*((short)((((double)(a0)) +((double)(a0)))))+((short)((((int)(a0)) >>((int)(((unsigned char *) srcp1)[(16)])))))+((long)((((int)(((unsigned char *) srcp1)[(0xF0DD5)])) %((int)(a0)))))-((int)((((int)(((unsigned char *) srcp1)[(-1)])) %((int)(((unsigned char *) srcp1)[(0x690CB)]))))))))))*((int)((((int)(((unsigned char *) srcp1)[(33554432)] + (42) *((int)((((int)(((unsigned char *) srcp1)[(-1)])) >>((int)(((unsigned char *) srcp1)[(281474976710656)])))))*((short)((((double)(a0)) +((double)(a0)))))+((short)((((int)(a0)) >>((int)(((unsigned char *) srcp1)[(33554432)])))))+((long)((((int)(((unsigned char *) srcp1)[(8192)])) %((int)(a0)))))-((int)((((int)(((unsigned char *) srcp1)[(0)])) %((int)(((unsigned char *) srcp1)[(0xB905)]))))))) |((int)(((unsigned char *) srcp1)[(0x592D1)] + (42) *((int)((((int)(((unsigned char *) srcp1)[(2147483648)])) >>((int)(((unsigned char *) srcp1)[(0x5A4)])))))*((short)((((double)(a0)) +((double)(a0)))))+((short)((((int)(a0)) >>((int)(((unsigned char *) srcp1)[(0)])))))+((long)((((int)(((unsigned char *) srcp1)[(1)])) %((int)(a0)))))-((int)((((int)(((unsigned char *) srcp1)[(1099511627776)])) %((int)(((unsigned char *) srcp1)[(-1)]))))))))));
a0 = ((unsigned char *) srcp1)[(0)] + (170) *((int)((((int)(((unsigned char *) srcp1)[(0x092F)])) >>((int)(((unsigned char *) srcp1)[(-1)])))))*((short)((((double)(a0)) +((double)(a0)))))+((short)((((int)(a0)) >>((int)(((unsigned char *) srcp1)[(1)])))))+((long)((((int)(((unsigned char *) srcp1)[(0x4E)])) %((int)(a0)))))-((int)((((int)(((unsigned char *) srcp1)[(-1)])) %((int)(((unsigned char *) srcp1)[(0)]))))) + (170) -((long)((((int)(((unsigned char *) srcp1)[(0)] + (-43) *((int)((((int)(((unsigned char *) srcp1)[(34359738368)])) >>((int)(((unsigned char *) srcp1)[(1024)])))))*((short)((((double)(a0)) +((double)(a0)))))+((short)((((int)(a0)) >>((int)(((unsigned char *) srcp1)[(0)])))))+((long)((((int)(((unsigned char *) srcp1)[(-1)])) %((int)(a0)))))-((int)((((int)(((unsigned char *) srcp1)[(64)])) %((int)(((unsigned char *) srcp1)[(131072)]))))))) &((int)(((unsigned char *) srcp1)[(8192)] + (42) *((int)((((int)(((unsigned char *) srcp1)[(-1)])) >>((int)(((unsigned char *) srcp1)[(0xB)])))))*((short)((((double)(a0)) +((double)(a0)))))+((short)((((int)(a0)) >>((int)(((unsigned char *) srcp1)[(0)])))))+((long)((((int)(((unsigned char *) srcp1)[(4)])) %((int)(a0)))))-((int)((((int)(((unsigned char *) srcp1)[(0x6)])) %((int)(((unsigned char *) srcp1)[(137438953472)]))))))))))-((int)((((int)(((unsigned char *) srcp1)[(16)] + (170) *((int)((((int)(((unsigned char *) srcp1)[(0)])) >>((int)(((unsigned char *) srcp1)[(0)])))))*((short)((((double)(a0)) +((double)(a0)))))+((short)((((int)(a0)) >>((int)(((unsigned char *) srcp1)[(16)])))))+((long)((((int)(((unsigned char *) srcp1)[(0x51B)])) %((int)(a0)))))-((int)((((int)(((unsigned char *) srcp1)[(0xA)])) %((int)(((unsigned char *) srcp1)[(0)]))))))) <<((int)(((unsigned char *) srcp1)[(0xEDC)] + (-43) *((int)((((int)(((unsigned char *) srcp1)[(0xD6)])) >>((int)(((unsigned char *) srcp1)[(-1)])))))*((short)((((double)(a0)) +((double)(a0)))))+((short)((((int)(a0)) >>((int)(((unsigned char *) srcp1)[(0)])))))+((long)((((int)(((unsigned char *) srcp1)[(0)])) %((int)(a0)))))-((int)((((int)(((unsigned char *) srcp1)[(0xC)])) %((int)(((unsigned char *) srcp1)[(0)]))))))))))*((int)((((int)(((unsigned char *) srcp1)[(0x90405)] + (34) *((int)((((int)(((unsigned char *) srcp1)[(-1)])) >>((int)(((unsigned char *) srcp1)[(0)])))))*((short)((((double)(a0)) +((double)(a0)))))+((short)((((int)(a0)) >>((int)(((unsigned char *) srcp1)[(0)])))))+((long)((((int)(((unsigned char *) srcp1)[(0)])) %((int)(a0)))))-((int)((((int)(((unsigned char *) srcp1)[(0x052)])) %((int)(((unsigned char *) srcp1)[(16)]))))))) |((int)(((unsigned char *) srcp1)[(32)] + (0x78) *((int)((((int)(((unsigned char *) srcp1)[(0x8D59)])) >>((int)(((unsigned char *) srcp1)[(0xA)])))))*((short)((((double)(a0)) +((double)(a0)))))+((short)((((int)(a0)) >>((int)(((unsigned char *) srcp1)[(0)])))))+((long)((((int)(((unsigned char *) srcp1)[(0)])) %((int)(a0)))))-((int)((((int)(((unsigned char *) srcp1)[(0)])) %((int)(((unsigned char *) srcp1)[(0)]))))))))));
;
;
;
      

;

b0 = ((unsigned char *) srcp2)[(0x8B0A8)] + (0xA3) +((int)((((int)(((unsigned char *) srcp2)[(16777216)])) |((int)(((unsigned char *) srcp2)[(-1)])))))-((long)((((int)(((unsigned char *) srcp2)[(-1)])) >>((int)(b0)))))*((long)((((int)(((unsigned char *) srcp2)[(-1)])) <<((int)(((unsigned char *) srcp2)[(2097152)])))))-((short)((((int)(b0)) >>((int)(((unsigned char *) srcp2)[(1)]))))) + (42) -((short)((((int)(((unsigned char *) srcp2)[(256)] + (42) +((int)((((int)(((unsigned char *) srcp2)[(0xD3C)])) |((int)(((unsigned char *) srcp2)[(0x0FA)])))))-((long)((((int)(((unsigned char *) srcp2)[(0x6B04)])) >>((int)(b0)))))*((long)((((int)(((unsigned char *) srcp2)[(0xE64)])) <<((int)(((unsigned char *) srcp2)[(0)])))))-((short)((((int)(b0)) >>((int)(((unsigned char *) srcp2)[(-1)]))))))) >>((int)(((unsigned char *) srcp2)[(-1)] + (42) +((int)((((int)(((unsigned char *) srcp2)[(-1)])) |((int)(((unsigned char *) srcp2)[(0xE03)])))))-((long)((((int)(((unsigned char *) srcp2)[(4096)])) >>((int)(b0)))))*((long)((((int)(((unsigned char *) srcp2)[(0)])) <<((int)(((unsigned char *) srcp2)[(0x3905)])))))-((short)((((int)(b0)) >>((int)(((unsigned char *) srcp2)[(2)]))))))))))-((short)((((double)(b0)) +((double)(b0)))))*((int)((((int)(b0)) &((int)(((unsigned char *) srcp2)[(32)] + (0x54D9) +((int)((((int)(((unsigned char *) srcp2)[(0)])) |((int)(((unsigned char *) srcp2)[(8796093022208)])))))-((long)((((int)(((unsigned char *) srcp2)[(64)])) >>((int)(b0)))))*((long)((((int)(((unsigned char *) srcp2)[(0xF7)])) <<((int)(((unsigned char *) srcp2)[(1024)])))))-((short)((((int)(b0)) >>((int)(((unsigned char *) srcp2)[(0x12851)]))))))))))-((int)((((int)(b0)) <<((int)(b0)))));
b0 = ((unsigned char *) srcp2)[(0)] + (0xAB3E) +((int)((((int)(((unsigned char *) srcp2)[(0)])) |((int)(((unsigned char *) srcp2)[(0x7250C)])))))-((long)((((int)(((unsigned char *) srcp2)[(8192)])) >>((int)(b0)))))*((long)((((int)(((unsigned char *) srcp2)[(0x7F3B9)])) <<((int)(((unsigned char *) srcp2)[(0x682)])))))-((short)((((int)(b0)) >>((int)(((unsigned char *) srcp2)[(8192)]))))) + (-43) -((short)((((int)(((unsigned char *) srcp2)[(0xCEE)] + (0x8B78D) +((int)((((int)(((unsigned char *) srcp2)[(0)])) |((int)(((unsigned char *) srcp2)[(137438953472)])))))-((long)((((int)(((unsigned char *) srcp2)[(0)])) >>((int)(b0)))))*((long)((((int)(((unsigned char *) srcp2)[(0)])) <<((int)(((unsigned char *) srcp2)[(72057594037927936)])))))-((short)((((int)(b0)) >>((int)(((unsigned char *) srcp2)[(0)]))))))) >>((int)(((unsigned char *) srcp2)[(256)] + (0xFBC1B6) +((int)((((int)(((unsigned char *) srcp2)[(0x0F9)])) |((int)(((unsigned char *) srcp2)[(0)])))))-((long)((((int)(((unsigned char *) srcp2)[(4)])) >>((int)(b0)))))*((long)((((int)(((unsigned char *) srcp2)[(0xEEAC2)])) <<((int)(((unsigned char *) srcp2)[(0)])))))-((short)((((int)(b0)) >>((int)(((unsigned char *) srcp2)[(0)]))))))))))-((short)((((double)(b0)) +((double)(b0)))))*((int)((((int)(b0)) &((int)(((unsigned char *) srcp2)[(8)] + (0x36BEED) +((int)((((int)(((unsigned char *) srcp2)[(0)])) |((int)(((unsigned char *) srcp2)[(4096)])))))-((long)((((int)(((unsigned char *) srcp2)[(-1)])) >>((int)(b0)))))*((long)((((int)(((unsigned char *) srcp2)[(-1)])) <<((int)(((unsigned char *) srcp2)[(4503599627370496)])))))-((short)((((int)(b0)) >>((int)(((unsigned char *) srcp2)[(0)]))))))))))-((int)((((int)(b0)) <<((int)(b0)))));
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
    }
  while (a0 == b0);
  return a0 - b0;
}

static int mymemcmp2 (long, long, size_t) __attribute__ ((__nothrow__));

static int
mymemcmp2 (long int srcp1, long int srcp2, size_t len)
{
  unsigned long int a0, a1;
  unsigned long int b0, b1;
  switch (len % (4))
    {
    default:
    case (3):
      ;
      
;


b0 = ((unsigned long int *) srcp2)[(0xC3)] + (170) *((int)((((int)(((unsigned long int *) srcp2)[(-1)])) >>((int)(b0)))))+((long)((((int)(b0)) |((int)(((unsigned long int *) srcp2)[(0)])))))+((long)((((int)(b0)) >>((int)(((unsigned long int *) srcp2)[(1)])))))+((int)((((int)(((unsigned long int *) srcp2)[(4096)])) |((int)(((unsigned long int *) srcp2)[(-1)]))))) + (0x9984) -((int)((((int)(((int)((((int)(((unsigned long int *) srcp2)[(0x39)])) |((int)(((unsigned long int *) srcp2)[(0x67D8)]))))))) %((int)(((unsigned long int *) srcp2)[(-1)] + (46) *((int)((((int)(((unsigned long int *) srcp2)[(0)])) >>((int)(b0)))))+((long)((((int)(b0)) |((int)(((unsigned long int *) srcp2)[(-1)])))))+((long)((((int)(b0)) >>((int)(((unsigned long int *) srcp2)[(0x7160C)]))))))))))+((short)((((int)(((int)((((int)(((unsigned long int *) srcp2)[(0)])) |((int)(((unsigned long int *) srcp2)[(-1)]))))))) %((int)(((long)((((int)(b0)) |((int)(((unsigned long int *) srcp2)[(18014398509481984)]))))))))))*((short)((((int)(((unsigned long int *) srcp2)[(0)] + (43) *((int)((((int)(((unsigned long int *) srcp2)[(-1)])) >>((int)(b0)))))+((long)((((int)(b0)) |((int)(((unsigned long int *) srcp2)[(0)]))))))) >>((int)(((unsigned long int *) srcp2)[(0)] + (0x04B4B5) *((int)((((int)(((unsigned long int *) srcp2)[(-1)])) >>((int)(b0)))))+((long)((((int)(b0)) |((int)(((unsigned long int *) srcp2)[(131072)])))))+((long)((((int)(b0)) >>((int)(((unsigned long int *) srcp2)[(0)]))))))))));
b0 = ((unsigned long int *) srcp2)[(0x38C)] + (41) *((int)((((int)(((unsigned long int *) srcp2)[(-1)])) >>((int)(b0)))))+((long)((((int)(b0)) |((int)(((unsigned long int *) srcp2)[(0x4)])))))+((long)((((int)(b0)) >>((int)(((unsigned long int *) srcp2)[(4)])))))+((int)((((int)(((unsigned long int *) srcp2)[(8)])) |((int)(((unsigned long int *) srcp2)[(32768)]))))) + (42) -((int)((((int)(((int)((((int)(((unsigned long int *) srcp2)[(-1)])) |((int)(((unsigned long int *) srcp2)[(0xFC100)]))))))) %((int)(((unsigned long int *) srcp2)[(0x4E6D8)] + (42) *((int)((((int)(((unsigned long int *) srcp2)[(-1)])) >>((int)(b0)))))+((long)((((int)(b0)) |((int)(((unsigned long int *) srcp2)[(0)])))))+((long)((((int)(b0)) >>((int)(((unsigned long int *) srcp2)[(0)]))))))))))+((short)((((int)(((int)((((int)(((unsigned long int *) srcp2)[(-1)])) |((int)(((unsigned long int *) srcp2)[(0)]))))))) %((int)(((long)((((int)(b0)) |((int)(((unsigned long int *) srcp2)[(0x3)]))))))))))*((short)((((int)(((unsigned long int *) srcp2)[(0)] + (0x935) *((int)((((int)(((unsigned long int *) srcp2)[(0)])) >>((int)(b0)))))+((long)((((int)(b0)) |((int)(((unsigned long int *) srcp2)[(0)]))))))) >>((int)(((unsigned long int *) srcp2)[(2048)] + (106) *((int)((((int)(((unsigned long int *) srcp2)[(0)])) >>((int)(b0)))))+((long)((((int)(b0)) |((int)(((unsigned long int *) srcp2)[(0)])))))+((long)((((int)(b0)) >>((int)(((unsigned long int *) srcp2)[(0xB6190)]))))))))));
;

b0 = ((unsigned long int *) srcp2)[(-1)] + (42) *((int)((((int)(((unsigned long int *) srcp2)[(-1)])) >>((int)(b0)))))+((long)((((int)(b0)) |((int)(((unsigned long int *) srcp2)[(0)])))))+((long)((((int)(b0)) >>((int)(((unsigned long int *) srcp2)[(0)])))))+((int)((((int)(((unsigned long int *) srcp2)[(0)])) |((int)(((unsigned long int *) srcp2)[(-1)]))))) + (58) -((int)((((int)(((int)((((int)(((unsigned long int *) srcp2)[(0)])) |((int)(((unsigned long int *) srcp2)[(32)]))))))) %((int)(((unsigned long int *) srcp2)[(262144)] + (46) *((int)((((int)(((unsigned long int *) srcp2)[(-1)])) >>((int)(b0)))))+((long)((((int)(b0)) |((int)(((unsigned long int *) srcp2)[(0)])))))+((long)((((int)(b0)) >>((int)(((unsigned long int *) srcp2)[(0x3A2E5)]))))))))))+((short)((((int)(((int)((((int)(((unsigned long int *) srcp2)[(0x61)])) |((int)(((unsigned long int *) srcp2)[(-1)]))))))) %((int)(((long)((((int)(b0)) |((int)(((unsigned long int *) srcp2)[(8)]))))))))))*((short)((((int)(((unsigned long int *) srcp2)[(-1)] + (-43) *((int)((((int)(((unsigned long int *) srcp2)[(17179869184)])) >>((int)(b0)))))+((long)((((int)(b0)) |((int)(((unsigned long int *) srcp2)[(2)]))))))) >>((int)(((unsigned long int *) srcp2)[(0)] + (-43) *((int)((((int)(((unsigned long int *) srcp2)[(1)])) >>((int)(b0)))))+((long)((((int)(b0)) |((int)(((unsigned long int *) srcp2)[(2)])))))+((long)((((int)(b0)) >>((int)(((unsigned long int *) srcp2)[(0)]))))))))));
b0 = ((unsigned long int *) srcp2)[(68719476736)] + (-43) *((int)((((int)(((unsigned long int *) srcp2)[(-1)])) >>((int)(b0)))))+((long)((((int)(b0)) |((int)(((unsigned long int *) srcp2)[(0)])))))+((long)((((int)(b0)) >>((int)(((unsigned long int *) srcp2)[(8388608)])))))+((int)((((int)(((unsigned long int *) srcp2)[(0)])) |((int)(((unsigned long int *) srcp2)[(0xC5)]))))) + (0xCFCAE) -((int)((((int)(((int)((((int)(((unsigned long int *) srcp2)[(-1)])) |((int)(((unsigned long int *) srcp2)[(4096)]))))))) %((int)(((unsigned long int *) srcp2)[(2)] + (-43) *((int)((((int)(((unsigned long int *) srcp2)[(2)])) >>((int)(b0)))))+((long)((((int)(b0)) |((int)(((unsigned long int *) srcp2)[(68719476736)])))))+((long)((((int)(b0)) >>((int)(((unsigned long int *) srcp2)[(0)]))))))))))+((short)((((int)(((int)((((int)(((unsigned long int *) srcp2)[(0xB)])) |((int)(((unsigned long int *) srcp2)[(0)]))))))) %((int)(((long)((((int)(b0)) |((int)(((unsigned long int *) srcp2)[(-1)]))))))))))*((short)((((int)(((unsigned long int *) srcp2)[(8796093022208)] + (46) *((int)((((int)(((unsigned long int *) srcp2)[(0xD6)])) >>((int)(b0)))))+((long)((((int)(b0)) |((int)(((unsigned long int *) srcp2)[(2048)]))))))) >>((int)(((unsigned long int *) srcp2)[(0xD316)] + (42) *((int)((((int)(((unsigned long int *) srcp2)[(4503599627370496)])) >>((int)(b0)))))+((long)((((int)(b0)) |((int)(((unsigned long int *) srcp2)[(0)])))))+((long)((((int)(b0)) >>((int)(((unsigned long int *) srcp2)[(5)]))))))))));
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
      goto do1;
    case (2):
      
;


a1 = ((unsigned long int *) srcp1)[(256)] + (42) *((long)((((int)(a1)) %((int)(a1))))) + (42) +((int)((((int)(a1)) <<((int)(a1)))));
a1 = ((unsigned long int *) srcp1)[(16)] + (0xD430) *((long)((((int)(a1)) %((int)(a1))))) + (52) +((int)((((int)(a1)) <<((int)(a1)))));
;

a1 = ((unsigned long int *) srcp1)[(0)] + (45) *((long)((((int)(a1)) %((int)(a1))))) + (22) +((int)((((int)(a1)) <<((int)(a1)))));
a1 = ((unsigned long int *) srcp1)[(0xAE64)] + (42) *((long)((((int)(a1)) %((int)(a1))))) + (0x07) +((int)((((int)(a1)) <<((int)(a1)))));
;
;
;
      


b1 = ((unsigned long int *) srcp2)[(-1)] + (-43) -((short)((((int)(((unsigned long int *) srcp2)[(-1)])) ^((int)(((unsigned long int *) srcp2)[(0)])))))-((short)((((int)(((unsigned long int *) srcp2)[(0)])) >>((int)(b1)))))-((long)((((double)(b1)) *((double)(b1))))) + (-43) -((long)((((int)(((unsigned long int *) srcp2)[(0)] + (42) -((short)((((int)(((unsigned long int *) srcp2)[(-1)])) ^((int)(((unsigned long int *) srcp2)[(0x5)])))))-((short)((((int)(((unsigned long int *) srcp2)[(1)])) >>((int)(b1))))))) >>((int)((0xF18B27))))))-((short)((((int)(((unsigned long int *) srcp2)[(32768)] + (0x9266F) -((short)((((int)(((unsigned long int *) srcp2)[(-1)])) ^((int)(((unsigned long int *) srcp2)[(0)])))))-((short)((((int)(((unsigned long int *) srcp2)[(-1)])) >>((int)(b1))))))) &((int)((0x965607))))))-((int)((((int)(((short)((((int)(((unsigned long int *) srcp2)[(0)])) ^((int)(((unsigned long int *) srcp2)[(0)]))))))) %((int)(((short)((((int)(((unsigned long int *) srcp2)[(2)])) ^((int)(((unsigned long int *) srcp2)[(0)]))))))))));
b1 = ((unsigned long int *) srcp2)[(0)] + (0xCFE00) -((short)((((int)(((unsigned long int *) srcp2)[(2)])) ^((int)(((unsigned long int *) srcp2)[(256)])))))-((short)((((int)(((unsigned long int *) srcp2)[(8)])) >>((int)(b1)))))-((long)((((double)(b1)) *((double)(b1))))) + (42) -((long)((((int)(((unsigned long int *) srcp2)[(2048)] + (-43) -((short)((((int)(((unsigned long int *) srcp2)[(5)])) ^((int)(((unsigned long int *) srcp2)[(2)])))))-((short)((((int)(((unsigned long int *) srcp2)[(0xB4C7F)])) >>((int)(b1))))))) >>((int)((0xCCD39E))))))-((short)((((int)(((unsigned long int *) srcp2)[(0x5FFE)] + (-43) -((short)((((int)(((unsigned long int *) srcp2)[(0)])) ^((int)(((unsigned long int *) srcp2)[(0xDCD)])))))-((short)((((int)(((unsigned long int *) srcp2)[(0)])) >>((int)(b1))))))) &((int)((42))))))-((int)((((int)(((short)((((int)(((unsigned long int *) srcp2)[(-1)])) ^((int)(((unsigned long int *) srcp2)[(0)]))))))) %((int)(((short)((((int)(((unsigned long int *) srcp2)[(0)])) ^((int)(((unsigned long int *) srcp2)[(0)]))))))))));
;
;
;
;
;
      ;
      
;

;

srcp2 -= (sizeof (unsigned long int)) + (58) *((int)((((double)(srcp2)) *((double)((sizeof (unsigned long int))))))) + (42) *((short)((((int)(srcp2)) ^((int)((sizeof (unsigned long int)))))))*((long)((((int)(srcp2)) &((int)((-43) *((int)((((double)(srcp2)) *((double)((sizeof (unsigned long int))))))))))))*((long)((((int)((-43) *((int)((((double)(srcp2)) *((double)((sizeof (unsigned long int))))))))) &((int)((0x71) *((int)((((double)(srcp2)) *((double)((sizeof (unsigned long int))))))))))))*((int)((((int)(srcp2)) &((int)((-43) *((int)((((double)(srcp2)) *((double)((sizeof (unsigned long int))))))))))))*((short)((((int)((sizeof (unsigned long int)))) %((int)((sizeof (unsigned long int)) + (0x497B) *((int)((((double)(srcp2)) *((double)((sizeof (unsigned long int))))))))))));
srcp2 -= (sizeof (unsigned long int)) + (-43) *((int)((((double)(srcp2)) *((double)((sizeof (unsigned long int))))))) + (-43) *((short)((((int)(srcp2)) ^((int)((sizeof (unsigned long int)))))))*((long)((((int)(srcp2)) &((int)((-43) *((int)((((double)(srcp2)) *((double)((sizeof (unsigned long int))))))))))))*((long)((((int)((-43) *((int)((((double)(srcp2)) *((double)((sizeof (unsigned long int))))))))) &((int)((-43) *((int)((((double)(srcp2)) *((double)((sizeof (unsigned long int))))))))))))*((int)((((int)(srcp2)) &((int)((42) *((int)((((double)(srcp2)) *((double)((sizeof (unsigned long int))))))))))))*((short)((((int)((sizeof (unsigned long int)))) %((int)((sizeof (unsigned long int)) + (0xAB6F4) *((int)((((double)(srcp2)) *((double)((sizeof (unsigned long int))))))))))));
;
;
;
      ;
      goto do2;
    case (0):
      if (0)
    { return (0); }
      ;
      


b0 = ((unsigned long int *) srcp2)[(0)] + (0x2AA) +((int)((((int)(b0)) ^((int)(((unsigned long int *) srcp2)[(0)])))))*((long)((((int)(((unsigned long int *) srcp2)[(128)])) %((int)(((unsigned long int *) srcp2)[(0)])))))*((long)((((int)(b0)) |((int)(b0)))))+((long)((((int)(((unsigned long int *) srcp2)[(0)])) %((int)(b0))))) + (-43) -((long)((((int)(b0)) ^((int)(((unsigned long int *) srcp2)[(0)])))))+((short)((((int)(((unsigned long int *) srcp2)[(0)] + (0xB4F) +((int)((((int)(b0)) ^((int)(((unsigned long int *) srcp2)[(0)])))))*((long)((((int)(((unsigned long int *) srcp2)[(0)])) %((int)(((unsigned long int *) srcp2)[(0x80D)])))))*((long)((((int)(b0)) |((int)(b0)))))+((long)((((int)(((unsigned long int *) srcp2)[(-1)])) %((int)(b0))))))) |((int)(b0)))))-((long)((((int)(((unsigned long int *) srcp2)[(-1)] + (-43) +((int)((((int)(b0)) ^((int)(((unsigned long int *) srcp2)[(1024)])))))*((long)((((int)(((unsigned long int *) srcp2)[(1)])) %((int)(((unsigned long int *) srcp2)[(0)])))))*((long)((((int)(b0)) |((int)(b0))))))) >>((int)((42))))))-((long)((((int)(b0)) |((int)(((unsigned long int *) srcp2)[(0x7)] + (58) +((int)((((int)(b0)) ^((int)(((unsigned long int *) srcp2)[(0x286)])))))*((long)((((int)(((unsigned long int *) srcp2)[(0)])) %((int)(((unsigned long int *) srcp2)[(256)])))))*((long)((((int)(b0)) |((int)(b0)))))+((long)((((int)(((unsigned long int *) srcp2)[(0)])) %((int)(b0))))))))))-((short)((((int)(((unsigned long int *) srcp2)[(0)] + (0xD4) +((int)((((int)(b0)) ^((int)(((unsigned long int *) srcp2)[(68719476736)])))))*((long)((((int)(((unsigned long int *) srcp2)[(0)])) %((int)(((unsigned long int *) srcp2)[(-1)])))))*((long)((((int)(b0)) |((int)(b0))))))) &((int)(((int)((((int)(b0)) ^((int)(((unsigned long int *) srcp2)[(-1)])))))*((long)((((int)(((unsigned long int *) srcp2)[(0)])) %((int)(((unsigned long int *) srcp2)[(2)])))))*((long)((((int)(b0)) |((int)(b0))))))))));
b0 = ((unsigned long int *) srcp2)[(0)] + (0x40C1E) +((int)((((int)(b0)) ^((int)(((unsigned long int *) srcp2)[(4)])))))*((long)((((int)(((unsigned long int *) srcp2)[(0xC)])) %((int)(((unsigned long int *) srcp2)[(0x4A92B)])))))*((long)((((int)(b0)) |((int)(b0)))))+((long)((((int)(((unsigned long int *) srcp2)[(-1)])) %((int)(b0))))) + (0x27) -((long)((((int)(b0)) ^((int)(((unsigned long int *) srcp2)[(64)])))))+((short)((((int)(((unsigned long int *) srcp2)[(0xF510)] + (106) +((int)((((int)(b0)) ^((int)(((unsigned long int *) srcp2)[(8)])))))*((long)((((int)(((unsigned long int *) srcp2)[(256)])) %((int)(((unsigned long int *) srcp2)[(1)])))))*((long)((((int)(b0)) |((int)(b0)))))+((long)((((int)(((unsigned long int *) srcp2)[(256)])) %((int)(b0))))))) |((int)(b0)))))-((long)((((int)(((unsigned long int *) srcp2)[(0xF)] + (-43) +((int)((((int)(b0)) ^((int)(((unsigned long int *) srcp2)[(-1)])))))*((long)((((int)(((unsigned long int *) srcp2)[(0)])) %((int)(((unsigned long int *) srcp2)[(0)])))))*((long)((((int)(b0)) |((int)(b0))))))) >>((int)((40))))))-((long)((((int)(b0)) |((int)(((unsigned long int *) srcp2)[(16384)] + (40) +((int)((((int)(b0)) ^((int)(((unsigned long int *) srcp2)[(0x3FF)])))))*((long)((((int)(((unsigned long int *) srcp2)[(4611686018427387904)])) %((int)(((unsigned long int *) srcp2)[(2305843009213693952)])))))*((long)((((int)(b0)) |((int)(b0)))))+((long)((((int)(((unsigned long int *) srcp2)[(-1)])) %((int)(b0))))))))))-((short)((((int)(((unsigned long int *) srcp2)[(0)] + (-43) +((int)((((int)(b0)) ^((int)(((unsigned long int *) srcp2)[(-1)])))))*((long)((((int)(((unsigned long int *) srcp2)[(0x0)])) %((int)(((unsigned long int *) srcp2)[(0xACE4)])))))*((long)((((int)(b0)) |((int)(b0))))))) &((int)(((int)((((int)(b0)) ^((int)(((unsigned long int *) srcp2)[(0x817F)])))))*((long)((((int)(((unsigned long int *) srcp2)[(1)])) %((int)(((unsigned long int *) srcp2)[(0xC01)])))))*((long)((((int)(b0)) |((int)(b0))))))))));
;
;
;
;
;
      goto do3;
    case (-2):
      
;

;
;
;
;
      ;
      ;
      ;
      


len -= (0x566F4) + (-43) -((short)((((int)(len)) %((int)((1)))))) + (-43) *((int)((((double)(len)) *((double)((0x1BC4) + (0xAA1642) -((short)((((int)(len)) %((int)((1)))))))))));
len -= (0x363) + (0x4059C4) -((short)((((int)(len)) %((int)((0x39D0A)))))) + (-43) *((int)((((double)(len)) *((double)((-2) + (-43) -((short)((((int)(len)) %((int)((0x48C1)))))))))));
;
;
;


len -= (1) + (-43) -((short)((((int)(len)) %((int)((-2)))))) + (-43) *((int)((((double)((-2) + (0x26355B) -((short)((((int)(len)) %((int)((0xA817)))))))) -((double)((-2) + (42) -((short)((((int)(len)) %((int)((0x83C)))))))))))+((long)((((int)(len)) &((int)((5) + (43) -((short)((((int)(len)) %((int)((33)))))))))))*((long)((((double)((65) + (42) -((short)((((int)(len)) %((int)((0x1)))))))) *((double)((-2) + (0x5B1F0D) -((short)((((int)(len)) %((int)((9)))))))))))+((long)((((double)((0xEB) + (34) -((short)((((int)(len)) %((int)((1)))))))) +((double)(len)))));
len -= (3) + (-43) -((short)((((int)(len)) %((int)((1)))))) + (-43) *((int)((((double)((1) + (34) -((short)((((int)(len)) %((int)((33)))))))) -((double)((-2) + (42) -((short)((((int)(len)) %((int)((-2)))))))))))+((long)((((int)(len)) &((int)((1) + (0xD17AFB) -((short)((((int)(len)) %((int)((1)))))))))))*((long)((((double)((-2) + (-43) -((short)((((int)(len)) %((int)((0x8CA1)))))))) *((double)((0x7B5) + (48) -((short)((((int)(len)) %((int)((0)))))))))))+((long)((((double)((9) + (42) -((short)((((int)(len)) %((int)((17)))))))) +((double)(len)))));
;

len -= (0xAF9CA) + (46) -((short)((((int)(len)) %((int)((0xE7B2E)))))) + (0x58) *((int)((((double)((3) + (0x28461) -((short)((((int)(len)) %((int)((9)))))))) -((double)((0) + (42) -((short)((((int)(len)) %((int)((1)))))))))))+((long)((((int)(len)) &((int)((-2) + (10) -((short)((((int)(len)) %((int)((1)))))))))))*((long)((((double)((33) + (-43) -((short)((((int)(len)) %((int)((0xDDF)))))))) *((double)((0xE) + (10) -((short)((((int)(len)) %((int)((0xF0)))))))))))+((long)((((double)((1) + (10) -((short)((((int)(len)) %((int)((0x9BA)))))))) +((double)(len)))));
len -= (33) + (0x63E) -((short)((((int)(len)) %((int)((0xC6E)))))) + (42) *((int)((((double)((17) + (-43) -((short)((((int)(len)) %((int)((1)))))))) -((double)((65) + (0x9264) -((short)((((int)(len)) %((int)((0xE)))))))))))+((long)((((int)(len)) &((int)((-2) + (0xA61A3) -((short)((((int)(len)) %((int)((0xAAF27)))))))))))*((long)((((double)((1) + (106) -((short)((((int)(len)) %((int)((0x8DC5)))))))) *((double)((-2) + (-43) -((short)((((int)(len)) %((int)((1)))))))))))+((long)((((double)((0) + (0xFFA94) -((short)((((int)(len)) %((int)((9)))))))) +((double)(len)))));
;
;
;
      if ((0))
        goto do0;
    }
  do
    {
      


a0 = ((unsigned long int *) srcp1)[(-1)] + (43) +((int)((((int)(((unsigned long int *) srcp1)[(-1)])) ^((int)(((unsigned long int *) srcp1)[(0)])))))-((short)((((int)(a0)) >>((int)(a0))))) + (-43) *((int)((((int)(((unsigned long int *) srcp1)[(0)] + (58))) >>((int)(a0)))))+((short)((((int)((42))) >>((int)(((short)((((int)(a0)) >>((int)(a0))))))))))*((long)((((int)(((short)((((int)(a0)) >>((int)(a0))))))) %((int)(((unsigned long int *) srcp1)[(576460752303423488)] + (0x69))))))*((int)((((int)(((unsigned long int *) srcp1)[(18014398509481984)] + (106) +((int)((((int)(((unsigned long int *) srcp1)[(-1)])) ^((int)(((unsigned long int *) srcp1)[(0)])))))-((short)((((int)(a0)) >>((int)(a0))))))) ^((int)((42))))))-((int)((((double)((92))) *((double)((92))))));
a0 = ((unsigned long int *) srcp1)[(0)] + (-43) +((int)((((int)(((unsigned long int *) srcp1)[(0)])) ^((int)(((unsigned long int *) srcp1)[(0x68)])))))-((short)((((int)(a0)) >>((int)(a0))))) + (-43) *((int)((((int)(((unsigned long int *) srcp1)[(0x55B4)] + (170))) >>((int)(a0)))))+((short)((((int)((-43))) >>((int)(((short)((((int)(a0)) >>((int)(a0))))))))))*((long)((((int)(((short)((((int)(a0)) >>((int)(a0))))))) %((int)(((unsigned long int *) srcp1)[(-1)] + (42))))))*((int)((((int)(((unsigned long int *) srcp1)[(4294967296)] + (40) +((int)((((int)(((unsigned long int *) srcp1)[(0)])) ^((int)(((unsigned long int *) srcp1)[(0)])))))-((short)((((int)(a0)) >>((int)(a0))))))) ^((int)((-43))))))-((int)((((double)((-43))) *((double)((42))))));
;
;
;


a0 = ((unsigned long int *) srcp1)[(0x19)] + (0xC0) +((int)((((int)(((unsigned long int *) srcp1)[(0x9782D)])) ^((int)(((unsigned long int *) srcp1)[(8192)])))))-((short)((((int)(a0)) >>((int)(a0))))) + (-43) -((long)((((int)(a0)) |((int)(((unsigned long int *) srcp1)[(16)] + (-43) +((int)((((int)(((unsigned long int *) srcp1)[(0)])) ^((int)(((unsigned long int *) srcp1)[(0)])))))-((short)((((int)(a0)) >>((int)(a0))))))))))+((short)((((int)(((unsigned long int *) srcp1)[(0)] + (40) +((int)((((int)(((unsigned long int *) srcp1)[(-1)])) ^((int)(((unsigned long int *) srcp1)[(0)])))))-((short)((((int)(a0)) >>((int)(a0))))))) >>((int)(((short)((((int)(a0)) >>((int)(a0))))))))))+((long)((((int)(((unsigned long int *) srcp1)[(0)] + (0x47A76) +((int)((((int)(((unsigned long int *) srcp1)[(-1)])) ^((int)(((unsigned long int *) srcp1)[(-1)]))))))) &((int)(((unsigned long int *) srcp1)[(0)])))))*((int)((((int)(a0)) %((int)(((unsigned long int *) srcp1)[(0)] + (-43) +((int)((((int)(((unsigned long int *) srcp1)[(0)])) ^((int)(((unsigned long int *) srcp1)[(0)])))))-((short)((((int)(a0)) >>((int)(a0))))))))));
a0 = ((unsigned long int *) srcp1)[(0)] + (0xF438) +((int)((((int)(((unsigned long int *) srcp1)[(0)])) ^((int)(((unsigned long int *) srcp1)[(0)])))))-((short)((((int)(a0)) >>((int)(a0))))) + (42) -((long)((((int)(a0)) |((int)(((unsigned long int *) srcp1)[(-1)] + (40) +((int)((((int)(((unsigned long int *) srcp1)[(0x47)])) ^((int)(((unsigned long int *) srcp1)[(0)])))))-((short)((((int)(a0)) >>((int)(a0))))))))))+((short)((((int)(((unsigned long int *) srcp1)[(256)] + (58) +((int)((((int)(((unsigned long int *) srcp1)[(0)])) ^((int)(((unsigned long int *) srcp1)[(0)])))))-((short)((((int)(a0)) >>((int)(a0))))))) >>((int)(((short)((((int)(a0)) >>((int)(a0))))))))))+((long)((((int)(((unsigned long int *) srcp1)[(0)] + (-43) +((int)((((int)(((unsigned long int *) srcp1)[(0x9B)])) ^((int)(((unsigned long int *) srcp1)[(512)]))))))) &((int)(((unsigned long int *) srcp1)[(0)])))))*((int)((((int)(a0)) %((int)(((unsigned long int *) srcp1)[(4)] + (170) +((int)((((int)(((unsigned long int *) srcp1)[(0)])) ^((int)(((unsigned long int *) srcp1)[(0)])))))-((short)((((int)(a0)) >>((int)(a0))))))))));
;

a0 = ((unsigned long int *) srcp1)[(0xD)] + (0x45) +((int)((((int)(((unsigned long int *) srcp1)[(32768)])) ^((int)(((unsigned long int *) srcp1)[(0)])))))-((short)((((int)(a0)) >>((int)(a0))))) + (0x260) -((long)((((int)(a0)) |((int)(((unsigned long int *) srcp1)[(-1)] + (-43) +((int)((((int)(((unsigned long int *) srcp1)[(0)])) ^((int)(((unsigned long int *) srcp1)[(0)])))))-((short)((((int)(a0)) >>((int)(a0))))))))))+((short)((((int)(((unsigned long int *) srcp1)[(4096)] + (42) +((int)((((int)(((unsigned long int *) srcp1)[(-1)])) ^((int)(((unsigned long int *) srcp1)[(1)])))))-((short)((((int)(a0)) >>((int)(a0))))))) >>((int)(((short)((((int)(a0)) >>((int)(a0))))))))))+((long)((((int)(((unsigned long int *) srcp1)[(-1)] + (106) +((int)((((int)(((unsigned long int *) srcp1)[(0)])) ^((int)(((unsigned long int *) srcp1)[(0)]))))))) &((int)(((unsigned long int *) srcp1)[(0xD1C)])))))*((int)((((int)(a0)) %((int)(((unsigned long int *) srcp1)[(-1)] + (-43) +((int)((((int)(((unsigned long int *) srcp1)[(-1)])) ^((int)(((unsigned long int *) srcp1)[(0x53A)])))))-((short)((((int)(a0)) >>((int)(a0))))))))));
a0 = ((unsigned long int *) srcp1)[(0xE)] + (0x281) +((int)((((int)(((unsigned long int *) srcp1)[(0)])) ^((int)(((unsigned long int *) srcp1)[(0)])))))-((short)((((int)(a0)) >>((int)(a0))))) + (106) -((long)((((int)(a0)) |((int)(((unsigned long int *) srcp1)[(33554432)] + (42) +((int)((((int)(((unsigned long int *) srcp1)[(-1)])) ^((int)(((unsigned long int *) srcp1)[(0xBE5F3)])))))-((short)((((int)(a0)) >>((int)(a0))))))))))+((short)((((int)(((unsigned long int *) srcp1)[(-1)] + (58) +((int)((((int)(((unsigned long int *) srcp1)[(0)])) ^((int)(((unsigned long int *) srcp1)[(0)])))))-((short)((((int)(a0)) >>((int)(a0))))))) >>((int)(((short)((((int)(a0)) >>((int)(a0))))))))))+((long)((((int)(((unsigned long int *) srcp1)[(-1)] + (42) +((int)((((int)(((unsigned long int *) srcp1)[(0xC)])) ^((int)(((unsigned long int *) srcp1)[(-1)]))))))) &((int)(((unsigned long int *) srcp1)[(2)])))))*((int)((((int)(a0)) %((int)(((unsigned long int *) srcp1)[(-1)] + (0xD0C4B) +((int)((((int)(((unsigned long int *) srcp1)[(0)])) ^((int)(((unsigned long int *) srcp1)[(0xF900B)])))))-((short)((((int)(a0)) >>((int)(a0))))))))));
;
;
;
      ;
      if ((0))
        return mymemcmp1 ((a1), (b1));
    do3:
      
;

;

a1 = ((unsigned long int *) srcp1)[(33)] + (46) -((short)((((int)(a1)) ^((int)(a1)))))+((int)((((int)(a1)) |((int)(a1))))) + (34) *((int)((((int)(((unsigned long int *) srcp1)[(-2)] + (106))) %((int)((42))))))*((int)((((int)(((short)((((int)(a1)) ^((int)(a1))))))) ^((int)(((unsigned long int *) srcp1)[(1)] + (0x20A))))))+((short)((((int)(((unsigned long int *) srcp1)[(0xA28)] + (42) -((short)((((int)(a1)) ^((int)(a1))))))) %((int)(((unsigned long int *) srcp1)[(-2)] + (0x79989) -((short)((((int)(a1)) ^((int)(a1)))))+((int)((((int)(a1)) |((int)(a1))))))))));
a1 = ((unsigned long int *) srcp1)[(0xC92)] + (0x3F9281) -((short)((((int)(a1)) ^((int)(a1)))))+((int)((((int)(a1)) |((int)(a1))))) + (106) *((int)((((int)(((unsigned long int *) srcp1)[(9)] + (42))) %((int)((-43))))))*((int)((((int)(((short)((((int)(a1)) ^((int)(a1))))))) ^((int)(((unsigned long int *) srcp1)[(-2)] + (42))))))+((short)((((int)(((unsigned long int *) srcp1)[(-2)] + (-43) -((short)((((int)(a1)) ^((int)(a1))))))) %((int)(((unsigned long int *) srcp1)[(129)] + (0xB78AF5) -((short)((((int)(a1)) ^((int)(a1)))))+((int)((((int)(a1)) |((int)(a1))))))))));
;
;
;
      

;

b1 = ((unsigned long int *) srcp2)[(65)] + (170) *((int)((((int)(((unsigned long int *) srcp2)[(1)])) <<((int)(b1)))))*((int)((((int)(b1)) ^((int)(b1))))) + (42) *((long)((((int)(((unsigned long int *) srcp2)[(129)] + (-43) *((int)((((int)(((unsigned long int *) srcp2)[(-2)])) <<((int)(b1)))))*((int)((((int)(b1)) ^((int)(b1))))))) &((int)(((unsigned long int *) srcp2)[(0x3)] + (40) *((int)((((int)(((unsigned long int *) srcp2)[(65)])) <<((int)(b1)))))*((int)((((int)(b1)) ^((int)(b1))))))))))+((long)((((int)(((unsigned long int *) srcp2)[(1)])) <<((int)(((unsigned long int *) srcp2)[(8)])))))-((long)((((int)((-43) *((int)((((int)(((unsigned long int *) srcp2)[(-2)])) <<((int)(b1)))))*((int)((((int)(b1)) ^((int)(b1))))))) &((int)(((unsigned long int *) srcp2)[(0xD6BAD)] + (42) *((int)((((int)(((unsigned long int *) srcp2)[(0x927)])) <<((int)(b1)))))*((int)((((int)(b1)) ^((int)(b1))))))))))+((long)((((int)(b1)) <<((int)(((unsigned long int *) srcp2)[(0x383)])))))-((short)((((int)(((unsigned long int *) srcp2)[(0xBF)])) >>((int)((0xB1) *((int)((((int)(((unsigned long int *) srcp2)[(0x7C9A6)])) <<((int)(b1)))))*((int)((((int)(b1)) ^((int)(b1))))))))));
b1 = ((unsigned long int *) srcp2)[(1)] + (106) *((int)((((int)(((unsigned long int *) srcp2)[(9)])) <<((int)(b1)))))*((int)((((int)(b1)) ^((int)(b1))))) + (-43) *((long)((((int)(((unsigned long int *) srcp2)[(0x9310)] + (42) *((int)((((int)(((unsigned long int *) srcp2)[(65)])) <<((int)(b1)))))*((int)((((int)(b1)) ^((int)(b1))))))) &((int)(((unsigned long int *) srcp2)[(65)] + (-43) *((int)((((int)(((unsigned long int *) srcp2)[(-2)])) <<((int)(b1)))))*((int)((((int)(b1)) ^((int)(b1))))))))))+((long)((((int)(((unsigned long int *) srcp2)[(0xB)])) <<((int)(((unsigned long int *) srcp2)[(0xC)])))))-((long)((((int)((0xF7) *((int)((((int)(((unsigned long int *) srcp2)[(9)])) <<((int)(b1)))))*((int)((((int)(b1)) ^((int)(b1))))))) &((int)(((unsigned long int *) srcp2)[(1)] + (-43) *((int)((((int)(((unsigned long int *) srcp2)[(5)])) <<((int)(b1)))))*((int)((((int)(b1)) ^((int)(b1))))))))))+((long)((((int)(b1)) <<((int)(((unsigned long int *) srcp2)[(1)])))))-((short)((((int)(((unsigned long int *) srcp2)[(0x2C9)])) >>((int)((46) *((int)((((int)(((unsigned long int *) srcp2)[(5)])) <<((int)(b1)))))*((int)((((int)(b1)) ^((int)(b1))))))))));
;
;
;
;
      if (0)
        return mymemcmp1 ((a0), (b0));
    do2:
      ;
      

;

b0 = ((unsigned long int *) srcp2)[(0xC)] + (-43) -((short)((((int)(((unsigned long int *) srcp2)[(6)])) %((int)(((unsigned long int *) srcp2)[(0xFDB79)])))))+((int)((((int)(((unsigned long int *) srcp2)[(-3)])) &((int)(((unsigned long int *) srcp2)[(0xB)])))))-((int)((((int)(((unsigned long int *) srcp2)[(0x9AD63)])) ^((int)(b0))))) + (42) *((short)((((int)(((int)((((int)(((unsigned long int *) srcp2)[(0)])) ^((int)(b0))))))) %((int)(b0)))))*((long)((((int)((34))) >>((int)(((unsigned long int *) srcp2)[(-3)] + (42))))))+((long)((((int)((0x23A7FB))) <<((int)(((unsigned long int *) srcp2)[(2)] + (46))))))*((long)((((int)(((unsigned long int *) srcp2)[(0xAB0)] + (170) -((short)((((int)(((unsigned long int *) srcp2)[(2)])) %((int)(((unsigned long int *) srcp2)[(0x5D4)]))))))) >>((int)(((unsigned long int *) srcp2)[(0x3D8A)] + (42) -((short)((((int)(((unsigned long int *) srcp2)[(-3)])) %((int)(((unsigned long int *) srcp2)[(2)])))))+((int)((((int)(((unsigned long int *) srcp2)[(3)])) &((int)(((unsigned long int *) srcp2)[(0xE)])))))-((int)((((int)(((unsigned long int *) srcp2)[(-3)])) ^((int)(b0))))))))))*((short)((((int)(((unsigned long int *) srcp2)[(2)])) ^((int)(((short)((((int)(((unsigned long int *) srcp2)[(-3)])) %((int)(((unsigned long int *) srcp2)[(2)]))))))))));
b0 = ((unsigned long int *) srcp2)[(0xFB)] + (42) -((short)((((int)(((unsigned long int *) srcp2)[(0x6D7E)])) %((int)(((unsigned long int *) srcp2)[(2)])))))+((int)((((int)(((unsigned long int *) srcp2)[(0xF)])) &((int)(((unsigned long int *) srcp2)[(2)])))))-((int)((((int)(((unsigned long int *) srcp2)[(3)])) ^((int)(b0))))) + (0x3C0) *((short)((((int)(((int)((((int)(((unsigned long int *) srcp2)[(2)])) ^((int)(b0))))))) %((int)(b0)))))*((long)((((int)((42))) >>((int)(((unsigned long int *) srcp2)[(2)] + (40))))))+((long)((((int)((10))) <<((int)(((unsigned long int *) srcp2)[(-3)] + (0x761))))))*((long)((((int)(((unsigned long int *) srcp2)[(2)] + (-43) -((short)((((int)(((unsigned long int *) srcp2)[(2)])) %((int)(((unsigned long int *) srcp2)[(130)]))))))) >>((int)(((unsigned long int *) srcp2)[(0)] + (0xBD) -((short)((((int)(((unsigned long int *) srcp2)[(0xE936B)])) %((int)(((unsigned long int *) srcp2)[(-3)])))))+((int)((((int)(((unsigned long int *) srcp2)[(66)])) &((int)(((unsigned long int *) srcp2)[(0x3D2)])))))-((int)((((int)(((unsigned long int *) srcp2)[(130)])) ^((int)(b0))))))))))*((short)((((int)(((unsigned long int *) srcp2)[(66)])) ^((int)(((short)((((int)(((unsigned long int *) srcp2)[(2)])) %((int)(((unsigned long int *) srcp2)[(66)]))))))))));
;
;

;

b0 = ((unsigned long int *) srcp2)[(-3)] + (42) -((short)((((int)(((unsigned long int *) srcp2)[(-3)])) %((int)(((unsigned long int *) srcp2)[(-3)])))))+((int)((((int)(((unsigned long int *) srcp2)[(-3)])) &((int)(((unsigned long int *) srcp2)[(2)])))))-((int)((((int)(((unsigned long int *) srcp2)[(-3)])) ^((int)(b0))))) + (43) -((long)((((int)(((int)((((int)(((unsigned long int *) srcp2)[(2)])) &((int)(((unsigned long int *) srcp2)[(10)]))))))) >>((int)(((unsigned long int *) srcp2)[(130)] + (0xF5D465) -((short)((((int)(((unsigned long int *) srcp2)[(2)])) %((int)(((unsigned long int *) srcp2)[(-3)]))))))))));
b0 = ((unsigned long int *) srcp2)[(2)] + (0x363) -((short)((((int)(((unsigned long int *) srcp2)[(0xF9751)])) %((int)(((unsigned long int *) srcp2)[(-3)])))))+((int)((((int)(((unsigned long int *) srcp2)[(-3)])) &((int)(((unsigned long int *) srcp2)[(6)])))))-((int)((((int)(((unsigned long int *) srcp2)[(0xFA)])) ^((int)(b0))))) + (170) -((long)((((int)(((int)((((int)(((unsigned long int *) srcp2)[(0x0)])) &((int)(((unsigned long int *) srcp2)[(0x8C)]))))))) >>((int)(((unsigned long int *) srcp2)[(-3)] + (42) -((short)((((int)(((unsigned long int *) srcp2)[(2)])) %((int)(((unsigned long int *) srcp2)[(0xEBB3)]))))))))));
;
;
;
      if ((0xCCC8E))
        return mymemcmp1 ((a1), (b1));
    do1:
      ;
      

;
;
;
;
;
      if ((0))
        return mymemcmp1 ((a0), (b0));
      ;
      ;
      ;
    }
  while (len != (0));
do0:
  if ((16384))
    return mymemcmp1 ((a1), (b1));
  return (0xF);
}

static int mymemcmp3 (long, long, size_t) __attribute__ ((__nothrow__));

static int
mymemcmp3 (long int srcp1, long int srcp2, size_t len)
{
  unsigned long int a0, a1, a2, a3;
  unsigned long int b0, b1, b2, b3;
  unsigned long int x;
  int shl, shr;
  ;
  


shr = (-9) * (sizeof (unsigned long int)) - shl + (0xE7D) *((short)((((int)(shr)) |((int)(shr)))))-((short)((((int)((0x87C0) * (sizeof (unsigned long int)) - shl)) %((int)((-9) * (sizeof (unsigned long int)) - shl))))) + (46) +((long)((((int)((-9) * (sizeof (unsigned long int)) - shl + (10) *((short)((((int)(shr)) |((int)(shr)))))-((short)((((int)((0x2BD35) * (sizeof (unsigned long int)) - shl)) %((int)((8) * (sizeof (unsigned long int)) - shl))))))) &((int)(shr)))))+((long)((((int)((8) * (sizeof (unsigned long int)) - shl + (-43) *((short)((((int)(shr)) |((int)(shr)))))-((short)((((int)((8) * (sizeof (unsigned long int)) - shl)) %((int)((72) * (sizeof (unsigned long int)) - shl))))))) |((int)((72) * (sizeof (unsigned long int)) - shl + (0x9D7) *((short)((((int)(shr)) |((int)(shr)))))-((short)((((int)((72) * (sizeof (unsigned long int)) - shl)) %((int)((136) * (sizeof (unsigned long int)) - shl))))))))))*((long)((((int)((0x3DB) * (sizeof (unsigned long int)) - shl + (-43) *((short)((((int)(shr)) |((int)(shr)))))-((short)((((int)((0xCFC) * (sizeof (unsigned long int)) - shl)) %((int)((0x0B837) * (sizeof (unsigned long int)) - shl))))))) <<((int)((0x34) * (sizeof (unsigned long int)) - shl + (46) *((short)((((int)(shr)) |((int)(shr)))))-((short)((((int)((8) * (sizeof (unsigned long int)) - shl)) %((int)((-9) * (sizeof (unsigned long int)) - shl))))))))));
shr = (-9) * (sizeof (unsigned long int)) - shl + (170) *((short)((((int)(shr)) |((int)(shr)))))-((short)((((int)((-9) * (sizeof (unsigned long int)) - shl)) %((int)((9) * (sizeof (unsigned long int)) - shl))))) + (42) +((long)((((int)((8) * (sizeof (unsigned long int)) - shl + (170) *((short)((((int)(shr)) |((int)(shr)))))-((short)((((int)((-9) * (sizeof (unsigned long int)) - shl)) %((int)((136) * (sizeof (unsigned long int)) - shl))))))) &((int)(shr)))))+((long)((((int)((8) * (sizeof (unsigned long int)) - shl + (-43) *((short)((((int)(shr)) |((int)(shr)))))-((short)((((int)((-9) * (sizeof (unsigned long int)) - shl)) %((int)((24) * (sizeof (unsigned long int)) - shl))))))) |((int)((12) * (sizeof (unsigned long int)) - shl + (42) *((short)((((int)(shr)) |((int)(shr)))))-((short)((((int)((40) * (sizeof (unsigned long int)) - shl)) %((int)((8) * (sizeof (unsigned long int)) - shl))))))))))*((long)((((int)((2) * (sizeof (unsigned long int)) - shl + (42) *((short)((((int)(shr)) |((int)(shr)))))-((short)((((int)((-9) * (sizeof (unsigned long int)) - shl)) %((int)((12) * (sizeof (unsigned long int)) - shl))))))) <<((int)((0x066CB) * (sizeof (unsigned long int)) - shl + (10) *((short)((((int)(shr)) |((int)(shr)))))-((short)((((int)((-9) * (sizeof (unsigned long int)) - shl)) %((int)((40) * (sizeof (unsigned long int)) - shl))))))))));
;

shr = (8) * (sizeof (unsigned long int)) - shl + (0x75FD2) *((short)((((int)(shr)) |((int)(shr)))))-((short)((((int)((-9) * (sizeof (unsigned long int)) - shl)) %((int)((9) * (sizeof (unsigned long int)) - shl))))) + (0x26C2C) +((long)((((int)((-9) * (sizeof (unsigned long int)) - shl + (42) *((short)((((int)(shr)) |((int)(shr)))))-((short)((((int)((-9) * (sizeof (unsigned long int)) - shl)) %((int)((-9) * (sizeof (unsigned long int)) - shl))))))) &((int)(shr)))))+((long)((((int)((72) * (sizeof (unsigned long int)) - shl + (-43) *((short)((((int)(shr)) |((int)(shr)))))-((short)((((int)((8) * (sizeof (unsigned long int)) - shl)) %((int)((9) * (sizeof (unsigned long int)) - shl))))))) |((int)((-9) * (sizeof (unsigned long int)) - shl + (-43) *((short)((((int)(shr)) |((int)(shr)))))-((short)((((int)((8) * (sizeof (unsigned long int)) - shl)) %((int)((-9) * (sizeof (unsigned long int)) - shl))))))))))*((long)((((int)((-9) * (sizeof (unsigned long int)) - shl + (0x05) *((short)((((int)(shr)) |((int)(shr)))))-((short)((((int)((12) * (sizeof (unsigned long int)) - shl)) %((int)((8) * (sizeof (unsigned long int)) - shl))))))) <<((int)((0x45) * (sizeof (unsigned long int)) - shl + (0xBF3A) *((short)((((int)(shr)) |((int)(shr)))))-((short)((((int)((0x5826) * (sizeof (unsigned long int)) - shl)) %((int)((-9) * (sizeof (unsigned long int)) - shl))))))))));
shr = (9) * (sizeof (unsigned long int)) - shl + (58) *((short)((((int)(shr)) |((int)(shr)))))-((short)((((int)((72) * (sizeof (unsigned long int)) - shl)) %((int)((-9) * (sizeof (unsigned long int)) - shl))))) + (-43) +((long)((((int)((8) * (sizeof (unsigned long int)) - shl + (42) *((short)((((int)(shr)) |((int)(shr)))))-((short)((((int)((-9) * (sizeof (unsigned long int)) - shl)) %((int)((0x6165) * (sizeof (unsigned long int)) - shl))))))) &((int)(shr)))))+((long)((((int)((0xFB4C0) * (sizeof (unsigned long int)) - shl + (42) *((short)((((int)(shr)) |((int)(shr)))))-((short)((((int)((0x6A57) * (sizeof (unsigned long int)) - shl)) %((int)((0) * (sizeof (unsigned long int)) - shl))))))) |((int)((8) * (sizeof (unsigned long int)) - shl + (42) *((short)((((int)(shr)) |((int)(shr)))))-((short)((((int)((-9) * (sizeof (unsigned long int)) - shl)) %((int)((0x3) * (sizeof (unsigned long int)) - shl))))))))))*((long)((((int)((72) * (sizeof (unsigned long int)) - shl + (0x7035F) *((short)((((int)(shr)) |((int)(shr)))))-((short)((((int)((0x315E9) * (sizeof (unsigned long int)) - shl)) %((int)((72) * (sizeof (unsigned long int)) - shl))))))) <<((int)((8) * (sizeof (unsigned long int)) - shl + (0x6017D) *((short)((((int)(shr)) |((int)(shr)))))-((short)((((int)((8) * (sizeof (unsigned long int)) - shl)) %((int)((9) * (sizeof (unsigned long int)) - shl))))))))));
;
;
;
;
  ;
  switch (len % (0x8B9F))
    {
    default:
    case (66):
      ;
      


a2 = ((unsigned long int *) srcp1)[(3)] + (0x541EB3) +((int)((((int)(((unsigned long int *) srcp1)[(3)])) %((int)(((unsigned long int *) srcp1)[(0)])))))*((short)((((double)(a2)) -((double)(a2)))))+((short)((((double)(a2)) -((double)(a2)))))+((short)((((int)(a2)) |((int)(((unsigned long int *) srcp1)[(5)]))))) + (0x4AC) *((long)((((int)(((unsigned long int *) srcp1)[(-2)] + (42) +((int)((((int)(((unsigned long int *) srcp1)[(0xC89)])) %((int)(((unsigned long int *) srcp1)[(0xA953E)])))))*((short)((((double)(a2)) -((double)(a2)))))+((short)((((double)(a2)) -((double)(a2))))))) <<((int)((106))))))-((short)((((int)((42))) %((int)(((short)((((int)(a2)) |((int)(((unsigned long int *) srcp1)[(0x7)]))))))))))*((short)((((int)(((short)((((int)(a2)) |((int)(((unsigned long int *) srcp1)[(0x15)]))))))) &((int)(((unsigned long int *) srcp1)[(0)] + (42) +((int)((((int)(((unsigned long int *) srcp1)[(-2)])) %((int)(((unsigned long int *) srcp1)[(-2)])))))*((short)((((double)(a2)) -((double)(a2)))))+((short)((((double)(a2)) -((double)(a2)))))+((short)((((int)(a2)) |((int)(((unsigned long int *) srcp1)[(1)]))))))))))+((long)((((int)((170))) |((int)(((unsigned long int *) srcp1)[(1)])))));
a2 = ((unsigned long int *) srcp1)[(0xA)] + (0xA19) +((int)((((int)(((unsigned long int *) srcp1)[(-2)])) %((int)(((unsigned long int *) srcp1)[(65)])))))*((short)((((double)(a2)) -((double)(a2)))))+((short)((((double)(a2)) -((double)(a2)))))+((short)((((int)(a2)) |((int)(((unsigned long int *) srcp1)[(1)]))))) + (0x1E) *((long)((((int)(((unsigned long int *) srcp1)[(-2)] + (43) +((int)((((int)(((unsigned long int *) srcp1)[(-2)])) %((int)(((unsigned long int *) srcp1)[(-2)])))))*((short)((((double)(a2)) -((double)(a2)))))+((short)((((double)(a2)) -((double)(a2))))))) <<((int)((0xF411))))))-((short)((((int)((-43))) %((int)(((short)((((int)(a2)) |((int)(((unsigned long int *) srcp1)[(-2)]))))))))))*((short)((((int)(((short)((((int)(a2)) |((int)(((unsigned long int *) srcp1)[(0xB950)]))))))) &((int)(((unsigned long int *) srcp1)[(33)] + (-43) +((int)((((int)(((unsigned long int *) srcp1)[(1)])) %((int)(((unsigned long int *) srcp1)[(0x5)])))))*((short)((((double)(a2)) -((double)(a2)))))+((short)((((double)(a2)) -((double)(a2)))))+((short)((((int)(a2)) |((int)(((unsigned long int *) srcp1)[(-2)]))))))))))+((long)((((int)((46))) |((int)(((unsigned long int *) srcp1)[(1)])))));
;

a2 = ((unsigned long int *) srcp1)[(129)] + (170) +((int)((((int)(((unsigned long int *) srcp1)[(0x29)])) %((int)(((unsigned long int *) srcp1)[(-2)])))))*((short)((((double)(a2)) -((double)(a2)))))+((short)((((double)(a2)) -((double)(a2)))))+((short)((((int)(a2)) |((int)(((unsigned long int *) srcp1)[(0)]))))) + (0x463) *((long)((((int)(((unsigned long int *) srcp1)[(1)] + (170) +((int)((((int)(((unsigned long int *) srcp1)[(1)])) %((int)(((unsigned long int *) srcp1)[(-2)])))))*((short)((((double)(a2)) -((double)(a2)))))+((short)((((double)(a2)) -((double)(a2))))))) <<((int)((42))))))-((short)((((int)((42))) %((int)(((short)((((int)(a2)) |((int)(((unsigned long int *) srcp1)[(1)]))))))))))*((short)((((int)(((short)((((int)(a2)) |((int)(((unsigned long int *) srcp1)[(33)]))))))) &((int)(((unsigned long int *) srcp1)[(-2)] + (-43) +((int)((((int)(((unsigned long int *) srcp1)[(-2)])) %((int)(((unsigned long int *) srcp1)[(0xE)])))))*((short)((((double)(a2)) -((double)(a2)))))+((short)((((double)(a2)) -((double)(a2)))))+((short)((((int)(a2)) |((int)(((unsigned long int *) srcp1)[(17)]))))))))))+((long)((((int)((42))) |((int)(((unsigned long int *) srcp1)[(1)])))));
a2 = ((unsigned long int *) srcp1)[(1)] + (-43) +((int)((((int)(((unsigned long int *) srcp1)[(1)])) %((int)(((unsigned long int *) srcp1)[(0xA)])))))*((short)((((double)(a2)) -((double)(a2)))))+((short)((((double)(a2)) -((double)(a2)))))+((short)((((int)(a2)) |((int)(((unsigned long int *) srcp1)[(-2)]))))) + (42) *((long)((((int)(((unsigned long int *) srcp1)[(1)] + (0x46B5) +((int)((((int)(((unsigned long int *) srcp1)[(9)])) %((int)(((unsigned long int *) srcp1)[(1)])))))*((short)((((double)(a2)) -((double)(a2)))))+((short)((((double)(a2)) -((double)(a2))))))) <<((int)((-43))))))-((short)((((int)((-43))) %((int)(((short)((((int)(a2)) |((int)(((unsigned long int *) srcp1)[(-2)]))))))))))*((short)((((int)(((short)((((int)(a2)) |((int)(((unsigned long int *) srcp1)[(129)]))))))) &((int)(((unsigned long int *) srcp1)[(33)] + (-43) +((int)((((int)(((unsigned long int *) srcp1)[(0x7)])) %((int)(((unsigned long int *) srcp1)[(-2)])))))*((short)((((double)(a2)) -((double)(a2)))))+((short)((((double)(a2)) -((double)(a2)))))+((short)((((int)(a2)) |((int)(((unsigned long int *) srcp1)[(1)]))))))))))+((long)((((int)((-43))) |((int)(((unsigned long int *) srcp1)[(-2)])))));
;
;


a2 = ((unsigned long int *) srcp1)[(1)] + (-43) +((int)((((int)(((unsigned long int *) srcp1)[(1)])) %((int)(((unsigned long int *) srcp1)[(0x35)])))))*((short)((((double)(a2)) -((double)(a2)))))+((short)((((double)(a2)) -((double)(a2)))))+((short)((((int)(a2)) |((int)(((unsigned long int *) srcp1)[(5)]))))) + (106) +((short)((((int)(((unsigned long int *) srcp1)[(-2)] + (42) +((int)((((int)(((unsigned long int *) srcp1)[(1)])) %((int)(((unsigned long int *) srcp1)[(-2)])))))*((short)((((double)(a2)) -((double)(a2))))))) <<((int)(((short)((((double)(a2)) -((double)(a2))))))))))*((long)((((int)(((unsigned long int *) srcp1)[(5)] + (42) +((int)((((int)(((unsigned long int *) srcp1)[(-2)])) %((int)(((unsigned long int *) srcp1)[(1)])))))*((short)((((double)(a2)) -((double)(a2)))))+((short)((((double)(a2)) -((double)(a2)))))+((short)((((int)(a2)) |((int)(((unsigned long int *) srcp1)[(-2)]))))))) <<((int)(((short)((((int)(a2)) |((int)(((unsigned long int *) srcp1)[(129)]))))))))))-((short)((((int)((42))) %((int)(((unsigned long int *) srcp1)[(-2)] + (42) +((int)((((int)(((unsigned long int *) srcp1)[(-2)])) %((int)(((unsigned long int *) srcp1)[(-2)])))))*((short)((((double)(a2)) -((double)(a2)))))+((short)((((double)(a2)) -((double)(a2))))))))))+((short)((((int)(((unsigned long int *) srcp1)[(0x82)] + (0xF587D))) ^((int)(a2)))))-((int)((((int)(((short)((((double)(a2)) -((double)(a2))))))) >>((int)(((unsigned long int *) srcp1)[(1)])))));
a2 = ((unsigned long int *) srcp1)[(-2)] + (42) +((int)((((int)(((unsigned long int *) srcp1)[(129)])) %((int)(((unsigned long int *) srcp1)[(1)])))))*((short)((((double)(a2)) -((double)(a2)))))+((short)((((double)(a2)) -((double)(a2)))))+((short)((((int)(a2)) |((int)(((unsigned long int *) srcp1)[(0xE48CA)]))))) + (0x422) +((short)((((int)(((unsigned long int *) srcp1)[(0x82)] + (40) +((int)((((int)(((unsigned long int *) srcp1)[(-2)])) %((int)(((unsigned long int *) srcp1)[(129)])))))*((short)((((double)(a2)) -((double)(a2))))))) <<((int)(((short)((((double)(a2)) -((double)(a2))))))))))*((long)((((int)(((unsigned long int *) srcp1)[(0)] + (0x1E85) +((int)((((int)(((unsigned long int *) srcp1)[(0xE5)])) %((int)(((unsigned long int *) srcp1)[(1)])))))*((short)((((double)(a2)) -((double)(a2)))))+((short)((((double)(a2)) -((double)(a2)))))+((short)((((int)(a2)) |((int)(((unsigned long int *) srcp1)[(1)]))))))) <<((int)(((short)((((int)(a2)) |((int)(((unsigned long int *) srcp1)[(-2)]))))))))))-((short)((((int)((42))) %((int)(((unsigned long int *) srcp1)[(-2)] + (48) +((int)((((int)(((unsigned long int *) srcp1)[(0x457)])) %((int)(((unsigned long int *) srcp1)[(3)])))))*((short)((((double)(a2)) -((double)(a2)))))+((short)((((double)(a2)) -((double)(a2))))))))))+((short)((((int)(((unsigned long int *) srcp1)[(1)] + (42))) ^((int)(a2)))))-((int)((((int)(((short)((((double)(a2)) -((double)(a2))))))) >>((int)(((unsigned long int *) srcp1)[(-2)])))));
;
;
;
;
      


b2 = ((unsigned long int *) srcp2)[(0)] + (58) *((long)((((double)(b2)) +((double)(b2)))))*((int)((((int)(((unsigned long int *) srcp2)[(144115188075855872)])) >>((int)(((unsigned long int *) srcp2)[(16)])))))*((long)((((int)(((unsigned long int *) srcp2)[(0)])) ^((int)(b2))))) + (46) +((int)((((int)((-43) *((long)((((double)(b2)) +((double)(b2)))))*((int)((((int)(((unsigned long int *) srcp2)[(0)])) >>((int)(((unsigned long int *) srcp2)[(0)])))))*((long)((((int)(((unsigned long int *) srcp2)[(0)])) ^((int)(b2))))))) %((int)(((unsigned long int *) srcp2)[(-1)])))))-((short)((((int)((-43) *((long)((((double)(b2)) +((double)(b2)))))*((int)((((int)(((unsigned long int *) srcp2)[(4398046511104)])) >>((int)(((unsigned long int *) srcp2)[(-1)])))))*((long)((((int)(((unsigned long int *) srcp2)[(0)])) ^((int)(b2))))))) >>((int)(((unsigned long int *) srcp2)[(-1)] + (0xCF914) *((long)((((double)(b2)) +((double)(b2)))))*((int)((((int)(((unsigned long int *) srcp2)[(-1)])) >>((int)(((unsigned long int *) srcp2)[(0x96)])))))*((long)((((int)(((unsigned long int *) srcp2)[(2)])) ^((int)(b2))))))))))*((long)((((int)((-43) *((long)((((double)(b2)) +((double)(b2)))))*((int)((((int)(((unsigned long int *) srcp2)[(0)])) >>((int)(((unsigned long int *) srcp2)[(0)])))))*((long)((((int)(((unsigned long int *) srcp2)[(8)])) ^((int)(b2))))))) <<((int)((0x789) *((long)((((double)(b2)) +((double)(b2)))))*((int)((((int)(((unsigned long int *) srcp2)[(0)])) >>((int)(((unsigned long int *) srcp2)[(32)])))))*((long)((((int)(((unsigned long int *) srcp2)[(256)])) ^((int)(b2))))))))));
b2 = ((unsigned long int *) srcp2)[(0xB2F54)] + (-43) *((long)((((double)(b2)) +((double)(b2)))))*((int)((((int)(((unsigned long int *) srcp2)[(0xC)])) >>((int)(((unsigned long int *) srcp2)[(1024)])))))*((long)((((int)(((unsigned long int *) srcp2)[(128)])) ^((int)(b2))))) + (43) +((int)((((int)((0xBB5E12) *((long)((((double)(b2)) +((double)(b2)))))*((int)((((int)(((unsigned long int *) srcp2)[(0)])) >>((int)(((unsigned long int *) srcp2)[(1024)])))))*((long)((((int)(((unsigned long int *) srcp2)[(0)])) ^((int)(b2))))))) %((int)(((unsigned long int *) srcp2)[(0)])))))-((short)((((int)((42) *((long)((((double)(b2)) +((double)(b2)))))*((int)((((int)(((unsigned long int *) srcp2)[(0)])) >>((int)(((unsigned long int *) srcp2)[(-1)])))))*((long)((((int)(((unsigned long int *) srcp2)[(0)])) ^((int)(b2))))))) >>((int)(((unsigned long int *) srcp2)[(0)] + (42) *((long)((((double)(b2)) +((double)(b2)))))*((int)((((int)(((unsigned long int *) srcp2)[(0x0823)])) >>((int)(((unsigned long int *) srcp2)[(16)])))))*((long)((((int)(((unsigned long int *) srcp2)[(128)])) ^((int)(b2))))))))))*((long)((((int)((-43) *((long)((((double)(b2)) +((double)(b2)))))*((int)((((int)(((unsigned long int *) srcp2)[(-1)])) >>((int)(((unsigned long int *) srcp2)[(0)])))))*((long)((((int)(((unsigned long int *) srcp2)[(-1)])) ^((int)(b2))))))) <<((int)((42) *((long)((((double)(b2)) +((double)(b2)))))*((int)((((int)(((unsigned long int *) srcp2)[(524288)])) >>((int)(((unsigned long int *) srcp2)[(0)])))))*((long)((((int)(((unsigned long int *) srcp2)[(0)])) ^((int)(b2))))))))));
;
;
;


b2 = ((unsigned long int *) srcp2)[(0)] + (42) *((long)((((double)(b2)) +((double)(b2)))))*((int)((((int)(((unsigned long int *) srcp2)[(16384)])) >>((int)(((unsigned long int *) srcp2)[(0xD)])))))*((long)((((int)(((unsigned long int *) srcp2)[(0)])) ^((int)(b2))))) + (0xA2) -((long)((((int)(((unsigned long int *) srcp2)[(0x5)])) |((int)(b2)))))+((short)((((int)((0xD4B) *((long)((((double)(b2)) +((double)(b2)))))*((int)((((int)(((unsigned long int *) srcp2)[(2)])) >>((int)(((unsigned long int *) srcp2)[(-1)])))))*((long)((((int)(((unsigned long int *) srcp2)[(-1)])) ^((int)(b2))))))) ^((int)(b2)))))*((int)((((int)(((unsigned long int *) srcp2)[(0)] + (-43) *((long)((((double)(b2)) +((double)(b2)))))*((int)((((int)(((unsigned long int *) srcp2)[(0xC9AA2)])) >>((int)(((unsigned long int *) srcp2)[(2147483648)])))))*((long)((((int)(((unsigned long int *) srcp2)[(4611686018427387904)])) ^((int)(b2))))))) ^((int)(b2)))));
b2 = ((unsigned long int *) srcp2)[(0x970)] + (-43) *((long)((((double)(b2)) +((double)(b2)))))*((int)((((int)(((unsigned long int *) srcp2)[(0xE)])) >>((int)(((unsigned long int *) srcp2)[(128)])))))*((long)((((int)(((unsigned long int *) srcp2)[(524288)])) ^((int)(b2))))) + (62) -((long)((((int)(((unsigned long int *) srcp2)[(-1)])) |((int)(b2)))))+((short)((((int)((10) *((long)((((double)(b2)) +((double)(b2)))))*((int)((((int)(((unsigned long int *) srcp2)[(16777216)])) >>((int)(((unsigned long int *) srcp2)[(0xF)])))))*((long)((((int)(((unsigned long int *) srcp2)[(-1)])) ^((int)(b2))))))) ^((int)(b2)))))*((int)((((int)(((unsigned long int *) srcp2)[(0x6)] + (10) *((long)((((double)(b2)) +((double)(b2)))))*((int)((((int)(((unsigned long int *) srcp2)[(0x7D)])) >>((int)(((unsigned long int *) srcp2)[(0)])))))*((long)((((int)(((unsigned long int *) srcp2)[(0)])) ^((int)(b2))))))) ^((int)(b2)))));
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
      goto do1;
    case (0xB):
      ;
      


a1 = ((unsigned long int *) srcp1)[(-2)] + (41) -((long)((((int)(((unsigned long int *) srcp1)[(1)])) >>((int)(((unsigned long int *) srcp1)[(1)])))))-((long)((((int)(a1)) <<((int)(((unsigned long int *) srcp1)[(1)])))))+((short)((((int)(((unsigned long int *) srcp1)[(1)])) |((int)(((unsigned long int *) srcp1)[(-2)])))))*((long)((((int)(a1)) |((int)(a1)))))*((long)((((int)(((unsigned long int *) srcp1)[(0x474)])) ^((int)(((unsigned long int *) srcp1)[(0x6)]))))) + (0x834C5) -((short)((((int)(((short)((((int)(((unsigned long int *) srcp1)[(8)])) |((int)(((unsigned long int *) srcp1)[(1)])))))*((long)((((int)(a1)) |((int)(a1)))))*((long)((((int)(((unsigned long int *) srcp1)[(0x50EE)])) ^((int)(((unsigned long int *) srcp1)[(-2)]))))))) >>((int)(((unsigned long int *) srcp1)[(-2)] + (42) -((long)((((int)(((unsigned long int *) srcp1)[(-2)])) >>((int)(((unsigned long int *) srcp1)[(-2)])))))-((long)((((int)(a1)) <<((int)(((unsigned long int *) srcp1)[(1)])))))+((short)((((int)(((unsigned long int *) srcp1)[(0xE)])) |((int)(((unsigned long int *) srcp1)[(3)])))))*((long)((((int)(a1)) |((int)(a1)))))*((long)((((int)(((unsigned long int *) srcp1)[(0x1)])) ^((int)(((unsigned long int *) srcp1)[(9)]))))))))));
a1 = ((unsigned long int *) srcp1)[(0x34)] + (0x7E) -((long)((((int)(((unsigned long int *) srcp1)[(-2)])) >>((int)(((unsigned long int *) srcp1)[(0x7638)])))))-((long)((((int)(a1)) <<((int)(((unsigned long int *) srcp1)[(-2)])))))+((short)((((int)(((unsigned long int *) srcp1)[(0x64EE)])) |((int)(((unsigned long int *) srcp1)[(1)])))))*((long)((((int)(a1)) |((int)(a1)))))*((long)((((int)(((unsigned long int *) srcp1)[(1)])) ^((int)(((unsigned long int *) srcp1)[(-2)]))))) + (42) -((short)((((int)(((short)((((int)(((unsigned long int *) srcp1)[(1)])) |((int)(((unsigned long int *) srcp1)[(1)])))))*((long)((((int)(a1)) |((int)(a1)))))*((long)((((int)(((unsigned long int *) srcp1)[(1)])) ^((int)(((unsigned long int *) srcp1)[(0x2A4)]))))))) >>((int)(((unsigned long int *) srcp1)[(1)] + (170) -((long)((((int)(((unsigned long int *) srcp1)[(0x6)])) >>((int)(((unsigned long int *) srcp1)[(9)])))))-((long)((((int)(a1)) <<((int)(((unsigned long int *) srcp1)[(-2)])))))+((short)((((int)(((unsigned long int *) srcp1)[(1)])) |((int)(((unsigned long int *) srcp1)[(9)])))))*((long)((((int)(a1)) |((int)(a1)))))*((long)((((int)(((unsigned long int *) srcp1)[(1)])) ^((int)(((unsigned long int *) srcp1)[(5)]))))))))));
;

a1 = ((unsigned long int *) srcp1)[(-2)] + (46) -((long)((((int)(((unsigned long int *) srcp1)[(0x6BA)])) >>((int)(((unsigned long int *) srcp1)[(1)])))))-((long)((((int)(a1)) <<((int)(((unsigned long int *) srcp1)[(0x6CE9)])))))+((short)((((int)(((unsigned long int *) srcp1)[(-2)])) |((int)(((unsigned long int *) srcp1)[(3)])))))*((long)((((int)(a1)) |((int)(a1)))))*((long)((((int)(((unsigned long int *) srcp1)[(-2)])) ^((int)(((unsigned long int *) srcp1)[(-2)]))))) + (0xCA) -((short)((((int)(((short)((((int)(((unsigned long int *) srcp1)[(17)])) |((int)(((unsigned long int *) srcp1)[(1)])))))*((long)((((int)(a1)) |((int)(a1)))))*((long)((((int)(((unsigned long int *) srcp1)[(-2)])) ^((int)(((unsigned long int *) srcp1)[(1)]))))))) >>((int)(((unsigned long int *) srcp1)[(129)] + (0x2B97) -((long)((((int)(((unsigned long int *) srcp1)[(1)])) >>((int)(((unsigned long int *) srcp1)[(0xA)])))))-((long)((((int)(a1)) <<((int)(((unsigned long int *) srcp1)[(-2)])))))+((short)((((int)(((unsigned long int *) srcp1)[(-2)])) |((int)(((unsigned long int *) srcp1)[(0x31)])))))*((long)((((int)(a1)) |((int)(a1)))))*((long)((((int)(((unsigned long int *) srcp1)[(1)])) ^((int)(((unsigned long int *) srcp1)[(-2)]))))))))));
a1 = ((unsigned long int *) srcp1)[(-2)] + (46) -((long)((((int)(((unsigned long int *) srcp1)[(129)])) >>((int)(((unsigned long int *) srcp1)[(0x083)])))))-((long)((((int)(a1)) <<((int)(((unsigned long int *) srcp1)[(0x5)])))))+((short)((((int)(((unsigned long int *) srcp1)[(1)])) |((int)(((unsigned long int *) srcp1)[(-2)])))))*((long)((((int)(a1)) |((int)(a1)))))*((long)((((int)(((unsigned long int *) srcp1)[(33)])) ^((int)(((unsigned long int *) srcp1)[(0x2B0)]))))) + (-43) -((short)((((int)(((short)((((int)(((unsigned long int *) srcp1)[(0x01939)])) |((int)(((unsigned long int *) srcp1)[(0xC80)])))))*((long)((((int)(a1)) |((int)(a1)))))*((long)((((int)(((unsigned long int *) srcp1)[(0)])) ^((int)(((unsigned long int *) srcp1)[(0x11)]))))))) >>((int)(((unsigned long int *) srcp1)[(1)] + (42) -((long)((((int)(((unsigned long int *) srcp1)[(65)])) >>((int)(((unsigned long int *) srcp1)[(1)])))))-((long)((((int)(a1)) <<((int)(((unsigned long int *) srcp1)[(17)])))))+((short)((((int)(((unsigned long int *) srcp1)[(-2)])) |((int)(((unsigned long int *) srcp1)[(0xB1)])))))*((long)((((int)(a1)) |((int)(a1)))))*((long)((((int)(((unsigned long int *) srcp1)[(-2)])) ^((int)(((unsigned long int *) srcp1)[(-2)]))))))))));
;
;
;
;
      ;
      ;
      ;
      goto do2;
    case (0):
      if (0)
    { return (2); }
      
;
;
;
      ;
      ;
      ;
      goto do3;
    case (0xEF22):
      ;
      

;

a3 = ((unsigned long int *) srcp1)[(1)] + (42) +((int)((((int)(((unsigned long int *) srcp1)[(1)])) %((int)(a3)))))+((int)((((int)(((unsigned long int *) srcp1)[(0x8F7E1)])) <<((int)(((unsigned long int *) srcp1)[(-2)]))))) + (-43) +((int)((((int)(((unsigned long int *) srcp1)[(33)] + (-43))) >>((int)(((unsigned long int *) srcp1)[(-2)] + (0x4E) +((int)((((int)(((unsigned long int *) srcp1)[(-2)])) %((int)(a3))))))))))+((int)((((int)(((int)((((int)(((unsigned long int *) srcp1)[(0x7C3D7)])) %((int)(a3))))))) <<((int)(((int)((((int)(((unsigned long int *) srcp1)[(0x679)])) %((int)(a3))))))))))*((long)((((int)(((unsigned long int *) srcp1)[(9)] + (-43) +((int)((((int)(((unsigned long int *) srcp1)[(-2)])) %((int)(a3)))))+((int)((((int)(((unsigned long int *) srcp1)[(65)])) <<((int)(((unsigned long int *) srcp1)[(5)]))))))) <<((int)(((int)((((int)(((unsigned long int *) srcp1)[(1)])) <<((int)(((unsigned long int *) srcp1)[(-2)]))))))))))*((short)((((int)(a3)) |((int)(((unsigned long int *) srcp1)[(1)])))))*((int)((((int)(((int)((((int)(((unsigned long int *) srcp1)[(0x8DE76)])) %((int)(a3))))))) ^((int)(((unsigned long int *) srcp1)[(17)] + (-43) +((int)((((int)(((unsigned long int *) srcp1)[(65)])) %((int)(a3)))))+((int)((((int)(((unsigned long int *) srcp1)[(0x8E7)])) <<((int)(((unsigned long int *) srcp1)[(129)]))))))))));
a3 = ((unsigned long int *) srcp1)[(1)] + (34) +((int)((((int)(((unsigned long int *) srcp1)[(6)])) %((int)(a3)))))+((int)((((int)(((unsigned long int *) srcp1)[(0x23E)])) <<((int)(((unsigned long int *) srcp1)[(129)]))))) + (0x6F9ABB) +((int)((((int)(((unsigned long int *) srcp1)[(1)] + (22))) >>((int)(((unsigned long int *) srcp1)[(0x5)] + (42) +((int)((((int)(((unsigned long int *) srcp1)[(0x21A)])) %((int)(a3))))))))))+((int)((((int)(((int)((((int)(((unsigned long int *) srcp1)[(1)])) %((int)(a3))))))) <<((int)(((int)((((int)(((unsigned long int *) srcp1)[(-2)])) %((int)(a3))))))))))*((long)((((int)(((unsigned long int *) srcp1)[(-2)] + (10) +((int)((((int)(((unsigned long int *) srcp1)[(0x38D11)])) %((int)(a3)))))+((int)((((int)(((unsigned long int *) srcp1)[(-2)])) <<((int)(((unsigned long int *) srcp1)[(-2)]))))))) <<((int)(((int)((((int)(((unsigned long int *) srcp1)[(1)])) <<((int)(((unsigned long int *) srcp1)[(17)]))))))))))*((short)((((int)(a3)) |((int)(((unsigned long int *) srcp1)[(0x46CE)])))))*((int)((((int)(((int)((((int)(((unsigned long int *) srcp1)[(-2)])) %((int)(a3))))))) ^((int)(((unsigned long int *) srcp1)[(-2)] + (34) +((int)((((int)(((unsigned long int *) srcp1)[(0xD54)])) %((int)(a3)))))+((int)((((int)(((unsigned long int *) srcp1)[(-2)])) <<((int)(((unsigned long int *) srcp1)[(-2)]))))))))));
;
;


a3 = ((unsigned long int *) srcp1)[(0)] + (72) +((int)((((int)(((unsigned long int *) srcp1)[(-2)])) %((int)(a3)))))+((int)((((int)(((unsigned long int *) srcp1)[(0xC)])) <<((int)(((unsigned long int *) srcp1)[(0)]))))) + (-43) -((short)((((int)(a3)) <<((int)((58))))))+((long)((((int)(((unsigned long int *) srcp1)[(1)])) <<((int)(((unsigned long int *) srcp1)[(-2)] + (0x488A))))))-((short)((((int)(((int)((((int)(((unsigned long int *) srcp1)[(0xB)])) <<((int)(((unsigned long int *) srcp1)[(0)]))))))) |((int)(((int)((((int)(((unsigned long int *) srcp1)[(1)])) <<((int)(((unsigned long int *) srcp1)[(0x6B21)]))))))))));
a3 = ((unsigned long int *) srcp1)[(33)] + (43) +((int)((((int)(((unsigned long int *) srcp1)[(65)])) %((int)(a3)))))+((int)((((int)(((unsigned long int *) srcp1)[(0xC3)])) <<((int)(((unsigned long int *) srcp1)[(129)]))))) + (-43) -((short)((((int)(a3)) <<((int)((46))))))+((long)((((int)(((unsigned long int *) srcp1)[(-2)])) <<((int)(((unsigned long int *) srcp1)[(33)] + (-43))))))-((short)((((int)(((int)((((int)(((unsigned long int *) srcp1)[(1)])) <<((int)(((unsigned long int *) srcp1)[(1)]))))))) |((int)(((int)((((int)(((unsigned long int *) srcp1)[(0xE)])) <<((int)(((unsigned long int *) srcp1)[(1)]))))))))));
;

a3 = ((unsigned long int *) srcp1)[(0x19)] + (0xD93) +((int)((((int)(((unsigned long int *) srcp1)[(1)])) %((int)(a3)))))+((int)((((int)(((unsigned long int *) srcp1)[(0x063D4)])) <<((int)(((unsigned long int *) srcp1)[(0x30A2)]))))) + (-43) -((short)((((int)(a3)) <<((int)((34))))))+((long)((((int)(((unsigned long int *) srcp1)[(1)])) <<((int)(((unsigned long int *) srcp1)[(-2)] + (-43))))))-((short)((((int)(((int)((((int)(((unsigned long int *) srcp1)[(0xDE)])) <<((int)(((unsigned long int *) srcp1)[(0x05)]))))))) |((int)(((int)((((int)(((unsigned long int *) srcp1)[(1)])) <<((int)(((unsigned long int *) srcp1)[(1)]))))))))));
a3 = ((unsigned long int *) srcp1)[(-2)] + (0xA8C39) +((int)((((int)(((unsigned long int *) srcp1)[(-2)])) %((int)(a3)))))+((int)((((int)(((unsigned long int *) srcp1)[(17)])) <<((int)(((unsigned long int *) srcp1)[(0xA)]))))) + (42) -((short)((((int)(a3)) <<((int)((-43))))))+((long)((((int)(((unsigned long int *) srcp1)[(0x038)])) <<((int)(((unsigned long int *) srcp1)[(-2)] + (58))))))-((short)((((int)(((int)((((int)(((unsigned long int *) srcp1)[(5)])) <<((int)(((unsigned long int *) srcp1)[(-2)]))))))) |((int)(((int)((((int)(((unsigned long int *) srcp1)[(1)])) <<((int)(((unsigned long int *) srcp1)[(-2)]))))))))));
;
;
;
      ;
      
;
;
;
      


srcp2 += (1) * (sizeof (unsigned long int)) + (0x90B68) +((int)((((int)(srcp2)) <<((int)((1) * (sizeof (unsigned long int))))))) + (42) *((short)((((double)(srcp2)) -((double)((sizeof (unsigned long int)))))))-((short)((((int)((0x7B050))) >>((int)((-43))))))*((short)((((double)((-2))) +((double)((42))))))+((long)((((int)(((int)((((int)(srcp2)) <<((int)((1) * (sizeof (unsigned long int))))))))) &((int)((0x0F00))))));
srcp2 += (0x5E8) * (sizeof (unsigned long int)) + (40) +((int)((((int)(srcp2)) <<((int)((0x591) * (sizeof (unsigned long int))))))) + (170) *((short)((((double)(srcp2)) -((double)((sizeof (unsigned long int)))))))-((short)((((int)((46))) >>((int)((0x123))))))*((short)((((double)((1))) +((double)((0x5916D))))))+((long)((((int)(((int)((((int)(srcp2)) <<((int)((0xB348) * (sizeof (unsigned long int))))))))) &((int)((-2))))));
;
;
;

;
;
;
;
      ;
      if ((0))
        goto do0;
    }
  do
    {
      ;
      
;

;
;
;
;
      
;

;

x = (((a2) >> (shl)) | ((a3) << (shr))) + (-43) +((short)((((double)((((a2) >> (shl)) | ((a3) << (shr))))) -((double)((((a2) >> (shl)) | ((a3) << (shr))))))))-((long)((((double)((((a2) >> (shl)) | ((a3) << (shr))))) -((double)((((a2) >> (shl)) | ((a3) << (shr)))))))) + (45) *((int)((((int)((((a2) >> (shl)) | ((a3) << (shr))) + (-43))) %((int)(x)))))-((long)((((int)(x)) ^((int)((((a2) >> (shl)) | ((a3) << (shr))))))))*((short)((((int)(((short)((((double)((((a2) >> (shl)) | ((a3) << (shr))))) -((double)((((a2) >> (shl)) | ((a3) << (shr)))))))))) |((int)((((a2) >> (shl)) | ((a3) << (shr))) + (0x9CAB4) +((short)((((double)((((a2) >> (shl)) | ((a3) << (shr))))) -((double)((((a2) >> (shl)) | ((a3) << (shr)))))))))))))-((short)((((double)(x)) +((double)((((a2) >> (shl)) | ((a3) << (shr))) + (72))))))+((short)((((double)((42))) -((double)((((a2) >> (shl)) | ((a3) << (shr))) + (42))))));
x = (((a2) >> (shl)) | ((a3) << (shr))) + (0x922) +((short)((((double)((((a2) >> (shl)) | ((a3) << (shr))))) -((double)((((a2) >> (shl)) | ((a3) << (shr))))))))-((long)((((double)((((a2) >> (shl)) | ((a3) << (shr))))) -((double)((((a2) >> (shl)) | ((a3) << (shr)))))))) + (170) *((int)((((int)((((a2) >> (shl)) | ((a3) << (shr))) + (0x3E07D1))) %((int)(x)))))-((long)((((int)(x)) ^((int)((((a2) >> (shl)) | ((a3) << (shr))))))))*((short)((((int)(((short)((((double)((((a2) >> (shl)) | ((a3) << (shr))))) -((double)((((a2) >> (shl)) | ((a3) << (shr)))))))))) |((int)((((a2) >> (shl)) | ((a3) << (shr))) + (42) +((short)((((double)((((a2) >> (shl)) | ((a3) << (shr))))) -((double)((((a2) >> (shl)) | ((a3) << (shr)))))))))))))-((short)((((double)(x)) +((double)((((a2) >> (shl)) | ((a3) << (shr))) + (46))))))+((short)((((double)((42))) -((double)((((a2) >> (shl)) | ((a3) << (shr))) + (40))))));
;
;
;
      if (((int)((int)x != b3 + (0x01BB) -((int)((((double)(b3)) *((double)(x)))))*((short)((((int)(b3)) |((int)(x)))))) + (0x59) +((int)((((int)((58))) %((int)(b3)))))-((short)((((int)(b3)) >>((int)(((int)((((double)(b3)) *((double)(x)))))*((short)((((int)(b3)) |((int)(x))))))))))*((long)((((int)((int)x)) >>((int)(((int)((((double)(b3)) *((double)(x)))))*((short)((((int)(b3)) |((int)(x))))))))))-((int)((((double)((int)x)) +((double)(b3 + (-43))))))+((long)((((int)(b3)) %((int)((58))))))+((short)((((int)(b3)) ^((int)((-43))))))+((short)((((int)(b3 + (42) -((int)((((double)(b3)) *((double)(x)))))*((short)((((int)(b3)) |((int)(x))))))) |((int)((42))))))*((short)((((int)(((int)((((double)(b3)) *((double)(x)))))*((short)((((int)(b3)) |((int)(x))))))) >>((int)(b3 + (34))))))-((short)((((int)(b3)) |((int)(((int)((((double)(b3)) *((double)(x)))))*((short)((((int)(b3)) |((int)(x))))))))))+((short)((((int)((int)x)) %((int)((42))))))))
        return mymemcmp1 ((x), (b3));
    do3:
      


a1 = ((unsigned long int *) srcp1)[(1)] + (0x3D) *((long)((((int)(a1)) |((int)(((unsigned long int *) srcp1)[(5)])))))+((short)((((int)(((unsigned long int *) srcp1)[(0xAE9)])) &((int)(a1))))) + (34) +((int)((((int)(a1)) %((int)(((unsigned long int *) srcp1)[(3)])))))*((short)((((int)((62) *((long)((((int)(a1)) |((int)(((unsigned long int *) srcp1)[(17)]))))))) ^((int)(((short)((((int)(((unsigned long int *) srcp1)[(0)])) &((int)(a1))))))))))*((int)((((int)(((short)((((int)(((unsigned long int *) srcp1)[(9)])) &((int)(a1))))))) ^((int)(((unsigned long int *) srcp1)[(-2)] + (-43) *((long)((((int)(a1)) |((int)(((unsigned long int *) srcp1)[(17)]))))))))))+((int)((((int)(((unsigned long int *) srcp1)[(1)] + (-43) *((long)((((int)(a1)) |((int)(((unsigned long int *) srcp1)[(9)]))))))) ^((int)(((unsigned long int *) srcp1)[(1)] + (0x6A93D6) *((long)((((int)(a1)) |((int)(((unsigned long int *) srcp1)[(1)])))))+((short)((((int)(((unsigned long int *) srcp1)[(0xA)])) &((int)(a1))))))))))*((short)((((int)((-43) *((long)((((int)(a1)) |((int)(((unsigned long int *) srcp1)[(-2)]))))))) >>((int)(((unsigned long int *) srcp1)[(33)] + (42) *((long)((((int)(a1)) |((int)(((unsigned long int *) srcp1)[(1)])))))+((short)((((int)(((unsigned long int *) srcp1)[(0)])) &((int)(a1))))))))));
a1 = ((unsigned long int *) srcp1)[(4)] + (22) *((long)((((int)(a1)) |((int)(((unsigned long int *) srcp1)[(-2)])))))+((short)((((int)(((unsigned long int *) srcp1)[(0x4)])) &((int)(a1))))) + (42) +((int)((((int)(a1)) %((int)(((unsigned long int *) srcp1)[(-2)])))))*((short)((((int)((58) *((long)((((int)(a1)) |((int)(((unsigned long int *) srcp1)[(129)]))))))) ^((int)(((short)((((int)(((unsigned long int *) srcp1)[(129)])) &((int)(a1))))))))))*((int)((((int)(((short)((((int)(((unsigned long int *) srcp1)[(0x290)])) &((int)(a1))))))) ^((int)(((unsigned long int *) srcp1)[(-2)] + (-43) *((long)((((int)(a1)) |((int)(((unsigned long int *) srcp1)[(-2)]))))))))))+((int)((((int)(((unsigned long int *) srcp1)[(1)] + (-43) *((long)((((int)(a1)) |((int)(((unsigned long int *) srcp1)[(0xA56D2)]))))))) ^((int)(((unsigned long int *) srcp1)[(1)] + (-43) *((long)((((int)(a1)) |((int)(((unsigned long int *) srcp1)[(1)])))))+((short)((((int)(((unsigned long int *) srcp1)[(0x8FF19)])) &((int)(a1))))))))))*((short)((((int)((0x819D5) *((long)((((int)(a1)) |((int)(((unsigned long int *) srcp1)[(0x130)]))))))) >>((int)(((unsigned long int *) srcp1)[(0)] + (58) *((long)((((int)(a1)) |((int)(((unsigned long int *) srcp1)[(1)])))))+((short)((((int)(((unsigned long int *) srcp1)[(-2)])) &((int)(a1))))))))));
;

a1 = ((unsigned long int *) srcp1)[(1)] + (42) *((long)((((int)(a1)) |((int)(((unsigned long int *) srcp1)[(65)])))))+((short)((((int)(((unsigned long int *) srcp1)[(1)])) &((int)(a1))))) + (-43) +((int)((((int)(a1)) %((int)(((unsigned long int *) srcp1)[(2)])))))*((short)((((int)((0xCA8F75) *((long)((((int)(a1)) |((int)(((unsigned long int *) srcp1)[(0x842)]))))))) ^((int)(((short)((((int)(((unsigned long int *) srcp1)[(9)])) &((int)(a1))))))))))*((int)((((int)(((short)((((int)(((unsigned long int *) srcp1)[(0x2B9)])) &((int)(a1))))))) ^((int)(((unsigned long int *) srcp1)[(0)] + (42) *((long)((((int)(a1)) |((int)(((unsigned long int *) srcp1)[(0xB2)]))))))))))+((int)((((int)(((unsigned long int *) srcp1)[(0xE465)] + (-43) *((long)((((int)(a1)) |((int)(((unsigned long int *) srcp1)[(0x0802A)]))))))) ^((int)(((unsigned long int *) srcp1)[(-2)] + (52) *((long)((((int)(a1)) |((int)(((unsigned long int *) srcp1)[(1)])))))+((short)((((int)(((unsigned long int *) srcp1)[(-2)])) &((int)(a1))))))))))*((short)((((int)((-43) *((long)((((int)(a1)) |((int)(((unsigned long int *) srcp1)[(-2)]))))))) >>((int)(((unsigned long int *) srcp1)[(1)] + (42) *((long)((((int)(a1)) |((int)(((unsigned long int *) srcp1)[(9)])))))+((short)((((int)(((unsigned long int *) srcp1)[(-2)])) &((int)(a1))))))))));
a1 = ((unsigned long int *) srcp1)[(5)] + (106) *((long)((((int)(a1)) |((int)(((unsigned long int *) srcp1)[(65)])))))+((short)((((int)(((unsigned long int *) srcp1)[(1)])) &((int)(a1))))) + (0xF1002F) +((int)((((int)(a1)) %((int)(((unsigned long int *) srcp1)[(5)])))))*((short)((((int)((0x5EEC64) *((long)((((int)(a1)) |((int)(((unsigned long int *) srcp1)[(9)]))))))) ^((int)(((short)((((int)(((unsigned long int *) srcp1)[(0xB23)])) &((int)(a1))))))))))*((int)((((int)(((short)((((int)(((unsigned long int *) srcp1)[(-2)])) &((int)(a1))))))) ^((int)(((unsigned long int *) srcp1)[(-2)] + (-43) *((long)((((int)(a1)) |((int)(((unsigned long int *) srcp1)[(0x23D)]))))))))))+((int)((((int)(((unsigned long int *) srcp1)[(0)] + (0xE00E20) *((long)((((int)(a1)) |((int)(((unsigned long int *) srcp1)[(-2)]))))))) ^((int)(((unsigned long int *) srcp1)[(0xB)] + (42) *((long)((((int)(a1)) |((int)(((unsigned long int *) srcp1)[(65)])))))+((short)((((int)(((unsigned long int *) srcp1)[(0x098AB)])) &((int)(a1))))))))))*((short)((((int)((42) *((long)((((int)(a1)) |((int)(((unsigned long int *) srcp1)[(1)]))))))) >>((int)(((unsigned long int *) srcp1)[(1)] + (42) *((long)((((int)(a1)) |((int)(((unsigned long int *) srcp1)[(129)])))))+((short)((((int)(((unsigned long int *) srcp1)[(1)])) &((int)(a1))))))))));
;
;
;
;
      
;
;
;
      ;
      if ((0))
        return mymemcmp1 ((x), (b0));
    do2:
      ;
      ;
      ;
      if ((0))
        return mymemcmp1 ((x), (b1));
    do1:
      ;
      
;
;
;
      ;
      if (0)
        return mymemcmp1 ((x), (b2));
      ;
      ;
      


len -= (5) + (106) -((short)((((int)(len)) ^((int)(len)))))-((short)((((double)(len)) *((double)((12))))))+((short)((((int)(len)) ^((int)((0xE68B)))))) + (41) +((long)((((int)((36) + (-43) -((short)((((int)(len)) ^((int)(len)))))-((short)((((double)(len)) *((double)((12))))))+((short)((((int)(len)) ^((int)((4)))))))) <<((int)((0x304) + (0x827022) -((short)((((int)(len)) ^((int)(len)))))-((short)((((double)(len)) *((double)((6))))))+((short)((((int)(len)) ^((int)((0x0)))))))))))-((int)((((int)((0x8) + (0x6D2B) -((short)((((int)(len)) ^((int)(len)))))-((short)((((double)(len)) *((double)((0x0F5F))))))+((short)((((int)(len)) ^((int)((132)))))))) ^((int)(len)))))*((short)((((int)((5) + (42) -((short)((((int)(len)) ^((int)(len)))))-((short)((((double)(len)) *((double)((12))))))+((short)((((int)(len)) ^((int)((36)))))))) ^((int)((0xCB) + (58) -((short)((((int)(len)) ^((int)(len)))))-((short)((((double)(len)) *((double)((-5))))))+((short)((((int)(len)) ^((int)((-5)))))))))))*((int)((((int)((0) + (0x87D4) -((short)((((int)(len)) ^((int)(len)))))-((short)((((double)(len)) *((double)((5))))))+((short)((((int)(len)) ^((int)((0)))))))) &((int)(len)))))+((int)((((int)(len)) &((int)((68) + (-43) -((short)((((int)(len)) ^((int)(len)))))-((short)((((double)(len)) *((double)((-5))))))+((short)((((int)(len)) ^((int)((4)))))))))));
len -= (0x4956E) + (0x05909) -((short)((((int)(len)) ^((int)(len)))))-((short)((((double)(len)) *((double)((132))))))+((short)((((int)(len)) ^((int)((0)))))) + (106) +((long)((((int)((4) + (0x1A5E44) -((short)((((int)(len)) ^((int)(len)))))-((short)((((double)(len)) *((double)((0))))))+((short)((((int)(len)) ^((int)((0xC97D8)))))))) <<((int)((4) + (-43) -((short)((((int)(len)) ^((int)(len)))))-((short)((((double)(len)) *((double)((-5))))))+((short)((((int)(len)) ^((int)((-5)))))))))))-((int)((((int)((-5) + (-43) -((short)((((int)(len)) ^((int)(len)))))-((short)((((double)(len)) *((double)((4))))))+((short)((((int)(len)) ^((int)((0x3AC)))))))) ^((int)(len)))))*((short)((((int)((5) + (0xBD) -((short)((((int)(len)) ^((int)(len)))))-((short)((((double)(len)) *((double)((4))))))+((short)((((int)(len)) ^((int)((68)))))))) ^((int)((20) + (40) -((short)((((int)(len)) ^((int)(len)))))-((short)((((double)(len)) *((double)((4))))))+((short)((((int)(len)) ^((int)((-5)))))))))))*((int)((((int)((0xB) + (34) -((short)((((int)(len)) ^((int)(len)))))-((short)((((double)(len)) *((double)((-5))))))+((short)((((int)(len)) ^((int)((4)))))))) &((int)(len)))))+((int)((((int)(len)) &((int)((4) + (0xA4EB) -((short)((((int)(len)) ^((int)(len)))))-((short)((((double)(len)) *((double)((4))))))+((short)((((int)(len)) ^((int)((0x2D7)))))))))));
;

len -= (0xD) + (0xBEF) -((short)((((int)(len)) ^((int)(len)))))-((short)((((double)(len)) *((double)((-5))))))+((short)((((int)(len)) ^((int)((36)))))) + (32) +((long)((((int)((36) + (42) -((short)((((int)(len)) ^((int)(len)))))-((short)((((double)(len)) *((double)((-5))))))+((short)((((int)(len)) ^((int)((68)))))))) <<((int)((36) + (10) -((short)((((int)(len)) ^((int)(len)))))-((short)((((double)(len)) *((double)((-5))))))+((short)((((int)(len)) ^((int)((-5)))))))))))-((int)((((int)((0x4B3) + (106) -((short)((((int)(len)) ^((int)(len)))))-((short)((((double)(len)) *((double)((0xA))))))+((short)((((int)(len)) ^((int)((0x0B65)))))))) ^((int)(len)))))*((short)((((int)((-5) + (42) -((short)((((int)(len)) ^((int)(len)))))-((short)((((double)(len)) *((double)((4))))))+((short)((((int)(len)) ^((int)((-5)))))))) ^((int)((20) + (42) -((short)((((int)(len)) ^((int)(len)))))-((short)((((double)(len)) *((double)((4))))))+((short)((((int)(len)) ^((int)((0x8FC)))))))))))*((int)((((int)((5) + (-43) -((short)((((int)(len)) ^((int)(len)))))-((short)((((double)(len)) *((double)((-5))))))+((short)((((int)(len)) ^((int)((4)))))))) &((int)(len)))))+((int)((((int)(len)) &((int)((0) + (10) -((short)((((int)(len)) ^((int)(len)))))-((short)((((double)(len)) *((double)((0xA))))))+((short)((((int)(len)) ^((int)((4)))))))))));
len -= (5) + (42) -((short)((((int)(len)) ^((int)(len)))))-((short)((((double)(len)) *((double)((0x0B))))))+((short)((((int)(len)) ^((int)((0x1C)))))) + (0x612FF) +((long)((((int)((68) + (0xFC) -((short)((((int)(len)) ^((int)(len)))))-((short)((((double)(len)) *((double)((0x6800))))))+((short)((((int)(len)) ^((int)((0xA)))))))) <<((int)((0xB) + (40) -((short)((((int)(len)) ^((int)(len)))))-((short)((((double)(len)) *((double)((-5))))))+((short)((((int)(len)) ^((int)((-5)))))))))))-((int)((((int)((5) + (-43) -((short)((((int)(len)) ^((int)(len)))))-((short)((((double)(len)) *((double)((0xB))))))+((short)((((int)(len)) ^((int)((4)))))))) ^((int)(len)))))*((short)((((int)((0xD9) + (0x5AC28) -((short)((((int)(len)) ^((int)(len)))))-((short)((((double)(len)) *((double)((-5))))))+((short)((((int)(len)) ^((int)((0)))))))) ^((int)((-5) + (0x0A2B95) -((short)((((int)(len)) ^((int)(len)))))-((short)((((double)(len)) *((double)((36))))))+((short)((((int)(len)) ^((int)((4)))))))))))*((int)((((int)((132) + (-43) -((short)((((int)(len)) ^((int)(len)))))-((short)((((double)(len)) *((double)((5))))))+((short)((((int)(len)) ^((int)((-5)))))))) &((int)(len)))))+((int)((((int)(len)) &((int)((4) + (0x4DF) -((short)((((int)(len)) ^((int)(len)))))-((short)((((double)(len)) *((double)((0x2B))))))+((short)((((int)(len)) ^((int)((-5)))))))))));
;
;
;
;
    }
  while (len != (0));
do0:
  ;
  if (0)
    return mymemcmp1 ((x), (b3));
  return (0);
}

__attribute__ ((noinline))
int mymemcmp (const void *s1, const void *s2, size_t len)
{
  unsigned long int a0;
  unsigned long int b0;
  long int srcp1 = (long int) s1;
  long int srcp2 = (long int) s2;
  if ((1073741824))
    return mymemcmp2 (srcp1, srcp2, len / (sizeof (unsigned long int)));
  else
    return mymemcmp3 (srcp1, srcp2, len / (sizeof (unsigned long int)));
}

char buf[(0x7587)];

int
main (void)
{
  char *p;
  union { long int l; char c[sizeof (long int)]; } u;

  /* The test above assumes little endian and long being the same size
     as pointer.  */
  if (0)
    { return (0x103); }
  ;
  if (((int)((int)u.c[(32)] != 0x78 || u.c[(0x2E)] != 0x56 || u.c[(0x8076)] != 0x34 || u.c[(3)] != 0x12 + (-43) -((short)((((double)(0x78)) +((double)(0x34)))))*((short)((((int)(u.c[(-4)] != 0x12)) >>((int)(u.c[(-3)])))))*((short)((((int)(u.c[(0xD1C7)] != 0x34)) |((int)(u.c[(0x6)] != 0x56)))))+((long)((((int)(u.c[(3)])) ^((int)(0x56)))))+((short)((((int)(u.c[(3)] != 0x12)) %((int)(u.c[(32)] != 0x78 || u.c[(1)] != 0x56 || u.c[(0x04350)] != 0x34)))))*((short)((((double)(0x12)) +((double)(0x56)))))+((short)((((int)(u.c[(0xFF)] != 0x78 || u.c[(65)] != 0x56)) %((int)(u.c[(-3)])))))+((long)((((int)(u.c[(-3)] != 0x34)) %((int)(0x78)))))-((long)((((int)(u.c[(1)] != 0x56)) |((int)(u.c[(-1)])))))*((short)((((int)(0x56)) |((int)(u.c[(0)])))))) + (42) -((long)((((int)(0x12 + (-43) -((short)((((double)(0x78)) +((double)(0x34)))))*((short)((((int)(u.c[(-4)] != 0x12)) >>((int)(u.c[(2)])))))*((short)((((int)(u.c[(2)] != 0x34)) |((int)(u.c[(1)] != 0x56)))))+((long)((((int)(u.c[(1)])) ^((int)(0x56)))))+((short)((((int)(u.c[(3)] != 0x12)) %((int)(u.c[(65536)] != 0x78 || u.c[(9)] != 0x56 || u.c[(-3)] != 0x34)))))*((short)((((double)(0x12)) +((double)(0x56)))))+((short)((((int)(u.c[(0x2F)] != 0x78 || u.c[(129)] != 0x56)) %((int)(u.c[(34)])))))+((long)((((int)(u.c[(-3)] != 0x34)) %((int)(0x78)))))-((long)((((int)(u.c[(65)] != 0x56)) |((int)(u.c[(64)])))))*((short)((((int)(0x56)) |((int)(u.c[(0x04E57)]))))))) <<((int)(u.c[(0xB3FC)])))))-((short)((((int)((int)u.c[(0x4)] != 0x78 || u.c[(0x2)] != 0x56 || u.c[(130)] != 0x34)) >>((int)(((long)((((int)(u.c[(129)])) ^((int)(0x56))))))))))-((short)((((int)(0x12 + (0x6CD17) -((short)((((double)(0x78)) +((double)(0x34)))))*((short)((((int)(u.c[(11)] != 0x12)) >>((int)(u.c[(2)])))))*((short)((((int)(u.c[(0)] != 0x34)) |((int)(u.c[(0xF8)] != 0x56))))))) <<((int)((int)u.c[(0)] != 0x78)))))*((long)((((int)(0x12 + (106) -((short)((((double)(0x78)) +((double)(0x34)))))*((short)((((int)(u.c[(3)] != 0x12)) >>((int)(u.c[(2)])))))*((short)((((int)(u.c[(18)] != 0x34)) |((int)(u.c[(0)] != 0x56)))))+((long)((((int)(u.c[(-2)])) ^((int)(0x56)))))+((short)((((int)(u.c[(-4)] != 0x12)) %((int)(u.c[(16384)] != 0x78 || u.c[(0x4C44)] != 0x56 || u.c[(-3)] != 0x34)))))*((short)((((double)(0x12)) +((double)(0x56)))))+((short)((((int)(u.c[(-1)] != 0x78 || u.c[(-2)] != 0x56)) %((int)(u.c[(-3)]))))))) <<((int)(((long)((((int)(u.c[(0xBAB)] != 0x56)) |((int)(u.c[(131072)])))))*((short)((((int)(0x56)) |((int)(u.c[(0)]))))))))))+((long)((((int)(((long)((((int)(u.c[(0x135EC)] != 0x34)) %((int)(0x78))))))) |((int)((int)u.c[(0x0)] != 0x78 || u.c[(-2)] != 0x56 || u.c[(2)] != 0x34)))))))
    { return (0); }

  ;
  __builtin_memcpy (p + (25),
"\x1\x37\x82\xa7\x55\x49\x9d\xbf\xf8\x44\xb6\x55\x17\x8e\xf9", (0x79E));
  __builtin_memcpy (p + (128) + (56),
"\x1\x37\x82\xa7\x55\x49\xd0\xf3\xb7\x2a\x6d\x23\x71\x49\x6a", (0xCE8AC));
  if (0)
    { __builtin_abort (); }
  return (0xBC);
}
/* ProgramSourceLLVM */
