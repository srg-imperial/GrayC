/* corpus/00093.c */
/* Taken from: https://github.com/c-testsuite/c-testsuite */
int a[] = {1, 2, 3, 4};

int
main()
{
	if (sizeof(a) != 4*sizeof(int))
		return 1;
	
	return 0;
}
/* ProgramSourceWild */
