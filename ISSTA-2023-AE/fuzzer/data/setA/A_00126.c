/* corpus/00126.c */
/* Taken from: https://github.com/c-testsuite/c-testsuite */
int
main()
{
        int x;

        x = 3;
        x = !x;
        x = !x;
        x = ~x;
        x = -x;
        if(x != 2)
                return 1;
        return 0;
}
/* ProgramSourceWild */
