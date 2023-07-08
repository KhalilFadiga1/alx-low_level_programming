#!/bin/bash
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 -C *.c
ar -rc liball.a *.o
ranlib liball.a
