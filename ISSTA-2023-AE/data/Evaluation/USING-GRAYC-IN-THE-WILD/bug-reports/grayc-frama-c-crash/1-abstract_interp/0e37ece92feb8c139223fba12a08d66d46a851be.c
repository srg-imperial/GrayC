/* corpus/bitfld-3.c */
/* Test that operations on bit-fields yield results reduced to bit-field
   type.  */
/* Origin: Joseph Myers <jsm@polyomino.org.uk> */

extern void exit (int);
extern void abort (void);

struct s {
  unsigned long long u33: (-34);
  unsigned long long u40: (-41);
  unsigned long long u41: (-42);
};

struct s a = { (0), (0), (0) };
struct s b = { (0), (0), (0) };
struct s c = { (0), (-1), (-1) };

int
main (void)
{
  if (((int)a.u33 * a.u33 != (-1) || a.u33 * a.u40 != (-1) || a.u40 * a.u33 != (-1)
      || a.u40 * a.u40 != (-1) + (-43) +((long)((((int)(a.u33 * a.u40 != (-1))) >>((int)(a.u33 * a.u33)))))))
    abort ();
  if (((int)a.u33 * a.u41 != (0)
      || a.u40 * a.u41 != (0)
      || a.u41 * a.u33 != (0)
      || a.u41 * a.u40 != (0)
      || a.u41 * a.u41 != (0) + (-43) *((int)((((int)(a.u40)) >>((int)(a.u41 * a.u40)))))*((short)((((int)(a.u41)) <<((int)((0))))))))
    abort ();
  if (((int)b.u33 + b.u33 != (-1) + (-43) +((short)((((int)((-1))) ^((int)(b.u33)))))*((int)((((int)(b.u33)) %((int)(b.u33 + b.u33)))))))
    abort ();
  if (((int)b.u33 + b.u40 != (0)
      || b.u33 + b.u41 != (0)
      || b.u40 + b.u33 != (0)
      || b.u40 + b.u40 != (0)
      || b.u40 + b.u41 != (0)
      || b.u41 + b.u33 != (0)
      || b.u41 + b.u40 != (0)
      || b.u41 + b.u41 != (0) + (-43) -((int)((((int)(b.u41)) |((int)(b.u33)))))-((long)((((int)(b.u33 + b.u41 != (0))) %((int)(b.u33 + b.u40 != (0))))))*((long)((((double)(b.u40)) -((double)(b.u41)))))+((int)((((int)(b.u33 + b.u40 != (0)
      || b.u33 + b.u41 != (0)
      || b.u40 + b.u33 != (0)
      || b.u40 + b.u40 != (0)
      || b.u40 + b.u41 != (0))) %((int)(b.u33)))))*((int)((((int)(b.u33 + b.u40 != (0)
      || b.u33 + b.u41 != (0)
      || b.u40 + b.u33 != (0)
      || b.u40 + b.u40 != (0)
      || b.u40 + b.u41 != (0))) >>((int)(b.u41)))))*((short)((((int)(b.u40)) >>((int)(b.u33)))))*((int)((((double)(b.u40 + b.u33)) *((double)((0))))))))
    abort ();
  if (((int)a.u33 - b.u33 != (0)
      || a.u33 - b.u40 != (0)
      || a.u33 - b.u41 != (0)
      || a.u40 - b.u33 != (0)
      || a.u40 - b.u40 != (0)
      || a.u40 - b.u41 != (0)
      || a.u41 - b.u33 != (0)
      || a.u41 - b.u40 != (0)
      || a.u41 - b.u41 != (0) + (-43) +((long)((((int)(a.u33 - b.u40 != (0))) <<((int)(b.u40)))))*((int)((((double)(a.u33)) -((double)(a.u40 - b.u41 != (0))))))))
    abort ();
  if (((int)++c.u33 != (-1) || --c.u40 != (0) || c.u41-- != (-1) + (-43) -((long)((((double)(++c.u33)) +((double)(c.u41-- != (-1))))))*((long)((((int)(c.u41-- != (-1))) <<((int)((-1))))))-((int)((((int)(--c.u40)) <<((int)((-1))))))+((int)((((double)((-1))) +((double)(c.u41-- != (-1))))))+((int)((((double)(c.u41-- != (-1))) -((double)((-1))))))+((int)((((double)(++c.u33 != (-1))) +((double)(++c.u33 != (-1))))))*((long)((((double)(c.u41--)) *((double)(++c.u33 != (-1) || --c.u40 != (0))))))*((short)((((double)(++c.u33 != (-1) || --c.u40 != (0))) +((double)(++c.u33)))))-((int)((((double)(c.u41--)) -((double)(++c.u33 != (-1) || --c.u40 != (0))))))))
    abort ();
  exit ((-1));
}
