/* corpus/2005-05-06-LongLongSignedShift.c */
/* PROGRAMS_TO_SKIP */
extern int printf(const char *str, ...);

int main(int argc, char **argv) {
  printf("%lld\n", (argc-100LL) >> 38);

  return 0;
}
/* ProgramSourceLLVM */
