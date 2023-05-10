/* corpus/multiplication-table.c */
/* Taken from: https://www.programiz.com/c-programming/examples/multiplication-table */
#include <stdio.h>
int main() {
  int n, i;
  printf("Enter an integer: ");
  scanf("%d", &n);
  for (i = 1; i <= 10; ++i) {
    printf("%d * %d = %d \n", n, i, n * i);
  }
  return 0;
}/* ProgramSourceWild */
