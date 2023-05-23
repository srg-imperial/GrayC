struct {
  long a
} b, *c;
void main() {
  c = &b;
  while (++c > &b)
    c->a = 1;
}
