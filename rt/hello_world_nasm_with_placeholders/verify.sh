#!/bin/env bash
if [[ "$(./main.bin 2 3 4 5 6 7 8)" == "Hello world! argc=8" ]]; then
    echo "Success!"
else
    echo "Failed!"
    exit -1
fi
