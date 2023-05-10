/* corpus/2003-05-14-initialize-string.c */
/* PROGRAMS_TO_SKIP */
extern int printf(const char *str, ...);

int main() {
  char title[] = "foo and stuff\n";
  printf("%s", title);
  return 0;
}
/* ProgramSourceLLVM */
