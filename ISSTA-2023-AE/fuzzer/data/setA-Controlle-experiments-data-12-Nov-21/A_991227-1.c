/* corpus/991227-1.c */
char* doit(int flag)
{
  return 1 + (flag ? "\0wrong\n" : "\0right\n");
}
int main()
{
  char *result = doit(0);
  if (*result == 'r' && result[1] == 'i')
    exit(0);
  abort();
}
/* ProgramSourceLLVM */
