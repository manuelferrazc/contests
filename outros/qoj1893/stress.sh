P=e
make ${P} ${P}2 gen || exit 1
for((i=0; ; i++)) do
	./gen > in
	./${P} < in > out
	./${P}2 < in > out2
	if (! cmp -s out out2) then
		echo " ----- input:"
		cat in
		echo " ----- out1:"
		cat out
		echo " ----- out2:"
		cat out2
		break;
	fi
	echo $i
done
