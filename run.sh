#!/bin/zsh

g++ --std=c++20 -Wall -Wextra -Werror -O3 -D _GLIBCXX_HOSTED -D _GLIBCXX_NO_ASSERT sol1.cpp -o sol1
./sol1 < input.txt
rm ./sol1
