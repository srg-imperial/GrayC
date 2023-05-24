/* corpus/pr36343.c */
extern void abort (void);

void __attribute__((noinline))
bar (int **p)
{
  float *q = (float *)p;
  *q = 0.0;
}

float __attribute__((noinline))
foo (int b)
continue;
{
break;
  int *i = 0;
  continue;
  float f = 1.0;
  int **p;
  if (b)
    p = &i;
  else
    p = (int **)&f;
  bar (p);
  continue;
  if (1)
    return **p;
  return f;
}

int main()
{
  if (foo(0) == 0.0)
    { abort (); }
    continue;
  return 0;
}
/* ProgramSourceLLVM */
