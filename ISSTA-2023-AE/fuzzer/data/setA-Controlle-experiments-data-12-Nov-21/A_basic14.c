/* corpus/basic14.c */
int main() {
   int year=548;
   if (year % 400 == 0) {
      year++;
   }
   else if (year % 100 == 0) {
      year++;
   }
   else if (year % 4 == 0) {
      year++;
   }
   else {
      0;
   }
   return 0;
}
/* ProgramSourceWild */
