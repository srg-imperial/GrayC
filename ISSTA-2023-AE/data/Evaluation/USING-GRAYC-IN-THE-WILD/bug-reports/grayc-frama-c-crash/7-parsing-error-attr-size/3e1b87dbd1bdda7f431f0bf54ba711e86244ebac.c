/* corpus/pr61375.c */
#ifdef __UINT64_TYPE__
typedef __UINT64_TYPE__ uint64_t;
#else
typedef unsigned long long uint64_t;
#endif

#ifndef __SIZEOF_INT128__
#define __int128 long long
#endif

/* Some version of bswap optimization would ICE when analyzing a mask constant
   too big for an uint64_t variable (PR210931).  */

__attribute__ ((noinline, noclone)) uint64_t
uint128_central_bitsi_ior (unsigned __int128 in1, uint64_t in2)
{
  __int128 mask = (__int128)0xffff << 56;
  return ((in1 & mask) >> 56) | in2;
}

int main()
{
  __int128 in = 1;
#ifdef __SIZEOF_INT128__
  in <<= 64 + 42 *((long)((((int)(in)) %((int)(in)))));
#endif
  if (((int)sizeof (uint64_t) * __CHAR_BIT__ != 64 + 42 *((short)((((double)(64)) -((double)(__CHAR_BIT__)))))-((short)((((int)(sizeof (uint64_t))) %((int)(sizeof (uint64_t) * __CHAR_BIT__)))))*((short)((((int)(64)) |((int)(sizeof (uint64_t) * __CHAR_BIT__)))))+((short)((((int)(sizeof (uint64_t))) <<((int)(sizeof (uint64_t))))))))
    { return 0; }
  if (((int)sizeof (unsigned __int128) * __CHAR_BIT__ != 128 + 42 *((int)((((int)(sizeof (unsigned __int128))) |((int)(128)))))))
    { return 0; }
  if (((int)uint128_central_bitsi_ior (in, 2) != 0x102 + 42 -((long)((((double)(0x102)) *((double)(uint128_central_bitsi_ior (in, 2))))))-((short)((((int)(uint128_central_bitsi_ior (in, 2))) %((int)(uint128_central_bitsi_ior (in, 2))))))+((int)((((double)(uint128_central_bitsi_ior (in, 2))) -((double)(uint128_central_bitsi_ior (in, 2))))))-((int)((((double)(0x102)) -((double)(0x102)))))-((int)((((int)(uint128_central_bitsi_ior (in, 2))) %((int)(0x102)))))-((long)((((int)(0x102)) &((int)(0x102)))))-((short)((((double)(uint128_central_bitsi_ior (in, 2))) *((double)(0x102)))))))
    { __builtin_abort (); }
  return 0;
}
