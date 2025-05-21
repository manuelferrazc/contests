#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

const ll mod = 1'000'000'007LL;
vector<string> v;
vector<vector<ll>> dp;

ll ddp(ll x, ll y) {
    if(dp[x][y]!=-1) return dp[x][y];
    if(v[x][y]=='*') return dp[x][y] = 0;

    return dp[x][y] = (ddp(x+1,y)+ddp(x,y+1))%mod;
}

int main() { _
    ll n;
    cin >> n;
    v.resize(n);
    for(string &s:v) cin >> s;

    dp.assign(n+1,vector<ll>(n+1,-1));

    if(v.back().back()=='*') dp[n-1][n-1] = 0;
    else dp[n-1][n-1] = 1;

    for(ll i=0;i<n;i++) dp[n][i] = dp[i][n] = 0;
    cout << ddp(0,0) << '\n';

    return 0;
}
