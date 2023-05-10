/* corpus/00087.c */
/* Taken from: https://github.com/c-testsuite/c-testsuite */
struct S
{
	int	(*fptr)();
};

int
foo()
{
	return 0;
}

int
main()
{
	struct S v;
	
	v.fptr = foo;
	return v.fptr();
}

/* ProgramSourceWild */
