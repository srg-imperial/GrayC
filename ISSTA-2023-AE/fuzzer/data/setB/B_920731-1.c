/* corpus/920731-1.c */
f(x){int i;for(i=0;i<8&&(x&1)==0;x>>=1,i++);return i;}
main(){if(f(4)!=2){ abort(); }exit(0);}
/* ProgramSourceLLVM */
