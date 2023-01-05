#!/bin/bash

g++ --std=c++17 -Wall -Wextra -Werror -O2 -D _GLIBCXX_HOSTED -D _GLIBCXX_NO_ASSERT sol1.cpp -o sol1
./sol1 < in
rm sol1
