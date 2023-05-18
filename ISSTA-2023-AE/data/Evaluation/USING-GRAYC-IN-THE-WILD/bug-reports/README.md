# Bug finding in the wild

We use the following classification of a bug’s kind and status. 

The bug’s kind is one of the following:
- ICE: Internal Compiler Error
- ITE: Internal Tool (Analyser) Error
- Hang: Compilation not terminating for hours
- False Neg.: Test program being incorrectly reported error-free by an analyser

The bug’s status is one on the following:
- New: Recently added bug, unconfirmed
- Confirmed: Valid bug
- Fixed: Bug fixed by developers
- Won’t fix: Bug will not be fixed (e.g. low priority)
- Ind. report: Bug was independently reported or fixed
- Unreprod.: Bug is no longer reproducible in the latest version of the compiler

## Confirmed Bugs detected by GrayC:

GrayC has found 30 confirmed bugs (25 previously unknown bugs):
GCC:99990:bug
GCC:103813:bug
GCC:104402:bug
GCC:103816:bug
GCC:105232:bug
GCC:105910:bug
GCC:103818:bug 
GCC:106560:bug
GCC:107170:bug
LLVM:49983:bug
LLVM:49993:bug
msvc:1427550:bug
msvc:1427553:bug
msvc:1427557:bug
framac:2550:bug
framac:2551:bug
framac:2576:bug
framac:2555:bug
framac:2556:bug
framac:2563:bug
framac:2588:bug
framac:2590:bug
framac:2592:bug
framac:2610:bug
framac:2585:bug
GCC:103314:bug
GCC:84964:bug
GCC:101636:bug
LLVM:49081:bug
framac:2595:bug

With three reports pending: 
[25871](https://github.com/llvm/llvm-project/issues/25871), 
[50222](https://github.com/llvm/llvm-project/issues/50222) 
and 
[48633](https://github.com/llvm/llvm-project/issues/48633).

During our fuzzing campaigns, we used 
[Creduce](https://embed.cs.utah.edu/creduce/), 
the LLVM sanitizers ([ASAN](https://clang.llvm.org/docs/AddressSanitizer.html), [MSAN](https://clang.llvm.org/docs/MemorySanitizer.html) and [UBSAN](https://clang.llvm.org/docs/UndefinedBehaviorSanitizer.html))
and [Frama-C](https://frama-c.com) as part of investigating the bugs that we found.
This led to us to report 11 additional bugs in these tools as a by-product of our work: 
[2559](https://git.frama-c.com/pub/frama-c/-/issues/2559),
[2573](https://git.frama-c.com/pub/frama-c/-/issues/2573),
[2574](https://git.frama-c.com/pub/frama-c/-/issues/2574),
[00537](https://www.flux.utah.edu/listarchives/creduce-bugs/msg00537.html),
[00551](https://www.flux.utah.edu/listarchives/creduce-bugs/msg00551.html),
[00553](https://www.flux.utah.edu/listarchives/creduce-bugs/msg00553.html),
[00555](https://www.flux.utah.edu/listarchives/creduce-bugs/msg00555.html),
[00563](https://www.flux.utah.edu/listarchives/creduce-bugs/msg00563.html),
[50332](https://github.com/llvm/llvm-project/issues/50332),
[51421](https://github.com/llvm/llvm-project/issues/51421) and 
[53105](https://github.com/llvm/llvm-project/issues/53105).
