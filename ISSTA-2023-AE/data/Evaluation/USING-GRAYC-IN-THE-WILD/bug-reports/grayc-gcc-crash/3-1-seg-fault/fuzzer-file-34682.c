struct {
  char a[0]
} b;
void main() { b.a[2251799813685248] || b.a[1]; }
