#!/bin/bash
g++ Program.cpp -o Program.out
echo TEST1
./Program.out < Test1.txt

printf "\n\n\n"
echo TEST2
./Program.out < Test2.txt
