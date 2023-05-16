git clone https://github.com/mc-imperial/remove-parens
cd remove-parens/third_party/
wget https://github.com/llvm/llvm-project/releases/download/llvmorg-13.0.1/clang+llvm-13.0.1-x86_64-linux-gnu-ubuntu-18.04.tar.xz
tar -xf clang+llvm-13.0.1-x86_64-linux-gnu-ubuntu-18.04.tar.xz
rm clang+llvm-13.0.1-x86_64-linux-gnu-ubuntu-18.04.tar.xz
mv clang+llvm-13.0.1-x86_64-linux-gnu-ubuntu-18.04 clang+llvm-13.0.1
ls -l clang+llvm-13.0.1
cd ..
mkdir build
cd build
cmake -G Ninja ..
ninja
