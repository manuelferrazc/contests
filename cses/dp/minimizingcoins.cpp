#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;


int main() { _
    ll n,x;
    cin >> n >> x;

    vector<ll> v(n), dp(x+1,INT_MAX);
    dp[0] = 0;
    for(ll &i:v) cin >> i;

    for(ll i=1;i<=x;i++) {
        for(ll c:v) {
            if(c<=i) dp[i] = min(dp[i],dp[i-c]+1);
        }
    }

    if(dp[x]>=INT_MAX) cout << -1 << '\n';
    else cout << dp[x] << '\n';
    
    return 0;
}
