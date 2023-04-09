#!/bin/bash

g++ --std=c++20 -Wall -Wextra -Werror -O2 -D _GLIBCXX_HOSTED -D _GLIBCXX_NO_ASSERT sol1.cpp -o sol1
g++ --std=c++20 -Wall -Wextra -Werror -O2 -D _GLIBCXX_HOSTED -D _GLIBCXX_NO_ASSERT sol2.cpp -o sol2
./sol1 < in > out1
./sol2 < in > out2
diff out1 out2
rm sol1 sol2 out1 out2
