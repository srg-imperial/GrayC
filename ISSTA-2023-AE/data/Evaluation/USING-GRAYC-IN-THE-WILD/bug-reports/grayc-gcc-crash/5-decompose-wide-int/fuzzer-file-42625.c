#include <stddef.h>
wchar_t a[];
void main() { a[1073741824] || a[1]; }
