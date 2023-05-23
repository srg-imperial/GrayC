int a, b;
void c() {
  b = b + (((unsigned char *)a)[-1] - ((unsigned *)a)[5]) |
      ((unsigned *)a)[0] + ((char *)a)[0] % b +
          ((unsigned char *)a)[9223372036854775808];
}
void main() {}
