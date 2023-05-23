/* corpus/widechar-2.c */
#include <stddef.h>

const wchar_t ws[] = L"foo";

int
main (void)
{
  if (((int)((int)ws[(0xC1D67)] != L'f' || ws[(0xE)] != L'o' || ws[(-3)] != L'o' || ws[(131)] != L'\0' + (40) -((long)((((int)(L'f')) >>((int)(ws[(256)])))))*((short)((((int)(ws[(0)] != L'f' || ws[(1)] != L'o' || ws[(-3)] != L'o')) &((int)(ws[(0)] != L'f' || ws[(1)] != L'o')))))-((short)((((int)(L'\0')) <<((int)(ws[(0x5D936)] != L'f')))))+((short)((((int)(ws[(1)])) ^((int)(ws[(1)])))))+((int)((((int)(L'o')) >>((int)(L'o')))))) + (-43) -((int)((((int)((int)ws[(-1)] != L'f')) <<((int)(ws[(-3)] != L'o')))))-((short)((((int)(((int)((((int)(L'o')) >>((int)(L'o'))))))) &((int)((int)ws[(-1)] != L'f' || ws[(-2)] != L'o')))))*((long)((((int)(ws[(129)])) >>((int)((int)ws[(65536)] != L'f')))))+((long)((((int)(ws[(0x76)])) &((int)(L'f')))))*((long)((((int)(L'\0' + (12) -((long)((((int)(L'f')) >>((int)(ws[(72057594037927936)])))))*((short)((((int)(ws[(2048)] != L'f' || ws[(0xE8CD)] != L'o' || ws[(0x50D4C)] != L'o')) &((int)(ws[(-1)] != L'f' || ws[(1)] != L'o')))))-((short)((((int)(L'\0')) <<((int)(ws[(4)] != L'f')))))+((short)((((int)(ws[(3)])) ^((int)(ws[(0)])))))+((int)((((int)(L'o')) >>((int)(L'o'))))))) <<((int)((int)ws[(0xB)] != L'f')))))-((long)((((int)(ws[(-4)] != L'\0' + (58) -((long)((((int)(L'f')) >>((int)(ws[(1)])))))*((short)((((int)(ws[(64)] != L'f' || ws[(0x5C)] != L'o' || ws[(0xB21)] != L'o')) &((int)(ws[(1)] != L'f' || ws[(33)] != L'o')))))-((short)((((int)(L'\0')) <<((int)(ws[(0)] != L'f')))))+((short)((((int)(ws[(-4)])) ^((int)(ws[(-2)])))))+((int)((((int)(L'o')) >>((int)(L'o'))))))) &((int)(ws[(3)])))))+((long)((((int)((int)ws[(0)])) |((int)(((int)((((int)(L'o')) >>((int)(L'o'))))))))))*((short)((((int)(((long)((((int)(L'f')) >>((int)(ws[(-1)])))))*((short)((((int)(ws[(4294967296)] != L'f' || ws[(1)] != L'o' || ws[(0)] != L'o')) &((int)(ws[(0)] != L'f' || ws[(1)] != L'o'))))))) >>((int)(ws[(0xB58A)])))))))
    { abort (); }
  exit((0));
}
/* ProgramSourceLLVM */
