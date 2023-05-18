/* corpus/00004.c */
/* Taken from: https://github.com/c-testsuite/c-testsuite */
int
main()
{
	int x;
	int *p;
	
	x = 4;
	p = &x;
	*p = 0;

	return *p;
}
/* ProgramSourceWild */
