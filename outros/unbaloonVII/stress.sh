P=d
make ${P} gen || exit 1
set -e
for((i=1;;i++)) do
	 ./gen > in
	 ./${P} < in > out
	 echo $i
done
