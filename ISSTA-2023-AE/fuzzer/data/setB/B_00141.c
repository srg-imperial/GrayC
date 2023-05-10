/* corpus/00141.c */
/* Taken from: https://github.com/c-testsuite/c-testsuite */
#define CAT(x,y) x ## y
#define XCAT(x,y) CAT(x,y)
#define FOO foo
#define BAR bar

int
main(void)
{
	int foo, bar, foobar;

	CAT(foo,bar) = foo + bar;
	XCAT(FOO,BAR) = foo + bar;
	return 0;
}
/* ProgramSourceWild */
