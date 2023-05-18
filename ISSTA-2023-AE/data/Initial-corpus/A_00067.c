/* corpus/00067.c */
/* Taken from: https://github.com/c-testsuite/c-testsuite */
#if 1
int x = 0;
#endif

#if 0
int x = 1;
#if 1
 X
#endif
#ifndef AAA
 X
#endif
#endif

int main()
{
	return x;
}
/* ProgramSourceWild */
