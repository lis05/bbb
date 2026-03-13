#!/bin/env bash

res=""
rc=0

echo "bbb binary: $1"

for file in $(ls parser_tests); do
    echo "================================================"
    echo "==========" $file "=========="
    ./$1 -vvv -o res.asm -p parser_tests/$file
    echo "================================================"
    if [ "$?" == "0" ]; then
        res="$res\nPassed: $file"
    else
        res="$res\nFAILED: $file"
        rc=1
    fi
done

echo -e "$res"
[ "$rc" == "0" ] && echo -e "\nPASSED ALL" || echo -e "\nFAILED ALL!!!!"
exit $rc
