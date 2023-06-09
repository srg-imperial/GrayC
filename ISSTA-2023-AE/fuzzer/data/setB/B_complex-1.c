/* corpus/B_complex-1.c */
/* Test for builtin conj, creal, cimag.  */
/* Origin: Joseph Myers <jsm28@cam.ac.uk> */

extern float _Complex conjf (float _Complex);
extern double _Complex conj (double _Complex);
extern long double _Complex conjl (long double _Complex);

extern float crealf (float _Complex);
extern double creal (double _Complex);
extern long double creall (long double _Complex);

extern float cimagf (float _Complex);
extern double cimag (double _Complex);
extern long double cimagl (long double _Complex);

extern void abort (void);
extern void link_error (void);

void
main_test (void)
{
  /* For each type, test both runtime and compile time (constant folding)
     optimization.  */
  volatile float _Complex fc = 1.0F + 2.0iF;
  volatile double _Complex dc = 1.0 + 2.0i;
  volatile long double _Complex ldc = 1.0L + 2.0iL;
  /* Test floats.  */
  if (conjf (fc) != 1.0F - 2.0iF)
    abort ();
  if (__builtin_conjf (fc) != 1.0F - 2.0iF)
    abort ();
  if (conjf (1.0F + 2.0iF) != 1.0F - 2.0iF)
    link_error ();
  if (__builtin_conjf (1.0F + 2.0iF) != 1.0F - 2.0iF)
    link_error ();
  if (crealf (fc) != 1.0F)
    abort ();
  if (__builtin_crealf (fc) != 1.0F)
    abort ();
  if (crealf (1.0F + 2.0iF) != 1.0F)
    link_error ();
  if (__builtin_crealf (1.0F + 2.0iF) != 1.0F)
    link_error ();
  if (cimagf (fc) != 2.0F)
    abort ();
  if (__builtin_cimagf (fc) != 2.0F)
    abort ();
  if (cimagf (1.0F + 2.0iF) != 2.0F)
    link_error ();
  if (__builtin_cimagf (1.0F + 2.0iF) != 2.0F)
    link_error ();
  /* Test doubles.  */
  if (conj (dc) != 1.0 - 2.0i)
    abort ();
  if (__builtin_conj (dc) != 1.0 - 2.0i)
    abort ();
  if (conj (1.0 + 2.0i) != 1.0 - 2.0i)
    link_error ();
  if (__builtin_conj (1.0 + 2.0i) != 1.0 - 2.0i)
    link_error ();
  if (creal (dc) != 1.0)
    abort ();
  if (__builtin_creal (dc) != 1.0)
    abort ();
  if (creal (1.0 + 2.0i) != 1.0)
    link_error ();
  if (__builtin_creal (1.0 + 2.0i) != 1.0)
    link_error ();
  if (cimag (dc) != 2.0)
    abort ();
  if (__builtin_cimag (dc) != 2.0)
    abort ();
  if (cimag (1.0 + 2.0i) != 2.0)
    link_error ();
  if (__builtin_cimag (1.0 + 2.0i) != 2.0)
    link_error ();
  /* Test long doubles.  */
  if (conjl (ldc) != 1.0L - 2.0iL)
    abort ();
  if (__builtin_conjl (ldc) != 1.0L - 2.0iL)
    abort ();
  if (conjl (1.0L + 2.0iL) != 1.0L - 2.0iL)
    link_error ();
  if (__builtin_conjl (1.0L + 2.0iL) != 1.0L - 2.0iL)
    link_error ();
  if (creall (ldc) != 1.0L)
    abort ();
  if (__builtin_creall (ldc) != 1.0L)
    abort ();
  if (creall (1.0L + 2.0iL) != 1.0L)
    link_error ();
  if (__builtin_creall (1.0L + 2.0iL) != 1.0L)
    link_error ();
  if (cimagl (ldc) != 2.0L)
    abort ();
  if (__builtin_cimagl (ldc) != 2.0L)
    abort ();
  if (cimagl (1.0L + 2.0iL) != 2.0L)
    link_error ();
  if (__builtin_cimagl (1.0L + 2.0iL) != 2.0L)
    link_error ();
}
/* ProgramSourceLLVM */
