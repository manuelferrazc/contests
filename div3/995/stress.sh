i=1
while true
do
	./gen $i > in
	./main < in > out
	./main2 < in > out2

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
	i=$(($i+1))
done

