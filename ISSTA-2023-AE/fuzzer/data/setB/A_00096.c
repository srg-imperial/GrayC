/* corpus/00096.c */
/* Taken from: https://github.com/c-testsuite/c-testsuite */
int x, x = 3, x;

int
main()
{
	if (x != 3)
		return 0;

	x = 0;
	return x;
}

/* ProgramSourceWild */