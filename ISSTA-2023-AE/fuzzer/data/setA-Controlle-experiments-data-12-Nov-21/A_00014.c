/* corpus/00014.c */
/* Taken from: https://github.com/c-testsuite/c-testsuite */
int
main()
{
	int x;
	int *p;
	
	x = 1;
	p = &x;
	p[0] = 0;
	return x;
}
/* ProgramSourceWild */
