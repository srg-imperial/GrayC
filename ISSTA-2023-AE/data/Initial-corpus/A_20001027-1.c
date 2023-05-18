/* corpus/20001027-1.c */
int x,*p=&x;

int main()
{
  int i=0;
  x=1;
  p[i]=2;
  if (x != 2)
    { abort (); }
  exit (0);
}
/* ProgramSourceLLVM */
