/* corpus/2003-06-16-VolatileError.c */
/* PROGRAMS_TO_SKIP */
/* This crashes the CFE.  */
extern int volatile test;
int volatile test = 0;

int main() { return 0; }
/* ProgramSourceLLVM */
