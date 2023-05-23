int ak, mt;
const int g5[1] = { -1 }, ip[5] = { 0 };
unsigned int eu;

void
cm (unsigned char t9)
{
  (void) t9;
  eu = (eu & (~0 - 1)) + ip[eu + 1 > 1];
}

void
qe (unsigned int nc)
{
  cm (nc);
  cm (nc);
  cm (nc);
  asm ("");
  cm (nc);
}

int
main (void)
{
  int xh, bc = mt == 2;

  mt = ak;

  for (xh = 0; xh < 1; ++xh)
    {
      qe (g5[xh]);
      asm (";");
      if (!!bc)
        __builtin_puts ("");
    }

  for (xh = 0; xh < 5; ++xh)
    {
      qe (ip[xh]);
      asm (";");
      if (!!bc)
        __builtin_printf ("%d\n", xh);

    }

  for (xh = 0; xh < 3; ++xh)
    {
      qe (ip[xh]);
      if (!!bc)
        mt += xh;
    }

  return 0;
}
