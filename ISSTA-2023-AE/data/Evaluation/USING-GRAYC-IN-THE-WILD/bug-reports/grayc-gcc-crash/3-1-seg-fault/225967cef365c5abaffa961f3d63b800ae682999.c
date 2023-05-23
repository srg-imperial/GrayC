struct {
  char a[0]
} b;
void main() { b.a[536870912] || b.a[1]; }
