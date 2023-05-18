// COVERAGE: llvm-project/clang/include/clang/AST/EvaluatedExprVisitor.h (1 new functions)
// COVERAGE: llvm-project/clang/lib/AST/ComputeDependence.cpp (1 new functions)
// COVERAGE: llvm-project/clang/lib/AST/Expr.cpp (2 new functions)
// COVERAGE: llvm-project/clang/lib/CodeGen/CGExprScalar.cpp (1 new functions)
// COVERAGE: llvm-project/clang/lib/Parse/ParseExpr.cpp (1 new functions)
// COVERAGE: llvm-project/clang/lib/Sema/SemaExpr.cpp (2 new functions)
#include <stdio.h>
typedef int (*fptr)(int);
int foo(int i) { return i; }
int main() {
  int b = _Generic(foo, fptr : 3, int : 4);
  printf("%d\n", b);
  return 0;
}
