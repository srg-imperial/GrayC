We ran a continuous six-month experiment with Csmith (single machine, Ubuntu 18.04 LTS x86\_64 using two virtual CPU cores and 8 GB RAM) as the initial corpus contained reduced Csmith-programs. 

With GCC-11 and CLANG-13, we did not detect bugs during that time. We have not evaluated \csmith{} against sanitisers and code analysers.

This folder contains the scripts and the loggers of this experiment.

Techincal data of Csmith:
 * Generator: csmith 2.4.0
 * Git version: deddca6
 * Options:   --bitfields --packed-struct
