/* corpus/20031211-1.c */
struct a { unsigned int bitfield : 1; };

unsigned int x;

main()
{
  struct a a = {0};
  x = 0xbeef;
  a.bitfield |= x;
  if (a.bitfield != 1)
    { abort (); }
  exit (0);
}
/* ProgramSourceLLVM */
