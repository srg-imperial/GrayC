# GrayC: A fuzzer for C compilers and code analyzers
<a href="https://srg.doc.ic.ac.uk/files/papers/grayc-issta-23.pdf" target="_blank"><img src="img/grayc.png" align="right" width="250"></a>
The GrayC approach involves using mutation-based fuzzing as a program generation technique, and then using the generated programs to test compilers and analysers.  

This version is the revamped version of the one presented in our ISSTA '23 paper. It contains the following enhancements:

1. Write-Your-Own-Mutator
2. Interface to extend the tool for the entire C-family
3. Out-of-tree implementation of the tool
4. Rewrite of the codebase which now heavily relies on the LLVM/Clang framework
5. Better debugging due to reliance on ASTMatchers and Clang's internal debugging framework

## Installation

```
wget -O - https://apt.llvm.org/llvm-snapshot.gpg.key | sudo apt-key add -
sudo apt-add-repository "deb http://apt.llvm.org/bionic/ llvm-toolchain-bionic-12 main"
sudo apt-get update
sudo apt-get install -y llvm-12 llvm-12-dev llvm-12-tools clang-12 libclang-common-12-dev libclang-12-dev 

This builds both LLVM and Clang on Ubuntu

git clone https://github.com/srg-imperial/GrayC.git
cd GrayC
mkdir build
cd build
cmake -GNinja -DCMAKE_C_COMPILER=clang-12 -DCMAKE_CXX_COMPILER=clang++-12 -DLLVM_CONFIG_BINARY=llvm-config-12 ../
ninja
```

## Example

```
cd build 
echo "int main(){int a=0; ++a;return 0;}" > b.cpp
bin/grayc --apply-mutation ../b.cpp --
```

## GrayC: Write-Your-Own-Mutator (WYOM)
The inspiration behind this functionality was the extensible framework introduced by `clang-tidy`. More technically, the `WYOM` functionality is realised by making use of the `add_new_mutator.py` script, which automatically updates the various files while providing the boilerplate code to write a new mutation. 

### WYOM Example Usage
Let's see the case for development of a simple mutator that converts a `+` to a `-`. For now, we would like the mutator to work on `C` programs. We will start off by calling the `add_new_mutator.py` as follows:

```
python3 add_new_mutator.py cmutation binary-operator-mutator
```
GrayC's mutators are divided into modules, based on the language that it targets. `cmutation` is the module corresponding to mutators for `C` files, while `cxxmutation` houses the `C++` mutators. The script does the following tasks:

1. Registers the `binary-operator-mutator` within the `cmutation` module 
2. Provides `BinaryOperatorMutator.cpp` and `BinaryOperatorMutator.h` files
3. Provides a small implementation of the `BinaryOperatorMutator::registerMatchers` and the `BinaryOperatorMutator::check` containing a sample matcher and the correponsing callback function. 

The user is then expected to refine the `ASTMatcher` in the `BinaryOperatorMutator::registerMatchers` function and the callback code in the `BinaryOperatorMutator::check` function. 

Once refined, the check can be called on a sample file in the aforementioned manner. 
