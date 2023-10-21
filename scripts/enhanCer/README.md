# enhanCer

The enhanCer is a set of scripts that are part of GrayC. It has two main functionalities:
 
- The first takes a program and injects Csmith function calls thus the resultant program prints checksum in the end.
 
- The other takes a fuzzed program that hits new coverage and transforms it into a small test for the LLVM test suite.

- Another basic version of the second set generate a report of difference between two test suites' coverage.

Scripts here start with (1-) or (2-) according to which functionality they perform.

## Requirements

To be able to run these scripts you will need to install several packages:

- Install Csmith
- Install C-reduce

For script 1-3-transform.py:
```
sudo apt-get install ctags
sudo apt install python3
sudo apt install python3-pip
pip3 install pandas
```

## Run the enhanCer (part-1)

To transform programs to have a checksum print in the end (we used the Csmith mechanism to do so, but you can pull these and implement yours):
```
./1-main-enhanCer-option-1.sh <working-folder-all-results> <input-data> <1-2-zip-or-folder> <csmith-installation>
```

## Run the enhanCer (part-2)

TODO: need to copy from private repository.


## Run the enhanCer - coverage

The following set of scripts takes coverage of two test suits and generate the delta of coverage between the first test suite and the second test suite.

Start with measuring coverage of both test suites.
