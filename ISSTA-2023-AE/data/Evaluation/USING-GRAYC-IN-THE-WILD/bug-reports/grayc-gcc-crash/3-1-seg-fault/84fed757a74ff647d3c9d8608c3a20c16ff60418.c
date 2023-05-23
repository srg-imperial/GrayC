typedef unsigned a[];
a *b;
void c() { (*b)[1073741824] || (*b)[1]; }
void main() {}
