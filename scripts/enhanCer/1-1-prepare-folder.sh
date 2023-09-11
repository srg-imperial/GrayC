#!/bin/bash
## Parameters:
sourceFolder=$1					## /home/user42/dailydump/*.c
skip=$2						## to skip original test-cases? 1-yes
skipFiles=$3					## skip_me.log

## Check we have process number
if [ -z "$1" ]
  then
	echo "No source folder supplied."
	exit 1
fi

## Run for all programs in folder:
# rm -f $sourceFolder/*.c 	## Only for opimization
rm -f $sourceFolder/*.zip

## Shall we skip it? (original code)
if [[ "$skip" -eq "1" ]] ; then
	for p in $sourceFolder/*
	do
		prog=${p%.*}
		program_file_name=${prog##*/}
		exists=`grep -x "$program_file_name" $skipFiles | wc -l`
		if [[ "$exists" -eq "1" ]] ; then
			rm $p
			echo "Remove file in original set $p"
		fi
		exists=`grep -x "$program_file_name.c" $skipFiles | wc -l`
                if [[ "$exists" -eq "1" ]] ; then
                        rm $p
                        echo "Remove file in original set $p"
                fi
		exists=`grep "q = p + 1 + 42" $p | wc -l`
		if [[ "$exists" -eq "1" ]] ; then
                        rm $p
                        echo "Remove file in original set $p"
                fi
	done
fi

## Check if need rename of remove of empty
for p in $sourceFolder/*
do
	## Check if need to rename or remove if size 0
	sizeF=`cat $p | wc -l`
	if [[ "$sizeF" -eq "0" ]] ; then
		rm $p
		echo "remove zero size file $p"	
	elif [[ ! $p == *.c ]]; then
		mv $p $p.c
		echo " >> rename $p to $p.c"
	elif [[ $p == *.c.c ]]; then
		prog=${p%.*}
		mv $p $prog
		echo " >> rename $p to $prog"
	fi
done

# Fix Main names - transformation before script 3
for p in $sourceFolder/*
do
        sed -i 's:enum fred frod;:enum fred frod=1;:g' $p
        sed -i 's:int a;:int a=0;:g' $p
        sed -i 's:int b;:int d=0;:g' $p
        sed -i 's:int c;:int c=0;:g' $p
        sed -i 's:int d;:int d=0;:g' $p
        sed -i 's:extern int memcmp (:extern int memcmp_inner-def (:g' $p
        sed -i 's:typedef __uint64_t uint64_t;:/* Remove typedef */:g' $p
        sed -i 's:typedef int ssize_t;:/* Remove typedef */:g' $p
        sed -i 's:typedef unsigned long long uint64_t;:/* Remove typedef */:g' $p
        sed -i 's:main ():main():g' $p
        sed -i 's:main (:main(:g' $p
        sed -i 's:( void ):(void):g' $p
        sed -i 's:(void ):(void):g' $p
        sed -i 's:( void):(void):g' $p
        sed -i 's:( int:(int:g' $p
        sed -i 's: ):):g' $p
        sed -i 's: (:(:g' $p
        sed -i 's:main(void):main():g' $p
        sed -i 's:main (void):main():g' $p
        sed -i 's:main(int argc):main(int argc, char \*argv[]):g' $p
        sed -i 's:main(int argc, char \*\*argv):main(int argc, char \*argv[]):g' $p
        sed -i 's:main(int argc, char\*\* argv):main(int argc, char \*argv[]):g' $p
        sed -i 's:main(int argc, char\* argv\[\]):main(int argc, char \*argv\[\]):g' $p
        sed -i 's:main(int argc,char \*\*argv):main(int argc, char \*argv[]):g' $p
        sed -i 's:main(int argc,char\*\* argv):main(int argc, char \*argv[]):g' $p
        sed -i 's:main(int argc,char \*argv\[\]):main(int argc, char \*argv\[\]):g' $p
        sed -i 's:main(int argc,char\* argv\[\]):main(int argc, char \*argv\[\]):g' $p
        sed -i ':a;N;$!ba;s:int\nmain():int main():g' $p
        sed -i ':a;N;$!ba;s:int\nmain(:int main(:g' $p
        sed -i ':a;N;$!ba;s:\nmain(: main(:g' $p
        sed -i ':a;N;$!ba;s:int main\(argc, argv\)\n     int argc;\n     char \*\*argv;:int main(int argc, char \*argv[]):g' $p
        sed -i ':a;N;$!ba;s:int main\(int argc __attribute__\(\(unused\)\), char \*\*argv __attribute__\(\(unused\)\)\):int main\(int argc, char \*argv\[\]\):g' $p
        sed -i ':a;N;$!ba;s:int main(argc, argv)\n     int argc;\n     char \*\*argv;:int main(int argc, char \*argv[]):g' $p
        sed -i ':a;N;$!ba;s:int main(int argc __attribute__((unused)), char \*\*argv __attribute__((unused))):int main(int argc, char \*argv[]):g' $p
        sed -i ':a;N;$!ba;s:typedef __attribute__((aligned(16))):typedef:g' $p
        sed -i ':a;N;$!ba;s:typedef __attribute__\(\(aligned\(16\)\)\):typedef:g' $p

        # Mark signature we can recognize
        sed -i 's:main():main() /* OK */:g' $p
        sed -i 's:main(int argc, char \*argv\[\]):main(int argc, char \*argv\[\]) /* OK */:g' $p
done

echo "## DONE. ##"
