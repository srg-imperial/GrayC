# Crash reproducer for clang version 10.0.0-4ubuntu1 
# Driver args: "-O2" "-fsanitize=undefined" "-pedantic" "-Wall" "-Wextra" "-I" "/home/user42/llvm-csmith-1/csmith/runtime/" "-I" "/home/user42/llvm-csmith-1/csmith/build/runtime/" "test1552568772.c" "-o" "clangA.out"
# Original command:  "/usr/lib/llvm-10/bin/clang" "-cc1" "-triple" "x86_64-pc-linux-gnu" "-emit-obj" "-disable-free" "-disable-llvm-verifier" "-discard-value-names" "-main-file-name" "test1552568772.c" "-mrelocation-model" "static" "-mthread-model" "posix" "-mframe-pointer=none" "-fmath-errno" "-fno-rounding-math" "-masm-verbose" "-mconstructor-aliases" "-munwind-tables" "-target-cpu" "x86-64" "-dwarf-column-info" "-fno-split-dwarf-inlining" "-debugger-tuning=gdb" "-resource-dir" "/usr/lib/llvm-10/lib/clang/10.0.0" "-I" "/home/user42/llvm-csmith-1/csmith/runtime/" "-I" "/home/user42/llvm-csmith-1/csmith/build/runtime/" "-internal-isystem" "/usr/local/include" "-internal-isystem" "/usr/lib/llvm-10/lib/clang/10.0.0/include" "-internal-externc-isystem" "/usr/include/x86_64-linux-gnu" "-internal-externc-isystem" "/include" "-internal-externc-isystem" "/usr/include" "-O2" "-Wall" "-Wextra" "-pedantic" "-fdebug-compilation-dir" "/tmp/creduce-Niz6yI" "-ferror-limit" "19" "-fmessage-length" "0" "-fsanitize=alignment,array-bounds,bool,builtin,enum,float-cast-overflow,function,integer-divide-by-zero,nonnull-attribute,null,object-size,pointer-overflow,return,returns-nonnull-attribute,shift-base,shift-exponent,signed-integer-overflow,unreachable,vla-bound,vptr" "-fsanitize-recover=alignment,array-bounds,bool,builtin,enum,float-cast-overflow,function,integer-divide-by-zero,nonnull-attribute,null,object-size,pointer-overflow,returns-nonnull-attribute,shift-base,shift-exponent,signed-integer-overflow,vla-bound,vptr" "-fgnuc-version=4.2.1" "-fobjc-runtime=gcc" "-fdiagnostics-show-option" "-vectorize-loops" "-vectorize-slp" "-faddrsig" "-o" "/tmp/test1552568772-0cf32a.o" "-x" "c" "test1552568772.c"
 "/usr/lib/llvm-10/bin/clang" "-cc1" "-triple" "x86_64-pc-linux-gnu" "-emit-obj" "-disable-free" "-disable-llvm-verifier" "-discard-value-names" "-main-file-name" "test1552568772.c" "-mrelocation-model" "static" "-mthread-model" "posix" "-mframe-pointer=none" "-fmath-errno" "-fno-rounding-math" "-masm-verbose" "-mconstructor-aliases" "-munwind-tables" "-target-cpu" "x86-64" "-dwarf-column-info" "-fno-split-dwarf-inlining" "-debugger-tuning=gdb" "-O2" "-Wall" "-Wextra" "-pedantic" "-ferror-limit" "19" "-fmessage-length" "0" "-fsanitize=alignment,array-bounds,bool,builtin,enum,float-cast-overflow,function,integer-divide-by-zero,nonnull-attribute,null,object-size,pointer-overflow,return,returns-nonnull-attribute,shift-base,shift-exponent,signed-integer-overflow,unreachable,vla-bound,vptr" "-fsanitize-recover=alignment,array-bounds,bool,builtin,enum,float-cast-overflow,function,integer-divide-by-zero,nonnull-attribute,null,object-size,pointer-overflow,returns-nonnull-attribute,shift-base,shift-exponent,signed-integer-overflow,vla-bound,vptr" "-fgnuc-version=4.2.1" "-fobjc-runtime=gcc" "-fdiagnostics-show-option" "-vectorize-loops" "-vectorize-slp" "-faddrsig" "-x" "c" "test1552568772-7dca88.c"