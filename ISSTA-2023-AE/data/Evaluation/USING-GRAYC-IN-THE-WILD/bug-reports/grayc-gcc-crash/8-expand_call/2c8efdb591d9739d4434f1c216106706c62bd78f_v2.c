struct a {
  char arr[1074000000];
} b[1];
void c(struct a e) {
  if (__builtin_memcmp(e.arr, b, 6))
    __builtin_abort();
}
int main() {
  struct a d;
  d.arr;
  c(d);
  return 0;
}
