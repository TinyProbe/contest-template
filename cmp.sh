#!/bin/bash

g++ -Wall -Wextra -Werror -D TINY__ sol1.cpp -o sol1
g++ -Wall -Wextra -Werror -D TINY__ sol2.cpp -o sol2
./sol1 > out1.txt
./sol2 > out2.txt
diff ./out1.txt ./out2.txt
rm ./sol1 ./sol2 ./out1.txt ./out2.txt
