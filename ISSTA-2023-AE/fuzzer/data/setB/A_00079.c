/* corpus/00079.c */
/* Taken from: https://github.com/c-testsuite/c-testsuite */
#define x(y) ((y) + 1)

int
main()
{
	int x;
	int y;
	
	y = 0;
	x = x(y);
	
	if(x != 1)
		return 1;
	
	return 0;
}

/* ProgramSourceWild */
