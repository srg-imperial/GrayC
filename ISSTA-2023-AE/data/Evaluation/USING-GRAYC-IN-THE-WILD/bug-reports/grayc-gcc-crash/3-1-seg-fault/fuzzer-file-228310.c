struct {
  unsigned a[0]
} b;
c() { b.a[281474976710656] == 0 & b.a[1] == 1; }
main() {}
