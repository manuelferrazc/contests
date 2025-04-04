sq = set()

i=1

while True:
    if i*i>1_000_000: break
    sq.add(i*i)
    i+=2

del i

for i in range(1,100,2):
    for j in range(2,100,2):
        if (i*i+j*j) in sq: print(f'i² = {i*i}, j² = {j*j}, s = {i*i+j*j}')