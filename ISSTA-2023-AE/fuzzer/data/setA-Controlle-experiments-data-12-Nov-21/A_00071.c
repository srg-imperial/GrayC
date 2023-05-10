/* corpus/00071.c */
/* Taken from: https://github.com/c-testsuite/c-testsuite */
#define X 1
#undef X

#ifdef X
FAIL
#endif

int
main()
{
	return 0;
}
/* ProgramSourceWild */
