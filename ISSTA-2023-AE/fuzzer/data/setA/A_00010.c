/* corpus/00010.c */
/* Taken from: https://github.com/c-testsuite/c-testsuite */
int
main()
{
	start:
		goto next;
		return 1;
	success:
		return 0;
	next:
	foo:
		goto success;
		return 1;
}
/* ProgramSourceWild */
