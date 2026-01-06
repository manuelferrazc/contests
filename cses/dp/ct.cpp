#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

const ll mod = 1'000'000'007;
int n,m;
ll dp[1001][1<<10];

bitset<1<<10> err;

ll ddp(int i, int fd) { // fd = mask: 1 se j-esimo da linha já ta preenchido
    // cout << i << ' ' << fd << '\n';
    if(dp[i][fd]!=-1) return dp[i][fd];

    int miss = (1<<n)-1-fd; // miss = mask: 1 se tenho que preencher
    dp[i][fd] = 0;

    for(int mask = miss;;mask = miss&(mask-1)) { // pra cada submascara do q tenho q preencher
    // (k-esimo bit é 1 se a posicao k e k+1 dividem uma peça)
        if(err[mask]) continue;
        
        int nmk = 0;
        bool err2 = false;
        for(int j=0;j<n;j++) {
            if((mask&(1<<j)) and (miss&(1<<(j+1)))==0) {
                err2 = true;
                break;
            }
            // if(mask%(1<<j))
            if((miss&(1<<j)) and (mask&(1<<j))==0 and (j==0 or (mask&(1<<(j-1)))==0)) {
                nmk+=(1<<j);
                // cout << mask << ' ' << j << '\n';
            }
        }
        
        
        if(not err2) dp[i][fd]+=ddp(i-1,nmk);
        // if(i==7) cout << mask << ' ' << nmk << '\n';

        if(mask==0) break;
    }

    dp[i][fd]%=mod;

    return dp[i][fd];
}

int main() { 
    cin >> n >> m;

    dp[0][0] = 1;
    for(int i=1;i<(1<<n);i++) dp[0][i] = 0;
    for(int i=1;i<=m;i++) for(int j=0;j<(1<<n);j++) dp[i][j] = -1;

    for(int i=0;i<(1<<(n-1));i++) {
        err[i] = 0;
        for(int j=0;j<n-1;j++) {
            if(i&(1<<j)) {
                if(i&(1<<(j+1))) {
                    err[i] = 1;
                    break;
                } else j++;
            } 
        }
    }

    
    for(int i=(1<<(n-1));i<(1<<n);i++) err[i] = 1;
    cout << ddp(m,0) << '\n';

    return 0;
}
