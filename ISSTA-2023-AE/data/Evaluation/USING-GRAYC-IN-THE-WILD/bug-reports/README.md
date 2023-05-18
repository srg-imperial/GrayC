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

GrayC has found 30 confirmed bugs:
[Frama-C-2550](https://git.frama-c.com/pub/frama-c/-/issues/2550),
[Frama-C-2551](https://git.frama-c.com/pub/frama-c/-/issues/2551),
[Frama-C-2555](https://git.frama-c.com/pub/frama-c/-/issues/2555),
[Frama-C-2556](https://git.frama-c.com/pub/frama-c/-/issues/2556),
[Frama-C-2563](https://git.frama-c.com/pub/frama-c/-/issues/2563),
[Frama-C-2576](https://git.frama-c.com/pub/frama-c/-/issues/2576),
[Frama-C-2585](https://git.frama-c.com/pub/frama-c/-/issues/2585),
[Frama-C-2588](https://git.frama-c.com/pub/frama-c/-/issues/2588),
[Frama-C-2590](https://git.frama-c.com/pub/frama-c/-/issues/2590),
[Frama-C-2592](https://git.frama-c.com/pub/frama-c/-/issues/2592),
[Frama-C-2595](https://git.frama-c.com/pub/frama-c/-/issues/2595),
[Frama-C-2610](https://git.frama-c.com/pub/frama-c/-/issues/2610),
[GCC-103314](https://gcc.gnu.org/bugzilla/show_bug.cgi?id=103314),
[GCC-103813](https://gcc.gnu.org/bugzilla/show_bug.cgi?id=103813),
[GCC-103816](https://gcc.gnu.org/bugzilla/show_bug.cgi?id=103816),
[GCC-103818](https://gcc.gnu.org/bugzilla/show_bug.cgi?id=103818),
[GCC-104402](https://gcc.gnu.org/bugzilla/show_bug.cgi?id=104402),
[GCC-105232](https://gcc.gnu.org/bugzilla/show_bug.cgi?id=105232),
[GCC-105910](https://gcc.gnu.org/bugzilla/show_bug.cgi?id=105910),
[GCC-106560](https://gcc.gnu.org/bugzilla/show_bug.cgi?id=106560),
[GCC-107170](https://gcc.gnu.org/bugzilla/show_bug.cgi?id=107170),
[GCC-84964](https://gcc.gnu.org/bugzilla/show_bug.cgi?id=84964),
[GCC-84964](https://gcc.gnu.org/bugzilla/show_bug.cgi?id=84964),
[GCC-99990](https://gcc.gnu.org/bugzilla/show_bug.cgi?id=99990),
[LLVM-49081](https://github.com/llvm/llvm-project/issues/49081),
[LLVM-49983](https://github.com/llvm/llvm-project/issues/49983),
[LLVM-49993](https://github.com/llvm/llvm-project/issues/49993),
[msvc-1427550](https://developercommunity.visualstudio.com/t/syntactically-invalid-c-program-causes-microsoft-c/1427550),
[msvc-1427553](https://developercommunity.visualstudio.com/t/internal-compiler-error-when-compiling-program-wit/1427553) and
[msvc-1427557](https://developercommunity.visualstudio.com/t/internal-compiler-error-when-compiling-program-wit/1427557), 
With 25 previously unknown bugs and 5 reported shortly before we managed to do so.

With three reports pending: 
[LLVM-25871](https://github.com/llvm/llvm-project/issues/25871), 
[LLVM-48633](https://github.com/llvm/llvm-project/issues/48633),
and
[LLVM-50222](https://github.com/llvm/llvm-project/issues/50222).

During our fuzzing campaigns, we used 
[Creduce](https://embed.cs.utah.edu/creduce/), 
the LLVM sanitizers ([ASAN](https://clang.llvm.org/docs/AddressSanitizer.html), [MSAN](https://clang.llvm.org/docs/MemorySanitizer.html) and [UBSAN](https://clang.llvm.org/docs/UndefinedBehaviorSanitizer.html))
and [Frama-C](https://frama-c.com) as part of investigating the bugs that we found.
This led to us to report 11 additional bugs in these tools as a by-product of our work: 
[Creduce-00537](https://www.flux.utah.edu/listarchives/creduce-bugs/msg00537.html),
[Creduce-00551](https://www.flux.utah.edu/listarchives/creduce-bugs/msg00551.html),
[Creduce-00553](https://www.flux.utah.edu/listarchives/creduce-bugs/msg00553.html),
[Creduce-00555](https://www.flux.utah.edu/listarchives/creduce-bugs/msg00555.html),
[Creduce-00563](https://www.flux.utah.edu/listarchives/creduce-bugs/msg00563.html),
[Frama-C-2559](https://git.frama-c.com/pub/frama-c/-/issues/2559),
[Frama-C-2573](https://git.frama-c.com/pub/frama-c/-/issues/2573),
[Frama-C-2574](https://git.frama-c.com/pub/frama-c/-/issues/2574),
[LLVM-50332](https://github.com/llvm/llvm-project/issues/50332),
[LLVM-51421](https://github.com/llvm/llvm-project/issues/51421) and 
[LLVM-53105](https://github.com/llvm/llvm-project/issues/53105).
