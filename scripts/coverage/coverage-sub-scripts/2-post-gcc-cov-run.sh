#!/bin/bash 
## Revert back all gcc changes: restore gcov
sudo rm -f /usr/local/bin/gcov /usr/bin/gcov 
sudo ln -s /usr/bin/gcov-10 /usr/bin/gcov
