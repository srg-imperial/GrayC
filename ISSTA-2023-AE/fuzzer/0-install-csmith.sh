# you can use this script to instal csmith
#!/bin/bash
working_folder=$1
cd $working_folder

## Get csmith
git clone https://github.com/csmith-project/csmith.git
cd ./csmith
git checkout 900729a
mkdir build
cd build
cmake ../
make -j$(nproc)
rm ./scripts/compiler_test.in
echo ">> Downloading and building Csmith (900729a $working_folder/csmith)"
