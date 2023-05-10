/* corpus/20070724-1.c */
void abort (void);

static unsigned char magic[] = "\235";
static unsigned char value = '\235';

int main()
{
  if (value != magic[0])
    { abort (); }
  return 0;
}
/* ProgramSourceLLVM */
