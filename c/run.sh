#!/bin/bash

cc --std=c23 -Wall -Wextra -Werror -O2 main.c &&\
    (./a.out < in.txt > out.txt ; rm ./a.out)
