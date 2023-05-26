echo "CLANG Errors: --->"
grep -e": Assertion" -e"failed." -e"error: clang frontend command failed with exit code" -e"Testing folder:" -e"assert" -e"Assert" -e"======" -e"LLVM ERROR: out of memory" -e"clang: error: unable to execute command: Aborted" $1 | grep -B1 -e"LLVM ERROR: out of memory" -e"clang: error: unable to execute command: Aborted" | grep -A1 " ============" | grep -ve"LLVM ERROR: out of memory" -ve"--" -ve"===="

echo "GCC Errors: --->"
grep -e"Testing folder:" -e"assert" -e"Assert" -e"internal compiler error:" $1 | grep -e"internal compiler error:" | grep -ve"internal compiler error: in expand_call, at calls.cc:3643" -ve"CPU time limit" -ve"File size limit exceeded signal terminated program as" -ve"internal compiler error: in expand_call, at calls.cc:3601" -ve"in expand_call, at calls.cc:3905" -ve"internal compiler error: verify_gimple failed" -ve "internal compiler error: in decompose, at wide-int.h:984" -ve"in tree_to_poly_int64, at tree.cc:3188" -ve"internal compiler error: in as_a, at value-range.h:381"

echo "Frama-c Errors: --->"
grep -e"Testing folder:" -e"============ Frama-C-zone/f" $1 | grep -e"============ Frama-C-zone/f" | grep -ve'Unexpected error (File "src/plugins/value/engine/evaluation.ml", line 1176, characters 14-20: Assertion failed).' -ve"Unexpected error (Stack overflow)." -ve"Unexpected error (Out of memory)." -ve'Unexpected error (Invalid_argument("Z.shift_left: count argument must be positive")).' -ve'Unexpected error (Invalid_argument("Array.make")).' -ve"Unexpected error (Cil.Not_representable)." -ve'Unexpected error (File "src/kernel_services/abstract_interp/ival.ml", line 444, characters 31-37: Assertion failed).' -ve"Unexpected error (Z.Overflow)."

files=`grep "Testing folder:" $1 | wc -l`
echo "Total tar files $files"
