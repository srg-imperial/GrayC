static int d, b, k;
static char c[];
static int e[];
static int *f = e;
static short h();
short h() {
  int *n = &b;
  char *o = &d;
  *n = ((&c == o) > 40, 1); /* HERE */
  return 0;
}
int main() { h(); }
