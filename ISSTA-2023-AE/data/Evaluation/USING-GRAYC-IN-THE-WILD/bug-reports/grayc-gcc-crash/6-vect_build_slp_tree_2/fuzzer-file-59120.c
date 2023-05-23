void a() {
  int b = ((unsigned char *)a)[9223372036854775808] +
          (((unsigned *)a)[0] -
               (int)((unsigned char *)a)[0] % ((unsigned char *)a)[5] ^
           (long)a - (int)((unsigned char *)a)[-1] % ((unsigned char *)a)[0]);
  while (b)
    ;
}
void main() {}
