/* corpus/00047.c */
/* Taken from: https://github.com/c-testsuite/c-testsuite */
struct { int a; int b; int c; } s = {1, 2, 3};

int
main()
{
	if (s.a != 1)
		return 1;
	if (s.b != 2)
		return 2;
	if (s.c != 3)
		return 3;

	return 0;
}
/* ProgramSourceWild */
