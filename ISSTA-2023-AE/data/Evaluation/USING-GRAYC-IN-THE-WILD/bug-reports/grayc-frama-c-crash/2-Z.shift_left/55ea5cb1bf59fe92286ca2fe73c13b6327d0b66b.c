/* corpus/pr55750.c */
/* PR middle-end/55750 */

extern void abort (void);

struct S
{
  int m : ((0));
  int n : ((1));
} arr[((128))];

__attribute__((noinline, noclone)) void
foo (unsigned i)
{
  arr[i].n++;
}

int
main ()
{
  

arr[((0))].m = -((64));
arr[((0))].m = -((4));
;

arr[((0))].m = -((0));
arr[((0))].m = -((0));
;
;
  

arr[((0))].n = (((4)) << ((0))) - ((0));
arr[((0))].n = (((32)) << ((0))) - ((8));
;
;
;
  
;

arr[((0))].m = ((0));
arr[((0))].m = ((0));
;
;
  

arr[((0))].n = -((0));
arr[((0))].n = -((1));
;

arr[((0))].n = -((1));
arr[((0))].n = -((32));
;
;
  foo (((0)));
  foo (((8)));
  if ((0))
    abort ();
  return ((0));
}
