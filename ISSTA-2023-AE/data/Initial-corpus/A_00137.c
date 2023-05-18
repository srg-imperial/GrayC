/* corpus/00137.c */
/* Taken from: https://github.com/c-testsuite/c-testsuite */
#define x(y) #y

int
main(void)
{
	char *p;
	p = x(hello)  " is better than bye";

	return (*p == 'h') ? 0 : 1;
}
/* ProgramSourceWild */
