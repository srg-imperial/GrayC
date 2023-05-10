/* corpus/00103.c */
/* Taken from: https://github.com/c-testsuite/c-testsuite */
int
main()
{
	int x;
	void *foo;
	void **bar;
	
	x = 0;
	
	foo = (void*)&x;
	bar = &foo;
	
	return **(int**)bar;
}
/* ProgramSourceWild */
