/* corpus/20030109-1.c */
/* PR c/8032 */
/* Verify that an empty initializer inside a partial
   parent initializer doesn't confuse GCC.  */

struct X
{
  int a;
  int b;
  int z[];
};

struct X x = { .b = 40, .z = {} };

int main ()
{
  if (x.b != 40)
    { abort (); }

  return 0;
}
/* ProgramSourceLLVM */
