#!/bin/bash

g++ -Wall -Wextra -Werror -D TINY___ sol1.cpp -o sol1
g++ -Wall -Wextra -Werror -D TINY___ sol2.cpp -o sol2
./sol1
./sol2
diff ./out1.txt ./out2.txt
rm ./sol1 ./sol2 ./out1.txt ./out2.txt
