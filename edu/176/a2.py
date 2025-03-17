t=int(input())
for _ in range(t):
    n,k=list(map(int, input().split()))
    c=0
    keven=k-k%2
    kodd=k-1+k%2
    if n%2==1:
        n-=kodd
        c+=1
    c+=n//keven
    n=n%keven
    if n>0:
        c+=1
        
        
    
    print(c)
