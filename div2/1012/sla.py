def prime(n):
    if n<=1: return False
    if(n==2): return True
    if(n%2==0): return False

    r = int(n**0.5)
    for i in range(3,r+1,2):
        if n%i==0: return False

    return True





def main():
    l = [int(x) for x in input().split(sep=' ')]

    c = [0]*len(l)
    s = 0
    p = 0

    for i in range(len(l)):
        s+=l[i]
        c[i] = s//(i+1)
        if s%(i+1)!=0: c[i]+=1

        if(prime(c[i])): p+=1
    print(f'c: {c}')
    print(f'# primes: {p}')


if __name__== '__main__': main()