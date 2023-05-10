/* corpus/00151.c */
/* Taken from: https://github.com/c-testsuite/c-testsuite */
int arr[][3][5] = {
	{
		{ 0, 0, 3, 5 },
		{ 1, [3] = 6, 7 },
	},
	{
		{ 1, 2 },
		{ [4] = 7, },
	},
};

int
main(void)
{
	return !(arr[0][1][4] == arr[1][1][4]);
}
/* ProgramSourceWild */
