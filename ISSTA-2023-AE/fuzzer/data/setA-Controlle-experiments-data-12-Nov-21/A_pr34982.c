/* corpus/pr34982.c */
extern void abort (void);

static void something();

int main()
{
  something(-1);
  return 0;
}

static void something(int i)
{
  if (i != -1)
    { abort (); }
}
/* ProgramSourceLLVM */
