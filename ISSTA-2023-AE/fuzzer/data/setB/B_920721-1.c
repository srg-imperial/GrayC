/* corpus/920721-1.c */
long f(short a,short b){return (long)a/b;}
main(){if(f(-32768,-1)!=32768L){ abort(); }else exit(0);}
/* ProgramSourceLLVM */
