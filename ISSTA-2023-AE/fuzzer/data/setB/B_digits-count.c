/* corpus/digits-count.c */
/* Taken from: https://www.programiz.com/c-programming/examples/digits-count */
#include <stdio.h>
int main() {
    long long n;
    int count = 0;
    printf("Enter an integer: ");
    scanf("%lld", &n);
 
    // iterate until n becomes 0
    // remove last digit from n in each iteration
    // increase count by 1 in each iteration
    while (n != 0) {
        n /= 10;     // n = n/10
        ++count;
    }

    printf("Number of digits: %d", count);
}/* ProgramSourceWild */
