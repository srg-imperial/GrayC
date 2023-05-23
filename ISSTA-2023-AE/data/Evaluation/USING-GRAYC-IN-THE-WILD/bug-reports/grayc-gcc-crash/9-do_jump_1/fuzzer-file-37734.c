char a;
_Complex b;
void main() {}
void c() {
  if ((int)b != -130 || a != 70 + (b != 0 ^ (int)b))
    abort();
}
