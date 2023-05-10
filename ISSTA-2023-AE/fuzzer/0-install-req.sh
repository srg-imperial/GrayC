#!/bin/bash
cd ~
echo "Install requiremnts"
sudo apt-get install software-properties-common
sudo add-apt-repository ppa:ubuntu-toolchain-r/test
sudo apt-get update
sudo apt install -y cmake
sudo apt-get install -y m4
sudo apt install -y ninja-build
sudo apt install -y python3
sudo apt install -y python3-pip
## set gcovi
echo "Install GCC and LLVM defaults"
wget https://apt.llvm.org/llvm.sh
chmod +x llvm.sh
sudo ./llvm.sh 12
sudo update-alternatives --install /usr/bin/clang clang /usr/bin/clang-12 120 --slave /usr/bin/clang++ clag++ /usr/bin/clang++-12
## The GCC
sudo apt-get -y install gcc-11 g++-11 cpp-11
sudo rm /usr/bin/cpp /usr/bin/gcc /usr/bin/g++  /usr/bin/gcov  /usr/bin/c++
sudo rm /usr/local/bin/cpp /usr/local/bin/gcc /usr/local/bin/g++ /usr/local/bin/gcov  /usr/local/bin/c++
sudo ln -s /usr/bin/cpp-11 /usr/bin/cpp
sudo ln -s /usr/bin/gcc-11 /usr/bin/gcc
sudo ln -s /usr/bin/g++-11 /usr/bin/g++
sudo ln -s /usr/bin/g++-11 /usr/bin/c++
sudo ln -s /usr/bin/gcov-11 /usr/bin/gcov
sudo update-alternatives --install /usr/bin/gcc gcc /usr/bin/gcc-11 110 --slave /usr/bin/g++ g++ /usr/bin/g++-11
sudo apt autoremove
## add swap
echo "Create a Swap of 4GB"
sudo fallocate -l 4G swapfile
sudo chmod 600 swapfile
sudo mkswap swapfile
sudo swapon swapfile
sudo swapon --show
