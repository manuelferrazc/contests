P=countonatree
make ${P} gen || exit 1
# make ${P} ${P}2 gen || exit 1
for ((i = 1; ; i++)) do
	echo $i
	./gen $i > in
	./${P} < in > out || exit 1
	# ./${P}2 < in > out2
	# if (! cmp -s out out2) then
	# 	echo "--> entrada:"
	# 	cat in
	# 	echo "--> saida1:"
	# 	cat out
	# 	echo "--> saida2:"
	# 	cat out2
	# 	break;
	# fi
done

