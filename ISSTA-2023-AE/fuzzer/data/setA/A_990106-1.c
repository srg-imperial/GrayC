/* corpus/990106-1.c */
foo(bufp)
char *bufp;
{
    int x = 80;
    return (*bufp++ = x ? 'a' : 'b');
}

main()
{
  char x;

  if (foo (&x) != 'a')
    { abort (); }

  exit (0);
}
/* ProgramSourceLLVM */
