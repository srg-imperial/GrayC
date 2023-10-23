## Assure we are in gcc-11!
sudo apt install gcc-11 g++-11
sudo update-alternatives --install /usr/bin/gcc gcc /usr/bin/gcc-11 1100 --slave /usr/bin/g++ g++ /usr/bin/g++-11 --slave /usr/bin/gcov gcov /usr/bin/gcov-11
sudo rm -f /usr/bin/c++ /usr/bin/cpp /usr/bin/gcc /usr/bin/g++ /usr/bin/gcov
sudo rm -f /usr/local/bin/c++ /usr/local/bin/cpp /usr/local/bin/gcc /usr/local/bin/g++ /usr/local/bin/gcov
sudo ln -s /usr/bin/cpp-11 /usr/bin/cpp
sudo ln -s /usr/bin/gcc-11 /usr/bin/gcc
sudo ln -s /usr/bin/g++-11 /usr/bin/g++
sudo ln -s /usr/bin/g++-11 /usr/bin/c++
sudo ln -s /usr/bin/gcov-11 /usr/bin/gcov
echo ">> End Settings"
