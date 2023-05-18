/* corpus/00016.c */
/* Taken from: https://github.com/c-testsuite/c-testsuite */
int
main()
{
	int arr[2];
	int *p;
	
	p = &arr[1];
	*p = 0;
	return arr[1];
}
/* ProgramSourceWild */
