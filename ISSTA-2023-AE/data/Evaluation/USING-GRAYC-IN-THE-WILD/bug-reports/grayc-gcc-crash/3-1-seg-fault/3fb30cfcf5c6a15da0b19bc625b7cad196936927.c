typedef struct {
  char a[0]
} b;
b c;
d() { c.a[72057594037927936] || c.a[1]; }
main() {}
