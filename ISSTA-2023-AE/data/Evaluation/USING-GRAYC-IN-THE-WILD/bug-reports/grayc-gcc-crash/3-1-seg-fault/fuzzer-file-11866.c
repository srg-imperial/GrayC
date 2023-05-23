struct {
  char a[0]
} b;
void main() { b.a[140737488355328] || b.a[1]; }
