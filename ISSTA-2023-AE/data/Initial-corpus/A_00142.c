/* corpus/00142.c */
/* Taken from: https://github.com/c-testsuite/c-testsuite */
#if defined(FOO)
int a;
#elif !defined(FOO) && defined(BAR)
int b;
#elif !defined(FOO) && !defined(BAR)
int c;
#else
int d;
#endif

int
main(void)
{
	return c;
}
/* ProgramSourceWild */
