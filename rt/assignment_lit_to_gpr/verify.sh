#!/bin/env bash
if [ "$(./main.bin)" == "-1 4294967295 1 1 " ]; then
    echo "Success!"
else
    echo "Failed!"
    exit -1
fi
