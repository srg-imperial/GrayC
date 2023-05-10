/* corpus/00073.c */
/* Taken from: https://github.com/c-testsuite/c-testsuite */
int
main()
{
	int arr[2];
	int *p;
	
	p = &arr[1];
	p -= 1;
	*p = 123;
	
	if(arr[0] != 123)
		return 1;
	return 0;
}
/* ProgramSourceWild */
