echo ""
echo "Running $# tests suits."

ok="0"
fail="0"

for test in $@; do
    echo " - running suit: $test"
    ./$test && ok=$((ok+1)) || fail=$((fail+1))
done

echo ""
echo "====================================="
echo "====================================="
echo ""
echo "Passed / failed:          $ok / $fail"
