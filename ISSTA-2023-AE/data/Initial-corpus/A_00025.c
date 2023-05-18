/* corpus/00025.c */
/* Taken from: https://github.com/c-testsuite/c-testsuite */
int strlen(char *);

int
main()
{
	char *p;
	
	p = "hello";
	return strlen(p) - 5;
}
/* ProgramSourceWild */
