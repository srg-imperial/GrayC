/* corpus/00217.c */
/* Taken from: https://github.com/c-testsuite/c-testsuite */
int printf(const char *, ...);
char t[] = "012345678";

int main(void)
{
    char *data = t;
    unsigned long long r = 4;
    unsigned a = 5;
    unsigned long long b = 12;

    *(unsigned*)(data + r) += a - b;

    printf("data = \"%s\"\n", data);
    return 0;
}
/* ProgramSourceWild */
