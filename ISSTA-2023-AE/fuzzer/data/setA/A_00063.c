/* corpus/00063.c */
/* Taken from: https://github.com/c-testsuite/c-testsuite */
#define BAR 0
#ifdef BAR
	#ifdef FOO
		XXX
		#ifdef FOO
			XXX
		#endif
	#else
		#define FOO
		#ifdef FOO
			int x = BAR;
		#endif
	#endif
#endif

int
main()
{
	return BAR;
}
/* ProgramSourceWild */
