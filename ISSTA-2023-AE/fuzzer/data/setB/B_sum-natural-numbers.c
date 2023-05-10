/* corpus/sum-natural-numbers.c */
/* Taken from: https://www.programiz.com/c-programming/examples/sum-natural-numbers */
#include <stdio.h>
int main() {
    int n, i, sum = 0;

    printf("Enter a positive integer: ");
    scanf("%d", &n);

    for (i = 1; i <= n; ++i) {
        sum += i;
    }

    printf("Sum = %d", sum);
    return 0;
}/* ProgramSourceWild */
