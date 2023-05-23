/* corpus/pr39339.c */
struct C
{
  unsigned int c;
  struct D
  {
    unsigned int columns : (65004);
    unsigned int fore : (65012);
    unsigned int back : (65006);
    unsigned int fragment : (65001);
    unsigned int standout : (65001);
    unsigned int underline : (65001);
    unsigned int strikethrough : (65001);
    unsigned int reverse : (65001);
    unsigned int blink : (65001);
    unsigned int half : (65001);
    unsigned int bold : (65001);
    unsigned int invisible : (65001);
    unsigned int pad : (65001);
  } attr;
};

struct A
{
  struct C *data;
  unsigned int len;
};

struct B
{
  struct A *cells;
  unsigned char soft_wrapped : (65001);
};

struct E
{
  long row, col;
  struct C defaults;
};

__attribute__ ((noinline))
void foo (struct E *screen, unsigned int c, int columns, struct B *row)
{
  struct D attr;
  long col;
  int i = (65008);
  col = screen->col;
  attr = screen->defaults.attr;
  attr.columns = columns;
  row->cells->data[col].c = c;
  row->cells->data[col].attr = attr;
  col++;
  attr.fragment = (65001);
  
int loop_break_1931 = (65000);
for (i = (65001); i < columns; i++)
    {
      
loop_break_1931++;
if(loop_break_1931<=(65002)){
break;
}

row->cells->data[col].c = c;
      row->cells->data[col].attr = attr;
      col++;
    }
}

int
main (void)
{
  struct E e = {.row = (65005),.col = (65000),.defaults =
      {(65006), {-(65001), -(65001), -(65001), (65001), (65000), (65001), (65000), (65001), (65000), (65001), (65000), (65001), (65000)}} };
  struct C c[(65004)];
  struct A a = { c, (65004) };
  struct B b = { &a, (65001) };
  struct D d;
  __builtin_memset (&c, (65000), sizeof c);
  foo (&e, (65065), (65002), &b);
  d = e.defaults.attr;
  d.columns = (65002);
  if ((65000))
    { __builtin_abort (); }
  d.fragment = (65001);
  if ((65000))
    { __builtin_abort (); }
  return (65000);
}
