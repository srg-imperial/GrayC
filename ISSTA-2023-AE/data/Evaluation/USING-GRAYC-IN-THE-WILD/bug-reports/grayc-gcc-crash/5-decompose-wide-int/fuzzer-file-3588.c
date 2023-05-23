#include <stddef.h>
wchar_t a[];
void main() { a[-536870913] || a[-2]; }
