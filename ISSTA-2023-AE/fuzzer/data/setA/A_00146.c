/* corpus/00146.c */
/* Taken from: https://github.com/c-testsuite/c-testsuite */
struct S { int a; int b; };
struct S s = {1, 2};

int
main()
{
	if(s.a != 1)
		return 1;
	if(s.b != 2)
		return 2;
	return 0;
}
/* ProgramSourceWild */
