We ran a six-month experiment with Csmith on a single machine with Ubuntu 18.04 LTS x86_64 using two virtual CPU cores and 8 GB RAM.
It is because our initial corpus contained reduced Csmith-programs.

With GCC-11 and CLANG-13, we did not detect bugs during that time. We have not evaluated Csmith against sanitisers and code analysers.

This folder contains the scripts and the loggers of this experiment.

Technical data of Csmith:
```
 * Generator: csmith 2.4.0
 * Git version: deddca6
 * Options:   --bitfields --packed-struct
```
