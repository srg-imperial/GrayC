/* corpus/00186.c */
/* Taken from: https://github.com/c-testsuite/c-testsuite */
#include <stdio.h>

int main()
{
   char Buf[100];
   int Count;

   for (Count = 1; Count <= 20; Count++)
   {
      sprintf(Buf, "->%02d<-\n", Count);
      printf("%s", Buf);
   }

   return 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/
/* ProgramSourceWild */
