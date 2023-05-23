void main() {
  struct {
    int a;
    char b[0]
  } c;
  c.b[65002] || c.b[65003];
}
