a(b, c) int *b; {
  while (c--)
    *b++ = *b++ % *b++ - *b--;
}
