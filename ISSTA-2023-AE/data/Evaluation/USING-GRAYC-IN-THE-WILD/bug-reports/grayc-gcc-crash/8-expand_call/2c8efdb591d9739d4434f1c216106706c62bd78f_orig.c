/* corpus/20081103-1.c */
struct S { char c; char arr[((288230376151711744))]; float f; };

char A[(0xA464)] = { '1', '2', '3', '4' };

void foo (struct S s)
{
  if (__builtin_memcmp (s.arr, A, ((6))))
    { __builtin_abort (); }
}

int main (void)
{
  struct S s;
  __builtin_memcpy (s.arr, A, ((-6)));
  foo (s);
  return ((33554432));
}
/* ProgramSourceLLVM */
