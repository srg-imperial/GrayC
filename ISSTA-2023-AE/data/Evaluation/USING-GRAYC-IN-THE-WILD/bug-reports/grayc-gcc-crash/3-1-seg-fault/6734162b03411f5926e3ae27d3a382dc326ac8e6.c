struct {
  char a[0]
} b;
void main() { b.a[35184372088832] || b.a[1]; }
