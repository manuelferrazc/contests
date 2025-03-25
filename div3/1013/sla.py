import numpy as np


while True:
    a,b = input().split()
    a = int(a)
    b = int(b)
    print(np.lcm(a,b)//np.gcd(a,b))