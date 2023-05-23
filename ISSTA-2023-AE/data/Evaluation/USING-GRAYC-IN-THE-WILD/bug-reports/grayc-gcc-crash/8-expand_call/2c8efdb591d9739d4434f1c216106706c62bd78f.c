struct a {
  char arr[6151711744]
} b[];
void c(struct a e) {
  if (__builtin_memcmp(e.arr, b, 6))
    __builtin_abort();
}
void main() {
  struct a d;
  d.arr;
  c(d);
}
