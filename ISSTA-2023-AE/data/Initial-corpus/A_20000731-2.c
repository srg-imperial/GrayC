/* corpus/20000731-2.c */
int
main()
{
    int i = 1;
    int j = 0;

    while (i != 1024 || j <= 0) {
        i *= 2;
        ++ j;
    }

    if (j != 10)
    { abort (); }

    exit (0);
}
/* ProgramSourceLLVM */
