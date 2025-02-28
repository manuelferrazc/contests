n = int(input())

esq = [0]*61
dir = [0]*61

while n>0:
    n-=1
    t,l = input().split(' ')
    t = int(t)
    if l[0]=='D':
        dir[t]+=1
    else:
        esq[t]+=1

ans = 0

for i in range(61):
    ans += min(esq[i],dir[i])

print(ans)