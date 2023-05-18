# GrayC in the wild

The qualitative evaluation presented here took place during the development of GRAYC over a period of 18 months discontinuously.
During this time, we regularly applied GRAYC to several versions of popular compilers and code analysers: 
  
- LLVM: versions 10,11,12,13,14 and 15 on UBUNTU 18.04 LTS x86 64 
- GCC: versions 10,11,12 and 13 on UBUNTU 18.04 LTS x86 64
- MSVC (19.28.29915) on WINDOWS platform with tests generated on Ubuntu
- FRAMA-C code analyser: versions 21,22,23 and 24 on on UBUNTU 18.04 LTS x86 64

Our fuzzing campaigns led to the discovery of bugs [here](USING-GRAYC-IN-THE-WILD/bug-reports/) and the contribution of programs to the CLANG/LLVM test suite [here](USING-GRAYC-IN-THE-WILD/test-contribution/).
