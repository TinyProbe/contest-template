#!/bin/bash

c++ --std=c++20 -Wall -Wextra -Werror -g3 -D _GLIBCXX_HOSTED -D _GLIBCXX_NO_ASSERT sol1.cpp -o sol1
c++ --std=c++20 -Wall -Wextra -Werror -g3 -D _GLIBCXX_HOSTED -D _GLIBCXX_NO_ASSERT sol2.cpp -o sol2
./sol1 < in.txt > out1.txt
./sol2 < in.txt > out2.txt
diff out1.txt out2.txt
rm -rf sol1 sol2 sol1.dSYM sol2.dSYM out1.txt out2.txt
