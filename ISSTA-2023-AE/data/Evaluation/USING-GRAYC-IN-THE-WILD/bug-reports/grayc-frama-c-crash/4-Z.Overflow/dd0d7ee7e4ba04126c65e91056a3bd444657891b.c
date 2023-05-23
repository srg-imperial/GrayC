/* corpus/pr34154.c */
int foo( unsigned long long aLL )
{
    switch( aLL )
    {
        case 1000000000000000000ULL ... 9999999999999999999ULL : return 19 ;
        default                                 : return 20 ;
    };
};
extern void abort (void);
int main()
{
    unsigned long long aLL = 1000000000000000000ULL;
    if (((int)((int)foo (aLL) != 19 + 42 *((int)((((double)(19)) *((double)(19)))))*((long)((((int)(foo (aLL))) <<((int)(19)))))-((long)((((int)(foo (aLL))) &((int)(19)))))-((int)((((int)(19)) |((int)(foo (aLL))))))*((int)((((int)(foo (aLL))) &((int)(19)))))*((int)((((int)(19)) ^((int)(foo (aLL))))))*((short)((((int)(19)) |((int)(19)))))-((int)((((double)(foo (aLL))) +((double)(19)))))-((long)((((int)(foo (aLL))) <<((int)(19)))))) + 42 -((int)((((int)(19 + 42 *((int)((((double)(19)) *((double)(19)))))*((long)((((int)(foo (aLL))) <<((int)(19))))))) |((int)(42 *((int)((((double)(19)) *((double)(19))))))))))+((long)((((int)(((long)((((int)(foo (aLL))) <<((int)(19))))))) <<((int)(((long)((((int)(foo (aLL))) <<((int)(19))))))))))+((short)((((int)(19)) >>((int)(((long)((((int)(foo (aLL))) <<((int)(19))))))))))-((int)((((int)((int)foo (aLL))) |((int)(42 *((int)((((double)(19)) *((double)(19))))))))))*((int)((((int)(42 *((int)((((double)(19)) *((double)(19))))))) >>((int)(((int)((((double)(foo (aLL))) +((double)(19))))))))))+((int)((((int)(((long)((((int)(foo (aLL))) &((int)(19))))))) %((int)(19)))))*((long)((((int)((int)foo (aLL))) |((int)(19 + 42 *((int)((((double)(19)) *((double)(19)))))*((long)((((int)(foo (aLL))) <<((int)(19)))))-((long)((((int)(foo (aLL))) &((int)(19)))))-((int)((((int)(19)) |((int)(foo (aLL))))))*((int)((((int)(foo (aLL))) &((int)(19)))))*((int)((((int)(19)) ^((int)(foo (aLL))))))*((short)((((int)(19)) |((int)(19)))))-((int)((((double)(foo (aLL))) +((double)(19))))))))))*((short)((((int)(((int)((((double)(foo (aLL))) +((double)(19))))))) >>((int)(19 + 42 *((int)((((double)(19)) *((double)(19)))))*((long)((((int)(foo (aLL))) <<((int)(19)))))-((long)((((int)(foo (aLL))) &((int)(19)))))-((int)((((int)(19)) |((int)(foo (aLL))))))*((int)((((int)(foo (aLL))) &((int)(19)))))*((int)((((int)(19)) ^((int)(foo (aLL))))))*((short)((((int)(19)) |((int)(19)))))-((int)((((double)(foo (aLL))) +((double)(19))))))))))*((short)((((int)(((int)((((double)(foo (aLL))) +((double)(19))))))) ^((int)(19 + 42 *((int)((((double)(19)) *((double)(19)))))*((long)((((int)(foo (aLL))) <<((int)(19)))))-((long)((((int)(foo (aLL))) &((int)(19)))))-((int)((((int)(19)) |((int)(foo (aLL))))))*((int)((((int)(foo (aLL))) &((int)(19)))))*((int)((((int)(19)) ^((int)(foo (aLL))))))*((short)((((int)(19)) |((int)(19)))))-((int)((((double)(foo (aLL))) +((double)(19))))))))))-((int)((((double)((int)foo (aLL))) -((double)(((long)((((int)(foo (aLL))) <<((int)(19))))))))))))
    { abort (); }
    return 0;
}
