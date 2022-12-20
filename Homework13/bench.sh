#!/bin/bash

make
make NPAR

time ./par.out
rm ans1.txt
rm test1.txt
time ./npar.out