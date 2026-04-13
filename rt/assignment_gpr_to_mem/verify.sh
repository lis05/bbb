#!/bin/env bash
if [ "$(./main.bin)" == "81985529216486895 2309737967 1 2 " ]; then
    echo "Success!"
else
    echo "Failed!"
    exit -1
fi
