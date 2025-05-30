#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

const ll mod = 1'000'000'007LL;
int main() { _
    ll n,x;
    cin >> n >> x;

    vector<ll> v(n), dp(x+1,0);
    for(ll &i:v) cin >> i;
    sort(v.begin(),v.end());

    for(ll c:v) {
        if(c>x) break;
        dp[c]++;
        dp[c]%=mod;
        for(ll i=c+1;i<=x;i++) 
            dp[i] = (dp[i]+dp[i-c])%mod;
    }

    cout << dp[x] << '\n';

    return 0;
}
