/* corpus/00024.c */
/* Taken from: https://github.com/c-testsuite/c-testsuite */
typedef struct { int x; int y; } s;

s v;

int
main()
{
	v.x = 1;
	v.y = 2;
	return 3 - v.x - v.y;
}

/* ProgramSourceWild */
