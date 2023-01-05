#!/bin/zsh

g++ --std=c++17 -Wall -Wextra -Werror -O2 -D _GLIBCXX_HOSTED -D _GLIBCXX_NO_ASSERT sol1.cpp -o sol1
g++ --std=c++17 -Wall -Wextra -Werror -O2 -D _GLIBCXX_HOSTED -D _GLIBCXX_NO_ASSERT sol2.cpp -o sol2
./sol1 < input.txt > out1.txt
./sol2 < input.txt > out2.txt
diff ./out1.txt ./out2.txt
rm ./sol1 ./sol2 ./out1.txt ./out2.txt
