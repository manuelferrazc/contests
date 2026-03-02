P=k
make ${P} ${P}2 gen || exit 1
for ((i = 1; ; i++)) do
	./gen $i > in || exit 1
	./${P} < in > out || exit 1
	./${P}2 < in > out2 || exit 1
	if (! cmp -s out out2) then
		echo "--> entrada:"
		cat in
		echo "--> saida1:"
		cat out
		echo "--> saida2:"
		cat out2
		break;
	fi
	echo $i
done

