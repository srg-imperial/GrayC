/* corpus/Floyds_triangle.c */
/* https://www.programiz.com/c-programming/examples/pyramid-pattern */
#include <stdio.h>
int main() {
   int rows=18, i, j, number = 1;
   for (i = 1; i <= rows; i++) {
      for (j = 1; j <= i; ++j) {
         printf("%d ", number);
         ++number;
      }
      printf("\n");
   }
   return 0;
}
/* ProgramSourceWild */
