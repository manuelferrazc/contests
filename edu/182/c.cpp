#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

const ll mod = 998244353;

int a[100],b[100];

ll ddp(vector<vector<ll>> &dp, int i, int op) {
    if(i==0) return dp[i][op] = 1;
    if(dp[i][op]!=-1) return dp[i][op];

    dp[i][op] = 0;

    if(op==1) swap(a[i],b[i]);
    
    if(a[i-1]<=a[i] and b[i-1]<=b[i]) dp[i][op] = ddp(dp,i-1,0);
    if(b[i-1]<=a[i] and a[i-1]<=b[i]) dp[i][op] += ddp(dp,i-1,1);

    dp[i][op]%=mod;

    if(op==1) swap(a[i],b[i]);
    
    return dp[i][op];
}

void solve() {
    int n;
    cin >> n;

    for(int i=0;i<n;i++) cin >> a[i];
    for(int i=0;i<n;i++) cin >> b[i];

    vector<vector<ll>> dp(n,vector<ll>(2,-1));

    cout << (ddp(dp,n-1,0)+ddp(dp,n-1,1))%mod << '\n';
}

int main() { _
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
