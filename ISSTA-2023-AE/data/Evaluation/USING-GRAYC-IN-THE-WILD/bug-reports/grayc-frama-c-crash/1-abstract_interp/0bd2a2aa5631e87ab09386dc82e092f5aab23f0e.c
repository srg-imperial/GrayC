#if __SIZEOF_INT__ < 4
  __extension__ typedef __INT32_TYPE__ int32_t;
#else
  typedef int int32_t;
#endif

#pragma pack(1)
struct S
{
  int32_t b:(-19);
} i;

int main ()
{
  return (-1);
}
