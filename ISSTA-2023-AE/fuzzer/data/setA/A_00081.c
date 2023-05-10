/* corpus/00081.c */
/* Taken from: https://github.com/c-testsuite/c-testsuite */
int
main()
{
	long long x;
	
	x = 0;
	x = x + 1;
	if (x != 1)
		return 1;
	return 0;
}
/* ProgramSourceWild */
