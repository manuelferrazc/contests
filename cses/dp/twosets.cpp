#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

const ll mod = 1'000'000'007LL;

vector<vector<ll>> dp;

ll ddp(ll n, ll s) {
    if(s<0) return 0;
    if(dp[n][s]!=-1) return dp[n][s];
    if(n==0) return dp[n][s] = 0;

    return dp[n][s] = (ddp(n-1,s)+ddp(n-1,s-n))%mod;
}

int main() { _
    ll n;
    cin >> n;

    ll s = n*(n+1)/2;
    if(s&1) {
        cout << "0\n";
        return 0;
    }

    s>>=1;
    dp.resize(n+1,vector<ll>(s+1,-1));

    for(ll i=0;i<=n;i++) dp[i][0] = 1;

    cout << (ddp(n,s)*500000004)%mod << '\n';

    return 0;
}
