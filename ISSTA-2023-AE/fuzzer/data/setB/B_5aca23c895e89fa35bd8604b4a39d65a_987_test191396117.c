/* corpus/5aca23c895e89fa35bd8604b4a39d65a_987_test191396117.c */
struct a {
  signed b : 2;
};
static volatile struct a c;
int main() { printf("%d\n", c.b); }
/* ProgramSourceCsmithReduce */
