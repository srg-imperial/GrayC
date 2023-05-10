/* corpus/00052.c */
/* Taken from: https://github.com/c-testsuite/c-testsuite */
int
main()
{
	struct T { int x; };
	{
		struct T s;
		s.x = 0;
		return s.x;
	}
}
/* ProgramSourceWild */
