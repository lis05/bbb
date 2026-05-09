#!/bin/env bash
if [ "$(./main.bin)" == $'-1\n-2\n3\n4\n5\n6\n7\n8\n9\n9\n9\n9\n10\n10\n10\n10\n11\n1212\n131313131\n14\n1515\n161616161' ]; then
    echo "Success!"
else
    echo "Failed!"
    exit 1
fi
