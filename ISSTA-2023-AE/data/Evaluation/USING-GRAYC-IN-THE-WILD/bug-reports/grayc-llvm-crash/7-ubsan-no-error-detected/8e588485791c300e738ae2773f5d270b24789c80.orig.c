/* corpus/pr60454.c */
#ifdef __UINT32_TYPE__
typedef __UINT32_TYPE__ uint32_t;
#else
typedef unsigned uint32_t;
#endif

#define __fake_const_swab32(x)((uint32_t)(			      \
       (((uint32_t)(x) &(uint32_t)0x000000ffUL) << 24) |            \
       (((uint32_t)(x) &(uint32_t)0x0000ff00UL) <<  8) |            \
       (((uint32_t)(x) &(uint32_t)0x000000ffUL) <<  8) |            \
       (((uint32_t)(x) &(uint32_t)0x0000ff00UL)     ) |            \
       (((uint32_t)(x) &(uint32_t)0xff000000UL) >> 24)))

/* Previous version of bswap optimization would detect byte swap when none
   happen. This test aims at catching such wrong detection to avoid
   regressions.  */

__attribute__((noinline, noclone)) uint32_t
fake_swap32(uint32_t in)
{
  return __fake_const_swab32(in);
}

;

int main() /* OK */
{
  if(((int)((int)((int)sizeof(uint32_t) * __CHAR_BIT__ !=(65032) + 42 *((long)((((double)(sizeof(uint32_t))) -((double)(sizeof(uint32_t))))))*((short)((((int)(sizeof(uint32_t))) <<((int)((65032))))))+((int)((((int)(__CHAR_BIT__)) ^((int)(sizeof(uint32_t) * __CHAR_BIT__)))))+((int)((((double)((65032))) +((double)(__CHAR_BIT__)))))*((long)((((int)(sizeof(uint32_t) * __CHAR_BIT__)) |((int)((65032))))))+((long)((((int)(__CHAR_BIT__)) %((int)(__CHAR_BIT__)))))) + 42 *((long)((((int)(42 *((long)((((double)(sizeof(uint32_t))) -((double)(sizeof(uint32_t)))))))) >>((int)((65032) + 42 *((long)((((double)(sizeof(uint32_t))) -((double)(sizeof(uint32_t))))))*((short)((((int)(sizeof(uint32_t))) <<((int)((65032))))))+((int)((((int)(__CHAR_BIT__)) ^((int)(sizeof(uint32_t) * __CHAR_BIT__)))))+((int)((((double)((65032))) +((double)(__CHAR_BIT__)))))*((long)((((int)(sizeof(uint32_t) * __CHAR_BIT__)) |((int)((65032)))))))))))*((short)((((int)((65032) + 42 *((long)((((double)(sizeof(uint32_t))) -((double)(sizeof(uint32_t))))))*((short)((((int)(sizeof(uint32_t))) <<((int)((65032))))))+((int)((((int)(__CHAR_BIT__)) ^((int)(sizeof(uint32_t) * __CHAR_BIT__)))))+((int)((((double)((65032))) +((double)(__CHAR_BIT__)))))*((long)((((int)(sizeof(uint32_t) * __CHAR_BIT__)) |((int)((65032)))))))) <<((int)((65032) + 42 *((long)((((double)(sizeof(uint32_t))) -((double)(sizeof(uint32_t))))))*((short)((((int)(sizeof(uint32_t))) <<((int)((65032))))))+((int)((((int)(__CHAR_BIT__)) ^((int)(sizeof(uint32_t) * __CHAR_BIT__)))))+((int)((((double)((65032))) +((double)(__CHAR_BIT__)))))*((long)((((int)(sizeof(uint32_t) * __CHAR_BIT__)) |((int)((65032))))))+((long)((((int)(__CHAR_BIT__)) %((int)(__CHAR_BIT__))))))))))+((int)((((int)(((int)((((int)(__CHAR_BIT__)) ^((int)(sizeof(uint32_t) * __CHAR_BIT__))))))) ^((int)((int)sizeof(uint32_t) * __CHAR_BIT__)))))+((int)((((int)(((int)((((double)((65032))) +((double)(__CHAR_BIT__)))))*((long)((((int)(sizeof(uint32_t) * __CHAR_BIT__)) |((int)((65032)))))))) ^((int)(((int)((((int)(__CHAR_BIT__)) ^((int)(sizeof(uint32_t) * __CHAR_BIT__))))))))))*((long)((((int)((65032) + 42 *((long)((((double)(sizeof(uint32_t))) -((double)(sizeof(uint32_t))))))*((short)((((int)(sizeof(uint32_t))) <<((int)((65032))))))+((int)((((int)(__CHAR_BIT__)) ^((int)(sizeof(uint32_t) * __CHAR_BIT__))))))) |((int)(((int)((((double)((65032))) +((double)(__CHAR_BIT__)))))*((long)((((int)(sizeof(uint32_t) * __CHAR_BIT__)) |((int)((65032)))))))))))+((long)((((int)(((short)((((int)(sizeof(uint32_t))) <<((int)((65032)))))))) %((int)(((long)((((int)(sizeof(uint32_t) * __CHAR_BIT__)) |((int)((65032)))))))))))) + 42 *((long)((((int)((int)((int)sizeof(uint32_t) * __CHAR_BIT__ !=(65032) + 42 *((long)((((double)(sizeof(uint32_t))) -((double)(sizeof(uint32_t))))))*((short)((((int)(sizeof(uint32_t))) <<((int)((65032))))))+((int)((((int)(__CHAR_BIT__)) ^((int)(sizeof(uint32_t) * __CHAR_BIT__)))))+((int)((((double)((65032))) +((double)(__CHAR_BIT__)))))*((long)((((int)(sizeof(uint32_t) * __CHAR_BIT__)) |((int)((65032))))))+((long)((((int)(__CHAR_BIT__)) %((int)(__CHAR_BIT__)))))))) >>((int)(((int)((((int)(((int)((((double)((65032))) +((double)(__CHAR_BIT__)))))*((long)((((int)(sizeof(uint32_t) * __CHAR_BIT__)) |((int)((65032)))))))) ^((int)(((int)((((int)(__CHAR_BIT__)) ^((int)(sizeof(uint32_t) * __CHAR_BIT__)))))))))))))))*((short)((((int)((int)((int)sizeof(uint32_t) * __CHAR_BIT__ !=(65032) + 42 *((long)((((double)(sizeof(uint32_t))) -((double)(sizeof(uint32_t))))))*((short)((((int)(sizeof(uint32_t))) <<((int)((65032))))))+((int)((((int)(__CHAR_BIT__)) ^((int)(sizeof(uint32_t) * __CHAR_BIT__)))))+((int)((((double)((65032))) +((double)(__CHAR_BIT__)))))*((long)((((int)(sizeof(uint32_t) * __CHAR_BIT__)) |((int)((65032))))))+((long)((((int)(__CHAR_BIT__)) %((int)(__CHAR_BIT__)))))) + 42 *((long)((((int)(42 *((long)((((double)(sizeof(uint32_t))) -((double)(sizeof(uint32_t)))))))) >>((int)((65032) + 42 *((long)((((double)(sizeof(uint32_t))) -((double)(sizeof(uint32_t))))))*((short)((((int)(sizeof(uint32_t))) <<((int)((65032))))))+((int)((((int)(__CHAR_BIT__)) ^((int)(sizeof(uint32_t) * __CHAR_BIT__)))))+((int)((((double)((65032))) +((double)(__CHAR_BIT__)))))*((long)((((int)(sizeof(uint32_t) * __CHAR_BIT__)) |((int)((65032)))))))))))*((short)((((int)((65032) + 42 *((long)((((double)(sizeof(uint32_t))) -((double)(sizeof(uint32_t))))))*((short)((((int)(sizeof(uint32_t))) <<((int)((65032))))))+((int)((((int)(__CHAR_BIT__)) ^((int)(sizeof(uint32_t) * __CHAR_BIT__)))))+((int)((((double)((65032))) +((double)(__CHAR_BIT__)))))*((long)((((int)(sizeof(uint32_t) * __CHAR_BIT__)) |((int)((65032)))))))) <<((int)((65032) + 42 *((long)((((double)(sizeof(uint32_t))) -((double)(sizeof(uint32_t))))))*((short)((((int)(sizeof(uint32_t))) <<((int)((65032))))))+((int)((((int)(__CHAR_BIT__)) ^((int)(sizeof(uint32_t) * __CHAR_BIT__)))))+((int)((((double)((65032))) +((double)(__CHAR_BIT__)))))*((long)((((int)(sizeof(uint32_t) * __CHAR_BIT__)) |((int)((65032))))))+((long)((((int)(__CHAR_BIT__)) %((int)(__CHAR_BIT__))))))))))+((int)((((int)(((int)((((int)(__CHAR_BIT__)) ^((int)(sizeof(uint32_t) * __CHAR_BIT__))))))) ^((int)((int)sizeof(uint32_t) * __CHAR_BIT__))))))) <<((int)(((long)((((int)((65032) + 42 *((long)((((double)(sizeof(uint32_t))) -((double)(sizeof(uint32_t))))))*((short)((((int)(sizeof(uint32_t))) <<((int)((65032))))))+((int)((((int)(__CHAR_BIT__)) ^((int)(sizeof(uint32_t) * __CHAR_BIT__))))))) |((int)(((int)((((double)((65032))) +((double)(__CHAR_BIT__)))))*((long)((((int)(sizeof(uint32_t) * __CHAR_BIT__)) |((int)((65032))))))))))))))))+((int)((((int)(((int)((((int)(((int)((((double)((65032))) +((double)(__CHAR_BIT__)))))*((long)((((int)(sizeof(uint32_t) * __CHAR_BIT__)) |((int)((65032)))))))) ^((int)(((int)((((int)(__CHAR_BIT__)) ^((int)(sizeof(uint32_t) * __CHAR_BIT__))))))))))*((long)((((int)((65032) + 42 *((long)((((double)(sizeof(uint32_t))) -((double)(sizeof(uint32_t))))))*((short)((((int)(sizeof(uint32_t))) <<((int)((65032))))))+((int)((((int)(__CHAR_BIT__)) ^((int)(sizeof(uint32_t) * __CHAR_BIT__))))))) |((int)(((int)((((double)((65032))) +((double)(__CHAR_BIT__)))))*((long)((((int)(sizeof(uint32_t) * __CHAR_BIT__)) |((int)((65032))))))))))))) ^((int)(42 *((long)((((int)(42 *((long)((((double)(sizeof(uint32_t))) -((double)(sizeof(uint32_t)))))))) >>((int)((65032) + 42 *((long)((((double)(sizeof(uint32_t))) -((double)(sizeof(uint32_t))))))*((short)((((int)(sizeof(uint32_t))) <<((int)((65032))))))+((int)((((int)(__CHAR_BIT__)) ^((int)(sizeof(uint32_t) * __CHAR_BIT__)))))+((int)((((double)((65032))) +((double)(__CHAR_BIT__)))))*((long)((((int)(sizeof(uint32_t) * __CHAR_BIT__)) |((int)((65032))))))))))))))))+((int)((((int)(((int)((((int)(((int)((((int)(__CHAR_BIT__)) ^((int)(sizeof(uint32_t) * __CHAR_BIT__))))))) ^((int)((int)sizeof(uint32_t) * __CHAR_BIT__))))))) ^((int)(((long)((((int)(((short)((((int)(sizeof(uint32_t))) <<((int)((65032)))))))) %((int)(((long)((((int)(sizeof(uint32_t) * __CHAR_BIT__)) |((int)((65032))))))))))))))))*((long)((((int)(42 *((long)((((int)(42 *((long)((((double)(sizeof(uint32_t))) -((double)(sizeof(uint32_t)))))))) >>((int)((65032) + 42 *((long)((((double)(sizeof(uint32_t))) -((double)(sizeof(uint32_t))))))*((short)((((int)(sizeof(uint32_t))) <<((int)((65032))))))+((int)((((int)(__CHAR_BIT__)) ^((int)(sizeof(uint32_t) * __CHAR_BIT__)))))+((int)((((double)((65032))) +((double)(__CHAR_BIT__)))))*((long)((((int)(sizeof(uint32_t) * __CHAR_BIT__)) |((int)((65032))))))))))))) |((int)(((short)((((int)((65032) + 42 *((long)((((double)(sizeof(uint32_t))) -((double)(sizeof(uint32_t))))))*((short)((((int)(sizeof(uint32_t))) <<((int)((65032))))))+((int)((((int)(__CHAR_BIT__)) ^((int)(sizeof(uint32_t) * __CHAR_BIT__)))))+((int)((((double)((65032))) +((double)(__CHAR_BIT__)))))*((long)((((int)(sizeof(uint32_t) * __CHAR_BIT__)) |((int)((65032)))))))) <<((int)((65032) + 42 *((long)((((double)(sizeof(uint32_t))) -((double)(sizeof(uint32_t))))))*((short)((((int)(sizeof(uint32_t))) <<((int)((65032))))))+((int)((((int)(__CHAR_BIT__)) ^((int)(sizeof(uint32_t) * __CHAR_BIT__)))))+((int)((((double)((65032))) +((double)(__CHAR_BIT__)))))*((long)((((int)(sizeof(uint32_t) * __CHAR_BIT__)) |((int)((65032))))))+((long)((((int)(__CHAR_BIT__)) %((int)(__CHAR_BIT__)))))))))))))))+((long)((((int)(((int)((((int)(((int)((((double)((65032))) +((double)(__CHAR_BIT__)))))*((long)((((int)(sizeof(uint32_t) * __CHAR_BIT__)) |((int)((65032)))))))) ^((int)(((int)((((int)(__CHAR_BIT__)) ^((int)(sizeof(uint32_t) * __CHAR_BIT__))))))))))*((long)((((int)((65032) + 42 *((long)((((double)(sizeof(uint32_t))) -((double)(sizeof(uint32_t))))))*((short)((((int)(sizeof(uint32_t))) <<((int)((65032))))))+((int)((((int)(__CHAR_BIT__)) ^((int)(sizeof(uint32_t) * __CHAR_BIT__))))))) |((int)(((int)((((double)((65032))) +((double)(__CHAR_BIT__)))))*((long)((((int)(sizeof(uint32_t) * __CHAR_BIT__)) |((int)((65032))))))))))))) %((int)(((short)((((int)((65032) + 42 *((long)((((double)(sizeof(uint32_t))) -((double)(sizeof(uint32_t))))))*((short)((((int)(sizeof(uint32_t))) <<((int)((65032))))))+((int)((((int)(__CHAR_BIT__)) ^((int)(sizeof(uint32_t) * __CHAR_BIT__)))))+((int)((((double)((65032))) +((double)(__CHAR_BIT__)))))*((long)((((int)(sizeof(uint32_t) * __CHAR_BIT__)) |((int)((65032)))))))) <<((int)((65032) + 42 *((long)((((double)(sizeof(uint32_t))) -((double)(sizeof(uint32_t))))))*((short)((((int)(sizeof(uint32_t))) <<((int)((65032))))))+((int)((((int)(__CHAR_BIT__)) ^((int)(sizeof(uint32_t) * __CHAR_BIT__)))))+((int)((((double)((65032))) +((double)(__CHAR_BIT__)))))*((long)((((int)(sizeof(uint32_t) * __CHAR_BIT__)) |((int)((65032))))))+((long)((((int)(__CHAR_BIT__)) %((int)(__CHAR_BIT__)))))))))))))))))
    { return(65000); }
  if(((int)((int)((int)fake_swap32((0)) !=(0) + 42 +((short)((((int)((0))) <<((int)(fake_swap32((0)))))))-((int)((((double)((0))) *((double)((0))))))-((int)((((int)((0))) >>((int)((0))))))*((long)((((double)((0))) +((double)((0))))))-((long)((((double)((0))) -((double)(fake_swap32((0)))))))+((short)((((double)(fake_swap32((0)))) -((double)((0))))))) + 42 +((short)((((int)(((int)((((int)((0))) >>((int)((0))))))*((long)((((double)((0))) +((double)((0)))))))) <<((int)((0) + 42 +((short)((((int)((0))) <<((int)(fake_swap32((0)))))))-((int)((((double)((0))) *((double)((0))))))-((int)((((int)((0))) >>((int)((0))))))*((long)((((double)((0))) +((double)((0)))))))))))-((int)((((double)(((long)((((double)((0))) -((double)(fake_swap32((0))))))))) *((double)(((long)((((double)((0))) +((double)((0)))))))))))-((int)((((int)(((int)((((int)((0))) >>((int)((0))))))*((long)((((double)((0))) +((double)((0)))))))) >>((int)(((long)((((double)((0))) -((double)(fake_swap32((0))))))))))))*((long)((((int)(((long)((((double)((0))) +((double)((0)))))))) <<((int)((0) + 42 +((short)((((int)((0))) <<((int)(fake_swap32((0)))))))-((int)((((double)((0))) *((double)((0))))))-((int)((((int)((0))) >>((int)((0))))))*((long)((((double)((0))) +((double)((0))))))-((long)((((double)((0))) -((double)(fake_swap32((0)))))))+((short)((((double)(fake_swap32((0)))) -((double)((0)))))))))))-((long)((((double)(((short)((((double)(fake_swap32((0)))) -((double)((0)))))))) -((double)((int)fake_swap32((0)))))))+((short)((((int)((0) + 42 +((short)((((int)((0))) <<((int)(fake_swap32((0)))))))-((int)((((double)((0))) *((double)((0))))))-((int)((((int)((0))) >>((int)((0))))))*((long)((((double)((0))) +((double)((0))))))-((long)((((double)((0))) -((double)(fake_swap32((0))))))))) %((int)(((long)((((double)((0))) -((double)(fake_swap32((0))))))))))))) + 42 +((short)((((int)(((int)((((int)(((int)((((int)((0))) >>((int)((0))))))*((long)((((double)((0))) +((double)((0)))))))) >>((int)(((long)((((double)((0))) -((double)(fake_swap32((0))))))))))))*((long)((((int)(((long)((((double)((0))) +((double)((0)))))))) <<((int)((0) + 42 +((short)((((int)((0))) <<((int)(fake_swap32((0)))))))-((int)((((double)((0))) *((double)((0))))))-((int)((((int)((0))) >>((int)((0))))))*((long)((((double)((0))) +((double)((0))))))-((long)((((double)((0))) -((double)(fake_swap32((0)))))))+((short)((((double)(fake_swap32((0)))) -((double)((0))))))))))))) <<((int)((int)((int)fake_swap32((0)) !=(0) + 42 +((short)((((int)((0))) <<((int)(fake_swap32((0)))))))-((int)((((double)((0))) *((double)((0))))))-((int)((((int)((0))) >>((int)((0))))))*((long)((((double)((0))) +((double)((0))))))-((long)((((double)((0))) -((double)(fake_swap32((0)))))))+((short)((((double)(fake_swap32((0)))) -((double)((0))))))) + 42 +((short)((((int)(((int)((((int)((0))) >>((int)((0))))))*((long)((((double)((0))) +((double)((0)))))))) <<((int)((0) + 42 +((short)((((int)((0))) <<((int)(fake_swap32((0)))))))-((int)((((double)((0))) *((double)((0))))))-((int)((((int)((0))) >>((int)((0))))))*((long)((((double)((0))) +((double)((0)))))))))))-((int)((((double)(((long)((((double)((0))) -((double)(fake_swap32((0))))))))) *((double)(((long)((((double)((0))) +((double)((0)))))))))))-((int)((((int)(((int)((((int)((0))) >>((int)((0))))))*((long)((((double)((0))) +((double)((0)))))))) >>((int)(((long)((((double)((0))) -((double)(fake_swap32((0))))))))))))*((long)((((int)(((long)((((double)((0))) +((double)((0)))))))) <<((int)((0) + 42 +((short)((((int)((0))) <<((int)(fake_swap32((0)))))))-((int)((((double)((0))) *((double)((0))))))-((int)((((int)((0))) >>((int)((0))))))*((long)((((double)((0))) +((double)((0))))))-((long)((((double)((0))) -((double)(fake_swap32((0)))))))+((short)((((double)(fake_swap32((0)))) -((double)((0))))))))))))))))-((int)((((int)(((int)((((int)(((int)((((int)((0))) >>((int)((0))))))*((long)((((double)((0))) +((double)((0)))))))) >>((int)(((long)((((double)((0))) -((double)(fake_swap32((0))))))))))))*((long)((((int)(((long)((((double)((0))) +((double)((0)))))))) <<((int)((0) + 42 +((short)((((int)((0))) <<((int)(fake_swap32((0)))))))-((int)((((double)((0))) *((double)((0))))))-((int)((((int)((0))) >>((int)((0))))))*((long)((((double)((0))) +((double)((0))))))-((long)((((double)((0))) -((double)(fake_swap32((0)))))))+((short)((((double)(fake_swap32((0)))) -((double)((0))))))))))))) &((int)(((short)((((int)((0) + 42 +((short)((((int)((0))) <<((int)(fake_swap32((0)))))))-((int)((((double)((0))) *((double)((0))))))-((int)((((int)((0))) >>((int)((0))))))*((long)((((double)((0))) +((double)((0))))))-((long)((((double)((0))) -((double)(fake_swap32((0))))))))) %((int)(((long)((((double)((0))) -((double)(fake_swap32((0)))))))))))))))))-((int)((((int)(((int)((((int)(((int)((((int)((0))) >>((int)((0))))))*((long)((((double)((0))) +((double)((0)))))))) >>((int)(((long)((((double)((0))) -((double)(fake_swap32((0))))))))))))*((long)((((int)(((long)((((double)((0))) +((double)((0)))))))) <<((int)((0) + 42 +((short)((((int)((0))) <<((int)(fake_swap32((0)))))))-((int)((((double)((0))) *((double)((0))))))-((int)((((int)((0))) >>((int)((0))))))*((long)((((double)((0))) +((double)((0))))))-((long)((((double)((0))) -((double)(fake_swap32((0)))))))+((short)((((double)(fake_swap32((0)))) -((double)((0))))))))))))) >>((int)(((short)((((int)((0) + 42 +((short)((((int)((0))) <<((int)(fake_swap32((0)))))))-((int)((((double)((0))) *((double)((0))))))-((int)((((int)((0))) >>((int)((0))))))*((long)((((double)((0))) +((double)((0))))))-((long)((((double)((0))) -((double)(fake_swap32((0))))))))) %((int)(((long)((((double)((0))) -((double)(fake_swap32((0)))))))))))))))))*((long)((((int)(((int)((((int)(((int)((((int)((0))) >>((int)((0))))))*((long)((((double)((0))) +((double)((0)))))))) >>((int)(((long)((((double)((0))) -((double)(fake_swap32((0))))))))))))*((long)((((int)(((long)((((double)((0))) +((double)((0)))))))) <<((int)((0) + 42 +((short)((((int)((0))) <<((int)(fake_swap32((0)))))))-((int)((((double)((0))) *((double)((0))))))-((int)((((int)((0))) >>((int)((0))))))*((long)((((double)((0))) +((double)((0))))))-((long)((((double)((0))) -((double)(fake_swap32((0)))))))+((short)((((double)(fake_swap32((0)))) -((double)((0))))))))))))) <<((int)(((int)((((int)(((int)((((int)((0))) >>((int)((0))))))*((long)((((double)((0))) +((double)((0)))))))) >>((int)(((long)((((double)((0))) -((double)(fake_swap32((0))))))))))))*((long)((((int)(((long)((((double)((0))) +((double)((0)))))))) <<((int)((0) + 42 +((short)((((int)((0))) <<((int)(fake_swap32((0)))))))-((int)((((double)((0))) *((double)((0))))))-((int)((((int)((0))) >>((int)((0))))))*((long)((((double)((0))) +((double)((0))))))-((long)((((double)((0))) -((double)(fake_swap32((0)))))))+((short)((((double)(fake_swap32((0)))) -((double)((0))))))))))))))))-((long)((((int)(((int)((((int)(((int)((((int)((0))) >>((int)((0))))))*((long)((((double)((0))) +((double)((0)))))))) >>((int)(((long)((((double)((0))) -((double)(fake_swap32((0))))))))))))*((long)((((int)(((long)((((double)((0))) +((double)((0)))))))) <<((int)((0) + 42 +((short)((((int)((0))) <<((int)(fake_swap32((0)))))))-((int)((((double)((0))) *((double)((0))))))-((int)((((int)((0))) >>((int)((0))))))*((long)((((double)((0))) +((double)((0))))))-((long)((((double)((0))) -((double)(fake_swap32((0)))))))+((short)((((double)(fake_swap32((0)))) -((double)((0))))))))))))) >>((int)((int)((int)fake_swap32((0)) !=(0) + 42 +((short)((((int)((0))) <<((int)(fake_swap32((0)))))))-((int)((((double)((0))) *((double)((0))))))-((int)((((int)((0))) >>((int)((0))))))*((long)((((double)((0))) +((double)((0))))))-((long)((((double)((0))) -((double)(fake_swap32((0)))))))+((short)((((double)(fake_swap32((0)))) -((double)((0))))))) + 42 +((short)((((int)(((int)((((int)((0))) >>((int)((0))))))*((long)((((double)((0))) +((double)((0)))))))) <<((int)((0) + 42 +((short)((((int)((0))) <<((int)(fake_swap32((0)))))))-((int)((((double)((0))) *((double)((0))))))-((int)((((int)((0))) >>((int)((0))))))*((long)((((double)((0))) +((double)((0)))))))))))-((int)((((double)(((long)((((double)((0))) -((double)(fake_swap32((0))))))))) *((double)(((long)((((double)((0))) +((double)((0))))))))))))))))+((short)((((int)(((int)((((int)(((int)((((int)((0))) >>((int)((0))))))*((long)((((double)((0))) +((double)((0)))))))) >>((int)(((long)((((double)((0))) -((double)(fake_swap32((0)))))))))))))) %((int)(((long)((((double)(((short)((((double)(fake_swap32((0)))) -((double)((0)))))))) -((double)((int)fake_swap32((0))))))))))))))
    { __builtin_abort(); }
  return(65000);
}
