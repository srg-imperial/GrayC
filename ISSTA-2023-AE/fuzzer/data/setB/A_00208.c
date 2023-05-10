/* corpus/00208.c */
/* Taken from: https://github.com/c-testsuite/c-testsuite */
#include <stdio.h>
struct wchar {
    char *data; char mem[1];
};
struct wint {
    char *data; int mem[1];
};
int f1char (void) {
    char s[9]="nonono";
    struct wchar q = {"bugs"};
    return !s[0];
}
int f1int (void) {
    char s[9]="nonono";
    struct wint q = {"bugs"};
    return !s[0];
}
int main (void) {
   char s[9]="nonono";
   static struct wchar q = {"bugs", {'c'}};
   //printf ("tcc has %s %s\n", s, q.data);
   if (f1char() || f1int())
     printf ("bla\n");
   return !s[0];
}
/* ProgramSourceWild */
