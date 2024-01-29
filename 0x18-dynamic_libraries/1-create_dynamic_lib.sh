#!/bin/bash
gcc -Wall -Wextra -Werror -pedantic -c *.c -fpic
gcc *.o -shared -o liball.so
export LD_LIBRARY_PATH=.:$LD_LIBRARY_PATH
