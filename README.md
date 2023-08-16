<img src="img/grayc-logo.png" align="right" width="300">

# Mutation-based Testing Tool for C Family Compilers and Code Analyzers
The GrayC approach involves using mutation-based fuzzing as a program generation technique (as described in our [ISSTA '23 paper](https://srg.doc.ic.ac.uk/files/papers/grayc-issta-23.pdf)) and then using the generated programs to test compilers and analysers. It is currently usable for generating programs across the C family i.e. `C`,`C++`,`Objective C` and `Objective C++`. For replication of the results presented in our [ISSTA '23 paper](https://srg.doc.ic.ac.uk/files/papers/grayc-issta-23.pdf), please checkout and use the tool from the [issta-2023](https://github.com/srg-imperial/GrayC/tree/issta-2023) branch.


## Features
This is the revamped version of the one presented in our ISSTA '23 paper. It contains the following enhancements:

1. Write-Your-Own-Mutator
2. Remove dependence on `libfuzzer`
3. Interface to extend the tool for the entire C-family
4. Out-of-tree implementation of the tool
5. Rewrite of the codebase which now heavily relies on the LLVM/Clang framework
6. Better debugging due to reliance on ASTMatchers and Clang's internal debugging framework
7. Per mutation profiling mechanism for long fuzzing runs (courtesy LLVM's `clang-tidy`)

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

Check the installation in the build directory as

```
bin/grayc --list-mutations
```

which should produce the following output
```
Enabled mutations:
    cmutation-assignment-expression-mutator
    cmutation-conditional-expression-mutator
    cmutation-duplicate-statement-mutator
    cmutation-jump-mutator
    cmutation-unary
```
## Example

```
cd build 
echo "int main(){int a=0; ++a;return 0;}" > b.cpp
bin/grayc -mutations="-*,cmutation-unary" --apply-mutation b.cpp -- 
```

This should result in the following program
```
int main()
{
    int a = 0;
    --a;
    return 0;
}
```

## GrayC: Write-Your-Own-Mutator (WYOM)
The inspiration behind this functionality was the extensible framework introduced by `clang-tidy`. More technically, the `WYOM` functionality is realised by making use of the `add_new_mutator.py` script, which automatically updates the various files while providing the boilerplate code to write a new mutation. 

### WYOM Example Usage
Let's see the case for development of a simple mutator that converts a `+` to a `-`. For now, we would like the mutator to work on `C` programs. We will start off by calling the `add_new_mutator.py`, which sits in the `grayc` folder, as follows:

```
./add_new_mutator.py cmutation binary-operator-mutator
```
 The script does the following tasks:

1. Registers the `binary-operator-mutator` within the `cmutation` module 
2. Provides `BinaryOperatorMutator.cpp` and `BinaryOperatorMutator.h` files
3. Provides a small implementation of the `BinaryOperatorMutator::registerMatchers` and the `BinaryOperatorMutator::check` containing a sample matcher and the correponsing callback function. 

The user is then expected to refine the `ASTMatcher` in the `BinaryOperatorMutator::registerMatchers` function and the callback code in the `BinaryOperatorMutator::check` function. 

Once refined, the check can be called on a sample file in the aforementioned manner. 

GrayC's mutators are divided into modules, based on the language that it targets. `cmutation` is the most general module corresponding to mutators applicable for the entire `C` family , while `cxxmutation` houses the `C++` specific mutators. We aim to extend this by having modules for Objective C and Objective C++ in the near future. 


