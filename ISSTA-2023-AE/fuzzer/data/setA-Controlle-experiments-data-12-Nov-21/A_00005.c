/* corpus/00005.c */
/* Taken from: https://github.com/c-testsuite/c-testsuite */
int
main()
{
	int x;
	int *p;
	int **pp;

	x = 0;
	p = &x;
	pp = &p;

	if(*p)
		return 1;
	if(**pp)
		return 1;
	else
		**pp = 1;

	if(x)
		return 0;
	else
		return 1;
}
/* ProgramSourceWild */
