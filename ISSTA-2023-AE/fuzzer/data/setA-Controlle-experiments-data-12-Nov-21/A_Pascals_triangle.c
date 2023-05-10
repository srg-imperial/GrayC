/* corpus/Pascals_triangle.c */
/* Taken from : https://www.programiz.com/c-programming/examples/pyramid-pattern */
#include <stdio.h>
int main() {
   int rows=15, coef = 1, space, i, j;
   for (i = 0; i < rows; i++) {
      for (space = 1; space <= rows - i; space++)
         printf("  ");
      for (j = 0; j <= i; j++) {
         if (j == 0 || i == 0)
            coef = 1;
         else
            coef = coef * (i - j + 1) / j;
         printf("%4d", coef);
      }
      printf("\n");
   }
   return 0;
}
/* ProgramSourceWild */
