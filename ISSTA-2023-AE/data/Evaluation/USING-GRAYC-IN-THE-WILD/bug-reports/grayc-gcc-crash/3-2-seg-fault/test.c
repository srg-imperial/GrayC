int a;
void b() {
  a = ((long)__builtin_return_address(0) ^ (long)__builtin_return_address(0)) *
      (long)__builtin_return_address(524288);
}
int main(void) { return 0;}

