#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

const ll mod = 1'000'000'007;
int a[22][22];

ll dp[1<<22];

ll ddp(int m, int qtd) {
    if(dp[m]!=-1) return dp[m];
    if(qtd==0) return dp[m] = 1;

    dp[m] = 0;

    for(int i=1;i<=21;i++) {
        if(((m>>i)&1) and a[i][qtd]) {
            dp[m] += ddp(m^(1<<i),qtd-1);
        }
    }

    return dp[m]%=mod;
}

int main() { _
    int n;
    cin >> n;
    
    for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) cin >> a[i][j];
    for(int i=0;i<(1<<22);i++) dp[i] = -1;

    cout << ddp((1<<(n+1))-2,n) << '\n';

    return 0;
}
