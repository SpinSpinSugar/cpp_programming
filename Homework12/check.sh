#!/bin/bash
for (( i = 1; i <= 10; ++ i)); do
    if (diff Tests/out${i}.txt Tests/sol${i}.txt); then
        echo "TEST ${i} PASSED"
    else
        echo "TEST ${i} FAILED"
    fi
done