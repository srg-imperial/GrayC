# enhanCer

The enhanCer is a set of scripts that are part of GrayC. It has two main functionalities:
 
- The first takes a program and injects Csmith function calls thus the resultant program prints checksum in the end.
 
- The other takes a fuzzed program that hits new coverage and transforms it into a small test for the LLVM test suite.

Scripts here start with (1-) or (2-) according to which functionality they perform.

## Requirements

To be able to run these scripts you will need to install several packages:

For script 1-3:
```
sudo apt-get install ctags
sudo apt install python3
sudo apt install python3-pip
pip3 install pandas
```
