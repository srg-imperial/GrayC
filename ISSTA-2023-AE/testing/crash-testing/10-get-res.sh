outputfolder=$1
grep -e"../gcc-source/gcc/" -e"assert" -e" diagnostic msg" -e"error: unable to execute command: Aborted" -e"Assertion" -e"LLVM ERROR" -e"Error: " -e"ERROR:" -e"BUG" -e"bug" -e"Bug" -e"Please" -e"please" -e"PLEASE" -e"Please" -e"internal compiler error:" -e" ============ test " -e"CPU time limit" -e"clang: error:" -e"unable to execute command: File size limit exceeded" -e"generic_simplify_BIT_NOT_EXPR" -e"diagnostic msg" -e"error: clang frontend command failed with exit code" -e"failed." -e": Assertion" $outputfolder/output.log | grep -ve"bugger(" -ve"copysign_bug" -ve"==ERROR: MemorySanitizer: " -ve"==ERROR: AddressSanitizer: " -ve"5-testing_all.sh" -ve"clang: error: linker command failed with exit code 1" -ve "debug" -ve "u32 bug " -ve "In function 'bug':" -ve"Please use" -ve"bug when they were" -ve"This tests for a bug in regstack" -ve"int showbug" -ve"unsigned bug " -ve"Bug in reorg.c" -ve"This bug exists in " -ve"had a bug that causes the final" -ve"If some target has a Max alignment less than 32" | grep -B1 -e"diagnostic msg" -e"generic_simplify_BIT_NOT_EXPR" -e"error: unable to execute command: Aborted" -e"Assertion" -e"LLVM ERROR" -e"Error: " -e"ERROR:" -e"BUG" -e"bug" -e"Bug" -e"Please" -e"please" -e"PLEASE" -e"Please" -e"internal compiler error:" -e"CPU time limit" -e"unable to execute command: File size limit exceeded"
echo " === END COMP === "
echo "."
echo "."
echo "==============> frama-c errors:"
## Run for all programs in folder:
(
for p in Frama-C-zone/*.log
do
	res=`grep -e"Unexpected error" -e"BUG" -e"bug" -e"Bug" -e"Please" -e"please" -e"PLEASE" -e"Please" $p | grep -ve"copysign_bug" -ve"debug" -ve "u32 bug " -ve "In function 'bug':" -ve"Please use" -ve"bug when they were" -ve"This tests for a bug in regstack" -ve"int showbug" -ve"unsigned bug " -ve"Bug in reorg.c" -ve"This bug exists in " -ve"had a bug that causes the final" -ve"If some target has a Max alignment less than 32" -ve"information to understand the bug" -ve"https://git.frama-c.com/pub/frama-c/-/wikis/Guidelines-for-reporting-bugs" -ve"eva:final-states" -ve"The following decl of" -ve"4294966804 (auto)"`
	if [[ ${#res} -gt 0 ]] ; then
		echo "============ $p > $res"
    else
        echo ""rm $p""
    fi
done
) | grep -B1 "Please report as "
