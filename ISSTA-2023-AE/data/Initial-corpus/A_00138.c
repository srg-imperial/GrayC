/* corpus/00138.c */
/* Taken from: https://github.com/c-testsuite/c-testsuite */
#define M(x) x
#define A(a,b) a(b)

int
main(void)
{
	char *a = A(M,"hi");

	return (a[1] == 'i') ? 0 : 1;
}
/* ProgramSourceWild */
