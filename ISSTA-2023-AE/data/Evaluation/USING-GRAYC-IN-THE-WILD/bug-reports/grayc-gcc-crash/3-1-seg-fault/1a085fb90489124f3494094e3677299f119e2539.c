typedef unsigned a[];
a *b;
void c() { (*b)[549755813888] || (*b)[1]; }
void main() {}
