# Bug finding 

Bug-finding controlled experiments for all tools in the evaluation, for all the trails we got. 

The new reports (maybe bugs) found via this evaluation with the other fuzzers are [here](reports).

# Technical Details

We tested the following tools:
- Frama-C: 24.0 (Chromium)
- LLVM: Ubuntu clang version 12.0.1-++20211102090516+fed41342a82f-1~exp1~20211102211019.11
- GCC: gcc (GCC) 12.0.1 20220310 (experimental)

With the following fuzzers:
- CLANG-FUZZER: Off-the-shelf clang-fuzzer
- regexpMutator: adapted UNIVERSAL MUTATOR, a regexp-based mutator, instead of LIBFUZZER default mutator
- GrayC aggressive and GrayC conservative modes
- Csmith

Versions of the fuzzers:
- LIBFUZZER-based configurations: LLVM 12.0.1 
- CSMITH 2.4.0 (27ace5b)
- universalmutator v1.0.18 (Git version: 3c93df6)

Reproduction of the Results:
Run this script to reproduce the results of this section:
```
python3 bucket-wrapper.py Bug-finding-trails.zip
```
```
python3 bucket-wrapper-abstract.py Bug-finding-trails.zip
```

## Results 

Find the results with all details [here](data_grayc_paper.xlsx).

### ClangFuzzer Statically Invalid Code Examples

Since the programs are statically invalid, the order in which the are presented shows the degree to which they are invalid and their likelihood of being accepted for a fix by developers. For instance example C is barely a C program while example A is closer to following the C grammar, yet being invalid.

We reported Example B to the LLVM developers, which accepted this as a valid bug report, but this bug was never fixed or further discussed except for basic triage (since 6 of May 2022). We kept the bug report anonymised for the review.

These examples are reduced to hit the ICE or compiler hand. See the table above the links to the original fuzzed programs.

Example A (Statically invalid):
```
void b() {
  int a[] =;
  a[3];
  int a;
}
```

Example B (Statically invalid and incomplete program):
```
struct a {
  int mv5; int tv6;
  struct { double kv6 } uv6
} b struct a c() {
  b.mv6.bv6 == c.mv6.bv6
```
This triggers an infinite loop in clang::Sema.

Example C (Statically invalid and incomplete program):
```
a() {
  L"<an invalid UTF-8 byte sequence>"
```
This example crahsed an instrumented compiler but ended normally (with errors) with regular clang. We did not report this bug as it has stray charecters and in general, the source file is not valid UTF-8.

Example D (Statically invalid and incomplete program):
```
               __attribute__(( a(memchr(L"\x1234", 0, sizeof 0
```
It leads to ICE in GCC with the following error: 
```
3/3f985ea6ca098a09555bf6e694c514a506f3eadd.c:1:16: internal compiler error: in constant_byte_string, at expr.cc:12202
    1 |                __attribute__(( a(memchr(L"\x1234", 0, sizeof 0
      |                ^~~~~~~~~~~~~
0x700760 constant_byte_string
	.././../gcc-source/gcc/expr.cc:12202
```
however, we did not report this bug as it has stray charecters and in general, the source file is not valid UTF-8.

**NOTE: GrayC never generated such examples: all GrayC-generated files are complete programs in valid UTF-8.**
