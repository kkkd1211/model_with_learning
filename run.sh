#!/bin/bash
g++ *.cpp -o k -lm -O2
rm ./output/*
./k
sh switch_R_C.sh
gnuplot makegif.plt
