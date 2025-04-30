#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

const ll mod = 1000000007LL;

ll n,m;
vector<vector<ll>> dp;
vector<string> v;

ll d(ll i, ll j) {
    if(dp[i][j]!=-1) return dp[i][j];
    if(v[i][j]=='#') return dp[i][j] = 0LL;
    if(i==n-1 and j==m-1) return dp[i][j] = 1LL;
    if(i==n-1) return dp[i][j] = d(i,j+1);
    if(j==m-1) return dp[i][j] = d(i+1,j);
    return dp[i][j] = (d(i+1,j)+d(i,j+1))%mod;
}

int main() { _
    cin >> n >> m;
    v.resize(n);
    dp.assign(n,vector<ll>(m,-1));
    for(string &s:v) cin >> s;

    cout << d(0,0) << '\n';
    
    return 0;
}
