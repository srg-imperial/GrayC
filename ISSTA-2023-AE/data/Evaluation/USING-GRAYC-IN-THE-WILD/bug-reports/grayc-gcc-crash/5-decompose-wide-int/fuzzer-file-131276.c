#include <stddef.h>
wchar_t a[];
void main() { a[4503599627370496] || a[1]; }
