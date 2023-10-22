## Assure we are in gcc-10!
sudo apt install gcc-10 g++-10
sudo update-alternatives --install /usr/bin/gcc gcc /usr/bin/gcc-10 990 --slave /usr/bin/g++ g++ /usr/bin/g++-10 --slave /usr/bin/gcov gcov /usr/bin/gcov-10
sudo rm -f /usr/bin/cpp /usr/bin/gcc /usr/bin/g++ /usr/bin/gcov
sudo rm -f /usr/local/bin/cpp /usr/local/bin/gcc /usr/local/bin/g++ /usr/local/bin/gcov
sudo ln -s /usr/bin/cpp-10 /usr/bin/cpp
sudo ln -s /usr/bin/gcc-10 /usr/bin/gcc
sudo ln -s /usr/bin/g++-10 /usr/bin/g++
sudo ln -s /usr/bin/gcov-10 /usr/bin/gcov
echo ">> End Settings"
