#!/bin/bash

cd src && make sorter
for (( i = 1; i <= 10; ++i )); do
    touch ../Tests/out${i}.txt
    ({ echo "../Tests/in${i}.txt"; echo "../Tests/out${i}.txt"; }  | ./sorter) &
done