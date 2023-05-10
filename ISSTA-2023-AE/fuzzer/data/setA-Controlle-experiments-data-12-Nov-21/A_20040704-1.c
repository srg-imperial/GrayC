/* corpus/20040704-1.c */
/* PR 16348: Make sure that condition-first false loops DTRT.  */

extern void abort ();

int main()
{
  for (; 0 ;)
    {
      abort ();
    label:
      return 0;
    }
  goto label;
}
/* ProgramSourceLLVM */
