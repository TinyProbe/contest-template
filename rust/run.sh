#!/bin/bash

rustc main.rs -o a.out &&\
    (./a.out < in.txt > out.txt ; rm ./a.out)
