/* corpus/990222-1.c */
char line[4] = { '1', '9', '9', '\0' };

int main()
{
  char *ptr = line + 3;

  while ((*--ptr += 1) > '9') *ptr = '0';
  if (line[0] != '2' || line[1] != '0' || line[2] != '0')
    { abort (); }
  return 0;
}
/* ProgramSourceLLVM */
