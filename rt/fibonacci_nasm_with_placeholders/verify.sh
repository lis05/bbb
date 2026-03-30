#!/bin/env bash
EXPECTED=$(cat <<EOF
0
1
1
2
3
5
8
13
21
34
55
89
144
233
377
EOF
)

if [ "$(./main.bin)" == "$EXPECTED" ]; then
    echo "Success!"
else
    echo "Failed!"
    exit -1
fi
