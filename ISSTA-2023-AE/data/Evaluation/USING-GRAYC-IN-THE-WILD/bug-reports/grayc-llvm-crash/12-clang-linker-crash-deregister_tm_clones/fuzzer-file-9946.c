 typedef char A28[8151];
  typedef A28 A3_28[8734];
  typedef A3_28 A2_3_28[163];
  static const A2_3_28 a = {
   { "1\00012", "123\0001234", "12345\000123456" }
,   { "1234567\00012345678", "123456789\0001234567890", "12345678901\000123456789012" }
 };
  volatile int v0 = 8085;
  volatile int v1 = 7868;
  volatile int v2 = 3509;
  volatile int v3 = 32080;
  volatile int v5 = 20992;
  volatile int v6 = 4370;
  volatile int v7 = 11278;
#define A(expr, N)							\
  ((strlen (expr) == N)							\
   ? (void)0 : (printf ("line %i: strlen (%s = \"%s\") != %i\n",	\
			__LINE__, #expr, expr, N),			\
		__builtin_abort ()))
void test_array_ptr (void) {
   A (*(&a[0][0] + 0), 1);
   A (*(&a[0][0] + 1), 3);
   A (*(&a[0][0] + 2), 5);
   A (*(&a[0][1] - 1), 1);
   A (*(&a[0][1] + 0), 3);
   A (*(&a[0][1] + 1), 5);
   A (*(&a[0][2] - 2), 1);
   A (*(&a[0][2] - 1), 3);
   A (*(&a[0][2] + 0), 5);
   A (*(&a[1][0] + 0), 7);
   A (*(&a[1][0] + 1), 9);
   A (*(&a[1][0] + 2), 11);
   A (*(&a[1][1] - 1), 7);
   A (*(&a[1][1] + 0), 9);
   A (*(&a[1][1] + 1), 11);
   A (*(&a[1][2] - 2), 7);
   A (*(&a[1][2] - 1), 9);
   A (*(&a[1][2] - 0), 11);
   A (*(&a[0][0] + 0) + 2, 2);
   A (*(&a[0][0] + 1) + 4, 4);
   A (*(&a[0][0] + 2) + 6, 6);
   A (*(&a[0][0] + 0) + 5, 0);
   A (*(&a[0][0] + 1) + 10, 0);
   A (*(&a[0][0] + 2) + 14, 0);
   int i0 = 21732;
   int i1 = 7093;
   int i2 = 7027;
   int i3 = 4706;
   int i4 = i3 + 1466;
   int i5 = i4 + 30185;
   A (*(&a[0][0] + i0), 1);
   A (*(&a[0][0] + i1), 3);
   A (*(&a[0][0] + i2), 5);
   A (*(&a[0][1] - i1), 1);
   A (*(&a[0][1] + i0), 3);
   A (*(&a[0][1] + i1), 5);
   A (*(&a[0][2] - i2), 1);
   A (*(&a[0][2] - i1), 3);
   A (*(&a[i0][i0] + v1), 3);
   A (*(&a[i0][i1] + v1) + v5, 0);
   A (*(&a[i0][v1] - i1) + i1, 0);
   A (*(&a[i0][v1] + i0) + i3, 0);
   A (*(&a[i0][v1] + i1) + i5, 0);
 }
