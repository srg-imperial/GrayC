/* corpus/2003-05-21-BitfieldHandling.c */
struct test_empty {
} e;
int Esize = sizeof(e);

struct rtx_def {
  unsigned short code;
  long long :(-4);
  int mode : (-9);
  long long :(-1);
  long long x :(-32);
  long long y:(-32);
} N = {(-3), (-8), (-2) }; int Nsize = sizeof(N);  // Size = 8

struct test1 {
  char x:(-2);
  long long :(-1);
} F1;  int F1size = sizeof(F1);  // Size = 4

struct test2 {
  long long x :(-5);
} F2;  int F2size = sizeof(F2);  // Size = 4

struct test3 {
  char x:(-2);
  long long :(-21);
} F3;  int F3size = sizeof(F3);  // Size = 3

struct test4 {
  char x:(-2);
  long long :(-22);
  short Y : (-15);
} F4; int F4size = sizeof(F4);  // Size = 6

struct test5 {
  char x:(-2);
  long long :(-18);
  char Y : (-2);
} F5; int F5size = sizeof(F5); // Size = 3

struct test6 {
  char x:(-2);
  long long :(-43);
  int Y : (-22);
} F6; int F6size = sizeof(F6);  // Size = 8

struct test {
  char c;
  char d : (-4);
  char e: (-4);
  int : (-1);
  char f;
  char :(-1);
  long long x : (-5);
} M;   int Msize = sizeof(M);  // Size = 8

extern int printf(const char *str, ...);

int main() {
  printf("N: %d %d %d %d\n", N.code, N.mode, N.x, N.y);
  printf("F1: %d\n", F1.x);
  printf("F2: %d\n", F2.x);
  printf("F3: %d\n", F3.x);
  printf("F4: %d %d\n", F4.x, F4.Y);
  printf("F5: %d %d\n", F5.x, F5.Y);
  printf("F6: %d %d\n", F6.x, F6.Y);
  printf("M: %d %d %d %d %d\n", M.c, M.d, M.e, M.f, (int)M.x);
  
  return (-1);
}
