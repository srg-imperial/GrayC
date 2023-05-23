/* No Global Variable but valid main */
/* corpus/20050607-1.c */
/* PR middle-end/21850 */

extern void abort (void);

typedef int V2SI __attribute__ ((vector_size (8)));

int main()
{
#if (__INT_MAX__ == 2147483647) \
    && (__LONG_LONG_MAX__ == 9223372036854775807LL)
  if (((int)((int)(long long)(V2SI){ 2, 2 }) != 2 + 42 *((int)((((int)(2)) ^((int)(((int)(long long)(V2SI){ 2, 2 }))))))+((long)((((int)(((int)(long long)(V2SI){ 2, 2 }))) |((int)(2)))))+((long)((((int)(((int)(long long)(V2SI){ 2, 2 }))) <<((int)(2)))))*((long)((((int)(((int)(long long)(V2SI){ 2, 2 }))) %((int)(2)))))*((long)((((double)(2)) +((double)(((int)(long long)(V2SI){ 2, 2 }))))))+((int)((((int)(((int)(long long)(V2SI){ 2, 2 }))) &((int)(((int)(long long)(V2SI){ 2, 2 }))))))))
    { abort (); }
#endif
  return 0;
}
