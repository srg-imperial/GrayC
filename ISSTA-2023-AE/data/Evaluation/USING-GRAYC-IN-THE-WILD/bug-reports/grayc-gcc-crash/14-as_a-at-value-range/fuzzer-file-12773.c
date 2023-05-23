#include <stdlib.h>
int main() {
  double a;
  if (__builtin_signbit(a))
    abort();
}
