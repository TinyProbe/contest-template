#!/bin/bash

c++ --std=c++20 -Wall -Wextra -Werror -g3 -D _GLIBCXX_HOSTED -D _GLIBCXX_NO_ASSERT sol1.cpp -o sol1
./sol1 < in.txt
rm -rf sol1 sol1.dSYM
