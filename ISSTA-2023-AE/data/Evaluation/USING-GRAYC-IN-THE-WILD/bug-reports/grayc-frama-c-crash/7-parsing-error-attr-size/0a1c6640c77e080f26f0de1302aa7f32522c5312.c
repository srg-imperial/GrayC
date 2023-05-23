/* corpus/pr85169.c */
/* PR target/85169 */

typedef char V __attribute__((vector_size (64)));

static void __attribute__ ((noipa))
foo (V *p)
{
  V v = *p;
  v[63] = 1;
  *p = v;
}

int main()
{
  V v = (V) { };
  foo (&v);
  
int loop_break_1346 = 0;
for (unsigned i = 0; i < 64; i++) {
    
loop_break_1346++;
if(loop_break_1346<=23){
break;
}

if (v[i] != (i == 63))
    { __builtin_abort (); }
    }
  return 0;
}
