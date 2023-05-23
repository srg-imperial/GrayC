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
  if (a.u33 * a.u33 != (-1) || a.u33 * a.u40 != (-1) || a.u40 * a.u33 != (-1)
      || a.u40 * a.u40 != (-1))
    abort ();
  if (a.u33 * a.u41 != (0)
      || a.u40 * a.u41 != (0)
      || a.u41 * a.u33 != (0)
      || a.u41 * a.u40 != (0)
      || a.u41 * a.u41 != (0))
    abort ();
  if (b.u33 + b.u33 != (-1))
    abort ();
  if (b.u33 + b.u40 != (0)
      || b.u33 + b.u41 != (0)
      || b.u40 + b.u33 != (0)
      || b.u40 + b.u40 != (0)
      || b.u40 + b.u41 != (0)
      || b.u41 + b.u33 != (0)
      || b.u41 + b.u40 != (0)
      || b.u41 + b.u41 != (0))
    abort ();
  if (a.u33 - b.u33 != (0)
      || a.u33 - b.u40 != (0)
      || a.u33 - b.u41 != (0)
      || a.u40 - b.u33 != (0)
      || a.u40 - b.u40 != (0)
      || a.u40 - b.u41 != (0)
      || a.u41 - b.u33 != (0)
      || a.u41 - b.u40 != (0)
      || a.u41 - b.u41 != (0))
    abort ();
  if (++c.u33 != (-1) || --c.u40 != (0) || c.u41-- != (-1))
    abort ();
  exit ((-1));
}
