# Coverage Scripts

To use these script to measure coverage for GrayC follow the steps below.

## Software Requirements

*For installing from source,* you will need to install the following: gcc, gcov, g++, flex, bison, binutils, git, python3, python3-pip, gfauto (under Google's graphicsfuzz), cmake, m4, ninja-build, curl, wget, zip, unzip, frama-c, creduce, openSSL (libcurl4-openssl-dev, libssl-dev). Commonly these packages are installed if you work with compilers' source code.

Note 1: CMake 3.13.4 or higher is required.

Note 2: GCC-10 or higher is required. We have tested our artifact with GCC-10 and GCC-11.

Note 3: gfauto: https://github.com/google/graphicsfuzz.git
	
### gfauto tool
If you don't have gfauto installed, please follow the instructions here: https://github.com/google/graphicsfuzz.
You can try the following instruction we used to set up the tool:
```
git clone https://github.com/google/graphicsfuzz.git
cd graphicsfuzz/gfauto/
vi dev_shell.sh.template
EDIT TO YOUR LOCAL VERSION of Python3: PYTHON=${PYTHON-python3.6}
rm Pipfile.lock (if Python3.8 or above)
./dev_shell.sh.template
```
