/* corpus/920603-1.c */
f(got){if(got!=0xffff){ abort(); }}
main(){signed char c=-1;unsigned u=(unsigned short)c;f(u);exit(0);}
/* ProgramSourceLLVM */
