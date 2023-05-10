/* corpus/00018.c */
/* Taken from: https://github.com/c-testsuite/c-testsuite */
int
main()
{

	struct S { int x; int y; } s;
	struct S *p;

	p = &s;	
	s.x = 1;
	p->y = 2;
	return p->y + p->x - 3; 
}

/* ProgramSourceWild */
