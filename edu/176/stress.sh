P=a
make ${P} gen || exit 1  # Remove ${P}2 from compilation

for ((i = 1; ; i++)) do
    ./gen $i > in
    ./${P} < in > out
    python3 ${P}2.py < in > out2  # Run P2.py instead of a compiled C++ program

    if (! cmp -s out out2) then
        echo "--> entrada:"
        cat in
        echo "--> saida1:"
        cat out
        echo "--> saida2:"
        cat out2
        # break;
    fi
    echo $i
done
