/* corpus/921007-1.c */
static int strcmp(){return-1;}
#define strcmp __builtin_strcmp
main()
{
if(strcmp("X","X\376")>=0){ abort(); }
exit(0);
}
/* ProgramSourceLLVM */
