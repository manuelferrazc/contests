P=gameontree
make ${P} ${P}2 gen || exit 1

for ((i = 1; ; i++)); do
    ./gen $i > in
    ./${P} < in > out
    ./${P}2 < in > out2

    # Read the first double from each output
    val1=$(head -n 1 out)
    val2=$(head -n 1 out2)

    # Compare using awk for floating point precision
    diff=$(awk -v a="$val1" -v b="$val2" 'BEGIN { print (a > b) ? a - b : b - a }')
    is_ok=$(awk -v d="$diff" 'BEGIN { print (d <= 1e-6) ? "yes" : "no" }')

    if [[ "$is_ok" == "no" ]]; then
        echo "--> entrada:"
        cat in
        echo "--> saida1: $val1"
        echo "--> saida2: $val2"
        echo "--> diferença: $diff"
        break
    fi

    echo $i
done
