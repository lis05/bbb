#!/bin/env bash
if [ "$(./main.bin)" == "81985529216486895 2309737967 2309685249 2309685250 " ]; then
    echo "Success!"
else
    echo "Failed!"
    exit -1
fi
