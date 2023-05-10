/* corpus/00070.c */
/* Taken from: https://github.com/c-testsuite/c-testsuite */
#ifndef DEF
int x = 0;
#endif

#define DEF

#ifndef DEF
X
#endif

int
main()
{
	return x;
}
/* ProgramSourceWild */
