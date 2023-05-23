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
    if (((int)foo (aLL) != 19 + 42 -((int)((((int)(19)) >>((int)(19)))))-((long)((((double)(19)) +((double)(19)))))*((int)((((int)(foo (aLL))) <<((int)(19)))))+((int)((((double)(foo (aLL))) -((double)(foo (aLL))))))-((int)((((int)(foo (aLL))) %((int)(19)))))-((int)((((double)(foo (aLL))) +((double)(foo (aLL))))))))
	abort ();
    return 0;
}
