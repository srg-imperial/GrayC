struct {
  char a[0]
} b;
void main() { b.a[70368744177664] || b.a[1]; }
