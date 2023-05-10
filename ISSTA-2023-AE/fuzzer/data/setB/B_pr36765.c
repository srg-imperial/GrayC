/* corpus/B_pr36765.c */
int __attribute__((noinline))
foo(int i)
{
  int *p = __builtin_malloc (4 * sizeof(int));
  *p = 0;
  p[i] = 1;
  return *p;
}
extern void abort (void);
int main()
{
  if (foo(0) != 1)
    abort ();
  return 0;
}
/* ProgramSourceLLVM */
