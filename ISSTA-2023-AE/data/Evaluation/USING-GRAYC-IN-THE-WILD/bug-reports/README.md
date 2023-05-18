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


