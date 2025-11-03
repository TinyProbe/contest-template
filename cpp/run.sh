#!/bin/bash

c++ --std=c++23 -Wall -Wextra -Werror -O2 main.cpp &&\
    (./a.out < in.txt > out.txt ; rm ./a.out)
