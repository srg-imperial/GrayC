/* corpus/921110-1.c */
extern void abort(void);
typedef void (*frob)();
frob f[] = {abort};

int main(void)
{
  exit(0);
}
/* ProgramSourceLLVM */
