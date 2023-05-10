/* corpus/00152.c */
/* Taken from: https://github.com/c-testsuite/c-testsuite */
#undef  line
#define line 1000

#line line
#if 1000 != __LINE__
	#error "  # line line" not work as expected
#endif

int
main()
{
	return 0;
}
/* ProgramSourceWild */
