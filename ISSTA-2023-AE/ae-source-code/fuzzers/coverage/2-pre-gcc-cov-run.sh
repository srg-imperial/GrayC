#!/bin/bash 
base=$1			## e.g., /home/user42
compiler=$2		## llvm or gcc
process_number=$3	## e.g., 5
working_folder=$base/$compiler-csmith-$process_number

######################################## Prepare the env. for using GCC compiler ########################################
# Restore softlink linker lto
cd $working_folder/gcc-build/gcc/
ln -sf liblto_plugin.so.0.0.0 liblto_plugin.so
ln -sf liblto_plugin.so.0.0.0 liblto_plugin.so.0

## Assure we are using the gcov in the gcc built:
usrLib=$working_folder/gcc-install
sudo rm -f /usr/local/bin/gcov /usr/bin/gcov 
sudo ln -s $usrLib/bin/gcov /usr/bin/gcov
