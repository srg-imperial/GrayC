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
void main() { c(0, 5.2, 9.2); }
