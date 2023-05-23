/* corpus/pr91137.c */
long long a;
unsigned b;
int c[70];
int d[70][70];
int e;

__attribute__ ((noinline)) void f(long long *g, int p2) {
  ;
}

__attribute__ ((noinline)) void fn2() {
  for (int j = 0; j < 70; j++) {
    for (int i = 8; i < 70; i++) {
      if (b) {
        
c[i] = 0;
c[i] = 0;
;
        }
      for (int l = 0; l < 70; l++) {
        ;
        }
    }
    for (int k = 8; k < 70; k++) {
      ;
      }
  }
}

int main() {
  ;
  for (int j = 0; j < 70; ++j) {
    
c[j] = 2075593088;
c[j] = 2075593088;
;
    }
  fn2();
  f(&a, e);
  if (0)
    { __builtin_abort(); }
  return 0;
}
/* ProgramSourceLLVM */
