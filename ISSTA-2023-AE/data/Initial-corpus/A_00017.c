/* corpus/00017.c */
/* Taken from: https://github.com/c-testsuite/c-testsuite */
int
main()
{
	struct { int x; int y; } s;
	
	s.x = 3;
	s.y = 5;
	return s.y - s.x - 2; 
}
/* ProgramSourceWild */
