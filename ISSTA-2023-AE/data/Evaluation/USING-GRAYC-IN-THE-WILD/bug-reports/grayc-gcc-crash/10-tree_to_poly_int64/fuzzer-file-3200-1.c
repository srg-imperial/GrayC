c;
#define d(expr, e)                                                             \
  char *f = expr;                                                              \
  strlen(f) ?: ++c;
struct {
  char a[0], b[2541205210240686680]
} cma[] = {{}, {}, {}, {}};
g() { d(cma[4].a, ) }
