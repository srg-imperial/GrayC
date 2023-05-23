#include <stdarg.h>
long a;
void b(va_list ap) {
  a = va_arg(ap, double);
  a += va_arg(ap, long);
}
void c(int d, ...) {
  va_list ap;
  va_start(ap, d);
  b(ap);
}
void main() { c(0, 8.1, 7.1); }
