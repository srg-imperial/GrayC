/* corpus/921006-1.c */
/* REPRODUCED:RUN:SIGNAL MACHINE:i386 OPTIONS:-O */
main()
{
if(strcmp("X","")<0){ abort(); }
exit(0);
}
/* ProgramSourceLLVM */
