/* corpus/00078.c */
/* Taken from: https://github.com/c-testsuite/c-testsuite */
int
f1(char *p)
{
	return *p+1;
}

int
main()
{
	char s = 1;
	int v[1000];
	int f1(char *);

	if (f1(&s) != 2)
		return 1;
	return 0;
}
/* ProgramSourceWild */
