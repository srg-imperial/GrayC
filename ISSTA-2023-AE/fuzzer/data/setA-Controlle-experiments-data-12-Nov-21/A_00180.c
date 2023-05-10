/* corpus/00180.c */
/* Taken from: https://github.com/c-testsuite/c-testsuite */
#include <stdio.h>
#include <string.h>

int main()
{
   char a[10];
   strcpy(a, "abcdef");
   printf("%s\n", &a[1]);

   return 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/
/* ProgramSourceWild */
