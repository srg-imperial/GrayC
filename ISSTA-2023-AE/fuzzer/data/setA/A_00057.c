/* corpus/00057.c */
/* Taken from: https://github.com/c-testsuite/c-testsuite */
int
main()
{
	char a[16], b[16];
	
	if(sizeof(a) != sizeof(b))
		return 1;
	return 0;
}
/* ProgramSourceWild */
