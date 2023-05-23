typedef enum { e } f;
struct {
  f __attribute__((mode(__byte__))) a;
  f __attribute__((mode(__byte__))) b;
  f __attribute__((mode(__byte__))) c;
  f __attribute__((mode(__byte__))) d
} g[];
void main() { g[0].b = (g[0].b & g[4].b) * g[2305843009213693952].c; }
