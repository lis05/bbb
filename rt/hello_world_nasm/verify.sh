#!/bin/env bash
if [ "$(./main)" == "Hello, world!" ]; then
    echo "Success!"
else
    echo "Failed!"
    exit -1
fi
