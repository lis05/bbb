tests_dir="$1"
tests="$(ls $tests_dir)"
single_test="$2"

if [ ! -z "$single_test" ]; then
    tests="$single_test"
fi

echo ""
echo "Running $(echo $tests | wc -w) tests suits."

ok="0"
fail="0"

for test in $tests; do
    echo " - running suit: $test"
    ./$tests_dir/$test && ok=$((ok+1)) || fail=$((fail+1))
done

echo ""
echo "====================================="
echo "====================================="
echo ""
echo "Passed / failed:          $ok / $fail"
