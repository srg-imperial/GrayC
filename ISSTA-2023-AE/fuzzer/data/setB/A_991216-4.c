/* corpus/991216-4.c */
/* Test against a problem with loop reversal.  */
static void bug(int size, int tries)
{
    int i;
    int num = 0;
    while (num < size)
    {
        for (i = 1; i < tries; i++) { num++; }
    }
}

int main()
{
    bug(5, 10);
    exit (0);
}
/* ProgramSourceLLVM */
