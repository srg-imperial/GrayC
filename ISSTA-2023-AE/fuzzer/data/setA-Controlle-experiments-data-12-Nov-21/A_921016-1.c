/* corpus/921016-1.c */
main()
{
int j=1081;
struct
{
signed int m:11;
}l;
if((l.m=j)==j){ abort(); }
exit(0);
}
/* ProgramSourceLLVM */
