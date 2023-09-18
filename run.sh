#!/bin/bash

c++ --std=c++20 -Wall -Wextra -Werror -O2 -D _GLIBCXX_HOSTED -D _GLIBCXX_NO_ASSERT -D __TINY__ sol1.cpp -o sol1
./sol1 < in.txt
rm sol1
