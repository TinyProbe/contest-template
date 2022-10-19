#!/bin/bash

g++ -Wall -Wextra -Werror -D TINY__ solution.cpp -o solution
./solution
rm ./solution
