/* corpus/00019.c */
/* Taken from: https://github.com/c-testsuite/c-testsuite */
int
main()
{
	struct S { struct S *p; int x; } s;
	
	s.x = 0;
	s.p = &s;
	return s.p->p->p->p->p->x;
}

/* ProgramSourceWild */
