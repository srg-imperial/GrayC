/* corpus/00076.c */
/* Taken from: https://github.com/c-testsuite/c-testsuite */
int
main()
{
	if(0 ? 1 : 0)
		return 1;
	if(1 ? 0 : 1)
		return 2;
	return 0;
}
/* ProgramSourceWild */
