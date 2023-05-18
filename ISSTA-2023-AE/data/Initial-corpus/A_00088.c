/* corpus/00088.c */
/* Taken from: https://github.com/c-testsuite/c-testsuite */
int (*fptr)() = 0;


int
main()
{
	if (fptr)
		return 1;
	return 0;
}

/* ProgramSourceWild */
