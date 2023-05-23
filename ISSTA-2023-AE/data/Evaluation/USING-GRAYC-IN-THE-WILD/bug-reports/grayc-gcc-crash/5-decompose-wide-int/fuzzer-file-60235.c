struct {
  int a;
  char b[]
} a;
void main() { a.a != 0 | a.b[-4398046511105] != 0; }
