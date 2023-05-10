/* corpus/octal-binary-convert.c */
/* Taken from: https://www.programiz.com/c-programming/examples/octal-binary-convert */

#include <math.h>
#include <stdio.h>
long long convert(int oct);
int main() {
    int oct;
    printf("Enter an octal number: ");
    scanf("%d", &oct);
    printf("%d in octal = %lld in binary", oct, convert(oct));
    return 0;
}

long long convert(int oct) {
    int dec = 0, i = 0;
    long long bin = 0;

    // converting octal to decimal
    while (oct != 0) {
        dec += (oct % 10) * pow(8, i);
        ++i;
        oct /= 10;
    }
    i = 1;

   // converting decimal to binary
    while (dec != 0) {
        bin += (dec % 2) * i;
        dec /= 2;
        i *= 10;
    }
    return bin;
}
/* ProgramSourceWild */
