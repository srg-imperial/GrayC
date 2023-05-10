/* corpus/00105.c */
/* Taken from: https://github.com/c-testsuite/c-testsuite */
int
main()
{
	int i;

	for(i = 0; i < 10; i++)
		if (!i)
			continue;
	
	return 0;
}
/* ProgramSourceWild */
