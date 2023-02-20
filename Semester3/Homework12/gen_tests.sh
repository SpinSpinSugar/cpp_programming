#!/bin/bash

cd src && make generator
for (( i = 1; i <= 10; ++i )); do
    touch ../Tests/in${i}.txt
    touch ../Tests/sol${i}.txt

    ({ echo "../Tests/in${i}.txt"; echo "../Tests/sol${i}.txt"; } | ./gen_tests) &

done
